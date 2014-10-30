#include "configs.h"

void main()
{
	init_uart();
	SendString("STC15F2K60S2\r\nUart Test !\r\n");
	
	init_pwm();
	play_music();
	
    while(1);
}
