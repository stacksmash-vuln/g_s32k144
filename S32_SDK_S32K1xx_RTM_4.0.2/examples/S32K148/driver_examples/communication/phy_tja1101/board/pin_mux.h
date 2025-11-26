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
#define LED0_PORT    PTE
#define LED0_PIN     21U
#define LED1_PORT    PTE
#define LED1_PIN     22U
#define LED2_PORT    PTE
#define LED2_PIN     23U
#define BTN0_PORT    PTC
#define BTN0_PIN     12U
#define BTN1_PORT    PTC
#define BTN1_PIN     13U
#define PHY_RESET_PORT    PTA
#define PHY_RESET_PIN     17U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 28
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

