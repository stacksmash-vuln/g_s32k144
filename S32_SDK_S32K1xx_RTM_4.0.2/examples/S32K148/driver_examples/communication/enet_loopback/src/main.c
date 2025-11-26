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

#define EVB

#ifdef EVB
    #define GPIO_PORT   PTE
    #define PCC_CLOCK   PCC_PORTE_CLOCK
    #define LED1        21U
    #define LED2        22U
#else
    #define GPIO_PORT   PTC
    #define PCC_CLOCK   PCC_PORTC_CLOCK
    #define LED1        0U
    #define LED2        1U
#endif

#include "sdk_project_config.h"
#include <interrupt_manager.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t destAddr[6];
    uint8_t srcAddr[6];
    uint16_t length;
    uint8_t payload[1500];
} mac_frame_t;

void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

void copyBuff(uint8_t *dest, uint8_t *src, uint32_t len)
{
    uint32_t i;

    for (i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
}

void rx_callback(uint8_t instance, enet_event_t event, uint8_t ring)
{
    (void)instance;

    if (event == ENET_RX_EVENT)
    {
        enet_buffer_t buff;
        status_t status;

        status = ENET_DRV_ReadFrame(INST_ENET, ring, &buff, NULL);
        if (status == STATUS_SUCCESS)
        {
            mac_frame_t *frame;

            frame = (mac_frame_t *) buff.data;

            /* You can process the payload here */
            (void)frame->payload;

            /* We successfully received a frame -> turn on LED 2 */
            PINS_DRV_ClearPins(GPIO_PORT, (1 << LED1));
            PINS_DRV_SetPins(GPIO_PORT, (1 << LED2));

            ENET_DRV_ProvideRxBuff(INST_ENET, ring, &buff);
        }
    }
}

int main(void)
{
    status_t error;
    /* Configure clocks for PORT */
    error = CLOCK_DRV_Init(&clockMan1_InitConfig0);
    DEV_ASSERT(error == STATUS_SUCCESS);
    /* Output Buffer Enable for ENET MII clock in internal loopback mode */
    SIM->MISCTRL0 |= SIM_MISCTRL0_RMII_CLK_OBE_MASK;

    /* Set pins as GPIO */
    error = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    DEV_ASSERT(error == STATUS_SUCCESS);

    /* Turn off LED 1 and LED 2 */
    PINS_DRV_ClearPins(GPIO_PORT, (1 << LED1));
    PINS_DRV_ClearPins(GPIO_PORT, (1 << LED2));

    /* Disable MPU */
    MPU->CESR = 0x00815200;

    /* Initialize ENET instance */
    ENET_DRV_Init(INST_ENET, &enetState, &enetInitConfig, enet_buffConfigArr, enet_MacAddr);

    enet_buffer_t buff;
    mac_frame_t frame;
    uint8_t i;

    for (i = 0; i < 50U; i++)
    {
        frame.payload[i] = i;
    }

    copyBuff(frame.destAddr, enet_MacAddr, 6U);
    copyBuff(frame.srcAddr, enet_MacAddr, 6U);
    frame.length = 50U;

    buff.data = (uint8_t *)&frame;
    /* Length == 12 bytes MAC addresses + 2 bytes length + 50 bytes payload */
    buff.length = 64U;

    /* Infinite loop:
     *    - Send frames
     */
    while (1)
    {
        /* We are about to send a frame -> turn on LED 1 */
        PINS_DRV_SetPins(GPIO_PORT, (1 << LED1));
        PINS_DRV_ClearPins(GPIO_PORT, (1 << LED2));

        ENET_DRV_SendFrame(INST_ENET, 0U, &buff, NULL);

        delay(70000);
    }
}
