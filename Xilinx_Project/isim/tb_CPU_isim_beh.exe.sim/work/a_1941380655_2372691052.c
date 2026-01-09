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
static const char *ng0 = "/home/ise/shared_dir/CPU/tb/tb_CPU.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1941380655_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);

LAB4:    if ((unsigned char)1 != 0)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3552);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB6:;
LAB8:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3552);
    xsi_process_wait(t2, t8);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    goto LAB4;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}

static void work_a_1941380655_2372691052_p_1(char *t0)
{
    char t22[16];
    char t23[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    unsigned char t14;
    unsigned char t15;
    int t16;
    unsigned char t17;
    int t18;
    unsigned char t19;
    char *t20;
    char *t21;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 3992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 4456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 4520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(52, ng0);
    t7 = (500 * 1000LL);
    t2 = (t0 + 3800);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 4520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2472U);
    t3 = *((char **)t2);
    t8 = (31 - 7);
    t9 = (t8 * 1U);
    t10 = (0 + t9);
    t2 = (t3 + t10);
    t4 = (t0 + 4584);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = (t6 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 4712);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(58, ng0);

LAB8:    if ((unsigned char)1 != 0)
        goto LAB9;

LAB11:    xsi_set_current_line(93, ng0);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB9:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2312U);
    t3 = *((char **)t2);
    t13 = (7 - 7);
    t8 = (t13 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t2 = (t3 + t10);
    t14 = *((unsigned char *)t2);
    t4 = (t0 + 4456);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = (t6 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t14;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(60, ng0);

LAB14:    t2 = (t0 + 4312);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB10:;
LAB12:    t4 = (t0 + 4312);
    *((int *)t4) = 0;
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t13 = (2 - 2);
    t8 = (t13 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t2 = (t3 + t10);
    t14 = *((unsigned char *)t2);
    t15 = (t14 == (unsigned char)2);
    if (t15 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB8;

LAB13:    t3 = (t0 + 1472U);
    t13 = (0 - 2);
    t8 = (t13 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t14 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t3, 2U, t10);
    if (t14 == 1)
        goto LAB12;
    else
        goto LAB14;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 2152U);
    t5 = *((char **)t4);
    t16 = *((int *)t5);
    t17 = (t16 == 31);
    if (t17 != 0)
        goto LAB19;

LAB21:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2152U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t16 = (t13 + 1);
    t2 = (t0 + 4776);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    *((int *)t11) = t16;
    xsi_driver_first_trans_fast(t2);

LAB20:    goto LAB17;

LAB19:    xsi_set_current_line(63, ng0);
    t4 = (t0 + 1832U);
    t6 = *((char **)t4);
    t18 = *((int *)t6);
    t19 = (t18 == 0);
    if (t19 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2312U);
    t3 = *((char **)t2);
    t8 = (7 - 6);
    t9 = (t8 * 1U);
    t10 = (0 + t9);
    t2 = (t3 + t10);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t23 + 0U);
    t11 = (t6 + 0U);
    *((int *)t11) = 6;
    t11 = (t6 + 4U);
    *((int *)t11) = 0;
    t11 = (t6 + 8U);
    *((int *)t11) = -1;
    t13 = (0 - 6);
    t24 = (t13 * -1);
    t24 = (t24 + 1);
    t11 = (t6 + 12U);
    *((unsigned int *)t11) = t24;
    t4 = xsi_base_array_concat(t4, t22, t5, (char)97, t2, t23, (char)99, (unsigned char)2, (char)101);
    t24 = (7U + 1U);
    t14 = (8U != t24);
    if (t14 == 1)
        goto LAB38;

LAB39:    t11 = (t0 + 4584);
    t12 = (t11 + 56U);
    t20 = *((char **)t12);
    t21 = (t20 + 56U);
    t25 = *((char **)t21);
    memcpy(t25, t4, 8U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t16 = (t13 - 1);
    t2 = (t0 + 4712);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    *((int *)t11) = t16;
    xsi_driver_first_trans_fast(t2);

LAB23:    goto LAB20;

LAB22:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 4712);
    t11 = (t4 + 56U);
    t12 = *((char **)t11);
    t20 = (t12 + 56U);
    t21 = *((char **)t20);
    *((int *)t21) = 7;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t14 = (t13 == 0);
    if (t14 != 0)
        goto LAB25;

LAB27:    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t14 = (t13 == 1);
    if (t14 != 0)
        goto LAB28;

LAB29:    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t14 = (t13 == 2);
    if (t14 != 0)
        goto LAB30;

LAB31:    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t15 = (t13 >= 3);
    if (t15 == 1)
        goto LAB34;

LAB35:    t14 = (unsigned char)0;

LAB36:    if (t14 != 0)
        goto LAB32;

LAB33:    xsi_set_current_line(79, ng0);
    goto LAB11;

LAB25:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t8 = (31 - 15);
    t9 = (t8 * 1U);
    t10 = (0 + t9);
    t2 = (t4 + t10);
    t5 = (t0 + 4584);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    t12 = (t11 + 56U);
    t20 = *((char **)t12);
    memcpy(t20, t2, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 1;
    xsi_driver_first_trans_fast(t2);

LAB26:    goto LAB23;

LAB28:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t8 = (31 - 23);
    t9 = (t8 * 1U);
    t10 = (0 + t9);
    t2 = (t4 + t10);
    t5 = (t0 + 4584);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    t12 = (t11 + 56U);
    t20 = *((char **)t12);
    memcpy(t20, t2, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 2;
    xsi_driver_first_trans_fast(t2);
    goto LAB26;

LAB30:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t8 = (31 - 31);
    t9 = (t8 * 1U);
    t10 = (0 + t9);
    t2 = (t4 + t10);
    t5 = (t0 + 4584);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    t12 = (t11 + 56U);
    t20 = *((char **)t12);
    memcpy(t20, t2, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 3;
    xsi_driver_first_trans_fast(t2);
    goto LAB26;

LAB32:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 7416);
    t6 = (t0 + 4584);
    t11 = (t6 + 56U);
    t12 = *((char **)t11);
    t20 = (t12 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t2, 8U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t13 = *((int *)t3);
    t16 = (t13 + 1);
    t2 = (t0 + 4648);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t11 = *((char **)t6);
    *((int *)t11) = t16;
    xsi_driver_first_trans_fast(t2);
    goto LAB26;

LAB34:    t2 = (t0 + 1992U);
    t4 = *((char **)t2);
    t16 = *((int *)t4);
    t17 = (t16 < 7);
    t14 = t17;
    goto LAB36;

LAB37:    goto LAB26;

LAB38:    xsi_size_not_matching(8U, t24, 0);
    goto LAB39;

LAB40:    goto LAB2;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

}


extern void work_a_1941380655_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1941380655_2372691052_p_0,(void *)work_a_1941380655_2372691052_p_1};
	xsi_register_didat("work_a_1941380655_2372691052", "isim/tb_CPU_isim_beh.exe.sim/work/a_1941380655_2372691052.didat");
	xsi_register_executes(pe);
}
