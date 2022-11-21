/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   Led.c
 *         \brief   Driver for LED module
 *         
 *       \details   -
 ******************************************************************************/
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Dio.h"
#include "Led.h"
/*******************************************************************************
 * \syntax          : void LED_OFF(LED_InstType LED_Ch)
 * \Description     : Turns off the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_OFF(LED_InstType LED_Ch){
    GPIO_WriteCh(LED_Ch, LOW);
}
/*******************************************************************************
 * \syntax          : void LED_ON(LED_InstType LED_Ch)
 * \Description     : Turns on the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_ON(LED_InstType LED_Ch){
    GPIO_WriteCh(LED_Ch, HIGH);
}
/*******************************************************************************
 * \syntax          : void LED_Tgl(LED_InstType LED_Ch)
 * \Description     : Toggles the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : LED_InstType LED_Ch
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Tgl(LED_InstType LED_Ch){
    GPIO_FlipCh(LED_Ch);
}
/*******************************************************************************
 *  END OF FILE:    Led.c
 ******************************************************************************/
