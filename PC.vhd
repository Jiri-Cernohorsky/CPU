library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        Shadow : in std_logic;
        PC_i : in std_logic_vector(10 downto 0);
        PC_o : out std_logic_vector(10 downto 0)

    );
end entity PC;

architecture RTL of PC is
    signal PC_reg : std_logic_vector(10 downto 0);
    signal Shadow_PC : std_logic_vector(10 downto 0);
    
begin

    PC : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PC_reg <= (others => '0');
                Shadow_PC <= (others => '0');
            else
                if Shadow = '0' then 
                    PC_reg <= PC_i;
                else
                    Shadow_PC <= PC_i;
                end if;
            end if;
        end if;
    end process PC;
    PC_o <= PC_reg when Shadow = '0' else Shadow_PC;
end architecture RTL;
