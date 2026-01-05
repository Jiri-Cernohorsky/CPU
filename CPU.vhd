library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity CPU is
    port(
        
        clk : in std_logic;
        unsyncRst : in std_logic;
        GPIOPins : inout std_logic_vector(7 downto 0)
    );
end entity CPU;

architecture behavioral of CPU is
    signal PCin : std_logic_vector(10 downto 0) := "00000000000"; --novej PC
    signal PCout : std_logic_vector(10 downto 0); -- aktuální PC
    signal PCPlus4 : std_logic_vector(10 downto 0); -- aktuální PC+4
    signal BranchTarget : std_logic_vector(10 downto 0); -- PC po větvení
    signal PCPlusImm : std_logic_vector(10 downto 0); -- aktuální PC+přímý operand
    signal shadow : std_logic; -- stav PC

    signal inst : std_logic_vector(31 downto 0); -- instrukce
    signal control_signal :  std_logic_vector (12 downto 0); -- ovládací signál
    signal IRR : std_logic_vector(7 downto 0); --interrupt request
    signal IntBraTar : std_logic_vector(10 downto 0); --interrupt cíl větvení
    signal IntBraTarEn : std_logic; --povolení interrapt větvení
    signal WIMR : std_logic_vector(7 downto 0); -- zápis do interrapt masky
    
    

    signal RegData : std_logic_vector(31 downto 0); -- data zapisující se do REG
    signal RD1 : std_logic_vector(31 downto 0); -- data z REG 1
    signal RD2 : std_logic_vector(31 downto 0); -- data z REG 2
    signal immOp : std_logic_vector(31 downto 0); --přímý operand

    signal ScrB : std_logic_vector(31 downto 0); -- druhej vstup do ALU
    signal ALUout : std_logic_vector(31 downto 0); -- výstup z ALU

    signal RDMem : std_logic_vector(31 downto 0); -- výstup z RAM
    signal RD_IO : std_logic_vector(31 downto 0); -- výstup z Periferií
    signal RDMemIO : std_logic_vector(31 downto 0); -- výstup z RAM/Periferií
    
    signal dataToREG : std_logic_vector(31 downto 0); -- hodnota z ALU/PC+4

    signal Z_Flag : std_logic; -- Z Flag
    signal BranchJalx : std_logic;
    signal BranchOutcome : std_logic; -- bude se větvit?
    signal BraEq : std_logic; -- chce se větvit a je EQ?
    
	 
	signal syncRst : std_logic;
	signal rst : std_logic;
     
	 
    component PC
    	port(
    		clk   : in  std_logic;
    		rst   : in  std_logic;
    		state : in  std_logic;
    		PCin  : in  std_logic_vector(10 downto 0);
    		PCout : out std_logic_vector(10 downto 0)
    	);
    end component PC;

    component controlUnit
    	port(
    		clk            : in  std_logic;
    		rst            : in  std_logic;
    		IRR            : in  std_logic_vector(7 downto 0);
    		WIMR           : in  std_logic_vector(7 downto 0);
    		shadow         : out std_logic;
    		IntBraTar      : out std_logic_vector(10 downto 0);
    		IntBraTarEn    : out std_logic;
    		inst           : in  std_logic_vector (31 downto 0);
    		control_signal : out std_logic_vector (12 downto 0)
    	);
    end component controlUnit;

    component registr32x4
        port(
            A1  : in  std_logic_vector(4 downto 0);
            A2  : in  std_logic_vector(4 downto 0);
            A3  : in  std_logic_vector(4 downto 0);
            WD3 : in  std_logic_vector(31 downto 0);
            WE3 : in  std_logic;
            clk : in  std_logic;
            rst : in  std_logic;
            RD1 : out std_logic_vector(31 downto 0);
            RD2 : out std_logic_vector(31 downto 0)
        );
    end component registr32x4;

    component ALU
        port(
            ScrA, ScrB : in  std_logic_vector(31 downto 0);
            ALUControl : in  std_logic_vector(2 downto 0);
            Z_Flag     : out std_logic;
            ALUout     : out std_logic_vector(31 downto 0)
        );
    end component ALU;

    component immDecode
        port(
            inst       : in  std_logic_vector(31 downto 0);
            immControl : in  std_logic_vector(2 downto 0);
            imm        : out std_logic_vector(31 downto 0)
        );
    end component immDecode;


    component RAMB512x32
        port(
            ADDR : in  std_logic_vector(8 downto 0);
            DI   : in  std_logic_vector(31 downto 0);
            WE   : in  std_logic;
            clk  : in  std_logic;
            rst  : in  std_logic;
            DO   : out std_logic_vector(31 downto 0) 
        );
    end component RAMB512x32;
   
    component IOControler
    	port(
    		clk      : in    std_logic;
    		rst      : in    std_logic;
    		WE       : in    std_logic;
    		Address  : in    std_logic_vector(31 downto 0);
    		WD       : in    std_logic_vector(31 downto 0);
    		RD       : out   std_logic_vector(31 downto 0);
    		IRR      : out   std_logic_vector(7 downto 0);
    		WIMR     : out   std_logic_vector(7 downto 0);
    		GPIOPins : inout std_logic_vector(7 downto 0)
    	);
    end component IOControler;
begin
    
    PC_inst : component PC
        port map(
            clk   => clk,
            rst   => rst,
            state => shadow,
            PCin  => PCin,
            PCout => PCout
        );
    
    controlUnit_inst : component controlUnit
        port map(
            clk            => clk,
            rst            => rst,
            inst           => inst,
            control_signal => control_signal,
            shadow         => shadow,
            IRR            => IRR,
            IntBraTar      => IntBraTar,
            IntBraTarEn    => IntBraTarEn,
            WIMR           => WIMR
        );
    
    registr32x4_inst : component registr32x4
        port map(
            A1  => inst(19 downto 15),
            A2  => inst(24 downto 20),
            A3  => inst(11 downto 7),
            WD3 => RegData,
            WE3 => control_signal(3),
            clk => clk,
            rst => rst,
            RD1 => RD1,
            RD2 => RD2
        );
    
    immDecode_inst : component immDecode
        port map(
            inst       => inst,
            immControl => control_signal(12 downto 10),
            imm        => immOp
        );
    
    ALU_inst : component ALU
        port map(
            ScrA       => RD1,
            ScrB       => ScrB,
            ALUControl => control_signal(9 downto 7),
            Z_Flag     => Z_Flag,
            ALUout     => ALUout
        );
        
    DataMem : component RAMB512x32
        port map(
            ADDR => ALUout(8 downto 0),
            DI   => RD2,
            WE   => not(ALUout(31)), --spodní půlka adres paměť, horní půlka adres I/O
            clk  => clk,
            rst  => rst,
            DO   => RDMem
        );

    InstrMem : component RAMB512x32
        port map(
            ADDR => PCout, -- !!!!!!!!! pořeba zvětšit paměť na 4násobek pak bude sedět lepší než to přepisovat všude jinde posereš se z toho když vv tom budeš zvětš i DataMem
            DI   => DI,
            WE   => WE,
            clk  => clk,
            rst  => rst,
            DO   => inst
        );
    
    IOControler_inst : IOControler
        port map(
            clk      => clk,
            rst      => rst,
            WE       => ALUout(31),
            Address  => ALUout(31 downto 0), -- mohl bych tam nedávat MSB ale 1. adresa by nebyla pravda 2. je to takhle jednodušší zapsat
            WD       => RD2,
            RD       => RD_IO,
            IRR      => IRR,
            WIMR => WIMR,
            GPIOPins => GPIOPins
        );

    main: process (clk) is
    begin
			 if rising_edge(clk) then
					if rst = '1' then
                         syncRst <= '0';
					          rst <= '0';
					else
                         syncRst <= unsyncRst;  
					          rst <= SyncRst;
                    end if;
			 end if;
    end process main;
    
    --muxy
    ScrB <= immOp when control_signal(6) = '1' else RD2;    --!!!!!!!!!!!!

    RDMemIO <= RD_IO when ALUout(31) = '1' else RDMem; -- spojeni dat z paměti a periferií

    RegData <= RDMemIO when control_signal(4) = '1' else dataToREG; -- spojeni dat z registru, PC+4, inputy a paměti

    dataToREG <= (31 downto 10 => '0') & PCPlus4(9 downto 0) when BranchJalx = '1' else ALUout; -- spojeni dat z  ALU a PC+4

    BranchTarget <= '0' & ALUout(9 downto 0) when control_signal(2) = '1' else PCPlusImm; -- adresa kam se má skočit
    
    BranchTarget <= BranchTarget when BranchOutcome = '1' else PCPlus4; -- novej PC bez interraptu

    PCin <= BranchTarget when IntBraTarEn = '0' else IntBraTar; -- nastal interrapt

    --addry
    PCPlusImm <= std_logic_vector(signed(PCout) + signed(immOp(10 downto 0))); -- PC + skok    !!!!!!!!!!!!

    PCPlus4 <= std_logic_vector(signed(PCout) + 4);-- PC++

    --and
    BraEq <= control_signal(0) and Z_Flag; -- kontrola jestli se může Bra

    --or
    BranchJalx <= control_signal(1) or control_signal(2);

    BranchOutcome <= BraEq or BranchJalx;
	 

end architecture behavioral;
