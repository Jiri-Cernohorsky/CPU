library ieee;
use ieee.std_logic_1164.all;

entity controlUnit is
    Port ( inst : in std_logic_vector (31 downto 0);
           control_signal : out std_logic_vector (12 downto 0));
            --immControl(12:10) [R(111), I(110), S(101), B(100), U(011), J(010)],
            --ALUControl(9:7)  [+(111), -(110), &(101), |(100), <(011)],
            --ALUSrc(6), MemW(5), MemToReg(4), RegW(3), BraJalr(2), BraJal(1), RraBeq(0)

end controlUnit;

architecture Behavioral of controlUnit is
    signal opcode: std_logic_vector(6 downto 0);
    signal Funct3: std_logic_vector(2 downto 0);
    signal Funct7: std_logic_vector(6 downto 0);

begin
    opcode <= inst(6 downto 0);
    Funct3 <= inst(14 downto 12);
    Funct7 <= inst(31 downto 25);
    controlUnit: process (Opcode, Funct3, Funct7)
    begin
    case Opcode is
        when "0000011" => control_signal <= "1101111011000"; --lw
        when "0100011" => control_signal <= "10111111-0000"; --sw
        when "0010011" => control_signal <= "1101111001000"; --addi
        when "1100011" => control_signal <= "10011000-0001"; --beq
        when "1101111" => control_signal <= "010----001010"; --jal
        when "1100111" => control_signal <= "1101111001100"; --jalr
        when "0110011" => case Funct3 is
            when "010" => control_signal <= "1110110001000"; --slt
            when "110" => control_signal <= "1111000001000"; --or
            when "111" => control_signal <= "1111010001000"; --and
            when "000" => case Funct7 is
                when "0000000" => control_signal <= "1111110001000"; --add
                when "0100000" => control_signal <= "1111100001000"; --sub
                when others =>  control_signal <= (others => '-');
            end case;
            when others =>  control_signal <= (others => '-');
        end case;
        when others =>  control_signal <= (others => '-');
    end case;

    end process controlUnit;
                      
end Behavioral;

