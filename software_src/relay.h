/*  继电器驱动程序
*
*引脚描述：  PORTXX
*功能描述：根据内部温度传感器的值决定是否打开继电器（启动内部加热功能）。
 */
#ifndef _RELAY_H_
#define _RELAY_H_
#include "config.h"
//设定加热器开启阈值电压



#define RELAY_PORT 		  PORTC
#define RELAY_PORT_NUM	  5
#define RELAY_DDR_SET() DDRC|=(1<<RELAY_PORT_NUM)

#define RELAY_ON()	RELAY_PORT &= ~(1 << RELAY_PORT_NUM)    /*拉低*/
#define RELAY_OFF() 	RELAY_PORT |=  (1 << RELAY_PORT_NUM)     /*拉高*/


void relay_init(void);
void relay(signed int temp);

#endif

