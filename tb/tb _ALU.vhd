library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_ALU is
end entity tb_ALU;

architecture RTL of tb_ALU is

    signal ScrA, ScrB :  std_logic_vector(31 downto 0) := "00000000000000000000000000000100";
    signal ALUControl :  std_logic_vector(2 downto 0);
    signal Z_Flag :  std_logic;
    signal ALUout :  std_logic_vector(31 downto 0);

begin
    uut: entity work.ALU
        port map(
            ScrA       => ScrA,
            ScrB       => ScrB,
            ALUControl => ALUControl,
            Z_Flag     => Z_Flag,
            ALUout     => ALUout
        );
    
        process
        begin
            while true loop
                ALUControl <= "110";
                ScrA <= "0000000000000000000000000000001";
                ScrB <= "00000000000000000000000000000100";
                
            end loop;
        end process;

end architecture RTL;