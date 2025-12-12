library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity synchronizer is
    Generic (
        GDataWidth : integer
    );
    port(
        clk : in std_logic;
        rst : in std_logic;
        unsyncInput : in std_logic_vector(GDataWidth - 1 downto 0);
        syncOutput : out std_logic_vector(GDataWidth - 1 downto 0)
    );
end entity synchronizer;

architecture behavioral of synchronizer is
    signal semiSync1 : std_logic_vector(GDataWidth - 1 downto 0);
    signal semiSync2 : std_logic_vector(GDataWidth - 1 downto 0);
begin
    synchronize : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                semiSync1 <= (others => '0');
                semiSync2 <= (others => '0');
            else
                semiSync1 <= unsyncInput;
                semiSync2 <= semiSync1;
            end if;
        end if;
    end process synchronize;
    syncOutput <= semiSync2;
end architecture behavioral;
