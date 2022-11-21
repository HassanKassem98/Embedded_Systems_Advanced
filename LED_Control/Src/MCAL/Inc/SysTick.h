/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   SysTick.h  
 *       MODULE:   SysTick
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "SysTick_Types.h"
/*******************************************************************************
 * \syntax          : Timer_Systick_ValType Timer_SysTick_GetVal(void)
 * \Description     : Readscurrent count of SysTick 
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): Timer_Systick_ValType Value
 * \Return value    : 0 - 0xFFFFFF
 ******************************************************************************/
Timer_Systick_ValType Timer_SysTick_GetVal(void);

/*******************************************************************************
 * \syntax          : void Timer_SysTick_Rld(Timer_Systick_ValType Value)
 * \Description     : Reloads SysTick 
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Timer_Systick_ValType Value
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_Rld(Timer_Systick_ValType Val);
/*******************************************************************************
 * \syntax          : void Timer_SysTick_Init(Timer_SysTick_CfgType *Timer_SysTick_CfgPtr)
 * \Description     : Initializes the SysTick timer module
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Timer_SysTick_CfgType *Timer_SysTick_CfgPtr
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_Init(const Timer_SysTick_CfgType *Timer_SysTick_CfgPtr);
/*******************************************************************************
 * \syntax          : Timer_Systick_FlgType Timer_SysTickChkFlg(void)
 * \Description     : Checks the current status flag
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): Timer_Systick_FlgType Flag
 * \Return value    : 0-1
 ******************************************************************************/
Timer_Systick_FlgType Timer_SysTickChkFlg(void);

/*******************************************************************************
 * \syntax          : void SysTick_Handler(void)
 * \Description     : Handler for the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Handler(void);

/*******************************************************************************
 * \syntax          : void Timer_SysTick_SCallB(SysTick_IntHandlerType(*CallB)())
 * \Description     : Sets the CB function to the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : SysTick_IntHandlerType (*CallB)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_SCallB(SysTick_IntHandlerType (*CallB)());

/*******************************************************************************
 * \syntax          : void SysTick_EnNotify(void)
 * \Description     : Enables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_Systick_EnNtf(void);

/*******************************************************************************
 * \syntax          : void SysTick_DisNotify(void)
 * \Description     : Disables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_DisNtf(void);

/*******************************************************************************
 * \syntax          : void Timer_SysTick_StrTime(void)
 * \Description     : Starts the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_StrTime(void);

/*******************************************************************************
 * \syntax          : void Timer_SyTickStop(void)
 * \Description     : Stops the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SyTickStop(void);

#endif  /* SYSTICK_H */

/*******************************************************************************
 *  END OF FILE:    SysTick.h  
 ******************************************************************************/
