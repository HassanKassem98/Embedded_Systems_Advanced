/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   Delay.c
 *         \brief   Delay using timer
 *         
 *       \details   -
 ******************************************************************************/
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Delay.h" 
#include "SysTick.h"
/*******************************************************************************
 * \syntax          : void LED_Delay_Timer_Init(Delay_IntHandlerType (*CB)())
 * \Description     : Initialize timer to provide delay
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Delay_IntHandlerType (*CB)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Delay_Timer_Init(Delay_IntHandlerType (*CB)()){
    Timer_SysTick_CfgType Cfg = 
    {
        Timer_SysTickClk,
        0,
        CB,
        Timer_SysTick_EnNtf
    };
    Timer_SysTick_Init(&Cfg);
}
/*******************************************************************************
 * \syntax          : void Delay_ms(uint32 Delay)
 * \Description     : Providing delay
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : uint32 Delay
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Delay_ms(uint32 Delay){
    Timer_SysTick_Rld(Delay*1000*16);
    Timer_SysTick_StrTime();
}
/*******************************************************************************
 *  END OF FILE:    Delay.c
 ******************************************************************************/
