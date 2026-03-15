import sys
import os

def generate_vhdl_init(bin_filename, output_filename="vhdl_init.txt"):
    # 1. Načtení binárního souboru
    try:
        with open(bin_filename, "rb") as f:
            data = f.read()
    except FileNotFoundError:
        print(f"Chyba: Soubor '{bin_filename}' nebyl nalezen.")
        return

    # 2. Doplnění nulami na velikost RAMB16_S36 (2048 bytů / 64 řádků po 32 bytech)
    data = data.ljust(2048, b'\x00')

    output_lines = []
    
    # 3. Zpracování všech 64 řádků
    for i in range(64):
        # Vyřízneme si 32 bytů pro jeden INIT řádek (256 bitů)
        chunk = data[i*32 : (i+1)*32]
        
        # Rozdělíme tento 32bytový blok na osm 4bytových (32bitových instrukcí/dat) slov
        words = [chunk[j*4 : (j+1)*4] for j in range(8)]
        
        # VHDL BlockRAM čte od nejnižší adresy z PRAVÉ strany řetězce.
        # Proto musíme otočit pořadí celých slov, ale BYTY UVNITŘ SLOVA zachováme!
        reversed_words = words[::-1]
        
        # Převedeme seznam slov na jeden dlouhý HEX řetězec a převedeme na velká písmena
        hex_str = ''.join(w.hex().upper() for w in reversed_words)
        
        # Naformátujeme VHDL kód
        output_lines.append(f'      INIT_{i:02X} => X"{hex_str}",')

    # 4. Spojení a výpis výsledku
    vhdl_code = "\n".join(output_lines)
    print("-- Zkopírujte následující kód do vašeho VHDL:")
    print(vhdl_code)
    
if __name__ == "__main__":
    # Název vstupního souboru. Pokud se jmenuje jinak, upravte ho zde:
    input_file = "C:/Xilinx/shared_dir/CPU/asm_test_codes/bootloader.bin"
    generate_vhdl_init(input_file)