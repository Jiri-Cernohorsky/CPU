library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_SPI is
end entity tb_SPI;

architecture behavior of tb_SPI is

    signal clk          : std_logic := '0';
    signal async_rst    : std_logic := '0';
    signal GPIO_pins_io : std_logic_vector(7 downto 0) := x"00";
    signal SPI_o        : std_logic_vector(2 downto 0);
    signal SPI_i        : std_logic;
    signal UART_RX : std_logic;
    signal UART_TX : std_logic;
    

    signal Bit_cnt      : integer range 0 to 31 := 7;
    signal Shift_reg    : std_logic_vector(31 downto 0);
    
    constant c_CLK_PERIOD : time := 20 ns;

    constant c_COMMAND : std_logic_vector(31 downto 0) := x"00508093";

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
        SPI_i <= '0';
        async_rst <= '1';
        wait for 500 ns;
        async_rst <= '0';
        Shift_reg <= c_COMMAND;
        Bit_cnt <= 31;
        -- čeká 32 cyklů
        for i in 31 downto 0 loop
            wait until rising_edge(SPI_o(0));    
        end loop;
        while true loop
            SPI_i <= Shift_reg(31);
            wait until rising_edge(SPI_o(0));
            if SPI_o(2) = '0' then
                    if Bit_cnt = 0 then
                        bit_cnt <= 31;
                    else
                        shift_reg <= shift_reg(30 downto 0) & '0';
                        bit_cnt <= bit_cnt - 1;
                     end if;
            end if;
        end loop;
        wait;
    end process;

end behavior;