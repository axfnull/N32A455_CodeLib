1、功能说明
    1、systick 100ms触发TIM1输出6步换相波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM 5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB v1.0.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM1 CLK=144M
        2、中断：
                    TIM1 COM事件中断打开，抢断优先级0，子优先级1
                    Systick 100ms中断，优先级0
        3、端口配置：
                    PA8选择为TIM1 CH1输出
                    PA9选择为TIM1 CH2输出
                    PA10选择为TIM1 CH3输出
                    PB13选择为TIM1 CH1N输出
                    PB14选择为TIM1 CH2N输出
                    PB15选择为TIM1 CH3N输出
                    PB12选择为TIM1 Breakin输入
        4、TIM：
                    TIM1 6路互补冻结输出模式，无刹车，开COM中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1的输出波形
        2、每隔100ms systick触发COM中断，在TIM的COM中断里面输出AB AC BC BA CA CB的6步换相波形
4、注意事项
    无



1. Function description
    1. systick triggers TIM1 for 100ms to output 6-step commutation waveform
2. Use environment
    Software development environment: KEIL MDK-ARM 5.34.0.0
    Hardware Environment: Developed based on N32A455VEL7_EVB v1.0.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM1 CLK=144M
        2. Interrupt:
                    TIM1 COM event interrupt on, steal priority 0, sub priority 1
                    Systick 100ms interrupt, priority 0
        3. Port configuration:
                    PA8 is selected as TIM1 CH1 output
                    PA9 is selected as TIM1 CH2 output
                    PA10 is selected as TIM1 CH3 output
                    PB13 is selected as TIM1 CH1N output
                    PB14 is selected as TIM1 CH2N output
                    PB15 is selected as TIM1 CH3N output
                    PB12 is selected as TIM1 Breakin input
        4. TIM:
                    TIM1 6-channel complementary freeze output mode, no brake, open COM interrupt
    Instructions:
        1. Open the debug mode after compiling, and observe the output waveform of TIM1 with an oscilloscope or logic analyzer
        2. The systick triggers the COM interrupt every 100ms, and outputs the 6-step commutation waveform of AB AC BC BA CA CB in the COM interrupt of the TIM
4. Matters needing attention
    none