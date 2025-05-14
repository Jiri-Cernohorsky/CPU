library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_InstMem is
end entity tb_InstMem;

architecture RTL of tb_InstMem is
    signal A : std_logic_vector(10 downto 0) := (others => '0');
    signal RD : std_logic_vector(31 downto 0);
begin
    uut: entity work.InstrMem
        port map(
            A  => A,
            RD => RD
        );
    
    process
    begin
        while true loop
            A <= std_logic_vector(unsigned(A) + 4);
            wait for 100 ns;
        end loop;
    end process;
end architecture RTL;
