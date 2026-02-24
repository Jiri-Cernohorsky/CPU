
-- VHDL Instantiation Created from source file UART.vhd -- 21:29:07 02/24/2026
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT UART
	PORT(
		clk : IN std_logic;
		rst : IN std_logic;
		RX : IN std_logic;
		WE_UART : IN std_logic;
		Address : IN std_logic_vector(31 downto 0);
		Bus_data_i : IN std_logic_vector(7 downto 0);          
		TX : OUT std_logic;
		Bus_data_o : OUT std_logic_vector(7 downto 0);
		Irq : OUT std_logic
		);
	END COMPONENT;

	Inst_UART: UART PORT MAP(
		clk => ,
		rst => ,
		RX => ,
		TX => ,
		WE_UART => ,
		Address => ,
		Bus_data_i => ,
		Bus_data_o => ,
		Irq => 
	);


