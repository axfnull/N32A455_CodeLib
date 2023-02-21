1、功能说明
    1、TIM3 CH2上升沿计算频率
2、使用环境
    软件开发环境：  KEIL MDK-ARM 5.34.0.0
    硬件环境：      基于N32A455VEL7_EVB v1.0.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM3 CLK=72M
        2、中断：
                    TIM3 CH2上升沿中断打开，抢断优先级0，子优先级1
        3、端口配置：
                    PA7选择为TIM3 CH2输入
                    PA3选择为IO 输出
        4、TIM：
                    TIM3 CH2 上升沿捕获中断打开,捕获的频率范围最小为((TIM3 CLK)/0xffff)Hz,最大频率为((TIM3 CLK)/1)Hz
    使用方法：
        1、编译后打开调试模式，连接PA3与PA7，将变量TIM3Freq添加到watch窗口
        2、程序控制PA3电平翻转后，查看TIM3Freq计算的频率值
4、注意事项
    无



1. Function description
     1. Calculate the frequency on the rising edge of TIM3 CH2
2. Use environment
     Software development environment: KEIL MDK-ARM 5.34.0.0
     Hardware Environment: Developed based on N32A455VEL7_EVB v1.0.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=144M,AHB=144M,APB1=36M,APB2=72M,TIM3 CLK=72M
         2. Interrupt:
                     TIM3 CH2 rising edge interrupt on, steal priority 0, sub-priority 1
         3. Port configuration:
                     PA7 is selected as TIM3 CH2 input
                     PA3 is selected as IO output
         4. TIM:
                     TIM3 CH2 rising edge capture interrupt is turned on, the minimum capture frequency range is ((TIM3 CLK)/0xffff)Hz, and the maximum frequency is ((TIM3 CLK)/1)Hz
     Instructions:
         1. Open the debug mode after compiling, connect PA3 and PA7, and add the variable TIM3Freq to the watch window
         2. After the program controls the PA3 level to flip, check the frequency value calculated by TIM3Freq
4. Matters needing attention
     none