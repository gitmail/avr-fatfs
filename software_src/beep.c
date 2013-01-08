#include "config.h"

#define BEEP_PORT	PORTC
#define BEEP_PIN	6
#define BEEP_OFF() BEEP_PORT|=(1<<BEEP_PIN)
#define BEEP_ON()  BEEP_PORT&=~(1<<BEEP_PIN)
//蜂鸣器
void beep(unsigned char long_beep,unsigned char short_beep)
{ 
unsigned char i;
DDRB|=(1<<0);
for(i=0;i<long_beep;i++)
{
BEEP_ON();  delayms(200);
BEEP_OFF(); delayms(50);
}
delayms(100);
for(i=0;i<short_beep;i++)
{
BEEP_ON();  delayms(80);
BEEP_OFF(); delayms(50);
}

}