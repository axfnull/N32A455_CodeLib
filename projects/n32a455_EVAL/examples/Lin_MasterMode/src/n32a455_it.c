/*****************************************************************************
 * Copyright (c) 2022, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file n32a455_it.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */
#include "n32a455_it.h"
#include "n32a455_SysTick.h"
#include "n32a455_LinDriver.h"
/** @addtogroup N32A455_StdPeriph_Template
 * @{
 */

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Memory Manage exception.
 */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Bus Fault exception.
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Usage Fault exception.
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles SVCall exception.
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 */
void SysTick_Handler(void)
{
	static uint32_t Mcal_Systime = 0;
	 Sys_TimerFlag.BITS.Task1msFlag=1;
	 Mcal_Systime++;
   if(Mcal_Systime >= 10)
   {
	   Mcal_Systime = 0;
	   Sys_TimerFlag.BITS.Task10msFlag = 1;
   }
}
/**
 * @brief  This function handles USARTy global interrupt request.
 */
void USARTLin_IRQHandler(void)
{
   if (USART_GetIntStatus(USARTLin, USART_INT_RXDNE) != RESET)
   {
       LinDriver_RxBuff.RxData[LinDriver_RxBuff.Lenth] = USART_ReceiveData(USARTLin);
       LinDriver_RxBuff.Lenth++;
       if (LinDriver_RxBuff.Lenth >= LinDriver_RxBuff.LenthMax)
       {
          LinDriver_RxBuff.RxStates = 0;  
					USART_ConfigInt(USARTLin, USART_INT_RXDNE, DISABLE);/* Disable the USARTz Receive interrupt */
       }
			else{;}
   }
	 else{;} 
	 if (USART_GetIntStatus(USARTLin, USART_INT_TXDE) != RESET)
    {
        USART_SendData(USARTLin, LinDriver_TxBuff.TxData[LinDriver_TxBuff.Lenth]);
		    LinDriver_TxBuff.Lenth++;
        if (LinDriver_TxBuff.Lenth >= LinDriver_TxBuff.LenthMax)
        {
			    LinDriver_TxBuff.TxStates = 0;
			    USART_ConfigInt(USARTLin, USART_INT_TXDE, DISABLE);/* Disable the USARTLin Transmit interrupt */
        }
				else{;}
    }
	  else{;}
}
