
/**
 * @file n32a455_LinPotocolDefine.h
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#ifndef __LINPROTOCOLDEFINE_H__
#define __LINPROTOCOLDEFINE_H__
#include <stdint.h>

/**
 * Data structe define
 */
#define LinNull  uint8_t*(0) 

typedef enum
{
   TransIdle = 0,
   TransHeader,
   TransData,
   TransSpecialID
} LinTransType;
typedef enum
{
    NO_Erro = 0,
   	PID_Erro,
	Break_Erro,
	ResponsTimerout,
   	SyncField_Erro,
   	CheckDataField_Erro,
   	DataFresh
} LinErroMess;


typedef struct
{
    uint8_t  LIN_Header[2]; 
	uint8_t  LIN_Data[9];
	LinTransType  LinTransType;
	LinErroMess  LinTransStates;
} Lin_ProtocolInfo;




#endif 
