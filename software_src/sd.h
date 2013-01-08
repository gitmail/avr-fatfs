#ifndef __SD_H_
#define __SD_H_

#include "config.h"

#define SD_DDR  DDRB
#define SD_PORT PORTB
#define SD_PIN	 PINB

#define SD_CS  0

#define SD_CS_EN()  SD_PORT &= ~(1<<SD_CS) 
#define SD_CS_DIS() SD_PORT |=  (1<<SD_CS)
#define SD_DET() !((PINE>>5)&0X01)

#define DELAY_TIME 100 //SD卡的复位与初始化时SPI的延时参数，根据实际速率修改其值，否则会造成SD卡复位或初始化失败
#define TRY_TIME 20    //向SD卡写入命令之后，读取SD卡的回应次数，即读TRY_TIME次，如果在TRY_TIME次中读不到回应，产生超时错误，命令写入失败
#define SD_TURE 0

/* SD卡类型定义 
#define SD_TYPE_MMC     0
#define SD_TYPE_V1      1
#define SD_TYPE_V2      2
#define SD_TYPE_V2HC    4
*/

//错误码定义
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0错误
#define INIT_CMD1_ERROR     0x02 //CMD1错误
#define WRITE_BLOCK_ERROR   0x03 //写块错误
#define READ_BLOCK_ERROR    0x04 //读块错误
//-------------------------------------------------------------

//SD卡指令表
/*------------------------------------------------------------
#define CMD0    0       //卡复位
#define CMD9    9       //命令9 ，读CSD数据
#define CMD10   10      //命令10，读CID数据
#define CMD12   12      //命令12，停止数据传输
#define CMD16   16      //命令16，设置SectorSize 应返回0x00
#define CMD17   17      //命令17，读sector
#define CMD18   18      //命令18，读Multi sector
#define ACMD23  23      //命令23，设置多sector写入前预先擦除N个block
#define CMD24   24      //命令24，写sector
#define CMD25   25      //命令25，写Multi sector
#define ACMD41  41      //命令41，应返回0x00
#define CMD55   55      //命令55，应返回0x01
#define CMD58   58      //命令58，读OCR信息
#define CMD59   59      //命令59，使能/禁止CRC，应返回0x00
//-------------------------------------------------------------
*/


//SD函数声明
//-------------------------------------------------------------
UINT8 SD_Init(void);//SD初始化	
UINT8 SD_Write_cmd(UINT8 *p);//SD卡写命令
UINT16 SD_Write_Sector(UINT32 addr, UINT8 *buffer);//SD卡写扇区
UINT16 SD_Read_Sector(UINT32 addr,UINT8 *buffer); //SD卡读扇区
//-------------------------------------------------------------
UINT16 SD_Read_Sector_ndata(UINT32 addr,UINT8 *buffer,UINT16 offset,UINT16 len);//读多个扇区数据

#endif
