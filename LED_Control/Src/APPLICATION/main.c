/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   main.c
 *         \brief   Main file for application (LED CONTROL)
 *         
 *       \details   -
 ******************************************************************************/
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "IntCtrl.h"
#include "Port.h"
#include "Led_Ctrl.h"
/*******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/
void INIT(void);
/*******************************************************************************
 *  LOCAL FUNCTIONS
 ******************************************************************************/
void INIT(void){
	Int_CtrlInit();
	GPIO_Init();
}
/*******************************************************************************
 * \syntax          : int main()
 * \Description     : Main fn of the application 
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
int main(){
	INIT();
	LED_Ctrl();
    while(1)
		{
		}
    return 0;
}
/*******************************************************************************
 *  END OF FILE:    main.c
 ******************************************************************************/
