def print_hex_dump_compact(file_path, bytes_per_line=32):
    try:
        with open(file_path, 'rb') as f:
            while True:
                chunk = f.read(bytes_per_line)
                if not chunk:
                    break
                
                # Změna: join('') místo join(' ')
                hex_string = ''.join(f'{b:02x}' for b in chunk)
                print(hex_string)
                
    except FileNotFoundError:
        print("Soubor nebyl nalezen. Zkontroluj cestu.")

print_hex_dump_compact('C:/Xilinx/shared_dir/CPU/asm_test_codes/GPIO_test.bin')