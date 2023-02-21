1、功能说明

    此例程展示了通过I2C模块与外部EEPRON的通信。   

2、使用环境

    软件开发环境：
        IDE工具：KEIL MDK-ARM 5.34.0.0
    
    硬件环境：
        开发板 N32A455VEL7_EVB v1.0.0

3、使用说明

    1、时钟源：HSE+PLL
    2、主时钟：144MHz
    3、I2C1 配置：
            SCL   -->  PB8          50MHz，AF_OP
            SDA   -->  PB9          50MHz，AF_OP

            ADDR：0xA0(7bit)
            CLOCK:400KHz
            
    4、USART1配置：
            TX  -->  PA9            50MHz，AF_PP
            波特率：115200
            数据位：8bit
            停止位：1bit
            无校验

    5、测试步骤与现象
        a，检查EEPROM连接
        b，编译下载代码复位运行
        c，从串口看打印信息，验证结果

4、注意事项
    1，此处使用的EEPROM是AT24C02，32个page，每个page 8byte
    2，读写数据时若长度大于一个page，则器件地址会自动回卷


1. Function description

    This routine demonstrates communication with an external EEPROM via the I2C module.

2. Use environment

    Software development environment:
        IDE tool: KEIL MDK-ARM 5.34.0.0
    
    Hardware environment:
        Development board N32A455VEL7_EVB v1.0.0

3. Instructions for use

    1. Clock source: HSE+PLL
    2. Main clock: 144MHz
    3. I2C1 configuration:
            SCL --> PB8 50MHz, AF_OP
            SDA --> PB9 50MHz, AF_OP

            ADDR: 0xA0 (7bit)
            CLOCK: 400KHz
            
    4. USART1 configuration:
            TX --> PA9 50MHz, AF_PP
            Baud rate: 115200
            Data bits: 8bit
            Stop bit: 1bit
            no verification

    5. Test steps and phenomena
        a, check the EEPROM connection
        b, compile and download the code to reset and run
        c, see the print information from the serial port, and verify the result

4. Matters needing attention
    1. The EEPROM used here is AT24C02, 32 pages, each page is 8byte
    2. If the length is greater than one page when reading and writing data, the device address will be automatically rewound