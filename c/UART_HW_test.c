#include <SoftwareSerial.h>

const int RxPin = 10; 
const int TxPin = 11;

SoftwareSerial CPU_UART(RxPin, TxPin);

void setup() {
  // Komunikace s počítačem
  Serial.begin(9600);
  Serial.println("Start komunikace");

  // Komunikace se samotným procesorem
  CPU_UART.begin(9600);
}

void loop() {
  // Čtení dat z CPU a odeslání do počítače
  if (CPU_UART.available()) {
    char dataZModulu = CPU_UART.read();
    Serial.write(dataZModulu);
  }

  // Čtení dat z počítače a odeslání do CPU
  if (Serial.available()) {
    char dataZPocitace = Serial.read();
    CPU_UART.write(dataZPocitace);
  }
}