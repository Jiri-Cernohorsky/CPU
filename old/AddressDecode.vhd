library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity AddressDecode is
    port(
        WE : in std_logic;
        A : in std_logic_vector(10 downto 0);
        WELed : out std_logic;
        WERAM : out std_logic;
        Sel : out std_logic
    );
end entity AddressDecode;

architecture behavioral of AddressDecode is
    
begin
    WELed <= '1' when A = "00000000000" and WE = '1' else '0';
    WERAM <= '1' when A > "00000000100" and WE = '1' else '0';

    Sel <= '1' when A = "00000000100" else '0'; -- 0 = data, 1 = button

end architecture behavioral;
