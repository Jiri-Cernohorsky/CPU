import os

def format_binary_file(filename):
    # Kontrola, zda soubor existuje
    if not os.path.exists(filename):
        print(f"Chyba: Soubor '{filename}' nebyl nalezen.")
        return

    try:
        with open(filename, 'rb') as f:
            content = f.read()
            
        # Zpracování po 4 bajtech (dle tvého vzoru)
        bytes_per_line = 4
        
        for i in range(0, len(content), bytes_per_line):
            chunk = content[i : i + bytes_per_line]
            
            # Formátování každého bajtu na x"HH"
            # :02x zajistí hex formát na 2 znaky (např. 0a místo a)
            formatted_bytes = [f'x"{b:02x}"' for b in chunk]
            
            # Spojení čárkami a přidání čárky na konec řádku
            line = ",".join(formatted_bytes) + ","
            
            # Výpis s odsazením (tabulátor nebo mezery, dle potřeby)
            print(f"        {line}")

    except Exception as e:
        print(f"Nastala chyba při čtení souboru: {e}")

# Spuštění funkce
if __name__ == "__main__":
    format_binary_file(input("Vstupní soubor (.asm/.s): ").strip())