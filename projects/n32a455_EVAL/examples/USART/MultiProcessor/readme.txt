1、功能说明

    该测例演示了如何使用USART多处理器模式。USARTy和USARTz可以是USART1
和USART2、USART3和UART4或UART6和UART7。
    首先，分别设置USARTy和USARTz的地址为0x1和0x2。USARTy连续给USARTz
发送字符0x33。USARTz收到0x33，便翻转LED1、LED2和LED3的引脚。
    一旦KEY1_INT_EXTI_LINE线检测到上升沿，则产生EXTI0中断，在
EXTI0_IRQHandler中断处理函数中(the ControlFlag = 0)，USARTz进入静默
模式，在静默模式中，LED引脚停止翻转，直到KEY1_INT_EXTI_LINE线检测到
上升沿(the ControlFlag = 1)。在EXTI0_IRQHandler中断处理函数中，USARTy
发送地址0x102唤醒USARTz。LED引脚重新启动翻转。

2、使用环境

    软件开发环境：KEIL MDK-ARM 5.34.0.0
    硬件环境：N32A455REL7_STB v1.0

3、使用说明
    
    系统时钟配置如下：
    - 时钟源 = HSE + PLL
    - 系统时钟 = 144MHz
    
    USARTy配置如下：
    - 波特率 = 115200 baud
    - 字长 = 9数据位
    - 1停止位
    - 校验控制禁用
    - 硬件流控制禁用（RTS和CTS信号）
    - 接收器和发送器使能  
    
    USART引脚连接如下：    
    - USART1_Tx.PA9    <------->   USART2_Rx.PA3
    - USART1_Rx.PA10   <------->   USART2_Tx.PA2 
    或
    - USART3_Tx.PB10   <------->   UART4_Rx.PC11
    - USART3_Rx.PB11   <------->   UART4_Tx.PC10
    或
    - UART6_Tx.PE2    <------->   UART7_Rx.PC5
    - UART6_Rx.PE3    <------->   UART7_Tx.PC4   
    
    KEY1_INT_EXTI_LINE.PA0    <------->   WAKEUP_KEY
    
    LED1    <------->   PB5
    LED2    <------->   PB4
    LED3    <------->   PA8
  
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，观察LED1~3是否处于闪烁状态
    - 按按键KEY，观察LED1~3是否停止闪烁
    - 再次按按键KEY，观察LED1~3是否恢复闪烁

4、注意事项
    使用PA9，PA10需要把开发板NS-LINK的MCU_TX和MCU_RX跳线帽断开


1. Function description

    This test example demonstrates how to use the USART multiprocessor mode. USARTy and USARTz can be USART1
and USART2, USART3 and UART4 or UART6 and UART7.
    First, set the addresses of USARTy and USARTz to 0x1 and 0x2, respectively. USARTy continuously gives USARTz
Send the character 0x33. USARTz receives 0x33 and flips the pins of LED1, LED2 and LED3.
    Once a rising edge is detected on the KEY1_INT_EXTI_LINE line, an EXTI0 interrupt will be generated.
In the EXTI0_IRQHandler interrupt handler (the ControlFlag = 0), USARTz goes silent
mode, in silent mode, the LED pin stops toggling until the KEY1_INT_EXTI_LINE line detects
Rising edge (the ControlFlag = 1). In the EXTI0_IRQHandler interrupt handler, USARTy
Send address 0x102 to wake up USARTz. The LED pin restarts toggling.

2. Use environment

    Software development environment: KEIL MDK-ARM 5.34.0.0
    Hardware environment: N32A455VEL7_EVB v1.0.0

3. Instructions for use
    
    The system clock configuration is as follows:
    - Clock source = HSE + PLL
    - System Clock = 144MHz
    
    USARTy is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 9 data bits
    - 1 stop bit
    - checksum control disabled
    - Hardware flow control disabled (RTS and CTS signals)
    - Receiver and transmitter enable
    
    The USART pins are connected as follows:
    - USART1_Tx.PA9 <-------> USART2_Rx.PA3
    - USART1_Rx.PA10 <-------> USART2_Tx.PA2
    or
    - USART3_Tx.PB10 <-------> UART4_Rx.PC11
    - USART3_Rx.PB11 <-------> UART4_Tx.PC10
    or
    - UART6_Tx.PE2 <-------> UART7_Rx.PC5
    - UART6_Rx.PE3 <-------> UART7_Tx.PC4
    
    KEY1_INT_EXTI_LINE.PA0 <-------> WAKEUP_KEY
    
    LED1 <-------> PB5
    LED2 <-------> PB4
    LED3 <-------> PA8
  
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Reset operation and observe whether LED1~3 are blinking
    - Press the button KEY and observe whether LED1~3 stop flashing
    - Press the button KEY again and observe whether LED1~3 resume to flash

4. Matters needing attention
    Use PA9, PA10 need to disconnect the MCU_TX and MCU_RX jumper caps of the development board NS-LINK