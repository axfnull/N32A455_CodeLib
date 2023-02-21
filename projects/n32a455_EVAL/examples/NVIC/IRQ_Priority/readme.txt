1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示NVIC优先级设置

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7-EVB V1.0
        
3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        USART：TX - PA9，波特率115200
    EXIT：PA0为浮空输入模式，外部中断线 - EXIT_LINE0，开启外部中断，优先级为0
    SysTick：中断优先级设置为0

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.正常情况下打印SysTick中断信息，当按键外部中断和SysTick中断同时触发时，修改SysTick中断优先级为2，并打印相关信息，程序运行正常；

4、注意事项


1. Function description

     /* Briefly describe the project function */
         This routine configures and demonstrates NVIC priority settings

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7-EVB V1.0
        
3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 144MHz
         USART: TX - PA9, baud rate 115200
     EXIT: PA0 is floating input mode, external interrupt line - EXIT_LINE0, open external interrupt, priority is 0
     SysTick: Interrupt priority set to 0

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Print the SysTick interrupt information under normal circumstances. When the external button interrupt and the SysTick interrupt are triggered at the same time, modify the SysTick interrupt priority to 2, and print the relevant information, the program runs normally;

4. Matters needing attention