1、功能说明
    1、TIM4周期触发DAC CH1 CH2两个通道DMA搬运正弦波数据到DAC，在PA4 PA5输出正弦波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.26.2.0
    硬件环境：      基于N32A455VEL7-EVB V1.0 EVB开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,DAC CLK=36M,TIM4 CLK=72M，DMA CLK=144M
        2、端口配置：
                    PA4选择为模拟功能DAC CH1 OUT
                    PA5选择为模拟功能DAC CH2 OUT
        3、TIM4：
                    TIM4 更新事件作为触发输出给DAC
        4、DAC：
                    DAC选择TIM4 TRGO信号触发，开启CH1 CH2两个通道，使能CH2 DMA
        5、DMA：
                    DMA2_CH4通道回环模式搬运32个字的DualSine12bit[32]数组到DAC 双通道数据寄存器
    使用方法：
        1、编译后打开调试模式，利用示波器观察PA4 PA5输出波形
        2、全速运行时，可看到PA4 PA5输出正弦波形
4、注意事项
    无

1. Function description
    1. TIM4 cycle triggers DAC CH1 CH2 two channels DMA to transfer sine wave data to DAC, and output sine wave in PA4 PA5
2. Use environment
    Software development environment: KEIL MDK-ARM V5.26.2.0
    Hardware environment: Based on N32A455VEL7-EVB V1.0 EVB development
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,DAC CLK=36M,TIM4 CLK=72M,DMA CLK=144M
        2. Port configuration:
                    PA4 is selected as analog function DAC CH1 OUT
                    PA5 is selected as analog function DAC CH2 OUT
        3. TIM4:
                    TIM4 update event as trigger output to DAC
        4. DAC:
                    The DAC selects the TIM4 TRGO signal to trigger, turns on the two channels of CH1 CH2, and enables the CH2 DMA
        5. DMA:
                    DMA2_CH4 channel loopback mode transfers 32-word DualSine12bit[32] array to DAC dual channel data register
    Instructions:
        1. Open the debug mode after compiling, and use the oscilloscope to observe the output waveform of PA4 and PA5
        2. When running at full speed, you can see the output sine waveform of PA4 and PA5
4. Matters needing attention
    none