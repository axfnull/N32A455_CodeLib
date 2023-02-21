1、功能说明
    1、ADC1采样转换PC0 PC1引脚的模拟电压，ADC2采样转换PC2 PC3引脚的模拟电压，ADC3采样转换PD10 PD11引脚的模拟电压，ADC4采样转换PD12 PD13引脚的模拟电压
    2、采用软件触发一次，采集一次的方式
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB V1.0 EVB开发
3、使用说明
    系统配置；
        1、时钟源：
            HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,ADC CLK=144M/16,ADC 1M CLK=HSE/8
        2、端口配置：
            PC0选择为模拟功能ADC1转换通道
            PC1选择为模拟功能ADC1转换通道
            PC2选择为模拟功能ADC2转换通道
            PC3选择为模拟功能ADC2转换通道
            PD10选择为模拟功能ADC3转换通道
            PD11选择为模拟功能ADC3转换通道
            PD12选择为模拟功能ADC4转换通道
            PD13选择为模拟功能ADC4转换通道
        3、ADC：
            ADC1独立工作模式、软件触发转换、12位数据右对齐，转换PC0 PC1的模拟电压数据
            ADC2独立工作模式、软件触发转换、12位数据右对齐，转换PC2 PC3的模拟电压数据
            ADC3独立工作模式、软件触发转换、12位数据右对齐，转换PD10 PD11的模拟电压数据
            ADC4独立工作模式、软件触发转换、12位数据右对齐，转换PD12 PD13的模拟电压数据
    使用方法：
        1、编译后打开调试模式，将变量ADC1ConvertedValue,ADC2ConvertedValue,ADC3ConvertedValue,ADC4ConvertedValue添加到watch窗口观察
        2、通过改变PC0,PC1,PC2,PC3,PD10,PD11,PD12,PD13引脚的电压，可以看到转换结果变量同步改变
4、注意事项
    当系统采用HSE时钟时（一般HSI也是打开的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)可以配置为HSE或者HSI
    当系统采用HSI时钟时（一般HSE是关闭的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)只能配置为HSI

1. Function description
    1. ADC1 samples and converts the analog voltage of PC0 PC1 pin, ADC2 samples and converts the analog voltage of PC2 PC3 pin, ADC3 samples and converts the analog voltage of PD10 PD11 pin, ADC4 samples and converts the analog voltage of PD12 PD13 pin
    2. The software triggers once and collects once
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Based on N32A455VEL7_EVB V1.0 EVB development
3. Instructions for use
    System Configuration;
        1. Clock source:
            HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,ADC CLK=144M/16,ADC 1M CLK=HSE/8
        2. Port configuration:
            PC0 is selected as the analog function ADC1 conversion channel
            PC1 is selected as the analog function ADC1 conversion channel
            PC2 is selected as the analog function ADC2 conversion channel
            PC3 is selected as the analog function ADC2 conversion channel
            PD10 is selected as the analog function ADC3 conversion channel
            PD11 is selected as the analog function ADC3 conversion channel
            PD12 is selected as the analog function ADC4 conversion channel
            PD13 is selected as the analog function ADC4 conversion channel
        3. ADC:
            ADC1 independent working mode, software-triggered conversion, 12-bit data is right-aligned, and analog voltage data of PC0 PC1 is converted
            ADC2 independent working mode, software-triggered conversion, 12-bit data is right-aligned, and analog voltage data of PC2 PC3 is converted
            ADC3 independent working mode, software-triggered conversion, 12-bit data is right-aligned, and analog voltage data of PD10 PD11 is converted
            ADC4 independent working mode, software-triggered conversion, 12-bit data is right-aligned, and analog voltage data of PD12 PD13 is converted
    Instructions:
        1. Open the debug mode after compiling, add the variables ADC1ConvertedValue, ADC2ConvertedValue, ADC3ConvertedValue, ADC4ConvertedValue to the watch window for observation
        2. By changing the voltage of PC0, PC1, PC2, PC3, PD10, PD11, PD12, PD13 pins, you can see that the conversion result variable changes synchronously
4. Matters needing attention
    When the system uses HSE clock (generally HSI is also turned on), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses HSI clock (generally HSE is turned off), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI