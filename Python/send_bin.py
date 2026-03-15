import serial
import serial.tools.list_ports
import os
import sys
import time

def list_ports():
    ports = serial.tools.list_ports.comports()
    if not ports:
        print("Zadne COM porty nenalezeny.")
        sys.exit(1)
    print("\nDostupne COM porty:")
    for i, p in enumerate(ports):
        print(f"  [{i}] {p.device} - {p.description}")
    return ports

def ask_port():
    ports = list_ports()
    while True:
        s = input("\nVyber port (cislo nebo nazev, napr. COM3): ").strip()
        if s.isdigit():
            idx = int(s)
            if 0 <= idx < len(ports):
                return ports[idx].device
        else:
            return s

def main():
    print("=== RISC-V Bootloader Upload ===\n")

    # Cesta k bin souboru
    while True:
        bin_path = input("Cesta k .bin souboru: ").strip().strip('"')
        if os.path.isfile(bin_path):
            break
        print(f"  Soubor nenalezen: {bin_path}")

    data = bytearray(open(bin_path, "rb").read())

    # Zarovnani na 4 byty
    if len(data) % 4 != 0:
        data += b'\x00' * (4 - len(data) % 4)

    num_words = len(data) // 4
    print(f"  Nacteno {len(data)} bytu = {num_words} slov")

    # Flash adresa
    flash_str = input("\nFlash adresa (hex, výchozí 000400): ").strip()
    flash_addr = int(flash_str, 16) if flash_str else 0x000400

    # RAM adresa
    ram_str = input("RAM adresa   (hex, výchozí 000320): ").strip()
    ram_addr = int(ram_str, 16) if ram_str else 0x000320

    # COM port
    port = ask_port()
    baud_str = input("\nBaud rate (výchozí 9600): ").strip()
    baud = int(baud_str) if baud_str.isdigit() else 9600

    print(f"\nOtvírám {port} @ {baud}...")
    ser = serial.Serial(port, baud, timeout=1)
    time.sleep(3)  # čekání na reset Arduina
    ser.reset_input_buffer()

    # Pošleme '?' aby Arduino znovu poslalo READY
    ser.write(b'?')

    # Čekání na "READY" od Arduina
    print("Čekám na Arduino...")
    deadline = time.time() + 10
    buf = ""
    while "READY" not in buf:
        if time.time() > deadline:
            print("Timeout - Arduino neodpovida.")
            print(f"Prijato: {repr(buf)}")
            ser.close(); sys.exit(1)
        line = ser.readline().decode("latin-1", errors="replace")
        if line:
            print(f"  Arduino: {line.strip()}")
            buf += line

    print("Arduino ready.\n")

    # Protokol:
    # [FLASH_H][FLASH_M][FLASH_L][RAM_H][RAM_M][RAM_L][WORDS_H][WORDS_L] + data
    header = bytes([
        (flash_addr >> 16) & 0xFF,
        (flash_addr >>  8) & 0xFF,
         flash_addr        & 0xFF,
        (ram_addr   >> 16) & 0xFF,
        (ram_addr   >>  8) & 0xFF,
         ram_addr          & 0xFF,
        (num_words  >>  8) & 0xFF,
         num_words         & 0xFF,
    ])

    print(f"Odesílám hlavičku: {header.hex()}")
    ser.write(header)

    # Čekání na "OK" potvrzení hlavičky
    time.sleep(0.1)
    resp = ser.read(2).decode("latin-1", errors="replace")
    if "OK" not in resp:
        print(f"Chyba: Arduino nepotvrdilo hlavičku (dostal: {repr(resp)})")
        ser.close(); sys.exit(1)

    # Odesílání dat po 64 bytech (chunk)
    CHUNK = 64
    total = len(data)
    sent  = 0
    print(f"Odesílám {total} bytů...")

    while sent < total:
        chunk = data[sent:sent + CHUNK]
        ser.write(chunk)
        sent += len(chunk)

        # Čekání na ACK ("AK") po každém chunku
        deadline = time.time() + 5
        ack_buf = ""
        while "AK" not in ack_buf:
            if time.time() > deadline:
                print(f"\nTimeout při ACK, offset {sent}")
                ser.close(); sys.exit(1)
            if ser.in_waiting:
                ack_buf += ser.read(ser.in_waiting).decode("latin-1", errors="replace")

        pct = sent * 100 // total
        bar = "█" * (pct // 5) + "░" * (20 - pct // 5)
        print(f"\r  [{bar}] {pct:3d}%  ({sent}/{total} B)", end="", flush=True)

    print("\n\nUpload hotov, čekám na výstup CPU...\n")
    print("─" * 40)

    try:
        while True:
            if ser.in_waiting:
                c = ser.read(ser.in_waiting)
                sys.stdout.write(c.decode("latin-1", errors="replace"))
                sys.stdout.flush()
            time.sleep(0.01)
    except KeyboardInterrupt:
        print("\nUkončeno.")
    finally:
        ser.close()

if __name__ == "__main__":
    main()