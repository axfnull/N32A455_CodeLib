
/**
 * @file main.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */
#include <stdio.h>
#include "n32a455_SysTick.h"
#include "LinMaster_App.h"
/**
 * @brief  Main program
 */

int main(void)
{
  n32a455_SystickConfig();  
  while (1)
  {
	if(Sys_TimerFlag.BITS.Task1msFlag)
	{//1ms task
	  Sys_TimerFlag.BITS.Task1msFlag = 0;
	  LinMaster_Schedule();
	}
	else{;}
  }
}
