library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        PCin : in std_logic_vector(10 downto 0);
        PCout : out std_logic_vector(10 downto 0)

    );
end entity PC;

architecture behavioral of PC is
    
begin  
    PC : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PCout <= (others => '0');
            else
                PCout <= PCin;
            end if;
        end if;
    end process PC;
    
end architecture behavioral;
