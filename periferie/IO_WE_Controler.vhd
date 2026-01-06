library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IO_WE_controler is
    port(
        WE : in std_logic;
        IO_address : in std_logic_vector(31 downto 0);
        WE_GPIO : out std_logic
    );
end entity IO_WE_controler;

architecture RTL of IO_WE_controler is

begin
    IO_WE_controler : process (IO_address, WE) is
    begin
    WE_GPIO <= '0';
    if WE = '1' then
        if (unsigned(IO_address) >= x"80000004" and unsigned(IO_address) <= x"80000010") then
            WE_GPIO <= '1';
        end if;
    end if;
    
end process IO_WE_controler;
end architecture RTL;
