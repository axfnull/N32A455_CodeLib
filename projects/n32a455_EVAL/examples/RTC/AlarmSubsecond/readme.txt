1、功能说明

    1、通过设定闹钟时间来触发闹钟中断。
    2、通过闹钟标志位来配置IO输出

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.25
    硬件环境：
        1、基于评估板N32A455R-STB V1.1开发
        2、MCU：N32A455VEL7


3、使用说明
    
    系统配置；
        1、RTC时钟源：LSE
        2、闹钟IO输出：PC13
        3、串口配置：
                            - 串口为USART1（TX：PA9  RX：PA10）:
                            - 数据位：8
                            - 停止位：1
                            - 奇偶校验：无
                            - 波特率： 115200 
    使用方法：
    在KEIL下编译后烧录到评估板，上电后，RTC闹钟每隔500ms产生闹钟中断
    串口会打印:500ms Alarm Wakeup  并且LED1 闪烁。

4、注意事项
    无


1. Function description

     1. Trigger the alarm interrupt by setting the alarm time.
     2. Configure the IO output through the alarm flag bit

2. Use environment

     Software development environment: KEIL MDK-ARM V5.25
     Hardware environment:
         1. Developed based on the evaluation board N32A455R-STB V1.1
         2. MCU：N32A455VEL7


3. Instructions for use
    
     System Configuration;
         1. RTC clock source: LSE
         2. Alarm clock IO output: PC13
         3. Serial port configuration:
                             - Serial port is USART1 (TX: PA9 RX: PA10):
                             - Data bits: 8
                             - Stop bit: 1
                             - Parity: none
                             - Baud rate: 115200
     Instructions:
     After compiling under KEIL and burning it to the evaluation board, after power-on, the RTC alarm clock generates an alarm interrupt every 500ms
     The serial port will print: 500ms Alarm Wakeup and LED1 blinks.

4. Matters needing attention
     none