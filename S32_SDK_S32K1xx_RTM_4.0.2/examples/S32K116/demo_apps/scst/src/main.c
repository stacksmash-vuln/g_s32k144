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
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define LED_PORT    PORTD
#define GPIO_PORT   PTD
#define LED1        15U
#define LED2        16U

#define ACCUMULATED_SIGNATURE_ID0_18 0x598714C0UL

/* Linker defined variables used to copy initialized data from ROM to RAM */
extern uint32_t __SCST_DATA_ROM[];
extern uint32_t __SCST_DATA_SIZE[];
extern uint32_t __scst_data_start__[];

volatile int32_t exit_code = 0;

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - main()
*/
int main(void)
{
  m0_scst_uint32_t result;
  status_t error;
  /* Configure clocks for PORT */
  error = CLOCK_DRV_Init(&clockMan1_InitConfig0);
  DEV_ASSERT(error == STATUS_SUCCESS);
  /* Set pins as GPIO */
  error = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
  DEV_ASSERT(error == STATUS_SUCCESS);

  /* Set Output value LED0 & LED1 */
  PINS_DRV_ClearPins(GPIO_PORT, 1 << LED1);
  PINS_DRV_ClearPins(GPIO_PORT, 1 << LED2);

  /* Copy sCST initialized data from ROM to RAM */
  memcpy(__scst_data_start__, __SCST_DATA_ROM, (uint32_t)__SCST_DATA_SIZE);
  /* Execute all tests */
  result = m0_scst_execute_core_tests(0U,18U);

  if(result == M0_SCST_WRONG_RANGE)
  {
    /* If the test range was incorrectly set, stop the execution flow */
    while(1);
  }
  else
  {
    /* All tests passed */
    if (m0_scst_accumulated_signature == ACCUMULATED_SIGNATURE_ID0_18)
    {
       /* Turn on GREEN LED to signal that the test was successful */
       PINS_DRV_ClearPins(GPIO_PORT, 1 << LED2);
       PINS_DRV_SetPins(GPIO_PORT, 1 << LED1);
    }

    else
    {
      /* Turn on RED LED to signal error */
      PINS_DRV_SetPins(GPIO_PORT, 1 << LED2);
      PINS_DRV_ClearPins(GPIO_PORT, 1 << LED1);
    }
  }
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/

