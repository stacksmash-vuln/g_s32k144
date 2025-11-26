/******************************************************************************
*
* Copyright 2018 NXP
*
* This software is owned or controlled by NXP and may only be used strictly 
* in accordance with the applicable license terms. By expressly accepting 
* such terms or by downloading, installing, activating and/or otherwise using 
* the software, you are agreeing that you have read, and that you agree to 
* comply with and are bound by, such license terms. If you do not agree to 
* be bound by the applicable license terms, then you may not retain, 
* install, activate or otherwise use the software.
*
******************************************************************************/

#ifndef M0_SCST_CONFIGURATION_H
#define M0_SCST_CONFIGURATION_H


/**********************************************************************************
* Definitions related to single-core / multi-core execution mode
**********************************************************************************/

#define M0_SCST_TESTS_NUM   19U

/* Nested Vector Interrupt (NVIC) registers */
#define M0_ICTR_REG         0xE000E004

/* System Control Block (SCB) registers  */
#define M0_ICSR_REG         0xE000ED04
#define M0_VTOR_REG         0xE000ED08
#define M0_CCR_REG          0xE000ED14
#define M0_SHPR2_REG        0xE000ED1C
#define M0_SHPR3_REG        0xE000ED20
#define M0_SHCSR_REG        0xE000ED24
#define M0_NVIC_ISER_REG    0xE000E100
#define M0_NVIC_ICER_REG    0xE000E180

#define M0_SCST_DISABLE_EXTERNAL_INTERRUPTS  1U

#endif /* M0_SCST_CONFIGURATION_H */
