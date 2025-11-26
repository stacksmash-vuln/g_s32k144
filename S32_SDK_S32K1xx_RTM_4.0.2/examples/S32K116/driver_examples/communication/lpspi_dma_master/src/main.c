/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software. The production use license in
 * Section 2.3 is expressly granted for this software.
 */
/*!
** @file main.c
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "sdk_project_config.h"

volatile int exit_code = 0;

#include <stdint.h>
#include <stdbool.h>

/* Definition of the data transfer size */
#define BUFFER_SIZE         (100u)
#define TIMEOUT             (200u)
#define GREEN_LED           (1<<15U)    /* GREEN_LED  PTD[15] */
#define GPIO_LED            PTD

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void)
{
    /* Write your local variable definition here */

    uint8_t masterDataSend[BUFFER_SIZE];
    uint8_t slaveDataSend[BUFFER_SIZE];
    uint8_t masterDataReceive[BUFFER_SIZE];
    uint16_t i;
    uint8_t frame_sent = 1;

    /* Initialize and configure clocks
     *     -   see clock manager component for details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *    -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    PINS_DRV_ClearPins(GPIO_LED, GREEN_LED);

    /* Initialize DMA */
    EDMA_DRV_Init(&dmaController_State, &dmaController_InitConfig, edmaChnStateArray, edmaChnConfigArray, EDMA_CONFIGURED_CHANNELS_COUNT);

    /* Initialize the data buffer */
    for (i = 0u; i < BUFFER_SIZE; i++)
    {
        slaveDataSend[i] = BUFFER_SIZE - i - 1u;
    }

    /* Initialize the data buffer */
    for (i = 0u; i < BUFFER_SIZE; i++)
    {
        masterDataSend[i] = i;
    }

    /* SPI master configuration: clock speed: 500 kHz, 8 bits/frame, MSB first */
    LPSPI_DRV_MasterInit(INST_LPSPI_1, &lpspi_1State, &lpspi_0_MasterConfig0);

    /* Set delay for transmission */
    LPSPI_DRV_MasterSetDelay(INST_LPSPI_1, 1u, 1u, 1u);

    LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_1, masterDataSend, masterDataReceive, BUFFER_SIZE, TIMEOUT);

    for(i=0;i<BUFFER_SIZE;i++)
    {
    	if(masterDataReceive[i]  != slaveDataSend[i])
    	{
    		frame_sent = 0;
    		break;
    	}
    }
    if(frame_sent == 0)
    {
    	PINS_DRV_ClearPins(GPIO_LED, GREEN_LED);
    }
    else
    {
    	PINS_DRV_SetPins(GPIO_LED, GREEN_LED);
    }

    /* Write your code here */
    /* For example: for(;;) { } */

    for(;;) 
    {
        if(exit_code != 0) 
        {
            break;
        }
    }
    return exit_code;
}

/* END main */
/*!
 ** @}
 */
