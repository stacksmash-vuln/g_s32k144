/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Including needed modules to compile this module/procedure */

#include "sdk_project_config.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* Definition of the data transfer size */
#define BUFF_SIZE 64

/* Master TX and RX buffers definition */
uint16_t masterTxBuffer[BUFF_SIZE];

volatile int exit_code = 0;

int main(void)
{
    uint8_t cnt = 0;

    /* Initialize the data buffer */
    for(cnt = 0; cnt < BUFF_SIZE; cnt++)
    {
        masterTxBuffer[cnt] = (uint16_t)cnt;
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

    /* Initialize I2S pal */
    I2S_Init(INST_I2S_PAL1, &i2s_pal1_Config0);

    /* Master sends */
    I2S_SendDataBlocking(INST_I2S_PAL1, (const uint8_t*) masterTxBuffer, BUFF_SIZE, 2000);

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
