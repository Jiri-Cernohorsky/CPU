library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IO_WE_Controler is
    port(
        clk : in std_logic;
        rst : in std_logic;
        WE : in std_logic;
        IOAddress : in std_logic_vector(31 downto 0);
        WEGPIO : out std_logic
    );
end entity IO_WE_Controler;

architecture behavioral of IO_WE_Controler is

begin
    IO_WE_Controler : process (IOAddress, WE) is
    begin
        WEGPIO <= '0';
        if WE = '1' then
            case IOAddress is
                when  x"80000010" downto x"80000004"=> WEGPIO <= '1';
                when others => null;
            end case;
        end if;
        
    end process IO_WE_Controler;
end architecture behavioral;
