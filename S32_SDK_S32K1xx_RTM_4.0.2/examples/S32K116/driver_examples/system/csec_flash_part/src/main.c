/*
 * Copyright 2018 NXP
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


/* Including needed modules to compile this module/procedure */
#include "sdk_project_config.h"
#include "flash_driver.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;

#include <stdint.h>
#include <stdbool.h>

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
    #define LED_PORT       PTD
    #define LED_ERROR      16U
    #define LED_OK         15U
#else
    #define LED_PORT       PTC
    #define LED_ERROR      1U
    #define LED_OK         2U
#endif

/* Flash configuration */
const flash_user_config_t Flash1_InitConfig0 = {
    .PFlashBase  = 0x00000000U,                     /* Base address of Program Flash block */
    .PFlashSize  = 0x00020000U,                     /* Size of Program Flash block         */
    .DFlashBase  = 0x10000000U,                     /* Base address of Data Flash block    */
    .EERAMBase   = 0x14000000U,                     /* Base address of FlexRAM block */
    /* If using callback, any code reachable from this function must not be placed in a Flash block targeted for a program/erase operation.*/
    .CallBack    = NULL_CALLBACK
};

status_t initFlashForCsecOperation(void)
{
	flash_ssd_config_t flashSSDConfig;
	status_t status = STATUS_SUCCESS;

	FLASH_DRV_Init(&Flash1_InitConfig0, &flashSSDConfig);

	if (flashSSDConfig.EEESize == 0)
	{
		uint32_t address;
		uint32_t size;

#if (FEATURE_FLS_HAS_PROGRAM_PHRASE_CMD == 1u)
		uint8_t unsecure_key[FTFx_PHRASE_SIZE] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFEu, 0xFFu, 0xFFu, 0xFFu};
#else   /* FEATURE_FLASH_HAS_PROGRAM_LONGWORD_CMD */
		uint8_t unsecure_key[FTFx_LONGWORD_SIZE] = {0xFEu, 0xFFu, 0xFFu, 0xFFu};
#endif  /* FEATURE_FLS_HAS_PROGRAM_PHRASE_CMD */

		/* First, erase all Flash blocks to ensure the IFR region is blank
		 * before partitioning FlexNVM and FlexRAM */
		status = FLASH_DRV_EraseAllBlock(&flashSSDConfig);
		if (status != STATUS_SUCCESS)
		{
			return status;
		}
		/* Reprogram secure byte in Flash configuration field */
#if (FEATURE_FLS_HAS_PROGRAM_PHRASE_CMD == 1u)
		address = 0x408u;
		size = FTFx_PHRASE_SIZE;
#else   /* FEATURE_FLASH_HAS_PROGRAM_LONGWORD_CMD == 1u */
		address = 0x40Cu;
		size = FTFx_LONGWORD_SIZE;
#endif /* FEATURE_FLS_HAS_PROGRAM_PHRASE_CMD */
		status = FLASH_DRV_Program(&flashSSDConfig, address, size, unsecure_key);
		if (status != STATUS_SUCCESS)
		{
			return status;
		}

		status = FLASH_DRV_DEFlashPartition(&flashSSDConfig, 0x3, 0x3, 0x3, false, true);
		if (status != STATUS_SUCCESS)
		{
			return status;
		}
	}
	else
	{
		PINS_DRV_SetPins(LED_PORT, 1 << LED_ERROR);
	}

	return status;
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - main()
*/
int main(void)
{
  /* Write your code here */
  status_t status;

  /* Initialize and configure clocks
   * 	-	see clock manager component for details
   */
  CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
						g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_FORCIBLE);

  /* Initialize pins */
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

  PINS_DRV_ClearPins(LED_PORT, (1 << LED_ERROR) | (1 << LED_OK));

  /* Initialize Flash for CSEc operation */
  status = initFlashForCsecOperation();
  if (status == STATUS_SUCCESS)
  {
      PINS_DRV_SetPins(LED_PORT, 1 << LED_OK);
  }
  else
  {
      PINS_DRV_SetPins(LED_PORT, 1 << LED_ERROR);
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
