/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   LED_Ctrl.c
 *         \brief   APPLICATION FOR LED CONTROL
 *       \details   __________________________
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Delay.h" 
#include "Led_Ctrl.h"
#include "Led.h"
#include "Switch.h"

/*******************************************************************************
 *  LOCAL MACROS
 ******************************************************************************/
#define ON                      1
#define OFF                     0

/*******************************************************************************
 *  GLOBAL DATA
 ******************************************************************************/
volatile static uint8 x;
volatile static uint8 Press;
volatile static uint8 Blink;
volatile static uint8 State[2];

/*******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/
void LED_Sw1ISR(void);
void LED_Sw2ISR(void); 
void LED_DelayISR(void);
 /*******************************************************************************
 * \syntax          : void LED_Ctrl(void)
 * \Description     : Toggeling The LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void LED_Ctrl(void)
	{
    LED_Delay_Timer_Init(LED_DelayISR);
    LED_SwCB(S1, LED_Sw1ISR);
    LED_SwCB(S2, LED_Sw2ISR);

    static uint8 i = 0;
    static uint8 t = 0;

    State[ON]  = 1;
    State[OFF] = 1;

    t = State[ON];

    LED_ON(LED_BLUE);
    Delay_ms(1000);

    while(1)
			{
				
        if((x / t) == 1)
				{
            LED_Tgl(LED_BLUE);
            t = State[i++];
            i &= 1;
            x = 0;
        }
				
    }
}
 /*******************************************************************************
 *  LOCAL FUNCTIONS
 ******************************************************************************/
void LED_Sw2ISR(void){
    Blink++;
	Blink &= 1;
	if(Press){
		State[Blink] = Press;
		Press = 0;
	}
} 
void LED_Sw1ISR(void)
{
    Press++;
}

 void LED_DelayISR(void)
{
    ++x;
    x %= 100;
}
/*******************************************************************************
 *  END OF FILE:    LED_Ctrl.c
 ******************************************************************************/
