1、功能说明
    1、对备份寄存器进行写入操作
2、使用环境
    软件开发环境：KEIL MDK-ARM V5.25
    硬件环境：
        1、基于评估板N32A455VEL7_EVB V1.0开发
        2、MCU：N32A455VEL7
3、使用说明 
    系统配置；
        1、时钟源：HSE+PLL
        2、时钟频率：144
    使用方法：
        在KEIL下编译后烧录到评估板，通过调试器进入调试模式。查看BKP窗口，全速执行后，42个备份寄存器都
              写入了对应的值。比如BKP_DAT1 = 0x3210,BKP_DAT1 = 0x326A
4、注意事项
    无


1. Function description
     1. Write the backup register
2. Use environment
     Software development environment: KEIL MDK-ARM V5.25
     Hardware environment:
         1. Developed based on the evaluation board N32A455VEL7_EVB V1.0
         2. MCU: N32A455VEL7
3. Instructions for use
     System Configuration;
         1. Clock source: HSE+PLL
         2. Clock frequency: 144
     Instructions:
         After compiling under KEIL, burn it to the evaluation board, and enter the debug mode through the debugger. Looking at the BKP window, after full speed execution, all 42 backup registers are
               The corresponding value is written. For example, BKP_DAT1 = 0x3210, BKP_DAT1 = 0x326A
4. Matters needing attention
     none