library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        state : in std_logic;
        PCin : in std_logic_vector(10 downto 0);
        PCout : out std_logic_vector(10 downto 0)

    );
end entity PC;

architecture behavioral of PC is
    signal PC : std_logic_vector(10 downto 0);
    signal ShadowPC : std_logic_vector(10 downto 0);
    
begin

    PC : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PC <= (others => '0');
                ShadowPC <= (others => '0');
            else
                if state = '0' then 
                    PC <= PCin;
                else
                    ShadowPC <= PCin;
                end if;
            end if;
        end if;
    end process PC;
    PCout <= PC when state = '0' else ShadowPC;
end architecture behavioral;
