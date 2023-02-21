/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/


#include "n32a455.h"
#include "system_n32a455.h"
#include <stdint.h>
#include "LinProtocolDefine.h"
/**
 *  Data Struct define
 */


/**
 *  Functon define
 */
void Mem_Copy ( uint8_t *p_des, volatile uint8_t *p_src, uint16_t length )
{
    uint16_t i;
    for(i = 0; i < length; i++)
    {
        *(p_des + i) = *(p_src + i);
    }
}
void Mem_Fill (uint8_t *p_buff, uint16_t len, uint8_t fill_data)
{
    while (len--)
    {
        *(p_buff++) = fill_data;
    }
}

LinErroMess LinProtocol_GeneratPID(uint8_t ID,uint8_t* PID)
{
   LinErroMess TempReturnvalue = PID_Erro;
   uint8_t p0,p1;
   *PID = 0;
	if(!(ID & 0xC0))
    {
      p0 = (ID & 0x01)^((ID & 0x02) >> 1)^((ID & 0x04) >> 2)^((ID & 0x10) >> 4); //°´Î»Òì»ò
      p0 = p0 & 0x01;
	    p1 = ~(((ID & 0x02) >> 1)^((ID & 0x08) >> 3)^((ID & 0x10) >> 4)^((ID & 0x20) >> 5));
      p1 = p1 & 0x01;
      *PID = (p1 << 7) | (p0 << 6) | ID;
	  TempReturnvalue = NO_Erro;
	}
	else{;}
	return(TempReturnvalue);
}

void LinProtocol_GeneratENSum(uint8_t PID,uint8_t* data,uint8_t* sumdata)
{
   uint16_t tempsumdata = 0;
   uint8_t i,Tempdata;
   tempsumdata = PID;
   for(i = 0;i < 8;i++)
   {
     tempsumdata += data[i];
	 Tempdata = ((tempsumdata & 0x0100)>>8);
	 tempsumdata = (tempsumdata & 0x00FF);
	 tempsumdata += Tempdata;
   }
   Tempdata = (tempsumdata & 0x00FF);
   *sumdata = 0xFF - Tempdata;
   
}
/*static LinProtocol_CheckSyncField(*data)
{

}
static LinProtocol_CheckPID(ID)
{

}
static LinProtocol_GeneratCLSum(*data)
{

}
static LinProtocol_CheckCLSum(*data)
{

}*/






