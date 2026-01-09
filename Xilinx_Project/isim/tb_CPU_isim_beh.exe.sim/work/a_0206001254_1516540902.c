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
static const char *ng0 = "/home/ise/shared_dir/CPU/RAM2048x36.vhd";



static void work_a_0206001254_1516540902_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
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

LAB0:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 7640);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t21);

LAB2:    t26 = (t0 + 7496);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 7640);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t2 = (t0 + 1352U);
    t6 = *((char **)t2);
    t7 = (10 - 10);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t6 + t9);
    t10 = (t0 + 12222);
    t12 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    t1 = t12;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 2U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t10 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0206001254_1516540902_p_1(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
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
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 7704);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t21);

LAB2:    t26 = (t0 + 7512);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 7704);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t2 = (t0 + 1352U);
    t6 = *((char **)t2);
    t7 = (10 - 10);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t6 + t9);
    t10 = (t0 + 12224);
    t12 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    t1 = t12;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 2U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t10 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0206001254_1516540902_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
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

LAB0:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 7768);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t21);

LAB2:    t26 = (t0 + 7528);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 7768);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t2 = (t0 + 1352U);
    t6 = *((char **)t2);
    t7 = (10 - 10);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t6 + t9);
    t10 = (t0 + 12226);
    t12 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    t1 = t12;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 2U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t10 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0206001254_1516540902_p_3(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
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

LAB0:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 7832);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t21);

LAB2:    t26 = (t0 + 7544);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 7832);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t2 = (t0 + 1352U);
    t6 = *((char **)t2);
    t7 = (10 - 10);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t6 + t9);
    t10 = (t0 + 12228);
    t12 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    t1 = t12;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 2U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t10 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}

static void work_a_0206001254_1516540902_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    unsigned char t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned char t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    unsigned char t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned char t59;
    unsigned int t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;

LAB0:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (10 - 10);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 12230);
    t8 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t8 = 0;

LAB7:    if (t8 != 0)
        goto LAB3;

LAB4:    t18 = (t0 + 1352U);
    t19 = *((char **)t18);
    t20 = (10 - 10);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t18 = (t19 + t22);
    t23 = (t0 + 12232);
    t25 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t25 = 0;

LAB15:    if (t25 != 0)
        goto LAB11;

LAB12:    t35 = (t0 + 1352U);
    t36 = *((char **)t35);
    t37 = (10 - 10);
    t38 = (t37 * 1U);
    t39 = (0 + t38);
    t35 = (t36 + t39);
    t40 = (t0 + 12234);
    t42 = 1;
    if (2U == 2U)
        goto LAB21;

LAB22:    t42 = 0;

LAB23:    if (t42 != 0)
        goto LAB19;

LAB20:    t52 = (t0 + 1352U);
    t53 = *((char **)t52);
    t54 = (10 - 10);
    t55 = (t54 * 1U);
    t56 = (0 + t55);
    t52 = (t53 + t56);
    t57 = (t0 + 12236);
    t59 = 1;
    if (2U == 2U)
        goto LAB29;

LAB30:    t59 = 0;

LAB31:    if (t59 != 0)
        goto LAB27;

LAB28:
LAB2:    t69 = (t0 + 7560);
    *((int *)t69) = 1;

LAB1:    return;
LAB3:    t12 = (t0 + 2632U);
    t13 = *((char **)t12);
    t12 = (t0 + 7896);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t13, 32U);
    xsi_driver_first_trans_fast_port(t12);
    goto LAB2;

LAB5:    t9 = 0;

LAB8:    if (t9 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t10 = (t1 + t9);
    t11 = (t6 + t9);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB6;

LAB10:    t9 = (t9 + 1);
    goto LAB8;

LAB11:    t29 = (t0 + 2792U);
    t30 = *((char **)t29);
    t29 = (t0 + 7896);
    t31 = (t29 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t30, 32U);
    xsi_driver_first_trans_fast_port(t29);
    goto LAB2;

LAB13:    t26 = 0;

LAB16:    if (t26 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t27 = (t18 + t26);
    t28 = (t23 + t26);
    if (*((unsigned char *)t27) != *((unsigned char *)t28))
        goto LAB14;

LAB18:    t26 = (t26 + 1);
    goto LAB16;

LAB19:    t46 = (t0 + 2952U);
    t47 = *((char **)t46);
    t46 = (t0 + 7896);
    t48 = (t46 + 56U);
    t49 = *((char **)t48);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    memcpy(t51, t47, 32U);
    xsi_driver_first_trans_fast_port(t46);
    goto LAB2;

LAB21:    t43 = 0;

LAB24:    if (t43 < 2U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t44 = (t35 + t43);
    t45 = (t40 + t43);
    if (*((unsigned char *)t44) != *((unsigned char *)t45))
        goto LAB22;

LAB26:    t43 = (t43 + 1);
    goto LAB24;

LAB27:    t63 = (t0 + 3112U);
    t64 = *((char **)t63);
    t63 = (t0 + 7896);
    t65 = (t63 + 56U);
    t66 = *((char **)t65);
    t67 = (t66 + 56U);
    t68 = *((char **)t67);
    memcpy(t68, t64, 32U);
    xsi_driver_first_trans_fast_port(t63);
    goto LAB2;

LAB29:    t60 = 0;

LAB32:    if (t60 < 2U)
        goto LAB33;
    else
        goto LAB31;

LAB33:    t61 = (t52 + t60);
    t62 = (t57 + t60);
    if (*((unsigned char *)t61) != *((unsigned char *)t62))
        goto LAB30;

LAB34:    t60 = (t60 + 1);
    goto LAB32;

}


extern void work_a_0206001254_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0206001254_1516540902_p_0,(void *)work_a_0206001254_1516540902_p_1,(void *)work_a_0206001254_1516540902_p_2,(void *)work_a_0206001254_1516540902_p_3,(void *)work_a_0206001254_1516540902_p_4};
	xsi_register_didat("work_a_0206001254_1516540902", "isim/tb_CPU_isim_beh.exe.sim/work/a_0206001254_1516540902.didat");
	xsi_register_executes(pe);
}
