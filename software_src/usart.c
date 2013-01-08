#include "config.h"


#define fosc 7372800UL //晶振7.3728MHZ
#define baud 38400  //波特率
//串口通信初始化  MEGA128
//UART1 initialize
// desired baud rate:38400
// actual baud rate:38400 (0.0%)
// char size: 8 bit
// parity: Disabled
void uart1_init(void)
{
 	 UCSR1B = 0x00; //disable while setting baud rate
     UCSR1A = 0x00;
     UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);//8bit+1bit stop
     UBRR1L=(fosc/16/(baud+1))%256;
     UBRR1H=(fosc/16/(baud+1))/256;
     UCSR1B =(1<<RXEN1)|(1<<TXEN1);//RXCEN TXCEN
}

#pragma interrupt_handler uart1_rx_isr:iv_USART1_RXC
void uart1_rx_isr(void){   
	 char tmp;
	 tmp=UDR1;
}

void Usart_Transmit(char c)
{
 	 while (!(UCSR1A&(1<<UDRE1)));//表明发送器一准备就绪
	 UDR1=c;
}

//串口输出字符串
void Puts( unsigned char *s)
{ 
	 while (*s) 
      { 
	  //为数据间的隔断创造一个串口能显示的隔断字符 即'/t'  ->  ' '
	  if(*s==0x09)  
	  {   Usart_Transmit(' ');    }
	 Usart_Transmit(*s);
	 s++;
	
	
      }
}



void Send_nByte(unsigned char *p, unsigned char len)
{ 
  int i = 0;
  for(i=0;i<len;i++)
  {
   	Usart_Transmit(*(p+i));
  }
}

void  PrintString(const unsigned char *str)
{    
	while(*str!=0)	Usart_Transmit(*str++);
}
void  PrintString_n(const unsigned char *str)
{   
	Usart_Transmit('\r');
	Usart_Transmit('\n'); 
	while(*str!=0)	Usart_Transmit(*str++);

} 
 
void PrintLong(unsigned long data)
{
 
	unsigned char da[8];
	unsigned char i;
	for(i=0;i<8;i++)	da[i]=0;
	while(data>=10000000L){ ++da[7];data-=10000000L;}
	if(da[7])	i=0;
	if(i==0)	Usart_Transmit('0'+da[7]);
	while(data>=1000000L) { ++da[6];data-=1000000L;}
	if(da[6])	i=0;
	if(i==0)	Usart_Transmit('0'+da[6]);
	while(data>=100000L)  { ++da[5];data-=100000L;}
	if(da[5])	i=0;
	if(i==0)	Usart_Transmit('0'+da[5]);
	while(data>=10000L)   { ++da[4];data-=10000L;}
	if(da[4])	i=0;
	if(i==0)	Usart_Transmit('0'+da[4]);
	while(data>=1000L)    { ++da[3];data-=1000L;}
	if(da[3])	i=0;
	if(i==0)	Usart_Transmit('0'+da[3]);
	while(data>=100L)     { ++da[2];data-=100L;}
	if(da[2])	i=0;
	if(i==0)	Usart_Transmit('0'+da[2]);
	while(data>=10L)      { ++da[1];data-=10L;}
	if(da[1])	i=0;
	if(i==0)	Usart_Transmit('0'+da[1]);
	Usart_Transmit('0'+data);
 
}
 
void PrintChar(unsigned char d)
{
	unsigned char h=(d&0xF0)>>4;
	if(h<10)	Usart_Transmit('0'+h);
	else		Usart_Transmit('A'-10+h);
	h=d&0x0f;
	if(h<10)	Usart_Transmit('0'+h);
	else		Usart_Transmit('A'-10+h);
	Usart_Transmit(' ');
}


 