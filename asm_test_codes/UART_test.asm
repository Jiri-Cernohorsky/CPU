addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 18
sll  x10, x10, x11      # x10 = 0x80000000
addi x3, X3, 3
sw x3, (x10) # maska interruptu globální zapnout UART a GPIO 
addi x10, x10, 0x104   # x10 = 0x80000104
addi x1, x1, 1
addi x2, x2, 2
sw x2, 8(x10) # interrupt enable
LOOP:
lw t1, 200(x0) # načtení UART dat
beq t1, x0, LOOP # if t1 == x0 then LOOP
sll t1, t1, x1 # posun o 1 do leva
sw t1, 0(x10) # poslat upravenou hodnotu UARTu
sw x1, 4(x10) # signal start pro UART
and t1, t1, x0   # t1 = t1 AND 0
jal zero, LOOP
#UART interrupt
sw x1, 0(zero) #zachování registru
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

and x10, x10, x0   # t1 = t1 AND 0
addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 18
sll  x10, x10, x11      # x10 = 0x80000000
addi x10, x10, 0x104   # x10 = 0x80000104
addi x2, x2, 2
lw t1, 0(x10) # načtení UART dat
sw t1, 200(x0) # uložení UART dat
sw t1, 12(x10) # vypnutí přerušení

lw x1, 0(x0) # načtení registru zpět
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
