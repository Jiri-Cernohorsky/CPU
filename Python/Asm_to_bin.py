import sys
import struct

OPCODES = {
    'R-TYPE': 0b0110011, 
    'I-TYPE': 0b0010011, 
    'L-TYPE': 0b0000011, 
    'S-TYPE': 0b0100011, 
    'B-TYPE': 0b1100011, 
    'J-TYPE': 0b1101111, 
    'JALR':   0b1100111,
    'SYSTEM': 0b1110011
}

FUNCT = {
    'add':  {'ft': 'R', 'f3': 0x0, 'f7': 0x00},
    'sub':  {'ft': 'R', 'f3': 0x0, 'f7': 0x20},
    'and':  {'ft': 'R', 'f3': 0x7, 'f7': 0x00},
    'or':   {'ft': 'R', 'f3': 0x6, 'f7': 0x00},
    'slt':  {'ft': 'R', 'f3': 0x2, 'f7': 0x00},
    'sll':  {'ft': 'R', 'f3': 0x1, 'f7': 0x00},
    'srl':  {'ft': 'R', 'f3': 0x5, 'f7': 0x00},
    'addi': {'ft': 'I', 'f3': 0x0},
    'lw':   {'ft': 'L', 'f3': 0x2}, 
    'sw':   {'ft': 'S', 'f3': 0x2}, 
    'beq':  {'ft': 'B', 'f3': 0x0},
    'jal':  {'ft': 'J'},
    'jalr': {'ft': 'I_JALR', 'f3': 0x0},
    'mret': {'ft': 'SYS', 'f3': 0x0, 'imm': 0x302}
}

REGS = {'x0' : 0, 'x1' : 1, 'x2' : 2, 'x3' : 3, 'x4' : 4, 'x5' : 5, 'x6' : 6, 'x7' : 7, 'x8' : 8, 'x9' : 9,
        'x10' : 10, 'x11' : 11, 'x12' : 12, 'x13' : 13, 'x14' : 14, 'x15' : 15, 'x16' : 16, 'x17' : 17, 'x18' : 18, 'x19' : 19,
        'x20' : 20, 'x21' : 21, 'x22' : 22, 'x23' : 23, 'x24' : 24, 'x25' : 25, 'x26' : 26, 'x27' : 27, 'x28' : 28, 'x29' : 29,
        'x30' : 30, 'x31' : 31, 'x32' : 32,
        'zero': 0, 'ra': 1, 'sp': 2, 'gp': 3, 'tp': 4, 't0': 5, 't1': 6, 't2': 7,
        's0': 8, 'fp': 8, 's1': 9, 'a0': 10, 'a1': 11, 'a2': 12, 'a3': 13,
        'a4': 14, 'a5': 15, 'a6': 16, 'a7': 17
}

def get_reg(reg_name):
    reg_name = reg_name.strip().lower().replace(',', '')
    if reg_name in REGS:
        return REGS[reg_name]

def parse_imm(val_str):
    val_str = val_str.strip().replace(',', '')
    return int(val_str, 0)

def to_bin_32(val):
    return val & 0xFFFFFFFF

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

def catch_labels(lines):
    addr = 0
    labels = {}
    for line in lines:
        line = line.split('#')[0].strip()
        if not line: continue
        
        if line.lower().startswith(('org ', '.org ')):
            parts = line.split()
            addr = parse_imm(parts[1])
            continue

        if line.endswith(':'):
            label_name = line[:-1].strip()
            labels[label_name] = addr
        else:
            addr += 4
    return labels

def assembler_pass(lines, labels):
    binary_code = []
    addr = 0

    for line in lines:
        line = line.split('#')[0].strip()
        if not line: continue
        if line.endswith(':'): continue

        if line.lower().startswith(('org ', '.org ')):
            new_addr = parse_imm(line.split()[1])
            if new_addr > addr:
                padding_words = (new_addr - addr) // 4
                binary_code.extend([0] * padding_words)
            elif new_addr < addr:
                print(f"Varování: ORG skáče zpět z adresy {hex(addr)} na {hex(new_addr)}. Ve formátu .bin to nelze snadno zapsat.")
            addr = new_addr
            continue

        parts = line.replace(',', ' ').split()
        cmd = parts[0].lower()

        info = FUNCT[cmd]
        funciton_type = info['ft']
        bin_line = 0

        try:
            if funciton_type == 'R': 
                rd = get_reg(parts[1])
                rs1 = get_reg(parts[2])
                rs2 = get_reg(parts[3])
                bin_line = encode_r_type(OPCODES['R-TYPE'], info['f3'], info['f7'], rd, rs1, rs2)

            elif funciton_type == 'I': 
                rd = get_reg(parts[1])
                rs1 = get_reg(parts[2])
                imm = parse_imm(parts[3])
                bin_line = encode_i_type(OPCODES['I-TYPE'], info['f3'], rd, rs1, imm)

            elif funciton_type == 'L':
                rd = get_reg(parts[1])
                mem_part = parts[2]
                offset = parse_imm(mem_part.split('(')[0])
                rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                bin_line = encode_i_type(OPCODES['L-TYPE'], info['f3'], rd, rs1, offset)

            elif funciton_type == 'S': 
                rs2 = get_reg(parts[1]) 
                mem_part = parts[2]
                offset = parse_imm(mem_part.split('(')[0])
                rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                bin_line = encode_s_type(OPCODES['S-TYPE'], info['f3'], rs1, rs2, offset)

            elif funciton_type == 'B': 
                rs1 = get_reg(parts[1])
                rs2 = get_reg(parts[2])
                target = parts[3]
                if target in labels:
                    offset = labels[target] - addr
                else:
                    offset = parse_imm(target)
                bin_line = encode_b_type(OPCODES['B-TYPE'], info['f3'], rs1, rs2, offset)

            elif funciton_type == 'J': 
                rd = get_reg(parts[1])
                target = parts[2]
                if target in labels:
                    offset = labels[target] - addr
                else:
                    offset = parse_imm(target)
                bin_line = encode_j_type(OPCODES['J-TYPE'], rd, offset)

            elif funciton_type == 'I_JALR': 
                rd = get_reg(parts[1])
                if '(' in parts[2]: 
                      mem_part = parts[2]
                      offset = parse_imm(mem_part.split('(')[0])
                      rs1 = get_reg(mem_part.split('(')[1].replace(')', ''))
                else: 
                      rs1 = get_reg(parts[2])
                      offset = parse_imm(parts[3]) if len(parts) > 3 else 0
                bin_line = encode_i_type(OPCODES['JALR'], info['f3'], rd, rs1, offset)

            elif funciton_type == 'SYS': 
                bin_line = encode_i_type(OPCODES['SYSTEM'], info['f3'], 0, 0, info['imm'])

            binary_code.append(bin_line)
            addr += 4 

        except Exception as e:
            print(f"Chyba na řádku: '{line}' -> {e}")
            return None

    return binary_code


if __name__ == "__main__":
    filename = input("Vstupní soubor (.asm): ").strip()
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            lines = f.readlines()

        labels = catch_labels(lines)
        print(f"Nalezeny labely: {labels}")

        machine_code_ints = assembler_pass(lines, labels)

        if machine_code_ints is not None:
            output_file = filename.rsplit('.', 1)[0] + ".bin"
            with open(output_file, 'wb') as f:
                for instr in machine_code_ints:
                    f.write(struct.pack('>I', instr))
            print(f"Uloženo do {output_file}")

    except FileNotFoundError:
        print("Soubor nenalezen")