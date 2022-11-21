/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   Port.c
 *         \brief   Driver for GPIO Port module.
 *         
 *       \details   -
 *****************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
#include "Port_Cfg.h"
#include "Port.h"
/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/
extern GPIO_CfgType CfgPtr[];
static Port_IntHandlerType (*Port_IntHandlers[])() = 
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
/******************************************************************************
 * \syntax          : void GPIO_Init(void)
 * \Description     : Configures GPIO pins
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_Init(void){
    uint8 i;
    uint32 GPIOS[] = {GPIO_A_BASE_ADDRESS, GPIO_B_BASE_ADDRESS, GPIO_C_BASE_ADDRESS, GPIO_D_BASE_ADDRESS, GPIO_E_BASE_ADDRESS, GPIO_F_BASE_ADDRESS};

    for(i=0; i<GPIO_PortNumPins; i++){
     
        uint32 Port = GPIOS[(CfgPtr[i].PINType / 8)];
        uint8 Pin   = (CfgPtr[i].PINType % 8);
        
       
        SetBit(R(SYSCTL_BASE_ADDRESS , RCGCGPIO), (CfgPtr[i].PINType / 8));

     
        switch(CfgPtr[i].PINDINPUT){
            case IN:
                ResetBit(R(Port, GPIODIR), Pin);
            break;

            case OUT:
                SetBit(R(Port, GPIODIR), Pin);
                
       
                switch(CfgPtr[i].PinOutCurr){
                    case MA_2:
                        SetBit(R(Port, GPIODR2R), Pin);
                    break;

                    case MA_4:
                        SetBit(R(Port, GPIODR4R), Pin);
                    break;

                    case MA_8:
                        SetBit(R(Port, GPIODR8R), Pin);
                    break;

                    case MA_8_WSLR:
                        SetBit(R(Port, GPIODR8R), Pin);
                        SetBit(R(Port, GPIOSLR), Pin);
                    break;

                    default:
                    break;
                }
            break;

            default:
            break;
        }

        
        if(!GetBit(R(Port, GPIOCR), Pin)){
            R(Port, GPIOLOCK) = 0x4C4F434Bu;
            SetBit(R(Port, GPIOCR), Pin);
        }

 
        switch(CfgPtr[i].PinAttIntr){
            case PullUp:
                SetBit(R(Port, GPIOPUR), Pin);
            break;

            case PullDown:
                SetBit(R(Port, GPIOPDR), Pin);
            break;

            case OpenDrin:
                SetBit(R(Port, GPIOODR), Pin);
            break;

            default:
            break;
        }

       
        switch(CfgPtr[i].GPIO_PinMode){
            case DigitalIO:
                SetBit(R(Port, GPIODEN), Pin);   
            break;

            case AnalogIN:
                ResetBit(R(Port, GPIODIR), Pin);
                SetBit(R(Port, GPIOAMSEL), Pin);
            break;

            case AlternativeFun:
                SetBit(R(Port, GPIOAFSEL), Pin);
                SetBit(R(Port, GPIODEN), Pin);
            break;
            default:
                ResetBit(R(Port, GPIODIR), Pin);
                SetBit(R(Port, GPIODEN), Pin);
                ResetBit(R(Port, GPIOIM), Pin);
                
                switch(CfgPtr[i].PinIntTri){
                    case Lvltri:
                        SetBit(R(Port, GPIOIS), Pin);
                    break;

                    case OneEdge:
                        ResetBit(R(Port, GPIOIS), Pin);
                        ResetBit(R(Port, GPIOIBE), Pin);
                    break;

                    case TwoEdges:
                        ResetBit(R(Port, GPIOIS), Pin);
                        SetBit(R(Port, GPIOIBE), Pin);
                    break;

                    default:
                    break;
                }

                switch(CfgPtr[i].PINEdge){
                    case FALL:
                        ResetBit(R(Port, GPIOIEV), Pin);
                    break;

                    case RISE:
                        SetBit(R(Port, GPIOIEV), Pin);
                    break;

                    default:
                    break;
                }

                if(CfgPtr[i].GPIO_PinMode == GPIO_ADCTrig){
                    SetBit(R(Port, GPIOADCCTL), Pin);
                }

                else if(CfgPtr[i].GPIO_PinMode == GPIO_DMATrig){
                    SetBit(R(Port, GPIODMACTL), Pin);
                }

                SetBit(R(Port, GPIOIM), Pin);
            break;
        }

    }
}
/******************************************************************************
 * \syntax          : void GPIO_A_INT(void)
 * \Description     : Port A interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOA_Handler(void){
    uint8 IntStat = R(GPIO_A_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i]))();
            SetBit(R(GPIO_A_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}
/******************************************************************************
 * \syntax          : void GPIO_B_INT(void)
 * \Description     : Port B interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOB_Handler(void){
    uint8 IntStat = R(GPIO_B_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i+8]))();
            SetBit(R(GPIO_B_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}
/******************************************************************************
 * \syntax          : void GPIO_C_INT(void)
 * \Description     : Port C interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOC_Handler(void){
    uint8 IntStat = R(GPIO_C_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i+16]))();
            SetBit(R(GPIO_C_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIO_D_INT(void)
 * \Description     : Port D interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOD_Handler(void){
    uint8 IntStat = R(GPIO_D_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i+24]))();
            SetBit(R(GPIO_D_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIO_E_INT(void)
 * \Description     : Port E interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOE_Handler(void){
    uint8 IntStat = R(GPIO_E_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i+32]))();
            SetBit(R(GPIO_E_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIO_F_INT(void)
 * \Description     : Port F interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOF_Handler(void){
    uint8 IntStat = R(GPIO_F_BASE_ADDRESS, GPIOMIS);
    uint8 i = 0;
    while(IntStat){
        if(IntStat & 1){
            (*(Port_IntHandlers[i+40]))();
            SetBit(R(GPIO_F_BASE_ADDRESS, GPIOICR), i);
            break;
        }
        IntStat >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIO_SetCB(GPIO_PINType Pin, 
 *                                          Port_IntHandlerType (*CB)())
 * \Description     : Sets the corresponding CB function
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : GPIO_PINType Pin
 *                    Port_IntHandlerType (*CB)
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIO_SetCB(GPIO_TypePin Pin, Port_IntHandlerType (*CB)()){
    Port_IntHandlers[Pin] = CB;
}

/******************************************************************************
 *  END OF FILE:    Port.c
 *****************************************************************************/
