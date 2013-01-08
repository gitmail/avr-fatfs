#ifndef _SPI_H_
#define _SPI_H_

#include "config.h"

#define SPI_DDR  DDRB
#define SPI_PORT PORTB
#define SPI_PIN	 PINB

#define SS   0
#define SCLK 1
#define MOSI 2
#define MISO 3

/******************************************************************
//SPI函数声明
******************************************************************/
#define SPI_Low()  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);SPSR &=~(SPI2X) 	//SPI低速通信
#define SPI_High() SPCR = (1<<SPE)|(1<<MSTR);SPSR |= (1<<SPI2X)			//SPI高速通信

void SPI_IO_Init(void);//SPI接口初始化
void SPI_Write(UINT8 data);//SPI写数据
UINT8 SPI_Read(void);//SPI读数据

#endif
