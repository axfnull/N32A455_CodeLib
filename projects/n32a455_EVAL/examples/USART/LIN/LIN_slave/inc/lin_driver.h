/**
  ******************************************************************************
  * @file
  * $Author:
  * $Revision:
  * $Date::
  * @brief
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LIN_DRIVER_H
#define _LIN_DRIVER_H
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

typedef void (*FUN_RESP)(uint8_t *pData, uint8_t Len); //命令回应函数指针

/* Exported Functions --------------------------------------------------------*/
#define GET_PID(data) ((data&0x3F)|((((data&0x01)^((data>>1)&0x01)^((data>>2)&0x01)^((data>>4)&0x01))&0x01)<<6)|(((~(((data>>1)&0x01)^((data>>3)&0x01)^((data>>4)&0x01)^((data>>5)&0x01)))&0x01)<<7))
#define ID_TYPE_SR  0
#define ID_TYPE_SW  1
//定义数据收发的帧ID，必须跟上位机软件配置一致，否则无法正常工作。
//对于LIN总线，数据收发ID可以定义为一个ID，也可以定义为不同的ID
#define MSG_RECEIVE_ID  0x3C
#define MSG_SEND_ID     0x3D
//定义数据校验类型，0-标准校验，1-增强校验，仅用于LIN升级
#define CHECK_TYPE   0
//固件类型值定义
#define FW_TYPE_BOOT     0x55
#define FW_TYPE_APP      0xAA
//定义当前固件类型为BOOT
#define FW_TYPE         FW_TYPE_APP

typedef enum
{
    IDLE,
    SYNCH,
    ID_LEN,
    DATA_GET,
    CHECKSUM
} LIN_STATE;

typedef struct _LIN_EX_MSG
{
    unsigned char DataLen;      //LIN数据段有效数据字节数
    unsigned char Sync;         //同步段0x55
    unsigned char PID;          //帧ID
    unsigned char Data[8];      //数据
    unsigned char Check;        //校验
} LIN_EX_MSG;
void LIN_Configuration(int BaudRate);
void LIN_SetResp(uint8_t ID, uint8_t *pData, uint8_t Len, uint8_t CheckType);
void LIN_IRQHandler(void);
void BOOT_ExecutiveCommand(uint8_t *pData, FUN_RESP pFunResp);

#endif /*_usart_H*/

/*********************************END OF FILE**********************************/
