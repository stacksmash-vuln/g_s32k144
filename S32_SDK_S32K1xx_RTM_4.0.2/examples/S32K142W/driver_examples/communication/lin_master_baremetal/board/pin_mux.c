/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: S32K142W
package_id: S32K142W_LQFP64
mcu_data: s32sdk_s32k1xx_rtm_402
processor_version: 0.0.0
pin_labels:
- {pin_num: '52', pin_signal: PTC6, label: lin1_rx, identifier: lin_rx;lin1_rx}
- {pin_num: '51', pin_signal: PTC7, label: lin1_tx, identifier: lin_tx;lin1_tx}
- {pin_num: '26', pin_signal: PTC0, label: LED0, identifier: LED0}
- {pin_num: '25', pin_signal: PTC1, label: LED1, identifier: LED1}
- {pin_num: '21', pin_signal: PTC2, label: LED2, identifier: LED2}
- {pin_num: '43', pin_signal: PTB12, label: BUTTON0, identifier: BUTTON0}
- {pin_num: '42', pin_signal: PTB13, label: BUTTON1, identifier: BUTTON1}
- {pin_num: '17', pin_signal: PTE8, label: LIN_XCVR, identifier: LIN_XCVR}
- {pin_num: '22', pin_signal: PTD7, label: lin2_tx, identifier: lin2_tx}
- {pin_num: '23', pin_signal: PTD6, label: lin2_rx, identifier: lin2_rx}
- {pin_num: '60', pin_signal: PTE0, label: LED0_EVB, identifier: LED0_EVB}
- {pin_num: '13', pin_signal: PTE3, label: LED1_EVB, identifier: LED0_EVB;LED1_EVB}
- {pin_num: '39', pin_signal: PTE7, label: LED2_EVB, identifier: LED0_EVB;LED2_EVB}
- {pin_num: '46', pin_signal: PTD2, label: BUTTON0_EVB, identifier: BUTTON0_EVB}
- {pin_num: '45', pin_signal: PTD3, label: BUTTON1_EVB, identifier: BUTTON1_EVB}
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
  - {pin_num: '52', peripheral: LPUART1, signal: rxd, pin_signal: PTC6, identifier: lin1_rx}
  - {pin_num: '51', peripheral: LPUART1, signal: txd, pin_signal: PTC7, identifier: lin1_tx, direction: OUTPUT}
  - {pin_num: '22', peripheral: LPUART2, signal: txd, pin_signal: PTD7, direction: OUTPUT}
  - {pin_num: '23', peripheral: LPUART2, signal: rxd, pin_signal: PTD6}
  - {pin_num: '26', peripheral: PORTC, signal: 'port, 0', pin_signal: PTC0, direction: OUTPUT}
  - {pin_num: '25', peripheral: PORTC, signal: 'port, 1', pin_signal: PTC1, direction: OUTPUT}
  - {pin_num: '21', peripheral: PORTC, signal: 'port, 2', pin_signal: PTC2, direction: OUTPUT}
  - {pin_num: '43', peripheral: PORTB, signal: 'port, 12', pin_signal: PTB12, direction: INPUT, IRQC: state_1010}
  - {pin_num: '42', peripheral: PORTB, signal: 'port, 13', pin_signal: PTB13, direction: INPUT, IRQC: state_1010}
  - {pin_num: '17', peripheral: PORTE, signal: 'port, 8', pin_signal: PTE8, direction: OUTPUT}
  - {pin_num: '60', peripheral: PORTE, signal: 'port, 0', pin_signal: PTE0, direction: OUTPUT}
  - {pin_num: '13', peripheral: PORTE, signal: 'port, 3', pin_signal: PTE3, identifier: LED1_EVB, direction: OUTPUT}
  - {pin_num: '39', peripheral: PORTE, signal: 'port, 7', pin_signal: PTE7, identifier: LED2_EVB, direction: OUTPUT}
  - {pin_num: '46', peripheral: PORTD, signal: 'port, 2', pin_signal: PTD2, direction: INPUT, IRQC: state_1010}
  - {pin_num: '45', peripheral: PORTD, signal: 'port, 3', pin_signal: PTD3, direction: INPUT, IRQC: state_1010}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* Generate array of configured pin structures */
pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] = {
    {
        .base            = PORTB,
        .pinPortIdx      = 12U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_INT_FALLING_EDGE,
        .clearIntFlag    = false,
        .gpioBase        = PTB,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 13U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_INT_FALLING_EDGE,
        .clearIntFlag    = false,
        .gpioBase        = PTB,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 1U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 2U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 6U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 7U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 2U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_INT_FALLING_EDGE,
        .clearIntFlag    = false,
        .gpioBase        = PTD,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 3U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_INT_FALLING_EDGE,
        .clearIntFlag    = false,
        .gpioBase        = PTD,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 6U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 7U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 3U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 7U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 8U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
};
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
