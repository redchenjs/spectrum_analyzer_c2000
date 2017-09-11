/*
 * task_fft.c
 *
 *  Created on: 2017-7-7
 *      Author: redchenjs
 */
#include <driverlib.h>
#include <device.h>

#include <vcu2_types.h>
#include <vcu2_fft.h>
//*****************************************************************************
// defines
//*****************************************************************************
#define NSTAGES     10
#define NSAMPLES    1<<NSTAGES
//*****************************************************************************
// globals
//*****************************************************************************
extern int16_t adcAResultsSig[];

#pragma DATA_SECTION(adcAResultsFFT,"buffer2")
int16_t adcAResultsFFT[2*NSAMPLES];

CFFT_Obj CFFT;
CFFT_Handle handleCFFT;

void task_fft(void)
{
    // Run the Forward FFT followed by an unpacking routine
    CFFT.run(handleCFFT);
    CFFT_unpack(handleCFFT);
}

void task_fft_init(void)
{
    // Initialize CFFT object
    CFFT.pInBuffer  = adcAResultsSig;
    CFFT.pOutBuffer = adcAResultsFFT;
    CFFT.init = (void (*)(void *))CFFT_init1024Pt;
    CFFT.run  = (void (*)(void *))CFFT_run1024Pt;

    // Initialize the handle
    handleCFFT = &CFFT;

    // Calling the init() will setup the twiddle factor table
    CFFT.init(handleCFFT);
}
