1、功能说明
    1、ADC1采样、转换PC2引脚的模拟电压
    2、其中ADC1转换结果通过DMA_CH1通道读取到变量ADCConvertedValue
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB V1.0 EVB开发
3、使用说明
    系统配置；
        1、时钟源：
            HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,ADC CLK=144M/16,ADC 1M CLK=HSE/8,DMA CLK=144M
        2、端口配置：
            PC2选择为模拟功能ADC1转换通道8
        3、DMA：
            DMA1_CH1通道回环模式搬运一个半字的ADC1转换结果到ADCConvertedValue变量
        4、ADC：
            ADC1独立工作模式、连续转换、扫描模式、软件触发、12位数据右对齐，转换通道8即PC2的模拟电压数据
    使用方法：
        1、编译后打开调试模式，将变量ADCConvertedValue添加到watch窗口观察
        2、通过改变PC2引脚的电压，可以看到转换结果变量同步改变
4、注意事项
    当系统采用HSE时钟时（一般HSI也是打开的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)可以配置为HSE或者HSI
    当系统采用HSI时钟时（一般HSE是关闭的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)只能配置为HSI

1. Function description
    1. ADC1 samples and converts the analog voltage of the PC2 pin
    2. The ADC1 conversion result is read to the variable ADCConvertedValue through the DMA_CH1 channel
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Based on N32A455VEL7_EVB V1.0 EVB development
3. Instructions for use
    System Configuration;
        1. Clock source:
            HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,ADC CLK=144M/16,ADC 1M CLK=HSE/8,DMA CLK=144M
        2. Port configuration:
            PC2 selected as analog function ADC1 conversion channel 8
        3. DMA:
            DMA1_CH1 channel loopback mode transfers a halfword of ADC1 conversion result to ADCConvertedValue variable
        4. ADC:
            ADC1 independent working mode, continuous conversion, scan mode, software trigger, 12-bit data is right-aligned, conversion channel 8 is the analog voltage data of PC2
    Instructions:
        1. After compiling, open the debug mode and add the variable ADCConvertedValue to the watch window to observe
        2. By changing the voltage of the PC2 pin, you can see that the conversion result variable changes synchronously
4. Matters needing attention
    When the system uses HSE clock (generally HSI is also turned on), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses HSI clock (generally HSE is turned off), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI