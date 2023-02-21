1、功能说明
    1、TIM3 CH1 CH2 CH3 CH4 达到CC值后输出翻转，并且比较值累加
2、使用环境
    软件开发环境：  KEIL MDK-ARM 5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB v1.0.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM3 CLK=72M
        2、中断：
                    TIM3 比较中断打开，抢断优先级0，子优先级0
        3、端口配置：
                    PA6选择为TIM3的CH1输出
                    PA7选择为TIM3的CH2输出
                    PB0选择为TIM3的CH3输出
                    PB1选择为TIM3的CH4输出
        4、TIM：
                    TIM3 配置好CH1 CH2 CH3 CH4的比较值输出翻转，并打开比较中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM3 的CH1 CH2 CH3 CH4的波形
        2、每当达到比较值时，输出翻转，并且再增加同样的比较值，波形占空比为50%
4、注意事项
    无


1. Function description
    1. After TIM3 CH1 CH2 CH3 CH4 reaches the CC value, the output is flipped, and the comparison value is accumulated
2. Use environment
    Software development environment: KEIL MDK-ARM 5.34.0.0
    Hardware Environment: Developed based on N32A455VEL7_EVB v1.0.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM3 CLK=72M
        2. Interrupt:
                    TIM3 compare interrupt on, steal priority 0, sub-priority 0
        3. Port configuration:
                    PA6 is selected as CH1 output of TIM3
                    PA7 is selected as CH2 output of TIM3
                    PB0 is selected as the CH3 output of TIM3
                    PB1 is selected as CH4 output of TIM3
        4. TIM:
                    TIM3 configures the comparison value output of CH1 CH2 CH3 CH4 to flip, and open the comparison interrupt
    Instructions:
        1. Open the debug mode after compiling, and observe the waveforms of CH1 CH2 CH3 CH4 of TIM3 with an oscilloscope or logic analyzer
        2. Whenever the comparison value is reached, the output is flipped, and the same comparison value is added again, and the waveform duty cycle is 50%
4. Matters needing attention
    none