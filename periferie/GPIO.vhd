library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity GPIO is
    port(
        clk : in std_logic;
        rst : in std_logic;
        GPIOPins : inout std_logic_vector(7 downto 0);

        WEGPIO : in std_logic;
        Address : in std_logic_vector(31 downto 0);
        Write_Data : in std_logic_vector(7 downto 0);
        Read_Data : out std_logic_vector(7 downto 0);
        
        Irq : out std_logic
    );
end entity GPIO;

architecture behavioral of GPIO is
    signal RegDataOut : std_logic_vector(7 downto 0);
    signal RegDataIn : std_logic_vector(7 downto 0);
    signal RegDataInPrev : std_logic_vector(7 downto 0);
    signal RegDir : std_logic_vector(7 downto 0);
    signal RegIntEnable : std_logic_vector(7 downto 0);
    signal RegIntState : std_logic_vector(7 downto 0);
    signal EdgeDetected : std_logic_vector(7 downto 0);
    

    component synchronizer
        generic(GDataWidth : integer);
        port(
            clk         : in  std_logic;
            rst         : in  std_logic;
            unsyncInput : in  std_logic_vector(GDataWidth - 1 downto 0);
            syncOutput  : out std_logic_vector(GDataWidth - 1 downto 0)
        );
    end component synchronizer;
begin
    synchronizer_inst : component synchronizer
        generic map(
            GDataWidth => 8
        )
        port map(
            clk         => clk,
            rst         => rst,
            unsyncInput => GPIOPins,
            syncOutput  => RegDataIn
        );
    
    --nastavení směru pinů
    tristate_gen: for i in 7 downto 0 generate
        GPIOPins(i) <= RegDataOut(i) when RegDir(i) = '1' else 'Z';
    end generate;


    GPIO : process (clk) is
    begin
        if rising_edge(clk) then
            if rst = '1' then
                RegDataOut <= (others => '0');
                RegDir <= (others => '0');
                RegIntEnable <= (others => '0');
                RegIntState <= (others => '0');
            else

                --zápis dat
                if WEGPIO = '1' then
                    case Address is
                        when x"80000000"=> RegDataOut <= Write_Data;
                        when x"80000004"=> RegDir <= Write_Data;
                        when x"80000008"=> RegIntEnable <= Write_Data;
                        -- napíšeš 1 pro smazání prej W1C princip říkali internety
                        when x"8000000C"=> RegIntState <= RegIntState and not Write_Data;
                        when others => null;
                    end case;  
                end if;

                --detekce hrany
                for i in 7 downto 0 loop
                    if EdgeDetected(i) = '1' and RegIntEnable(i) = '1' then
                        RegIntState(i) <= '1';
                    end if;
                end loop;
            end if;
            --uložení předešlé hodnoty
            RegDataInPrev <= RegDataIn;
        end if;
    end process GPIO;

    --čtení
    process(Address, RegDataOut, RegDir, RegIntEnable, RegIntState)
    begin
        case Address is
            when x"80000000" => Read_Data <= RegDataOut;
            when x"80000004" => Read_Data <= RegDir;
            when x"80000008" => Read_Data <= RegIntEnable;
            when x"8000000C" => Read_Data <= RegIntState;
            when others => Read_Data <= (others => '0');
        end case;
    end process;

    --řešení interraptu
    EdgeDetected <= RegDataIn and (not RegDataInPrev);
    Irq <= '1' when (unsigned(RegIntState) /= 0) else '0';
end architecture behavioral;
