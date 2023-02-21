1、功能说明

    1、此例程展示读取端口高低电平，控制 LED（D6、D17）闪烁
    2、控制 JTAG 和 SWD 接口配置成普通 IO 口进行电平翻转

2、使用环境

    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32A455VEL7-EVB V1.0

3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
    SystemClock：144MHz
    GPIO：PA0 选择作为读取电平端口，PA11、PA12 控制 LED(RED、GREEN) 闪烁

    /* 描述Demo的测试步骤和现象 */
    1.编译后下载程序复位运行；
    2.将 PA0 接入 3.3V GREEN 亮，RED 灭；PA0 断开，GREEN 灭，RED 亮，用示波器看 PA13、PA14、PA15、PB3、PB4 IO 电平翻转；

4、注意事项
    JTAG 和 SWD 接口配置成普通 IO 后，需要将 BOOT0 管脚接到 3.3V，通过 BOOT 重新下载


1. Function description

     1. This routine shows the high and low levels of the read port and controls the flashing of the LEDs (D6, D17)
     2. Control the JTAG and SWD interfaces to be configured as ordinary IO ports for level flipping

2. Use environment

     /* Hardware environment: the development hardware platform corresponding to the project */
     Development board: N32A455VEL7-EVB V1.0

3. Instructions for use
    
     /* Describe related module configuration methods; for example: clock, I/O, etc. */
     SystemClock: 144MHz
     GPIO: PA0 is selected as the read level port, PA11, PA12 control LED (RED, GREEN) to flash

     /* Describe the test steps and phenomena of the Demo */
     1. After compiling, download the program to reset and run;
     2. Connect PA0 to 3.3V, GREEN is on, RED is off; PA0 is disconnected, GREEN is off, RED is on, use an oscilloscope to see the IO level inversion of PA13, PA14, PA15, PB3, PB4;

4. Matters needing attention
     After the JTAG and SWD interfaces are configured as ordinary IO, you need to connect the BOOT0 pin to 3.3V, and re-download through BOOT