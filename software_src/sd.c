//*****************************************************************************//
//*								数码相框
//*控制芯片：ATmgea128
//*开发环境：AVR Studio+GCC
//*隶属模块：SD卡控制
//*修改者：  桃子
//*****************************************************************************//
#include "sd.h"

//****************************************************************
//*隶属模块：SD卡控制
//*函数功能：写6字节数据
//****************************************************************
UINT8 SD_Write_cmd(UINT8 *p)
{	
	UINT16 temp,k=0;
	SD_CS_DIS();//禁止SPI
	SPI_Read();//空读一字节
	SD_CS_EN();//使能SPI

	SPI_Write(p[0]);
	SPI_Write(p[1]);
	SPI_Write(p[2]);
	SPI_Write(p[3]);
	SPI_Write(p[4]);
	SPI_Write(p[5]);

	do 
 	{  
  		temp = SPI_Read();//一直读，直到读到的不是0xff或超时
 		k++;
 	}while((temp==0xff)&&(k<TRY_TIME)); 

	return temp;
}
//****************************************************************
//*隶属模块：SD卡控制
//*函数功能：初始化
//****************************************************************
UINT8 SD_Init(void)	
{  
	UINT8 time=0,temp=0;
	UINT8 pcmd[] = {0x40,0x00,0x00,0x00,0x00,0x95}; //命令0的字节序列
	if(SD_DET()==0) return 0x02; //no disk
	SD_PORT |= (1<<SD_CS);
	SD_DDR |= (1<<SD_CS);

	SPI_IO_Init();
	SPI_Low();

	SD_CS_DIS();  //关闭片选 
	for(time=0;time<10;time++) //初始时，首先要发送最少74个时钟信号，这是必须的！！！
	{
  		SPI_Read(); 
	}
	SD_CS_EN(); //打开片选
	time = 0;
	do
	{ 
		temp=SD_Write_cmd(pcmd);//写入CMD0
	 	time++;
	 	if(time==TRY_TIME) 
	 	{ 
	  		SD_CS_DIS(); //关闭片选
	  		return(INIT_CMD0_ERROR);//CMD0写入失败
	 	}
	 }while(temp!=0x01);

	SD_CS_DIS(); //关闭片选
	SPI_Read(); //按照SD卡的操作时序在这里补8个时钟 
	SD_CS_EN(); //打开片选

	pcmd[0]=0x41,pcmd[5]=0xff;
	time = 0;
	do
	{ 
		temp=SD_Write_cmd(pcmd);
		time++;
		if(time==TRY_TIME) 
		{ 
		 	SD_CS_DIS(); //关闭片选
			 return(INIT_CMD1_ERROR);//CMD1写入失败
		 }
	 }while(temp!=0);
  
	 SPI_High();  
	 SD_CS_DIS();  //关闭片选 
	 SPI_Read(); //按照SD卡的操作时序在这里补8个时钟
	 return SD_TURE; //返回0,说明初始化操作成功
} 
//****************************************************************
//*隶属模块：SD卡控制
//*函数功能：写512字节数据（一扇区字节）
//****************************************************************
UINT16 SD_Write_Sector(UINT32 addr,UINT8 *buffer)
{  
	UINT8 temp=0,time=0;
	UINT16 i=0;
	UINT8 pcmd[] = {0x58,0x00,0x00,0x00,0x00,0xff}; //向SD卡中单个块（512字节，一个扇区）写入数据，用CMD24

	 addr<<=9; //将块地址（扇区地址）转为字节地址 ［这里就限制了SD卡的最大容量为4G］

	 pcmd[1]=(addr>>24); //将字节地址写入到CMD24字节序列中
	 pcmd[2]=(addr>>16);
	 pcmd[3]=(addr>>8);
	// pcmd[4]=offset;	
	 SD_CS_EN();//打开SD卡片选

	 do
	 {  
		temp=SD_Write_cmd(pcmd);
  		time++;
  		if(time==TRY_TIME) 
  		{ 
   			SD_CS_DIS(); //关闭片选
   			return(temp); //命令写入失败
  		}
	}while(temp!=0); 

	for(i=0;i<100;i++) //这里要插入若干时钟信号
  		SPI_Read();
	
	SPI_Write(0xfe);//写入开始字节 0xfe，后面就是要写入的512个字节的数据	
	
	for(i=0;i<512;i++) //将缓冲区中要写入的512个字节写入SD卡
		SPI_Write(*buffer++);
  
	SPI_Read(); 
	SPI_Read(); //两个字节的CRC校验码，不用关心
   
    
	temp=SPI_Read();   //读取返回值
	if((temp&0x1F)!=0x05) //如果返回值是 XXX00101说明数据已经被SD卡接受了
	{
 		SD_CS_DIS();
 		return(WRITE_BLOCK_ERROR); //写块数据失败
	}
 
	while(SPI_Read()!=0xff);//等到SD卡不忙（数据被接受以后，SD卡要将这些数据写入到自身的FLASH中，需要一个时间）
						    //忙时，读回来的值为0x00,不忙时，为0xff

	SD_CS_DIS(); //关闭片选

	SPI_Read();//按照SD卡的操作时序在这里补8个时钟
	return SD_TURE;		 //返回0,说明写扇区操作成功
} 
//****************************************************************
//*隶属模块：SD卡控制
//*函数功能：读512字节数据（一扇区字节）
//****************************************************************
UINT16 SD_Read_Sector(UINT32 addr,UINT8 *buffer)//从SD卡的指定扇区中读出512个字节，使用CMD17（17号命令）
{

	 UINT16 j=0;
	 UINT8 time=0,temp=0;
	 UINT8 pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17的字节序列

	 addr <<= 9; //将块地址（扇区地址）转为字节地址

	 pcmd[1] = (addr>>24);//将字节地址写入到CMD17字节序列中
	 pcmd[2] = (addr>>16);
	 pcmd[3] =(addr>>8);
	// pcmd[4] = offset;

	 SD_CS_EN();//打开片选 

	 do
	 {  
		  temp=SD_Write_cmd(pcmd); //写入CMD17
		  time++;
		  if(time==TRY_TIME) 
		  {
		   SD_CS_DIS();
		   return(READ_BLOCK_ERROR); //读块失败
		  }
	 }while(temp!=0); 
   			
	 while(SPI_Read()!= 0xfe); //一直读，当读到0xfe时，说明后面的是512字节的数据了
 		   	   	
	 for(j=0;j<512;j++)	 //将数据写入到数据缓冲区中
	 {	
	    buffer[j]=SPI_Read();
	 }

	 SPI_Read();//读取两个字节的CRC校验码，不用关心它们
	 SPI_Read();

	 SD_CS_DIS();  //SD卡关闭片选 

	 SPI_Read();//按照SD卡的操作时序在这里补8个时钟

	 return SD_TURE;
}
//****************************************************************
//*隶属模块：SD卡控制
//*函数功能：写多扇区数据（多扇区字节）
//****************************************************************
UINT16 SD_Read_Sector_ndata(UINT32 addr,UINT8 *buffer,UINT16 offset,UINT16 len)//从SD卡的指定扇区中读出512个字节，使用CMD17（17号命令）
{

	 UINT16 j=0;
	 UINT8 time=0,temp=0;
	 UINT8 pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17的字节序列

	 addr <<= 9; //将块地址（扇区地址）转为字节地址

	 pcmd[1] = (addr>>24);//将字节地址写入到CMD17字节序列中
	 pcmd[2] = (addr>>16);
	 pcmd[3] =(addr>>8);
	// pcmd[4] = offset;

	 SD_CS_EN();//打开片选 

	 do
	 {  
		  temp=SD_Write_cmd(pcmd); //写入CMD17
		  time++;
		  if(time==TRY_TIME) 
		  {
		   SD_CS_DIS();
		   return(READ_BLOCK_ERROR); //读块失败
		  }
	 }while(temp!=0); 
   			
	 while(SPI_Read()!= 0xfe); //一直读，当读到0xfe时，说明后面的是512字节的数据了
 		   	   	
	 for(j=0;j<offset;j++)	 //将数据写入到数据缓冲区中
	    SPI_Read();
	 for(;j<offset+len;j++)	 
		buffer[j]=SPI_Read();
	 for(;j<512;j++)	 
		SPI_Read();

	 SPI_Read();//读取两个字节的CRC校验码，不用关心它们
	 SPI_Read();

	 SD_CS_DIS();  //SD卡关闭片选 

	 SPI_Read();//按照SD卡的操作时序在这里补8个时钟

	 return SD_TURE;
}
