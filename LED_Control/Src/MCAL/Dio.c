/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   Dio.c
 *         \brief   Driver for DIO module
 *         
 *       \details   -
 *****************************************************************************/
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Dio.h"
/******************************************************************************
 *  LOCAL DATA
 *****************************************************************************/
const static uint32 GPIOS[] = {GPIO_A_BASE_ADDRESS, GPIO_B_BASE_ADDRESS, GPIO_C_BASE_ADDRESS, GPIO_D_BASE_ADDRESS, GPIO_E_BASE_ADDRESS, GPIO_F_BASE_ADDRESS};

/******************************************************************************
 * \syntax          : void GPIO_WrtPort(GPIO_PortType PrtNm, 
 *                                       GPIO_PortLvlType Level)
 * \Description     : Writes PORT
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_PortType PrtNm
 *                    GPIO_PortLvlType Level
 * \parameters (out): None
 * \Return Val    : None
 *****************************************************************************/
void GPIO_WrtPort(GPIO_PortType PrtNm, GPIO_PortLvlType Lvl){
    R(PrtNm, GPIODATA) = Lvl;
}
/******************************************************************************
 * \syntax          : GPIO_LvlType GPIO_ReadCh(GPIO_ChType ChID)
 * \Description     : Reads status from pin
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 * \parameters (out): GPIO_LvlType Val
 * \Return Val    : 0-1
 *****************************************************************************/
GPIO_LvlType GPIO_ReadCh(GPIO_ChType ChID){
    GPIO_LvlType Val;
    uint32 Port = GPIOS[(ChID / 8)];
    uint8 Pin   = (ChID % 8);
    
    /* Val = GetBit(R(Port, (1 << (Pin + 2))), Pin); */
    Val = GetBit(R(Port, GPIODATA), Pin);
    
    return (Val && 1);
}
/******************************************************************************
 * \syntax          : Dio_PortLvlType GPIO_PortRead(GPIO_PortType PrtNm)
 * \Description     : Read from port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_PortType PrtNm
 * \parameters (out): Dio_PortLvlType Val
 * \Return Val    : 0-255
 *****************************************************************************/
GPIO_PortLvlType GPIO_PortRead(GPIO_PortType PrtNm){
    GPIO_PortLvlType Val;

    Val = R(PrtNm, GPIODATA);

    return Val;
}
/******************************************************************************
 * \syntax          : void GPIO_FlipCh(GPIO_ChType ChID)
 * \Description     : Toggles the desired pin
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 * \parameters (out): None
 * \Return Val    : None
 *****************************************************************************/
void GPIO_FlipCh(GPIO_ChType ChID){
    uint32 Port = GPIOS[(ChID / 8)];
    uint8 Pin   = (ChID % 8);

    /* TglBit(R(Port, (1 << (Pin + 2))), Pin); */
    TglBit(R(Port, GPIODATA), Pin);
}
/******************************************************************************
 * \syntax          : void GPIO_WriteCh(GPIO_ChType ChID, 
 *                                          GPIO_LvlType Level)
 * \Description     : Writes in pin.
 * \Sync\Async      : sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 *                    GPIO_LvlType Level
 * \parameters (out): None
 * \Return Val    : None
 *****************************************************************************/
void GPIO_WriteCh(GPIO_ChType ChID, GPIO_LvlType Lvl){
    uint32 Port = GPIOS[(ChID / 8)];
    uint8 Pin   = (ChID % 8);
    
    switch(Lvl){
        case LOW:
            /* R(Port, (1 << (Pin + 2))) =  0; */
            ResetBit(R(Port, GPIODATA), Pin);
        break;

        default:
            /* R(Port, (1 << (Pin + 2))) = 0xFFu; */
            SetBit(R(Port, GPIODATA), Pin);
        break;
    }
    
}
/******************************************************************************
 *  END OF FILE:    Dio.c
 *****************************************************************************/
