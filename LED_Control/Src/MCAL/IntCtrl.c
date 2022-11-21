/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   IntCtrl.c
 *         \brief   Interrupt control driver
 *       \details   ________________________________
 *****************************************************************************/
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"
/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/
extern Int_CtrlCnfgType Int_CtrlCfg[];
/******************************************************************************
 * \syntax          :   void Int_CtrlInit(void)
 * \Description     :   Initialize NVIC/SCB Module
 * \Sync\Async      :   Sync
 * \Reentrancy      :   Non-Reentrant
 * \parameters (in) :   None
 * \parameters (out):   None
 * \Return value    :   None
 *****************************************************************************/
void Int_CtrlInit(void){
	uint8 a;
    R(ARM_CORTEXM4_BASE_ADDRESS, APINT) = (0x05FA0000U | (Int_PRIGroups << 8));
    
    for(a=0; a<Int_NumInts; a++){
        switch(Int_CtrlCfg[a].IntType < 16){
            case TRUE:
                SetVal(
                    R(
                        ARM_CORTEXM4_BASE_ADDRESS, 
                        (SYSPRI1 + (((Int_CtrlCfg[a].IntType /4)-1)*4))
                    ), 
                    (((Int_CtrlCfg[a].IntType % 4) * 8) + 5), 
                    (Int_CtrlCfg[a].PRIValType & 0x07u)
                );
                
                if(Int_CtrlCfg[a].IntType < 7){
                    SetBit(
                        R(ARM_CORTEXM4_BASE_ADDRESS, SYSHNDCTRL), 
                        (Int_CtrlCfg[a].IntType + 12)
                    );
                }
            break;

            default:
                Int_CtrlCfg[a].IntType -= 16;
                SetVal(
                    R(
                        ARM_CORTEXM4_BASE_ADDRESS, 
                        (PRI0 + ((Int_CtrlCfg[a].IntType / 4)*4))
                    ),
                    (((Int_CtrlCfg[a].IntType % 4) * 8) + 5), 
                    (Int_CtrlCfg[a].PRIValType & 0x07u)  
                );

                SetBit(
                    R(
                        ARM_CORTEXM4_BASE_ADDRESS, 
                        (EN0 + ((Int_CtrlCfg[a].IntType / 32)*4))
                    ), 
                    (Int_CtrlCfg[a].IntType % 32)
                );
            break;
        }
    }
}

/******************************************************************************
 *  END OF FILE:    IntCtrl.c
 *****************************************************************************/
