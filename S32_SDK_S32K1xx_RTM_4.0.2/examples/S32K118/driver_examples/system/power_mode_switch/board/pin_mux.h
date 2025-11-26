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
#define PTD16_PORT    PTD
#define PTD16_PIN     16U
#define PTD15_PORT    PTD
#define PTD15_PIN     15U
#define PTD5_PORT    PTD
#define PTD5_PIN     5U
#define PTB1_PORT    PTB
#define PTB1_PIN     1U
#define PTB0_PORT    PTB
#define PTB0_PIN     0U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 5
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

