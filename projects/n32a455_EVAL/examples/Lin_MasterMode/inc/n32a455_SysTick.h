/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/


#ifndef  __N32AG455_SYSTICK_H__
#define  __N32AG455_SYSTICK_H__

#include <stdint.h>
typedef union
{
	uint8_t status;
    struct
	{
		uint8_t Task1msFlag   :1;	//bit1
		uint8_t Task3msFlag   :1;	//bit2
		uint8_t Task4msFlag   :1;	//bit3
		uint8_t Task10msFlag  :1;	//bit4
		uint8_t bit5          :1;	//bit5
		uint8_t bit6          :1;	//bit6
		uint8_t bit7	      :1;	//bit7
		uint8_t bit8	      :1;	//bit8
	}BITS;
}TYPE_SystemTimerService;
extern TYPE_SystemTimerService Sys_TimerFlag;
extern void n32a455_SystickConfig(void);
#endif
