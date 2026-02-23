library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Imm_decode is
    port(
        Inst : in std_logic_vector(31 downto 0);
        Imm_control : in std_logic_vector(2 downto 0);
        Imm : out std_logic_vector(31 downto 0)
    );
end entity Imm_decode;

architecture RTL of Imm_decode is
    
begin
    Imm_decode: process (Inst, Imm_control)
    begin
    case Imm_control is
        when "110" => Imm(31 downto 11) <= (others => Inst(31)); --I
                      Imm(10 downto 0) <= Inst(30 downto 20);
        when "101" => Imm(31 downto 11) <= (others => Inst(31)); --S
                      Imm(10 downto 5) <= Inst(30 downto 25);
                      Imm(4 downto 0) <= Inst(11 downto 7);
        when "100" => Imm(31 downto 12) <= (others => Inst(31)); --B
                      Imm(11) <= Inst(7);
                      Imm(10 downto 5) <= Inst(30 downto 25); 
                      Imm(4 downto 1) <= Inst(11 downto 8);
                      Imm(0) <= '0';
        when "011" => Imm(31 downto 12) <= Inst(31 downto 12); --U
                      Imm(11 downto 0) <= (others => '0');
        when "010" => Imm(31 downto 20) <= (others => Inst(31)); --J
                      Imm(19 downto 12) <= Inst(19 downto 12);
                      Imm(11) <= Inst(20);
                      Imm(10 downto 1) <= Inst(30 downto 21);
                      Imm(0) <= '0';
        when others => Imm <= (others => 'X');   --R and others
    end case;
    end process Imm_decode;
end architecture RTL;
 