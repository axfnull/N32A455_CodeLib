/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/

#include <stdio.h>
#include "n32a455.h"
#include "system_n32a455.h"

#include "LinProtocolDefine.h"
#include "LinProtocol.h"
#include "n32a455_LinDriver.h"

/**
 *  Data Struct define
 */

Lin_ProtocolInfo LinTransFram;

/**
 * Functon define
 */
void LinTrans_Init(void)
{
   Mem_Fill(LinTransFram.LIN_Header,2,0x00);
   Mem_Fill(LinTransFram.LIN_Data,9,0x00);
   LinTransFram.LinTransType = TransIdle;
   LinTransFram.LinTransStates = NO_Erro;
}


void LinTrans_CheckResData(uint8_t* data,LinErroMess* MESS)
{
  uint8_t tempdata[12];
  uint8_t tempcheckdata;
  LinDriver_GetRxInfo(tempdata);
  *MESS = SyncField_Erro;
  LinProtocol_GeneratENSum(LinTransFram.LIN_Header[1],&tempdata[3],&tempcheckdata);
  if(tempcheckdata == tempdata[11])
  {
    *MESS = DataFresh;
	 Mem_Copy(data,&tempdata[3],8);
  }
  else{;}

}
void LinTrans_StartTrans(LinTransType TransType,uint8_t ID,uint8_t* data) 
{
   LinErroMess TempValue = NO_Erro;
   LinTransFram.LIN_Header[0] = 0x55;
   //Generate and check Pid
   TempValue = LinProtocol_GeneratPID(ID,&LinTransFram.LIN_Header[1]);//
   if((NO_Erro == TempValue)
   	   &&(TransHeader == TransType))
   {
      LinTransFram.LinTransType = TransHeader;
	    LinDriver_SendBreak();
      LinDriver_TransPro(LinTransFram.LIN_Header[1],TransType,NULL);
   }
   else if((NO_Erro == TempValue)
   	        &&(TransData == TransType))
   {
      Mem_Copy(LinTransFram.LIN_Data,data,8);
	  LinProtocol_GeneratENSum(LinTransFram.LIN_Header[1],data,&LinTransFram.LIN_Data[8]);//Generate ENSUM
      LinTransFram.LinTransType = TransData;
	  LinDriver_SendBreak();
      LinDriver_TransPro(LinTransFram.LIN_Header[1],TransType,&LinTransFram.LIN_Data[0]);
   }
   else{;}
}


