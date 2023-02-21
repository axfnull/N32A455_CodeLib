#ifndef _LIN_MASTER_H
#define _LIN_MASTER_H
#include <stdio.h>
#include "n32a455.h"
#include "log.h"


#define SC_RECEIVE_TIMEOUT 0x4000  /* Direction to reader */

typedef enum
{
    CLASSIC = 0,
    ENHANCED = !CLASSIC
} ChecksumType;

typedef struct M_LIN_EX_MSG
{
    ChecksumType CheckType;    //LIN数据校验类型
    unsigned char DataLen;      //LIN数据段有效数据字节数
    unsigned char Sync;         //同步段0x55
    unsigned char PID;          //帧ID
    unsigned char Data[8];      //数据
    unsigned char Check;        //校验
} M_LIN_EX_MSG;

void TestLinMaster(void);

#endif
