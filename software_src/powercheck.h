 
#ifndef _POWER_H_
#define _POWER_H_
#include "config.h"
//2013.06.24 bakeup
//#define POWER_PORT 	  PINC
//#define POWER_PIN	  4
//#define POWER_DDR_SET() DDRC&=!(1<<POWER_PIN)
//定义端口号 power低的输入脚为PINE_4
#define POWER_DDR DDRE
#define POWER_PIN PINE
#define POWER_PIN_MASK   (1<<4)
//设置端口方向
#define POWER_DDR_SET() POWER_DDR&=~POWER_PIN_MASK

//读取端口电平 
#define POWER_PIN_READ() ((POWER_PIN)&(POWER_PIN_MASK))
//低电平显示led，低有效。
#define LED_PORT  PORTC
#define LED_PIN	  7
#define LED_DDR   DDRC

#define LED_ON()	LED_DDR|=(1<<LED_PIN);LED_PORT &= ~(1 << LED_PIN)    /*拉低*/
#define LED_OFF() 	LED_DDR|=(1<<LED_PIN);LED_PORT |=  (1 << LED_PIN)     /*拉高*/

void power_check_init(void);
void power_state_refresh(void);

#endif

