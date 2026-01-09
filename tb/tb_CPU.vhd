library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_CPU is
end entity tb_CPU;

architecture behavior of tb_CPU is

    signal clk          : std_logic := '0';
    signal async_rst    : std_logic := '0';
    signal GPIO_pins_io : std_logic_vector(7 downto 0) := x"00";
    signal SPI_o        : std_logic_vector(2 downto 0);
    signal SPI_i        : std_logic;
    
    signal Bit_cnt      : integer range 0 to 7 := 7;

    signal command_cnt  : integer range 0 to 7 := 0; 
    signal loop_cnt  : integer range 0 to 31 := 0; 
    signal Shift_reg    : STD_LOGIC_VECTOR(7 downto 0);
    
    constant c_CLK_PERIOD : time := 20 ns;

    signal command : std_logic_vector(31 downto 0) := x"00508093";

begin


    CPU_inst : entity work.CPU
        port map(
            clk          => clk,
            async_rst    => async_rst,
            GPIO_pins_io => GPIO_pins_io,
            SPI_o        => SPI_o,
            SPI_i        => SPI_i
        );
    
    clk_process : process
    begin
        while true loop
            clk <= '0';
            wait for c_CLK_PERIOD / 2;
            clk <= '1';
            wait for c_CLK_PERIOD / 2;
        end loop;
    end process;

    stim_proc: process
    begin
        SPI_i <= '0';
        async_rst <= '1';
        wait for 500 ns;
        async_rst <= '0';
        Shift_reg <= command(7 downto 0);
        command_cnt <= 0;
        Bit_cnt <= 7;
        
        while true loop
            SPI_i <= Shift_reg(7);
            wait until rising_edge(SPI_o(0));
            if SPI_o(2) = '0' then
                if loop_cnt = 31 then
                    if Bit_cnt = 0 then
                    bit_cnt <= 7;

                    if command_cnt = 0 then
                        Shift_reg <= command(15 downto 8);
                        command_cnt <= 1;
                    elsif command_cnt = 1 then
                        Shift_reg <= command(23 downto 16);
                        command_cnt <= 2;
                    elsif command_cnt = 2 then
                        Shift_reg <= command(31 downto 24);
                        command_cnt <= 3;
                    elsif command_cnt >= 3 and command_cnt < 7 then
                        Shift_reg <= x"FF";
                        command_cnt <= command_cnt + 1;
                    else
                        exit; 
                    end if;
                    else
                        shift_reg <= shift_reg(6 downto 0) & '0';
                        bit_cnt <= bit_cnt - 1;
                    end if;
                else
                    loop_cnt <= loop_cnt + 1;
                end if;
                
                
                
            end if;
        end loop;
        wait;
    end process;

end behavior;