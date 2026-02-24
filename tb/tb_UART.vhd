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
        while true loop
            
            --dodelat

        end loop;
        wait;
    end process;

end behavior;