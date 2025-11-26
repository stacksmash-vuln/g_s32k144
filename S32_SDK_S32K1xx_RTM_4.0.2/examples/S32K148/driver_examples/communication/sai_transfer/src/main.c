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
**     Project     : sai_transfer_s32k148
**     Processor   : S32K148_144
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
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
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include <stdio.h>
#include <stdbool.h>
#include "sdk_project_config.h"

#include <string.h>

volatile int exit_code = 0;

#define BUFF_SIZE 100U

uint16_t LeftData[BUFF_SIZE];
uint16_t RightData[BUFF_SIZE];
uint16_t* SendData[2] = {LeftData, RightData};
uint16_t RecvBuff[BUFF_SIZE*2];
uint16_t* RecvData[1] = {RecvBuff};
bool CheckResult;

/* check data from a certain index */
bool CheckData(uint32_t from)
{
    uint32_t j = 0;
    uint32_t i;
    for (i = from; i < BUFF_SIZE; i++)
    {
        if (RecvBuff[j*2] != LeftData[i] || RecvBuff[j*2+1] != RightData[i])
        {
            return false;
        }
        j++;
    }
    return true;
}
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - main()
*/
int main(void)
{
  /* initialize send data */
  uint32_t i;

  for (i = 0; i < BUFF_SIZE; i++)
  {
      LeftData[i] = i*2;
      RightData[i] = i*2+1;
  }
  /* Initialize clock module */
  CLOCK_DRV_Init(&clockMan1_InitConfig0);

  /* Initialize eDMA module & channels */
  EDMA_DRV_Init(&dmaController_State,
                &dmaController_InitConfig,
                edmaChnStateArray,
                edmaChnConfigArray,
                EDMA_CONFIGURED_CHANNELS_COUNT);
  /* Initialize pins */
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
  /* Enables system interrupt */
  INT_SYS_EnableIRQGlobal();
  /* Initialize SAI module */
  SAI_DRV_RxInit(INST_SAI1, &SAI1_InitConfig0, &sai1RxState0);
  SAI_DRV_TxInit(INST_SAI0, &SAI0_InitConfig0, &sai0TxState0);

  /* Call receive data first because rx is slave */
  SAI_DRV_Receive(INST_SAI1, (uint8_t**) RecvData, BUFF_SIZE*2);
  /* Send data from SAI0 to SAI1 */
  SAI_DRV_Send(INST_SAI0, (const uint8_t**) SendData, BUFF_SIZE);
  /* Wait for transfer complete */
  while (SAI_DRV_GetReceivingStatus(INST_SAI1, NULL) == STATUS_BUSY)
  {
  }

  SAI_DRV_TxDeinit(INST_SAI0);
  SAI_DRV_RxDeinit(INST_SAI1);

  /* Check if data is received properly, result of the check is stored in CheckResult */
  CheckResult = CheckData(0);

  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
}
