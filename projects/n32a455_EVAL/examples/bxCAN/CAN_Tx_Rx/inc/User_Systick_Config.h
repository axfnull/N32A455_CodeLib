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
 * @file User_Systick_Config.h
 * @author Nations 
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
 */


#ifndef  __USER_SYSTICK_CONFIG_H__
#define  __USER_SYSTICK_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif


#define  TIME_1MS      1
#define  TIME_10MS    (TIME_1MS*10)
#define  TIME_100MS   (TIME_10MS*10)
#define  TIME_1S      (TIME_100MS*10)

extern uint32_t systick_count;
extern void Systick_MS_Config(uint32_t sys_freq);
extern void Systick_Disable(void);
extern uint32_t User_Time_Read(uint32_t time);
extern void User_Time_Set(uint32_t* time);


#ifdef __cplusplus
}
#endif


#endif/**/
