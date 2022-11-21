/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Port_Types.h  
 *       MODULE:   Port
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef void Port_IntHandlerType;

typedef enum {
    NO_ATTACHMENT,
    PullUp,
    PullDown,
    OpenDrin
} GPIO_PinIntAttType;

typedef enum {
    NoLvl,
    LowLvl,
    HighLvl,
    FALL = 1,
    RISE
} GPIO_PinEdgType;

typedef enum {
    /* PORT A*/
    PinA0,
    PinA1,
    PinA2,
    PinA3,
    PinA4,
    PinA5,
    PinA6,
    PinA7,
    /* PORT B*/
    PinB0,
    PinB1,
    PinB2,
    PinB3,
    PinB4,
    PinB5,
    PinB6,
    PinB7,
    /* PORT C*/
    PinC0,
    PinC1,
    PinC2,
    PinC3,
    PinC4,
    PinC5,
    PinC6,
    PinC7,
    /* PORT D*/
    PinD0,
    PinD1,
    PinD2,
    PinD3,
    PinD4,
    PinD5,
    PinD6,
    PinD7,
    /* PORT E*/
    PinE0,
    PinE1,
    PinE2,
    PinE3,
    PinE4,
    PinE5,
    PinE6,
    PinE7,
    /* PORT F*/
    PinF0,
    PinF1,
    PinF2,
    PinF3,
    PinF4,
    PinF5,
    PinF6,
    PinF7
} GPIO_TypePin;

typedef enum {
    IN,
    OUT
} GPIO_PinDir;

typedef enum {
    DigitalIO,
    EXT_INT,
    GPIO_ADCTrig,
    GPIO_DMATrig,
    AnalogIN,
    AlternativeFun
} GPIO_PinModeType;

typedef enum {
    NoCurrent,
    MA_2,
    MA_4,
    MA_8,
    MA_8_WSLR
} GPIO_PinOutCurrType;

typedef enum {
    NoTgr,
    Lvltri,
    OneEdge,
    TwoEdges
} GPIO_PinIntTrigType;
typedef struct {
    GPIO_TypePin PINType;
    GPIO_PinModeType GPIO_PinMode;
    GPIO_PinDir PINDINPUT;
    GPIO_PinIntAttType PinAttIntr;
    GPIO_PinOutCurrType PinOutCurr;
    GPIO_PinIntTrigType PinIntTri;
    GPIO_PinEdgType PINEdge;
} GPIO_CfgType;

#endif  /* PORT_TYPES_H */

/******************************************************************************
 *  END OF FILE:    Port_Types.h  
 *****************************************************************************/
