library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IOControler is
    port(
        clk : in std_logic;
        rst : in std_logic;
        WE : in std_logic;
        IOAddress : in std_logic_vector(30 downto 0);
        WEGPIO : out std_logic
    );
end entity IOControler;

architecture behavioral of IOControler is
<<<<<<< Updated upstream
    
=======

>>>>>>> Stashed changes
begin
    IOcontrol : process (IOAddress, WE) is
    begin
        WEGPIO <= '0';
        if WE = '1' then
            case IOAddress is
                when ADDRESSDoplnit => WEGPIO <= '1';
                when others => null;
            end case;
        end if;
        
    end process IOcontrol;
    

end architecture behavioral;
