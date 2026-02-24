library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_UART is
end entity tb_UART;

architecture behavior of tb_UART is

    signal clk          : std_logic := '0';
    signal async_rst    : std_logic := '0';
    signal GPIO_pins_io : std_logic_vector(7 downto 0) := x"00";
    signal SPI_o        : std_logic_vector(2 downto 0);
    signal SPI_i        : std_logic;
    signal UART_RX : std_logic;
    signal UART_TX : std_logic;
    
    constant c_CLK_PERIOD : time := 20 ns;

    constant c_BAUD_RATE  : integer := 9600;
    constant c_BIT_PERIOD : time := 1000000000 ns / c_BAUD_RATE;

    signal tb_received_data  : std_logic_vector(7 downto 0) := x"00";
    signal data_in : std_logic_vector(7 downto 0) := x"41";
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

    stim_proc: process
    begin
        async_rst <= '1';
        wait for 500 ns;
        async_rst <= '0';
        wait for 1000 ns;  
        -- start bit  
        UART_RX <= '0';
        wait for c_BIT_PERIOD;
        for i in 0 to 7 loop -- poslani dat
            UART_RX <= data_in(i);
            wait for c_BIT_PERIOD;
        end loop;
        -- Stop bit
        UART_RX <= '1';
        while true loop
        end loop;
    end process;
    
    uart_rx_from_cpu_proc : process
    begin
        -- Start bit
        wait until falling_edge(UART_TX);
        -- posun do středu periody
        wait for c_BIT_PERIOD / 2;
        if UART_TX = '0' then -- pokud je stále start bit
            -- Čtení 8 datových bitů
            for i in 0 to 7 loop
                wait for c_BIT_PERIOD;
                tb_received_data(i) <= UART_TX;
            end loop;
            while true loop
        end loop;
        end if;
    end process;
end behavior;