library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is
    port(
        Scr_A, Scr_B : in std_logic_vector(31 downto 0);
        ALU_control : in std_logic_vector(2 downto 0);
        Flag_z : out std_logic;
        ALU_o : out std_logic_vector(31 downto 0)
    );
end entity ALU;

architecture RTL of ALU is
    signal ALU_result : std_logic_vector(31 downto 0);
begin
    ALU_process : process(Scr_A, Scr_B, ALU_control) is
    begin
        case ALU_control is
            when "111" => ALU_result <= std_logic_vector(signed(Scr_A) + signed(Scr_B));
            when "110" => ALU_result <= std_logic_vector(signed(Scr_A) - signed(Scr_B));
            when "101" => ALU_result <= Scr_A and Scr_B;
            when "100" => ALU_result <= Scr_A or Scr_B;
            --!!
            when "011" => if (signed(Scr_A) < signed(Scr_B)) then
                            ALU_result <= (31 downto 1 => '0') & '1';
                          else
                            ALU_result <= (others => '0');
                          end if;
            when "001" => ALU_result <= std_logic_vector(shift_left(unsigned(Scr_A), to_integer(unsigned(Scr_B(4 downto 0)))));
            when "000" => ALU_result <= std_logic_vector(shift_right(unsigned(Scr_A), to_integer(unsigned(Scr_B(4 downto 0)))));
           when others => null;
        end case;
    end process ALU_process;
    Flag_z  <= '1' when ALU_result = (31 downto 0 => '0') else '0';
    ALU_o <= ALU_result;
end architecture RTL;
