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
    #define LED1_RED    (1 << 21U)
    #define LED2_GREEN  (1 << 22U)
    #define LED3_BLUE   (1 << 23U)
#else
    #define GPIO_PORT   PTC
    #define PCC_CLOCK   PCC_PORTC_CLOCK
    #define LED1_RED    (1 << 0U)
    #define LED2_GREEN  (1 << 1U)
    #define LED3_BLUE   (1 << 2U)
#endif

#define PTB_PHY_INT (1 << 20U)
#define PTC_BTN0    (1 << 12U)
#define PTC_BTN1    (1 << 13U)


#define PHY_CONFIG1                  (18U)
#define PHY_CONFIG1_FWDREM           (0x0004U)
#define PHY_EXTENDED_CTRL_ADDR       (17U)
#define PHY_EXTENDED_CTRL_CONFIG_EN  (0x0004U)
#define PHY_COM_CONFIG               (27U)
#define PHY_COM_CONFIG_WAKE          (0x0040U)

#include "sdk_project_config.h"
#include "interrupt_manager.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Port C IRQ handler */
void portc_Handler(void)
{
    uint32_t flags;
    static bool loopback;
    static phy_role_t phyRole = PHY_ROLE_MASTER;
    uint32_t delay = 1000000U;

    do
    {
        /* wait some time to allow capturing pushing multiple buttons at once */
        delay--;
    }
    while(delay != 0);

    flags = PINS_DRV_GetPortIntFlag(PORTC);
    if ((flags & (PTC_BTN1 | PTC_BTN0)) == (PTC_BTN1 | PTC_BTN0))
    {
        /* both buttons pressed - change master/slave settings */
        PHY_SetRole(0, phyRole);
        phyRole = (phyRole == PHY_ROLE_MASTER) ? (PHY_ROLE_SLAVE) : (PHY_ROLE_MASTER);
    }
    else
    {
        if ((flags & PTC_BTN1) != 0U)
        {
            PHY_Sleep(0);
        }
        if ((flags & PTC_BTN0) != 0U)
        {
            if (loopback)
            {
                PHY_SetLoopback(0, PHY_LOOPBACK_NONE);
            }
            else
            {
                PHY_SetLoopback(0, PHY_LOOPBACK_INTERNAL);
            }
            loopback = !loopback;
        }
    }
    /* Clear interrupt flag */
    PINS_DRV_ClearPortIntFlagCmd(PORTC);
}

/* Sleep request event callback */
void sleep_request(uint8_t phy)
{
    if (phy == 0U)
    {
        PINS_DRV_ClearPins(GPIO_PORT, LED1_RED);
        PINS_DRV_ClearPins(GPIO_PORT, LED2_GREEN);
        PINS_DRV_SetPins(GPIO_PORT, LED3_BLUE);
    }
}

/* Link up callback */
void link_up(uint8_t phy)
{
    if (phy == 0U)
    {
        PINS_DRV_ClearPins(GPIO_PORT, LED1_RED);
        PINS_DRV_SetPins(GPIO_PORT, LED2_GREEN);
        PINS_DRV_ClearPins(GPIO_PORT, LED3_BLUE);
    }
}

/* Link down callback  */
void link_down(uint8_t phy)
{
    if (phy == 0U)
    {
        PINS_DRV_SetPins(GPIO_PORT, LED1_RED);
        PINS_DRV_ClearPins(GPIO_PORT, LED2_GREEN);
        PINS_DRV_ClearPins(GPIO_PORT, LED3_BLUE);
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
    status_t error;
    /* Configure clocks for PORT */
    error = CLOCK_DRV_Init(&clockMan1_InitConfig0);
    DEV_ASSERT(error == STATUS_SUCCESS);
    /* Output Buffer Enable for ENET MII clock in internal loopback mode */
    SIM->MISCTRL0 |= SIM_MISCTRL0_RMII_CLK_OBE_MASK;
    /* Initialize pins
     *    -   See PinSettings component for more info
     */
    error = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    DEV_ASSERT(error == STATUS_SUCCESS);

    /* Turn off LEDs */
    PINS_DRV_ClearPins(GPIO_PORT, LED1_RED);
    PINS_DRV_ClearPins(GPIO_PORT, LED2_GREEN);
    PINS_DRV_ClearPins(GPIO_PORT, LED3_BLUE);

    /* Disable MPU */
    MPU->CESR = 0x00815200;

    /* Initialize ENET instance */
    ENET_DRV_Init(INST_ENET, &enetState, &enetInitConfig, enet_buffConfigArr, enet_MacAddr);
    ENET_DRV_EnableMDIO(INST_ENET, false);

    PINS_DRV_SetPins(GPIO_PORT, LED1_RED);

    PHY_FrameworkInit(phyConfig, phyDrivers);
    PHY_Init(0);

    INT_SYS_InstallHandler(PORTC_IRQn, portc_Handler, (isr_t *)0);
    INT_SYS_EnableIRQ(PORTC_IRQn);

    while (1)
    {
        PHY_MainFunction(0);
        OSIF_TimeDelay(10);
    }
}
