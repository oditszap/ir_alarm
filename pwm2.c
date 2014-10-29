#include "reg51.h"

#define MAIN_Fosc       24000000UL      //定义主时钟

sfr AUXR      = 0x8e;               // 辅助寄存器
sfr INT_CLKO  = 0x8f;               // 时钟输出控制寄存器
sbit T0CLKO   = P3^5;               // 定时器0的时钟输出口

// 定时器0
// 1T模式，输出时钟频率=sysclk/(65536-[RL_TH0,RL_TL0])/2
// 12T模式，输出时钟频率=sysclk/12/(65536-[RL_TH0,RL_TL0])/2
void load_pwm(int freq)
{
	int cnt = 65536 - MAIN_Fosc/2/freq;
	TR0 = 0;
	TL0 = cnt;          			// 初始化定时器初值和重装值
    TH0 = cnt >> 8;
    TR0 = 1;                    	// 定时器0开始计时
}

void init_pwm(void)
{
	AUXR = 0x80;                    // 定时器0为1T模式
    INT_CLKO = 0x01;                // 使能定时器0的时钟输出功能
    TMOD &= 0xf0;                   // 设置定时器0为模式0(16位自动重装载)
	T0CLKO = 1;                     // 初始化时钟输出脚(软PWM口)
}
