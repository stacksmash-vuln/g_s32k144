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
#define lin1_rx_PORT    PTC
#define lin1_rx_PIN     6U
#define lin1_tx_PORT    PTC
#define lin1_tx_PIN     7U
#define lin2_tx_PORT    PTD
#define lin2_tx_PIN     7U
#define lin2_rx_PORT    PTD
#define lin2_rx_PIN     6U
#define LED0_PORT    PTC
#define LED0_PIN     0U
#define LED1_PORT    PTC
#define LED1_PIN     1U
#define LED2_PORT    PTC
#define LED2_PIN     2U
#define BUTTON0_PORT    PTB
#define BUTTON0_PIN     12U
#define BUTTON1_PORT    PTB
#define BUTTON1_PIN     13U
#define LIN_XCVR_PORT    PTE
#define LIN_XCVR_PIN     8U
#define LED0_EVB_PORT    PTE
#define LED0_EVB_PIN     0U
#define LED1_EVB_PORT    PTE
#define LED1_EVB_PIN     3U
#define LED2_EVB_PORT    PTE
#define LED2_EVB_PIN     7U
#define BUTTON0_EVB_PORT    PTD
#define BUTTON0_EVB_PIN     2U
#define BUTTON1_EVB_PORT    PTD
#define BUTTON1_EVB_PIN     3U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 15
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

