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
static const char *ng0 = "/home/ise/shared_dir/CPU/tb/tb_Bootloader.vhd";
extern char *IEEE_P_2592010699;
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_17802405650254020620_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_13554554585326073636_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1543185115_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);

LAB4:    if ((unsigned char)1 != 0)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3752);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB6:;
LAB8:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 4592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3752);
    xsi_process_wait(t2, t8);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    goto LAB4;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}

static void work_a_1543185115_2372691052_p_1(char *t0)
{
    char t25[16];
    char t26[16];
    char t27[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int t8;
    int t9;
    int t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned char t22;
    int64 t23;
    unsigned char t24;
    char *t28;

LAB0:    t1 = (t0 + 4192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(80, ng0);
    t7 = (1000 * 1000LL);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 4656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(82, ng0);
    t7 = (1000 * 1000LL);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t7);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 7992);
    *((int *)t2) = 0;
    t3 = (t0 + 7996);
    *((int *)t3) = 25;
    t8 = 0;
    t9 = 25;

LAB12:    if (t8 <= t9)
        goto LAB13;

LAB15:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB13:    xsi_set_current_line(86, ng0);
    t4 = (t0 + 2968U);
    t5 = *((char **)t4);
    t4 = (t0 + 7992);
    t10 = *((int *)t4);
    t11 = (t10 - 0);
    t12 = (t11 * 1);
    t13 = (8U * t12);
    t14 = (0 + t13);
    t6 = (t5 + t14);
    t15 = (t0 + 4720);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t6, 8U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 4784);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t7);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB14:    t2 = (t0 + 7992);
    t8 = *((int *)t2);
    t3 = (t0 + 7996);
    t9 = *((int *)t3);
    if (t8 == t9)
        goto LAB15;

LAB62:    t10 = (t8 + 1);
    t8 = t10;
    t4 = (t0 + 7992);
    *((int *)t4) = t8;
    goto LAB12;

LAB16:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 8000);
    *((int *)t2) = 0;
    t3 = (t0 + 8004);
    *((int *)t3) = 7;
    t10 = 0;
    t11 = 7;

LAB20:    if (t10 <= t11)
        goto LAB21;

LAB23:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 4784);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(99, ng0);

LAB31:    t2 = (t0 + 4512);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB21:    xsi_set_current_line(92, ng0);
    t4 = (t0 + 2152U);
    t5 = *((char **)t4);
    t4 = (t0 + 8000);
    t20 = *((int *)t4);
    t21 = (t20 - 7);
    t12 = (t21 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t4));
    t13 = (1U * t12);
    t14 = (0 + t13);
    t6 = (t5 + t14);
    t22 = *((unsigned char *)t6);
    t15 = (t0 + 4784);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t22;
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t7);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB22:    t2 = (t0 + 8000);
    t10 = *((int *)t2);
    t3 = (t0 + 8004);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB23;

LAB28:    t20 = (t10 + 1);
    t10 = t20;
    t4 = (t0 + 8000);
    *((int *)t4) = t10;
    goto LAB20;

LAB24:    goto LAB22;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB29:    t4 = (t0 + 4512);
    *((int *)t4) = 0;
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t23 = (t7 / 2);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t23);

LAB35:    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB30:    t3 = (t0 + 1952U);
    t22 = ieee_p_2592010699_sub_13554554585326073636_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t22 == 1)
        goto LAB29;
    else
        goto LAB31;

LAB32:    goto LAB30;

LAB33:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t22 = *((unsigned char *)t3);
    t24 = (t22 == (unsigned char)2);
    if (t24 != 0)
        goto LAB37;

LAB39:
LAB38:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 8016);
    t4 = ((STD_STANDARD) + 384);
    t5 = (t0 + 2152U);
    t6 = *((char **)t5);
    t5 = (t0 + 7656U);
    t10 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t6, t5);
    t15 = xsi_int_to_mem(t10);
    t16 = xsi_string_variable_get_image(t25, t4, t15);
    t18 = ((STD_STANDARD) + 984);
    t19 = (t27 + 0U);
    t28 = (t19 + 0U);
    *((int *)t28) = 1;
    t28 = (t19 + 4U);
    *((int *)t28) = 8;
    t28 = (t19 + 8U);
    *((int *)t28) = 1;
    t11 = (8 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t28 = (t19 + 12U);
    *((unsigned int *)t28) = t12;
    t17 = xsi_base_array_concat(t17, t26, t18, (char)97, t2, t27, (char)97, t16, t25, (char)101);
    t28 = (t25 + 12U);
    t12 = *((unsigned int *)t28);
    t13 = (8U + t12);
    xsi_report(t17, t13, 0);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 8024);
    t4 = ((STD_STANDARD) + 384);
    t5 = (t0 + 2312U);
    t6 = *((char **)t5);
    t5 = (t0 + 7672U);
    t10 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t6, t5);
    t15 = xsi_int_to_mem(t10);
    t16 = xsi_string_variable_get_image(t25, t4, t15);
    t18 = ((STD_STANDARD) + 984);
    t19 = (t27 + 0U);
    t28 = (t19 + 0U);
    *((int *)t28) = 1;
    t28 = (t19 + 4U);
    *((int *)t28) = 8;
    t28 = (t19 + 8U);
    *((int *)t28) = 1;
    t11 = (8 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t28 = (t19 + 12U);
    *((unsigned int *)t28) = t12;
    t17 = xsi_base_array_concat(t17, t26, t18, (char)97, t2, t27, (char)97, t16, t25, (char)101);
    t28 = (t25 + 12U);
    t12 = *((unsigned int *)t28);
    t13 = (8U + t12);
    xsi_report(t17, t13, 0);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 2152U);
    t3 = *((char **)t2);
    t2 = (t0 + 2312U);
    t4 = *((char **)t2);
    t22 = 1;
    if (8U == 8U)
        goto LAB56;

LAB57:    t22 = 0;

LAB58:    if (t22 != 0)
        goto LAB53;

LAB55:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 8042);
    xsi_report(t2, 12U, 0);

LAB54:    goto LAB14;

LAB34:    goto LAB33;

LAB36:    goto LAB34;

LAB37:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 8008);
    *((int *)t2) = 0;
    t4 = (t0 + 8012);
    *((int *)t4) = 7;
    t10 = 0;
    t11 = 7;

LAB40:    if (t10 <= t11)
        goto LAB41;

LAB43:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t2 = (t0 + 4000);
    xsi_process_wait(t2, t7);

LAB51:    *((char **)t1) = &&LAB52;
    goto LAB1;

LAB41:    xsi_set_current_line(104, ng0);
    t5 = (t0 + 2848U);
    t6 = *((char **)t5);
    t7 = *((int64 *)t6);
    t5 = (t0 + 4000);
    xsi_process_wait(t5, t7);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB42:    t2 = (t0 + 8008);
    t10 = *((int *)t2);
    t3 = (t0 + 8012);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB43;

LAB48:    t20 = (t10 + 1);
    t10 = t20;
    t4 = (t0 + 8008);
    *((int *)t4) = t10;
    goto LAB40;

LAB44:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t22 = *((unsigned char *)t3);
    t2 = (t0 + 8008);
    t20 = *((int *)t2);
    t21 = (t20 - 7);
    t12 = (t21 * -1);
    t13 = (1 * t12);
    t14 = (0U + t13);
    t4 = (t0 + 4848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t15 = (t6 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t22;
    xsi_driver_first_trans_delta(t4, t14, 1, 0LL);
    goto LAB42;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

LAB49:    goto LAB38;

LAB50:    goto LAB49;

LAB52:    goto LAB50;

LAB53:    xsi_set_current_line(115, ng0);
    t6 = (t0 + 8032);
    xsi_report(t6, 10U, 0);
    goto LAB54;

LAB56:    t12 = 0;

LAB59:    if (t12 < 8U)
        goto LAB60;
    else
        goto LAB58;

LAB60:    t2 = (t3 + t12);
    t5 = (t4 + t12);
    if (*((unsigned char *)t2) != *((unsigned char *)t5))
        goto LAB57;

LAB61:    t12 = (t12 + 1);
    goto LAB59;

}


extern void work_a_1543185115_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1543185115_2372691052_p_0,(void *)work_a_1543185115_2372691052_p_1};
	xsi_register_didat("work_a_1543185115_2372691052", "isim/tb_Bootloader_isim_beh.exe.sim/work/a_1543185115_2372691052.didat");
	xsi_register_executes(pe);
}
