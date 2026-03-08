/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/ise/Shared_dir/vhd/periferie/IO_WE_Controler.vhd";
extern char *IEEE_P_2592010699;



static void work_a_2515606248_1516540902_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    xsi_set_current_line(19, ng0);
    t1 = (t0 + 3064);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(20, ng0);
    t1 = (t0 + 3128);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(21, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t6 = *((unsigned char *)t2);
    t7 = (t6 == (unsigned char)3);
    if (t7 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2984);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t1 = (t0 + 4873);
    t5 = ((IEEE_P_2592010699) + 4000);
    t9 = xsi_vhdl_greaterEqual(t5, t3, 32U, t1, 32U);
    if (t9 == 1)
        goto LAB8;

LAB9:    t8 = (unsigned char)0;

LAB10:    if (t8 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4937);
    t4 = ((IEEE_P_2592010699) + 4000);
    t7 = xsi_vhdl_greaterEqual(t4, t2, 32U, t1, 32U);
    if (t7 == 1)
        goto LAB13;

LAB14:    t6 = (unsigned char)0;

LAB15:    if (t6 != 0)
        goto LAB11;

LAB12:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(23, ng0);
    t15 = (t0 + 3064);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t15);
    goto LAB6;

LAB8:    t10 = (t0 + 1192U);
    t11 = *((char **)t10);
    t10 = (t0 + 4905);
    t13 = ((IEEE_P_2592010699) + 4000);
    t14 = xsi_vhdl_lessthanEqual(t13, t11, 32U, t10, 32U);
    t8 = t14;
    goto LAB10;

LAB11:    xsi_set_current_line(25, ng0);
    t13 = (t0 + 3128);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t13);
    goto LAB6;

LAB13:    t5 = (t0 + 1192U);
    t10 = *((char **)t5);
    t5 = (t0 + 4969);
    t12 = ((IEEE_P_2592010699) + 4000);
    t8 = xsi_vhdl_lessthanEqual(t12, t10, 32U, t5, 32U);
    t6 = t8;
    goto LAB15;

}


extern void work_a_2515606248_1516540902_init()
{
	static char *pe[] = {(void *)work_a_2515606248_1516540902_p_0};
	xsi_register_didat("work_a_2515606248_1516540902", "isim/tb_Bootloader_isim_beh.exe.sim/work/a_2515606248_1516540902.didat");
	xsi_register_executes(pe);
}
