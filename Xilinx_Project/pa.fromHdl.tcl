
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Project -dir "/home/ise/Shared_dir/Xilinx_Project/planAhead_run_1" -part xc3s500efg320-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "/home/ise/Shared_dir/other/config_CPU.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {../vhd/synchronizer.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/periferie/UART.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/periferie/SPI_flash.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/periferie/IO_WE_Controler.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/periferie/GPIO.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/registr32x4.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/RAM2048x36.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/periferie/IO_controler.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/PC.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/Imm_decode.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/Control_unit.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/bootloader.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/ALU.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../vhd/CPU.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top CPU $srcset
add_files [list {/home/ise/Shared_dir/other/config_CPU.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s500efg320-4
