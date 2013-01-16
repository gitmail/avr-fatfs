//------------------------------------------------------------------------------
// 文件名：DS18B20_driver.c
// 说明：  DS18B20驱动头文件
// 功能：  实现1-wire器件的读写
// 使用方法：   void Delay_nus(unsigned int n);             //延时n微秒函数
//              unsigned char reset_18B20(void);            //18B20复位
//              void write_bit_18B20(char bitval);          //写一位到18B20
//              unsigned char read_bit_18B20(void);         //读一位从18B20
//              void write_byte_18B20(unsigned char data);  //写一字节到18B20
//              unsigned char read_18B20(void);             //读一字节到18B20
//
// 运行平台：   AVR 8bit (M16已验证)
// 依存关系：   DS18B20_driver.h    DS18B20基本驱动头文件（函数声明）
// 移植人：     
// 最后修改：   
//------------------------------------------------------------------------------

#include "config.h"
#define DS18B20_PORT PORTG
#define DS18B20_PIN  PING
#define DS18B20_DDR  DDRG
#define CL_DQ   DS18B20_PORT&=~(1<<T_NUM)					   
#define SET_DQ  DS18B20_PORT|=(1<<T_NUM)			   
#define SET_OUT DS18B20_DDR|=(1<<T_NUM)				   
#define SET_IN  DS18B20_DDR&=~(1<<T_NUM)			   
#define IN_DQ   DS18B20_PIN&(1<<T_NUM)				  
unsigned char T_NUM=0;


//------------------------------------------------------------------------------
// 延时N微秒程序 供控制读写DS18B20时序使用
//------------------------------------------------------------------------------
void Delay_nus(unsigned int n)   
{  unsigned int i;
	  for (i=0;i<n;i++) 
	  		{NOP();
						NOP();
						NOP();				        //20--300//比较接近
					}
}


//------------------------------------------------------------------------------
// 1-wire总线复位
//------------------------------------------------------------------------------
unsigned char reset_18B20(void)
{
	char bus_flag;
	CLI();
	SET_DQ;
	SET_OUT;
 	
  	Delay_nus(1);
  	CL_DQ;
  	Delay_nus(550);		//拉低至少480us时间
  	SET_DQ;				//释放
					NOP();
					NOP();
  	SET_IN;				//输入
  	Delay_nus(60);
  	
						//等待回复
  	bus_flag = IN_DQ;
  	
  	Delay_nus(240);		//回复的低电平在60到240US
  	SET_OUT;
					NOP();
					NOP();
  	SET_DQ;				//回到初始DQ=1；

  	SEI();
	if(bus_flag){
		return FALSE;
	}else{
		return TRUE;
	}

}

//------------------------------------------------------------------------------
// 写一位到总线
//------------------------------------------------------------------------------
void write_bit_18B20(char bitval)
{
    SET_OUT;
					NOP();
					NOP();
			 CL_DQ;
	   Delay_nus(1);
	   if(bitval){    //写数据，从低位开始
		     SET_DQ;
	  }else{
		     CL_DQ;
	  }
	Delay_nus(40);		//15~60us
	SET_DQ;
	Delay_nus(10);
}

//------------------------------------------------------------------------------
// 读一位从总线
//------------------------------------------------------------------------------
unsigned char read_bit_18B20(void)
{
	unsigned char k;
	SET_OUT;
	CL_DQ;			//读时间片开始，拉低总线至少1us
	Delay_nus(1);
	
					//SET_DQ;	
	SET_IN;
	Delay_nus(4);
	k=IN_DQ;    	//读数据,从低位开始
	Delay_nus(10);
	SET_DQ;	
				NOP();
				NOP();
	SET_OUT;
	    NOP();
					NOP();
	if(k){
	    return 1;
	}else{
	    return 0;
	}
	
}

//------------------------------------------------------------------------------
// 写一个字节到总线
//------------------------------------------------------------------------------
void write_byte_18B20(unsigned char data)
{
	unsigned char i;
   CLI();
    for(i=0;i<8;i++)
    {
        write_bit_18B20(data&(1<<i));
        
    }
    SET_DQ;
				  NOP();
					 NOP();
    SEI();
    
    //return;
}

//------------------------------------------------------------------------------
// 读一个字节
//------------------------------------------------------------------------------
unsigned char read_byte_18B20(void)
{
	unsigned char temp,n;
    CLI();
  	temp=0;
    for(n=0;n<8;n++)
    {
      	if(read_bit_18B20()){
      		temp|=(1<<n);
      	}else{
      		temp&=~(1<<n);
      	}
      	Delay_nus(70); //60~120us
      	
   }
   SEI();

   return temp;
}



//------------------------------------------------------------------------------
// 应用函数部分！ 供外部调用
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// 单器件/多器件：开始转换
//------------------------------------------------------------------------------
void convert_T(void)
{
					if(reset_18B20()){
					write_byte_18B20(0xcc);
					write_byte_18B20(0x44);
					}
}

//------------------------------------------------------------------------------
// 单器件：读温度，返回INIT8U型温度数据（原始数据）
//------------------------------------------------------------------------------
float read_T(void)
{
    unsigned char th=0,tl=0;
	float tmp;
    if(reset_18B20()){
    	write_byte_18B20(0xcc);
    	write_byte_18B20(0xbe);
    }
    
    tl = read_byte_18B20();
    th = read_byte_18B20();
 	tmp= ((float)(th<<8|tl))*0.0625;
    return( tmp);
}

float read_T_NUM(unsigned char NUM){
float ttemp;
if ( NUM >1) return 123.45;
T_NUM=NUM;//设置访问器件
convert_T();//温度转换
delayms(800);
ttemp=read_T();
return ttemp;
}


//-----------------------------------------------------------------------------
//数据类型转换
//-----------------------------------------------------------------------------
/*
void last_temp(unsigned int data)
{ 
  unsigned char zhengshu;
  unsigned char xiaoshu1;   //只取一位小数
		unsigned int data;
		unsigned char sign;
		
		data=read_T();
	 if((data&0x8000)==0x8000) //负温度
					{
					 sign='-';
					 data=(~data)+1;       //补码形式，取反加一
					}
		elae 
					{
					 sign=' ';
					}
		xiaoshu1=(unsigned char) ((data&0x0f)*10/16);
		zhengshu=(unsigned char) (data>>4);
				
		real_temp[4]={sign,zhengshu,'.',xiaoshu1,'℃'};
		//以char型存储
}


*/
