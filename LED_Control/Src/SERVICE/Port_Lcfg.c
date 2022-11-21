/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   Port_Lcfg.c
 *         \brief   Configuration for PORT MODULE
 *         
 *       \details   -
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Port_Cfg.h"
/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/
#if(GPIO_PortNumPins)
GPIO_CfgType CfgPtr[GPIO_PortNumPins] = {
    {PinF2, DigitalIO, OUT, PullDown, MA_2, NoTgr, NoLvl},
    {PinF0, EXT_INT, IN, PullUp, NoCurrent, OneEdge, LowLvl},
    {PinF4, EXT_INT, IN, PullUp, NoCurrent, OneEdge, LowLvl}
};
#else
GPIO_CfgType *CfgPtr;
#endif
/******************************************************************************
 *  END OF FILE:    Port_Lcfg.c
 *****************************************************************************/
