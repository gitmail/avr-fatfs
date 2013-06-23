 
#ifndef _POWER_H_
#define _POWER_H_
#include "config.h"
//2013.06.24 bakeup
//#define POWER_PORT 	  PINC
//#define POWER_PIN	  4
//#define POWER_DDR_SET() DDRC&=!(1<<POWER_PIN)
//定义端口号 假设power低的输入脚为PORTC_5
#define POWER_DDR DDRC
#define POWER_PORT PINC
#define POWER_PIN_MASK   (1<<5)
//设置端口方向
#define POWER_DDR_SET() POWER_DDR&=~POWER_PIN_MASK

//读取端口电平 
#define POWER_PIN_READ()    POWER_PORT&POWER_PIN_MASK

#define LED_PORT  PORTC
#define LED_PIN	  7
#define LED_DDR   DDRC

#define LED_OFF()	DDRC|=(1<<LED_PIN);LED_PORT &= ~(1 << LED_PIN)    /*拉低*/
#define LED_ON() 	DDRC|=(1<<LED_PIN);LED_PORT |=  (1 << LED_PIN)     /*拉高*/

void power_check_init(void);
void power_state_refresh(void);

#endif

