library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity GPIO is
    port(
        clk : in std_logic;
        rst : in std_logic;
        GPIO_pins_io : inout std_logic_vector(7 downto 0);

        WE_GPIO : in std_logic;
        Address : in std_logic_vector(31 downto 0);
        Bus_data_i : in std_logic_vector(7 downto 0);
        Bus_data_o : out std_logic_vector(7 downto 0);
        
        Irq : out std_logic
    );
end entity GPIO;

architecture RTL of GPIO is
    signal Data_reg_TX : std_logic_vector(7 downto 0);
    signal Data_reg_RX : std_logic_vector(7 downto 0);
    signal Prev_data_reg_i : std_logic_vector(7 downto 0);
    signal Dir_reg : std_logic_vector(7 downto 0);
    signal Int_En_reg : std_logic_vector(7 downto 0);
    signal Int_State_reg : std_logic_vector(7 downto 0);
    signal Edge_detected : std_logic_vector(7 downto 0);
    

    component Synchronizer
    	generic(g_DATA_WIDTH : integer);
    	port(
    		clk     : in  std_logic;
    		rst     : in  std_logic;
    		Async_i : in  std_logic_vector(g_DATA_WIDTH - 1 downto 0);
    		Sync_o  : out std_logic_vector(g_DATA_WIDTH - 1 downto 0)
    	);
    end component Synchronizer;
    
begin
    synchronizer_inst : component Synchronizer
        generic map(
            g_DATA_WIDTH => 8
        )
        port map(
            clk         => clk,
            rst         => rst,
            Async_i => GPIO_pins_io,
            Sync_o  => Data_reg_RX
        );
    
    --nastavení směru pinů
    tristate_gen: for i in 7 downto 0 generate
        GPIO_pins_io(i) <= Data_reg_TX(i) when Dir_reg(i) = '1' else 'Z';
    end generate;


    GPIO : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                Data_reg_TX <= (others => '0');
                Dir_reg <= (others => '0');
                Int_En_reg <= (others => '0');
                Int_State_reg <= (others => '0');
            else

                --zápis dat
                if WE_GPIO = '1' then
                    case Address is
                        when x"80000004"=> Data_reg_TX <= Bus_data_i;
                        when x"80000008"=> Dir_reg <= Bus_data_i;
                        when x"8000000C"=> Int_En_reg <= Bus_data_i;
                        -- napíšeš 1 pro smazání prej W1C princip říkali internety
                        when x"80000010"=> Int_State_reg <= Int_State_reg and not Bus_data_i;
                        when others => null;
                    end case;  
                end if;

                --detekce hrany
                for i in 7 downto 0 loop
                    if Edge_detected(i) = '1' and Int_En_reg(i) = '1' then
                        Int_State_reg(i) <= '1';
                    end if;
                end loop;
            end if;
            --uložení předešlé hodnoty
            Prev_data_reg_i <= Data_reg_RX;
        end if;
    end process GPIO;

    --čtení
    process(Address, Data_reg_TX, Dir_reg, Int_En_reg, Int_State_reg)
    begin
        case Address is
            when x"80000004" => Bus_data_o <= Data_reg_TX;
            when x"80000008" => Bus_data_o <= Dir_reg;
            when x"8000000C" => Bus_data_o <= Int_En_reg;
            when x"80000010" => Bus_data_o <= Int_State_reg;
            when others => Bus_data_o <= (others => '0');
        end case;
    end process;

    --řešení interraptu
    Edge_detected <= Data_reg_RX and (not Prev_data_reg_i);
    Irq <= '1' when (unsigned(Int_State_reg) /= 0) else '0';
end architecture RTL;
