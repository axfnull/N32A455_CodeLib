1、功能说明

    1、WWDG复位功能。

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.25
    硬件环境：
        1、N32A455VEL7-EVB V1.0
        2、MCU：N32A455REL7

3、使用说明
    
    系统配置；
        1、WWDG时钟源：PCLK1
        2、窗口值：42.77ms < n <58.25ms
        3、指示灯：
                         PA11     RGB RED LED
                         PA12     RGB GREEN LED
	         PB10     RGB BLUE LED
        4、串口配置：
                        - 串口为USART1（TX：PA9  RX：PA10）:
                        - 数据位：8
                        - 停止位：1
                        - 奇偶校验：无
                        - 波特率： 115200               
    使用方法：
        1、在KEIL下编译后烧录到评估板，上电后，控制的指示灯不停的闪烁。说明窗口值刷新正常，代码正常运行。
        2、当把Delay(50)函数参数改成50以上，整个系统将一直处于复位状态。

4、注意事项
     无

1. Function description

    1. WWDG reset function.

2. Use environment

    Software development environment: KEIL MDK-ARM V5.25
    Hardware environment:
        1. N32A455VEL7-EVB V1.0
        2. MCU: N32A455REL7

3. Instructions for use
    
    System Configuration;
        1. WWDG clock source: PCLK1
        2. Window value: 42.77ms < n < 58.25ms
        3. Indicator light:
                         PA11 RGB RED LED
                         PA12 RGB GREEN LED
PB10 RGB BLUE LED
        4. Serial port configuration:
                        - Serial port is USART1 (TX: PA9 RX: PA10):
                        - Data bits: 8
                        - Stop bit: 1
                        - Parity: none
                        - Baud rate: 115200
    Instructions:
        1. After compiling under KEIL and burning it to the evaluation board, after power-on, the control indicator light keeps flashing. It means that the window value refreshes normally and the code runs normally.
        2. When the parameter of the Delay(50) function is changed to more than 50, the whole system will always be in the reset state.

4. Matters needing attention
     none