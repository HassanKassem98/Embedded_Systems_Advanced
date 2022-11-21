/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Port.h  
 *       MODULE:   Port
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef PORT_H
#define PORT_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Port_Types.h"
/******************************************************************************
 * \syntax          : void GPIO_Init(void)
 * \Description     : Configures GPIO pins functionalities
 * \Sync\Async      : Synchronos
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_Init(void);

/******************************************************************************
 * \syntax          : void GPIO_A_INT(void)
 * \Description     : Port A interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOA_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_B_INT(void)
 * \Description     : Port B interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOB_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_C_INT(void)
 * \Description     : Port C interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOC_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_D_INT(void)
 * \Description     : Port D interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOD_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_E_INT(void)
 * \Description     : Port E interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOE_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_F_INT(void)
 * \Description     : Port F interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOF_Handler(void);

/******************************************************************************
 * \syntax          : void GPIO_SetCB(GPIO_TypePin Pin, 
 *                                          Port_IntHandlerType (*CB)())
 * \Description     : Sets the corresponding CB function
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : GPIO_TypePin Pin
 *                    Port_IntHandlerType (*CB)
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_SetCB(GPIO_TypePin Pin, Port_IntHandlerType (*CB)());

#endif  /* PORT_H */

/******************************************************************************
 *  END OF FILE:    Port.h  
 *****************************************************************************/
