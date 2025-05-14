library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_controlUnit is
end entity tb_controlUnit;

architecture RTL of tb_controlUnit is
    signal inst : std_logic_vector (31 downto 0);
    signal control_signal : std_logic_vector (12 downto 0);
begin
    uut: entity work.controlUnit
        port map(
            inst           => inst,
            control_signal => control_signal
        );
    
        process
        begin
            while true loop
                inst <= "00000000000000000010000000000011";
                wait for 100 ns;
                inst <= "00000000000000000010000000100011";
                wait for 100 ns;
                inst <= "00000000000000000000000000110011";
                wait for 100 ns;
                inst <= "01000000000000000000000000110011";
                wait for 100 ns;
                inst <= "00000000000000000010000000110011";
                wait for 100 ns;
                inst <= "00000000000000000110000000110011";
                wait for 100 ns;
                inst <= "00000000000000000111000000110011";
                wait for 100 ns;
					 inst <= "00000000000000000000000000010011";
                wait for 100 ns;
                inst <= "00000000000000000000000001100011";
                wait for 100 ns;
                inst <= "00000000000000000000000001101111";
                wait for 100 ns;
                inst <= "00000000000000000000000001100111";
                wait for 100 ns;
            end loop;
        end process;
end architecture RTL;
