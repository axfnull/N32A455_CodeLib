

/**
 * @file n32a455_LinDriver.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */

#include "LinProtocolDefine.h"
#include "n32a455_LinDriver.h"
#include "n32a455.h"
#include "LinProtocol.h"
#include "LinProtocolDefine.h"

/**
 * Variable define
 */
LinDriver_TxBuffType LinDriver_TxBuff;
LinDriver_RxBuffType LinDriver_RxBuff;
/**
 * Functon define
 */

void LinDriv_init(void)
{
  	NVIC_InitType NVIC_InitStructure;
    GPIO_InitType GPIO_InitStructure;
	  USART_InitType USART_InitStructure;
   	/* Enable GPIO and USARTLin clock */
    RCC_EnableAPB2PeriphClk(USARTLin_GPIO_CLK | USARTLin_GPIO_CLK | RCC_APB2_PERIPH_AFIO, ENABLE);
    USARTLin_APBxClkCmd(USARTLin_CLK, ENABLE);
    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USARTLin Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel            = USARTLin_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd         = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Configure USARTLin Rx as input floating */
    GPIO_InitStructure.Pin       = USARTLin_RxPin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitPeripheral(USARTLin_GPIO, &GPIO_InitStructure);
    /* Configure USARTLin Tx as alternate function push-pull */
    GPIO_InitStructure.Pin        = USARTLin_TxPin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitPeripheral(USARTLin_GPIO, &GPIO_InitStructure);
	/* USARTLin configuration ------------------------------------------------------*/
    USART_InitStructure.BaudRate            = 19200;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure.Mode                = USART_MODE_RX | USART_MODE_TX;

    /* Configure USARTLin */
    USART_Init(USARTLin, &USART_InitStructure);
    USART_EnableLIN(USARTLin, ENABLE);
		
    /* Disable USARTLin Receive and Transmit interrupts */
    USART_ConfigInt(USARTLin, USART_INT_RXDNE, DISABLE);
    USART_ConfigInt(USARTLin, USART_INT_TXDE, DISABLE);
    /* Enable the USARTLin */
    USART_Enable(USARTLin, ENABLE);
}
void LinDriver_SendBreak(void)
{
    USART_SendBreak(USARTLin);
}
void LinDriver_TransPro(uint8_t PID,LinTransType TransType,uint8_t* data)
{
  LinDriver_TxBuff.TxData[0] = 0x55;
	LinDriver_TxBuff.TxData[1] = PID;
	if(TransType == TransHeader)
	{
    LinDriver_TxBuff.LenthMax = 2;
	  LinDriver_TxBuff.Lenth = 0;
	  LinDriver_TxBuff.TxStates = 1;
	  Mem_Fill(LinDriver_RxBuff.RxData,15,0x00);//Clear RXbuff
	  LinDriver_RxBuff.LenthMax = 12;
	  LinDriver_RxBuff.Lenth = 0; 
	  LinDriver_RxBuff.RxStates = 1; 	  
	  USART_ConfigInt(USARTLin, USART_INT_RXDNE, ENABLE);//ENABLE tx,rx interrupt
      USART_ConfigInt(USARTLin, USART_INT_TXDE, ENABLE);
	}
	else if(TransType == TransData)
	{
    LinDriver_TxBuff.LenthMax = 11;
	  LinDriver_TxBuff.Lenth = 0;
	  LinDriver_TxBuff.TxStates = 1;
	  Mem_Copy(&LinDriver_TxBuff.TxData[2],data,9);
    USART_ConfigInt(USARTLin, USART_INT_TXDE, ENABLE);
	}
	else{;}
}

void LinDriver_GetRxInfo(uint8_t* data)
{
    Mem_Copy(data,LinDriver_RxBuff.RxData,12);
}
uint8_t LinDriver_GetRxStates(void)
{
    return(LinDriver_RxBuff.RxStates);
}
uint8_t LinDriver_GetTxStates(void)
{
    return(LinDriver_TxBuff.TxStates);
}

/*
void LinDriver_Sleep(void)
{
   ;
}
*/



