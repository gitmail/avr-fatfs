/*  此文件定义了从机zigbee的模块自检 及 与上位机通信的相关函数
*   版本 V1.0
*   日期 2012 08 10
*   版本历史：
* 数据格式
* 帧头    长度    目的地址   命令  内容     校验    帧尾
* FA       AA      B1        D1    01 03    00 00    fb  
*
*
*
************/
#include "config.h"

#ifndef _DEVICE_INFOMATION_
#define _DEVICE_INFOMATION_
//设备相关信息 可存进EEPROM 调试阶段暂时做成全局常量

const char CommonId = 0xFF; //从设备公共ID
/***************配置设备ID***************/
#define _DEVICE_ID 1
/**************************************/
#if   _DEVICE_ID == 1 
char devicename[8] = {"DEV00001"};//设备名称
const char deviceId = 0xB1;//设备ID		
#elif  _DEVICE_ID == 2 
char devicename[8] = {"DEV000002"};//设备名称
const char deviceId = 0xB2;//设备ID		
#elif  _DEVICE_ID == 3  
char devicename[8] = {"DEV000003"};//设备名称
const char deviceId = 0xB3;//设备ID		
#elif  _DEVICE_ID == 4  
char devicename[8] = {"DEV000004"};//设备名称
const char deviceId = 0xB4;//设备ID		
#elif  _DEVICE_ID == 5  
char devicename[8] = {"DEV000005"};//设备名称
const char deviceId = 0xB5;//设备ID		
#elif  _DEVICE_ID == 6  
char devicename[8] = {"DEV000006"};//设备名称
const char deviceId = 0xB6;//设备ID		
#endif

//char *reslut_a ="Dev000001,0001,20120920,12:00,-40.5,12.3,-55.5,-40.4,-40.3";

//char *p2 = "a123456789b12456789c123456789d123456789e123456789f12456789g123456789h12345789i12456789";
#endif
 

#define FRAME_LEN     13
#define STORAGE_DB_AND_SD  0
#define STORAGE_DB		   1
#define STORAGE_SD		   2
#define Z_CMD0 0xD0   
//命令0 响应查找从机命令

#define Z_CMD1_DATE 0xD1
//命令1 发送 采样日期  Result.Date

#define Z_CMD2_TIME 0xD2
//命令2 发送 采样时间  Result.Time

#define Z_CMD3_TEMPERATURE 0xD3
//命令3 发送 温度

#define Z_CMD4_WS 0xD4
//命令4 发送风速

#define Z_CMD5_WCI 0xD5
//命令5 发送WCI

#define Z_CMD6_ETC 0xD6
//命令6 发送ETC

#define Z_CMD7_TEQ 0xD7
//命令7 发送TEQ

#define Z_CMD8_OTHER 0xD8
//命令8 发送冻伤危害性和轻、重、中四个字节的数据

#define Z_CMD9_SINGLE 0xD9
//命令09 单次检测

#define Z_CMD10_CYCLE 0xDA
//命令10 循环检测

#define Z_CMD11_STOP 0xDB
//命令11 中止检测

#define Z_CMD12_SYNC 0xDC
//命令12 同步时钟

#define Z_CMD13_GET_DATA 0xDD
//命令13 请求数据

#define Z_CMD14_SET_STORAGE 0xDE
//命令9 设置存储位置

struct buffer_struct Rec;
//缓存池 Buf[100] ;
//读缓存指针BufReadP;
//写缓存指针BufWriteP;
//当前缓存个数 BufCount;

//struct SendStruct Send; 

void zigbee_init( void )
{
  Rec.BufReadP=0;
  Rec.BufWriteP=0;
  Rec.BufCount=0;
}
unsigned char RecAdd(unsigned char ByteRec)
{
  if (Rec.BufWriteP >= BufSize)  
  	 Rec.BufWriteP=0;
  Rec.Buf[Rec.BufWriteP++] = ByteRec ;
  Rec.BufCount++;
  return Rec.BufWriteP;
} 

void RecRemove(char N)
{ 
  if(Rec.BufCount >= N ) 
  {  debug("DEL=",Rec.Buf[Rec.BufReadP]);
     Rec.Buf[Rec.BufReadP]=0x00; 
   	 Rec.BufReadP=Rec.BufReadP+N;
	 if(Rec.BufReadP >= BufSize) {
	 				 		 Rec.BufReadP =Rec.BufReadP-BufSize;
							 }
	 Rec.BufCount=Rec.BufCount-N;
	 if(Rec.BufCount==0) {
	 Rec.BufReadP=0;
     Rec.BufWriteP=0;
	 
	 }
	 
  }
  else 
  {  //移除量大于现有量 移除所有 计数清零
    Rec.BufReadP=0;
    Rec.BufWriteP=0;
    Rec.BufCount=0;
  
  }
 }
char  RecRead(unsigned char index)
{ 
  int tmp;
  if(Rec.BufCount < index) 
  	return 0;
	
  tmp=Rec.BufReadP+index;
  if(tmp>=BufSize)  {tmp=tmp-BufSize;}
  return Rec.Buf[tmp-1];
} 


char CheckCRC(unsigned char i)
{
 i=i;
 return 1;  //校验成功

}
#define res Result
 //1 找头 2找长度 3计算尾 4找尾 5核对校验码 6分析命令 7执行操作
unsigned char RecDeal( void )
{ 
  int i=0 , tmp=0, state=0 ;
  char buf[5];
  //[TASK :找帧头]
  for(i=0;i <= Rec.BufCount ; i++ ){ 
      tmp = RecRead(1);    //读出当前值
	  if(tmp != FRAME_HEAD ) {
	      state = 1; //已查找无帧头
		  RecRemove(1);
	  }		  
	  else{	  //已找到帧头 跳出循环
      state = 2 ;  //已找到帧头 标志	 
	  break ;
	  }
 }		
 
 if(Rec.BufCount < FRAME_LEN) return 0x01;  //缓冲区数据太少  直接返回
 
 if(state == 1 || Rec.BufCount< FRAME_LEN ) return 0x03; //退出函数  无帧头
 //debug("#FRAME END =",RecRead(FRAME_LEN));
 //debug("#RECREAD(3) =",RecRead(3));
 if(RecRead(FRAME_LEN) != FRAME_END || ((RecRead(3)!=deviceId)&& (RecRead(3)!=CommonId) )  )  //非成帧数据或ID不符
 {
    RecRemove(1);	//移除命令
    return 0x05;    //非成帧数据 或ID不符
 }
 else if((CheckCRC(FRAME_LEN)==1))   //校验通过
 {
     switch(RecRead(4)){
         case Z_CMD0 :  //发送设备信息
		 Send_string((char *)devicename,Z_CMD0,sizeof(devicename));
		 RecRemove(12);
	     return Z_CMD0;  //发送完成 返回成功
		 break ;
  		
		 case Z_CMD1_DATE :  //发送日期
		 Send_string(res.Date, Z_CMD1_DATE, 9);
		 return Z_CMD1_DATE;  //发送完成 返回成功
		 break ;	
		 
		 case Z_CMD2_TIME :  //发送Time
		 Send_string(res.Time, Z_CMD2_TIME, 10);
		 return Z_CMD2_TIME;  //发送完成 返回成功
		 break ;	
		 
		 case Z_CMD3_TEMPERATURE :  //发送温度
		 Send_string(res.TempChar, Z_CMD3_TEMPERATURE, 6);
		 return Z_CMD3_TEMPERATURE;  //发送完成 返回成功
		 break ;	
		 
		 case Z_CMD4_WS :  //发送WSChar
		 Send_string(res.WSChar, Z_CMD4_WS, 5);
		 return Z_CMD4_WS;  //发送完成 返回成功
		 break ;			 
		 
		 case Z_CMD5_WCI :  //发送WCIChar
		 Send_string(res.WCIChar, Z_CMD5_WCI ,8);
		 return Z_CMD5_WCI;  //发送完成 返回成功
		 break ;	
		 
		 case Z_CMD6_ETC :  //ECTChar
		 Send_string(res.ECTChar, Z_CMD6_ETC ,6);
		 return Z_CMD6_ETC;  //发送完成 返回成功
		 break ;		
		 
		 case Z_CMD7_TEQ :  //发送TeqCharres.TeqChar
		 Send_string(res.TeqChar, Z_CMD7_TEQ ,6);
		 return Z_CMD7_TEQ;  //发送完成 返回成功
		 break ;	 
		 
		 case Z_CMD8_OTHER :  //发送日期
		 buf[0]= res.WeiHai + 0x30;
		 buf[1]= res.LowLabor + 0x30;
		 buf[2]= res.MidLabor + 0x30;
		 buf[3]= res.HighLabor + 0x30;
		 buf[4]= 0;
		 Send_string(buf, Z_CMD8_OTHER, 4);
		 return Z_CMD8_OTHER;  //发送完成 返回成功
		 break ;
		 
		 case Z_CMD9_SINGLE:
		 	  config.comCmd = 0x01; //sigle——check
		 break;
		 
		 case Z_CMD10_CYCLE:
		 	  config.comCmd = 0x02; //cycle check.
			  
//			  config.checkDeltaTime
		 break;
		 
		 case Z_CMD11_STOP:
		      config.comCmd = 0x03; //stop check 
		 break;
		 
		 case Z_CMD12_SYNC:
		 break;
		 
		 case Z_CMD13_GET_DATA:
		 break;
		 
		 case Z_CMD14_SET_STORAGE:
		 break;
		 
		 default:    
	     return 0xff;			   
     }
 } 
 else { //校验不成功 丢弃帧头 寻找下一帧头
  RecRemove(1);  //丢弃帧头
  return 0xff;
 }
return 0xff;
}
void Send_string(char *buf, unsigned char cmd, unsigned char MaxLen){
	 char i = 0;
	 
	 unsigned char sendBuf[64];
	 sendBuf[0] = FRAME_HEAD;
	 sendBuf[1] = 0;
	 sendBuf[2] = 0x00; //主机地址
	 sendBuf[3] = deviceId;//Send.src; //本机地址
	 sendBuf[4] = cmd; //
	 for(i=0;i<MaxLen;i++){
	     if( *(buf+i) != 0 ){
		 	 sendBuf[i+5] = *(buf+i);
		 }
		 else { 
		 break;
		 }
	 }
	 i=i+5;
	 sendBuf[i++] = 0xCC;
	 sendBuf[i++] = 0xCC;
	 sendBuf[i] = FRAME_END;
	 sendBuf[1] = i+1;
	 delayms((deviceId-0xB1)*1);  //不同设备延时不同时间发送数据，避免碰撞
	 Send_nByte(sendBuf, i+1); //uart send
}
/* 发送hex 暂未用到
void Send_bin(char *buf, unsigned char cmd, unsigned char buf_len){
	 char i = 0;
	 
	 unsigned char sendBuf[64];
	 sendBuf[0] = FRAME_HEAD;
	 sendBuf[1] = 0;
	 sendBuf[2] = 0x00; //主机地址
	 sendBuf[3] = deviceId; //本机地址
	 sendBuf[4] = cmd; //
	 for(i=0;i<buf_len;i++){
			 	 sendBuf[i+5] = *(buf+i);
	 }
	 i=i+5;
	 sendBuf[i++] = 0xCC;
	 sendBuf[i++] = 0xCC;
	 sendBuf[i] = FRAME_END;
	 sendBuf[1] = i+1;
	 delayms((deviceId-0xB1)*1);  //不同设备延时不同时间发送数据，避免碰撞
	 Send_nByte(sendBuf, i+1); //uart send
}
*/
void zigbee_send_date(void){
	char buf[5];
    Send_string(res.Date, Z_CMD1_DATE, 9);
	Send_string(res.Time, Z_CMD2_TIME, 10);
	Send_string(res.TempChar, Z_CMD3_TEMPERATURE, 6);
	Send_string(res.WSChar, Z_CMD4_WS, 5);
	Send_string(res.WCIChar, Z_CMD5_WCI ,8);
	Send_string(res.ECTChar, Z_CMD6_ETC ,6);
	Send_string(res.TeqChar, Z_CMD7_TEQ ,6);
	
	buf[0]= Result.WeiHai + 0x30;
	buf[1]= Result.LowLabor + 0x30;
	buf[2]= Result.MidLabor + 0x30;
	buf[3]= Result.HighLabor + 0x30;
	buf[4]= 0;
	Send_string(buf, Z_CMD8_OTHER, 5);
	return ;
}

void zigbee_send_id(void){
	 Send_string((char *)devicename,Z_CMD0,sizeof(devicename));
}