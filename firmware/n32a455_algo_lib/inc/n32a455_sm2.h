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
 * @file n32a455_sm2.h
 * @author Nations Solution Team
 * @version v1.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */

#ifndef _n32a455_sm2_H
#define _n32a455_sm2_H

#include "n32a455_rng.h"
#include "n32a455_hash.h"
#include "n32a455_algo_common.h"
#define SM2_WORDLEN 8
#define SM2_BYTELEN 32
#define SM2_BITLEN 256
 enum
{
	SM2_SUCCESS					= 0,
	SM2_DIV_OK					= 0,
	SM2_HCAL_OK					= 0,
	SM2_INIT_OK					= 0,
	SM2_MUL_OK					= 0,
	SM2_MODMUL_OK					= 0,
	SM2_Reverse_OK			= 0,
	SM2_SUB_OK					= 0,
	SM2_ADD_OK					= 0,
	SM2_Cpy_OK=0,//copy success
	SM2_XOR_OK=0,   //XOR success
	SM2_SetZero_OK = 0,
	SM2_isCurve_Ok = 0,
	SM2_isCurve_Not = 0x05,
	SM2_PointAdd_Ok =0,
	SM2_PointDouble_Ok = 0,
	SM2_PointMul_Ok = 0,
	SM2_Sign_Ok = 0,
	SM2_Verif_Ok = 0,
	SM2_En_Ok = 0,
	SM2_De_Ok = 0,
	SM2_Exchange_Ok = 0,
	SM2_FAIL					= 0x01,
	SM2_YES						= 0x02,
	SM2_NOT						= 0x03,
	ZERO_VALUE_ERROR = 0x04
};

enum{
	SM2_IsZero_NOT = 0, //Big number is not zero
	SM2_Cmp_EQUAL = 0, //Two big number are equal
	SM2_IsOne_NOT = 0,//big number is one
	SM2_IsOne_YES = 1,//big number is not one
	SM2_IsZero_YES = 1, //Big number is zero
	SM2_Cmp_LESS = -1,  //The former big number is less than the latter
	SM2_Cmp_GREATER = 1,//The former big number is greater than the latter
	SM2_Reverse_ERROR = 0x7A9E0863, //reverse fail due to src and dst are same 
	SM2_ERROR = 3,
	POINT_MUL_ERROR = 4,
	PRIKEY_ERROR = 5,
	LENGTH_TOO_LONG = 6,
	PUBKEY_ERROR = 7,
	FAIL = 8,
	SM2_AddrErr,
	SM2_LengthErr,
	SM2_ROLE_ERR
};

/**
 * @brief get SM2_PointIsOnCrv
 * @param[in] public key
 * @return SM2_isCurve_Ok, SM2_PointIsOnCrv success; othets: SM2_PointIsOnCrv fail
 * @note  1.Please refer to the demo in user guidance before using this function  

 */
uint32_t SM2_PointIsOnCrv(uint8_t pubKey[65]);

/**
 * @brief get SM2 key
 * @param[out] private key
 * @param[out] public key
 * @return SM2_SUCCESS, SM2 decrypt success; othets: SM2 decrypt fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  

 */
uint32_t SM2_getKey(uint8_t priKey[32], uint8_t pubKey[65]);

/**
 * @brief get SM2 public key
 * @param[in] private key
 * @param[out] public key
 * @return SM2_SUCCESS, SM2 decrypt success; othets: SM2 decrypt fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
          2.SM2_Init() must be recalled before you want to use this function
 */
uint32_t SM2_getPubKey(uint8_t priKey[32], uint8_t pubKey[65]);

/**
 * @brief SM2 get Z
 * @param[in] ID pointer to user's identity
 * @param[in] the length of ID
 * @param[in] public key
 * @param[out] hash result(Z)
 * @return SM2_SUCCESS, SM2 get Z success; othets: SM2 get Z fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 */
uint32_t SM2_getZ(uint8_t* ID, uint32_t IDByteLen, uint8_t pubKey[65], uint8_t Z[32]);
 /**
 * @brief SM2 get E
 * @param[in] M pointer to message
 * @param[in] the length of M
 * @param[in] Z value
 * @param[out] hash result(E)
 * @return SM2_SUCCESS, SM2 get E success; othets: SM2 get E fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
					3.If you want to get E,you should get recall SM2_GetZ() o get E
 */
uint32_t SM2_GetE(uint8_t* M, uint32_t MByteLen, uint8_t Z[32], uint8_t E[32]);

/**
 * @brief SM2 signature
 * @param[in] disgest, the hash result on message by SM3
 * @param[in] private key
 * @param[in] public key
 * @param[out] signature r
 * @param[out] signature s
 * @return SM2_Sign_Ok, SM2 sign success; othets: SM2 sign fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 */
uint32_t SM2_sign(uint8_t E[32],uint8_t priKey[32], uint8_t r[32], uint8_t s[32]);

/**
 * @brief SM2 verify
 * @param[in] disgest, the hash result on message by SM3
 * @param[in] public key
 * @param[in] signature r
 * @param[in] signature s
 * @return SM2_Verif_Ok, SM2 verify success; othets: SM2 verify fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 */
uint32_t SM2_verify(uint8_t E[32], uint8_t pubKey[65], uint8_t r[32], uint8_t s[32]);

/**
 * @brief SM2 encrypt
 * @param[in] M pointer to the message to be encryption
 * @param[in] the length of M
 * @param[in] public key
 * @param[out] C pointer to the result
 * @param[out] the length of C
 * @return SM2_En_Ok, SM2 encrypt success; othets: SM2 encrypt fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 */
uint32_t SM2_encrypt(uint8_t *M, uint32_t MByteLen, uint8_t pubKey[65], uint8_t *C, uint32_t *CByteLen);

/**
 * @brief SM2 decrypt
 * @param[in] C pointer to the message to be decryption
 * @param[in] the length of C
 * @param[in] private key
 * @param[out] M pointer to the result
 * @param[out] the length of M
 * @return SM2_De_Ok, SM2 decrypt success; othets: SM2 decrypt fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
 */
uint32_t SM2_decrypt(uint8_t *C, uint32_t CByteLen, uint8_t priKey[32], uint8_t *M, uint32_t *MByteLen);
/**
 * @brief SM2 key exchange
 * @param[in] role,1 denotes the initiator(user A), 0 denotes the corresponding(user B)
 * @param[in] IDA pointer to user A ID
 * @param[in] the byte length of IDA
 * @param[in] IDB pointer to user B ID
 * @param[in] the byte length of IDB
 * @param[in] user A private key
 * @param[in] user A public key
 * @param[in] user B public key
 * @param[in] user A temporary private key
 * @param[in] user A temporary public key
 * @param[in] user B temporary public key
 * @param[in] the byte length of KA
 * @param[out] KA pointer to key exchange result
 * @param[out] S1 of user A or S2 of user B
 * @param[out] SA of user A or SB of user B
 * @return SM2_SUCCESS, SM2 key exchange success; othets: SM2 key exchange fail(reference to the definition by enum variation) 
 * @note  1.Please refer to the demo in user guidance before using this function  
          3.PA =[dA]G (G is base point and in this case, PA's first byte 0x04 is ignore), RA=[rA]G	
	        4.You can check S1 is equal to SB and S2 is equal to SA to verify whether key exchange success or not
            if S1=SB and S2=SA,key exchange success;otherwise key exchange fail.					           					 
**/
 

uint32_t SM2_ExchangeKey(uint8_t role, uint8_t *IDA, uint32_t IDAByteLen, uint8_t *IDB, uint32_t IDBByteLen, uint8_t dA[32], uint8_t PA[65], 
                    uint8_t PB[65], uint8_t rA[32], uint8_t RA[65], uint8_t RB[65], uint32_t kByteLen, uint8_t *KA, uint8_t S1[32], uint8_t SA[32]);

/**
 * @brief Get SM2 lib version
 * @param[out] type pointer one byte type information represents the type of the lib, like Commercial version.\
 * @Bits 0~4 stands for Commercial (C), Security (S), Normal (N), Evaluation (E), Test (T), Bits 5~7 are reserved. e.g. 0x09 stands for CE version.
 * @param[out] customer pointer one byte customer information represents customer ID. for example, 0x00 stands for standard version, 0x01 is for Tianyu customized version...
 * @param[out] date pointer array which include three bytes date information. If the returned bytes are 18,9,13,this denotes September 13,2018 
 * @param[out] version pointer one byte version information represents develop version of the lib. e.g. 0x12 denotes version 1.2.
 * @return none
 * @1.You can recall this function to get SM2 lib information
 */
void SM2_Version(uint8_t *type, uint8_t *customer, uint8_t date[3], uint8_t *version);

#endif
