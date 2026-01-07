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
static const char *ng0 = "/home/ise/shared_dir/CPU/ALU.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;

unsigned char ieee_p_1242562249_sub_3044623114557194624_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3525738511873186323_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3525738511873258197_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_16439767405979520975_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_16439989832805790689_503743352(char *, char *, char *, char *, char *, char *);


static void work_a_0832606739_1516540902_p_0(char *t0)
{
    char t17[16];
    char t34[16];
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
    unsigned int t28;
    unsigned int t29;
    unsigned char t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t35;
    unsigned char t36;

LAB0:    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 5627);
    t4 = xsi_mem_cmp(t1, t2, 3U);
    if (t4 == 1)
        goto LAB3;

LAB9:    t5 = (t0 + 5630);
    t7 = xsi_mem_cmp(t5, t2, 3U);
    if (t7 == 1)
        goto LAB4;

LAB10:    t8 = (t0 + 5633);
    t10 = xsi_mem_cmp(t8, t2, 3U);
    if (t10 == 1)
        goto LAB5;

LAB11:    t11 = (t0 + 5636);
    t13 = xsi_mem_cmp(t11, t2, 3U);
    if (t13 == 1)
        goto LAB6;

LAB12:    t14 = (t0 + 5639);
    t16 = xsi_mem_cmp(t14, t2, 3U);
    if (t16 == 1)
        goto LAB7;

LAB13:
LAB8:    xsi_set_current_line(30, ng0);

LAB2:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    if (-1 == -1)
        goto LAB30;

LAB31:    t28 = 0;

LAB32:    t4 = (t28 - 31);
    t29 = (t4 * -1);
    t31 = (1U * t29);
    t5 = (t3 + t31);
    t7 = (0 - 31);
    t32 = (t7 * -1);
    t32 = (t32 + 1);
    t33 = (1U * t32);
    memset(t5, (unsigned char)2, t33);
    t30 = 1;
    if (32U == 32U)
        goto LAB33;

LAB34:    t30 = 0;

LAB35:    if (t30 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 3712);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB28:    t1 = (t0 + 3552);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(20, ng0);
    t18 = (t0 + 1032U);
    t19 = *((char **)t18);
    t18 = (t0 + 5440U);
    t20 = (t0 + 1192U);
    t21 = *((char **)t20);
    t20 = (t0 + 5456U);
    t22 = ieee_p_1242562249_sub_3525738511873186323_1035706684(IEEE_P_1242562249, t17, t19, t18, t21, t20);
    t23 = (t0 + 3648);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t22, 32U);
    xsi_driver_first_trans_fast(t23);
    goto LAB2;

LAB4:    xsi_set_current_line(21, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5440U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5456U);
    t6 = ieee_p_1242562249_sub_3525738511873258197_1035706684(IEEE_P_1242562249, t17, t2, t1, t5, t3);
    t8 = (t0 + 3648);
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
    t1 = (t0 + 5440U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5456U);
    t6 = ieee_p_2592010699_sub_16439989832805790689_503743352(IEEE_P_2592010699, t17, t2, t1, t5, t3);
    t8 = (t17 + 12U);
    t28 = *((unsigned int *)t8);
    t29 = (1U * t28);
    t30 = (32U != t29);
    if (t30 == 1)
        goto LAB15;

LAB16:    t9 = (t0 + 3648);
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
    t1 = (t0 + 5440U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5456U);
    t6 = ieee_p_2592010699_sub_16439767405979520975_503743352(IEEE_P_2592010699, t17, t2, t1, t5, t3);
    t8 = (t17 + 12U);
    t28 = *((unsigned int *)t8);
    t29 = (1U * t28);
    t30 = (32U != t29);
    if (t30 == 1)
        goto LAB17;

LAB18:    t9 = (t0 + 3648);
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
    t1 = (t0 + 5440U);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5456U);
    t30 = ieee_p_1242562249_sub_3044623114557194624_1035706684(IEEE_P_1242562249, t2, t1, t5, t3);
    if (t30 != 0)
        goto LAB19;

LAB21:    xsi_set_current_line(28, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t3 = (t0 + 3648);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t3);

LAB20:    goto LAB2;

LAB14:;
LAB15:    xsi_size_not_matching(32U, t29, 0);
    goto LAB16;

LAB17:    xsi_size_not_matching(32U, t29, 0);
    goto LAB18;

LAB19:    xsi_set_current_line(26, ng0);
    t6 = xsi_get_transient_memory(31U);
    memset(t6, 0, 31U);
    t8 = t6;
    if (-1 == 1)
        goto LAB22;

LAB23:    t28 = 1;

LAB24:    t4 = (t28 - 1);
    t29 = (t4 * 1);
    t31 = (1U * t29);
    t9 = (t8 + t31);
    t7 = (1 - 31);
    t32 = (t7 * -1);
    t32 = (t32 + 1);
    t33 = (1U * t32);
    memset(t9, (unsigned char)2, t33);
    t12 = ((IEEE_P_2592010699) + 4000);
    t14 = (t34 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 1;
    t15 = (t14 + 4U);
    *((int *)t15) = 31;
    t15 = (t14 + 8U);
    *((int *)t15) = 1;
    t10 = (31 - 1);
    t35 = (t10 * 1);
    t35 = (t35 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t35;
    t11 = xsi_base_array_concat(t11, t17, t12, (char)97, t6, t34, (char)99, (unsigned char)3, (char)101);
    t35 = (31U + 1U);
    t36 = (32U != t35);
    if (t36 == 1)
        goto LAB25;

LAB26:    t15 = (t0 + 3648);
    t18 = (t15 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t11, 32U);
    xsi_driver_first_trans_fast(t15);
    goto LAB20;

LAB22:    t28 = 31;
    goto LAB24;

LAB25:    xsi_size_not_matching(32U, t35, 0);
    goto LAB26;

LAB27:    xsi_set_current_line(33, ng0);
    t9 = (t0 + 3712);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t9);
    goto LAB28;

LAB30:    t28 = 31;
    goto LAB32;

LAB33:    t35 = 0;

LAB36:    if (t35 < 32U)
        goto LAB37;
    else
        goto LAB35;

LAB37:    t6 = (t2 + t35);
    t8 = (t1 + t35);
    if (*((unsigned char *)t6) != *((unsigned char *)t8))
        goto LAB34;

LAB38:    t35 = (t35 + 1);
    goto LAB36;

}

static void work_a_0832606739_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(38, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 3776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3568);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0832606739_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0832606739_1516540902_p_0,(void *)work_a_0832606739_1516540902_p_1};
	xsi_register_didat("work_a_0832606739_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_0832606739_1516540902.didat");
	xsi_register_executes(pe);
}
