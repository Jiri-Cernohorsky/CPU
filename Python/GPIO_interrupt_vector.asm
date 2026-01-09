sw x1, 0(x0)
sw x2, 4(zero)
sw x3, 8(zero)
sw x4, 12(zero)
sw x5, 16(zero)
sw x6, 20(zero)
sw x7, 24(zero)
sw x8, 28(zero)
sw x9, 32(zero)
sw x10, 36(zero)
sw x11, 40(zero)
sw x12, 44(zero)
sw x13, 48(zero)
sw x14, 52(zero)
sw x15, 56(zero)
sw x16, 60(zero)
sw x17, 64(zero)
sw x18, 68(zero)
sw x19, 72(zero)
sw x20, 76(zero)
sw x21, 80(zero)
sw x22, 84(zero)
sw x23, 88(zero)
sw x24, 92(zero)
sw x25, 96(zero)
sw x26, 100(zero)
sw x27, 104(zero)
sw x28, 108(zero)
sw x29, 112(zero)
sw x30, 116(zero)
sw x31, 120(zero)
addi s1, x0, 0x400
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
add s1, s1, s1
lw t1, 8(s1)
addi x1, zero, 1 # x1 = zero + 1
addi x2, zero, 2 # x2 = zero + 2
slt x4, t1, x2
beq x4, x0, SKIP # if x4 == x2 then SKIP
add t1, t1, x2 # t1 = t1 + x2
sw t1, 8(s1)
SKIP:
lw t0, 4(s1)
slt x4, t0, x1     # x4 = 1 pokud t0 < x1, jinak 0
beq x4, x1, ELSE2 # if x4 == x2 then ELSE2
add t0, t0, x2 # t0 = t0 + x2 
jal zero, KONEC
ELSE2:
sub t0, t0, x2 # t0 = t0 - x2
KONEC:
sw t0, 4(s1)
sw x1, 16(s1)
lw x1, 0(x0)
lw x2, 4(zero)
lw x3, 8(zero)
lw x4, 12(zero)
lw x5, 16(zero)
lw x6, 20(zero)
lw x7, 24(zero)
lw x8, 28(zero)
lw x9, 32(zero)
lw x10, 36(zero)
lw x11, 40(zero)
lw x12, 44(zero)
lw x13, 48(zero)
lw x14, 52(zero)
lw x15, 56(zero)
lw x16, 60(zero)
lw x17, 64(zero)
lw x18, 68(zero)
lw x19, 72(zero)
lw x20, 76(zero)
lw x21, 80(zero)
lw x22, 84(zero)
lw x23, 88(zero)
lw x24, 92(zero)
lw x25, 96(zero)
lw x26, 100(zero)
lw x27, 104(zero)
lw x28, 108(zero)
lw x29, 112(zero)
lw x30, 116(zero)
lw x31, 120(zero)
mret