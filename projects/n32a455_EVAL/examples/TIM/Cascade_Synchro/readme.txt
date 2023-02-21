1、功能说明
    1、TIM2周期门控TIM3，TIM3周期门控TIM4
2、使用环境
    软件开发环境：  KEIL MDK-ARM 5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB v1.0.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM2 CLK=72M,TIM3 CLK=72M,TIM4 CLK=72M
        2、端口配置：
                    PA0选择为TIM2 CH1输出
                    PA6选择为TIM3 CH1输出
                    PB6选择为TIM4 CH1输出
        3、TIM：
                    TIM2 的周期门控TIM3，TIM3的周期门控TIM4
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM2 CH1，TIM3 CH1，TIM4 CH1波形
        2、TIM3 4倍周期TIM2，TIM4 4倍周期TIM3
4、注意事项
    无



1. Function description
     1. TIM2 cycle gate TIM3, TIM3 cycle gate TIM4
2. Use environment
     Software development environment: KEIL MDK-ARM 5.34.0.0
     Hardware Environment: Developed based on N32A455VEL7_EVB v1.0.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM2 CLK=72M,TIM3 CLK=72M,TIM4 CLK=72M
         2. Port configuration:
                     PA0 is selected as TIM2 CH1 output
                     PA6 is selected as TIM3 CH1 output
                     PB6 is selected as TIM4 CH1 output
         3. TIM:
                     The period gate of TIM2 is TIM3, the period gate of TIM3 is TIM4
     Instructions:
         1. Open the debug mode after compiling, and observe the TIM2 CH1, TIM3 CH1, TIM4 CH1 waveforms with an oscilloscope or logic analyzer
         2. TIM3 4 times the period TIM2, TIM4 4 times the period TIM3
4. Matters needing attention
     none