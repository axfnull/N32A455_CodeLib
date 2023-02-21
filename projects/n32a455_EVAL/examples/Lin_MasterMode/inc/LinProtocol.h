/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/

#ifndef _LINPROTOCOL_H_
#define _LINPROTOCOL_H_
#include <stdint.h>
//--------------------------------------º¯ÊýÉùÃ÷------------------------------------------//
extern void Mem_Copy ( uint8_t *p_des, volatile uint8_t *p_src, uint16_t length );
extern void Mem_Fill (uint8_t *p_buff, uint16_t len, uint8_t fill_data);
extern void LinProtocol_GeneratENSum(uint8_t PID,uint8_t* data,uint8_t* sumdata);
extern LinErroMess LinProtocol_GeneratPID(uint8_t ID,uint8_t* PID);


#endif
