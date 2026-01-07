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
addi x1, x1, 1
sw x1, 0(s1)
sw x1, 0xC(s1)
loop:
jal zero, loop
