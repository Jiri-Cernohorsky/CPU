library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity UART is
    port(
        clk : in std_logic;
        rst : in std_logic;
        RX : in std_logic;
        TX : out std_logic;

        -- Bus info
        WE_UART : in std_logic;
        Address : in std_logic_vector(31 downto 0);
        Bus_data_i : in std_logic_vector(7 downto 0);
        Bus_data_o : out std_logic_vector(7 downto 0);
        Irq : out std_logic
    );
end entity UART;

architecture RTL of UART is
    constant c_BAUD_RATE : integer := 9600;
    constant c_BIT_PERIOD : integer := 50000000/c_BAUD_RATE; 

    -- synchronizační signály
    signal RX_semisync_1 : std_logic;
    signal RX_semisync_2 : std_logic;
    signal RX_synced   : std_logic;

    type STATE_t is (IDLE, START, DATA, STOP);
    signal TX_state : STATE_t := IDLE; -- stav odesílání
    signal RX_state : STATE_t := IDLE; -- stav přijímání
    
    -- TX signály
    signal TX_start : std_logic; -- start nastavený uživatelem (1-cyklový pulz)
    signal TX_reg : std_logic_vector(7 downto 0); -- data od uživatele
    signal TX_cnt : integer range 0 to c_BIT_PERIOD; -- počítadlo rychlosti 
    signal TX_bit_idx : integer range 0 to 7; -- počítadlo bitu
    signal TX_done : std_logic; -- 1-cyklový pulz od TX procesu
    
    -- RX signály
    signal RX_reg : std_logic_vector(7 downto 0);
    signal RX_cnt : integer range 0 to c_BIT_PERIOD; -- počítadlo rychlosti 
    signal RX_bit_idx : integer range 0 to 7; -- počítadlo bitu
    signal RX_done : std_logic; -- 1-cyklový pulz od RX procesu
    
    -- interrupt register management
    signal Int_En_reg : std_logic_vector(1 downto 0);
    signal Irq_reg : std_logic_vector(1 downto 0); 
    
begin

    -- synchronizace asynchronního vstupu RX
    synchronize : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                RX_semisync_1 <= '0';
                RX_semisync_2 <= '0';
            else
                RX_semisync_1 <= RX;
                RX_semisync_2 <= RX_semisync_1;
            end if;
        end if;
    end process synchronize;
    RX_synced <= RX_semisync_2;

    -- přístup procesoru k datům (zde spravujeme všechny registry)
    Read_Write_to_reg : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Bus_data_o <= x"00";
                TX_start <= '0';
                TX_reg <= x"00";
                Int_En_reg <= "00";
                Irq_reg <= "00";
            else
                -- Defaultní hodnota pro TX_start - vytvoří jednorázový pulz
                TX_start <= '0';

                -- Zápis dat
                if WE_UART = '1' then
                    case Address is
                        when x"80000104"=> TX_reg <= Bus_data_i;
                        when x"8000010C"=> TX_start <= Bus_data_i(0);
                        when x"80000110"=> Int_En_reg <= Bus_data_i(1 downto 0);
                        -- W1C: zapíšeš 1 pro smazání příslušného bitu
                        when x"80000114"=> Irq_reg <= Irq_reg and not Bus_data_i(1 downto 0);
                        when others => null;
                    end case;  
                end if;
                if TX_done = '1' then
                    Irq_reg(0) <= '1';
                end if;
                if RX_done = '1' then
                    Irq_reg(1) <= '1';
                end if;

                -- Čtení dat
                case Address is
                    when x"80000108" => Bus_data_o <= RX_reg;
                    when x"80000110" => Bus_data_o <= "000000" & Int_En_reg;
                    when x"80000114" => Bus_data_o <= "000000" & Irq_reg;
                    when others => Bus_data_o <= (others => '0');
                end case;
            end if;
        end if;
    end process Read_Write_to_reg;
    
    -- interrupt výstup na základě masky)
    Irq <= '1' when (unsigned(Irq_reg and Int_En_reg) /= 0) else '0'; 

    -- samotný UART TX
    TX_process : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                TX_done <= '0';
                TX_state <= IDLE;
                TX <= '1';
                TX_bit_idx <= 0;
                TX_cnt <= 0;
            else
                case TX_state is
                    when IDLE =>
                        TX <= '1'; 
                        if TX_start = '1' then
                            TX_state <= START;
                            TX_cnt <= 0;
                            TX_start  <= '0';
                        end if;

                    when START =>
                        TX <= '0'; -- start bit
                        if TX_cnt < c_BIT_PERIOD - 1 then 
                            TX_cnt <= TX_cnt + 1;
                        else
                            TX_cnt <= 0;
                            TX_state <= DATA;
                            TX_bit_idx <= 0;
                        end if;

                    when DATA =>
                        TX <= TX_reg(TX_bit_idx);
                        if TX_cnt < c_BIT_PERIOD - 1 then 
                            TX_cnt <= TX_cnt + 1;
                        else
                            TX_cnt <= 0;
                            if TX_bit_idx < 7 then 
                                TX_bit_idx <= TX_bit_idx + 1;
                            else
                                TX_state <= STOP;
                            end if;
                        end if;

                    when STOP =>
                        TX <= '1'; -- stop bit
                        if TX_cnt < c_BIT_PERIOD - 1 then 
                            TX_cnt <= TX_cnt + 1;
                        else
                            TX_state <= IDLE;
                            TX_done <= '1'; -- vyvolání přerušení
                        end if;

                end case;
            end if;
        end if;
    end process TX_process;

    -- samotný UART RX
    RX_process : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                RX_done <= '0';
                RX_bit_idx <= 0;
                RX_cnt <= 0;
                RX_reg <= x"00";
                RX_state <= IDLE;
            else
                RX_done <= '0'; -- default pulz
                case RX_state is
                    when IDLE =>
                        if RX_synced = '0' then -- detekce start bitu
                            RX_state <= START;
                            RX_cnt <= 0;
                        end if;

                    when START =>
                        if RX_cnt < c_BIT_PERIOD/2 - 1 then 
                            RX_cnt <= RX_cnt + 1;
                        else
                            if RX_synced = '0' then 
                                RX_cnt <= 0;
                                RX_state <= DATA;
                                RX_bit_idx <= 0;
                            else
                                RX_state <= IDLE;
                            end if;
                        end if;

                    when DATA =>
                        if RX_cnt < c_BIT_PERIOD - 1 then 
                            RX_cnt <= RX_cnt + 1;
                        else
                            RX_cnt <= 0;
                            RX_reg(RX_bit_idx) <= RX_synced;
                            if RX_bit_idx < 7 then 
                                RX_bit_idx <= RX_bit_idx + 1;
                            else
                                RX_state <= STOP;
                            end if;
                        end if;

                    when STOP =>
                        if RX_cnt < c_BIT_PERIOD - 1 then 
                            RX_cnt <= RX_cnt + 1;
                        else
                            RX_state <= IDLE;
                            RX_done <= '1'; -- vyvolání přerušení
                        end if;
                end case;
            end if;
        end if;
    end process RX_process;
end architecture RTL;