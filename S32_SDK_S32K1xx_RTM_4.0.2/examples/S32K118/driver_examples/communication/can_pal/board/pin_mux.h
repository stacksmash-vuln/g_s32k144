#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "pins_driver.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*! @brief Definitions/Declarations for BOARD_InitPins Functional Group */
/*! @brief User definition pins */
#define CAN_TX_PORT    PTE
#define CAN_TX_PIN     5U
#define CAN_RX_PORT    PTE
#define CAN_RX_PIN     4U
#define button0_PORT    PTD
#define button0_PIN     3U
#define button1_PORT    PTD
#define button1_PIN     5U
#define led0_PORT    PTD
#define led0_PIN     15U
#define led1_PORT    PTD
#define led1_PIN     16U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 6
/*! @brief User configuration structure */
extern pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0];


#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

