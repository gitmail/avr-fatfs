 ////////////////////////////LCD.H/////////////////////////////////////
//LCD头文件
//功能：定义lcd控制函数 及 简单说明函数使用方法
//制作人：付继兴   
//时间： 2010.12.23  v1.0
//版本修改记录：
///////////////////////////////////////////////////////////////////// 
#ifndef _LCD_H_
#define _LCD_H_
//void lcd_test(void);  //pin debug
void lp(unsigned char *p);//滚屏操作
void W_1byte(unsigned char RW, unsigned char RS, unsigned char W_data); //写一字节 命令或数据
void Write_8bits(unsigned int W_bits);   //写一字节数据
void LCD_Init(void); //软件复位 初始化 
unsigned char LCD_INT(void); //总始化  2遍  间隔50ms
// flash中 两字符 显示 单行		  
void LCD_const_disp(unsigned char x,  //	行数 
            		 unsigned char y, //列数   
					const unsigned char  *single_data);//字符串首地址	 LCD_const_disp(1,5,“付继兴”);		
//	程序中变量 显示 单行		  
void LCD_var_disp(unsigned char x,  //	行数 
	 				 unsigned char y, //列数   
					  unsigned char  *single_data);//字符串首地址	 unsigned char tab[]={"fugreat"}  LCD_var_disp(2,4,tab);

void LCD_print(unsigned char x,unsigned char y,unsigned char ch);
void LCD_print1(char ch);
void LCD_print4num(unsigned char x,unsigned char y,unsigned int num);
void LCD_print2num(unsigned char x,unsigned char y,unsigned char num);  //LCD_print2num(2,3,wendu);
unsigned char LCD_SW(unsigned char i);
void LCD_char_disp(unsigned char x, unsigned char y, unsigned char data);   //unsigned char wendu=65;  LCD_char_disp(1,2,wendu);   a
void LCD_CLR(void);  //清除显示地址归零
void Set_White(unsigned char x,unsigned char y,unsigned char end_x,unsigned char clear);
void clr_white(void); //清反白
void set_white_n(unsigned char n,unsigned char clear);
void Set_Draw( void );  //  设置为绘图模式
//////////////////////常用指令////////////////////////////////////
//W_1byte(0,0,0x34);			//8BIT控制界面，扩充指令集,，绘图显示OFF
//W_1byte(0,0,0x36);	        //8BIT控制界面，扩充指令集,，绘图显示ON
//W_1byte(0,0,0x30);	        //进入基本指令集
void lcm_set_power_high(void);
void lcm_set_power_low(void);

#endif














				   