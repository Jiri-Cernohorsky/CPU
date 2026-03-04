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
    
    constant c_CLK_PERIOD : time := 20 ns;
    
    constant c_BAUD_RATE  : integer := 9600;
    constant c_BIT_PERIOD : time := 1000000000 ns / c_BAUD_RATE;

    signal Data_i : std_logic_vector(7 downto 0); 
    signal Data_o  : std_logic_vector(7 downto 0);

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

    sim_proc: process
    begin
        async_rst <= '1';
        wait for 1000 ns;
        async_rst <= '0';
        wait for 1000 ns;
			
        for i in c_SEND_DATA'range loop

            Data_i  <= c_SEND_DATA(i);

            --poslat data
            UART_RX  <= '0'; --start bit
            wait for c_BIT_PERIOD;
            for i in 0 to 7 loop  -- poslat bajt
                UART_RX <= Data_i(i);
                wait for c_BIT_PERIOD;
            end loop;
            -- Stop bit
            UART_RX <= '1';

            --čeká na stejná data zpátky
            wait until falling_edge(UART_TX);
            -- posun do středu periody
            wait for c_BIT_PERIOD / 2;
            if UART_TX = '0' then -- pokud je stále start bit
                -- Čtení 8 datových bitů
                for i in 0 to 7 loop
                    wait for c_BIT_PERIOD;
                    Data_o(i) <= UART_TX;
                end loop;
            end if;

            -- kontrola jestli se vrátil
            if Data_i = Data_o then
                report "did return";
            else
                report "didnt return";
            end if;
        end loop;
    end process;

end behavior;