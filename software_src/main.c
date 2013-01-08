#include "config.h"
#define  N_per_Second  (2.72*60)
const char tab[]="\t\0";
const char enter[]="\n\0";
char buffer[512];
struct DATA Result;
struct tm t;
unsigned long now =0; 
void debug(UINT8 *str,UINT8 val);
struct CONFIG config;
void initDevices(void){
	 DDRA=0XFF;
	 PORTA=0XFF;
	 DDRB=0XFF;
	 PORTB=0XFF; 	 
	 DDRC=0XFF;
	 PORTC=0XFF;
	 DDRG=0XFF;
	 PORTG=0XFF;	 
	 SPI_IO_Init(); 
	 SD_Init();
	 uart1_init();
	 LCD_INT();delayms(50);LCD_INT();
	 LCD_SW(1);
	 config.THRESHOLD_delta_sec=10; //一次检测用时
	 config.autocheck=0;
}
void WriteFileHead(void) ;
void selfTest(void);
void main(void){
	 UINT8 tmp,keycode;
	 initDevices();
	 dateRefresh(1);
	 WriteFileHead();
	 while(1){
	 check();
	 StructToChar();
	 Result.Index++;
	 delayms(100);
	 }
	 while(1)
	 {
	  	  tmp=GUI_mainmeu();
		  delayms(300);
	      if(tmp==3) {GUI_check();}//check
		  if(tmp==4) {GUI_set_time();}//setclock
		  if(tmp==5) {}//lookup
		  if(tmp==6) {}//send data
		  if(tmp==7) {selfTest();}//init 
		  tmp=0;
	  }
}
void selfTest(void){
	float tmp=0;
	char str1[6],str2[6];
	
	 //自检程序
	lp("自检程序");delayms(500);
	lp("外部温度 ");
	tmp=read_T_NUM(0);
	ftochr(tmp,str1);
	str1[6]=0;
	lp(str1);
	delayms(500);
	lp("内部温度");
	tmp=read_T_NUM(1);
	ftochr(tmp,str2);
	str2[6]=0;
	lp(str2);
	delayms(500);
	lp("风速脉冲：");delayms(500);
	lp("蜂鸣器"); beep(2,2);delayms(500);
	lp("power 指示灯");
	LED_OFF();delayms(100);LED_ON();delayms(100);
	LED_OFF();delayms(100);LED_ON();delayms(100);
	LED_OFF();delayms(100);LED_ON();delayms(100);
	delayms(500);
	lp("加热开关");
	RELAY_ON();delayms(100);  
	RELAY_OFF();delayms(100);
	RELAY_ON();delayms(100);
	RELAY_OFF();delayms(100);
	lp("  ");delayms(500);
	lp("完成自检");delayms(500);
	  
}
void WriteFileHead(void)   
{
 	 unsigned int bw;
	 FRESULT res;
	 FATFS fs;
	 FIL file;
	 char fnamep[]="201301.xls\0\0\0"; 
	 UINT8 itam[]="DEV000001\t\t\t\t\t\t\t\t\t\t\t\n序号\t日期\t时分\t温度\t风速\t风冷指数\t等价制冷温度\t相当温度\t冻伤危害性\t安静作业\t中等强度作业\t高强度作业\n\0";
	 res=disk_initialize(0);
	 #ifdef _DEBUG
	 debug("dinit",res);
	 #endif
	 res = f_mount(0, &fs);
	 #ifdef _DEBUG
 	 debug("dmnt",res);
	 #endif
	 res = f_open(&file, get_name(fnamep) , FA_OPEN_ALWAYS | FA_WRITE );  //创建一个新的文件
	 #ifdef _DEBUG
	 debug("fopen",res);
	 #endif
	 res = f_write(&file,itam,128,&bw);   //bw 已写入字节数
	 #ifdef _DEBUG
	 debug("fwrite",res);
	 #endif
	 f_close(&file);
	 f_mount(0, NULL);
}
 
void check( void )
{
 unsigned char tmp;
 unsigned int WScounter;
 //检测风速
 //读计数器1 此步需严格按手册进行。
 tmp=SREG;
 CLI();
 WScounter=TCNT1H*256+TCNT1L;
 SREG=tmp;
 SEI();
 //计算风速
 Result.WindSpeed=WScounter/N_per_Second;
 //温度
 Result.Temperature=read_T_NUM(1);
 //WCI风冷指数
  Result.WCI = 4.18 *(10*SquareRootFloat(Result.WindSpeed) + 10.45 -  Result.WindSpeed  ) *( 33 - Result.Temperature );
 //ECT等价制冷温度
 Result.ECT = 33 - 0.01085 * Result.WCI;
 //TEQ 相当温度
 Result.Teq = Result.Temperature +( (Result.Temperature -36)/10 ) * Result.WindSpeed ;
//将数据转换成字符串
 
ftochr(Result.WindSpeed,Result.WSChar);
ftochr(Result.Temperature,Result.TempChar);
ftochr(Result.WCI,Result.WCIChar);
ftochr(Result.ECT,Result.ECTChar);
ftochr(Result.Teq,Result.TeqChar);
itoa(Result.IndexChar,Result.Index,10);
Result.TempChar[6]='\0';
Result.WSChar[5]='\0';
Result.WCIChar[6]='\0';
Result.ECTChar[6]='\0';
Result.TeqChar[6]='\0';
 return ;
}
////////////////////////////////////////////
//				字符串转换函数
//   浮点 到  字符串
////////////////////////////////////////////
void ftochr(float a,char * dest){//float
char i=0,j=0,lenth;
int status;
char *res;
 res=ftoa(a,&status);  //float to ascii
lenth=strlen(res);

for(i=0;i <lenth;i++) 
       {
	   	dest[i]=res[i];

		if( res[i]=='.'  ) 
			{
				dest[i+1]=res[i+1];
					dest[i+2]='\0';
						return ;    
		    }
 
 		}
}
//////////////////////////////////////////////////////
//              整型数据变字符串
//    a  到  dest
///////////////////////////////////////////////////////
void itochr(int a,char * dest){ //int to ascii
	 itoa(dest,a,10); 
}
//////////////////////////////////////////////////////
//                  结构体 变字符串
// 将目前存于结构体的数据转换到Temp_Char中。
///////////////////////////////////////////////////////
void  StructToChar(void)
{ unsigned char i;
  char Temp_Char[80];
  char otherbyte[]="0\t0\t0\t0";
  char *(ary[])={Result.IndexChar,Result.Date,Result.Time,
 	  			Result.TempChar,Result.WSChar,Result.WCIChar,Result.ECTChar,
				Result.TeqChar
			   };  //指向数组首地址的指针
  //strcat(Temp_Char,Result.Name);
  for(i=0;i<=80;i++) Temp_Char[i]='\0';  //清空数组
    for(i=0;i<=7;i++){
		strcat(Temp_Char,ary[i]);  // 按顺序复制字符串
		strcat(Temp_Char,tab);     //
    }
				 
				 otherbyte[0]=otherbyte[0]+Result.WeiHai;
				 otherbyte[2]=otherbyte[0]+Result.LowLabor;
				 otherbyte[4]=otherbyte[0]+Result.MidLabor;
				 otherbyte[6]=otherbyte[0]+Result.HighLabor;
 
  strcat(Temp_Char,otherbyte);  
  strcat(Temp_Char,enter);  
}

//////////////////////////////////////////////////////
//               字符串  变  结构体
// 
///////////////////////////////////////////////////////
void CharToStruct(void)
{
  unsigned char i=0,j=0;
  unsigned char *p,*q;
  char *(ary[])={Result.IndexChar,Result.Date,Result.Time,
 	  			Result.TempChar,Result.WSChar,Result.WCIChar,Result.ECTChar,
				Result.TeqChar
			   };  //指向数组首地址的指针
  char Temp_Char[80];
    p=ary[j];
	q=Temp_Char;
	while(1){
    if(*q =='\n') {*p='\0'; return;} ;
	if(*q =='\t') {j++;p=ary[j];i=0;}
    *p++=*q++;
	}
  }
 
 ////////////////////////////////////////////
//				根据当前日期获取文件名
//   
////////////////////////////////////////////
char *get_name( char filenamep[] ){     
	  unsigned char i=0;
 	  for(i=0;i<6;i++) {
	  				    *(filenamep+i)=Result.Date[i];
	  				   } 
	 	*(filenamep+(i++))='.';
		*(filenamep+(i++))='x';
		*(filenamep+(i++))='l';
		*(filenamep+(i++))='s';
		*(filenamep+(i))='\0';
					   
      return filenamep;
} 
float SquareRootFloat(float number)
{
    long i;
    float x, y;
    const float f = 1.5F;
    x = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );  //卡马克
  //i  = 0x5f375a86 - ( i >> 1 );  //Lomont
    y  = * ( float * ) &i;
    y  = y * ( f - ( x * y * y ) );
    y  = y * ( f - ( x * y * y ) );
    return number * y;
} 
//
//###############################################################//
//debug
void debug(UINT8 *str,UINT8 val)
{
 UINT8 str2[4]={0,0,0,0};
 str=str;
 val=val;
 #ifdef _UARTDEBUG
 PrintString("\r\n");
 PrintString(str);
 PrintChar(val);
 #endif
 #ifdef _LCDDEBUG
 lp(str);
 str2[2]=val%10+0x30;
 val=val/10;
 str2[1]=val%10+0x30;
 val=val/10;
 str2[0]=val%10+0x30;
 lp(str2);
 #endif
}
