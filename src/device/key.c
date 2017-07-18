/*
 * key.c
 *
 *  Created on: 2017-7-6
 *      Author: redchenjs
 */
#include "driverlib.h"
#include "device.h"
//
// Function Prototypes
//
interrupt void xint1_isr(void);

void key_init(void)
{
    Interrupt_register(INT_XINT1, &xint1_isr);

    Interrupt_enable(INT_XINT1);

    GPIO_setDirectionMode(99, GPIO_DIR_MODE_IN);          // input
    // XINT1 Qual using 6 samples
    GPIO_setQualificationMode(99, GPIO_QUAL_6SAMPLE);
    GPIO_setQualificationPeriod(99, 510);

    GPIO_setInterruptPin(99, GPIO_INT_XINT1);

    // Falling edge interrupt
    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);

    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
}

//
// xint1_isr - External Interrupt 1 ISR
//
interrupt void xint1_isr(void)
{
    EQEP_setPosition(EQEP1_BASE, 0);
    //
    // Acknowledge this interrupt to get more from group 1
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
