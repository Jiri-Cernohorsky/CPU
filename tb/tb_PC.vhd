library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_PC is
end entity tb_PC;

architecture RTL of tb_PC is
    signal clk : std_logic;
    signal rst : std_logic;
    signal PCin : std_logic_vector(10 downto 0) := (others => '0');
    signal PCout : std_logic_vector(10 downto 0);
    
    constant clk_period : time := 10 ns;
begin
    uut: entity work.PC
    port map(
        clk   => clk,
        rst   => rst,
        PC_i  => PCin,
        PC_o => PCout
    );
    clk_process : process
    begin
        while true loop
            clk <= '0';
            wait for clk_period / 2;
            clk <= '1';
            wait for clk_period / 2;
        end loop;
    end process;

    process
    begin
        while true loop
            PCin <= std_logic_vector(unsigned(PCin) + 4);
            wait for 100 ns;
        end loop;
    end process;
end architecture RTL;
