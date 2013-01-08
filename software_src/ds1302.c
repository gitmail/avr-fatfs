#include "config.h"

#define TPORT PORTB
#define TDDR DDRB
#define TPIN PINB
#define PIN_RST	 4
#define PIN_IO	 5
#define PIN_SCK	 6
/******************复位脚*********************/
#define RST_CLR	TPORT &= ~(1 << PIN_RST)   /*电平置低*/
#define RST_SET	TPORT |= (1 << PIN_RST)    /*电平置高*/
#define RST_IN	TDDR &= ~(1 << PIN_RST)    /*方向输入*/
#define RST_OUT	TDDR |= (1 << PIN_RST)     /*方向输出*/

/*****************双向数据********************/
#define IO_CLR	TPORT &= ~(1 << PIN_IO)  /*电平置低*/
#define IO_SET	TPORT |= (1 << PIN_IO)   /*电平置高*/
#define IO_R	TPIN & (1 << PIN_IO)     /*电平读取*/
#define IO_IN	TDDR &= ~(1 << PIN_IO)   /*方向输入*/
#define IO_OUT	TDDR |= (1 << PIN_IO)    /*方向输出*/

/*****************时钟信号*******************/
#define SCK_CLR	TPORT &= ~(1 << PIN_SCK)  /*时钟信号*/
#define SCK_SET	TPORT |= (1 << PIN_SCK)   /*电平置高*/
#define SCK_IN	TDDR &= ~(1 << PIN_SCK)   /*方向输入*/
#define SCK_OUT	TDDR |= (1 << PIN_SCK)    /*方向输出*/

#define ds1302_sec_add			0x80		//秒数据地址
#define ds1302_min_add			0x82		//分数据地址
#define ds1302_hr_add			0x84		//时数据地址
#define ds1302_date_add			0x86		//日数据地址
#define ds1302_month_add		0x88		//月数据地址
#define ds1302_day_add			0x8a		//星期数据地址
#define ds1302_year_add			0x8c		//年数据地址
#define ds1302_control_add		0x8e		//控制数据地址
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

unsigned char time_buf[8] = {0x20,0x0c,0x0A,0x1c,0x22,0x46,0x00,0x06};
/*
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
	*/

//DS1302初始化函数
void ds1302_init(void) 
{
	RST_CLR;			/*RST脚置低*/
	SCK_CLR;			/*SCK脚置低*/
	RST_OUT;			/*RST脚设置为输出*/
	SCK_OUT;			/*SCK脚设置为输出*/
}

//向DS1302写入一字节数据
void ds1302_write_byte(unsigned char addr, unsigned char d) {

	unsigned char i;
	RST_SET;					/*启动DS1302总线*/
	
	/*写入目标地址：addr*/
	IO_OUT;
	addr = addr & 0xFE;   //最低位置零，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;      //产生时钟
		SCK_CLR;
		addr = addr >> 1;
		}
	
	/*写入数据：d*/
	IO_OUT;
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;    //产生时钟
		SCK_CLR;
		d = d >> 1;
		}
	RST_CLR;		//停止DS1302总线
	
}

//从DS1302读出一字节数据
unsigned char ds1302_read_byte(unsigned char addr) {

	unsigned char i;
	unsigned char temp;
	RST_SET;					/*启动DS1302总线*/

	/*写入目标地址：addr*/
	IO_OUT;
	addr = addr | 0x01;    //最低位置高，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;
		SCK_CLR;
		addr = addr >> 1;
		}
	
	/*输出数据：temp*/
	IO_IN;
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO_R) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK_SET;
		SCK_CLR;
		}
	
	RST_CLR;					/*停止DS1302总线*/
	return temp;
}

//向DS302写入时钟数据
void ds1302_write_time(void) {

	ds1302_write_byte(ds1302_control_add,0x00);			//关闭写保护 
	ds1302_write_byte(ds1302_sec_add,0x80);				//暂停时钟 
	//ds1302_write_byte(ds1302_charger_add,0xa9);	    //涓流充电 
	ds1302_write_byte(ds1302_year_add,time_buf[1]);		//年 
	ds1302_write_byte(ds1302_month_add,time_buf[2]);	//月 
	ds1302_write_byte(ds1302_date_add,time_buf[3]);		//日 
	ds1302_write_byte(ds1302_hr_add,time_buf[4]);		//时 
	ds1302_write_byte(ds1302_min_add,time_buf[5]);		//分
	ds1302_write_byte(ds1302_sec_add,time_buf[6]);		//秒
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//周 
	ds1302_write_byte(ds1302_control_add,0x80);			//打开写保护 
}

//从DS302读出时钟数据
void ds1302_read_time(void)  { 
	time_buf[1]=ds1302_read_byte(ds1302_year_add);		//年 
	time_buf[2]=ds1302_read_byte(ds1302_month_add);		//月 
	time_buf[3]=ds1302_read_byte(ds1302_date_add);		//日 
	time_buf[4]=ds1302_read_byte(ds1302_hr_add);		//时 
	time_buf[5]=ds1302_read_byte(ds1302_min_add);		//分 
	time_buf[6]=(ds1302_read_byte(ds1302_sec_add))&0x7F;//秒，屏蔽秒的第7位，避免超出59
	time_buf[7]=ds1302_read_byte(ds1302_day_add);		//周 
}


