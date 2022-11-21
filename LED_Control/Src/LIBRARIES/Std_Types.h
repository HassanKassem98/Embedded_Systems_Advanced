/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Std_Types.h  
 *       MODULE:   -
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdint.h>

/******************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************/
#define FALSE                           0u
#define TRUE                            1u

#define LOW                             0u
#define HIGH                            1u

#define SetBit(Register, Pin)               (Register |=  (1 << Pin))
#define ResetBit(Register, Pin)             (Register &= ~(1 << Pin))
#define GetBit(Register, Pin)               (Register &   (1 << Pin))
#define TglBit(Register, Pin)            	(Register ^=  (1 << Pin))

#define SetVal(Register, Pin, Val)        (Register |=  (Val << Pin))
#define ResetVal(Register, Pin, Val)      (Register &= ~(Val << Pin))
#define GetVal(Register, Pin, Val)        (Register &   (Val << Pin))
#define TglVal(Register, Pin)            (Register ^=  (Val << Pin))

#define NULL                            ((void *)0)

/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef signed char                     int8;
typedef short                           int16;
typedef int                             int32;
typedef long long                       int64;
typedef unsigned char                   uint8;
typedef unsigned short                  uint16;
typedef unsigned int                    uint32;
typedef unsigned long long              uint64;

#endif  /* STD_TYPES_H */

/******************************************************************************
 *  END OF FILE:    Std_Types.h  
 *****************************************************************************/
