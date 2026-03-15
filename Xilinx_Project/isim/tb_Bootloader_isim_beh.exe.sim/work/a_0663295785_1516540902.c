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
static const char *ng0 = "/home/ise/shared_dir/CPU/vhd/periferie/SPI_flash.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_17802405650254020620_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0663295785_1516540902_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;

LAB0:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 7048);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 4072U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = (t5 == 3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t5 = *((int *)t3);
    t11 = (t5 + 1);
    t1 = (t0 + 7176);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t11;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(59, ng0);
    t1 = (t0 + 7240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 7176);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(56, ng0);
    t1 = (t0 + 7240);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

}

static void work_a_0663295785_1516540902_p_1(char *t0)
{
    char t24[16];
    char t26[16];
    char t31[16];
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
    int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    char *t25;
    char *t27;
    char *t28;
    int t29;
    unsigned int t30;
    char *t32;
    int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    unsigned char t38;
    static char *nl0[] = {&&LAB17, &&LAB18, &&LAB19, &&LAB20, &&LAB22, &&LAB23, &&LAB21, &&LAB24};

LAB0:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 7064);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(67, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 4552U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(68, ng0);
    t3 = (t0 + 7304);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 7368);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(72, ng0);
    t1 = (t0 + 7560);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 12806);
    t4 = (t0 + 7624);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 7688);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 7752);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 12838);
    t4 = (t0 + 7816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    goto LAB6;

LAB8:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 7752);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 4232U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 < 3);
    if (t2 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 7560);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB11:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 4392U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 < 1);
    if (t2 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 7688);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB14:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB10:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 4232U);
    t4 = *((char **)t1);
    t12 = *((int *)t4);
    t13 = (t12 + 1);
    t1 = (t0 + 7880);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t13;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB13:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t12 = *((int *)t4);
    t13 = (t12 + 1);
    t1 = (t0 + 7944);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t13;
    xsi_driver_first_trans_fast(t1);
    goto LAB14;

LAB16:    goto LAB6;

LAB17:    xsi_set_current_line(92, ng0);
    t4 = (t0 + 1832U);
    t7 = *((char **)t4);
    t5 = *((unsigned char *)t7);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB25;

LAB27:
LAB26:    goto LAB16;

LAB18:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 4712U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB33;

LAB35:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB36;

LAB38:    xsi_set_current_line(115, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t15 = (31 - 30);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t3 + t17);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t26 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 30;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t11 = (0 - 30);
    t18 = (t11 * -1);
    t18 = (t18 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t18;
    t4 = xsi_base_array_concat(t4, t24, t7, (char)97, t1, t26, (char)99, (unsigned char)2, (char)101);
    t18 = (31U + 1U);
    t2 = (32U != t18);
    if (t2 == 1)
        goto LAB61;

LAB62:    t9 = (t0 + 7816);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    memcpy(t27, t4, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 - 1);
    t1 = (t0 + 7496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);

LAB37:
LAB34:    goto LAB16;

LAB19:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 4712U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB63;

LAB65:    xsi_set_current_line(122, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(123, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB66;

LAB68:    xsi_set_current_line(137, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t15 = (31 - 30);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t3 + t17);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t26 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 30;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t11 = (0 - 30);
    t18 = (t11 * -1);
    t18 = (t18 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t18;
    t4 = xsi_base_array_concat(t4, t24, t7, (char)97, t1, t26, (char)99, (unsigned char)2, (char)101);
    t18 = (31U + 1U);
    t2 = (32U != t18);
    if (t2 == 1)
        goto LAB94;

LAB95:    t9 = (t0 + 7816);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    memcpy(t27, t4, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(138, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 - 1);
    t1 = (t0 + 7496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);

LAB67:
LAB64:    goto LAB16;

LAB20:    xsi_set_current_line(142, ng0);
    t1 = (t0 + 4712U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB96;

LAB98:    xsi_set_current_line(146, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(147, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB99;

LAB101:    xsi_set_current_line(157, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t15 = (31 - 30);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t3 + t17);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t26 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 30;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t11 = (0 - 30);
    t18 = (t11 * -1);
    t18 = (t18 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t18;
    t4 = xsi_base_array_concat(t4, t24, t7, (char)97, t1, t26, (char)99, (unsigned char)2, (char)101);
    t18 = (31U + 1U);
    t2 = (32U != t18);
    if (t2 == 1)
        goto LAB111;

LAB112:    t9 = (t0 + 7816);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    memcpy(t27, t4, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(158, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 - 1);
    t1 = (t0 + 7496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);

LAB100:
LAB97:    goto LAB16;

LAB21:    xsi_set_current_line(162, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB113;

LAB115:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)7;
    xsi_driver_first_trans_fast(t1);

LAB114:    goto LAB16;

LAB22:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 4712U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB119;

LAB121:    xsi_set_current_line(173, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(174, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB122;

LAB124:    xsi_set_current_line(177, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t15 = (31 - 30);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t3 + t17);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t26 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 30;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t11 = (0 - 30);
    t18 = (t11 * -1);
    t18 = (t18 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t18;
    t4 = xsi_base_array_concat(t4, t24, t7, (char)97, t1, t26, (char)99, (unsigned char)2, (char)101);
    t18 = (31U + 1U);
    t2 = (32U != t18);
    if (t2 == 1)
        goto LAB125;

LAB126:    t9 = (t0 + 7816);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    memcpy(t27, t4, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(178, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 - 1);
    t1 = (t0 + 7496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);

LAB123:
LAB120:    goto LAB16;

LAB23:    xsi_set_current_line(182, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB127;

LAB129:    xsi_set_current_line(190, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)7;
    xsi_driver_first_trans_fast(t1);

LAB128:    goto LAB16;

LAB24:    xsi_set_current_line(193, ng0);
    t1 = (t0 + 7368);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(194, ng0);
    t1 = (t0 + 7560);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(195, ng0);
    t1 = (t0 + 7880);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(196, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB25:    xsi_set_current_line(93, ng0);
    t4 = (t0 + 7304);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    *((unsigned char *)t14) = (unsigned char)1;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(94, ng0);
    t1 = (t0 + 5008U);
    t3 = *((char **)t1);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 12464U);
    t11 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t4, t1);
    t12 = (t11 - 0);
    t15 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 4, 1, t11);
    t16 = (8U * t15);
    t17 = (0 + t16);
    t7 = (t3 + t17);
    t8 = xsi_get_transient_memory(24U);
    memset(t8, 0, 24U);
    t9 = t8;
    if (-1 == 1)
        goto LAB28;

LAB29:    t18 = 0;

LAB30:    t13 = (t18 - 0);
    t19 = (t13 * 1);
    t20 = (1U * t19);
    t10 = (t9 + t20);
    t21 = (0 - 23);
    t22 = (t21 * -1);
    t22 = (t22 + 1);
    t23 = (1U * t22);
    memset(t10, (unsigned char)2, t23);
    t25 = ((IEEE_P_2592010699) + 4000);
    t27 = (t26 + 0U);
    t28 = (t27 + 0U);
    *((int *)t28) = 7;
    t28 = (t27 + 4U);
    *((int *)t28) = 0;
    t28 = (t27 + 8U);
    *((int *)t28) = -1;
    t29 = (0 - 7);
    t30 = (t29 * -1);
    t30 = (t30 + 1);
    t28 = (t27 + 12U);
    *((unsigned int *)t28) = t30;
    t28 = (t31 + 0U);
    t32 = (t28 + 0U);
    *((int *)t32) = 0;
    t32 = (t28 + 4U);
    *((int *)t32) = 23;
    t32 = (t28 + 8U);
    *((int *)t32) = 1;
    t33 = (23 - 0);
    t30 = (t33 * 1);
    t30 = (t30 + 1);
    t32 = (t28 + 12U);
    *((unsigned int *)t32) = t30;
    t14 = xsi_base_array_concat(t14, t24, t25, (char)97, t7, t26, (char)97, t8, t31, (char)101);
    t30 = (8U + 24U);
    t2 = (32U != t30);
    if (t2 == 1)
        goto LAB31;

LAB32:    t32 = (t0 + 7816);
    t34 = (t32 + 56U);
    t35 = *((char **)t34);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    memcpy(t37, t14, 32U);
    xsi_driver_first_trans_fast(t32);
    xsi_set_current_line(95, ng0);
    t1 = (t0 + 7368);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 7432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(97, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB26;

LAB28:    t18 = 23;
    goto LAB30;

LAB31:    xsi_size_not_matching(32U, t30, 0);
    goto LAB32;

LAB33:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 7432);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB34;

LAB36:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 12870);
    t5 = 1;
    if (3U == 3U)
        goto LAB42;

LAB43:    t5 = 0;

LAB44:    if (t5 != 0)
        goto LAB39;

LAB41:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 12873);
    t2 = 1;
    if (3U == 3U)
        goto LAB50;

LAB51:    t2 = 0;

LAB52:    if (t2 != 0)
        goto LAB48;

LAB49:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(111, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t4 = t1;
    if (-1 == 1)
        goto LAB56;

LAB57:    t15 = 0;

LAB58:    t11 = (t15 - 0);
    t16 = (t11 * 1);
    t17 = (1U * t16);
    t7 = (t4 + t17);
    t12 = (0 - 7);
    t18 = (t12 * -1);
    t18 = (t18 + 1);
    t19 = (1U * t18);
    memset(t7, (unsigned char)2, t19);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t0 + 12432U);
    t14 = (t26 + 0U);
    t25 = (t14 + 0U);
    *((int *)t25) = 0;
    t25 = (t14 + 4U);
    *((int *)t25) = 7;
    t25 = (t14 + 8U);
    *((int *)t25) = 1;
    t13 = (7 - 0);
    t20 = (t13 * 1);
    t20 = (t20 + 1);
    t25 = (t14 + 12U);
    *((unsigned int *)t25) = t20;
    t8 = xsi_base_array_concat(t8, t24, t9, (char)97, t3, t10, (char)97, t1, t26, (char)101);
    t20 = (24U + 8U);
    t2 = (32U != t20);
    if (t2 == 1)
        goto LAB59;

LAB60:    t25 = (t0 + 7816);
    t27 = (t25 + 56U);
    t28 = *((char **)t27);
    t32 = (t28 + 56U);
    t34 = *((char **)t32);
    memcpy(t34, t8, 32U);
    xsi_driver_first_trans_fast(t25);
    xsi_set_current_line(112, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 23;
    xsi_driver_first_trans_fast(t1);

LAB40:    goto LAB37;

LAB39:    xsi_set_current_line(105, ng0);
    t10 = (t0 + 7304);
    t14 = (t10 + 56U);
    t25 = *((char **)t14);
    t27 = (t25 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = (unsigned char)7;
    xsi_driver_first_trans_fast(t10);
    goto LAB40;

LAB42:    t15 = 0;

LAB45:    if (t15 < 3U)
        goto LAB46;
    else
        goto LAB44;

LAB46:    t8 = (t4 + t15);
    t9 = (t1 + t15);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB43;

LAB47:    t15 = (t15 + 1);
    goto LAB45;

LAB48:    xsi_set_current_line(107, ng0);
    t9 = (t0 + 7304);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    *((unsigned char *)t27) = (unsigned char)3;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(108, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 7;
    xsi_driver_first_trans_fast(t1);
    goto LAB40;

LAB50:    t15 = 0;

LAB53:    if (t15 < 3U)
        goto LAB54;
    else
        goto LAB52;

LAB54:    t7 = (t3 + t15);
    t8 = (t1 + t15);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB51;

LAB55:    t15 = (t15 + 1);
    goto LAB53;

LAB56:    t15 = 7;
    goto LAB58;

LAB59:    xsi_size_not_matching(32U, t20, 0);
    goto LAB60;

LAB61:    xsi_size_not_matching(32U, t18, 0);
    goto LAB62;

LAB63:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 7432);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB64;

LAB66:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 12876);
    t5 = 1;
    if (3U == 3U)
        goto LAB72;

LAB73:    t5 = 0;

LAB74:    if (t5 != 0)
        goto LAB69;

LAB71:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 12879);
    t2 = 1;
    if (3U == 3U)
        goto LAB80;

LAB81:    t2 = 0;

LAB82:    if (t2 != 0)
        goto LAB78;

LAB79:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 12882);
    t2 = 1;
    if (3U == 3U)
        goto LAB88;

LAB89:    t2 = 0;

LAB90:    if (t2 != 0)
        goto LAB86;

LAB87:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)7;
    xsi_driver_first_trans_fast(t1);

LAB70:    goto LAB67;

LAB69:    xsi_set_current_line(125, ng0);
    t10 = (t0 + 7304);
    t14 = (t10 + 56U);
    t25 = *((char **)t14);
    t27 = (t25 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = (unsigned char)3;
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(126, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 31;
    xsi_driver_first_trans_fast(t1);
    goto LAB70;

LAB72:    t15 = 0;

LAB75:    if (t15 < 3U)
        goto LAB76;
    else
        goto LAB74;

LAB76:    t8 = (t4 + t15);
    t9 = (t1 + t15);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB73;

LAB77:    t15 = (t15 + 1);
    goto LAB75;

LAB78:    xsi_set_current_line(128, ng0);
    t9 = (t0 + 7304);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    *((unsigned char *)t27) = (unsigned char)5;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(129, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 7816);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 31;
    xsi_driver_first_trans_fast(t1);
    goto LAB70;

LAB80:    t15 = 0;

LAB83:    if (t15 < 3U)
        goto LAB84;
    else
        goto LAB82;

LAB84:    t7 = (t3 + t15);
    t8 = (t1 + t15);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB81;

LAB85:    t15 = (t15 + 1);
    goto LAB83;

LAB86:    xsi_set_current_line(132, ng0);
    t9 = (t0 + 7304);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    *((unsigned char *)t27) = (unsigned char)7;
    xsi_driver_first_trans_fast(t9);
    goto LAB70;

LAB88:    t15 = 0;

LAB91:    if (t15 < 3U)
        goto LAB92;
    else
        goto LAB90;

LAB92:    t7 = (t3 + t15);
    t8 = (t1 + t15);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB89;

LAB93:    t15 = (t15 + 1);
    goto LAB91;

LAB94:    xsi_size_not_matching(32U, t18, 0);
    goto LAB95;

LAB96:    xsi_set_current_line(143, ng0);
    t1 = (t0 + 7432);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(144, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 7816);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_delta(t1, 31U, 1, 0LL);
    goto LAB97;

LAB99:    xsi_set_current_line(148, ng0);
    t1 = (t0 + 3752U);
    t4 = *((char **)t1);
    t1 = (t0 + 7624);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 32U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(149, ng0);
    t1 = (t0 + 7688);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(150, ng0);
    t1 = (t0 + 7944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(151, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 12885);
    t2 = 1;
    if (3U == 3U)
        goto LAB105;

LAB106:    t2 = 0;

LAB107:    if (t2 != 0)
        goto LAB102;

LAB104:    xsi_set_current_line(154, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)6;
    xsi_driver_first_trans_fast(t1);

LAB103:    goto LAB100;

LAB102:    xsi_set_current_line(152, ng0);
    t9 = (t0 + 7304);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    t25 = (t14 + 56U);
    t27 = *((char **)t25);
    *((unsigned char *)t27) = (unsigned char)7;
    xsi_driver_first_trans_fast(t9);
    goto LAB103;

LAB105:    t15 = 0;

LAB108:    if (t15 < 3U)
        goto LAB109;
    else
        goto LAB107;

LAB109:    t7 = (t3 + t15);
    t8 = (t1 + t15);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB106;

LAB110:    t15 = (t15 + 1);
    goto LAB108;

LAB111:    xsi_size_not_matching(32U, t18, 0);
    goto LAB112;

LAB113:    xsi_set_current_line(163, ng0);
    t1 = (t0 + 1992U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t38 = (t6 == (unsigned char)3);
    if (t38 != 0)
        goto LAB116;

LAB118:
LAB117:    goto LAB114;

LAB116:    xsi_set_current_line(164, ng0);
    t1 = (t0 + 7304);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(165, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 31;
    xsi_driver_first_trans_fast(t1);
    goto LAB117;

LAB119:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 7432);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB120;

LAB122:    xsi_set_current_line(175, ng0);
    t1 = (t0 + 7304);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    goto LAB123;

LAB125:    xsi_size_not_matching(32U, t18, 0);
    goto LAB126;

LAB127:    xsi_set_current_line(183, ng0);
    t1 = (t0 + 2152U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t38 = (t6 == (unsigned char)3);
    if (t38 != 0)
        goto LAB130;

LAB132:
LAB131:    goto LAB128;

LAB130:    xsi_set_current_line(184, ng0);
    t1 = (t0 + 1512U);
    t7 = *((char **)t1);
    t1 = (t0 + 7816);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    memcpy(t14, t7, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(185, ng0);
    t1 = (t0 + 7752);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(186, ng0);
    t1 = (t0 + 7496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 31;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(187, ng0);
    t1 = (t0 + 7304);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB131;

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

LAB0:    xsi_set_current_line(202, ng0);

LAB3:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 8008);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 7080);
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

LAB0:    xsi_set_current_line(203, ng0);

LAB3:    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 8072);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast_port(t8);

LAB2:    t13 = (t0 + 7096);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0663295785_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0663295785_1516540902_p_0,(void *)work_a_0663295785_1516540902_p_1,(void *)work_a_0663295785_1516540902_p_2,(void *)work_a_0663295785_1516540902_p_3};
	xsi_register_didat("work_a_0663295785_1516540902", "isim/tb_Bootloader_isim_beh.exe.sim/work/a_0663295785_1516540902.didat");
	xsi_register_executes(pe);
}
