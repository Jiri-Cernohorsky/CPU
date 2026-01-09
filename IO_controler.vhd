library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IO_controler is
    port(
        clk : in std_logic;
        rst : in std_logic;
        WE : in std_logic;
        Bus_address : in std_logic_vector(31 downto 0);  
        Bus_data_i : in std_logic_vector(31 downto 0);
        Bus_data_o : out std_logic_vector(31 downto 0);
        IRR : out std_logic_vector(7 downto 0);
        W_IMR : out std_logic_vector(7 downto 0);
        GPIO_pins_io : inout std_logic_vector(7 downto 0)
    );
end entity IO_controler;

architecture RTL of IO_controler is
    component IO_WE_controler
    	port(
    		WE         : in  std_logic;
    		IO_address : in  std_logic_vector(31 downto 0);
    		WE_GPIO    : out std_logic
    	);
    end component IO_WE_controler;
    
    component GPIO
    	port(
    		clk          : in    std_logic;
    		rst          : in    std_logic;
    		GPIO_pins_io : inout std_logic_vector(7 downto 0);
    		WE_GPIO      : in    std_logic;
    		Address      : in    std_logic_vector(31 downto 0);
    		Bus_data_i   : in    std_logic_vector(7 downto 0);
    		Bus_data_o    : out   std_logic_vector(7 downto 0);
    		Irq          : out   std_logic
    	);
    end component GPIO;
    signal WE_GPIO : std_logic;
    signal GPIO_o : std_logic_vector(7 downto 0);
    signal GPIO_irq : std_logic;
    
    signal W_IMR_internal : std_logic_vector(7 downto 0);
    
    
begin
    
    IO_WE_controler_inst : component IO_WE_controler
        port map(
            WE         => WE,
            IO_address => Bus_address,
            WE_GPIO    => WE_GPIO
        );

    GPIO_inst : GPIO
        port map(
            clk            => clk,
            rst            => rst,
            GPIO_pins_io   => GPIO_pins_io,
            WE_GPIO        => WE_GPIO,
            Address        => Bus_address,
            Bus_data_i     => Bus_data_i(7 downto 0),
            Bus_data_o      => GPIO_o,
            Irq            => GPIO_irq
        );

    
    --mux
    Bus_data_o <= x"000000" & GPIO_o  when Bus_address >= x"80000004" and Bus_address <= x"80000010" else -- GPIO_o je moc malí proto to x"000000"
          --x"000000" & JINA_DATA when JINA_PODMINKA = '1' else
          x"00000000";
    
    Interrupt_handler : process(GPIO_irq) is
    begin
        IRR(0) <= GPIO_irq;
        IRR(7 downto 1) <= (others => '0');
    end process Interrupt_handler;

    -- zápis do interrapt maska
    W_IMR_internal <= Bus_data_i(7 downto 0) when Bus_address = x"80000000" and WE = '1' else W_IMR_internal;
    W_IMR <= W_IMR_internal; 

end architecture RTL;
