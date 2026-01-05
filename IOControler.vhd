library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IOControler is
    port(
        clk : in std_logic;
        rst : in std_logic;
        WE : in std_logic;
        Address : in std_logic_vector(31 downto 0);  
        WD : in std_logic_vector(31 downto 0);
        RD : out std_logic_vector(31 downto 0);

        GPIOPins : inout std_logic_vector(7 downto 0)
        
    );
end entity IOControler;

architecture behavioral of IOControler is
    component IO_WE_Controler
        port(
            clk       : in  std_logic;
            rst       : in  std_logic;
            WE        : in  std_logic;
            IOAddress : in  std_logic_vector(31 downto 0);
            WEGPIO    : out std_logic
        );
    end component IO_WE_Controler;

    component GPIO
        port(
            clk        : in    std_logic;
            rst        : in    std_logic;
            GPIOPins   : inout std_logic_vector(7 downto 0);
            WEGPIO     : in    std_logic;
            Address    : in    std_logic_vector(31 downto 0);
            Write_Data : in    std_logic_vector(7 downto 0);
            Read_Data  : out   std_logic_vector(7 downto 0);
            Irq        : out   std_logic
        );
    end component GPIO;
    signal WEGPIO : std_logic;
    signal GPIO_RD : std_logic_vector(7 downto 0);
    

begin

    IO_WE_Controler_inst : component IO_WE_Controler
        port map(
            clk       => clk,
            rst       => rst,
            WE        => WE,
            IOAddress => Address,
            WEGPIO    => WEGPIO
        );

    GPIO_inst : GPIO
        port map(
            clk        => clk,
            rst        => rst,
            GPIOPins   => GPIOPins,
            WEGPIO     => WEGPIO,
            Address    => Address,
            Write_Data => WD(7 downto 0),
            Read_Data  => GPIO_RD,
            Irq        => Irq
        );

    --mux
    
    RD <= x"000000" & GPIO_RD  when WEGPIO = '1' else
          x"000000" & JINA_DATA when JINA_PODMINKA = '1' else
          x"00000000";
        
    
end architecture behavioral;
