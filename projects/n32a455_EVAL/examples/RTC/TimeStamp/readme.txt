1、功能说明

    1、通过EXTI线来触发时间戳。

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.25
    硬件环境：
        1、基于评估板N32A455VEL7-EVB V1.0开发
        2、MCU：N32A455VEL7

3、使用说明
    
    系统配置；
        1、时钟源：LSI
        2、EXTI中断IO：PB8
        3、串口配置：
                            - 串口为USART1（TX：PA9  RX：PA10）:
                            - 数据位：8
                            - 停止位：1
                            - 奇偶校验：无
                            - 波特率： 115200 
    使用方法：
        在KEIL下编译后烧录到评估板，把PC13连接到PB8，上电后，串口每隔1S会打印时间戳输出。

4、注意事项
    无


1. Function description

     1. Trigger the timestamp through the EXTI line.

2. Use environment

     Software development environment: KEIL MDK-ARM V5.25
     Hardware environment:
         1. Developed based on the evaluation board N32A455VEL7-EVB V1.0
         2. MCU: N32A455VEL7

3. Instructions for use
    
     System Configuration;
         1. Clock source: LSI
         2. EXTI interrupt IO: PB8
         3. Serial port configuration:
                             - Serial port is USART1 (TX: PA9 RX: PA10):
                             - Data bits: 8
                             - Stop bit: 1
                             - Parity: none
                             - Baud rate: 115200
     Instructions:
         After compiling under KEIL, burn it to the evaluation board, connect PC13 to PB8, after power-on, the serial port will print time stamp output every 1S.

4. Matters needing attention
     none