/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Dio_Types.h  
 *       MODULE:   DIO driver
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Mcu_Hw.h"
/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef uint8 GPIO_LvlType;

typedef uint8 GPIO_PortLvlType;

typedef enum 
 {
    PORT_A = GPIO_A_BASE_ADDRESS,
    PORT_B = GPIO_B_BASE_ADDRESS,
    PORT_C = GPIO_C_BASE_ADDRESS,
    PORT_D = GPIO_D_BASE_ADDRESS,
    PORT_E = GPIO_E_BASE_ADDRESS,
    PORT_F = GPIO_F_BASE_ADDRESS
} GPIO_PortType;

typedef enum {
    /* PORT A*/
    PA0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,
    /* PORT B*/
    PB0,
    PB1,
    PB2,
    PB3,
    PB4,
    PB5,
    PB6,
    PB7,
    /* PORT C*/
    PC0,
    PC1,
    PC2,
    PC3,
    PC4,
    PC5,
    PC6,
    PC7,
    /* PORT D*/
    PD0,
    PD1,
    PD2,
    PD3,
    PD4,
    PD5,
    PD6,
    PD7,
    /* PORT E*/
    PE0,
    PE1,
    PE2,
    PE3,
    PE4,
    PE5,
    PE6,
    PE7,
    /* PORT F*/
    PF0,
    PF1,
    PF2,
    PF3,
    PF4,
    PF5,
    PF6,
    PF7
} GPIO_ChType;

#endif  /* DIO_TYPES_H */

/******************************************************************************
 *  END OF FILE:    Dio_Types.h  
 *****************************************************************************/
