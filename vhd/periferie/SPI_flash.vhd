library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity SPI_flash is
    port(
        clk : in std_logic;
        rst : in std_logic;
        Adress_i : in std_logic_vector(23 downto 0);
        Data_i : in std_logic_vector(31 downto 0);
        CMD_sel : in std_logic_vector(1 downto 0);

        Data_o : out std_logic_vector(31 downto 0) := (others => '0');
        Read_done : out std_logic;

        SPI_sclk : out std_logic;  -- zpomalené hodiny
        SPI_mosi : out std_logic;  -- master out slave in
        SPI_miso : in std_logic;   -- mastr in slave out
        SPI_cs_n : out std_logic   -- chip select jeden chip takže jen jeden bit
    
    );
end entity SPI_flash;

architecture RTL of SPI_flash is
    type STATE_t is (IDLE, SEND_CMD, SEND_ADDR, DATA_LOOP, CLEANUP);
    signal State : STATE_t := IDLE;

    signal Shift_reg : std_logic_vector(31 downto 0);
    signal Bit_cnt   : integer range 0 to 31 := 0;
    
    signal clk_div_cnt : integer range 0 to 3 := 0; --dělič hodin
    signal spi_tick    : std_logic := '0';
    signal sclk_reg     : std_logic := '0';

    constant c_CMD_READ : std_logic_vector(7 downto 0)     := x"03";
    constant c_CMD_WRITE_EN : std_logic_vector(7 downto 0) := x"06";
    constant c_CMD_WRITE : std_logic_vector(7 downto 0)    := x"02";
    constant c_CMD_ERASE : std_logic_vector(7 downto 0)    := x"C7";

begin
    -- zpomalení hodin na čtvrtinu rychleji číst nejde 20 MHz max takže by jsme měli stíhat
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
                -- vystrčen ven z casu State aby měl okamžitou reakci na Read_en
            elsif (State = IDLE and Read_en = '1') then
                state <= SEND_CMD;
                shift_reg <= c_CMD_READ & Adress_i;
                spi_cs_n <= '0';
                sclk_reg <= '0';
                Bit_cnt <= 31;
            elsif spi_tick = '1' then
                
                case State is
                    when IDLE =>
                        if Read_en = '1' then
                            state <= SEND_CMD;
                        shift_reg <= c_CMD_READ & Adress_i;
                        spi_cs_n <= '0';
                        sclk_reg <= '0';
                        Bit_cnt <= 31;
                        end if;
                    when SEND_CMD => -- zápis příkazu pro flash
                        if sclk_reg = '0' then sclk_reg <= '1';  
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                state <= READ_LOOP;
                                bit_cnt <= 31;
                            else
                                shift_reg <= shift_reg(30 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when READ_LOOP => -- čtení z flash
                        if sclk_reg = '0' then
                            sclk_reg <= '1';
                            shift_reg(0) <= spi_miso;
                        else
                            sclk_reg <= '0';
                            if Bit_cnt = 0 then
                                Data_o <= shift_reg;
                                Read_done <= '1';
                                if Read_en = '1' then
                                    bit_cnt <= 31;
                                else
                                    State <= CLEANUP;
                                end if;
                            else
                                shift_reg <= shift_reg(30 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;  
                    when CLEANUP =>
                         spi_cs_n <= '1';
                        state <= IDLE;
                end case;
            end if;
        end if;
    end process SPI_state_machine;
    
    spi_sclk  <= sclk_reg;
    spi_mosi <= shift_reg(31);
    
end architecture RTL;
