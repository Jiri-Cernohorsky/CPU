#UART interrupt
org 0x0
#zachování registru
sw x1, 0(zero)
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

addi x2, x0, 2 # x2 = x0 + 2
addi x1, x0, 1 # x1 = x0 + 1
and x10, x10, x0   # x10 = x10 AND 0
addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 22
sll  x10, x10, x11      # x10 = 0x80000000
addi x10, x10, 0x104   # x10 = 0x80000104
lw x21, 4(x10) # načtení UART dat
sw x1, 200(x0) 
sw x21, 204(x0) # uložení UART dat
addi x2, x0, 2 # x2 = x0 + 2
sw x2, 16(x10) # vypnutí přerušení

 # načtení registru zpět
lw x1, 0(zero)
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


org 0x190 #setup
addi x10, x0, 0x200    # x10 = 0x00000200
addi x11, x0, 22
sll  x10, x10, x11      # x10 = 0x80000000
addi x1, x0, 1 
addi x2, x0, 2
sw x1, 0(x10) # maska interruptu globální zapnout UART
sw x2, 272(x10) # interrupt enable UART_RX

UART_LOOP: #defoult wait loop
lw x21, 200(x0) # cekani na uart
beq x21, x0, UART_LOOP # if x21 == x0 then UART_LOOP
sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
lw x21 204(x0) # načtení UART dat
sw x21, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
sw x1, 268(x10) # signal start pro UART

beq x21, x1, START #spustit program z flash
beq x21, x2, PROGRAM #načítat program z arduina

ERASE: # smazat data flash na adrese od arduina

    #získání adresy
    addi x27, x0, 8 # posun o jeden bajt
    addi x26, x0, 3 # počet bajtu
    addi x22, x0, 0 # x22 = x0 + 0 adresa ERASE
    ADDRESS_ERASE:
        lw x25, 200(x0) # adresa pro mazání
        beq x25, x0, ADDRESS_ERASE # if x22 == x0 then ADDRESS_ERASE
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x22, x22, x25 # x22 = x22 + x25
        sll x22, x22, x27 # x22 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, ADDRESS_ERASE_END # if x26 == x0 then ADDRESS_ERASE_END
        jal x15, ADDRESS_ERASE  # jump to ADDRESS_ERASE
    ADDRESS_ERASE_END:
    sw x22, 524(x10) # zápis do SPI_address

    # Write enable
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
        beq x22, x23, WE_CMD_SEND_END # if x22 == x23 then WE_CMD_SEND_END
        jal x15, WE_CMD_SEND  
    WE_CMD_SEND_END:

    # Erase
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
        jal x15, ERASE_CMD_SEND  
    ERASE_CMD_SEND_END:

    #status čtení
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
        jal x15, STATUS_CMD_SEND
    STATUS_CMD_SEND_END:
    lw x22 , 214(x10) #SPI_data_o
    and x22, x22, x1 # izolace prvního bitu
    beq x22, , x1, STATUS_WAIT # if x22 == x1 then STATUS_WAIT
    jal x15, END  # jump to END
    


START: #spustit program z flash
    #získání adres
    addi x27, x0, 8 # posun o jeden bajt
    addi x26, x0, 3 # počet bajtu
    addi x22, x0, 0  # x22 = x0 + 0 adresa Flash
    ADDRESS_FLASH:
        lw x25, 200(x0) # adresa odkud čtu v FLASH
        beq x25, x0, ADDRESS_FLASH # if x22 == x0 then ADDRESS_FLASH
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x22, x22, x25 # x22 = x22 + x25
        sll x22, x22, x27 # x22 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, ADDRESS_FLASH_END # if x26 == x0 then ADDRESS_FLASH_END
        jal x15, ADDRESS_FLASH  # jump to ADDRESS_FLASH
    ADDRESS_FLASH_END:
    sw x22, 524(x10) # zápis do SPI_address

    addi x26, x0, 2 # počet bajtu
    addi x23, x0, 0  # x23 = x0 + 0 adresa RAM
    ADDRESS_RAM:
        lw x25, 200(x0) # adresa kam zapisuju v RAM
        beq x25, x0, ADDRESS_RAM # if x22 == x0 then ADDRESS_RAM
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x23, x23, x25 # x23 = x23 + x25
        sll x23, x23, x27 # x23 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, ADDRESS_RAM_END # if x26 == x0 then ADDRESS_RAM_END
        jal x15, ADDRESS_RAM  # jump to ADDRESS_RAM
    ADDRESS_RAM_END:

    #počet slov
    addi x26, x0, 2 # počet bajtu
    addi x29, x0, 0  # x23 = x0 + 0 počet slov
    WORD_COUNT:
        lw x25, 200(x0) # počet slov k přečtení
        beq x25, x0, WORD_COUNT # if x22 == x0 then WORD_COUNT
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x29, x29, x25 # x29 = x29 + x25
        sll x29, x29, x27 # x29 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, WORD_COUNT_END # if x26 == x0 then WORD_COUNT_END
        jal x15, WORD_COUNT  # jump to WORD_COUNT
    WORD_COUNT_END:

    #přidání k adrese RAM '1' na druhej MSB aby zapisoval do instr_MEM
    addi x30, x0, 1
    addi x31, x0, 30
    sll x30, x30, x31 # x30 << x31
    add x23, x23, x30  # x23 = x23 + x30
    WORD_LOOP:
        addi x28, x0, 0 # slovo
        addi x26, x0, 4 # počet bajtu
        READ_LOOP:
            addi x20, x0, 9 # 001001 Read_ready = 0 EN_comm = 1, CMD_sel = 001 read
            sw x20, 516(x10) # SPI_control_i
            WAIT_FOR_DATA: 
                lw x24, 520(x10) # SPI_control_o
                beq x24, x1, WAIT_FOR_DATA_END
                jal x15, WAIT_FOR_DATA  # jump to WAIT_FOR_DATA
            WAIT_FOR_DATA_END:
                lw x25, 532(x10) # SPI_data_o
                addi x20, x0, 25 # 011001 Read_ready = 1 EN_comm = 1, CMD_sel = 001 read
                sw x20, 516(x10) # SPI_control_i
                add x28, x28, x25  # x28 = x28 + x25
                sll x28, x28, x27 # x28 << x27
                sub x26, x26, x1 # x26 = x26 - x1
                beq x26, x0, WORD_READ  # if x26 == x0 then WORD_READ
                jal x15, READ_LOOP  # jump to READ_LOOP
        WORD_READ:
            sw x28, 0(x23) # zápis do instr_mem
            addi x23, x23, 4 # x23 = x23 + 4
            sub x29, x29, x1 # x29 = x29 - 1
            beq x29, x0, END_READ  # if x29 == x0 then END_READ
            jal x15, WORD_LOOP  # jump to WORD_LOOP
    END_READ:
        addi x23, x0, 4 # CMD_done
        sw zero, 516(x10) # SPI_control_i (vypnuti EN_com)
        READ_CMD_SEND:
            lw x22, 520(x10) # SPI_control_o
            beq x22, x23, READ_CMD_SEND_END # if x22 == x23 then READ_CMD_SEND_END
            jal x15, READ_CMD_SEND  
        READ_CMD_SEND_END:
        sw x21, 260(x10) # poslat flag done UARTu
        sw x1, 268(x10) # signal start pro UART
        sw x1, 4(x10) # Start_program = 1
        jal x15, UART_LOOP



PROGRAM: #načítat program z arduina

    #získání adresy
    addi x27, x0, 8 # posun o jeden bajt
    addi x26, x0, 3 # počet bajtu
    addi x22, x0, 0  # x22 = x0 + 0 adresa PROGRAM
    ADDRESS_PROGRAM:
        lw x25, 200(x0) # adresa pro programování
        beq x25, x0, ADDRESS_PROGRAM # if x22 == x0 then ADDRESS_PROGRAM
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x22, x22, x25 # x22 = x22 + x25
        sll x22, x22, x27 # x22 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, ADDRESS_PROGRAM_END # if x26 == x0 then ADDRESS_PROGRAM_END
        jal x15, ADDRESS_PROGRAM  # jump to ADDRESS_PROGRAM
    ADDRESS_PROGRAM_END:
    sw x22, 524(x10) # zápis do SPI_address

    #počet slov
    addi x26, x0, 2 # počet bajtu
    addi x29, x0, 0 # x23 = x0 + 0 počet slov
    WORD_COUNT1:
        lw x25, 200(x0) # počet slov k přečtení
        beq x25, x0, WORD_COUNT1 # if x22 == x0 then WORD_COUNT1
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x25 204(x0) # načtení UART dat
        sw x25, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART
        add x29, x29, x25 # x29 = x29 + x25
        sll x29, x29, x27 # x29 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, WORD_COUNT_END1 # if x26 == x0 then WORD_COUNT_END1
        jal x15, WORD_COUNT1  # jump to WORD_COUNT1
    WORD_COUNT_END1:

    # Write enable
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
        jal x15, WE_CMD_SEND1  
    WE_CMD_SEND_END1:

    # Zapisování
    addi x23, x0, 2 # Write_start
    DATA_NEXT: 
        #odpočet slov
        addi x20, x0, 10 # 001010 Write_ready = 0 EN_comm = 1, CMD_sel = 010
        sw x20, 516(x10) # SPI_control_i
        beq x29, x0, END_WRITE
        sub x29, x29, x1 # x29 = x29 - x1

        addi x25, x0, 0 # x25 = x0 + 0 data
        addi x26, x0, 4
        DATA:
        lw x22, 200(x0) # načtení dat z UART
        beq x22, x0, DATA # if x22 == x0 then DATA
        sw zero, 200(x0) #ulozeni 0 do načítací UART adresy
        lw x22 204(x0) # načtení UART dat
        sw x22, 260(x10) # poslat to stejné zpět UARTu pro kontrolu
        sw x1, 268(x10) # signal start pro UART

        add x25, x25, x22 # x25 = x25 + x22
        sll x25, x25, x27 # x25 << x27
        sub x26, x26, x1 # x26 = x26 - x1
        beq x26, x0, CONTINUE
            jal x15, DATA  # jump to DATA
        CONTINUE:
            sw x25,  528(x10) # SPI_data_in
            addi x20, x0, 26 # 011010 Write_ready = 1 EN_comm = 1, CMD_sel = 010
            sw x20, 516(x10) # SPI_control_i
            WRITEN:
                lw x22, 520(x10) # SPI_control_o
                beq x22, x23, DATA_NEXT # if x22 == x23
                jal x15, WRITEN 
    END_WRITE:
        addi x23, x0, 4 # CMD_done
        sw x0, 516(x10) # SPI_control_i (vypnuti EN_com)
        CMD_DONE:
            lw x22, 520(x10) # SPI_control_o
            beq x22, x23, CMD_DONE_END # if x22 == x23 then ERASE_CMD_SEND
            jal x15, CMD_DONE
        CMD_DONE_END:


    #status čtení
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
        jal x15, STATUS_CMD_SEND1
    STATUS_CMD_SEND_END1:
    lw x22 , 214(x10) #SPI_data_o
    and x22, x22, x1 # izolace prvního bitu
    beq x22, , x1, STATUS_WAIT1 # if x22 == x1 then STATUS_WAIT1

END:
    sw x21, 260(x10) # poslat flag done UARTu
    sw x1, 268(x10) # signal start pro UART
    jal x15, UART_LOOP