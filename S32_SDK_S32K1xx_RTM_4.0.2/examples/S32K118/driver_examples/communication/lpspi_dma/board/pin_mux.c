/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: S32K118
package_id: S32K118_LQFP64
mcu_data: s32sdk_s32k1xx_rtm_402
processor_version: 0.0.0
pin_labels:
- {pin_num: '18', pin_signal: PTB5, label: PCS0, identifier: PCS0}
- {pin_num: '32', pin_signal: PTB2, label: SCK0, identifier: SCK0}
- {pin_num: '31', pin_signal: PTB3, label: SIN0, identifier: SIN0}
- {pin_num: '19', pin_signal: PTB4, label: SOUT0, identifier: SOUT0}
- {pin_num: '59', pin_signal: PTE1, label: PCS1, identifier: PCA1;PCS1}
- {pin_num: '60', pin_signal: PTE0, label: SOUT1, identifier: SOUT1}
- {pin_num: '2', pin_signal: PTD0, label: SCK1, identifier: SCK1}
- {pin_num: '1', pin_signal: PTD1, label: SIN1, identifier: SIN1}
- {pin_num: '15', pin_signal: PTD15, label: LED, identifier: LED}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and integer type.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from unsigned int to pointer.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 */

#include "pin_mux.h"

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0}
- pin_list:
  - {pin_num: '18', peripheral: LPSPI0, signal: 'pcs, 0', pin_signal: PTB5, direction: OUTPUT}
  - {pin_num: '32', peripheral: LPSPI0, signal: 'sck, sck', pin_signal: PTB2, direction: OUTPUT}
  - {pin_num: '31', peripheral: LPSPI0, signal: sin, pin_signal: PTB3, direction: INPUT}
  - {pin_num: '19', peripheral: LPSPI0, signal: sout, pin_signal: PTB4, direction: OUTPUT}
  - {pin_num: '59', peripheral: LPSPI1, signal: 'pcs, 0', pin_signal: PTE1, identifier: PCS1, direction: INPUT}
  - {pin_num: '60', peripheral: LPSPI1, signal: sout, pin_signal: PTE0, direction: OUTPUT}
  - {pin_num: '2', peripheral: LPSPI1, signal: 'sck, sck', pin_signal: PTD0, direction: INPUT}
  - {pin_num: '1', peripheral: LPSPI1, signal: sin, pin_signal: PTD1, direction: INPUT}
  - {pin_num: '15', peripheral: PORTD, signal: 'port, 15', pin_signal: PTD15, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* Generate array of configured pin structures */
pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] = {
    {
        .base            = PORTB,
        .pinPortIdx      = 2U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 3U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 4U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 5U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT4,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 1U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 15U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTD,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT5,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 1U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT5,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
};
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
