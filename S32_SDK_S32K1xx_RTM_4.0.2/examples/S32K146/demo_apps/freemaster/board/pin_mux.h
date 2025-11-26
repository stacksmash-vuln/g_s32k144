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
#define PTC7_PORT    PTC
#define PTC7_PIN     7U
#define PTC6_PORT    PTC
#define PTC6_PIN     6U
#define PTE21_PORT    PTE
#define PTE21_PIN     21U
#define PTE22_PORT    PTE
#define PTE22_PIN     22U
#define PTE23_PORT    PTE
#define PTE23_PIN     23U
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

