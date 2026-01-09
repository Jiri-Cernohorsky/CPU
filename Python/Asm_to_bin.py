import sys
import struct

# === KONFIGURACE RISC-V (32-bit) ===

OPCODES = {
    'R-TYPE': 0b0110011, 
    'I-TYPE': 0b0010011, 
    'LOAD':   0b0000011, 
    'STORE':  0b0100011, 
    'BRANCH': 0b1100011, 
    'JAL':    0b1101111, 
    'JALR':   0b1100111,
    'SYSTEM': 0b1110011  # NEW
}

FUNCT = {
    'add':  {'fmt': 'R', 'f3': 0x0, 'f7': 0x00},
    'sub':  {'fmt': 'R', 'f3': 0x0, 'f7': 0x20},
    'and':  {'fmt': 'R', 'f3': 0x7, 'f7': 0x00},
    'or':   {'fmt': 'R', 'f3': 0x6, 'f7': 0x00},
    'slt':  {'fmt': 'R', 'f3': 0x2, 'f7': 0x00},
    'addi': {'fmt': 'I', 'f3': 0x0},
    'lw':   {'fmt': 'L', 'f3': 0x2}, 
    'sw':   {'fmt': 'S', 'f3': 0x2}, 
    'beq':  {'fmt': 'B', 'f3': 0x0},
    'jal':  {'fmt': 'J'},
    'jalr': {'fmt': 'I_JALR', 'f3': 0x0},
    'mret': {'fmt': 'SYS', 'f3': 0x0, 'imm': 0x302} # NEW
}

REGS = {f'x{i}': i for i in range(32)}
ABI_NAMES = {
    'zero': 0, 'ra': 1, 'sp': 2, 'gp': 3, 'tp': 4, 't0': 5, 't1': 6, 't2': 7,
    's0': 8, 'fp': 8, 's1': 9, 'a0': 10, 'a1': 11, 'a2': 12, 'a3': 13,
    'a4': 14, 'a5': 15, 'a6': 16, 'a7': 17
}
REGS.update(ABI_NAMES)

# === POMOCNÉ FUNKCE ===

def get_reg(reg_name):
    reg_name = reg_name.strip().lower().replace(',', '')
    if reg_name in REGS:
        return REGS[reg_name]
    raise ValueError(f"Neznámý registr: {reg_name}")

def parse_imm(val_str):
    val_str = val_str.strip().replace(',', '')
    return int(val_str, 0)

def to_bin_32(val):
    return val & 0xFFFFFFFF

# === ENKÓDOVÁNÍ INSTRUKCÍ ===

def encode_r_type(opcode, f3, f7, rd, rs1, rs2):
    return (f7 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | opcode

def encode_i_type(opcode, f3, rd, rs1, imm):
    imm = to_bin_32(imm) & 0xFFF
    return (imm << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | opcode

def encode_s_type(opcode, f3, rs1, rs2, imm):
    imm = to_bin_32(imm)
    imm_11_5 = (imm >> 5) & 0x7F
    imm_4_0 = imm & 0x1F
    return (imm_11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (imm_4_0 << 7) | opcode

def encode_b_type(opcode, f3, rs1, rs2, offset):
    off = to_bin_32(offset)
    imm_12 = (off >> 12) & 1
    imm_10_5 = (off >> 5) & 0x3F
    imm_4_1 = (off >> 1) & 0xF
    imm_11 = (off >> 11) & 1
    return (imm_12 << 31) | (imm_10_5 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (imm_4_1 << 8) | (imm_11 << 7) | opcode

def encode_j_type(opcode, rd, offset):
    off = to_bin_32(offset)
    imm_20 = (off >> 20) & 1
    imm_10_1 = (off >> 1) & 0x3FF
    imm_11 = (off >> 11) & 1
    imm_19_12 = (off >> 12) & 0xFF
    return (imm_20 << 31) | (imm_19_12 << 12) | (imm_11 << 20) | (imm_10_1 << 21) | (rd << 7) | opcode

# === LOGIKA PŘEKLADU ===

def assembler_pass(lines, labels=None, current_address=0):
    binary_code = []
    is_first_pass = (labels is not None) and (len(labels) == 0)
    addr = 0
    
    for line in lines:
        line = line.split('#')[0].strip()
        if not line: continue
        
        if line.endswith(':'):
            if is_first_pass:
                label_name = line[:-1]
                labels[label_name] = addr
            continue 

        if is_first_pass:
            addr += 4
            continue

        parts = line.replace(',', ' ').split()
        cmd = parts[0].lower()
        
        if cmd not in FUNCT:
            print(f"❌ Chyba: Neznámá instrukce '{cmd}'")
            return None

        info = FUNCT[cmd]
        fmt = info['fmt']
        machine_code = 0
        
        try:
            if fmt == 'R': 
                rd = get_reg(parts[1])
                rs1 = get_reg(parts[2])
                rs2 = get_reg(parts[3])
                machine_code = encode_r_type(OPCODES['R-TYPE'], info['f3'], info['f7'], rd, rs1, rs2)
                
            elif fmt == 'I': 
                rd = get_reg(parts[1])
                rs1 = get_reg(parts[2])
                imm = parse_imm(parts[3])
                machine_code = encode_i_type(OPCODES['I-TYPE'], info['f3'], rd, rs1, imm)
                
            elif fmt == 'L':
                rd = get_reg(parts[1])
                mem_part = parts[2]
                offset = parse_imm(mem_part.split('(')[0])
                rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                machine_code = encode_i_type(OPCODES['LOAD'], info['f3'], rd, rs1, offset)
            
            elif fmt == 'S': 
                rs2 = get_reg(parts[1]) 
                mem_part = parts[2]
                offset = parse_imm(mem_part.split('(')[0])
                rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                machine_code = encode_s_type(OPCODES['STORE'], info['f3'], rs1, rs2, offset)
                
            elif fmt == 'B': 
                rs1 = get_reg(parts[1])
                rs2 = get_reg(parts[2])
                target = parts[3]
                if target in labels:
                    offset = labels[target] - addr
                else:
                    offset = parse_imm(target)
                machine_code = encode_b_type(OPCODES['BRANCH'], info['f3'], rs1, rs2, offset)
                
            elif fmt == 'J': 
                rd = get_reg(parts[1])
                target = parts[2]
                if target in labels:
                    offset = labels[target] - addr
                else:
                    offset = parse_imm(target)
                machine_code = encode_j_type(OPCODES['JAL'], rd, offset)

            elif fmt == 'I_JALR': 
                rd = get_reg(parts[1])
                if '(' in parts[2]: 
                      mem_part = parts[2]
                      offset = parse_imm(mem_part.split('(')[0])
                      rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                else: 
                      rs1 = get_reg(parts[2])
                      offset = parse_imm(parts[3]) if len(parts) > 3 else 0
                machine_code = encode_i_type(OPCODES['JALR'], info['f3'], rd, rs1, offset)

            elif fmt == 'SYS': # NEW: mret handler
                # Pro mret: rd=0, rs1=0, imm=0x302 (funct12)
                machine_code = encode_i_type(OPCODES['SYSTEM'], info['f3'], 0, 0, info['imm'])

            binary_code.append(machine_code)
            addr += 4 
            
        except Exception as e:
            print(f"❌ Chyba na řádku: '{line}' -> {e}")
            return None

    return binary_code

def main():
    print("=== RISC-V ASSEMBLER (s podporou MRET) ===")
    filename = input("Vstupní soubor (.asm/.s): ").strip()
    
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            
        labels = {}
        assembler_pass(lines, labels)
        print(f"🔎 Nalezeny labely: {labels}")
        
        machine_code_ints = assembler_pass(lines, labels, 0)
        
        if machine_code_ints is None:
            return 
            
        output_file = filename.rsplit('.', 1)[0] + ".bin"
        with open(output_file, 'wb') as f:
            for instr in machine_code_ints:
                f.write(struct.pack('>I', instr))
                
        print(f"✅ Hotovo! Uloženo do {output_file}")
        
    except FileNotFoundError:
        print("❌ Soubor nenalezen.")
    except Exception as e:
        print(f"❌ Chyba: {e}")

if __name__ == "__main__":
    main()