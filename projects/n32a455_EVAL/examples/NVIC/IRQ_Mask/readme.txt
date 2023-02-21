1、功能说明

    /* 简单描述工程功能 */
        这个例程配置并演示使用GPIO使能和禁用中断通过TIM定时器中断中打印信息观察中断的使能和禁用

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32A455VEL7-EVB V1.0
        
3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        USART：TX - PA9，波特率115200
        GPIO：PA0为输入上拉模式
    TIM：预分频系数 - （SystemClock/1200-1），周期 - （1200-1），开启定时器中断

    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.查看串口打印信息，定时器中断信息每1S打印一次，按下WKUP按键打印停止，再次按下则继续打印，表明程序运行正常；

4、注意事项


1. Function description

     /* Briefly describe the project function */
         This routine configures and demonstrates enabling and disabling interrupts using GPIO Observe the enabling and disabling of interrupts by printing information in the TIM timer interrupt

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32A455VEL7-EVB V1.0
        
3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 144MHz
         USART: TX - PA9, baud rate 115200
         GPIO: PA0 is input pull-up mode
     TIM: prescale factor - (SystemClock/1200-1), period - (1200-1), enable timer interrupt

     /* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Check the serial port printing information, the timer interrupt information is printed every 1S, press the WKUP button to stop printing, press it again to continue printing, indicating that the program is running normally;

4. Matters needing attention