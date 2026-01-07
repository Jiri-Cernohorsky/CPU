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
static const char *ng0 = "/home/ise/shared_dir/CPU/periferie/IO_WE_Controler.vhd";
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
    char *t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 2904);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t6 = *((unsigned char *)t2);
    t7 = (t6 == (unsigned char)3);
    if (t7 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2824);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t1 = (t0 + 4577);
    t5 = ((IEEE_P_2592010699) + 4000);
    t9 = xsi_vhdl_greaterEqual(t5, t3, 32U, t1, 32U);
    if (t9 == 1)
        goto LAB8;

LAB9:    t8 = (unsigned char)0;

LAB10:    if (t8 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(21, ng0);
    t15 = (t0 + 2904);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t15);
    goto LAB6;

LAB8:    t10 = (t0 + 1192U);
    t11 = *((char **)t10);
    t10 = (t0 + 4609);
    t13 = ((IEEE_P_2592010699) + 4000);
    t14 = xsi_vhdl_lessthanEqual(t13, t11, 32U, t10, 32U);
    t8 = t14;
    goto LAB10;

}


extern void work_a_2515606248_1516540902_init()
{
	static char *pe[] = {(void *)work_a_2515606248_1516540902_p_0};
	xsi_register_didat("work_a_2515606248_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_2515606248_1516540902.didat");
	xsi_register_executes(pe);
}
