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
static const char *ng0 = "/home/ise/shared_dir/CPU/periferie/SPI_flash.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0663295785_1516540902_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    int t12;

LAB0:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6088);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(46, ng0);
    t3 = (t0 + 2632U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)0);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 3);
    if (t2 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 + 1);
    t1 = (t0 + 6216);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 6280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(47, ng0);
    t3 = (t0 + 6216);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 6280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 6216);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(52, ng0);
    t1 = (t0 + 6280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

}

static void work_a_0663295785_1516540902_p_1(char *t0)
{
    char t19[16];
    char t20[16];
    char t31[16];
    char t33[16];
    char t43[16];
    char t45[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t21;
    char *t22;
    int t23;
    int t24;
    int t25;
    char *t26;
    int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t32;
    char *t34;
    char *t35;
    int t36;
    unsigned int t37;
    char *t38;
    int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t44;
    char *t46;
    char *t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    static char *nl0[] = {&&LAB22, &&LAB16, &&LAB17, &&LAB18, &&LAB19, &&LAB20, &&LAB21};

LAB0:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6104);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(65, ng0);
    t3 = (t0 + 6344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)3);
    if (t8 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t8 = *((unsigned char *)t3);
    t9 = (t8 == (unsigned char)0);
    if (t9 == 1)
        goto LAB10;

LAB11:    t2 = (unsigned char)0;

LAB12:    if (t2 != 0)
        goto LAB8;

LAB9:    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)3);
    if (t8 != 0)
        goto LAB13;

LAB14:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 6472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 6408);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    *((unsigned char *)t12) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 4048U);
    t3 = *((char **)t1);
    t1 = (t0 + 6600);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 6472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB10:    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t10 = *((unsigned char *)t4);
    t11 = (t10 == (unsigned char)3);
    t2 = t11;
    goto LAB12;

LAB13:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 2632U);
    t4 = *((char **)t1);
    t9 = *((unsigned char *)t4);
    t1 = (char *)((nl0) + t9);
    goto **((char **)t1);

LAB15:    goto LAB6;

LAB16:    xsi_set_current_line(81, ng0);
    t5 = (t0 + 3752U);
    t6 = *((char **)t5);
    t10 = *((unsigned char *)t6);
    t11 = (t10 == (unsigned char)2);
    if (t11 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t2 = (t15 == 0);
    if (t2 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t16 = (7 - 6);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t20 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 6;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t15 = (0 - 6);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t21;
    t4 = xsi_base_array_concat(t4, t19, t5, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (7U + 1U);
    t2 = (8U != t21);
    if (t2 == 1)
        goto LAB29;

LAB30:    t7 = (t0 + 6600);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t22 = *((char **)t14);
    memcpy(t22, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(90, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 - 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);

LAB27:
LAB24:    goto LAB15;

LAB17:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)2);
    if (t8 != 0)
        goto LAB31;

LAB33:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(97, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t2 = (t15 == 0);
    if (t2 != 0)
        goto LAB34;

LAB36:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t16 = (7 - 6);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t20 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 6;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t15 = (0 - 6);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t21;
    t4 = xsi_base_array_concat(t4, t19, t5, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (7U + 1U);
    t2 = (8U != t21);
    if (t2 == 1)
        goto LAB37;

LAB38:    t7 = (t0 + 6600);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t22 = *((char **)t14);
    memcpy(t22, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 - 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);

LAB35:
LAB32:    goto LAB15;

LAB18:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)2);
    if (t8 != 0)
        goto LAB39;

LAB41:    xsi_set_current_line(109, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(110, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t2 = (t15 == 0);
    if (t2 != 0)
        goto LAB42;

LAB44:    xsi_set_current_line(115, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t16 = (7 - 6);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t20 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 6;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t15 = (0 - 6);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t21;
    t4 = xsi_base_array_concat(t4, t19, t5, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (7U + 1U);
    t2 = (8U != t21);
    if (t2 == 1)
        goto LAB45;

LAB46:    t7 = (t0 + 6600);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t22 = *((char **)t14);
    memcpy(t22, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 - 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);

LAB43:
LAB40:    goto LAB15;

LAB19:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)2);
    if (t8 != 0)
        goto LAB47;

LAB49:    xsi_set_current_line(122, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(123, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t2 = (t15 == 0);
    if (t2 != 0)
        goto LAB50;

LAB52:    xsi_set_current_line(127, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t16 = (7 - 6);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t20 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 6;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t15 = (0 - 6);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t21;
    t4 = xsi_base_array_concat(t4, t19, t5, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (7U + 1U);
    t2 = (8U != t21);
    if (t2 == 1)
        goto LAB53;

LAB54:    t7 = (t0 + 6600);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t22 = *((char **)t14);
    memcpy(t22, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(128, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 - 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);

LAB51:
LAB48:    goto LAB15;

LAB20:    xsi_set_current_line(132, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)2);
    if (t8 != 0)
        goto LAB55;

LAB57:    xsi_set_current_line(136, ng0);
    t1 = (t0 + 6536);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(137, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t2 = (t15 == 0);
    if (t2 != 0)
        goto LAB58;

LAB60:    xsi_set_current_line(154, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t16 = (7 - 6);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t20 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 6;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t15 = (0 - 6);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t21;
    t4 = xsi_base_array_concat(t4, t19, t5, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (7U + 1U);
    t2 = (8U != t21);
    if (t2 == 1)
        goto LAB69;

LAB70:    t7 = (t0 + 6600);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t22 = *((char **)t14);
    memcpy(t22, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(155, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 - 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);

LAB59:
LAB56:    goto LAB15;

LAB21:    xsi_set_current_line(159, ng0);
    t1 = (t0 + 6472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(160, ng0);
    t1 = (t0 + 6408);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

LAB22:    xsi_set_current_line(162, ng0);
    goto LAB15;

LAB23:    xsi_set_current_line(81, ng0);
    t5 = (t0 + 6536);
    t7 = (t5 + 56U);
    t12 = *((char **)t7);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t5);
    goto LAB24;

LAB26:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(86, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t16 = (23 - 23);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t4 = (t0 + 6600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    memcpy(t12, t1, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(87, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB27;

LAB29:    xsi_size_not_matching(8U, t21, 0);
    goto LAB30;

LAB31:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 6536);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB32;

LAB34:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(99, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t16 = (23 - 15);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t4 = (t0 + 6600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    memcpy(t12, t1, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(100, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB35;

LAB37:    xsi_size_not_matching(8U, t21, 0);
    goto LAB38;

LAB39:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 6536);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB40;

LAB42:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(112, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t16 = (23 - 7);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t4 = (t0 + 6600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    memcpy(t12, t1, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(113, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB43;

LAB45:    xsi_size_not_matching(8U, t21, 0);
    goto LAB46;

LAB47:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 6536);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB48;

LAB50:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(125, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB51;

LAB53:    xsi_size_not_matching(8U, t21, 0);
    goto LAB54;

LAB55:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 6536);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(134, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 6600);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t2;
    xsi_driver_first_trans_delta(t1, 7U, 1, 0LL);
    goto LAB56;

LAB58:    xsi_set_current_line(139, ng0);
    t1 = (t0 + 3272U);
    t4 = *((char **)t1);
    t23 = *((int *)t4);
    t8 = (t23 == 3);
    if (t8 != 0)
        goto LAB61;

LAB63:    xsi_set_current_line(149, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 3272U);
    t4 = *((char **)t1);
    t15 = *((int *)t4);
    t23 = (t15 - 2);
    t16 = (t23 * -1);
    t17 = (8U * t16);
    t18 = (0U + t17);
    t1 = (t0 + 6856);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    memcpy(t12, t3, 8U);
    xsi_driver_first_trans_delta(t1, t18, 8U, 0LL);
    xsi_set_current_line(150, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t23 = (t15 + 1);
    t1 = (t0 + 6792);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t23;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(151, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 7;
    xsi_driver_first_trans_fast(t1);

LAB62:    goto LAB59;

LAB61:    xsi_set_current_line(140, ng0);
    t1 = (t0 + 2952U);
    t5 = *((char **)t1);
    t1 = (t0 + 2792U);
    t6 = *((char **)t1);
    t24 = (2 - 2);
    t16 = (t24 * -1);
    t17 = (8U * t16);
    t18 = (0 + t17);
    t1 = (t6 + t18);
    t12 = ((IEEE_P_2592010699) + 4000);
    t13 = (t0 + 10784U);
    t14 = (t20 + 0U);
    t22 = (t14 + 0U);
    *((int *)t22) = 7;
    t22 = (t14 + 4U);
    *((int *)t22) = 0;
    t22 = (t14 + 8U);
    *((int *)t22) = -1;
    t25 = (0 - 7);
    t21 = (t25 * -1);
    t21 = (t21 + 1);
    t22 = (t14 + 12U);
    *((unsigned int *)t22) = t21;
    t7 = xsi_base_array_concat(t7, t19, t12, (char)97, t5, t13, (char)97, t1, t20, (char)101);
    t22 = (t0 + 2792U);
    t26 = *((char **)t22);
    t27 = (1 - 2);
    t21 = (t27 * -1);
    t28 = (8U * t21);
    t29 = (0 + t28);
    t22 = (t26 + t29);
    t32 = ((IEEE_P_2592010699) + 4000);
    t34 = (t33 + 0U);
    t35 = (t34 + 0U);
    *((int *)t35) = 7;
    t35 = (t34 + 4U);
    *((int *)t35) = 0;
    t35 = (t34 + 8U);
    *((int *)t35) = -1;
    t36 = (0 - 7);
    t37 = (t36 * -1);
    t37 = (t37 + 1);
    t35 = (t34 + 12U);
    *((unsigned int *)t35) = t37;
    t30 = xsi_base_array_concat(t30, t31, t32, (char)97, t7, t19, (char)97, t22, t33, (char)101);
    t35 = (t0 + 2792U);
    t38 = *((char **)t35);
    t39 = (0 - 2);
    t37 = (t39 * -1);
    t40 = (8U * t37);
    t41 = (0 + t40);
    t35 = (t38 + t41);
    t44 = ((IEEE_P_2592010699) + 4000);
    t46 = (t45 + 0U);
    t47 = (t46 + 0U);
    *((int *)t47) = 7;
    t47 = (t46 + 4U);
    *((int *)t47) = 0;
    t47 = (t46 + 8U);
    *((int *)t47) = -1;
    t48 = (0 - 7);
    t49 = (t48 * -1);
    t49 = (t49 + 1);
    t47 = (t46 + 12U);
    *((unsigned int *)t47) = t49;
    t42 = xsi_base_array_concat(t42, t43, t44, (char)97, t30, t31, (char)97, t35, t45, (char)101);
    t49 = (8U + 8U);
    t50 = (t49 + 8U);
    t51 = (t50 + 8U);
    t9 = (32U != t51);
    if (t9 == 1)
        goto LAB64;

LAB65:    t47 = (t0 + 6728);
    t52 = (t47 + 56U);
    t53 = *((char **)t52);
    t54 = (t53 + 56U);
    t55 = *((char **)t54);
    memcpy(t55, t42, 32U);
    xsi_driver_first_trans_fast_port(t47);
    xsi_set_current_line(141, ng0);
    t1 = (t0 + 6344);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(142, ng0);
    t1 = (t0 + 6792);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t6) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(143, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)3);
    if (t8 != 0)
        goto LAB66;

LAB68:    xsi_set_current_line(146, ng0);
    t1 = (t0 + 6408);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)6;
    xsi_driver_first_trans_fast(t1);

LAB67:    goto LAB62;

LAB64:    xsi_size_not_matching(32U, t51, 0);
    goto LAB65;

LAB66:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB67;

LAB69:    xsi_size_not_matching(8U, t21, 0);
    goto LAB70;

}

static void work_a_0663295785_1516540902_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(168, ng0);

LAB3:    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 6920);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 6120);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0663295785_1516540902_p_3(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(169, ng0);

LAB3:    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t3 = (7 - 7);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 6984);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 6136);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0663295785_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0663295785_1516540902_p_0,(void *)work_a_0663295785_1516540902_p_1,(void *)work_a_0663295785_1516540902_p_2,(void *)work_a_0663295785_1516540902_p_3};
	xsi_register_didat("work_a_0663295785_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_0663295785_1516540902.didat");
	xsi_register_executes(pe);
}
