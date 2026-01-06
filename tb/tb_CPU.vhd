library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_CPU is
end entity tb_CPU;

architecture behavior of tb_CPU is

    signal clk   : std_logic := '0';
    signal async_rst   : std_logic := '0';
    signal GPIO_pins_io : std_logic_vector(7 downto 0) := x"00";

    constant c_CLK_PERIOD : time := 20 ns;

begin

    CPU_inst : entity work.CPU
        port map(
            clk          => clk,
            async_rst    => async_rst,
            GPIO_pins_io => GPIO_pins_io
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
		wait for 500 ns;
        while true loop
            GPIO_pins_io(0) <= '0';
            wait for 1 ms;

            GPIO_pins_io(0) <= '1';
            wait for 1 ms;
        end loop;
        wait;
    end process;

end behavior;
