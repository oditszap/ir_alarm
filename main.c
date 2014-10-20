#include <REG52.H>

void main (void)
{
    SCON = 0x50;   
    TMOD = 0x20;   
    TH1 = 0xFD;    //9600bps@11.0592MHz
    TL1 = 0xFD;
    TR1 = 1;                        
    ES  = 1;      
    EA  = 1;
    while(1) ;
}
