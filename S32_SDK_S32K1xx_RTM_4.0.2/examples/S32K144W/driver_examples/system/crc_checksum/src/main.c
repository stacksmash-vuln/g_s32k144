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
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "sdk_project_config.h"

volatile int exit_code = 0;

#include <stdint.h>

extern const uint32_t CRC_data[];

/* Define CRC data size */
#define CRC_DATA_SIZE           (548U)
/* Define result CRC calculator with CCITT 16 bits standard */
#define RESULT_CRC_16_CCITT     (0xb532U)

#define EVB

#ifdef EVB
    #define LED1_PIN        7U
    #define LED0_PIN        0U
    #define LED0_PORT       PTE
    #define LED1_PORT       PTE
    #define SW_PORT         PTD
    #define SW_PIN          3U
#else
    #define LED1_PIN        1U
    #define LED0_PIN        0U
    #define LED0_PORT       PTC
    #define LED1_PORT       PTC
    #define SW_PORT         PTB
    #define SW_PIN          12U
#endif

/*!
  \brief The main function for the project.
*/
int main(void)
{
    /* Write your local variable definition here */
    volatile uint32_t result;

    /* Initializes clocks for CRC instances used */
    CLOCK_DRV_Init(&clockMan1_InitConfig0);

    /* Initialize pins */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* CCITT 16 bits standard */
    /*
        .crcWidth = CRC_BITS_16,
        .seed = 0xFFFFU,
        .polynomial = 0x1021U,
        .writeTranspose = CRC_TRANSPOSE_NONE,
        .readTranspose = CRC_TRANSPOSE_NONE,
        .complementChecksum = false
    */
    /* result = 0xb532 */
    /* Initialize CRC module */
    CRC_DRV_Init(INST_CRC, &crc_Cfg0);

    /* Infinite loop */
    for(;;) {

        if (PINS_DRV_ReadPins(SW_PORT) & (1U << SW_PIN))
        {
            /* Calculate CRC value for CRC_data with configuration of 16 bit wide result */
            CRC_DRV_WriteData(INST_CRC, (const uint8_t*)CRC_data, CRC_DATA_SIZE);
            result = CRC_DRV_GetCrcResult(INST_CRC);
            /* If result of CRC calculator is correct */
            if (result == RESULT_CRC_16_CCITT)
            {
                /* Turn on LED 0 */
                PINS_DRV_TogglePins(LED0_PORT, (1 << LED0_PIN));
            }
            else
            {
                /* Turn on LED 1 */
                PINS_DRV_TogglePins(LED1_PORT, (1 << LED1_PIN));
            }
            break;
        }
    }

  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
}
