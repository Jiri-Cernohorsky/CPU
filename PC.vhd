library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        shadow : in std_logic;
        PCin : in std_logic_vector(10 downto 0);
        PCout : out std_logic_vector(10 downto 0)

    );
end entity PC;

architecture behavioral of PC is
    signal PCReg : std_logic_vector(10 downto 0);
    signal ShadowPC : std_logic_vector(10 downto 0);
    
begin

    PC : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PCReg <= (others => '0');
                ShadowPC <= (others => '0');
            else
                if shadow = '0' then 
                    PCReg <= PCin;
                else
                    ShadowPC <= PCin;
                end if;
            end if;
        end if;
    end process PC;
    PCout <= PCReg when shadow = '0' else ShadowPC;
end architecture behavioral;
