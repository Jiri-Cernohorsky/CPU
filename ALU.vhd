library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is
    port(
        ScrA, ScrB : in std_logic_vector(31 downto 0);
        ALUControl : in std_logic_vector(2 downto 0);
        Z_Flag : out std_logic;
        ALUout : out std_logic_vector(31 downto 0)
    );
end entity ALU;

architecture behavioral of ALU is
    signal ALU_Result : std_logic_vector(31 downto 0);
begin
    ALUProcess : process(ScrA, ScrB, ALUControl, ALU_Result) is
    begin
        case ALUControl is
            when "111" => ALU_Result <= std_logic_vector(signed(ScrA) + signed(ScrB));
            when "110" => ALU_Result <= std_logic_vector(signed(ScrA) - signed(ScrB));
            when "101" => ALU_Result <= ScrA and ScrB;
            when "100" => ALU_Result <= ScrA or ScrB;
            when "011" => if (signed(ScrA) < signed(ScrB)) then
                            ALU_Result <= (31 downto 1 => '0') & '1';
                          else
                            ALU_Result <= (others => '0');
                          end if;
           when others => null;
        end case;
		  if ALU_Result = (31 downto 0 => '0') then
				Z_Flag <= '1';
		  else
				Z_Flag <= '0';
		  end if;
    end process ALUProcess;
    ALUout <= ALU_Result;
end architecture behavioral;
