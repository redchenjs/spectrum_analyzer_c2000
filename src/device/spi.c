#include "driverlib.h"
#include "device.h"
/*
 * spi.c
 *
 *  Created on: 2017-4-16
 *      Author: redchenjs
 */

void spi_init(void)
{
    SPI_disableModule(SPIA_BASE);

    GPIO_setMasterCore(58, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_58_SPISIMOA);
    GPIO_setDirectionMode(58, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(58, GPIO_PIN_TYPE_STD);

    GPIO_setMasterCore(60, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_60_SPICLKA);
    GPIO_setDirectionMode(60, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(60, GPIO_PIN_TYPE_STD);

    GPIO_setMasterCore(61, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_61_SPISTEA);
    GPIO_setDirectionMode(61, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(61, GPIO_PIN_TYPE_STD);

    SPI_enableTriWire(SPIA_BASE);

    SPI_enableHighSpeedMode(SPIA_BASE);

    SPI_setConfig(SPIA_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA1,
               SPI_MODE_MASTER, DEVICE_LSPCLK_FREQ, 8);

    SPI_setEmulationMode(SPIA_BASE, SPI_EMULATION_STOP_AFTER_TRANSMIT);

    SPI_enableModule(SPIA_BASE);
}
