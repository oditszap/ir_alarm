#include "reg51.h"

typedef unsigned char	u8;
typedef unsigned int	u16;
typedef unsigned long	u32;

void init_uart();
void SendData(unsigned char dat);
void SendString(char *s);

void init_pwm(void);
void load_pwm(int freq);

void play_music(void);