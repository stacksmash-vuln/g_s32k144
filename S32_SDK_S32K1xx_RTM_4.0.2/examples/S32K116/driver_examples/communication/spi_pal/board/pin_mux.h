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
#define SCK_PORT    PTB
#define SCK_PIN     2U
#define SIN_PORT    PTB
#define SIN_PIN     3U
#define SOUT_PORT    PTB
#define SOUT_PIN     4U
#define PCS_PORT    PTB
#define PCS_PIN     5U
#define D1_PORT    PTD
#define D1_PIN     1U
#define D0_PORT    PTD
#define D0_PIN     0U
#define D7_PORT    PTE
#define D7_PIN     5U
#define D6_PORT    PTE
#define D6_PIN     4U
#define LED_PORT    PTD
#define LED_PIN     15U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 9
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

