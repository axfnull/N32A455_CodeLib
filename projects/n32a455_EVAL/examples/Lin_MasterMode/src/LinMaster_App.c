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
#include "LinTrans.h"
/**
 *  Data Struct define
 */
 #define LinMaster_ScheduleNUM  2 
 uint8_t LinAPP_Testdata[8];
 uint8_t LinAPP_Testdata1[8] = {1, 2, 3, 4,5,6,7,8}; 
typedef enum
{
   LinSche_Init = 0,
   LinSche_Idle,
   LinSche_WaitResponse,
   LinSche_Sleep,
} LinWorkStatesType;
LinWorkStatesType LinMasterWorkStates = LinSche_Init;
typedef struct
{
	uint8_t       LinID;
	uint8_t*      LinData;
	LinErroMess   ErroMess;
	LinTransType  TransType;
	uint8_t       LinErroTimer;//
	uint16_t      ScheduleCycle;
	uint16_t      ScheduleTimer; 
} LinAppInfoType;

LinAppInfoType	LinMaster_ScheduleTab[LinMaster_ScheduleNUM] = {

{0x02,&LinAPP_Testdata[0],    NO_Erro,  TransHeader,   0x00, 10, 0},     
{0x01,&LinAPP_Testdata1[0],   NO_Erro,  TransData,     0x00, 10, 0}
  
};
/**
 * Functon define
 */
void LinMaster_Schedule(void) 
{
   static uint8_t ScheduleTab_Index = 0;
   switch(LinMasterWorkStates)
   {
        case LinSche_Init:
			  LinDriv_init();
			  LinMasterWorkStates = LinSche_Idle;
		break;
		case LinSche_Idle:
			 LinMaster_ScheduleTab[ScheduleTab_Index].ScheduleTimer++;
			 if(LinMaster_ScheduleTab[ScheduleTab_Index].ScheduleTimer >= 
			       LinMaster_ScheduleTab[ScheduleTab_Index].ScheduleCycle)
			 {
          LinMaster_ScheduleTab[ScheduleTab_Index].ScheduleTimer = 0;
			    LinTrans_StartTrans(LinMaster_ScheduleTab[ScheduleTab_Index].TransType,LinMaster_ScheduleTab[ScheduleTab_Index].LinID,LinMaster_ScheduleTab[ScheduleTab_Index].LinData);
			    LinMasterWorkStates = LinSche_WaitResponse;
			 }
			 else{;}
		break;
		case LinSche_WaitResponse:
			LinMaster_ScheduleTab[ScheduleTab_Index].LinErroTimer++;
			 if((TransHeader == LinMaster_ScheduleTab[ScheduleTab_Index].TransType)
			 	 &&(0 == LinDriver_GetRxStates()))
			 {
          LinTrans_CheckResData(LinMaster_ScheduleTab[ScheduleTab_Index].LinData,&LinMaster_ScheduleTab[ScheduleTab_Index].ErroMess);
				  LinMaster_ScheduleTab[ScheduleTab_Index].LinErroTimer = 0;
				  ScheduleTab_Index++;
				  if(ScheduleTab_Index >= LinMaster_ScheduleNUM)
				  {
                     ScheduleTab_Index = 0;
				  }
				  else{;}
				  LinMasterWorkStates = LinSche_Idle;
			 }
			 else if((TransData == LinMaster_ScheduleTab[ScheduleTab_Index].TransType)
			 	 &&(0 == LinDriver_GetTxStates()))
			 {
				  LinMaster_ScheduleTab[ScheduleTab_Index].LinErroTimer = 0;	
				  ScheduleTab_Index++;
				  if(ScheduleTab_Index >= LinMaster_ScheduleNUM)
				  {
                     ScheduleTab_Index = 0;
				  }
				  else{;}
				  LinMasterWorkStates = LinSche_Idle;				  
			 }	
			 else if(LinMaster_ScheduleTab[ScheduleTab_Index].LinErroTimer >= 10)	
			 {
			      LinMaster_ScheduleTab[ScheduleTab_Index].LinErroTimer = 0; 
				  LinMaster_ScheduleTab[ScheduleTab_Index].ErroMess = ResponsTimerout;
			      ScheduleTab_Index++;
			     if(ScheduleTab_Index >= LinMaster_ScheduleNUM)
			     {
				   ScheduleTab_Index = 0;
			     }
			     else{;}
			     LinMasterWorkStates = LinSche_Idle;
			 }
			 else{;}
		break;
		default:
            LinMasterWorkStates = LinSche_Init;
        break;
   }
}


