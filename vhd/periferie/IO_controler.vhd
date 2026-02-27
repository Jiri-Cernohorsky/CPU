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
        IRR : out std_logic_vector(7 downto 0);   -- interupt request registr
        W_IMR : out std_logic_vector(7 downto 0);  --interrupt maska regist pro zápis vytažený z Control unit
        GPIO_pins_io : inout std_logic_vector(7 downto 0);
        UART_TX : out std_logic;
        UART_RX : in std_logic;
        SPI_o : out std_logic_vector(2 downto 0); -- 0. sclk 1. mosi 2. cs_n
        SPI_i : in std_logic
    );
end entity IO_controler;

architecture RTL of IO_controler is
    component IO_WE_controler
    	port(
    		WE         : in  std_logic;
    		IO_address : in  std_logic_vector(31 downto 0);
    		WE_GPIO    : out std_logic;
    		WE_UART    : out std_logic
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
    
    component UART
        port(
            clk        : in  std_logic;
            rst        : in  std_logic;
            RX         : in  std_logic;
            TX         : out std_logic;
            WE_UART    : in  std_logic;
            Address    : in  std_logic_vector(31 downto 0);
            Bus_data_i : in  std_logic_vector(7 downto 0);
            Bus_data_o : out std_logic_vector(7 downto 0);
            Irq        : out std_logic
        );
    end component UART;
    signal WE_UART : std_logic;
    signal UART_o : std_logic_vector(7 downto 0);
    signal UART_irq : std_logic;

    component SPI_flash
        port(
            clk            : in  std_logic;
            rst            : in  std_logic;
            Adress_i       : in  std_logic_vector(23 downto 0);
            Data_i         : in  std_logic_vector(31 downto 0);
            CMD_sel        : in  std_logic_vector(1 downto 0);
            EN_comm        : in  std_logic;
            Ready_to_read  : in  std_logic                     := '1';
            Ready_to_write : in  std_logic                     := '1';
            Data_o         : out std_logic_vector(31 downto 0) := (others => '0');
            Read_done      : out std_logic;
            Write_start    : out std_logic;
            CMD_done       : out std_logic;
            SPI_sclk       : out std_logic;
            SPI_mosi       : out std_logic;
            SPI_miso       : in  std_logic;
            SPI_cs_n       : out std_logic
        );
    end component SPI_flash;
    signal SPI_control_o : std_logic_vector(2 downto 0);
    signal SPI_control_i : std_logic_vector(4 downto 0);
    signal SPI_address : std_logic_vector(23 downto 0);
    signal SPI_data_i : std_logic_vector(31 downto 0);
    signal SPI_data_o : std_logic_vector(31 downto 0);
  
    
    
    
    
    
    

    signal W_IMR_internal : std_logic_vector(7 downto 0);

begin
    
    IO_WE_controler_inst : component IO_WE_controler
        port map(
            WE         => WE,
            IO_address => Bus_address,
            WE_GPIO    => WE_GPIO,
            WE_UART => WE_UART
        );

    GPIO_inst : GPIO
        port map(
            clk            => clk,
            rst            => rst,
            GPIO_pins_io   => GPIO_pins_io,
            WE_GPIO        => WE_GPIO,
            Address        => Bus_address,
            Bus_data_i     => Bus_data_i(7 downto 0),
            Bus_data_o     => GPIO_o,
            Irq            => GPIO_irq
        );
    
    UART_inst : UART
        port map(
            clk        => clk,
            rst        => rst,
            RX         => UART_RX,
            TX         => UART_TX,
            WE_UART    => WE_UART,
            Address    => Bus_address,
            Bus_data_i => Bus_data_i(7 downto 0),
            Bus_data_o => UART_o,
            Irq        => UART_irq
        );

    SPI_flash_inst : SPI_flash
        port map(
            clk            => clk,
            rst            => rst,
            Adress_i       => SPI_address,
            Data_i         => SPI_data_i,
            CMD_sel        => SPI_control_i(1 downto 0),
            EN_comm        => SPI_control_i(2),
            Ready_to_read  => SPI_control_i(3),
            Ready_to_write => SPI_control_i(4),
            Data_o         => SPI_data_o,
            Read_done      => SPI_control_o(0),
            Write_start    => SPI_control_o(1),
            CMD_done       => SPI_control_o(2),
            SPI_sclk       => SPI_o(0),
            SPI_mosi       => SPI_o(1),
            SPI_miso       => SPI_i,
            SPI_cs_n       => SPI_o(2)
        );


    -- write adresy
    W_IMR_internal  <= Bus_data_i(7 downto 0)   when Bus_address = x"80000000" and WE = '1' else W_IMR_internal;
        --SPI
    SPI_control_i   <= Bus_data_i(4 downto 0)   when Bus_address = x"80000004" and WE = '1' else SPI_control_i;
    SPI_address     <= Bus_data_i(23 downto 0)  when Bus_address = x"8000000C" and WE = '1' else SPI_address;
    SPI_data_i      <= Bus_data_i               when Bus_address = x"80000010" and WE = '1' else SPI_data_i ;


    -- read adresy
    Bus_data_o <= x"000000" & "000" &   SPI_control_i   when Bus_address = x"80000004" else
                  x"0000000" & "0" &    SPI_control_o   when Bus_address = x"80000008" else
                  x"00" &               SPI_address     when Bus_address = x"8000000C" else
                                        SPI_data_i      when Bus_address = x"80000010" else
                                        SPI_data_o      when Bus_address = x"80000014";

    --výběr správného výstupu na základě adresy
    Bus_data_o <= x"000000" & GPIO_o  when Bus_address >= x"80000004" and Bus_address <= x"80000010" else -- GPIO_o je moc malí proto to x"000000"
                  x"000000" & UART_o  when Bus_address >= x"80000104" and Bus_address <= x"80000110" else
          --x"000000" & JINA_DATA when JINA_PODMINKA = '1' else
          x"00000000";
    
    Interrupt_handler : process(GPIO_irq, UART_irq) is
    begin
        IRR(0) <= GPIO_irq;
        IRR(1) <= UART_irq;
        IRR(7 downto 2) <= (others => '0');
    end process Interrupt_handler;

    -- zápis do interrapt masky
    W_IMR <= W_IMR_internal; 

end architecture RTL;
