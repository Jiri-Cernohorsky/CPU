library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_Bootloader is
end entity tb_Bootloader;

architecture behavior of tb_Bootloader is

    -- CPU porty
    signal clk          : std_logic := '0';
    signal async_rst    : std_logic := '0';
    signal GPIO_pins_io : std_logic_vector(7 downto 0) := x"00";
    signal SPI_o        : std_logic_vector(2 downto 0);
    signal SPI_i        : std_logic := '0';
    signal UART_RX      : std_logic := '1';
    signal UART_TX      : std_logic;

    constant c_CLK_PERIOD : time := 20 ns;

    constant c_BAUD_RATE  : integer := 9600;
    constant c_BIT_PERIOD : time := 1000000000 ns / c_BAUD_RATE;

    signal Data_i_UART : std_logic_vector(7 downto 0);
    signal Data_o_UART : std_logic_vector(7 downto 0);

    type SEND_DATA_UART_t is array (0 to 25) of std_logic_vector(7 downto 0);
    constant c_SEND_DATA_UART : SEND_DATA_UART_t := (
        x"03", x"00", x"00", x"04",   -- erase + adresa
        x"02", x"00", x"00", x"04",    -- program + adresa flash
        x"00", x"02",                  -- program počet slov
        x"00", x"10", x"80", x"93",   -- program data
        x"40", x"11", x"01", x"33",   -- program data
        x"01",                          -- start
        x"00", x"00", x"00",           -- start adresa flash
        x"00", x"00",                  -- start adresa RAM
        x"00", x"02"                   -- start počet slov
    );

    type SEND_DATA_SPI_t is array (0 to 25) of std_logic_vector(7 downto 0);
    constant c_SEND_DATA_SPI : SEND_DATA_SPI_t := (
        x"01", x"00",                  -- status erase (busy=1, pak busy=0)
        x"01", x"01", x"00",           -- status program
        x"00", x"10", x"80", x"93",   -- start data
        x"40", x"11", x"01", x"33",   -- start data
        x"00", x"00", x"00", x"00",   -- padding
        x"00", x"00", x"00", x"00",
        x"00", x"00", x"00", x"00",
        x"00"
    );

begin

    CPU_inst : entity work.CPU
        port map(
            clk          => clk,
            async_rst    => async_rst,
            GPIO_pins_io => GPIO_pins_io,
            SPI_o        => SPI_o,
            SPI_i        => SPI_i,
            UART_TX      => UART_TX,
            UART_RX      => UART_RX
        );

    clk_process : process
    begin
        while true loop
            clk <= '0';
            wait for c_CLK_PERIOD / 2;
            clk <= '1';
            wait for c_CLK_PERIOD / 2;
        end loop;
    end process;

    -- ---------------------------------------------------------------------------
    -- UART simulátor — beze změny, logika byla správná
    -- ---------------------------------------------------------------------------
    sim_proc_UART : process
    begin
        async_rst <= '1';
        wait for 1000 ns;
        async_rst <= '0';
        wait for 1000 ns;

        for i in c_SEND_DATA_UART'range loop

            Data_i_UART <= c_SEND_DATA_UART(i);

            -- Start bit
            UART_RX <= '0';
            wait for c_BIT_PERIOD;
            -- 8 datových bitů
            for j in 0 to 7 loop
                UART_RX <= c_SEND_DATA_UART(i)(j);
                wait for c_BIT_PERIOD;
            end loop;
            -- Stop bit
            UART_RX <= '1';

            -- Čeká na echo zpět
            wait until falling_edge(UART_TX);
            wait for c_BIT_PERIOD / 2;
            if UART_TX = '0' then
                for j in 0 to 7 loop
                    wait for c_BIT_PERIOD;
                    Data_o_UART(j) <= UART_TX;
                end loop;
                wait for c_BIT_PERIOD;
            end if;

            report "Data_i_UART: " & integer'image(to_integer(unsigned(Data_i_UART)));
            report "Data_o_UART: " & integer'image(to_integer(unsigned(Data_o_UART)));
            if Data_i_UART = Data_o_UART then
                report "did return";
            else
                report "didnt return";
            end if;

        end loop;
    end process;

    sim_proc_SPI : process is

        variable v_spi_cnt : integer range 0 to 25 := 0;

        procedure read_byte_MOSI(signal spi_bus : in std_logic_vector(2 downto 0);
                                  result        : out std_logic_vector(7 downto 0)) is
        begin
            for b in 0 to 7 loop
                wait until rising_edge(spi_bus(0));
                result(b) := spi_bus(1);  -- MOSI = SPI_o(1)
            end loop;
        end procedure;

        procedure send_byte_MISO(signal   spi_miso : out std_logic;
                                  constant data     : in  std_logic_vector(7 downto 0)) is
        begin
            for b in 0 to 7 loop
                wait until falling_edge(SPI_o(0));
                spi_miso <= data(b);
            end loop;
        end procedure;

        variable v_byte : std_logic_vector(7 downto 0);

    begin

        SPI_i <= '0';

        -- WRITE ENABLE před ERASE
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "WE cmd: 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"06" then report "WE OK"; else report "WE FAIL"; end if;

        -- ERASE — příkaz + 3 bajty adresy
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "ERASE cmd: 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"d8" then report "ERASE cmd OK"; else report "ERASE cmd FAIL"; end if;

        for i in 0 to 2 loop
            wait until falling_edge(SPI_o(2));
            read_byte_MOSI(SPI_o, v_byte);
            report "ERASE addr byte " & integer'image(i) & ": 0x" & integer'image(to_integer(unsigned(v_byte)));
            if v_byte = x"00" then report "adresa spravna"; else report "adresa spatna"; end if;
        end loop;

        -- Posíláme 2 bajty statusu: 0x01 (busy), 0x00 (idle)
        for i in 0 to 1 loop
            send_byte_MISO(SPI_i, c_SEND_DATA_SPI(v_spi_cnt));
            report "Sent MISO status byte: 0x" & integer'image(to_integer(unsigned(c_SEND_DATA_SPI(v_spi_cnt))));
            v_spi_cnt := v_spi_cnt + 1; 
        end loop;


        -- WRITE ENABLE před PROGRAM
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "WE cmd (pre-program): 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"06" then report "WE OK"; else report "WE FAIL"; end if;

        -- PROGRAM — příkaz + 3 bajty adresy + data
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "PROGRAM cmd: 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"02" then report "PROGRAM cmd OK"; else report "PROGRAM cmd FAIL"; end if;

        for i in 0 to 2 loop
            wait until falling_edge(SPI_o(2));
            read_byte_MOSI(SPI_o, v_byte);
            report "PROGRAM addr byte " & integer'image(i) & ": 0x" & integer'image(to_integer(unsigned(v_byte)));
            if v_byte = x"00" then report "adresa spravna"; else report "adresa spatna"; end if;
        end loop;

        -- Data bajty (bootloader zapisuje 2 slova = 8 bajtů, čteme kolik přijde)
        for i in 0 to 2 loop
            wait until falling_edge(SPI_o(2));
            read_byte_MOSI(SPI_o, v_byte);
            report "PROGRAM data byte " & integer'image(i) & ": 0x" & integer'image(to_integer(unsigned(v_byte)));
        end loop;

        -- STATUS READ po PROGRAM — příkaz + 3 bajty odpovědi
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "STATUS cmd (post-program): 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"05" then report "STATUS cmd OK"; else report "STATUS cmd FAIL"; end if;

        for i in 0 to 2 loop
            send_byte_MISO(SPI_i, c_SEND_DATA_SPI(v_spi_cnt));
            report "Sent MISO status byte: 0x" & integer'image(to_integer(unsigned(c_SEND_DATA_SPI(v_spi_cnt))));
            v_spi_cnt := v_spi_cnt + 1;  
        end loop;

        -- START — READ příkaz + 3 bajty adresy + 8 bajtů dat zpět do RAM
        wait until falling_edge(SPI_o(2));
        read_byte_MOSI(SPI_o, v_byte);
        report "START READ cmd: 0x" & integer'image(to_integer(unsigned(v_byte)));
        if v_byte = x"03" then report "READ cmd OK"; else report "READ cmd FAIL (expected 0x03)"; end if;

        for i in 0 to 2 loop
            wait until falling_edge(SPI_o(2));
            read_byte_MOSI(SPI_o, v_byte);
            report "START addr byte " & integer'image(i) & ": 0x" & integer'image(to_integer(unsigned(v_byte)));
            if v_byte = x"00" then report "adresa spravna"; else report "adresa spatna"; end if;
        end loop;

        -- Posíláme 8 bajtů programu (2 instrukce × 4 bajty)
        for i in 0 to 7 loop
            send_byte_MISO(SPI_i, c_SEND_DATA_SPI(v_spi_cnt));
            report "Sent program byte " & integer'image(i) & ": 0x" & integer'image(to_integer(unsigned(c_SEND_DATA_SPI(v_spi_cnt))));
            v_spi_cnt := v_spi_cnt + 1;
        end loop;
        report "SPI simulace dokoncena.";
        wait;

    end process sim_proc_SPI;

end behavior;