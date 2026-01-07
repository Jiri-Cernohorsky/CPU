library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        Shadow : in std_logic;
        Int_bra_tar : in std_logic_vector(10 downto 0);
        PC_i : in std_logic_vector(10 downto 0);
        PC_o : out std_logic_vector(10 downto 0)

    );
end entity PC;

architecture RTL of PC is
    signal PC_reg : std_logic_vector(10 downto 0);
    signal Last_shadow : std_logic;
    
begin

    PC : process (clk) is -- @suppress "Incomplete sensitivity list. Missing signals: Shadow"
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PC_reg <= (others => '0');
                PC_o <= (others => '0');
            else
                if Shadow = '0' then
                    if Last_shadow = Shadow then
                        PC_reg <= PC_i;
                        PC_o <= PC_i;
                    else
                        PC_o <= PC_reg;
                    end if;
                else
                    if Last_shadow = Shadow then
                        PC_o <= PC_i;
                    else
                        PC_o <= Int_bra_tar;
                    end if;
                end if;
            end if;
            Last_shadow <= Shadow;
        end if;
    end process PC;
end architecture RTL;
