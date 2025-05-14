library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_CPU is
end entity tb_CPU;

architecture behavior of tb_CPU is

    signal clk   : std_logic := '0';
    signal rst   : std_logic := '0';
    signal Buttons : std_logic_vector(7 downto 0) := "00000000";
    signal Leds    : std_logic_vector(7 downto 0);

    constant clk_period : time := 10 ns;

begin

    -- Instance DUT
    uut: entity work.CPU
        port map(
            clk     => clk,
            rst     => rst,
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
        for i in 1 to 3 loop
            -- Aktivuj enable
            Buttons <= "00000001";
            wait for 500 ns;

            -- Deaktivuj enable
            Buttons <= "00000000";
            wait for 500 ns;
        end loop;

        -- Konec simulace
        wait;
    end process;

end behavior;
