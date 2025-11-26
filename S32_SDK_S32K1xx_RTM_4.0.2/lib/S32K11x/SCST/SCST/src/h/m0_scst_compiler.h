/******************************************************************************
*
* Copyright 2018,2020 NXP
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

#ifndef M0_SCST_COMPILER_H
#define M0_SCST_COMPILER_H


/* C/C++ compiler macros for placing code or variable in SCST Library defined section */
#if defined (__IAR_SYSTEMS_ICC__)
#define SCST_PLACE_IN_SECTION_HELPER_0(X) #X
#define SCST_PLACE_IN_SECTION_HELPER_1(SECTION_NAME) SCST_PLACE_IN_SECTION_HELPER_0(location = #SECTION_NAME)
#define SCST_PLACE_IN_SECTION_HELPER_2(SECTION_NAME) SCST_PLACE_IN_SECTION_HELPER_1(.SECTION_NAME)
#define SCST_PLACE_IN_SECTION(SECTION_NAME) _Pragma(SCST_PLACE_IN_SECTION_HELPER_2(SECTION_NAME)) 
#endif  /* __IAR_SYSTEMS_ICC__*/

#if defined (__ghs__) || defined (__GNUC__) || defined (__DCC__)
#define SCST_PLACE_IN_SECTION_HELPER(SECTION_NAME) __attribute__ (( section(#SECTION_NAME) ))
#define SCST_PLACE_IN_SECTION(SECTION_NAME) SCST_PLACE_IN_SECTION_HELPER(.SECTION_NAME) 
#endif /* __ghs__ __GNUC__ */


/****************************** Wind River Diab ******************************/
#if defined (__DCC__)

    #define SCST_THUMB .code16
    
    #define function @tfunc
    #define label @object
    
    #define SCST_TYPE(name,param) .type name, param

    #define SCST_WORD .long
    #define SCST_SHORT .short
    
    #define SCST_EXPORT .global
    #define SCST_EXTERN .global
    
    #define SCST_LTORG .ltorg
    
    /* reserves block of data initialized to zero in bytes */
    #define SCST_ALLOC_BYTES(SIZE) .skip SIZE
    
    #define SCST_SET(NAME,VALUE) .set NAME, VALUE
    #define SCST_DEFINE(NAME,VALUE) .set NAME, VALUE
    
    #define SCST_SECTION_EXEC(SECTION_NAME) .section .SECTION_NAME,rx
    #define SCST_SECTION_DATA(SECTION_NAME) .section .SECTION_NAME,rw
    #define SCST_SECTION_CONST(SECTION_NAME) .section .SECTION_NAME,r
    #define SCST_SECTION_EXEC_W(SECTION_NAME) .section .SECTION_NAME,rwx
    #define SCST_SECTION_DATA_UNINIT(SECTION_NAME) .section .SECTION_NAME,rwb
    
    #define SCST_SECTION_EXEC_ALIGN(SECTION_NAME, ALIGNMENT) .section .SECTION_NAME,ALIGNMENT,rx
    #define SCST_SECTION_DATA_ALIGN(SECTION_NAME, ALIGNMENT) .section .SECTION_NAME,ALIGNMENT,rw
    #define SCST_SECTION_CONST_ALIGN(SECTION_NAME, ALIGNMENT) .section .SECTION_NAME,ALIGNMENT,r
    #define SCST_SECTION_EXEC_W_ALIGN(SECTION_NAME, ALIGNMENT) .section .SECTION_NAME,ALIGNMENT,rwx
    #define SCST_SECTION_DATA_UNINIT_ALIGN(SECTION_NAME, ALIGNMENT) .section .SECTION_NAME,ALIGNMENT,rwb
    
    #define SCST_BYTES_2 2
    #define SCST_BYTES_4 4
    #define SCST_BYTES_8 8
    #define SCST_BYTES_16 16
    #define SCST_BYTES_32 32
    #define SCST_BYTES_64 64
    #define SCST_BYTES_128 128
    #define SCST_BYTES_256 256
    
    /* default option is -Xalign-power2 */
    #define SCST_ALIGN_BYTES_2 .align 1
    #define SCST_ALIGN_BYTES_4 .align 2
    #define SCST_ALIGN_BYTES_8 .align 3
    #define SCST_ALIGN_BYTES_16 .align 4
    #define SCST_ALIGN_BYTES_32 .align 5
    #define SCST_ALIGN_BYTES_64 .align 6
    #define SCST_ALIGN_BYTES_128 .align 7
    #define SCST_ALIGN_BYTES_256 .align 8
    
    #define SCST_OPCODE16(OPCODE) SCST_SHORT OPCODE
    #define SCST_OPCODE32(OPCODE) SCST_WORD OPCODE
    
    #define MOV_S MOV
    #define MVN_S MVN
    #define AND_S AND
    #define EOR_S EOR
    #define ORR_S ORR
    #define BIC_S BIC
    #define ROR_S ROR
    #define LSL_S LSL
    #define LSR_S LSR
    #define ASR_S ASR
    #define ADD_S ADD
    #define ADC_S ADC
    #define SUB_S SUB
    #define SBC_S SBC
    #define NEG_S NEG
    #define MUL_S MUL
    
    #define SCST_FILE_END

    
/******************************** IAR Systems ********************************/
#elif defined (__IAR_SYSTEMS_ICC__) 
#elif defined (__IAR_SYSTEMS_ASM__)
    
    #define SCST_THUMB THUMB
    
    /* Labels within a Thumb area have bit 0 set to 1 */
    #define SCST_TYPE(name, ident) /* not needed */

    #define SCST_WORD DC32
    #define SCST_SHORT DC16

    #define SCST_EXPORT PUBLIC
    #define SCST_EXTERN EXTERN
    
    #define SCST_LTORG LTORG
    
    /* reserves block of data initialized to zero in bytes */
    #define SCST_ALLOC_BYTES(N) DS8 N
    
    #define SCST_DEFINE(NAME,VALUE) NAME: DEFINE VALUE 
    #define SCST_SET(NAME,VALUE) NAME: SET VALUE
    
    #define SCST_SECTION_EXEC(SECTION_NAME) section .SECTION_NAME :CODE
    #define SCST_SECTION_DATA(SECTION_NAME) section .SECTION_NAME :DATA
    #define SCST_SECTION_CONST(SECTION_NAME) section .SECTION_NAME :CONST
    #define SCST_SECTION_EXEC_W(SECTION_NAME) section .SECTION_NAME :DATA
    #define SCST_SECTION_DATA_UNINIT(SECTION_NAME) section .SECTION_NAME :DATA
    
    #define SCST_SECTION_EXEC_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC(SECTION_NAME) (ALIGNMENT)
    #define SCST_SECTION_DATA_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA(SECTION_NAME) (ALIGNMENT)
    #define SCST_SECTION_CONST_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_CONST(SECTION_NAME) (ALIGNMENT)
    #define SCST_SECTION_EXEC_W_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC_W(SECTION_NAME) (ALIGNMENT)
    #define SCST_SECTION_DATA_UNINIT_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA_UNINIT(SECTION_NAME) (ALIGNMENT)
    
    #define SCST_BYTES_2   1
    #define SCST_BYTES_4   2
    #define SCST_BYTES_8   3
    #define SCST_BYTES_16  4
    #define SCST_BYTES_32  5
    #define SCST_BYTES_64  6
    #define SCST_BYTES_128 7
    #define SCST_BYTES_256 8
    
    #define SCST_ALIGN_BYTES_2 DATA ALIGNROM 1
    #define SCST_ALIGN_BYTES_4 DATA ALIGNROM 2
    #define SCST_ALIGN_BYTES_8 DATA ALIGNROM 3
    #define SCST_ALIGN_BYTES_16 DATA ALIGNROM 4
    #define SCST_ALIGN_BYTES_32 DATA ALIGNROM 5
    #define SCST_ALIGN_BYTES_64 DATA ALIGNROM 6
    #define SCST_ALIGN_BYTES_128 DATA ALIGNROM 7
    #define SCST_ALIGN_BYTES_256 DATA ALIGNROM 8
    
    #define SCST_OPCODE16(OPCODE) SCST_SHORT OPCODE
    #define SCST_OPCODE32(OPCODE) SCST_WORD OPCODE
    
    #define MOV_S MOVS
    #define MVN_S MVNS
    #define AND_S ANDS
    #define EOR_S EORS
    #define ORR_S ORRS
    #define BIC_S BICS
    #define ROR_S RORS
    #define LSL_S LSLS
    #define LSR_S LSRS
    #define ASR_S ASRS
    #define ADD_S ADDS
    #define ADC_S ADCS
    #define SUB_S SUBS
    #define SBC_S SBCS
    #define NEG_S NEGS
    #define MUL_S MULS
    
    #define SCST_FILE_END END
    

/******************************** Green Hills *********************************/    
#elif defined (__ghs__)

    #define function $function
    #define label $object
    
    #define SCST_THUMB .thumb

    #define SCST_TYPE(name, ident) .type name, ident
    
    #define SCST_WORD .long
    #define SCST_SHORT .short

    #define SCST_EXPORT .global
    #define SCST_EXTERN .global
    
    #define SCST_ALIGN_POWER_OF_TWO(POWER) .align (1 << POWER)
    #define SCST_LTORG .ltorg
    
    #define SCST_ALLOC_BYTES(N) .space N
    
    /* has to be at the beginning of a line */
    #define SCST_SET(NAME,VALUE) .set NAME, VALUE
    /* has to be at the beginning of a line */
    #define SCST_DEFINE(NAME,VALUE) .set NAME, VALUE

    #define SCST_SECTION_EXEC(SECTION_NAME) .section .SECTION_NAME,"ax"
    #define SCST_SECTION_DATA(SECTION_NAME) .section .SECTION_NAME,"aw"
    #define SCST_SECTION_CONST(SECTION_NAME) .section .SECTION_NAME,"a"
    #define SCST_SECTION_EXEC_W(SECTION_NAME) .section .SECTION_NAME,"awx"
    #define SCST_SECTION_DATA_UNINIT(SECTION_NAME) .section .SECTION_NAME,"awb"
    
    #define SCST_SECTION_EXEC_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC(SECTION_NAME)
    #define SCST_SECTION_DATA_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA(SECTION_NAME)
    #define SCST_SECTION_CONST_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_CONST(SECTION_NAME)
    #define SCST_SECTION_EXEC_W_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC_W(SECTION_NAME)
    #define SCST_SECTION_DATA_UNINIT_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA_UNINIT(SECTION_NAME)
    
    #define SCST_BYTES_2   1
    #define SCST_BYTES_4   2
    #define SCST_BYTES_8   3
    #define SCST_BYTES_16  4
    #define SCST_BYTES_32  5
    #define SCST_BYTES_64  6
    #define SCST_BYTES_128 7
    #define SCST_BYTES_256 8
    
    #define SCST_ALIGN_BYTES_2 SCST_ALIGN_POWER_OF_TWO(1)
    #define SCST_ALIGN_BYTES_4 SCST_ALIGN_POWER_OF_TWO(2)
    #define SCST_ALIGN_BYTES_8 SCST_ALIGN_POWER_OF_TWO(3)
    #define SCST_ALIGN_BYTES_16 SCST_ALIGN_POWER_OF_TWO(4)
    #define SCST_ALIGN_BYTES_32 SCST_ALIGN_POWER_OF_TWO(5)
    #define SCST_ALIGN_BYTES_64 SCST_ALIGN_POWER_OF_TWO(6)
    #define SCST_ALIGN_BYTES_128 SCST_ALIGN_POWER_OF_TWO(7)
    #define SCST_ALIGN_BYTES_256 SCST_ALIGN_POWER_OF_TWO(8)
    
    #define SCST_OPCODE16(OPCODE) SCST_SHORT OPCODE
    #define SCST_OPCODE32(OPCODE) SCST_WORD OPCODE
    
    #define MOV_S MOV
    #define MVN_S MVN
    #define AND_S AND
    #define EOR_S EOR
    #define ORR_S ORR
    #define BIC_S BIC
    #define ROR_S ROR
    #define LSL_S LSL
    #define LSR_S LSR
    #define ASR_S ASR
    #define ADD_S ADD
    #define ADC_S ADC
    #define SUB_S SUB
    #define SBC_S SBC
    #define NEG_S NEG
    #define MUL_S MUL
    
    #define APSR_nzcvq APSR
    
    #define SCST_FILE_END
        

/********************************** GNU GCC ***********************************/        
#elif defined (__GNUC__)

    #define SCST_THUMB .thumb

    #define SCST_TYPE(name, ident) .type name, %ident

    #define SCST_WORD .long
    #define SCST_SHORT .short

    #define SCST_EXPORT .global
    #define SCST_EXTERN .global
    
    #define label object
    
    #define SCST_ALIGN_POWER_OF_TWO(POWER) .align POWER
    #define SCST_LTORG .ltorg
    
    #define SCST_ALLOC_BYTES(N) .space N
    
    /* has to be at the beginning of a line */
    #define SCST_SET(NAME,VALUE) .set NAME, VALUE
    /* has to be at the beginning of a line */
    #define SCST_DEFINE(NAME,VALUE) .set NAME, VALUE

    #define SCST_SECTION_EXEC(SECTION_NAME) .section .SECTION_NAME,"ax"
    #define SCST_SECTION_DATA(SECTION_NAME) .section .SECTION_NAME,"aw"
    #define SCST_SECTION_CONST(SECTION_NAME) .section .SECTION_NAME,"a"
    #define SCST_SECTION_EXEC_W(SECTION_NAME) .section .SECTION_NAME,"awx"
    #define SCST_SECTION_DATA_UNINIT(SECTION_NAME) .section .SECTION_NAME,"aw"
    
    #define SCST_SECTION_EXEC_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC(SECTION_NAME) ; SCST_ALIGN_POWER_OF_TWO(ALIGNMENT)
    #define SCST_SECTION_DATA_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA(SECTION_NAME) ; SCST_ALIGN_POWER_OF_TWO(ALIGNMENT)
    #define SCST_SECTION_CONST_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_CONST(SECTION_NAME) ; SCST_ALIGN_POWER_OF_TWO(ALIGNMENT)
    #define SCST_SECTION_EXEC_W_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_EXEC_W(SECTION_NAME) ; SCST_ALIGN_POWER_OF_TWO(ALIGNMENT)
    #define SCST_SECTION_DATA_UNINIT_ALIGN(SECTION_NAME, ALIGNMENT) SCST_SECTION_DATA_UNINIT(SECTION_NAME) ; SCST_ALIGN_POWER_OF_TWO(ALIGNMENT)
    
    #define SCST_BYTES_2   1
    #define SCST_BYTES_4   2
    #define SCST_BYTES_8   3
    #define SCST_BYTES_16  4
    #define SCST_BYTES_32  5
    #define SCST_BYTES_64  6
    #define SCST_BYTES_128 7
    #define SCST_BYTES_256 8
    
    #define SCST_ALIGN_BYTES_2 SCST_ALIGN_POWER_OF_TWO(1)
    #define SCST_ALIGN_BYTES_4 SCST_ALIGN_POWER_OF_TWO(2)
    #define SCST_ALIGN_BYTES_8 SCST_ALIGN_POWER_OF_TWO(3)
    #define SCST_ALIGN_BYTES_16 SCST_ALIGN_POWER_OF_TWO(4)
    #define SCST_ALIGN_BYTES_32 SCST_ALIGN_POWER_OF_TWO(5)
    #define SCST_ALIGN_BYTES_64 SCST_ALIGN_POWER_OF_TWO(6)
    #define SCST_ALIGN_BYTES_128 SCST_ALIGN_POWER_OF_TWO(7)
    #define SCST_ALIGN_BYTES_256 SCST_ALIGN_POWER_OF_TWO(8)
    
    #define SCST_OPCODE16(OPCODE) SCST_SHORT OPCODE
    #define SCST_OPCODE32(OPCODE) SCST_WORD OPCODE
    
    #define MOV_S MOV
    #define MVN_S MVN
    #define AND_S AND
    #define EOR_S EOR
    #define ORR_S ORR
    #define BIC_S BIC
    #define ROR_S ROR
    #define LSL_S LSL
    #define LSR_S LSR
    #define ASR_S ASR
    #define ADD_S ADD
    #define ADC_S ADC
    #define SUB_S SUB
    #define SBC_S SBC
    #define NEG_S NEG
    #define MUL_S MUL

    #define APSR_nzcvq APSR_nzcvq
    
    #define SCST_FILE_END
  
#else
    #error "Unsupported compiler. Compiler abstraction needs to be updated to use this compiler."
#endif


#endif /* #ifndef M0_SCST_COMPILER_H */
