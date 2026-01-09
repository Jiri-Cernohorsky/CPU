library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity SPI_flash is
    port(
        clk : in std_logic;
        rst : in std_logic;
        Adress_i : in std_logic_vector(23 downto 0);
        Read_en : in std_logic;

        Data_o : out std_logic_vector(31 downto 0);
        Read_done : out std_logic;

        SPI_sclk : out std_logic;
        SPI_mosi : out std_logic;
        SPI_miso : in std_logic;
        SPI_cs_n : out std_logic
    
    );
end entity SPI_flash;

architecture RTL of SPI_flash is
    type STATE_t is (IDLE, SEND_CMD, SEND_ADDR_2, SEND_ADDR_1, SEND_ADDR_0, READ_LOOP, CLEANUP);
    signal State : STATE_t := IDLE;

    type Data_o_array_t is array(2 downto 0) of std_logic_vector(7 downto 0);
    signal Data_o_array : Data_o_array_t;

    signal Shift_reg : STD_LOGIC_VECTOR(7 downto 0);
    signal Bit_cnt   : integer range 0 to 7 := 0;
    signal Data_o_cnt : integer range 0 to 3 := 0;
    
    signal clk_div_cnt : integer range 0 to 3 := 0;
    signal spi_tick    : std_logic := '0';
    signal sclk_reg     : std_logic := '0';

    constant c_CMD_READ : std_logic_vector(7 downto 0) := x"03";
begin

    SPI_clk_gen : process (clk) is
    begin
        if rising_edge(clk) then
            if State = IDLE then
                clk_div_cnt <= 0;
                spi_tick <= '0';
            else
                if clk_div_cnt = 3 then
                    clk_div_cnt <= 0;
                    spi_tick <= '1';
                else
                    clk_div_cnt <= clk_div_cnt + 1;
                    spi_tick <= '0';
                end if;
            end if;
        end if;
    end process SPI_clk_gen;

    SPI_state_machine : process (clk) is
    begin
        if rising_edge(clk) then

            Read_done <= '0';

            if rst = '1' then
                State <= IDLE;
                SPI_cs_n <= '1';
                sclk_reg <= '0';
            elsif (State = IDLE and Read_en = '1') then
                state <= SEND_CMD;
                shift_reg <= c_CMD_READ;
                spi_cs_n <= '0';
                sclk_reg <= '0';
                Bit_cnt <= 7;
            elsif spi_tick = '1' then
                
                case State is
                    when SEND_CMD =>
                        if sclk_reg = '0' then sclk_reg <= '1';
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                state <= SEND_ADDR_2;
                                shift_reg <= Adress_i(23 downto 16);
                                bit_cnt <= 7;
                            else
                                shift_reg <= shift_reg(6 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when SEND_ADDR_2 =>
                        if sclk_reg = '0' then sclk_reg <= '1';
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                state <= SEND_ADDR_1;
                                shift_reg <= Adress_i(15 downto 8);
                                bit_cnt <= 7;
                            else
                                shift_reg <= shift_reg(6 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when SEND_ADDR_1 =>
                        if sclk_reg = '0' then sclk_reg <= '1';
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                state <= SEND_ADDR_0;
                                shift_reg <= Adress_i(7 downto 0);
                                bit_cnt <= 7;
                            else
                                shift_reg <= shift_reg(6 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when SEND_ADDR_0 =>
                        if sclk_reg = '0' then sclk_reg <= '1';
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                state <= READ_LOOP;
                                bit_cnt <= 7;
                            else
                                shift_reg <= shift_reg(6 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when READ_LOOP =>
                        if sclk_reg = '0' then
                            sclk_reg <= '1';
                            shift_reg(0) <= spi_miso;
                        else
                            sclk_reg <= '0';
                            if Bit_cnt = 0 then
                                --skladaní 8 bit za sebe na vyrvoření celé instrukce
                                if Data_o_cnt = 3 then
                                    Data_o <= shift_reg & Data_o_array(2) & Data_o_array(1) & Data_o_array(0);
                                    Read_done <= '1';

                                    if Read_en = '1' then
                                        bit_cnt <= 7;
                                    else
                                        State <= CLEANUP;
                                    end if;
                                else
                                    Data_o_array(Data_o_cnt) <= shift_reg;
                                    Data_o_cnt <= Data_o_cnt + 1;
                                    bit_cnt <= 7;
                                end if;
                            else
                                shift_reg <= shift_reg(6 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;  
                    when CLEANUP =>
                         spi_cs_n <= '1';
                        state <= IDLE;
                    when IDLE =>
                    	null;
                end case;
            end if;
        end if;
    end process SPI_state_machine;
    
    spi_sclk  <= sclk_reg;
    spi_mosi <= shift_reg(7);
    
end architecture RTL;
