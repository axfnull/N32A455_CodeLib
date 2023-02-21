1、功能说明

    此例程提供了一种DMA MemtoMem模式用法，用于在FLASH与RAM之间传输数据。
    
    首先定义了一个静态数组SRC_Const_Buffer，数据保存在FLASH的只读存储区，
    再配置DMA1_CH1通道，用于将数据传输到RAM区DST_Buffer中，
    开启DMA的传输完成中断，用于指示传输已完成，
    
    等待数据传输完成，并比较DST_Buffer的数据与SRC_Const_Buffer中数据是否一致，
    输出对比结果到串口。
    
2、使用环境

    软件开发环境：
        IDE工具：KEIL MDK-ARM 5.26.2.0
    
    硬件环境：
        开发板 N32A455VEL7-EVB

3、使用说明
    
    1、时钟源：HSE+PLL
    2、主时钟：144MHz
    3、DMA通道：DMA1_CH1
    
    4、USART1配置：
            TX  -->  PA9            50MHz，AF_PP
            波特率：115200
            数据位：8bit
            停止位：1bit
            无校验

    5、测试步骤与现象
        a，编译下载代码复位运行
        b，从串口看打印信息，验证结果

4、注意事项
    无

1. Function description

    This routine provides a DMA MemtoMem mode usage for transferring data between FLASH and RAM.
    
    First, a static array SRC_Const_Buffer is defined, and the data is stored in the read-only storage area of ​​FLASH.
    Then configure the DMA1_CH1 channel to transfer data to the RAM area DST_Buffer,
    Turn on the DMA transfer completion interrupt to indicate that the transfer is complete,
    
    Wait for the data transfer to complete, and compare whether the data in DST_Buffer is consistent with the data in SRC_Const_Buffer,
    Output the comparison result to the serial port.
    
2. Use environment

    Software development environment:
        IDE tool: KEIL MDK-ARM 5.26.2.0
    
    Hardware environment:
        Development Board N32A455VEL7-EVB

3. Instructions for use
    
    1. Clock source: HSE+PLL
    2. Main clock: 144MHz
    3. DMA channel: DMA1_CH1
    
    4. USART1 configuration:
            TX --> PA9 50MHz, AF_PP
            Baud rate: 115200
            Data bits: 8bit
            Stop bit: 1bit
            no verification

    5. Test steps and phenomena
        a, compile and download the code to reset and run
        b. View the print information from the serial port and verify the result

4. Matters needing attention
    none