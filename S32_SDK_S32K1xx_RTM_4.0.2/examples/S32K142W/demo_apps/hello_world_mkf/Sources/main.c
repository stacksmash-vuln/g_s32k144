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

#include "clock_manager.h"
#include "pins_driver.h"

#define EVB

#ifdef EVB
    #define LED1            0U
    #define LED2            7U
    #define LED_PORT        PORTE
    #define PCC_CLOCK       PORTE_CLK
    #define GPIO_PORT       PTE
#else
    #define LED1            0U
    #define LED2            1U
    #define LED_PORT        PORTC
    #define PCC_CLOCK       PORTC_CLK
    #define GPIO_PORT       PTC
#endif

void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

int main(void)
{
  /* Configure clocks for PORT */
  CLOCK_DRV_SetModuleClock(PCC_CLOCK, NULL);
  /* Set pins as GPIO */
  PINS_DRV_SetMuxModeSel(LED_PORT, LED1, PORT_MUX_AS_GPIO);
  PINS_DRV_SetMuxModeSel(LED_PORT, LED2, PORT_MUX_AS_GPIO);

  /* Output direction for LED0 & LED1 */
  PINS_DRV_SetPinsDirection(GPIO_PORT, ((1 << LED1) | (1 << LED2)));

  /* Set Output value LED0 & LED1 */
  PINS_DRV_SetPins(GPIO_PORT, 1 << LED1);
  PINS_DRV_ClearPins(GPIO_PORT, 1 << LED2);

  for (;;)
  {
      /* Insert a small delay to make the blinking visible */
      delay(720000);

      /* Toggle output value LED0 & LED1 */
      PINS_DRV_TogglePins(GPIO_PORT, ((1 << LED1) | (1 << LED2)));
  }
}
