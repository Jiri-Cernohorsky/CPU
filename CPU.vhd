library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
Library UNISIM;
use UNISIM.vcomponents.all;

entity CPU is
    port(
        
        clk : in std_logic;
        unsyncRst : in std_logic;
        Buttons : in std_logic_vector(3 downto 0);
        Leds : out std_logic_vector(7 downto 0)
    );
end entity CPU;

architecture behavioral of CPU is
    signal PCin : std_logic_vector(10 downto 0) := "00000000000"; --novej PC
    signal PCout : std_logic_vector(10 downto 0); -- aktuální PC
    signal PCPlus4 : std_logic_vector(10 downto 0); -- aktuální PC+4
    signal BranchTarget : std_logic_vector(10 downto 0); -- PC po větvení
    signal PCPlusImm : std_logic_vector(10 downto 0); -- aktuální PC+přímý operand

    signal inst : std_logic_vector(31 downto 0); -- instrukce
    signal control_signal :  std_logic_vector (12 downto 0); -- ovládací signál

    signal memData : std_logic_vector(31 downto 0); -- data zapisující se do REG
    signal RD1 : std_logic_vector(31 downto 0); -- data z REG 1
    signal RD2 : std_logic_vector(31 downto 0); -- data z REG 2
    signal immOp : std_logic_vector(31 downto 0); --přímý operand

    signal ScrB : std_logic_vector(31 downto 0); -- druhej vstup do ALU
    signal ALUout : std_logic_vector(31 downto 0); -- výstup z ALU

    signal RDMem : std_logic_vector(31 downto 0); -- výstup z RAM
    signal IOandRDMem : std_logic_vector(31 downto 0); -- výstup z RAM/inputů
    signal dataToREG : std_logic_vector(31 downto 0); -- hodnota z ALU/PC+4
    signal WERAM : std_logic; -- WE do paměti
    signal WELed : std_logic; -- WE na led výstup
    signal Sel : std_logic; -- výběr co se čte inputy/paměti 

    signal Z_Flag : std_logic; -- Z Flag
    signal BranchJalx : std_logic;
    signal BranchOutcome : std_logic; -- bude se větvit?
    signal BraEq : std_logic; -- chce se větvit a je EQ?
    
	 signal Parity_dummy : std_logic_vector(3 downto 0);
	 
	 signal FullSyncButtons : std_logic_vector(3 downto 0);
	 signal SyncButtons : std_logic_vector(3 downto 0);
	 signal syncRst : std_logic;
	 signal rst : std_logic;
	 
    component PC
        port(
            clk   : in  std_logic;
            rst   : in  std_logic;
            PCin  : in  std_logic_vector(10 downto 0);
            PCout : out std_logic_vector(10 downto 0)
        );
    end component PC;

    component InstrMem
        port(
            A  : in  std_logic_vector(10 downto 0);
            RD : out std_logic_vector(31 downto 0)
        );
    end component InstrMem;

    component controlUnit
        port(
            inst           : in  STD_LOGIC_VECTOR (31 downto 0);
            control_signal : out STD_LOGIC_VECTOR (12 downto 0)
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

    component RAM1024x1
        port(
            A   : in  std_logic_vector(9 downto 0);
            WD1 : in  std_logic_vector(7 downto 0);
            WD4 : in  std_logic_vector(31 downto 0);
            WE1 : in  std_logic;
            WE4 : in  std_logic;
            clk : in  std_logic;
            rst : in  std_logic;
            RD1 : out std_logic_vector(7 downto 0);
            RD4 : out std_logic_vector(31 downto 0)
        );
    end component RAM1024x1;

    component AddressDecode
        port(
            WE    : in  std_logic;
            A     : in  std_logic_vector(10 downto 0);
            WELed : out std_logic;
            WERAM : out std_logic;
            Sel   : out std_logic
        );
    end component AddressDecode;




begin
	
   RAMB16_S36_dataMem : RAMB16_S36
   generic map (
      INIT => X"000000000",  --  Value of output RAM registers at startup
      SRVAL => X"000000000", --  Output value upon SSR assertion
      WRITE_MODE => "WRITE_FIRST", --  WRITE_FIRST, READ_FIRST or NO_CHANGE
      -- The following INIT_xx declarations specify the initial contents of the RAM
      -- Address 0 to 127
      INIT_00 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_01 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_02 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_03 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_04 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_05 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_06 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_07 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_08 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_09 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0A => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0B => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0C => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0D => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0E => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_0F => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 128 to 255
      INIT_10 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_11 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_12 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_13 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_14 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_15 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_16 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_17 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_18 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_19 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1A => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1B => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1C => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1D => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1E => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_1F => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 256 to 383
      INIT_20 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_21 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_22 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_23 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_24 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_25 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_26 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_27 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_28 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_29 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2A => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2B => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2C => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2D => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2E => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_2F => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 384 to 511
      INIT_30 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_31 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_32 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_33 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_34 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_35 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_36 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_37 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_38 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_39 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3A => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3B => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3C => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3D => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3E => X"0000000000000000000000000000000000000000000000000000000000000000",
      INIT_3F => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- The next set of INITP_xx are for the parity bits
      -- Address 0 to 127
      INITP_00 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INITP_01 => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 128 to 255
      INITP_02 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INITP_03 => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 256 to 383
      INITP_04 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INITP_05 => X"0000000000000000000000000000000000000000000000000000000000000000",
      -- Address 384 to 511
      INITP_06 => X"0000000000000000000000000000000000000000000000000000000000000000",
      INITP_07 => X"0000000000000000000000000000000000000000000000000000000000000000")
   port map (
      DO => RDMem,      -- 32-bit Data Output
      DOP => parity_dummy,    -- 4-bit parity Output
      ADDR => ALUout(8 downto 0),  -- 9-bit Address Input
      CLK => clk,    -- Clock
      DI => RD2,      -- 32-bit Data Input
      DIP => "0000",    -- 4-bit parity Input
      EN => '1',      -- RAM Enable Input
      SSR => rst,    -- Synchronous Set/Reset Input
      WE => WERAM       -- Write Enable Input
   );
    
    PC_inst : component PC
        port map(
            clk   => clk,
            rst   => rst,
            PCin  => PCin,
            PCout => PCout
        );

    InstrMem_inst : component InstrMem
        port map(
            A  => PCout,
            RD => inst
        );
    
    controlUnit_inst : component controlUnit
        port map(
            inst           => inst,
            control_signal => control_signal
        );
    
    registr32x4_inst : component registr32x4
        port map(
            A1  => inst(19 downto 15),
            A2  => inst(24 downto 20),
            A3  => inst(11 downto 7),
            WD3 => memData,
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
    
    
    AddressDecode_inst : component AddressDecode
        port map(
            WE    => control_signal(5),
            A     => ALUout(10 downto 0),
            WELed => WELed,
            WERAM => WERAM,
            Sel   => Sel
        );


    main: process (clk) is
    begin
			 if rising_edge(clk) then
					if rst = '1' then
						 Leds <= (others => '0');
                         FullSyncButtons <= (others => '0');
					          SyncButtons <= (others => '0');
                         syncRst <= '0';
					          rst <= '0';
					else
						 if WELed = '1' then
							  Leds <= RD2(7 downto 0);
						 end if;
                         SyncButtons <= Buttons;  
								 FullSyncButtons <= SyncButtons;
                         syncRst <= unsyncRst;  
					          rst <= SyncRst;
                    end if;
			 end if;

    end process main;
    
    --muxy
    ScrB <= immOp when control_signal(6) = '1' else RD2;    --!!!!!!!!!!!!

    IOandRDMem <=  (31 downto 4 => '0') & FullSyncButtons when Sel = '1' else RDMem; -- výběr co se čte inputy/paměti

    memData <= IOandRDMem when control_signal(4) = '1' else dataToREG; -- výběr co se čte data do registru nebo inputy/paměti

    dataToREG <= (31 downto 10 => '0') & PCPlus4(9 downto 0) when BranchJalx = '1' else ALUout; -- hodnota z ALU/PC+4

    BranchTarget <= '0' & ALUout(9 downto 0) when control_signal(2) = '1' else PCPlusImm; -- adresa kam se má skočit
    
    PCin <= BranchTarget when BranchOutcome = '1' else PCPlus4; -- novej PC

    --addry
    PCPlusImm <= std_logic_vector(signed(PCout) + signed(immOp(10 downto 0))); -- PC + skok    !!!!!!!!!!!!

    PCPlus4 <= std_logic_vector(signed(PCout) + 4);-- PC++

    --and
    BraEq <= control_signal(0) and Z_Flag; -- kontrola jestli se může Bra

    --or
    BranchJalx <= control_signal(1) or control_signal(2);

    BranchOutcome <= BraEq or BranchJalx;
	 

end architecture behavioral;
