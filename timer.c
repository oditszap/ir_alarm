#include "reg51.h"

typedef unsigned char BYTE;
typedef unsigned int WORD;

#define FOSC 18432000L

#define T1MS (65536-FOSC/1000)      //1T模式
//#define T1MS (65536-FOSC/12/1000) //12T模式

sfr AUXR = 0x8e;                    //Auxiliary register
sbit P10 = P1^0;

//-----------------------------------------------

/* Timer1 interrupt routine */
void tm1_isr() interrupt 3 using 1
{
    P10 = ! P10;                    //将测试口取反
}

//-----------------------------------------------

/* main program */
void main()
{
    AUXR |= 0x40;                   //定时器1为1T模式
//  AUXR &= 0xdf;                   //定时器1为12T模式

    TMOD = 0x00;                    //设置定时器为模式0(16位自动重装载)
	
    TL1 = T1MS;                     //初始化计时值
    TH1 = T1MS >> 8;
    TR1 = 1;                        //定时器1开始计时
    ET1 = 1;                        //使能定时器0中断
    EA = 1;

    while (1);
}

void init_timer(void)
{
	AUXR |= 0x40;                   //定时器1为1T模式
    TMOD = 0x00;                    //设置定时器为模式0(16位自动重装载)
}

void load_timer(int time)
{
	int cnt = 65536-FOSC/time;
	TL1 = cnt;                     //初始化计时值
    TH1 = cnt >> 8;
    TR1 = 1;                        //定时器1开始计时
    ET1 = 1;                        //使能定时器0中断
    EA = 1;
}

