library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity registr32x4 is -- 32x4 byty
    port(
        clk : in std_logic;
        rst : in std_logic;
        A1 : in std_logic_vector(4 downto 0);
        A2 : in std_logic_vector(4 downto 0);
        A3 : in std_logic_vector(4 downto 0);
        WD3 : in std_logic_vector(31 downto 0);
        WE3 : in std_logic;
        RD1 : out std_logic_vector(31 downto 0);
        RD2 : out std_logic_vector(31 downto 0)
    );
end entity registr32x4;

architecture RTL of registr32x4 is
    type Reg_array_t is array (31 downto 0) of std_logic_vector (31 downto 0);
    signal Reg: Reg_array_t := (others => (others => '0'));
begin
    Reg_process : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Reg <= (others => (others => '0'));
            else
                if WE3 = '1' and A3 /= "00000" then 
                    Reg(to_integer(unsigned(A3))) <= WD3;
                end if;
            end if;
        end if;
    end process Reg_process;
    RD1 <= Reg(to_integer(unsigned(A1)));
	 RD2 <= Reg(to_integer(unsigned(A2)));
    
end architecture RTL;
