/*
 * task_adc.c
 *
 *  Created on: 2017-6-27
 *      Author: redchenjs
 */
#include <driverlib.h>
#include <device.h>

#include <stdlib.h>

#include <inc/system/fonts.h>
#include <inc/driver/ssd1351.h>

extern uint16_t eqep1_position;

extern int16_t adcAResultsFFT[];

void task_disp(void)
{
    int i;
    int point = 0;

    ssd1351_display_num(80, 0, eqep1_position, 3, FONT_1616, Yellow, Blue);

    for (i=0; i<80; i++) {
        point = abs(adcAResultsFFT[i+eqep1_position]);
        if (point > 128) {
            point = 128;
        }
        ssd1351_draw_column(i, 0, 128-point, Black, White);
    }
    for (i=80; i<128; i++) {
        point = abs(adcAResultsFFT[i+eqep1_position]);
        if (point > 128) {
            point = 128;
        }
        ssd1351_draw_column(i, 16, 128-point-16, Black, White);
    }
}
