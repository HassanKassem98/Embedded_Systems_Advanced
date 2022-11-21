/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   SysTick.c
 *         \brief   Driver for System Tick Timer module
 *         
 *       \details   -
 ******************************************************************************/
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Mcu_Hw.h"
#include "SysTick.h"
/*******************************************************************************
 *  LOCAL DATA
 ******************************************************************************/
 /*******************************************************************************
 * \syntax          : void Timer_SysTick_Init(Timer_SysTick_CfgType *Timer_SysTick_CfgPtr)
 * \Description     : INITializes SysTick 
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Timer_SysTick_CfgType *Timer_SysTick_CfgPtr
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_Init(const Timer_SysTick_CfgType *Timer_SysTick_CfgPtr){
    Timer_SyTickStop();

    switch(Timer_SysTick_CfgPtr->ClockSrc){
        case Timer_SystickPIOSC:
            ResetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_ClksrcSt);
        break;
        
        default:
            SetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_ClksrcSt);
        break;
    }

    Timer_SysTick_Rld(Timer_SysTick_CfgPtr->Val);

    if(Timer_SysTick_CfgPtr->CallB){
        Timer_SysTick_SCallB(Timer_SysTick_CfgPtr->CallB);
    }

    if(Timer_SysTick_CfgPtr->Notify){
        Timer_Systick_EnNtf();
    }
}
/*******************************************************************************
 * \syntax          : void Timer_SysTick_Rld(Timer_Systick_ValType Value)
 * \Description     : Reloads systick
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Timer_Systick_ValType Value
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_Rld(Timer_Systick_ValType Val){
    R(ARM_CORTEXM4_BASE_ADDRESS, STRELOAD)  = (Val & 0x00FFFFFFu);
    R(ARM_CORTEXM4_BASE_ADDRESS, STCURRENT) = 1;
}
/*******************************************************************************
 * \syntax          : Timer_Systick_ValType Timer_SysTick_GetVal(void)
 * \Description     : Readscurrent count of SysTick
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): Timer_Systick_ValType Value
 * \Return value    : 0 - 0xFFFFFF
 ******************************************************************************/
Timer_Systick_ValType Timer_SysTick_GetVal(void){
    Timer_Systick_ValType Val;
    
    Val = R(ARM_CORTEXM4_BASE_ADDRESS, STCURRENT);

    return Val;
}
/*******************************************************************************
 * \syntax          : Timer_Systick_FlgType Timer_SysTickChkFlg(void)
 * \Description     : Checks flag
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): Timer_Systick_FlgType Flag
 * \Return value    : 0-1
 ******************************************************************************/
Timer_Systick_FlgType Timer_SysTickChkFlg(void){
    Timer_Systick_FlgType Flg;

    Flg = GetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_StCount);

    return (Flg && 1);
}
/*******************************************************************************
 * \syntax          : void SysTick_Handler(void)
 * \Description     : Handler for the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
static SysTick_IntHandlerType (*Int_Handler)() = NULL;
void SysTick_Handler(void){
    (*Int_Handler)();
}

/*******************************************************************************
 * \syntax          : void Timer_SysTick_SCallB(SysTick_IntHandlerType(*CallB))
 * \Description     : Sets the CB function to the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : SysTick_IntHandlerType (*CallB)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_SCallB(SysTick_IntHandlerType (*CallB)()){
    Int_Handler = CallB;
}

/*******************************************************************************
 * \syntax          : void Timer_Systick_EnNtf(void)
 * \Description     : Enables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_Systick_EnNtf(void){
    SetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_EnIntSt);
}

/*******************************************************************************
 * \syntax          : void SysTick_DisNotify(void)
 * \Description     : Disables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_DisNtf(void){
    ResetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_EnIntSt);
}

/*******************************************************************************
 * \syntax          : void Timer_SysTick_StrTime(void)
 * \Description     : Starts the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SysTick_StrTime(void){
    SetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_EnStCtrl);
}

/*******************************************************************************
 * \syntax          : void Timer_SyTickStop(void)
 * \Description     : Stops the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Timer_SyTickStop(void){
    ResetBit(R(ARM_CORTEXM4_BASE_ADDRESS, STCTRL), Timer_EnStCtrl);
}

/*******************************************************************************
 *  END OF FILE:    SysTick.c
 ******************************************************************************/
