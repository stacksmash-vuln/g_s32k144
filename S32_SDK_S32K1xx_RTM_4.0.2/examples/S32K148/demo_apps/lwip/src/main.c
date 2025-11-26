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

#include "sdk_project_config.h"
#include <interrupt_manager.h>
#include <stdint.h>
#include <stdbool.h>

volatile int exit_code = 0;

extern void start_example(void);

int main(void)
{

    /* Write your code here */
    status_t ret = STATUS_ERROR;

    /* Initialize and configure clocks */
    ret = CLOCK_SYS_Init(g_clockManConfigsArr, (uint8_t)CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, (uint8_t)CLOCK_MANAGER_CALLBACK_CNT);
    DEV_ASSERT(STATUS_SUCCESS == ret);
    ret = CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
    DEV_ASSERT(STATUS_SUCCESS == ret);

    /* Initialize pins */
    ret = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    DEV_ASSERT(STATUS_SUCCESS == ret);

    if (STATUS_SUCCESS == ret)
    {
      start_example();
    }

    for(;;) {
      if(exit_code != 0) {
        break;
      }
    }
    return exit_code;

}
