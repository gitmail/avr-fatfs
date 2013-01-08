#ifndef _CONFIG_H_
#define _CONFIG_H_
//debug选项
#define _DEBUG
//#define _LCDDEBUG
#define _UARTDEBUG

//类型定义
#define INT8   char
#define UINT8  unsigned char
#define INT16  int 
#define UINT16 unsigned int 
#define INT32  long 
#define UINT32 unsigned long 
#define nop()    NOP()
//基本头文件
#include "iom128v.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <macros.h>
#include "main.h"
//文件系统
#include "sd.h"
#include "SPI.h"
#include "diskio.h"
#include "ff.h"
//串口
#include "usart.h"
//延时函数
#include "delay.h"
//LCD显示
#include "lcd.h"
//蜂鸣器
#include "beep.h"
//继电器
#include "relay.h"
//温度传感器
#include "DS18B20_driver.h"
//时钟
#include "ds1302.h"
//风速传感器
//按键检测
#include "key.h"
//界面程序
#include "gui.h"
//电池电量检测
#include "powercheck.h"

struct DATA {
   char  ID;
   char  Name[9]	  ;
   unsigned int Index ;
   char IndexChar[6]  ;
   char  Date[9]	  ;
   char	Time[10] 	  ;
   float    Temperature	   ;  //温度
   char  TempChar[6]  ;       //每个数值参数都附带char型变量，用于显示或发送
   float    WindSpeed ;
   char  WSChar[5]    ;
   float    WCI ;   //风冷指数
   char  WCIChar[6]   ;
   float    ECT ;   //等价制冷温度
   char  ECTChar[6]   ;
   float    Teq ;	//相当温度
   char  TeqChar[6] ;
   unsigned char    WeiHai		  ;   //冻伤危害性(环境提示)
   unsigned char    LowLabor	  ;   //轻度
   unsigned char    MidLabor	  ;   //中度
   unsigned char    HighLabor	  ;   //重度
   };
 struct CONFIG {
 		char Sd;
		char Relay;
		char LcdBackLight;
		char BackTemp;
		long THRESHOLD_delta_sec;
		long time1;
		long now;
		char autocheck;
		
  };  
 struct tm {
   	int tm_sec;   // 秒 seconds after the minute, 0 to 60
   	int tm_min;   // 分 minutes after the hour, 0 to 59
	int tm_hour;  // 时 hours since midnight, 0 to 23*
	int tm_mday;  // 日 day of the month, 1 to 31
	int tm_mon;   // 月 months since January, 0 to 11
	int tm_year;  // 年 years since 1900
	int tm_wday;  // 星期 days since Sunday, 0 to 6
	int tm_yday;  // 从元旦起的天数 days since January 1, 0 to 365
 	int tm_isdst; // 夏令时？？Daylight Savings Time flag
 	};  
extern struct CONFIG config; 
extern const char devicename[8];//设备名称
extern const char deviceId ;	
extern  struct  tm t; //文件系统时间存储结构体
extern unsigned char time_buf[8]; //外部变量 存储上1302上时间的原始形式
extern char buffer[512];
extern unsigned long now;
extern struct DATA Result;

#endif
