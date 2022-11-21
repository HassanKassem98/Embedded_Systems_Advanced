/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   LED_Ctrl.h  
 *       MODULE:   Led Control
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef LED_Ctrl_H
#define LED_Ctrl_H
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
 * \syntax          : void LED_Ctrl(void)
 * \Description     : Toggles an LED after for given ON and OFF time
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Ctrl(void);
#endif  /* LED_Ctrl_H */
/*******************************************************************************
 *  END OF FILE:    LED_Ctrl.h  
 ******************************************************************************/