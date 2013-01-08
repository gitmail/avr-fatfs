#ifndef _USART_H_
#define _USART_H_
 
void Puts( unsigned char *s);  
void Usart_Transmit(char i);
void uart1_init(void);
void PrintString(const unsigned char *str);
void PrintString_n(const unsigned char *str);
void PrintLong(unsigned long data);
void PrintChar(unsigned char d);
unsigned char getch(void);
void Send_nByte(unsigned char *p, unsigned char len);
#endif