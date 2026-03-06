library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
    port(
        clk         : in  std_logic;
        rst         : in  std_logic;
        ISR         : in  std_logic;
        Int_bra_tar : in  std_logic_vector(13 downto 0);
        PC_i        : in  std_logic_vector(13 downto 0);
        PC_o        : out std_logic_vector(13 downto 0);
        write_en    : in  std_logic
    );
end entity PC;

architecture RTL of PC is
    signal PC_reg      : std_logic_vector(13 downto 0);
    signal PC_next     : std_logic_vector(13 downto 0);
    signal mepc        : std_logic_vector(13 downto 0);
    signal Int_running : std_logic;
begin
    PC_next <= Int_bra_tar when (ISR = '1' and Int_running = '0') else
               mepc         when (ISR = '0' and Int_running = '1') else
               PC_i;

    PC_proc : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                PC_reg      <= "00000110010000";
                mepc        <= (others => '0');
                Int_running <= '0';
            else
                if ISR = '1' and Int_running = '0' then
                    mepc        <= PC_reg;       
                    PC_reg      <= PC_next;      
                    Int_running <= '1';
                elsif ISR = '0' and Int_running = '1' then
                    PC_reg      <= mepc;         
                    Int_running <= '0';
                elsif write_en = '1' then
                    PC_reg <= PC_next;           -- normální zápis PC
                end if;
            end if;
        end if;
    end process PC_proc;

    PC_o <= PC_reg;
end architecture RTL;
