library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk : in std_logic;
        rst : in std_logic;
        ISR : in std_logic;
        Int_bra_tar : in std_logic_vector(10 downto 0);
        PC_i : in std_logic_vector(10 downto 0);
        PC_o : out std_logic_vector(10 downto 0);
        stall: in std_logic

    );
end entity PC;

architecture RTL of PC is
    signal PC_reg : std_logic_vector(10 downto 0);
    
    signal mepc : std_logic_vector(10 downto 0);
    signal Int_runnig : std_logic;
    
begin

    PC : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                mepc <= (others => '0');
                PC_reg <= (others => '0');
                Int_runnig <= '0';
            else
                if ISR = '1' and Int_runnig = '0' then
                    mepc <= PC_i;
                    PC_reg <= Int_bra_tar;
                    Int_runnig <= '1';
                elsif ISR = '0' and INT_runnig = '1'then
                    PC_reg <= mepc;
                    Int_runnig <= '0';
                else 
                    if stall = '1' then
                        PC_reg <= PC_reg;
                    else
                        PC_reg <= PC_i;
                    end if;
                end if;
            end if;
        end if;
    end process PC;
    PC_o <= PC_reg;
end architecture RTL;
