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
static const char *ng0 = "/home/ise/shared_dir/CPU/Imm_decode.vhd";



static void work_a_2575241240_1516540902_p_0(char *t0)
{
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
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4571);
    t4 = xsi_mem_cmp(t1, t2, 3U);
    if (t4 == 1)
        goto LAB3;

LAB9:    t5 = (t0 + 4574);
    t7 = xsi_mem_cmp(t5, t2, 3U);
    if (t7 == 1)
        goto LAB4;

LAB10:    t8 = (t0 + 4577);
    t10 = xsi_mem_cmp(t8, t2, 3U);
    if (t10 == 1)
        goto LAB5;

LAB11:    t11 = (t0 + 4580);
    t13 = xsi_mem_cmp(t11, t2, 3U);
    if (t13 == 1)
        goto LAB6;

LAB12:    t14 = (t0 + 4583);
    t16 = xsi_mem_cmp(t14, t2, 3U);
    if (t16 == 1)
        goto LAB7;

LAB13:
LAB8:    xsi_set_current_line(36, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)1, 32U);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t3);

LAB2:    t1 = (t0 + 2824);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(19, ng0);
    t17 = xsi_get_transient_memory(21U);
    memset(t17, 0, 21U);
    t18 = t17;
    t19 = (t0 + 1032U);
    t20 = *((char **)t19);
    t21 = (31 - 31);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t19 = (t20 + t24);
    t25 = *((unsigned char *)t19);
    memset(t18, t25, 21U);
    t26 = (t0 + 2904);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    memcpy(t30, t17, 21U);
    xsi_driver_first_trans_delta(t26, 0U, 21U, 0LL);
    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 30);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 11U);
    xsi_driver_first_trans_delta(t3, 21U, 11U, 0LL);
    goto LAB2;

LAB4:    xsi_set_current_line(21, ng0);
    t1 = xsi_get_transient_memory(21U);
    memset(t1, 0, 21U);
    t2 = t1;
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t4 = (31 - 31);
    t22 = (t4 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t3 = (t5 + t24);
    t25 = *((unsigned char *)t3);
    memset(t2, t25, 21U);
    t6 = (t0 + 2904);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 21U);
    xsi_driver_first_trans_delta(t6, 0U, 21U, 0LL);
    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 30);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 6U);
    xsi_driver_first_trans_delta(t3, 21U, 6U, 0LL);
    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 11);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 5U);
    xsi_driver_first_trans_delta(t3, 27U, 5U, 0LL);
    goto LAB2;

LAB5:    xsi_set_current_line(24, ng0);
    t1 = xsi_get_transient_memory(20U);
    memset(t1, 0, 20U);
    t2 = t1;
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t4 = (31 - 31);
    t22 = (t4 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t3 = (t5 + t24);
    t25 = *((unsigned char *)t3);
    memset(t2, t25, 20U);
    t6 = (t0 + 2904);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 20U);
    xsi_driver_first_trans_delta(t6, 0U, 20U, 0LL);
    xsi_set_current_line(25, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = (7 - 31);
    t22 = (t4 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t25 = *((unsigned char *)t1);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t25;
    xsi_driver_first_trans_delta(t3, 20U, 1, 0LL);
    xsi_set_current_line(26, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 30);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 6U);
    xsi_driver_first_trans_delta(t3, 21U, 6U, 0LL);
    xsi_set_current_line(27, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 11);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_delta(t3, 27U, 4U, 0LL);
    xsi_set_current_line(28, ng0);
    t1 = (t0 + 2904);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 31U, 1, 0LL);
    goto LAB2;

LAB6:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 31);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 20U);
    xsi_driver_first_trans_delta(t3, 0U, 20U, 0LL);
    xsi_set_current_line(30, ng0);
    t1 = xsi_get_transient_memory(12U);
    memset(t1, 0, 12U);
    t2 = t1;
    memset(t2, (unsigned char)2, 12U);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 12U);
    xsi_driver_first_trans_delta(t3, 20U, 12U, 0LL);
    goto LAB2;

LAB7:    xsi_set_current_line(31, ng0);
    t1 = xsi_get_transient_memory(12U);
    memset(t1, 0, 12U);
    t2 = t1;
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t4 = (31 - 31);
    t22 = (t4 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t3 = (t5 + t24);
    t25 = *((unsigned char *)t3);
    memset(t2, t25, 12U);
    t6 = (t0 + 2904);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 12U);
    xsi_driver_first_trans_delta(t6, 0U, 12U, 0LL);
    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 19);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 8U);
    xsi_driver_first_trans_delta(t3, 12U, 8U, 0LL);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = (20 - 31);
    t22 = (t4 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t25 = *((unsigned char *)t1);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t25;
    xsi_driver_first_trans_delta(t3, 20U, 1, 0LL);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t22 = (31 - 30);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t1 = (t2 + t24);
    t3 = (t0 + 2904);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 10U);
    xsi_driver_first_trans_delta(t3, 21U, 10U, 0LL);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2904);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 31U, 1, 0LL);
    goto LAB2;

LAB14:;
}


extern void work_a_2575241240_1516540902_init()
{
	static char *pe[] = {(void *)work_a_2575241240_1516540902_p_0};
	xsi_register_didat("work_a_2575241240_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_2575241240_1516540902.didat");
	xsi_register_executes(pe);
}
