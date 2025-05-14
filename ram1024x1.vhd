library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RAM1024x1 is
    port(
        A : in std_logic_vector(9 downto 0);
        WD1 : in std_logic_vector(7 downto 0);
        WD4 : in std_logic_vector(31 downto 0);
        WE1 : in std_logic;
        WE4 : in std_logic;
        clk : in std_logic;
        rst : in std_logic;
        RD1 : out std_logic_vector(7 downto 0);
        RD4 : out std_logic_vector(31 downto 0)
    );
end entity RAM1024x1;

architecture behavioral of RAM1024x1 is
    type RAM_ARRAY is array (1023 downto 0) of std_logic_vector (7 downto 0);
    signal RAM: RAM_ARRAY := (others => (others => '0'));
begin
    RAMProcess : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                RAM <= (others => (others => '0'));
            else
                if WE1 = '1' then 
                    RAM(to_integer(signed(A))) <= WD1;
                end if;
                if WE4 = '1' and unsigned(A) mod 4 = 0 then 
                    RAM(to_integer(unsigned(A))) <= WD4(31 downto 24);
                    RAM(to_integer(unsigned(A))+1) <= WD4(23 downto 16);
                    RAM(to_integer(unsigned(A))+2) <= WD4(15 downto 8);
                    RAM(to_integer(unsigned(A))+3) <= WD4(7 downto 0);
                end if;
            end if;
            RD1 <= RAM(to_integer(unsigned(A)));
            if  unsigned(A) mod 4 = 0 then
                RD4 <= RAM(to_integer(unsigned(A))) & RAM(to_integer(unsigned(A))+1) & RAM(to_integer(unsigned(A))+2) & RAM(to_integer(unsigned(A))+3);
            end if;
        end if;
    end process RAMProcess;

end architecture behavioral;
