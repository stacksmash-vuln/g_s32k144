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
#include <stdio.h>
#include <stdbool.h>
#include "sdk_project_config.h"
#include <stdint.h>
#include <string.h>

/* Definition of the data transfer size */
#define BUFF_SIZE 64

/* Definition LED */
#define LED_PORT  (PTE)
#define LED_RED   (21u)
#define LED_GREEN (22u)

/* Initialization of slave buffers */
/* compare buffers definition */
uint16_t compareBuffer[BUFF_SIZE];
/* Slave RX buffers definition */
uint16_t slaveRxBuffer[BUFF_SIZE];
bool CheckResult;

volatile int exit_code = 0;

int main(void)
{
    uint8_t cnt = 0;
    extension_flexio_for_i2s_t ext;

    /* Initialize the data buffer and Clear RX buffer */
    for(cnt = 0; cnt < BUFF_SIZE; cnt++)
    {
        compareBuffer[cnt] = (uint16_t)cnt;
        slaveRxBuffer[cnt]  = 0U;
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
    i2s_pal1_Config0.extension = &ext;
    ext.sckPin = 4;
    ext.wsPin = 5;
    ext.txPin = 6;
    ext.rxPin = 7;
    I2S_Init(INST_I2S_PAL1, &i2s_pal1_Config0);

    /* Red off */
    PINS_DRV_WritePin(LED_PORT, LED_RED, 0);
    /* Green off */
    PINS_DRV_WritePin(LED_PORT, LED_GREEN, 0);
    CheckResult = true;

    /* Clear RX buffer */
    for(cnt = 0; cnt < BUFF_SIZE; cnt++)
    {
        slaveRxBuffer[cnt]  = 0U;
    }

    /* Call slave transfer function first */
    I2S_ReceiveData(INST_I2S_PAL1, (uint8_t*) slaveRxBuffer, BUFF_SIZE);

    /* Check if transfer is completed with no errors */
    while (I2S_GetStatus(INST_I2S_PAL1, NULL) == STATUS_BUSY)
    {
    }

    /* Perform a comparison between the master and slave buffers, to check the
     * validity of the values transferred.
     * The Red LED will be turned if data does not match. For the case in which
     * the data was correctly transfered the Green LED will be lit.
     */
    for (cnt = 0; cnt < BUFF_SIZE; cnt++)
    {
        if (slaveRxBuffer[cnt] != compareBuffer[cnt])
        {
            CheckResult = false;
            break;
        }
    }

    /* Turn on Red or Green LED depend on the check result */
    PINS_DRV_WritePin(LED_PORT, LED_RED, (1u - CheckResult));
    PINS_DRV_WritePin(LED_PORT, LED_GREEN, CheckResult);

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
