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
#include "device_registers.h"
#include "clock_manager.h"
//#include "pins_driver.h"

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define LED_PORT 	PORTD
	#define GPIO_PORT	PTD
	#define LED1		15U
	#define LED2		16U
#else
	#define LED_PORT 	PORTC
	#define GPIO_PORT	PTC
	#define LED1		0U
	#define LED2		1U
#endif

void delay(volatile int cycles);

int main(void)
{
	  PCC->PCCn[PCC_PORTD_INDEX] = 0xC0000000;
	  LED_PORT->PCR[LED1] |= PORT_PCR_MUX(1);
	  LED_PORT->PCR[LED2] |= PORT_PCR_MUX(1);
	  GPIO_PORT->PDDR |= (1 << LED1)|(1 << LED2);
	  GPIO_PORT->PSOR |= (1 << LED2);
	  GPIO_PORT->PCOR |= (1 << LED1);

	  for (;;)
	  {
		  GPIO_PORT->PTOR |= (1 << LED1)|(1 << LED2);
	      /* Insert a small delay to make the blinking visible */
	      delay(720000);
	  }
  
}

void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}
