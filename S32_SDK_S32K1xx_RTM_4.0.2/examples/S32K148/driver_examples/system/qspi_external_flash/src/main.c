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
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "sdk_project_config.h"
#include "osif.h"
#include <stdint.h>
#include <stdbool.h>

volatile int exit_code = 0;

#define LED_PIN     22U
#define LED_PORT    PTE

#define BUFFER_SIZE 1024
#define SECTOR_ADDR 0x2000U
uint8_t txBuffer[BUFFER_SIZE];
uint8_t rxBuffer[BUFFER_SIZE] = {0x00};
volatile status_t status;
flash_mx25l6433f_state_t flashState;


/* Check if data in Tx and Rx buffers matches */
void checkBuffers(uint8_t *tx, uint8_t *rx, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < size; i++)
    {
        DEV_ASSERT(rx[i] == tx[i]);
    }
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your local variable definition here */
    uint32_t count;

    /* Initialize clock module */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize txBuffer */
    for (count = 0; count < BUFFER_SIZE / 2; count++)
    {
        txBuffer[count] = (uint8_t)count;
    }
    for (count = BUFFER_SIZE / 2; count < BUFFER_SIZE; count++)
    {
        txBuffer[count] = (0xFFU - (uint8_t)count);
    }

    /* Initialize DMA */
    EDMA_DRV_Init(&dmaController_State, &dmaController_InitConfig, edmaChnStateArray, edmaChnConfigArray, EDMA_CONFIGURED_CHANNELS_COUNT);

    /* Initialize qspi driver */
    status = QSPI_DRV_Init(INST_QUADSPI_CONFIG_1, &qspi1_Config0, &qspiState);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Initialize external flash driver */
    status = FLASH_MX25L6433F_DRV_Init(INST_QUADSPI_CONFIG_1, &flash_mx25l6433f_Config0, &flashState);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Erase one sector */
    status = FLASH_MX25L6433F_DRV_Erase4K(INST_QUADSPI_CONFIG_1, SECTOR_ADDR);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Wait for erase to finish */
    while ((status = FLASH_MX25L6433F_DRV_GetStatus(INST_QUADSPI_CONFIG_1)) == STATUS_BUSY) { }
    DEV_ASSERT(status == STATUS_SUCCESS);

    for (count = 0; count < 4; count++)
    {
        /* Program 256 bytes at a time, this is the maximum allowed by the external flash device */
        status = FLASH_MX25L6433F_DRV_Program(INST_QUADSPI_CONFIG_1, SECTOR_ADDR + (256 * count), txBuffer + (256 * count), 256);
        DEV_ASSERT(status == STATUS_SUCCESS);

        /* Wait for program to finish */
        while ((status = FLASH_MX25L6433F_DRV_GetStatus(INST_QUADSPI_CONFIG_1)) == STATUS_BUSY) { }
        DEV_ASSERT(status == STATUS_SUCCESS);
    }

    /* Read all bytes */
    status = FLASH_MX25L6433F_DRV_Read(INST_QUADSPI_CONFIG_1, SECTOR_ADDR, rxBuffer, BUFFER_SIZE);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Wait for program to finish */
    while ((status = FLASH_MX25L6433F_DRV_GetStatus(INST_QUADSPI_CONFIG_1)) == STATUS_BUSY) { }
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Check received data */
    checkBuffers(txBuffer, rxBuffer, BUFFER_SIZE);

    /* If we get here it means the test has passed */
    PINS_DRV_SetPins(LED_PORT, (1 << LED_PIN));

    for (;;)
    {
      if (exit_code != 0)
        break;
    }
    return exit_code;
}

/* END main */
