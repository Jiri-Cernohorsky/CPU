library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Synchronizer is
    Generic (
        g_DATA_WIDTH : integer
    );
    port(
        clk : in std_logic;
        rst : in std_logic;
        Async_i : in std_logic_vector(g_DATA_WIDTH - 1 downto 0);
        Sync_o : out std_logic_vector(g_DATA_WIDTH - 1 downto 0)
    );
end entity Synchronizer;

architecture RTL of Synchronizer is
    signal Semi_sync_1 : std_logic_vector(g_DATA_WIDTH - 1 downto 0);
    signal Semi_sync_2 : std_logic_vector(g_DATA_WIDTH - 1 downto 0);
begin
    synchronize : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Semi_sync_1 <= (others => '0');
                Semi_sync_2 <= (others => '0');
            else
                Semi_sync_1 <= Async_i;
                Semi_sync_2 <= Semi_sync_1;
            end if;
        end if;
    end process synchronize;
    Sync_o <= Semi_sync_2;
end architecture RTL;
