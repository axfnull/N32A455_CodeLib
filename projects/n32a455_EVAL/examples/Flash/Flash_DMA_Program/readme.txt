1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示使用DMA将SRAM数据写入FLASH

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7-EVB V1.0
        
3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        USART：TX - PA9，RX - PA10，波特率115200
    DMA：数据传输方向为SRAM到FLASH

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.查看串口打印信息，对比传输完成后的SRAM及FLASH数组数据，完全相同则打印信息为测试通过，程序运行正常；

4、注意事项


1. Function description

     /* Briefly describe the project function */
         This routine configures and demonstrates writing SRAM data to FLASH using DMA

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7-EVB V1.0
        
3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 144MHz
         USART: TX - PA9, RX - PA10, baud rate 115200
     DMA: The data transfer direction is from SRAM to FLASH

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Check the printing information of the serial port, compare the SRAM and FLASH array data after the transmission is completed, if the printing information is the same, the test is passed, and the program is running normally;

4. Matters needing attention