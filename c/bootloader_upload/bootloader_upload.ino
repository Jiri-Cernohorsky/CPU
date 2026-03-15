#include <SoftwareSerial.h>

const int RxPin = 10;
const int TxPin = 11;
SoftwareSerial CPU_UART(RxPin, TxPin);

const uint32_t BAUD_CPU  = 9600;
const uint32_t BAUD_PC   = 9600;
const uint16_t CHUNK_SIZE = 64;

// ── Stav ────────────────────────────────────────
enum State { WAIT_HEADER, RECEIVE_DATA, PASSTHROUGH };
State state = WAIT_HEADER;

uint32_t flash_addr;
uint32_t ram_addr;
uint16_t num_words;
uint32_t total_bytes;
uint32_t received_bytes;

// ── Pomocné funkce ───────────────────────────────

bool cpu_send_byte_echo(uint8_t b) {
    CPU_UART.write(b);
    unsigned long deadline = millis() + 2000;
    while (!CPU_UART.available()) {
        if (millis() > deadline) {
            Serial.print("NOECHO:0x");
            Serial.println(b, HEX);
            return false;
        }
    }
    uint8_t echo = CPU_UART.read();
    if (echo != b) {
        Serial.print("BADECHO:sent=0x");
        Serial.print(b, HEX);
        Serial.print(",got=0x");
        Serial.println(echo, HEX);
        return false;
    }
    return true;
}

bool cpu_send_bytes(const uint8_t* buf, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        if (!cpu_send_byte_echo(buf[i])) {
            Serial.print("ERR echo @ byte ");
            Serial.println(i);
            return false;
        }
    }
    return true;
}

// ── Setup ────────────────────────────────────────

void setup() {
    Serial.begin(BAUD_PC);
    CPU_UART.begin(BAUD_CPU);
    delay(100);
    Serial.println("READY");
}

// ── Loop ─────────────────────────────────────────

void loop() {

    // ── 1) Čekání na hlavičku (8 bytů) ─────────────
    if (state == WAIT_HEADER) {
        if (Serial.available() >= 1) {
            // Ping od Pythonu - znovu poslat READY
            if (Serial.peek() == '?') {
                Serial.read();
                Serial.println("READY");
                return;
            }
        }
        if (Serial.available() >= 8) {
            uint8_t h[8];
            Serial.readBytes(h, 8);

            flash_addr = ((uint32_t)h[0] << 16) | ((uint32_t)h[1] << 8) | h[2];
            ram_addr   = ((uint32_t)h[3] << 16) | ((uint32_t)h[4] << 8) | h[5];
            num_words  = ((uint16_t)h[6] << 8)  |  h[7];
            total_bytes   = (uint32_t)num_words * 4;
            received_bytes = 0;

            Serial.print("OK"); // potvrzení hlavičky

            // ── ERASE ──────────────────────────────
            Serial.println("ERASE...");
            uint8_t erase_seq[4] = {
                0x03,
                (uint8_t)(flash_addr >> 16),
                (uint8_t)(flash_addr >>  8),
                (uint8_t)(flash_addr      )
            };
            if (!cpu_send_bytes(erase_seq, 4)) {
                Serial.println("FAIL ERASE");
                return;
            }
            Serial.println("ERASE OK");

            // ── PROGRAM hlavička ───────────────────
            Serial.println("PROGRAM...");
            uint8_t prog_hdr[6] = {
                0x02,
                (uint8_t)(flash_addr >> 16),
                (uint8_t)(flash_addr >>  8),
                (uint8_t)(flash_addr      ),
                (uint8_t)(num_words  >>  8),
                (uint8_t)(num_words       )
            };
            if (!cpu_send_bytes(prog_hdr, 6)) {
                Serial.println("FAIL PROG HDR");
                return;
            }

            state = RECEIVE_DATA;
        }
        return;
    }

    // ── 2) Příjem a přeposílání dat ─────────────────
    if (state == RECEIVE_DATA) {
        if (Serial.available() > 0) {
            uint8_t chunk[CHUNK_SIZE];
            uint16_t to_read = min((uint32_t)CHUNK_SIZE, total_bytes - received_bytes);
            uint16_t n = Serial.readBytes(chunk, to_read);

            // Přeposílání do CPU
            if (!cpu_send_bytes(chunk, n)) {
                Serial.println("FAIL DATA");
                state = WAIT_HEADER;
                return;
            }

            received_bytes += n;
            Serial.print("AK"); // ACK po každém chunku

            // Všechna data přijata
            if (received_bytes >= total_bytes) {
                Serial.println("DATA OK");

                // ── START ──────────────────────────
                uint8_t start_seq[8] = {
                    0x01,
                    (uint8_t)(flash_addr >> 16),
                    (uint8_t)(flash_addr >>  8),
                    (uint8_t)(flash_addr      ),
                    (uint8_t)(ram_addr   >> 16),
                    (uint8_t)(ram_addr   >>  8),
                    (uint8_t)(ram_addr        ),
                    (uint8_t)(num_words  >>  8),
                    // pozn: num_words LSB vynechán – přidej pokud bootloader vyžaduje
                };
                // Odeslání všech 9 bytů START sekvence
                uint8_t start_full[9] = {
                    0x01,
                    (uint8_t)(flash_addr >> 16),
                    (uint8_t)(flash_addr >>  8),
                    (uint8_t)(flash_addr      ),
                    (uint8_t)(ram_addr   >> 16),
                    (uint8_t)(ram_addr   >>  8),
                    (uint8_t)(ram_addr        ),
                    (uint8_t)(num_words  >>  8),
                    (uint8_t)(num_words       )
                };
                if (!cpu_send_bytes(start_full, 9)) {
                    Serial.println("FAIL START");
                    state = WAIT_HEADER;
                    return;
                }
                Serial.println("START OK - program bezi");
                state = PASSTHROUGH;
            }
        }
        return;
    }

    // ── 3) Passthrough po spuštění programu ─────────
    if (state == PASSTHROUGH) {
        if (CPU_UART.available()) {
            Serial.write(CPU_UART.read());
        }
        if (Serial.available()) {
            CPU_UART.write(Serial.read());
        }
    }
}
