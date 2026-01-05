library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_CPU is
end entity tb_CPU;

architecture behavior of tb_CPU is

    signal clk   : std_logic := '0';
    signal unsyncRst   : std_logic := '0';
    signal Buttons : std_logic_vector(3 downto 0) := "0000";
    signal Leds    : std_logic_vector(7 downto 0);

    constant clk_period : time := 10 ns;

begin

    -- Instance DUT
    uut: entity work.CPU
        port map(
            clk     => clk,
            async_rst     => unsyncRst,
            Buttons => Buttons,
            Leds    => Leds
        );

    -- Generování hodinového signálu
    clk_process : process
    begin
        while true loop
            clk <= '0';
            wait for clk_period / 2;
            clk <= '1';
            wait for clk_period / 2;
        end loop;
    end process;

    -- Testovací proces s opakováním
    stim_proc: process
    begin
		unsyncRst <= '1';
		wait for 500 ns;
		unsyncRst <= '0';
		wait for 500 ns;
        while true loop
            -- Aktivuj enable
            Buttons <= "0001";
            wait for 1 ms;

            -- Deaktivuj enable
            Buttons <= "0000";
            wait for 1 ms;
        end loop;

        -- Konec simulace
        wait;
    end process;

end behavior;
