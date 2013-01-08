 
#ifndef _POWER_H_
#define _POWER_H_
#include "config.h"

#define POWER_PORT 	  PIN
#define POWER_PIN	  4
#define POWER_DDR_SET() DDRC&=!(1<<POWER_PIN)

#define LED_PORT  PORTC
#define LED_PIN	  7
#define LED_DDR   DDRC

#define LED_OFF()	DDRC|=(1<<LED_PIN);LED_PORT &= ~(1 << LED_PIN)    /*À­µÍ*/
#define LED_ON() 	DDRC|=(1<<LED_PIN);LED_PORT |=  (1 << LED_PIN)     /*À­¸ß*/

 

#endif

