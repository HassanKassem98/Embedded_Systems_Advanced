/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   Delay.h  
 *       MODULE:   Delay header file
 * 
 *  DESCRIPTION:  __________________
 * 
 ******************************************************************************/
#ifndef DELAY_H
#define DELAY_H
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Std_Types.h"
#include "SysTick_Types.h"
/*******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/
typedef SysTick_IntHandlerType Delay_IntHandlerType;
/*******************************************************************************
 * \syntax          : void Delay_ms(uint32 Delay)
 * \Description     : Providing delay
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : uint32 Delay
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Delay_ms(uint32 Delay);
/*******************************************************************************
 * \syntax          : void LED_Delay_Timer_Init(Delay_IntHandlerType (*CB)())
 * \Description     : Initialize timer to provide delay
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Delay_IntHandlerType (*CB)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Delay_Timer_Init(Delay_IntHandlerType (*CB)());
#endif  /* DELAY_H */
/*******************************************************************************
 *  END OF FILE:    Delay.h  
 ******************************************************************************/
