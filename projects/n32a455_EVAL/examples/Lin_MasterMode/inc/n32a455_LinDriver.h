/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************/
#ifndef  __N32A455_SYSTICK_H__
#define  __N32A455_SYSTICK_H__

#include <stdint.h>
#include <stdio.h>
#include "LinProtocolDefine.h" 
/**
 * macro define
 */

#define USARTLin            USART1
#define USARTLin_GPIO       GPIOA
#define USARTLin_CLK        RCC_APB2_PERIPH_USART1
#define USARTLin_GPIO_CLK   RCC_APB2_PERIPH_GPIOA
#define USARTLin_RxPin      GPIO_PIN_10
#define USARTLin_TxPin      GPIO_PIN_9
#define USARTLin_APBxClkCmd RCC_EnableAPB2PeriphClk
#define USARTLin_IRQn       USART1_IRQn
#define USARTLin_IRQHandler USART1_IRQHandler

/**
 * Data structe define
 */
#define LinDriver_TxBufferSize 15
typedef struct
{
    uint8_t  TxData[LinDriver_TxBufferSize]; 
	uint8_t  Lenth;
	uint8_t  LenthMax;
	uint8_t  TxStates;
} LinDriver_TxBuffType;
#define LinDriver_RxBufferSize 15
typedef struct
{
    uint8_t  RxData[LinDriver_RxBufferSize]; 
	uint8_t  Lenth;
	uint8_t  LenthMax;
	uint8_t  RxStates;
} LinDriver_RxBuffType;

extern LinDriver_TxBuffType LinDriver_TxBuff;
extern LinDriver_RxBuffType LinDriver_RxBuff;
extern void LinDriv_init(void);
extern void LinDriver_SendBreak(void);
extern void LinDriver_TransPro(uint8_t PID,LinTransType TransType,uint8_t* data);
extern void LinDriver_GetRxInfo(uint8_t* data);
extern uint8_t LinDriver_GetRxStates(void);
extern uint8_t LinDriver_GetTxStates(void);


#endif
