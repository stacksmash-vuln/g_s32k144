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

#ifndef M0_SCST_TEST_SHELL_H
#define M0_SCST_TEST_SHELL_H


/******************************************************************************
* Includes
******************************************************************************/
#include "m0_scst_typedefs.h"


/******************************************************************************
* Defines
******************************************************************************/
/* Return values for the m0_scst_execute_core_tests function */
#define M0_SCST_WRONG_RANGE     0xFF030303U


/******************************************************************************
* Global Variables
******************************************************************************/

extern m0_scst_uint32_t m0_scst_last_executed_test_number;
extern m0_scst_vuint32_t m0_scst_accumulated_signature;
extern m0_scst_uint32_t m0_scst_fault_inject_test_index;


/******************************************************************************
* Global functions
******************************************************************************/

m0_scst_uint32_t m0_scst_execute_core_tests(m0_scst_uint32_t start, m0_scst_uint32_t end);


#endif /* M0_SCST_TEST_SHELL_H */
