/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/

#ifndef _LINTRANS_H_
#define _LINTRANS_H_
#include "LinProtocolDefine.h"
//--------------------------------------º¯ÊýÉùÃ÷------------------------------------------//
extern void LinTrans_CheckResData(uint8_t* data,LinErroMess* MESS);
extern void LinTrans_StartTrans(LinTransType TransType,uint8_t ID,uint8_t* data);
#endif
