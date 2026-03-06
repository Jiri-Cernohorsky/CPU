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
    signal SPI_i        : std_logic;
    signal UART_RX : std_logic := '1';
    signal UART_TX : std_logic;
    
    signal clk_div_cnt : integer range 0 to 3 := 0; --dělič hodin
    signal spi_tick    : std_logic := '0';

    constant c_CLK_PERIOD : time := 20 ns;
    
    constant c_BAUD_RATE  : integer := 9600;
    constant c_BIT_PERIOD : time := 1000000000 ns / c_BAUD_RATE;

    signal Data_i_UART : std_logic_vector(7 downto 0); 
    signal Data_o_UART  : std_logic_vector(7 downto 0);
    signal Data_i_SPI : std_logic_vector(7 downto 0); 
    signal Data_o_SPI  : std_logic_vector(7 downto 0);

     type SEND_DATA_t is array (0 to 25) of std_logic_vector(7 downto 0) ;
    constant c_SEND_DATA : SEND_DATA_t := ( x"03",  -- erase
                                            x"00",  -- erase adresa
                                            x"00",  -- erase adresa
                                            x"00",  -- erase adresa
                                            x"02",  -- program
                                            x"00",  -- program adresa flash
                                            x"00",  -- program adresa flash
                                            x"00",  -- program adresa flash
                                            x"00",  -- program počet slov
                                            x"02",  -- program počet slov
                                            x"00",  -- program data
                                            x"10",  -- program data
                                            x"80",  -- program data
                                            x"93",  -- program data
                                            x"40",  -- program data
                                            x"11",  -- program data
                                            x"01",  -- program data
                                            x"33",  -- program data
                                            x"01",  -- start
                                            x"00",  -- start adresa flash
                                            x"00",  -- start adresa flash
                                            x"00",  -- start adresa flash
                                            x"00",  -- start adresa RAM
                                            x"00",  -- start adresa RAM
                                            x"00",  -- start počet slov
                                            x"02"); -- start počet slov
begin

    CPU_inst : entity work.CPU
        port map(
            clk          => clk,
            async_rst    => async_rst,
            GPIO_pins_io => GPIO_pins_io,
            SPI_o        => SPI_o,
            SPI_i        => SPI_i,
            UART_TX => UART_TX,
            UART_RX => UART_RX
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

     SPI_clk_gen : process (clk) is
    begin
        if rising_edge(clk) then
            if clk_div_cnt = 3 then
                clk_div_cnt <= 0;
                spi_tick <= '1';
            else
                clk_div_cnt <= clk_div_cnt + 1;
                spi_tick <= '0';
            end if;

        end if;
    end process SPI_clk_gen;

    sim_proc_UART: process
    begin
        async_rst <= '1';
        wait for 1000 ns;
        async_rst <= '0';
        wait for 1000 ns;
			
        for i in c_SEND_DATA'range loop

            Data_i_UART  <= c_SEND_DATA(i);

            --poslat data
            UART_RX  <= '0'; --start bit
            wait for c_BIT_PERIOD;
            for i in 0 to 7 loop  -- poslat bajt
                UART_RX <= Data_i_UART(i);
                wait for c_BIT_PERIOD;
            end loop;
            -- Stop bit
            UART_RX <= '1';

            --čeká na stejná data zpátky
            wait until falling_edge(UART_TX);
            wait for c_BIT_PERIOD/2;
            if UART_TX = '0' then -- pokud je stále start bit
                -- Čtení 8 datových bitů
                for i in 0 to 7 loop
                    wait for c_BIT_PERIOD;
                    Data_o_UART(i) <= UART_TX;
                end loop;
                wait for c_BIT_PERIOD;  
            end if;


            -- kontrola jestli se vrátil
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
    begin
        --WE
        --cmd
        wait until falling_edge(SPI_o(2));
         -- Čtení 8 datových bitů
                for i in 0 to 7 loop
                    wait until spi_tick = '1';
                    Data_o_SPI(i) <= UART_TX;
                end loop;
            report "Data_o_UART: " & integer'image(to_integer(unsigned(Data_o_UART)));
            if x"06" = Data_o_UART then
                report "WE";
            else
                report "didnt WE";
            end if;

        --ERASE
        --cmd
        wait until falling_edge(SPI_o(2));
         -- Čtení 8 datových bitů
                for i in 0 to 7 loop
                    wait until spi_tick = '1';
                    Data_o_SPI(i) <= UART_TX;
                end loop;
            report "Data_o_UART: " & integer'image(to_integer(unsigned(Data_o_UART)));
            if x"d8" = Data_o_UART then
                report "start erase";
            else
                report "didnt start erase";
            end if;
        --adres
        for i in 0 to 2 loop
            wait until falling_edge(SPI_o(2));
         -- Čtení 8 datových bitů
                for i in 0 to 7 loop
                    wait until spi_tick = '1';
                    Data_o_SPI(i) <= UART_TX;
                end loop;
            report "Data_o_UART: " & integer'image(to_integer(unsigned(Data_o_UART)));
            if x"00" = Data_o_UART then
                report "adresa spravna";
            else
                report "adresa spatna";
            end if;
        end loop;
        
    end process sim_proc_SPI;
    
end behavior;