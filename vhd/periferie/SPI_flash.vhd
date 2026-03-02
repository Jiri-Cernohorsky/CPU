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
        EN_comm : in std_logic;
        Ready_to_read : in std_logic := '1'; -- pokud  procesor zpracoval read = '1' 
        Ready_to_write : in std_logic  := '1'; -- pokud  procesor zpracoval write = '1' 
        
        Data_o : out std_logic_vector(31 downto 0) := (others => '0');
        Read_done : out std_logic;
        Write_start : out std_logic;
        CMD_done : out std_logic;

        SPI_sclk : out std_logic;  -- zpomalené hodiny
        SPI_mosi : out std_logic;  -- master out slave in
        SPI_miso : in std_logic;   -- mastr in slave out
        SPI_cs_n : out std_logic   -- chip select jeden chip takže jen jeden bit
    
    );
end entity SPI_flash;

architecture RTL of SPI_flash is
    type STATE_t is (IDLE, SEND_CMD, SEND_ADDR, READ_LOOP, WRITE_LOOP, WRITE_WAIT, READ_WAIT, CLEANUP);
    signal State : STATE_t := IDLE;

    signal Shift_reg : std_logic_vector(31 downto 0);
    signal Bit_cnt   : integer range 0 to 31 := 0; -- jedna instrukce
    
    
    signal clk_div_cnt : integer range 0 to 3 := 0; --dělič hodin
    signal spi_tick    : std_logic := '0';
    signal sclk_reg     : std_logic := '0';

    type COMMANDS_t is array (0 to 3) of std_logic_vector(7 downto 0) ;
    constant c_COMMANDS : COMMANDS_t := (x"06",  --write enable
                                         x"03",  --read
                                         x"02",  --write
                                         x"d8"); --erase sector

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
            if rst = '1' then
                State <= IDLE;
                SPI_cs_n <= '1';
                sclk_reg <= '0';
                Bit_cnt  <= 0;
                CMD_done <= '0';
                Data_o  <= x"00000000";
                Read_done <= '0';
                Write_start <= '0';
                Shift_reg <= x"00000000";
            elsif spi_tick = '1' then
                Read_done <= '0';
                Write_start <= '0';
                case State is
                    when IDLE =>
                        if EN_comm = '1' then
                            state <= SEND_CMD;
                            shift_reg <= c_COMMANDS(to_integer(unsigned(CMD_sel))) & (23 downto 0 => '0');
                            spi_cs_n <= '0';
                            sclk_reg <= '0';
                            Bit_cnt <= 7;  
                        end if;
                    when SEND_CMD => --  poslání vybraného příkazu pro flash
                        if sclk_reg = '0' then sclk_reg <= '1';  
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                if CMD_sel = "00" then -- write enable
                                    State  <= CLEANUP;
                                else
                                    State <= SEND_ADDR;
                                    shift_reg  <= Adress_i & (7 downto 0 => '0');
                                    bit_cnt <= 23;
                                end if;
                            else
                                shift_reg <= shift_reg(30 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when SEND_ADDR =>
                        if sclk_reg = '0' then sclk_reg <= '1';  
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                if CMD_sel = "01" then    --read
                                    State  <= READ_LOOP;
                                    bit_cnt <= 31;
                                elsif CMD_sel = "10" then --write
                                    State  <= WRITE_LOOP;
                                    Shift_reg  <= Data_i;
                                    bit_cnt <= 31;
                                else                      --erase sector
                                    State  <= CLEANUP;
                                end if;
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
                                State  <= READ_WAIT;
                            else
                                shift_reg <= shift_reg(30 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;  
                    when READ_WAIT  => 
                            if EN_comm = '1' then
                                if Ready_to_read = '1' then
                                    bit_cnt <= 31;
                                end if;
                            else
                                State <= CLEANUP;
                            end if;
                        when WRITE_LOOP =>
                        if sclk_reg = '0' then sclk_reg <= '1';  
                        else
                            sclk_reg <='0';
                            if Bit_cnt = 0 then
                                State  <= WRITE_WAIT;
                            else
                                shift_reg <= shift_reg(30 downto 0) & '0';
                                bit_cnt <= bit_cnt - 1;
                            end if;
                        end if;
                    when WRITE_WAIT =>
                        if EN_comm = '1' then
                            if Ready_to_write = '1' then
                                shift_reg  <= Data_i;
                                Write_start <= '1';
                                bit_cnt <= 31;
                                State  <= WRITE_LOOP;
                            end if;
                        else 
                            State <= CLEANUP;
                        end if; 
                    when CLEANUP =>
                        spi_cs_n <= '1';
                        CMD_done <= '1';
                        state <= IDLE;
                end case;
            end if;
        end if;
    end process SPI_state_machine;
    
    spi_sclk  <= sclk_reg;
    spi_mosi <= shift_reg(31);
    
end architecture RTL;
