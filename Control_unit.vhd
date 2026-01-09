library ieee;
use ieee.std_logic_1164.all;

entity Control_unit is
    Port ( 
        clk : in std_logic;
        rst : in std_logic;
        IRR : in std_logic_vector(7 downto 0);
        W_IMR : in std_logic_vector(7 downto 0);
        Int_bra_tar : out std_logic_vector(10 downto 0);
        ISR : out std_logic; 
        Inst : in std_logic_vector (31 downto 0);
        Control_signal : out std_logic_vector (12 downto 0)
        --immControl(12:10) [R(111), I(110), S(101), B(100), U(011), J(010)],
        --ALUControl(9:7)  [+(111), -(110), &(101), |(100), <(011)],
        --ALUSrc(6), MemW(5), MemToReg(4), RegW(3), BraJalr(2), BraJal(1), RraBeq(0)
        );

end Control_unit;

architecture RTL of Control_unit is
    signal Opcode: std_logic_vector(6 downto 0);
    signal Funct3: std_logic_vector(2 downto 0);
    signal Funct7: std_logic_vector(6 downto 0);
    signal IMR : std_logic_vector(7 downto 0);
    signal Internal_ISR : std_logic;
    
    --IMR(0) = GPIO 
    type Rtq_array_t is array (0 to 7) of std_logic_vector(10 downto 0);
    constant c_RTQ : Rtq_array_t := ("00001101100",
                                     "00000000000",
                                     "00000000000",
                                     "00000000000",
                                     "00000000000",
                                     "00000000000",
                                     "00000000000",
                                     "00000000000");
begin
    IMR <= W_IMR;
    Opcode <= Inst(6 downto 0);
    Funct3 <= Inst(14 downto 12);
    Funct7 <= Inst(31 downto 25);
    Istr_handler: process (Opcode, Funct3, Funct7)
    begin
    case Opcode is
        when "0000011" => Control_signal <= "1101111011000"; --lw
        when "0100011" => Control_signal <= "10111111-0000"; --sw
        when "0010011" => Control_signal <= "1101111001000"; --addi
        when "1100011" => Control_signal <= "10011000-0001"; --beq
        when "1101111" => Control_signal <= "010----001010"; --jal
        when "1100111" => Control_signal <= "1101111001100"; --jalr
        when "1110011" => Control_signal <= "0000000000000"; --mret
        when "0110011" => case Funct3 is
            when "010" => Control_signal <= "1110110001000"; --slt
            when "110" => Control_signal <= "1111000001000"; --or
            when "111" => Control_signal <= "1111010001000"; --and
            when "000" => case Funct7 is
                when "0000000" => Control_signal <= "1111110001000"; --add
                when "0100000" => Control_signal <= "1111100001000"; --sub
                when others =>  Control_signal <= (others => '-');
            end case;
            when others =>  Control_signal <= (others => '-');
        end case;
        when others =>  Control_signal <= (others => '-');
    end case;
    end process Istr_handler;
   
    Interrupt_handler : process (clk,Opcode) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Int_bra_tar <= (others => '0');
                Internal_ISR <= '0';
            else
                for i in 0 to 7 loop
                    if IRR(i) = '1' and IMR(i) = '1' and Internal_ISR = '0' then
                    Int_bra_tar <= c_RTQ(i);
                    Internal_ISR <= '1';
                end if;
                end loop;
            end if;
        end if;
        if Opcode = "1110011" then 
            Internal_ISR <= '0';
        end if;
    end process Interrupt_handler;
    ISR <= Internal_ISR;
end RTL;

