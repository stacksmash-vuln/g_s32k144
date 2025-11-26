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
/* ###################################################################
**     Filename    : main.c
**     Project     : timing_pal_s32k144w
**     Processor   : s32k144w
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
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
/* User includes */

/* This define configures led pin and port for use with EVB, to make it run on
 * other boards you need to comment the following line.
 */
#define EVB

#ifdef EVB
    #define LED_0           3U         /* pin PTE3 - RGB LED on DEV-KIT */
    #define LED_1           7U         /* pin PTE7 - RGB LED on DEV-KIT */
    #define LED_2           0U         /* pin PTE0 - RGB LED on DEV-KIT */
    #define LED_GPIO        PTE        /* GPIO PORT E */
#else
    #define LED_GPIO        PTC        /* LED GPIO type */
    #define LED_0           0U         /* pin PTC0 - LED0 on Motherboard */
    #define LED_1           1U         /* pin PTC1 - LED1 on Motherboard */
    #define LED_2           2U         /* pin PTC2 - LED2 on Motherboard */
#endif


/* LPIT channel used */
#define LPIT_CHANNEL        0UL
/* LPTMR channel used */
#define LPTMR_CHANNEL       0UL
/* FTM0 channel used */
#define FTM_CHANNEL         0UL
/* Period in nanosecond unit */
#define PERIOD_BY_NS        1000000000UL /* The period is 1 second */

/*!
 * @brief: The callback function of timing over LPIT channel 0.
 *         The callback function toggles LED_0
 */
void timingLpitInst0_callback(void * userData)
{
    (void)userData;
    /* Toggle LED_BLUE */
    PINS_DRV_TogglePins(LED_GPIO, (1 << LED_0));
}

/*!
 * @brief: The callback function of timing over LPTMR channel 0.
 *         The callback function toggles LED_1
 */
void timingLptmrInst0_callback(void * userData)
{
    (void)userData;
    /* Toggle LED_RED */
    PINS_DRV_TogglePins(LED_GPIO, (1 << LED_1));
}

/*!
 * @brief: The callback function of timing over FTM0 channel 0.
 *         The callback function toggles LED_2
 */
void timingFtmInst0_callback(void * userData)
{
    (void)userData;
    /* Toggle LED_GREEN */
    PINS_DRV_TogglePins(LED_GPIO, (1 << LED_2));
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
    uint64_t lpitResolution;
    uint64_t lptmrResolution;
    uint64_t ftmResolution;
    status_t status;
    /* Initialize clock module */
    status = CLOCK_DRV_Init(&clockMan1_InitConfig0);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Initialize LEDs and Button configuration */
    status = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Initialize TIMING over LPIT */
    status = TIMING_Init(&timingLpitInst0, &timingLpit_InitConfig0);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Initialize TIMING over LPTMR */
    status = TIMING_Init(&timingLptmrInst0, &timingLptmr_InitConfig0);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Initialize TIMING over FTM0 */
    status = TIMING_Init(&timingFtmInst0, &timingFtm_InitConfig0);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Get tick resolution in nanosecond unit for TIMING over LPIT */
    status = TIMING_GetResolution(&timingLpitInst0, TIMER_RESOLUTION_TYPE_NANOSECOND, &lpitResolution);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Get tick resolution in nanosecond unit for TIMING over LPTMR */
    status = TIMING_GetResolution(&timingLptmrInst0, TIMER_RESOLUTION_TYPE_NANOSECOND, &lptmrResolution);
    DEV_ASSERT(status == STATUS_SUCCESS);
    /* Get tick resolution in nanosecond unit for TIMING over FTM */
    status = TIMING_GetResolution(&timingFtmInst0, TIMER_RESOLUTION_TYPE_NANOSECOND, &ftmResolution);
    DEV_ASSERT(status == STATUS_SUCCESS);

    /* Start LPIT channel 0 counting with the period is 1 second,
       the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
    TIMING_StartChannel(&timingLpitInst0, LPIT_CHANNEL, PERIOD_BY_NS/lpitResolution);
    /* Start LPTMR channel 0 counting with the period is 1 second,
       the period in tick = the period in nanosecond / LPTMR tick resolution nanosecond*/
    TIMING_StartChannel(&timingLptmrInst0, LPTMR_CHANNEL, PERIOD_BY_NS/lptmrResolution);
    /* Start FTM channel 0 counting with the period is 1 second,
       the period in tick = the period in nanosecond / FTM tick resolution nanosecond*/
    TIMING_StartChannel(&timingFtmInst0, FTM_CHANNEL, PERIOD_BY_NS/ftmResolution);

    /* Infinite loop */
    for(;;) {
        if(exit_code != 0) {
        break;
        }
    }
    return exit_code;
}

/* END main */
/*!
** @}
*/
