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
static const char *ng0 = "/home/ise/Shared_dir/vhd/ALU.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;

int ieee_p_1242562249_sub_17802405650254020620_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_1987757588013599599_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_3044623114557194624_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3525738511873186323_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3525738511873258197_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_8645934262925994370_1035706684(char *, char *, char *, char *, int );
char *ieee_p_2592010699_sub_16439767405979520975_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_16439989832805790689_503743352(char *, char *, char *, char *, char *, char *);


static void work_a_0832606739_1516540902_p_0(char *t0)
{
    char t23[16];
    char t40[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    int t19;
    char *t20;
    char *t21;
    int t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned char t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    unsigned char t42;

LAB0:    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 5931);
    t4 = xsi_mem_cmp(t1, t2, 3U);
    if (t4 == 1)
        goto LAB3;

LAB11:    t5 = (t0 + 5934);
    t7 = xsi_mem_cmp(t5, t2, 3U);
    if (t7 == 1)
        goto LAB4;

LAB12:    t8 = (t0 + 5937);
    t10 = xsi_mem_cmp(t8, t2, 3U);
    if (t10 == 1)
        goto LAB5;

LAB13:    t11 = (t0 + 5940);
    t13 = xsi_mem_cmp(t11, t2, 3U);
    if (t13 == 1)
        goto LAB6;

LAB14:    t14 = (t0 + 5943);
    t16 = xsi_mem_cmp(t14, t2, 3U);
    if (t16 == 1)
        goto LAB7;

LAB15:    t17 = (t0 + 5946);
    t19 = xsi_mem_cmp(t17, t2, 3U);
    if (t19 == 1)
        goto LAB8;

LAB16:    t20 = (t0 + 5949);
    t22 = xsi_mem_cmp(t20, t2, 3U);
    if (t22 == 1)
        goto LAB9;

LAB17:
LAB10:    xsi_set_current_line(32, ng0);

LAB2:    t1 = (t0 + 3800);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(20, ng0);
    t24 = (t0 + 1032U);
    t25 = *((char **)t24);
    t24 = (t0 + 5744U);
    t26 = (t0 + 1192U);
    t27 = *((char **)t26);
    t26 = (t0 + 5760U);
    t28 = ieee_p_1242562249_sub_3525738511873186323_1035706684(IEEE_P_1242562249, t23, t25, t24, t27, t26);
    t29 = (t0 + 3912);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memcpy(t33, t28, 32U);
    xsi_driver_first_trans_fast(t29);
    goto LAB2;

LAB4:    xsi_set_current_line(21, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5760U);
    t6 = ieee_p_1242562249_sub_3525738511873258197_1035706684(IEEE_P_1242562249, t23, t2, t1, t5, t3);
    t8 = (t0 + 3912);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    memcpy(t14, t6, 32U);
    xsi_driver_first_trans_fast(t8);
    goto LAB2;

LAB5:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5760U);
    t6 = ieee_p_2592010699_sub_16439989832805790689_503743352(IEEE_P_2592010699, t23, t2, t1, t5, t3);
    t8 = (t23 + 12U);
    t34 = *((unsigned int *)t8);
    t35 = (1U * t34);
    t36 = (32U != t35);
    if (t36 == 1)
        goto LAB19;

LAB20:    t9 = (t0 + 3912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB6:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5760U);
    t6 = ieee_p_2592010699_sub_16439767405979520975_503743352(IEEE_P_2592010699, t23, t2, t1, t5, t3);
    t8 = (t23 + 12U);
    t34 = *((unsigned int *)t8);
    t35 = (1U * t34);
    t36 = (32U != t35);
    if (t36 == 1)
        goto LAB21;

LAB22:    t9 = (t0 + 3912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB7:    xsi_set_current_line(25, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5760U);
    t36 = ieee_p_1242562249_sub_3044623114557194624_1035706684(IEEE_P_1242562249, t2, t1, t5, t3);
    if (t36 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(28, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t3 = (t0 + 3912);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t3);

LAB24:    goto LAB2;

LAB8:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t34 = (31 - 4);
    t35 = (t34 * 1U);
    t37 = (0 + t35);
    t3 = (t5 + t37);
    t6 = (t40 + 0U);
    t8 = (t6 + 0U);
    *((int *)t8) = 4;
    t8 = (t6 + 4U);
    *((int *)t8) = 0;
    t8 = (t6 + 8U);
    *((int *)t8) = -1;
    t4 = (0 - 4);
    t38 = (t4 * -1);
    t38 = (t38 + 1);
    t8 = (t6 + 12U);
    *((unsigned int *)t8) = t38;
    t7 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t3, t40);
    t8 = ieee_p_1242562249_sub_1987757588013599599_1035706684(IEEE_P_1242562249, t23, t2, t1, t7);
    t9 = (t0 + 3912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB9:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5744U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t34 = (31 - 4);
    t35 = (t34 * 1U);
    t37 = (0 + t35);
    t3 = (t5 + t37);
    t6 = (t40 + 0U);
    t8 = (t6 + 0U);
    *((int *)t8) = 4;
    t8 = (t6 + 4U);
    *((int *)t8) = 0;
    t8 = (t6 + 8U);
    *((int *)t8) = -1;
    t4 = (0 - 4);
    t38 = (t4 * -1);
    t38 = (t38 + 1);
    t8 = (t6 + 12U);
    *((unsigned int *)t8) = t38;
    t7 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t3, t40);
    t8 = ieee_p_1242562249_sub_8645934262925994370_1035706684(IEEE_P_1242562249, t23, t2, t1, t7);
    t9 = (t0 + 3912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB18:;
LAB19:    xsi_size_not_matching(32U, t35, 0);
    goto LAB20;

LAB21:    xsi_size_not_matching(32U, t35, 0);
    goto LAB22;

LAB23:    xsi_set_current_line(26, ng0);
    t6 = xsi_get_transient_memory(31U);
    memset(t6, 0, 31U);
    t8 = t6;
    if (-1 == 1)
        goto LAB26;

LAB27:    t34 = 1;

LAB28:    t4 = (t34 - 1);
    t35 = (t4 * 1);
    t37 = (1U * t35);
    t9 = (t8 + t37);
    t7 = (1 - 31);
    t38 = (t7 * -1);
    t38 = (t38 + 1);
    t39 = (1U * t38);
    memset(t9, (unsigned char)2, t39);
    t12 = ((IEEE_P_2592010699) + 4000);
    t14 = (t40 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 1;
    t15 = (t14 + 4U);
    *((int *)t15) = 31;
    t15 = (t14 + 8U);
    *((int *)t15) = 1;
    t10 = (31 - 1);
    t41 = (t10 * 1);
    t41 = (t41 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t41;
    t11 = xsi_base_array_concat(t11, t23, t12, (char)97, t6, t40, (char)99, (unsigned char)3, (char)101);
    t41 = (31U + 1U);
    t42 = (32U != t41);
    if (t42 == 1)
        goto LAB29;

LAB30:    t15 = (t0 + 3912);
    t17 = (t15 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t11, 32U);
    xsi_driver_first_trans_fast(t15);
    goto LAB24;

LAB26:    t34 = 31;
    goto LAB28;

LAB29:    xsi_size_not_matching(32U, t41, 0);
    goto LAB30;

}

static void work_a_0832606739_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned char t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
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

LAB0:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    if (-1 == -1)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    t5 = (t4 - 31);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (t3 + t7);
    t9 = (0 - 31);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t11 = (1U * t10);
    memset(t8, (unsigned char)2, t11);
    t12 = 1;
    if (32U == 32U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    if (t12 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 3976);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t21);

LAB2:    t26 = (t0 + 3816);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 3976);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t16);
    goto LAB2;

LAB5:    t4 = 31;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 32U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t1 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0832606739_1516540902_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(36, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4040);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3832);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0832606739_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0832606739_1516540902_p_0,(void *)work_a_0832606739_1516540902_p_1,(void *)work_a_0832606739_1516540902_p_2};
	xsi_register_didat("work_a_0832606739_1516540902", "isim/tb_Bootloader_isim_beh.exe.sim/work/a_0832606739_1516540902.didat");
	xsi_register_executes(pe);
}
