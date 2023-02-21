1、功能说明
    1、TIM2 CH1 CH2 CH3 CH4 达到CC值后，对应拉低PC6 PC7 PC8 PC9的IO电平
2、使用环境
    软件开发环境：  KEIL MDK-ARM 5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB v1.0.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM2 CLK=72M
        2、中断：
                    TIM2 比较中断打开，抢断优先级0，子优先级1
        3、端口配置：
                    PC6选择为IO 输出
                    PC7选择为IO 输出
                    PC8选择为IO 输出
                    PC9选择为IO 输出
        4、TIM：
                    TIM2 配置好CH1 CH2 CH3 CH4的比较值，并打开比较中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察PC6 PC7 PC8 PC9的波形
        2、定时器运进入CC1 CC2 CC3 CC4中断后,对应拉低PC6 PC7 PC8 PC9的IO
4、注意事项
    无


1. Function description
    1. After TIM2 CH1 CH2 CH3 CH4 reaches the CC value, correspondingly pull down the IO level of PC6 PC7 PC8 PC9
2. Use environment
    Software development environment: KEIL MDK-ARM 5.34.0.0
    Hardware Environment: Developed based on N32A455VEL7_EVB v1.0.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM2 CLK=72M
        2. Interrupt:
                    TIM2 compare interrupt on, steal priority 0, sub-priority 1
        3. Port configuration:
                    PC6 is selected as IO output
                    PC7 is selected as IO output
                    PC8 is selected as IO output
                    PC9 is selected as IO output
        4. TIM:
                    TIM2 configures the comparison value of CH1 CH2 CH3 CH4 and turns on the comparison interrupt
    Instructions:
        1. Open the debug mode after compiling, and observe the waveforms of PC6 PC7 PC8 PC9 with an oscilloscope or logic analyzer
        2. After the timer runs into CC1, CC2, CC3, and CC4, the IO of PC6, PC7, PC8, and PC9 is pulled down correspondingly.
4. Matters needing attention
    none