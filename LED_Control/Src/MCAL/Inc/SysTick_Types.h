/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   SysTick_Types.h  
 *       MODULE:   SysTick
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Mcu_Hw.h"

/*******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/
typedef uint32 Timer_Systick_ValType;

typedef uint8 Timer_Systick_FlgType;

typedef void SysTick_IntHandlerType;

typedef enum {
    Timer_EnStCtrl,
    Timer_EnIntSt,
    Timer_ClksrcSt,
    Timer_StCount = 16
} Timer_SysTick_CtrlFld;

typedef enum {
    Timer_SystickPIOSC,
    Timer_SysTickClk
} Timer_SysTick_ClkSrcType;

typedef enum {
    Timer_SysTick_DisNtfy,
    Timer_SysTick_EnNtf
} Timer_SysTick_NtfType;
typedef struct {
    Timer_SysTick_ClkSrcType ClockSrc; 
    Timer_Systick_ValType Val;
    SysTick_IntHandlerType (*CallB)();
    Timer_SysTick_NtfType Notify;
} Timer_SysTick_CfgType;

#endif  /* SYSTICK_TYPES_H */

/*******************************************************************************
 *  END OF FILE:    SysTick_Types.h  
 ******************************************************************************/
