1、功能说明
    1、通过RTC闹钟来唤醒STOP2。
    2、串口打印进入退出状态

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.25

    硬件环境：
        1、基于评估板N32A455VEL7-EVB V1.0开发
        2、MCU：N32A455VEL7

3、使用说明
    
    系统配置；
        1、RTC时钟源：LSI
        2、低功耗模式：STOP2
        3、串口配置：
                            - 串口为USART1（TX：PA9  RX：PA10）:
                            - 数据位：8
                            - 停止位：1
                            - 奇偶校验：无
                            - 波特率： 115200 
        使用方法：
        在KEIL下编译后烧录到评估板，通电，过了一会串口打印start low power，说明进入低功耗模式了。
        当串口打印输出Exit low power，说明此时闹钟唤醒STOP2了。

4、注意事项
    无


1. Function description
     1. Wake up STOP2 through the RTC alarm clock.
     2. The serial port printing enters the exit state

2. Use environment

     Software development environment: KEIL MDK-ARM V5.25

     Hardware environment:
         1. Developed based on the evaluation board N32A455VEL7-EVB V1.0
         2. MCU: N32A455VEL7

3. Instructions for use
    
     System Configuration;
         1. RTC clock source: LSI
         2. Low power consumption mode: STOP2
         3. Serial port configuration:
                             - Serial port is USART1 (TX: PA9 RX: PA10):
                             - Data bits: 8
                             - Stop bit: 1
                             - Parity: none
                             - Baud rate: 115200
         Instructions:
         After compiling under KEIL, burn it to the evaluation board, power on, and after a while, the serial port prints start low power, indicating that it has entered the low power consumption mode.
         When the serial port prints out Exit low power, it means that the alarm clock wakes up STOP2 at this time.

4. Matters needing attention
     none