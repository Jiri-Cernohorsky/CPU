# Implementace jednoduchého RISC-V procesoru

Tato ročníková práce se zabývá návrhem a implementací jednocyklového procesoru na architektuře RISC-V. Procesor je navržen v jazyce VHDL a otestován pomocí simulace i nasazením na FPGA desce.

## Shrnutí

- **Architektura:** RISC-V (picoRISC-V subset)
- **Typ:** Jednocyklový procesor
- **Technologie:** VHDL, FPGA (Spartan-3E)
- **Cílová platforma:** Xilinx ISE, ISIM, Sigasi + VS Code
- **Autor:** Jiří Černohorský
- **Vedoucí práce:** Ing. Petr Socha, Ph.D.
- **Školní rok:** 2024/2025

## Funkce procesoru

### Podporované instrukce (11 instrukcí):
- **Čtení/zápis:** `lw`, `sw`
- **ALU operace:** `add`, `addi`, `sub`, `and`, `or`, `slt`
- **Skoky a volání:** `beq`, `jal`, `jalr`

### Klíčové komponenty:
- **Řadič:** Generuje řídicí signály na základě `opcode`, `funct3`, `funct7`.
- **ALU:** Aritmeticko-logická jednotka s operacemi +, -, AND, OR, SLT.
- **Registre:** 32 registrů šířky 32 bitů (0. registr = nula).
- **Paměť:**
  - **Instrukční paměť:** 1KB (256 instrukcí), hard-coded.
  - **Datová paměť:** 512 B, podpora I/O (LED na adrese 0, DIP přepínače na adrese 4).
- **Top-Level Architektura:** Harvardská architektura (oddělená paměť dat a programu).

## Použité zdroje

1. Ing. Michal Štěpanovský, Ph.D. – Přednášky o RISC mikroarchitektuře (BI-APS, FIT ČVUT)
2. [RISC-V Instruction Encoder/Decoder](https://luplab.gitlab.io/rvcodecjs/)

