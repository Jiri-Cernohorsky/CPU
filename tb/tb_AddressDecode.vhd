library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_AddressDecode is
end entity tb_AddressDecode;

architecture RTL of tb_AddressDecode is

    signal WE :  std_logic;
    signal A :  std_logic_vector(10 downto 0) := "00000000000";
    signal WELed :  std_logic;
    signal WERAM : std_logic;
    signal Sel : std_logic;

begin
    uut: entity work.AddressDecode
        port map(
            WE    => WE,
            A     => A,
            WELed => WELed,
            WERAM => WERAM,
            Sel   => Sel
        );
    
        process
        begin
            while true loop
                WE <= '0';
                A <= "00000100000";
                wait for 500 ns;
                A <= "00000000000";
                wait for 500 ns;
                A <= "00000000100";
                wait for 500 ns;
                WE <= '1';
                A <= "00000100000";
                wait for 500 ns;
                A <= "00000000000";
                wait for 500 ns;
                A <= "00000000100";
                wait for 500 ns;
            end loop;
        end process;

end architecture RTL;
