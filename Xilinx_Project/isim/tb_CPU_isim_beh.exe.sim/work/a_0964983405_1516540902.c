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
static const char *ng0 = "/home/ise/shared_dir/CPU/IO_controler.vhd";
extern char *IEEE_P_2592010699;



static void work_a_0964983405_1516540902_p_0(char *t0)
{
    char t16[16];
    char t18[16];
    unsigned char t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t10;
    unsigned char t11;
    char *t12;
    char *t14;
    char *t15;
    char *t17;
    char *t19;
    char *t20;
    int t21;
    unsigned int t22;
    unsigned char t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t2 = (t0 + 8173);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = xsi_vhdl_greaterEqual(t5, t3, 32U, t2, 32U);
    if (t6 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB10:    t29 = (t0 + 8261);
    t31 = (t0 + 5296);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t29, 32U);
    xsi_driver_first_trans_fast_port(t31);

LAB2:    t36 = (t0 + 5168);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t12 = (t0 + 8237);
    t14 = (t0 + 2632U);
    t15 = *((char **)t14);
    t17 = ((IEEE_P_2592010699) + 4000);
    t19 = (t18 + 0U);
    t20 = (t19 + 0U);
    *((int *)t20) = 0;
    t20 = (t19 + 4U);
    *((int *)t20) = 23;
    t20 = (t19 + 8U);
    *((int *)t20) = 1;
    t21 = (23 - 0);
    t22 = (t21 * 1);
    t22 = (t22 + 1);
    t20 = (t19 + 12U);
    *((unsigned int *)t20) = t22;
    t20 = (t0 + 8048U);
    t14 = xsi_base_array_concat(t14, t16, t17, (char)97, t12, t18, (char)97, t15, t20, (char)101);
    t22 = (24U + 8U);
    t23 = (32U != t22);
    if (t23 == 1)
        goto LAB8;

LAB9:    t24 = (t0 + 5296);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t14, 32U);
    xsi_driver_first_trans_fast_port(t24);
    goto LAB2;

LAB5:    t7 = (t0 + 1512U);
    t8 = *((char **)t7);
    t7 = (t0 + 8205);
    t10 = ((IEEE_P_2592010699) + 4000);
    t11 = xsi_vhdl_lessthanEqual(t10, t8, 32U, t7, 32U);
    t1 = t11;
    goto LAB7;

LAB8:    xsi_size_not_matching(32U, t22, 0);
    goto LAB9;

LAB11:    goto LAB2;

}

static void work_a_0964983405_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5360);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_delta(t1, 7U, 1, 0LL);
    xsi_set_current_line(77, ng0);
    t1 = xsi_get_transient_memory(7U);
    memset(t1, 0, 7U);
    t2 = t1;
    memset(t2, (unsigned char)2, 7U);
    t4 = (t0 + 5360);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 7U);
    xsi_driver_first_trans_delta(t4, 0U, 7U, 0LL);
    t1 = (t0 + 5184);
    *((int *)t1) = 1;

LAB1:    return;
}

static void work_a_0964983405_1516540902_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;

LAB0:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t2 = (t0 + 8293);
    t5 = 1;
    if (32U == 32U)
        goto LAB8;

LAB9:    t5 = 0;

LAB10:    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB14:    t22 = (t0 + 2952U);
    t23 = *((char **)t22);
    t22 = (t0 + 5424);
    t24 = (t22 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t23, 8U);
    xsi_driver_first_trans_fast(t22);

LAB2:    t28 = (t0 + 5200);
    *((int *)t28) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 1672U);
    t13 = *((char **)t9);
    t14 = (31 - 7);
    t15 = (t14 * 1U);
    t16 = (0 + t15);
    t9 = (t13 + t16);
    t17 = (t0 + 5424);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t9, 8U);
    xsi_driver_first_trans_fast(t17);
    goto LAB2;

LAB5:    t9 = (t0 + 1352U);
    t10 = *((char **)t9);
    t11 = *((unsigned char *)t10);
    t12 = (t11 == (unsigned char)3);
    t1 = t12;
    goto LAB7;

LAB8:    t6 = 0;

LAB11:    if (t6 < 32U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t7 = (t3 + t6);
    t8 = (t2 + t6);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB9;

LAB13:    t6 = (t6 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0964983405_1516540902_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(82, ng0);

LAB3:    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t1 = (t0 + 5488);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 5216);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0964983405_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0964983405_1516540902_p_0,(void *)work_a_0964983405_1516540902_p_1,(void *)work_a_0964983405_1516540902_p_2,(void *)work_a_0964983405_1516540902_p_3};
	xsi_register_didat("work_a_0964983405_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_0964983405_1516540902.didat");
	xsi_register_executes(pe);
}
