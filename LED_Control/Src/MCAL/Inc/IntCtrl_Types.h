/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   IntCtrl_Types.h  
 *       MODULE:   Interrupt Control
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef uint8 Int_CtrlPRIValType;

typedef enum {
    PRIGroup_8,
    PRIGroup_4 = 5,
    PRIGroup_2,
    PRIGroup_0
} Int_CtrPRIGrpType;

typedef enum {
    /* Exceptions */
    MEM_MNG_EXC = 4,
    BUS_FAULT_EXC,
    USAGE_FAULT_EXC,
    SVC_EXC = 11,
    DEBUG_MONITOR_EXC,
    PENDSV_EXC = 14,
    SYSTICK_EXC,
    /* Interrupts */
    GPIO_A_INT,
    GPIO_B_INT,
    GPIO_C_INT,
    GPIO_D_INT,
    GPIO_E_INT,
    UART0_INT,
    UART1_INT,
    SSI0_INT,
    I2C0_INT,
    PWM0_FAULT_INT,
    PWM0_GEN0_INT,
    PWM0_GEN1_INT,
    PWM0_GEN2_INT,
    QEI0_INT,
    ADC0_SEQ0_INT,
    ADC0_SEQ1_INT,
    ADC0_SEQ2_INT,
    ADC0_SEQ3_INT,
    WDT01_INT,
    TIMER0A_INT,
    TIMER0B_INT,
    TIMER1A_INT,
    TIMER1B_INT,
    TIMER2A_INT,
    TIMER2B_INT,
    ANALOG_CMP0_INT,
    ANALOG_CMP1_INT,
    SYS_CTL_INT = 44,
    FLASH_AND_EEPROM_CTL_INT,
    GPIO_F_INT,
    UART2_INT = 49,
    SSI1_INT,
    TIMER3A_INT,
    TIMER3B_INT,
    I2C1_INT,
    QEI1_INT,
    CAN0_INT,
    CAN1_INT,
    HIBERNATION_INT = 59,
    USB_INT,
    PWM0_GEN3_INT,
    DMA_SOFTWARE_INT,
    DMA_ERROR_INT,
    ADC1_SEQ0_INT,
    ADC1_SEQ1_INT,
    ADC1_SEQ2_INT,
    ADC1_SEQ3_INT,
    SSI2_INT = 73,
    SSI3_INT,
    UART3_INT,
    UART4_INT,
    UART5_INT,
    UART6_INT,
    UART7_INT,
    I2C2_INT = 84,
    I2C3_INT,
    TIMER4A_INT,
    TIMER4B_INT,
    TIMER5A_INT = 108,
    TIMER5B_INT,
    WIDE_TIMER0A_INT,
    WIDE_TIMER0B_INT,
    WIDE_TIMER1A_INT,
    WIDE_TIMER1B_INT,
    WIDE_TIMER2A_INT,
    WIDE_TIMER2B_INT,
    WIDE_TIMER3A_INT,
    WIDE_TIMER3B_INT,
    WIDE_TIMER4A_INT,
    WIDE_TIMER4B_INT,
    WIDE_TIMER5A_INT,
    WIDE_TIMER5B_INT,
    SYS_EXCEPTION_INT,
    PWM1_GEN0_INT = 150,
    PWM1_GEN1_INT,
    PWM1_GEN2_INT,
    PWM1_GEN3_INT,
    PWM1_FAULT_INT 
} Int_CtrIntType;

typedef struct {
    Int_CtrIntType IntType;
    Int_CtrlPRIValType PRIValType;
} Int_CtrlCnfgType;

#endif  /* INTCTRL_TYPES_H */

/******************************************************************************
 *  END OF FILE:    IntCtrl_Types.h  
 *****************************************************************************/
