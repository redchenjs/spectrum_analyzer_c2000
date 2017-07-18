/*
 * user.c
 *
 *  Created on: 2017-4-16
 *      Author: redchenjs
 */
#include <inc/tasks/task_eqep.h>
#include <inc/tasks/task_adc.h>
#include <inc/tasks/task_fft.h>
#include <inc/tasks/task_disp.h>

void user_loop(void)
{
    task_eqep();    // 任务一：QEP解码
    task_adc();     // 任务二：ADC采样
    task_fft();     // 任务三：FFT变换
    task_disp();    // 任务四：更新显示
}

void user_init(void)
{
    task_fft_init();     // FFT旋转因子表初始化
}
