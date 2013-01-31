//------------------------------------------------------------------------------
// 文件名：DS18B20_driver.h
// 说明：  DS18B20驱动头文件
// 功能：  实现1-wire器件的读写
// 使用方法：  
// 运行平台：   AVR 8bit (M16已验证)
// 依存关系：   DS18B20_driver.c    DS18B20基本驱动主文件（包括读写位、字节方法）
// 移植人：     
// 最后修改：   
//------------------------------------------------------------------------------


#ifndef _DS18B20_DRIVER_H_

 #define _DS18B20_DRIVER_H_


#ifndef TRUE
		#define TRUE 1
#endif

#ifndef FALSE
		#define FALSE 0
#endif
#define TemIn 1
#define TemOut 2
//------------------------------------------------------------------------------
// 基本函数声明
//------------------------------------------------------------------------------
void          Delay_nus(unsigned int n);             //延时n微秒函数
unsigned char reset_18B20(void);                     //18B20复位
void          write_bit_18B20(char bitval);          //写一位到18B20
unsigned char read_bit_18B20(void);         									//读一位从18B20
void          write_byte_18B20(unsigned char data);  //写一字节到18B20
unsigned char read_18B20(void);             									//读一字节到18B20
float read_T(void);
float read_T_NUM(unsigned char NUM);
float readWithoutDelay(unsigned char NUM);
//------------------------------------------------------------------------------
// 功能函数声明 (针对单个器件)
//------------------------------------------------------------------------------
unsigned char reset_18B20(void);  
void convert_T(void);

//void last_temp(unsigned int data);


#endif
