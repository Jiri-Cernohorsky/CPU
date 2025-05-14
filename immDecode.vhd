library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity immDecode is
    port(
        inst : in std_logic_vector(31 downto 0);
        immControl : in std_logic_vector(2 downto 0);
        imm : out std_logic_vector(31 downto 0)
    );
end entity immDecode;

architecture Behavioral of immDecode is
    
begin
    immDecode: process (inst, immControl)
    begin
    case immControl is
        when "110" => imm(31 downto 11) <= (others => inst(31)); --I
                      imm(10 downto 0) <= inst(30 downto 20);
        when "101" => imm(31 downto 11) <= (others => inst(31)); --S
                      imm(10 downto 5) <= inst(30 downto 25);
                      imm(4 downto 0) <= inst(11 downto 7);
        when "100" => imm(31 downto 12) <= (others => inst(31)); --B
                      imm(11) <= inst(7);
                      imm(10 downto 5) <= inst(30 downto 25); 
                      imm(4 downto 1) <= inst(11 downto 8);
                      imm(0) <= '0';
        when "011" => imm(31 downto 12) <= inst(31 downto 12); --U
                      imm(11 downto 0) <= (others => '0');
        when "010" => imm(31 downto 20) <= (others => inst(31)); --J
                      imm(19 downto 12) <= inst(19 downto 12);
                      imm(11) <= inst(20);
                      imm(10 downto 1) <= inst(30 downto 21);
                      imm(0) <= '0';
        when others => imm <= (others => 'X');   --R and others
    end case;

    end process immDecode;
end architecture Behavioral;
 