1、功能说明
    1、TIM5周期触发DAC CH1 CH2输出三角波数据到DAC，在PA4 PA5输出三角波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.26.2.0
    硬件环境：      基于N32A455VEL7-EVB V1.0 EVB开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,DAC CLK=36M,TIM5 CLK=72M
        2、端口配置：
                    PA4选择为模拟功能DAC CH1 OUT
                    PA5选择为模拟功能DAC CH2 OUT
        3、TIM：
                    TIM5 更新事件作为触发输出给DAC
        4、DAC：
                    DAC选择TIM5 TRGO信号触发，开启CH1 CH2两个通道，使能三角波幅度2048，基值0X100
    使用方法：
        1、编译后打开调试模式，利用示波器观察PA4 PA5输出波形
        2、全速运行时，TIM5的每个周期触发PA4 PA5的一个数据，形成三角波
4、注意事项
    无


1. Function description
     1. TIM5 periodically triggers DAC CH1 CH2 to output triangular wave data to DAC, and outputs triangular waveform in PA4 PA5
2. Use environment
     Software development environment: KEIL MDK-ARM V5.26.2.0
     Hardware environment: Based on N32A455VEL7-EVB V1.0 EVB development
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,DAC CLK=36M,TIM5 CLK=72M
         2. Port configuration:
                     PA4 is selected as analog function DAC CH1 OUT
                     PA5 is selected as analog function DAC CH2 OUT
         3. TIM:
                     TIM5 update event as trigger output to DAC
         4. DAC:
                     The DAC selects the TIM5 TRGO signal to trigger, opens the two channels of CH1 and CH2, enables the amplitude of the triangular wave to be 2048, and the base value is 0X100
     Instructions:
         1. Open the debug mode after compiling, and use the oscilloscope to observe the output waveform of PA4 and PA5
         2. When running at full speed, each cycle of TIM5 triggers a data of PA4 and PA5 to form a triangular wave
4. Matters needing attention
     none