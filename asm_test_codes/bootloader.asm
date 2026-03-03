org 0x0 #setup
addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 18
sll  x10, x10, x11      # x10 = 0x80000000
addi x2, X2, 2
sw x2, (x10) # maska interruptu globální zapnout UART
addi x1, x1, 1 
sw x2, 272(x10) # interrupt enable UART_RX

UART_LOOP: #defoult wait loop
lw x21, 200(x0) # načtení UART dat
beq x21, x0, UART_LOOP # if x21 == x0 then UART_LOOP
sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
sw x21, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
sw x1, 268(x10) # signal start pro UART

beq x21, x1, START #spustit program z flash
beq x21, x2, PROGRAM #načítat program z arduina

ERASE: # smazat data flash na adrese od arduina
    lw x22, 200(x0) # načtení adresy pro mazání z UART 
    beq x22, x0, ERASE # if x21 == x0 then ERASE
    sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
    sw x22,  524(x10) # SPI_address

    addi x20, x0, 8 # 001011 EN_comm = 1, CMD_sel = 000
    sw x20, 516(x10) # SPI_control_i
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    addi x23, x0, 4 # CMD_done
    sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
    WE_CMD_SEND:
        lw x22, 520(x10) # SPI_control_o
        beq x22, x23, WE_CMD_SEND_END # if x22 == x23 then ERASE_CMD_SEND
        jal WE_CMD_SEND  
    WE_CMD_SEND_END:

    addi x20, x0, 11 # 001011 EN_comm = 1, CMD_sel = 011
    sw x20, 516(x10) # SPI_control_i
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
    ERASE_CMD_SEND:
        lw x22, 520(x10) # SPI_control_o
        beq x22, x23, ERASE_CMD_SEND_END # if x22 == x23 then ERASE_CMD_SEND
        jal ERASE_CMD_SEND  
    ERASE_CMD_SEND_END:

    STATUS_WAIT:
    addi x20, x0, 12 # 001100 EN_comm = 1, CMD_sel = 100
    sw x20, 516(x10) # SPI_control_i
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
    STATUS_CMD_SEND:
        lw x22, 520(x10) # SPI_control_o
        beq x22, x23, STATUS_CMD_SEND_END # if x22 == x23 then STATUS_CMD_SEND_END
        jal STATUS_CMD_SEND 
    STATUS_CMD_SEND_END:
    lw x22 , 214(x10) #SPI_data_o
    and x22, x22, x1 # izolace prvního bitu
    beq x22, , x1, STATUS_WAIT # if x22 == x1 then STATUS_WAIT
    jal END  # jump to END
    
START: #spustit program z flash

    
PROGRAM: #načítat program z arduina
    lw x22, 200(x0) # načtení adresy pro zápis dat z UART 
    beq x22, x0, PROGRAM # if x22 == x0 then PROGRAM
    sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
    sw x22, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
    sw x1, 268(x10) # signal start pro UART
    sw x22,  524(x10) # SPI_address

    addi x20, x0, 8 # 001011 EN_comm = 1, CMD_sel = 000
    sw x20, 516(x10) # SPI_control_i
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    add zero, zero, zero # nop
    addi x23, x0, 4 # CMD_done
    sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
    WE_CMD_SEND1:
        lw x22, 520(x10) # SPI_control_o
        beq x22, x23, WE_CMD_SEND_END1 # if x22 == x23 then WE_CMD_SEND_END1
        jal WE_CMD_SEND1 
    WE_CMD_SEND_END1:

    addi x25, x0, 0 # x25 = x0 + 0
    addi x26, x0, 3
    addi x27, x0, 8
    WORD_NUM: #načíst počet slov;
        lw x24, 200(x0) # načtení počtu bytů z UART 
        beq x24, x0, WORD_NUM # if x24 == x0 then WORD_NUM
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        sw x24, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x25, x25, x24 # x25 = x25 + x24
        sll x25, x25, x27 # x25 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, CONTINUE
        jal WORD_NUM  # jump to WORD_NUM
        CONTINUE:
        add x24, x25, x0 # x24 = x25 + x0
        sw x25,  528(x10) # SPI_data_in
        addi x20, x0, 24 # 011000 Write_ready = 1 EN_comm = 1, CMD_sel = 000
        sw x20, 516(x10) # SPI_control_i
        addi x23, x0, 2 # Write_start
        jal WRITEN

    DATA_NEXT: 
        addi x20, x0, 8 # 001000 Write_ready = 0 EN_comm = 1, CMD_sel = 000
        sw x20, 516(x10) # SPI_control_i
        sub x24, x24, x1 # x24 = x24 - x1
        beq x24, x0, END_WRITE

        addi x25, x0, 0 # x25 = x0 + 0
        addi x26, x0, 3
        DATA:
        lw x22, 200(x0) # načtení dat z UART
        beq x22, x0, DATA # if x22 == x0 then DATA
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        sw x22, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART

        add x25, x25, x22 # x25 = x25 + x22
        sll x25, x25, x27 # x25 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, CONTINUE
        jal BYTE_NUM  # jump to BYTE_NUM
        CONTINUE:
        add x22, x25, x0 # x22 = x25 + x0
        sw x22,  528(x10) # SPI_data_in
        addi x20, x0, 24 # 011000 Write_ready = 1 EN_comm = 1, CMD_sel = 000
        sw x20, 516(x10) # SPI_control_i
        WRITEN:
            lw x22, 520(x10) # SPI_control_o
            beq x22, x23, DATA_NEXT # if x22 == x23
            jal WRITEN 
#-----------------------------------sem zkontrolovano--------------------------------------
    END_WRITE:
        addi x23, x0, 4 # CMD_done
        sw x0, 516(x10) # SPI_control_i (vypnuti EN_com)
        CMD_DONE:
            lw x22, 520(x10) # SPI_control_o
            beq x22, x23, CMD_DONE_END # if x22 == x23 then ERASE_CMD_SEND
            jal CMD_DONE 
        CMD_DONE_END:
    STATUS_WAIT1:
        addi x20, x0, 12 # 001100 EN_comm = 1, CMD_sel = 100
        sw x20, 516(x10) # SPI_control_i
        add zero, zero, zero # nop
        add zero, zero, zero # nop
        add zero, zero, zero # nop
        add zero, zero, zero # nop
        add zero, zero, zero # nop
        sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
        STATUS_CMD_SEND1:
            lw x22, 520(x10) # SPI_control_o
            beq x22, x23, STATUS_CMD_SEND_END1 # if x22 == x23 then STATUS_CMD_SEND_END1
            jal STATUS_CMD_SEND1
        STATUS_CMD_SEND_END1:
        lw x22 , 214(x10) #SPI_data_o
        and x22, x22, x1 # izolace prvního bitu
        beq x22, x1, STATUS_WAIT1 # if x22 == x1 then STATUS_WAIT1
END:
sw x21, 260(x10) # poslat flag done UARTu
sw x1, 268(x10) # signal start pro UART
jal zero, UART_LOOP


#UART interrupt
org 0x190
#zachování registru
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

and x10, x10, x0   # x10 = x10 AND 0
addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 18
sll  x10, x10, x11      # x10 = 0x80000000
addi x10, x10, 0x104   # x10 = 0x80000104
lw x21, 4(x10) # načtení UART dat
sw x21, 200(x0) # uložení UART dat
sw x21, 16(x10) # vypnutí přerušení

 # načtení registru zpět
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