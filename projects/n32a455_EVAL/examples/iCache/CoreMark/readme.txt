1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示MCU跑分测试

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7_EVB v1.0.0
        
3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        USART：TX - PA9，RX - PA10，波特率115200
    SysTick：时钟滴答配置为1MS

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.通过串口打印出跑分结果；

4、注意事项


1. Function description

     /* Briefly describe the project function */
         This example configures and demonstrates the MCU benchmark

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7_EVB v1.0.0
        
3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         USART: TX - PA9, RX - PA10, baud rate 115200
     SysTick: Clock ticks configured as 1MS

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Print out the running score results through the serial port;

4. Matters needing attention