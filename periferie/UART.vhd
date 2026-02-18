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
    constant c_BIT_PERIOD : integer := 50000000/c_BAUD_RATE; -- dělička je drahá takže tohle je jako konstanta možnost zlepšit na upravitelný baud rate

    --synchronizační signáli
    signal RX_semisync_1 : std_logic;
    signal RX_semisync_2 : std_logic;
    signal RX_synced   : std_logic;

    type STATE_t is (IDLE, START, DATA, STOP);
    signal TX_state : STATE_t := IDLE; -- stav odeslání
    signal RX_state : STATE_t := IDLE; -- stav příjmání
    
    --TX signály
    signal TX_start : std_logic; -- start nastavený uživatelem
    signal TX_reg : std_logic_vector(7 downto 0); -- data od uživatele nastavitelné
    signal TX_cnt : integer range 0 to c_BIT_PERIOD; -- počítadlo rychosti 
    signal TX_bit_idx : integer range 0 to 7; -- počítadlo bitu
    
    --RX signály
    signal RX_reg : std_logic_vector(7 downto 0);
    signal RX_cnt : integer range 0 to c_BIT_PERIOD; -- počítadlo rychosti 
    signal RX_bit_idx : integer range 0 to 7; -- počítadlo bitu
    
    --interrupt
    signal Int_En_reg : std_logic_vector(1 downto 0);
    signal Irq_reg : std_logic_vector(1 downto 0); -- 01 = TX interrupt 10 = RX interupt 00 = žádný interrupt 
    
begin

    --synchronizace asinchroního Vstupu RX
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

    -- přístu procesoru k datům
    Read_Write_to_reg : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                TX_reg <= x"00";
                TX_start <= '0';
                Irq_reg <= "00";
                Bus_data_o <= x"00";
            else
                --zápis dat
                if WE_UART = '1' then
                    case Address is
                        when x"80000104"=> TX_reg <= Bus_data_i;
                        when x"80000108"=> TX_start <= Bus_data_i(0);
                        when x"8000010C"=> Int_En_reg <= Bus_data_i(1 downto 0);
                        -- napíšeš 1 pro smazání prej W1C princip říkali internety
                        when x"80000110"=> Irq_reg <= Irq_reg and not Bus_data_i(1 downto 0);
                        when others => null;
                    end case;  
                end if;
                case Address is
                    when x"80000104" => Bus_data_o <= RX_reg;
                    when others => Bus_data_o <= (others => '0');
                end case;
            end if;
        end if;
    end process Read_Write_to_reg;
    
    --interrupt
    Irq <= '1' when (unsigned(Irq_reg and Int_En_reg) /= 0) else '0'; -- pokud se bit 1 obou rovná 1 nebo bit 0 obou se rovná 1

    --samotný UART
    TX_process : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                TX_state <= IDLE;
                TX <= '1';
                TX_bit_idx <= 0;
                TX_cnt <= 0;
                Irq_reg <= "00";
                TX_start <= '0';
            else
                case TX_state is
                    when IDLE =>
                        TX <= '1'; -- klidový stav UART
                        if TX_start = '1' then --čekání na signal start
                            TX_state <= START;
                            TX_cnt <= 0;
                            TX_start <= '0';
                        end if;

                    when START =>
                        TX <= '0'; -- start bit
                        if TX_cnt < c_BIT_PERIOD - 1 then -- počítadlo periody
                            TX_cnt <= TX_cnt + 1;
                        else
                            TX_cnt <= 0;
                            TX_state <= DATA;
                            TX_bit_idx <= 0;
                        end if;

                    when DATA =>
                        TX <= TX_reg(TX_bit_idx); -- posílání dat UARTu
                        if TX_cnt < c_BIT_PERIOD - 1 then -- počítadlo periody
                            TX_cnt <= TX_cnt + 1;
                        else
                            TX_cnt <= 0;
                            if TX_bit_idx /= 8 then -- počítadlo bitu zprávy
                                TX_bit_idx <= TX_bit_idx + 1;
                            else
                                TX_state <= STOP;
                            end if;
                        end if;

                    when STOP =>
                        TX <= '1'; --stop bit
                        if TX_cnt < c_BIT_PERIOD - 1 then -- počítadlo periody
                            TX_cnt <= TX_cnt + 1;
                        else
                            tx_state <= IDLE;
                            Irq_reg <= Irq_reg(1) & '1'; -- vyvolání přerušení
                        end if;

                end case;
            end if;
        end if;
    end process TX_process;

    RX_process : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Irq_reg <= "00";
                RX_bit_idx <= 0;
                RX_cnt <= 0;
                RX_reg <= x"00";
                RX_state <= IDLE;
            else
                case RX_state is
                    when IDLE =>
                        if RX_synced = '0' then --detekce start bitu
                            RX_state <= START;
                            RX_cnt <= 0;
                        end if;

                    when START =>
                        if RX_cnt < c_BIT_PERIOD/2 - 1 then -- čekání do poloviny bitu 
                            RX_cnt <= RX_cnt + 1;
                        else
                            if  RX_synced = '0' then -- kontrola start bitu
                                RX_cnt <= 0;
                                RX_state <= DATA;
                                RX_bit_idx <= 0;
                            else
                                RX_state <= IDLE;
                            end if;
                        end if;

                    when DATA =>
                        if RX_cnt < c_BIT_PERIOD - 1 then -- počítadlo periody
                            RX_cnt <= RX_cnt + 1;
                        else
                            RX_cnt <= 0;
                            RX_reg(RX_bit_idx) <= RX_synced;
                            if RX_bit_idx /= 8 then -- počítadlo bitu zprávy
                                RX_bit_idx <= RX_bit_idx + 1;
                            else
                                RX_state <= STOP;
                            end if;
                        end if;

                    when STOP =>
                        if RX_cnt < c_BIT_PERIOD - 1 then -- počítadlo periody
                            RX_cnt <= RX_cnt + 1;
                        else
                            RX_state <= IDLE;
                            Irq_reg <= Irq_reg(0) & '1'; -- vyvolání přerušení
                        end if;
                end case;
            end if;
        end if;
    end process RX_process;
end architecture RTL;
