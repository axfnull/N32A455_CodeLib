1、功能说明

    该测例演示了USARTy与USARTz间通过中断实现的基础通信。
    USARTy发送TxBuffer1数据至USARTz，USARTz接收数据存至RxBuffer2。同时，
USARTz发送TxBuffer2数据至USARTy，USARTy接收数据存至RxBuffer1。
    随后，分别比较两组接收数据与发送数据，比较结果存入TransferStatus1变量
和TransferStatus2变量。
    USARTy和USARTz可以是USART1和USART2、USART3和UART4或UART6和UART7。

2、使用环境

    软件开发环境：KEIL MDK-ARM 5.34.0.0
    硬件环境：N32A455VEL7_EVB v1.0.0


3、使用说明
    
    系统时钟配置如下：
    - 时钟源 = HSE + PLL
    - 系统时钟 = 144MHz
    
    USART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位
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
   
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，依次查看变量TransferStatus1和TransferStatus2，其中，
      PASSED为测试通过，FAILED为测试异常

4、注意事项
    使用PA9，PA10需要把开发板NS-LINK的MCU_TX和MCU_RX跳线帽断开


1. Function description

    This test example demonstrates basic communication between USARTy and USARTz via interrupts.
    USARTy sends TxBuffer1 data to USARTz, and USARTz receives data and stores it in RxBuffer2. at the same time,
USARTz sends TxBuffer2 data to USARTy, USARTy receives data and stores it in RxBuffer1.
    Then, compare the two groups of received data and sent data respectively, and store the comparison results in the TransferStatus1 variable.
and the TransferStatus2 variable.
    USARTy and USARTz can be USART1 and USART2, USART3 and UART4, or UART6 and UART7.

2. Use environment

    Software development environment: KEIL MDK-ARM 5.34.0.0
    Hardware environment: N32A455VEL7_EVB v1.0.0


3. Instructions for use
    
    The system clock configuration is as follows:
    - Clock source = HSE + PLL
    - System Clock = 144MHz
    
    USART is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
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
   
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, where,
      PASSED is the test passed, FAILED is the test abnormal

4. Matters needing attention
    Use PA9, PA10 need to disconnect the MCU_TX and MCU_RX jumper caps of the development board NS-LINK