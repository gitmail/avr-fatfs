#include "config.h"

//此硬件引脚适合冷强度检测仪第2版电路  mega128
#define LCD_PIN_CS   4
#define LCD_PIN_SID  3
#define LCD_PIN_SCLK 2
#define LCD_PIN_RST  1
#define LCD_BACKLIGHT_SW		0
#define LCD_PORT PORTC
#define LCD_PIN_DDR DDRC
#define Set_CS()     LCD_PIN_DDR |= (1<<LCD_PIN_CS)  ;LCD_PORT |= (1<<LCD_PIN_CS) 
#define Set_SID()    LCD_PIN_DDR |= (1<<LCD_PIN_SID) ;LCD_PORT |= (1<<LCD_PIN_SID) 
#define Set_SCLK()   LCD_PIN_DDR |= (1<<LCD_PIN_SCLK);LCD_PORT |= (1<<LCD_PIN_SCLK) 
#define LCD_LIGHT_ON()   LCD_PIN_DDR |= (1<<LCD_BACKLIGHT_SW);LCD_PORT |= (1<<LCD_BACKLIGHT_SW) 
#define Set_RST()   LCD_PIN_DDR |= (1<<LCD_PIN_RST);LCD_PORT |= (1<<LCD_PIN_RST) 

#define Clr_CS()     LCD_PIN_DDR |= (1<<LCD_PIN_CS)  ;LCD_PORT &=~(1<<LCD_PIN_CS) 
#define Clr_SID()    LCD_PIN_DDR |= (1<<LCD_PIN_SID) ;LCD_PORT &=~(1<<LCD_PIN_SID) 
#define Clr_SCLK()   LCD_PIN_DDR |= (1<<LCD_PIN_SCLK);LCD_PORT &=~(1<<LCD_PIN_SCLK) 
#define LCD_LIGHT_OFF()   LCD_PIN_DDR |= (1<<LCD_BACKLIGHT_SW);LCD_PORT &=~(1<<LCD_BACKLIGHT_SW) 
#define Clr_RST()   LCD_PIN_DDR |= (1<<LCD_PIN_RST);LCD_PORT &=~(1<<LCD_PIN_RST) 
 
void W_1byte(unsigned char RW, unsigned char RS, unsigned char W_data); 
void Write_8bits(unsigned int W_bits); 
void LCD_Init(void); 
unsigned char LCD_INT(void); 

unsigned char LCD_SW(unsigned char i)
{
 if(i==0){
 LCD_LIGHT_OFF();
 return 0;
 }
 else{
 LCD_LIGHT_ON();
 return 1;
 }
 
}
 
unsigned char LCD_INT(void) 
{ 
  Clr_CS(); 
  Clr_SID(); 
  Clr_SCLK(); 
  LCD_Init(); 
  return (0);
} 
  
/******************************************************************** 
函数 名：address
入口参数：地址转换
出口参数：无 
函数作用： 
说        明： 
********************************************************************/ 
unsigned char address(unsigned char x,unsigned char y)
{  
 unsigned char a;

switch(x) 
{ 
case 1: 
{a=0x80;break;} 
case 2: 
{a=0x90;break;} 
  case 3: 
{a=0x88;break;} 
  case 4: 
{a=0x98;break;} 
} 
a=a+y-1;

return a;
}
 
//////////////////////////////////////////////////////////////

/******************************************************************** 
函数 名：LCD_const_disp
入口参数：x y  *single_data
出口参数：无 
函数作用：负责 显示一串常量
说        明： 
********************************************************************/ 
void LCD_const_disp(unsigned char x, unsigned char y, const unsigned char *single_data) 
{ 
unsigned char  a,i; 
a=address(x,y);
W_1byte(0,0,a);     //显示的地址 
   for(i=0; single_data[i]!='\0';i++) 
   {
    if(i>=16) break; 
    W_1byte(0,1,single_data[i]); 
    
   } 
   W_1byte(0,0,0XFF); // 移走地址指针 防止下一输入内容的干扰
 
} 

/******************************************************************** 
函数 名：LCD_var_disp
入口参数：single_row single_line  *single_data
出口参数：无 
函数作用：负责 显示一串变量
说        明： 
********************************************************************/ 

void LCD_var_disp(unsigned char x, unsigned char y, unsigned char *single_data) 
{ 
unsigned char  a,i; 

#if _debug == 1 
	PrintString_n(single_data);
#endif 

a=address( x,y);
W_1byte(0,0,a);     //显示的地址0x88 

for(i=0; single_data[i]!='\0';i++) 
   { 
    if(i>=16) break;
    W_1byte(0,1,single_data[i]); 
	} 
  W_1byte(0,0,0XFF); // 移走地址指针 防止下一输入内容的干扰
} 
/******************************************************************** 
函数 名：LCD_char_disp
入口参数：single_row single_line  data
出口参数：无 
函数作用：负责 显示一个 变量
说        明： 
********************************************************************/ 

void LCD_char_disp(unsigned char x, unsigned char y, unsigned char data) 
{ 
unsigned char a; 
a=address(x,y);
W_1byte(0,0,a);     //显示的地址 
W_1byte(0,1,data);  //显示内容
 
  W_1byte(0,0,0XFF); // 移走地址指针 防止下一输入内容的干扰
} 

/******************************************************************** 
函数 名：LCD_Init
入口参数：无
出口参数：unsigned char  0/1
函数作用：负责 清空液晶显示
说        明： 
********************************************************************/ 
void LCD_Init(void) 
{ 
   unsigned char cmd; 
   cmd=0x30;      //功能设置 8 位数据，基本指令 
  W_1byte(0,0,cmd); 
  delayms(2); 
  cmd=0x0C;      //显示状态 ON，游标OFF，反白OFF 
  W_1byte(0,0,cmd); //写指令 
  delayms(2); 
  cmd=0x01;      //清除显示 
  W_1byte(0,0,cmd); //写指令 
  delayms(2); 
  cmd=0x02;      //地址归位 
  W_1byte(0,0,cmd); //写指令 
  delayms(2); 
  cmd=0x80;      //设置DDRAM 地址 
  W_1byte(0,0,cmd); //写指令 
  delayms(2);     //延时 
} 

void LCD_CLR(void)
{
unsigned char cmd;
  cmd=0x01;      //清除显示 
  W_1byte(0,0,cmd); //写指令 
  delayms(1); 
  cmd=0x02;      //地址归位 
  W_1byte(0,0,cmd); //写指令 
  delayms(1); 
  cmd=0x80;      //设置DDRAM 地址 
  W_1byte(0,0,cmd); //写指令 
  delayms(1);     //延时

}
 
/*******************************************************************
函 数 名：W_1byte
入口参数：RW、RS、W_data
出口参数：无
建立日期：2007年3月3日
修改日期：
函数作用：写一个字节的数据到12864液晶，包括指令和数据
说    明：RW=1，从液晶读数据到MCU；RW=0，写一个数据到液晶；
		 （一般RW都设为0，即只向液晶写数据，不读数据）
          RS=1，写入的是数据；RS=0，写入的是指令；
		  一般模式：RW=0，RS=1;写数据
		  			RW=0，RS=0;写指令
********************************************************************/
void W_1byte(unsigned char RW, unsigned char RS, unsigned char W_data)
{
	unsigned int H_data,L_data,S_ID = 0xf8;	 //11111RWRS0
	if(RW == 0)
	{
	 	S_ID &=~ 0x04;
	}
	else					//if(RW==1)
	{
	 	S_ID |= 0X04;
	}
	if(RS == 0)
	{
	 	S_ID &=~ 0x02;
	}
	else					//if(RS==1)
	{
	 	S_ID |= 0X02;
	}
	H_data = W_data;
	H_data &= 0xf0;			//屏蔽低4位的数据
	L_data = W_data;	   	//xxxx0000格式
	L_data &= 0x0f;			//屏蔽高4位的数据
	L_data <<= 4;			//xxxx0000格式
	Set_CS();
	Write_8bits(S_ID); 		//发送S_ID
	Write_8bits(H_data);	//发送H_data
	Write_8bits(L_data);	//发送L_data
	Clr_CS();	Clr_CS();	Clr_CS();	
	 

}
/********************************************************************
函 数 名：Write_8bits
入口参数：W_bits
出口参数：无
建立日期：2007年3月3日
修改日期：
函数作用：负责串行输出8个bit位
说    明：
********************************************************************/
void Write_8bits(unsigned int W_bits)
{
	unsigned int i,Temp_data;
	for(i=0; i<8; i++)
	{
		Temp_data = W_bits;
		Temp_data <<= i;
		if((Temp_data&0x80)==0) 
		{
		 	Clr_SID();
		}
		else
		{
		 	Set_SID();
		} 
		NOP();
		Set_SCLK();
		NOP();
		NOP();
		Clr_SCLK();
		NOP();
		Clr_SID();
	}
}
 
/********************************************************************
函 数 名：Set_Draw(
入口参数：无
出口参数：无
函数作用：设置为绘图模式
说    明：
********************************************************************/
void Set_Draw(void)
{  	
	//W_1byte(0,0,0x34);			//8BIT控制界面，扩充指令集,，绘图显示OFF
	W_1byte(0,0,0x36);
	delayms(1);					//延时
} 
 

/******************************************************************** 
函数 名：Set_White 
入口参数：  x,   y,  end_x,  clear
出口参数：无 
函数作用： 设置反显
说        明： 
********************************************************************/ 
void Set_White(unsigned char x,unsigned char y,unsigned char end_x,unsigned char clear)
{
 
	unsigned char i, j, white_x, white_y,white_end_x,clr_x,clr_y ;		//
  
	W_1byte(0,0,0x36);	  //8BIT控制界面，扩充指令集,，绘图显示ON
	delayus(20);					//延时
 
	white_end_x = (end_x-x+1);
	white_end_x <<= 1;
	if(y==1)   //x,1  a=80+x-1                   
	{
	 	white_x = (0x80+x-1); 
		white_y = 0x80;
		clr_x = 0x80;
		clr_y = 0x80;
	}
	else if(y==2)
	{
	 	white_x = (0x80+x-1);
		white_y = 0x90;
		clr_x = 0x80;
		clr_y = 0x90;
	}
	else if(y==3)
	{
	 	white_x = (0x88+x-1);
		white_y = 0x80;
		clr_x = 0x88;
		clr_y = 0x80;
	}
	else if(y==4)
	{
	 	white_x = (0x88+x-1);
		white_y = 0x90;
		clr_x = 0x88;
		clr_y = 0x90;
	}
  if(clear==0)//要反白时，先将整行的液晶全部清成不反白（此处行指y）
	{
	 	for(i=0;i<16;i++ )			//16行
		{
		 	W_1byte(0,0,clr_y++);	//设置绘图区的Y地址坐标0
			W_1byte(0,0,clr_x);		//设置绘图区的X地址坐标0
			for(j=0;j<16;j++)		//
			{
			 	W_1byte(0,1,0x00);	//清成不反白
			 	nop();
			}
		}
	}
	nop();
//	
	for(i=0;i<16;i++ )				//16行，因为是16*16汉字
	{
		W_1byte(0,0,white_y++);		//设置绘图区的Y地址坐标0
		W_1byte(0,0,white_x);		//设置绘图区的X地址坐标0
		for(j=0;j<white_end_x;j++)	//
		{
			 if(clear==1)
			 {
			  	W_1byte(0,1,0x00); //取消这一行的8个点的反白，液晶地址自动加1
								   //（此处行指一个一个液晶点所组成的行）
			 }
			 else
			 {
				W_1byte(0,1,0xff); //反白这一行的8个点，液晶地址自动加1
								   //（此处行指一个一个液晶点所组成的行）
			 }
			nop();
		}
	}
	W_1byte(0,0,0x30);		//基本指令集,，绘图显示OFF
 }

/******************************************************************** 
函数 名：set_white_n
入口参数： n ,  clear
出口参数：无 
函数作用：   将四行分成八个位置。n代表位置1-8。本函数用于反显或取消反显
          某一位置的文字。
说        明： 例如 set_white_n(1,0); 表示反显第一行前四个字
********************************************************************/ 
void set_white_n(unsigned char n,unsigned char clear)
{
unsigned char tempx,tempy,tempendx;
if(n==1) {tempx=1;tempy=1;tempendx=4;}
else if(n==2) {tempx=5;tempy=1;tempendx=8;}
else if(n==3) {tempx=1;tempy=2;tempendx=4;}
else if(n==4) {tempx=5;tempy=2;tempendx=8;}
else if(n==5) {tempx=1;tempy=3;tempendx=4;}
else if(n==6) {tempx=5;tempy=3;tempendx=8;}
else if(n==7) {tempx=1;tempy=4;tempendx=4;}
else if(n==8) {tempx=5;tempy=4;tempendx=8;}
Set_White(tempx,tempy,tempendx,clear);

}
 
/******************************************************************** 
函数 名：clr_white
入口参数： 清所有 反白
出口参数：无 
函数作用： 
说        明： 
********************************************************************/ 
void clr_white(void)
{      unsigned char i,j;

       unsigned char  clr_y=0x80;
	   unsigned char  clr_x=0x80;
	   W_1byte(0,0,0x36);	  //8BIT控制界面，扩充指令集,，绘图显示ON
	 	for(i=0;i<16;i++ )			//16行
		{
		 	W_1byte(0,0,clr_y++);	//设置绘图区的Y地址坐标0
			W_1byte(0,0,clr_x);		//设置绘图区的X地址坐标0
			for(j=0;j<16;j++)		//
			{
			 	W_1byte(0,1,0x00);	//清成不反白
			 	nop();
			}
		}
	
	    clr_y=0x80;
	    clr_x=0x90;
		 	for(i=0;i<16;i++ )			//16行
		{
		 	W_1byte(0,0,clr_y++);	//设置绘图区的Y地址坐标0
			W_1byte(0,0,clr_x);		//设置绘图区的X地址坐标0
			for(j=0;j<16;j++)		//
			{
			 	W_1byte(0,1,0x00);	//清成不反白
			 	nop();
			}
		}   
	   
	     clr_y=0x88;
	     clr_x=0x80;
		 	for(i=0;i<16;i++ )			//16行
		{
		 	W_1byte(0,0,clr_y++);	//设置绘图区的Y地址坐标0
			W_1byte(0,0,clr_x);		//设置绘图区的X地址坐标0
			for(j=0;j<16;j++)		//
			{
			 	W_1byte(0,1,0x00);	//清成不反白
			 	nop();
			}
		} 
	     clr_y=0x88;
	     clr_x=0x90;
		 	for(i=0;i<16;i++ )			//16行
		{
		 	W_1byte(0,0,clr_y++);	//设置绘图区的Y地址坐标0
			W_1byte(0,0,clr_x);		//设置绘图区的X地址坐标0
			for(j=0;j<16;j++)		//
			{
			 	W_1byte(0,1,0x00);	//清成不反白
			 	nop();
			}
		} 		
  W_1byte(0,0,0x30);	  //8BIT控制界面，扩充指令集,，绘图显示ON
	}
/******************************************************************** 
函数 名：LCD_print2num
入口参数： 显示2数字
出口参数：无 
函数作用： 
说        明： 
********************************************************************/ 
void LCD_print2num(unsigned char x,unsigned char y,unsigned char num){
unsigned char tem;
unsigned char a; 

a=address(x,y);
W_1byte(0,0,a);     //显示的地址 
tem=num/10;
W_1byte(0,1,tem+0x30);
tem=num%10;
W_1byte(0,1,tem+0x30); 
W_1byte(0,0,0XFF); // 移走地址指针 防止下一输入内容的干扰
}
 
/******************************************************************** 
函数 名：LCD_print4num
入口参数： 显示4数字
出口参数：无 
函数作用： 
说        明： 
********************************************************************/ 
void LCD_print4num(unsigned char x,unsigned char y,unsigned int num){
unsigned char tem;
tem=num/100;
LCD_print2num(x,y,tem);

tem=num%100;   
LCD_print2num(x,y+1,tem);


  W_1byte(0,0,0XFF); // 移走地址指针 防止下一输入内容的干扰
}
 
//////////////////////////////////////////////////////////////

/******************************************************************** 
函数 名：LCD_print 
入口参数： 显示1 ascii
出口参数：无 
函数作用： 
说        明： 
********************************************************************/ 
void LCD_print(unsigned char x,unsigned char y,unsigned char ch)
{  
unsigned char a; 
a=address(x,y);
W_1byte(0,0,a);     //显示的地址 
W_1byte(0,1,ch); 



}
/******************************************************************** 
函数 名：LCD_print1 
入口参数： 显示1 ascii
出口参数：无 
函数作用：接着上文地址显示，不重设地址 
说        明： 
********************************************************************/ 
void LCD_print1(char ch)
{  
W_1byte(0,1,ch); 
}
//////////////////////////////////////////////////////////////



 void lp(unsigned char *p)
 {
 static unsigned char *p1=" ",*p2=" ",*p3=" ",*p4=" ";
 p4=p3;
 p3=p2;
 p2=p1;
 p1=p;
  LCD_const_disp(1,1,"                ");
  LCD_const_disp(2,1,"                ");
  LCD_const_disp(3,1,"                ");
  LCD_const_disp(4,1,"                ");
  LCD_var_disp(1,1,p4);
  LCD_var_disp(2,1,p3);
  LCD_var_disp(3,1,p2);
  LCD_var_disp(4,1,p1);
  delayms(300);
 }

//pin debug
/*
void lcd_test(void)
{

int i;
// Set_CS()Set_SID()Set_SCLK()  Clr_CS() Clr_SID() Clr_SCLK() 
 
 for(i=0;i<5;i++) {Set_CS();delayms(200); Clr_CS();delayms(200); }
  for(i=0;i<5;i++) {Set_SID();delayms(500); Clr_SID();delayms(500); }
   for(i=0;i<5;i++) {Set_SCLK();delayms(1000); Clr_SCLK();delayms(1000); }
 

}

*/
