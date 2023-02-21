1、功能说明

    1、通过设定唤醒时间触发中断。
    2、通过唤醒标志位来配置IO输出

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.25
    硬件环境：
        1、基于评估板N32A455VEL7-EVB V1.0开发
        2、MCU：N32A455VEL7


3、使用说明
    
    系统配置；
        1、周期性唤醒时钟源：RTCCLK（1HZ）
        2、唤醒输出口：PC13
        3、串口配置：
                            - 串口为USART1（TX：PA9  RX：PA10）:
                            - 数据位：8
                            - 停止位：1
                            - 奇偶校验：无
                            - 波特率： 115200 
    使用方法：
        1、在KEIL下编译后烧录到评估板，上电后，串口每隔5s会打印Stop2 Wakeup From RTC
        2、设定#define    RTC_ALARM_TEST_TYPE  RTC_ALARM_TEST_TYPE_OUTPUT ，编译后烧录到评估板，
           上电后，PC13每隔5S翻转一次。
                
4、注意事项
    无


1. Function description

    1. Trigger the interrupt by setting the wake-up time.
    2. Configure the IO output through the wake-up flag bit

2. Use environment

    Software development environment: KEIL MDK-ARM V5.25
    Hardware environment:
        1. Developed based on the evaluation board N32A455VEL7-EVB V1.0
        2. MCU: N32A455VEL7


3. Instructions for use
    
    System Configuration;
        1. Periodic wake-up clock source: RTCCLK (1HZ)
        2. Wake-up output port: PC13
        3. Serial port configuration:
                            - Serial port is USART1 (TX: PA9 RX: PA10):
                            - Data bits: 8
                            - Stop bit: 1
                            - Parity: none
                            - Baud rate: 115200
    Instructions:
        1. After compiling under KEIL and burning to the evaluation board, after power-on, the serial port will print Stop2 Wakeup From RTC every 5s
        2. Set #define RTC_ALARM_TEST_TYPE RTC_ALARM_TEST_TYPE_OUTPUT, compile and burn to the evaluation board,
           After power-on, PC13 flips every 5S.
                
4. Matters needing attention
    none