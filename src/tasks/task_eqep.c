/*
 * task_eqep.c
 *
 *  Created on: 2017-4-16
 *      Author: redchenjs
 */
#include <driverlib.h>
#include <device.h>

uint16_t  eqep1_position  = 0;

void task_eqep(void)
{
    if ((uint16_t)EQEP_getPosition(EQEP1_BASE) > 384 && (uint16_t)EQEP_getPosition(EQEP1_BASE) < 32768) {
        EQEP_setPosition(EQEP1_BASE, 384);
    }
    if ((uint16_t)EQEP_getPosition(EQEP1_BASE) > 32768) {
        EQEP_setPosition(EQEP1_BASE, 0);
    }
    eqep1_position  = (uint16_t)EQEP_getPosition(EQEP1_BASE);
}

