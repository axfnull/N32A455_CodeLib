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
 * @file n32a455_sm1.h
 * @author Nations Solution Team
 * @version v1.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */
#ifndef __N32A455_SM1_H__
#define __N32A455_SM1_H__

#include <stdint.h>
/** @addtogroup N32A455_Algorithm_Library
 * @{
 */

/** @addtogroup SM1
 * @brief SM1 symmetrical cipher algorithm
 * @{
 */


#define SM1_ECB (0x11111111)
#define SM1_CBC (0x22222222)

#define SM1_ENC  (0x44444444)
#define SM1_DEC  (0x55555555)

enum
{
  SM1_Crypto_OK = 0x0,		//SM1 opreation success
	SM1_Init_OK = 0x0,		//SM1 opreation success
	SM1_Crypto_ModeError = 0x5a5a5a5a,		//Working mode error(Neither ECB nor CBC)
	SM1_Crypto_EnOrDeError,		//En&De error(Neither encryption nor decryption)
	SM1_Crypto_ParaNull,		// the part of input(output/iv) Null
	SM1_Crypto_LengthError,		//the length of input message must be 4 times and cannot be zero
	SM1_UnInitError,   //SM1 uninitialized
};

typedef struct
{
		uint32_t *in;		// the part of input 
		uint32_t *iv;		// the part of initial vector
		uint32_t *out;		// the part of output
		uint32_t *key;		// the part of key
		uint32_t inWordLen;	// the length(by word) of plaintext or cipher
		uint32_t En_De;	// 0x44444444- encrypt, 0x55555555 - decrypt
		uint32_t Mode;  // 0x11111111 - ECB, 0x22222222 - CBC
}SM1_PARM;

 /**
 * @brief SM1_Init
 * @return SM1_Init_OK, SM1_Init success; othets: SM1_Init fail
 * @note    
 */
uint32_t SM1_Init(SM1_PARM *parm);
/**
 * @brief SM1 crypto
 * @param[in] parm pointer to SM1 context and the detail please refer to struct SM1_PARM in SM1.h
 * @return SM1_Crypto_OK, SM1 crypto success; othets: SM1 crypto fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 *        2.Input and output can be the same buffer
 *        3. IV can be NULL when ECB mode
 *        4. The word lengrh of message must be as times as 4.
 *        5. If the input is in byte, make sure align by word.
 */
uint32_t SM1_Crypto(SM1_PARM *parm);

/**
 * @brief SM1 close
 * @return none
 * @note  if you want to close SM1 algorithm, this function can be recalled.  
 */
void SM1_Close(void);

/**
 * @brief Get SM1 lib version
 * @param[out] type pointer one byte type information represents the type of the lib, like Commercial version.\
 * @Bits 0~4 stands for Commercial (C), Security (S), Normal (N), Evaluation (E), Test (T), Bits 5~7 are reserved. e.g. 0x09 stands for CE version.
 * @param[out] customer pointer one byte customer information represents customer ID. for example, 0x00 stands for standard version, 0x01 is for Tianyu customized version...
 * @param[out] date pointer array which include three bytes date information. If the returned bytes are 18,9,13,this denotes September 13,2018 
 * @param[out] version pointer one byte version information represents develop version of the lib. e.g. 0x12 denotes version 1.2.
 * @return none
 * @1.You can recall this function to get SM1 lib information
 */
void SM1_Version(uint8_t *type, uint8_t *customer, uint8_t date[3], uint8_t *version);

#endif


