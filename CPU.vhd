library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity CPU is
    port(
        
        clk : in std_logic;
        async_rst : in std_logic;
        GPIO_pins_io : inout std_logic_vector(7 downto 0)
    );
end entity CPU;

architecture RTL of CPU is
    signal PC_i : std_logic_vector(10 downto 0) := "00000000000"; --novej PC
    signal PC_o : std_logic_vector(10 downto 0); -- aktuální PC
    signal PC_plus_4 : std_logic_vector(10 downto 0); -- aktuální PC+4
    signal Branch_target : std_logic_vector(10 downto 0); -- PC po větvení
    signal PC_plus_imm : std_logic_vector(10 downto 0); -- aktuální PC+přímý operand
    signal Shadow : std_logic; -- stav PC

    signal Inst : std_logic_vector(31 downto 0); -- instrukce
    signal Control_signal :  std_logic_vector (12 downto 0); -- ovládací signál
    signal IRR : std_logic_vector(7 downto 0); --interrupt request
    signal Int_bra_tar : std_logic_vector(10 downto 0); --interrupt cíl větvení
    signal Int_bra_tar_en : std_logic; --povolení interrapt větvení
    signal W_IMR : std_logic_vector(7 downto 0); -- zápis do interrapt masky
    


    signal Data_reg_i : std_logic_vector(31 downto 0); -- data zapisující se do REG
    signal Data_reg_o_1 : std_logic_vector(31 downto 0); -- data z REG 1
    signal Data_reg_o_2 : std_logic_vector(31 downto 0); -- data z REG 2
    signal Imm_op : std_logic_vector(31 downto 0); --přímý operand

    signal Scr_B : std_logic_vector(31 downto 0); -- druhej vstup do ALU
    signal ALU_o : std_logic_vector(31 downto 0); -- výstup z ALU

    signal RD_mem : std_logic_vector(31 downto 0); -- výstup z RAM
    signal RD_IO : std_logic_vector(31 downto 0); -- výstup z Periferií
    signal RD_mem_IO : std_logic_vector(31 downto 0); -- výstup z RAM/Periferií
    signal Branch_mux_o : std_logic_vector(10 downto 0); 

    signal Data_to_reg : std_logic_vector(31 downto 0); -- hodnota z ALU/PC+4

    signal Flag_z : std_logic; -- Z Flag
    signal Branch_jalx : std_logic;
    signal Branch_outcome : std_logic; -- bude se větvit?
    signal Branch_eq : std_logic; -- chce se větvit a je EQ?
    
    signal Semi_sync_rst : std_logic;
	signal rst : std_logic;

    signal Data_i_dummy : std_logic_vector(31 downto 0);
    signal WE_dummy : std_logic;
    

    component PC
    	port(
    		clk    : in  std_logic;
    		rst    : in  std_logic;
    		Shadow : in  std_logic;
    		PC_i   : in  std_logic_vector(10 downto 0);
    		PC_o  : out std_logic_vector(10 downto 0)
    	);
    end component PC;

    component Control_unit
        port(
            clk            : in  std_logic;
            rst            : in  std_logic;
            IRR            : in  std_logic_vector(7 downto 0);
            W_IMR          : in  std_logic_vector(7 downto 0);
            Shadow         : out std_logic;
            Int_bra_tar    : out std_logic_vector(10 downto 0);
            Int_bra_tar_en : out std_logic;
            Inst           : in  std_logic_vector (31 downto 0);
            Control_signal : out std_logic_vector (12 downto 0)
        );
    end component Control_unit;

    component registr32x4
    	port(
    		clk : in  std_logic;
    		rst : in  std_logic;
    		A1  : in  std_logic_vector(4 downto 0);
    		A2  : in  std_logic_vector(4 downto 0);
    		A3  : in  std_logic_vector(4 downto 0);
    		WD3 : in  std_logic_vector(31 downto 0);
    		WE3 : in  std_logic;
    		RD1 : out std_logic_vector(31 downto 0);
    		RD2 : out std_logic_vector(31 downto 0)
    	);
    end component registr32x4;

    component ALU
    	port(
    		Scr_A, Scr_B : in  std_logic_vector(31 downto 0);
    		ALU_control  : in  std_logic_vector(2 downto 0);
    		Flag_z       : out std_logic;
    		ALU_o        : out std_logic_vector(31 downto 0)
    	);
    end component ALU;

    component Imm_decode
    	port(
    		Inst        : in  std_logic_vector(31 downto 0);
    		Imm_control : in  std_logic_vector(2 downto 0);
    		Imm         : out std_logic_vector(31 downto 0)
    	);
    end component Imm_decode;


    component RAM2048x32
    	port(
    		clk     : in  std_logic;
    		rst     : in  std_logic;
    		Address : in  std_logic_vector(10 downto 0);
    		Data_i  : in  std_logic_vector(31 downto 0);
    		WE      : in  std_logic;
    		Data_o  : out std_logic_vector(31 downto 0)
    	);
    end component RAM2048x32;
   
    component IO_controler
    	port(
    		clk          : in    std_logic;
    		rst          : in    std_logic;
    		WE           : in    std_logic;
    		Bus_address  : in    std_logic_vector(31 downto 0);
    		Bus_data_i   : in    std_logic_vector(31 downto 0);
    		Bus_data_o   : out   std_logic_vector(31 downto 0);
    		IRR          : out   std_logic_vector(7 downto 0);
    		W_IMR        : out   std_logic_vector(7 downto 0);
    		GPIO_pins_io : inout std_logic_vector(7 downto 0)
    	);
    end component IO_controler;

    component InstrMem
        port(
            A  : in  std_logic_vector(10 downto 0);
            RD : out std_logic_vector(31 downto 0)
        );
    end component InstrMem;
begin
    
    PC_inst : component PC
        port map(
            clk   => clk,
            rst   => rst,
            Shadow => Shadow,
            PC_i  => PC_i,
            PC_o => PC_o
        );
    
    Control_unit_inst : component Control_unit
        port map(
            clk            => clk,
            rst            => rst,
            inst           => Inst,
            control_signal => Control_signal,
            shadow         => Shadow,
            IRR            => IRR,
            Int_bra_tar    => Int_bra_tar,
            Int_bra_tar_en => Int_bra_tar_en,
            W_IMR          => W_IMR
        );
    
    registr32x4_inst : component registr32x4
        port map(
            A1  => Inst(19 downto 15),
            A2  => Inst(24 downto 20),
            A3  => Inst(11 downto 7),
            WD3 => Data_reg_i,
            WE3 => Control_signal(3),
            clk => clk,
            rst => rst,
            RD1 => Data_reg_o_1,
            RD2 => Data_reg_o_2
        );
    
    Imm_decode_inst : component Imm_decode
        port map(
            Inst       => Inst,
            Imm_control => Control_signal(12 downto 10),
            Imm        => Imm_op
        );
    
    ALU_inst : component ALU
        port map(
            Scr_A       => Data_reg_o_1,
            Scr_B       => Scr_B,
            ALU_control => Control_signal(9 downto 7),
            Flag_z      => Flag_z,
            ALU_o       => ALU_o
        );
        
    Data_mem : component RAM2048x32
        port map(
            Address => ALU_o(10 downto 0),
            Data_i   => Data_reg_o_2,
            WE   => not(ALU_o(31)), --spodní půlka adres paměť, horní půlka adres I/O
            clk  => clk,
            rst  => rst,
            Data_o   => RD_mem
        );

    --Instr_mem : component RAM2048x32
    --    port map(
    --        Address  => PC_o,
    --        Data_i   => Data_i_dummy,
    --        WE       => WE_dummy,
    --        clk      => clk,
    --        rst      => rst,
    --        Data_o   => Inst
    --    );
    InstrMem_inst : component InstrMem
        port map(
            A  => PC_o,
            RD => Inst
        );
    
    
    IO_controler_inst : IO_controler
        port map(
            clk          => clk,
            rst          => rst,
            WE           => ALU_o(31),
            Bus_address  => ALU_o(31 downto 0), -- mohl bych tam nedávat MSB ale 1. adresa by nebyla pravda 2. je to takhle jednodušší zapsat
            Bus_data_i   => Data_reg_o_2,
            Bus_data_o   => RD_IO,
            IRR          => IRR,
            W_IMR        => W_IMR,
            GPIO_pins_io => GPIO_pins_io
        );

    Main: process (clk) is
    begin
			 if rising_edge(clk) then
                Semi_sync_rst <= async_rst;  
                rst <= Semi_sync_rst;
			 end if;
    end process Main;
    
    --muxy
    Scr_B <= Imm_op when Control_signal(6) = '1' else Data_reg_o_2;    --!!!!!!!!!!!!

    RD_mem_IO <= RD_IO when ALU_o(31) = '1' else RD_mem; -- spojeni dat z paměti a periferií

    Data_reg_i <= RD_mem_IO when Control_signal(4) = '1' else Data_to_reg; -- spojeni dat z registru, PC+4, inputy a paměti

    Data_to_reg <= (31 downto 10 => '0') & PC_plus_4(9 downto 0) when Branch_jalx = '1' else ALU_o; -- spojeni dat z  ALU a PC+4

    Branch_target <= '0' & ALU_o(9 downto 0) when Control_signal(2) = '1' else PC_plus_imm; -- adresa kam se má skočit
    
    Branch_mux_o <= Branch_target when Branch_outcome = '1' else PC_plus_4; -- novej PC bez interraptu

    PC_i <= Branch_mux_o when Int_bra_tar_en = '0' else Int_bra_tar; -- nastal interrapt

    --addry
    PC_plus_imm <= std_logic_vector(signed(PC_o) + signed(Imm_op(10 downto 0))); -- PC + skok    !!!!!!!!!!!!

    PC_plus_4 <= std_logic_vector(signed(PC_o) + 4);-- PC++

    --and
    Branch_eq <= Control_signal(0) and Flag_z; -- kontrola jestli se může Bra

    --or
    Branch_jalx <= Control_signal(1) or Control_signal(2);

    Branch_outcome <= Branch_eq or Branch_jalx;
	 

end architecture RTL;
