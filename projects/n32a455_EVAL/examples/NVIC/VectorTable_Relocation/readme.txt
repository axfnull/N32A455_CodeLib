1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示NVIC中断向量表重定位

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7-EVB V1.0
        
3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        USART：TX - PA9，波特率115200
    EXIT：PA0为浮空输入模式，外部中断线 - EXIT_LINE0，开启外部中断，优先级为0

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.一开始向量表位于FLASH，当按键按下后向量表重定位至SRAM，并打印相关信息，程序运行正常；

4、注意事项


1. Function description

     /* Briefly describe the project function */
         This routine configures and demonstrates NVIC interrupt vector table relocation

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7-EVB V1.0
        
3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 144MHz
         USART: TX - PA9, baud rate 115200
     EXIT: PA0 is floating input mode, external interrupt line - EXIT_LINE0, open external interrupt, priority is 0

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. The vector table is located in FLASH at the beginning, when the button is pressed, the vector table is relocated to SRAM, and the relevant information is printed, and the program runs normally;

4. Matters needing attention