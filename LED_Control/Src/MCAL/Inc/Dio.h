/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Dio.h  
 *       MODULE:   DIO driver
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef DIO_H
#define DIO_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
#include "Dio_Types.h"
/******************************************************************************
 * \syntax          : GPIO_LvlType GPIO_ReadCh(GPIO_ChType ChID)
 * \Description     : Reads the status of the desired pin.
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 * \parameters (out): GPIO_LvlType Value
 * \Return value    : 0-1
 *****************************************************************************/
GPIO_LvlType GPIO_ReadCh(GPIO_ChType ChID);

/******************************************************************************
 * \syntax          : void GPIO_WriteCh(GPIO_ChType ChID, 
 *                                          GPIO_LvlType Level)
 * \Description     : Writes to the desired pin.
 * \Sync\Async      : sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 *                    GPIO_LvlType Level
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_WriteCh(GPIO_ChType ChID, GPIO_LvlType Lvl);
/******************************************************************************
 * \syntax          : void GPIO_WrtPort(GPIO_PortType PrtNm, 
 *                                       GPIO_PortLvlType Level)
 * \Description     : Writes to the desired port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_PortType PrtNm
 *                    GPIO_PortLvlType Level
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_WrtPort(GPIO_PortType PrtNm, GPIO_PortLvlType Lvl);
/******************************************************************************
 * \syntax          : GPIO_PortLvlType GPIO_PortRead(GPIO_PortType PrtNm)
 * \Description     : Reads the status of the desired port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_PortType PrtNm
 * \parameters (out): GPIO_PortLvlType Value
 * \Return value    : 0-255
 *****************************************************************************/
GPIO_PortLvlType GPIO_PortRead(GPIO_PortType PrtNm);

/******************************************************************************
 * \syntax          : void GPIO_FlipCh(GPIO_ChType ChID)
 * \Description     : Toggles the desired pin
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : GPIO_ChType ChID
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_FlipCh(GPIO_ChType ChID);

#endif  /* DIO_H */

/******************************************************************************
 *  END OF FILE:    Dio.h  
 *****************************************************************************/
