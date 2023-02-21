1、功能说明

    此例程展示了通过SDIO主机接口与TF卡之间数据读写功能。
             
    首先初始化SDIO主机，再进行TF卡的初始化，
    
    向TF卡写入数据，用DMA2_CH4将Buffer_Block_Tx数据传输到SDIO主机，SDIO主机再将数据写入TF卡，
    在DMA完成写入操作后要等待SDIO主机与TF卡的执行完成，获取到正确的返回状态表示写入完成。
    
    从TF卡读出数据，SDIO主机从TF卡中读出数据到数据寄存器，用DMA2_CH4将SDIO主机接收到的数据
    存到Buffer_Block_Rx中。等待DMA执行完成，等待SDIO读操作执行完成。
    
    比较Buffer_Block_Tx和Buffer_Block_Rx中的数据一致性，输出对比结果到串口

2、使用环境

    软件开发环境：
        IDE工具：KEIL MDK-ARM 5.34.0.0 
    硬件环境：
        开发板 N32A455VEL7_EVB v1.0.0

3、使用说明
    
    1、SystemClock：144MHz
    2、DMA通道：DMA2_CH4
    3、SDIO 配置：
            D0   -->   PC8          50MHz，AF_PP
            D1   -->   PC9          50MHz，AF_PP
            D2   -->   PC10         50MHz，AF_PP
            D3   -->   PC11         50MHz，AF_PP
            CLK   -->  PC12         50MHz，AF_PP
            CMD   -->  PD2          50MHz，AF_PP

            分频系数：178    （SDIOCLK = HCLK, SDIO_CK = HCLK/(2 + 分频系数)）
            上升沿有效
            禁用旁路
            禁用时钟保持
            总线位宽4bit
    
    4、USART1配置：
            TX  -->  PA9            50MHz，AF_PP
            波特率：115200
            数据位：8bit
            停止位：1bit
            无校验

    5、测试步骤与现象
        a，测试前请先安装好TF卡
        b，编译下载代码复位运行
        c，从串口看打印信息，验证结果

4、注意事项
    1、在初始化TF卡时，总线位宽必须为1bit，之后根据卡的类型可以用1/4/6bit位宽
    2、读写操作之后必须调用SD_WaitWriteOperation()/SD_WaitReadOperation()/SD_GetStatus()
    以确保操作完成。



1. Function description

    This routine shows the function of reading and writing data between the SDIO host interface and the TF card.
             
    First initialize the SDIO host, then initialize the TF card,
    
    Write data to the TF card, use DMA2_CH4 to transfer the Buffer_Block_Tx data to the SDIO host, and the SDIO host will write the data to the TF card,
    After the DMA completes the write operation, wait for the execution of the SDIO host and the TF card to complete, and obtain the correct return status to indicate that the write is complete.
    
    Read data from TF card, SDIO host reads data from TF card to data register, use DMA2_CH4 to receive data from SDIO host
    Stored in Buffer_Block_Rx. Wait for the DMA execution to complete, and wait for the SDIO read operation to complete.
    
    Compare the data consistency between Buffer_Block_Tx and Buffer_Block_Rx, and output the comparison result to the serial port

2. Use environment

    Software development environment:
        IDE tool: KEIL MDK-ARM 5.34.0.0
    Hardware environment:
        Development board N32A455VEL7_EVB v1.0.0

3. Instructions for use
    
    1. SystemClock: 144MHz
    2. DMA channel: DMA2_CH4
    3. SDIO configuration:
            D0 --> PC8 50MHz, AF_PP
            D1 --> PC9 50MHz, AF_PP
            D2 --> PC10 50MHz, AF_PP
            D3 --> PC11 50MHz, AF_PP
            CLK --> PC12 50MHz, AF_PP
            CMD --> PD2 50MHz, AF_PP

            Frequency division factor: 178 (SDIOCLK = HCLK, SDIO_CK = HCLK/(2 + frequency division factor))
            Active on rising edge
            Disable bypass
            Disable clock hold
            Bus width 4bit
    
    4. USART1 configuration:
            TX --> PA9 50MHz, AF_PP
            Baud rate: 115200
            Data bits: 8bit
            Stop bit: 1bit
            no verification

    5. Test steps and phenomena
        a, please install the TF card before testing
        b, compile and download the code to reset and run
        c, see the print information from the serial port, and verify the result

4. Matters needing attention
    1. When initializing the TF card, the bus bit width must be 1bit, and then 1/4/6bit bit width can be used according to the type of the card
    2. SD_WaitWriteOperation()/SD_WaitReadOperation()/SD_GetStatus() must be called after read and write operations
    to ensure the operation is complete.