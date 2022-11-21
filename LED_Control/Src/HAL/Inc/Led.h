/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   Led.h  
 *       MODULE:   LED
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef LED_H
#define LED_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Dio_Types.h"

/*******************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************************************************************/
#define LED_GREEN                   PF3
#define LED_BLUE                    PF2
#define LED_RED                     PF1
/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/
typedef GPIO_ChType LED_InstType;
/*******************************************************************************
 * \syntax          : void LED_OFF(LED_InstType LED_Ch)
 * \Description     : Turns off the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_OFF(LED_InstType LED_Ch);
/*******************************************************************************
 * \syntax          : void LED_ON(LED_InstType LED_Ch)
 * \Description     : Turns on the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_ON(LED_InstType LED_Ch);
/*******************************************************************************
 * \syntax          : void LED_Tgl(LED_InstType LED_Ch)
 * \Description     : Toggles the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Tgl(LED_InstType LED_Ch);

#endif  /* LED_H */

/*******************************************************************************
 *  END OF FILE:    Led.h  
 ******************************************************************************/
