//////////////////////////////////////////////////////////////
//按键扫描程序1.0
/*  说明：
     按键 硬件接口图
			 
  端口初始化方式：
  PORTA = 0xff;
  DDRA  = 0x3F;
 
  main 中应包含：
 //定时器T0初始化
void timer0_init(void)
{
 TCCR0  = 0x00;//停止定时器
 TCNT0  = 0xB8;//初始值
 OCR0   = 0xB7;//匹配值
 TIMSK |= 0x01;//中断允许
 TCCR0  = 0x05;//启动定时器
}                             

//T0溢出中断服务程序
#pragma interrupt_handler timer0_ovf_isr:10
void timer0_ovf_isr(void)
{
 TCNT0 = 0xB8;
 
 
kbscan_en=1;
}


*/

/////////////////////////////////////////////////////////////////


#include "config.h"
#define up 0B00011110
#define down 0B00011101
#define left 0B00011011
#define right 0B00010111
#define ok 0B00001111
//长按
#define lup 0B10011110
#define ldown 0B10011101
#define lleft 0B10011011
#define lright 0B10010111
#define lok 0B10001111
//长短按区分界限常量  80000约等于1秒
#define LONGKEY  80000
 
#define NO_KEY 0x00


#define DDR_SET DDRA &= 0x07
//#define KEY_PORT   PORTA
#define KEY_PIN    PINA&KEY_MASK
#define KEY_MASK   0X1F  
unsigned char kbscan(void);