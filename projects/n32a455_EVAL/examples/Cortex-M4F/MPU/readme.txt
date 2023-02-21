1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示MPU内存保护功能

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7_EVB V1.0

3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        USART：TX - PA9，RX - PA10，波特率115200

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.查看串口打印信息，允许访问则打印允许访问信息，不允许访问则进入内存管理故障中断并打印不允许访问信息；

4、注意事项

1. Function description

     /* Briefly describe the project function */
         This routine configures and demonstrates the MPU memory protection feature

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7_EVB V1.0

3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 144MHz
         USART: TX - PA9, RX - PA10, baud rate 115200

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Check the serial port printing information, if the access is allowed, the access information is printed; if the access is not allowed, the memory management fault is interrupted and the access is not allowed information;

4. Matters needing attention