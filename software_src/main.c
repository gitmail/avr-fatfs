#include "config.h"
#define  N_per_Second  (168.64)
//=2.72*N_Seconds, now N=62。N_per_Second=62*2.72=168.64
//#define _FOR_FAST_TEST

const char tab[]="\t\0";
const char enter[]="\n\0";
char buffer[512];
char TempChar[80]; //存放临时字串
struct DATA Result;
struct tm t;
unsigned long now =0; //时间寄存器 单位S
void debug(UINT8 *str,UINT8 val);//debug输出函数
void WriteSDFile(void);//写SD卡
float Round(float x); //四舍五入函数
struct CONFIG config; //系统配置变量结构体

void initDevices(void){
     CLI();
	 DDRA=0XFF;
	 PORTA=0XFF;
	 DDRB=0XFF;
	 PORTB=0XFF; 	 
	 DDRC=0XFF;
	 PORTC=0XFF;
	 DDRE=0XFF;
	 PORTE=0XFF;
	 DDRG=0XFF;
	 PORTG=0XFF;
	 power_check_init(); 
	 SPI_IO_Init(); //spi接口硬件初始化
	 SD_Init();//sd卡初始化
	 uart1_init();//通信用的UART为UART1
	 LCD_INT();delayms(50);LCD_INT();//LCD初始化
	 LCD_SW(1);
	 config.comCmd = 0; //无上位机命令
	 config.last5s=0; //5s定时器
	 config.THRESHOLD_delta_sec=60; //一次检测用时
	 config.heatThreshold = 5; //继电器开启温度 
	 config.checkDeltaTime=20;  //自动检测模式 时间间隔	 
	 config.checkDelta = 0;     //
	 config.autocheck=1;        //自动检测开关
	 config.readMode = 0;      //读数据模式
	 config.autoSend = 1; //zigbee发送开关，不为0时，使能发送
	 config.Sd = 1;      //Sd存储开关， 不为0时，使能存储
	 config.is_lowpower = 0; //电池电量指示寄存器 is_lowpower !=0电量低。
	 #ifdef _FOR_FAST_TEST
	 config.THRESHOLD_delta_sec=5; //一次检测用时
	 config.heatThreshold = 20; //继电器开启温度 
	 config.checkDeltaTime=5;  //自动检测模式 时间间隔	 
	 #endif
	 
	 SEI();
}
void timer1_init(void)
{
 TCCR1B = 0x00; //stop
 TCNT1H = 0x00 /*INVALID SETTING*/; //setup
 TCNT1L = 0x00 /*INVALID SETTING*/;
 TCCR1A = 0x00;
 TCCR1B = 0x46; //start Timer
}
////////////////////////////////////////////////////////////////
void main(void){
	 UINT8 tmp,keycode;
	 UINT8 buf512[513];
	 char filename[]="201301.xls\0\0\0";
	 int i=0;
	 initDevices();
	 dateRefresh(1);
	 WriteFileHead();
     Result.Index=findIndex(get_name(filename),buf512);
	 #ifdef _DBG_RD_  
	 	 while(1){
		     GUI_readback(buf512);
	     }
	 #endif
	 //selfTest();
	 GUI_welcome();
	/*   //FOR DEBUG
	 while(alwaysCheck())
	 {
	   delayms(100);dateRefresh(1);StructToChar();
	   check();
	   zigbee_send_date();
	 }
	 */
	 while(alwaysCheck()){
	    tmp=GUI_mainmeu();
		switch(tmp){
		    case 3 : GUI_check(); break; 
			case 4 : GUI_set_time(); break ;
			case 5 : GUI_readback(buf512); break;
			//case 6 : GUI_send_date();
			case 7 : selfTest(); break ;
			default : break;
	   }
	   delayms(100);
	 }
}
char alwaysCheck(void)
{
 float temp;
 RecDeal(); //zigbee data deal
  	 
 power_state_refresh();
 //间隔5s 背温检测,发送本机ID
 if(config.now>config.last5s)
 {   
 	 config.last5s=config.now+5;
	 zigbee_send_id(); //发送本机ID
     temp= readWithoutDelay(INSIDE_SENSOR);
     if (temp>config.heatThreshold) {
 	     RELAY_OFF(); //debug("off=",(int)temp);
		 return 1;
 	 }
     else  {
   	     RELAY_ON();//debug("on=",(int)temp);
	 } 
 }
 
 
 return 1;
}
void selfTest(void){
	float tmp=0;                                                                
	char str1[6],str2[6];
	lp("┌──────┐");
	lp("│  自检程序  │");
	lp("│            │");
	lp("└──────┘");
	 //自检程序
	delayms(500);
	lp("外部温度 ");
	tmp=read_T_NUM(OUTSIDE_SENSOR);
	sprintf(str1,"%#0.1f",tmp);
	str1[6]=0;
	lp(str1);
	delayms(500);
	lp("内部温度");
	tmp=read_T_NUM(INSIDE_SENSOR);
	sprintf(str2,"%#0.1f",tmp);
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
	lp("                ");
	lp("                ");
	lp("                ");
	lp("                ");
	delayms(100);
	  
}

void WriteFileHead(void)   
{
 	 unsigned int bw;
	 FRESULT res;
	 FATFS fs;
	 FIL file;
	 char fnamep[]="201201.xls\0\0\0"; 
	 UINT8 itam[]="DEV000001\t\t\t\t\t\t\t\t\t\t\r\n序号\t日期\t时分\t温度\t风速\t风冷指数\t等价制冷温度\t相当温度\t冻伤危害性\t安静作业\t中等强度作业\t高强度作业\n\0";
	 res=disk_initialize(0);
	 res = f_mount(0, &fs);
	 //get_name(fnamep)
	 res = f_open(&file, get_name(fnamep) , FA_OPEN_ALWAYS | FA_WRITE );  //创建一个新的文件
	 res = f_write(&file,itam,128,&bw);   //bw 已写入字节数
	 f_close(&file);
	 f_mount(0, NULL);
} /////////////////////////////////////////////////
//       写入文件函数 
//(创建)打开文件 
// data 指向欲写入的的字符串 64byt 
//////////////////////////////////////////////// 
void WriteSDFile(void)   
{
    unsigned int bw;
	FRESULT res;
	FATFS fs;
    FIL file;
	char fnamep[13];
	long lenth=0;
	disk_initialize(0);
	res = f_mount(0, &fs);
	res = f_open(&file,get_name(fnamep), FA_OPEN_ALWAYS | FA_WRITE );  //创建一个新的文件
	lenth=file.fsize;   
	res = f_lseek (&file,lenth);	 
	res = f_write(&file,TempChar,SINGLE_ITEM_SIZE,&bw);   //bw 已写入字节数
	f_close(&file);
	f_mount(0, NULL);
}
/////////////////////////////////////////////////
//       读取文件函数
//以64byte为一块 读取
//index数据偏移量   data读出后存放地
//////////////////////////////////////////////// 
char ReadSDFile(char *fnamep,int index, char *data, char mode)
{
 	unsigned int bw;
	char res;
	FATFS fs;
    FIL file;
	static int indexoffset;
	unsigned int max;
	disk_initialize(0);
    res = f_mount(0, &fs);
    res = f_open(&file,fnamep,FA_READ);  
    if(res==FR_NO_FILE) {
	data=NULL;
    #if _debug >= 1 
    debug_out("now file",255);
	debug_out(filename,res);
	debug_out("file is no exist....",255);
    #endif 
    return res;
    }   
    max = (file.fsize-128)/SINGLE_ITEM_SIZE;
	if(mode == 0){ //绝对位置模式
		indexoffset = index;
	}
	else if(mode == 1){ //位置偏移模式
		indexoffset+=index;
	}
	if(indexoffset >max){
	    indexoffset = max;
	}
	else if(indexoffset <=0){
		indexoffset = 1;
	}
	res = f_lseek (&file,(indexoffset-1)*SINGLE_ITEM_SIZE+128);	 //前两个字节数据为文件头空间 所以从第三块读/写起
    res = f_read(&file,data,SINGLE_ITEM_SIZE,&bw);
    f_close(&file);
	f_mount(0, NULL);
	return res;
} 
//////////////////////////////////
//   find index
// 检查当前文件尺寸，根据倒数第二个
//'\n'及其后面的index确定当前index值
//////////////////////////////////
unsigned int findIndex(char *filename,char *buf){
    unsigned int bw,tmp;
	long index =0;
	unsigned char is_first_end=0;
	char *fnamep=filename;
	FRESULT res;
	FATFS fs;
	FIL file;
	long lenth=0;
	int readsize=0;
	//PrintString_n(fnamep);
	res = f_mount(0, &fs);
	res = f_open(&file,fnamep, FA_OPEN_ALWAYS | FA_READ );  //创建一个新的文件
	if(res !=  FR_OK){ //openerror
	    return res;}
	lenth=file.fsize;   //文件尾部为 file.size 
	//debug("size=",0xff);
	//PrintLong(lenth);
	if(lenth > 512) {
	    readsize=512;
		lenth=file.fsize;
	}
	else {
	    readsize =file.fsize;
		lenth=0;
	}
	res = f_lseek (&file,file.fsize-readsize);
	//debug("readSIZE=",0x00);
	//PrintLong((file.fsize-readsize));
	res = f_read(&file,buf,readsize,&bw);
	f_close(&file);
	//debug("readRES=",res);
	//debug("readbw=",0X00);
	//PrintLong(bw);
	//PrintString_n(buf);
	for(tmp=readsize;tmp>0;tmp--){
		//debug("buf index",buf[tmp]);
		//PrintLong(tmp);
		//if(buf[tmp] == '\n') Usart_Transmit('@');						  
		if(buf[tmp] == '\n' && is_first_end== 0){
		    is_first_end=1; 	
			//debug("first=",0xf0);					      
		}
		else if(buf[tmp] == '\n' && is_first_end== 1){
		    lenth -= (512-tmp);
			break;
		} 						
	}
	//debug("start=",0X00); PrintLong(lenth);
	if(lenth < 118 ){ 
 		return 1;
	}
	else {
		 //debug(">128 ",0X00);
		 while(buf[tmp] <= '0' || buf[tmp] >= '9') tmp++;
		 //debug("nozero ",bw); PrintLong(tmp);
		 while(buf[tmp] != 't' && buf[tmp] >= '0' && buf[tmp] <= '9'){
		     index=index*10+(buf[tmp]-'0');
		 	 //Usart_Transmit(buf[tmp]);	
		 	 tmp++;
		 }
	}
	//debug("index=",0X00);
	//PrintLong(index+1);
	return index+1;
}
float Round(float x){
    x=x*10;
	if(x >=0) x+=0.5;
	else x-=0.5;
	x=(int)x;
	x=x/10.0;
	return x;
}

void check( void )
{
 unsigned char tmp;
 unsigned int WScounter;
 //检测风速
 //读计数器1 此步需严格按手册进行。
 tmp=SREG;
 CLI();
 WScounter=TCNT1;
 SREG=tmp;
 SEI();
 TCCR1B = 0x00; //关闭计数器
 //计算风速
 Result.WindSpeed=WScounter/N_per_Second;
 //风速修正
 //将风速检测的值的使用做一调整，暂时做如下调整
 //       风速V<3m/s时，V=V-0.1
 //       3<V<13M/S时，V=V
 //       13<=V<=16时，V=V+0.3
 //       V>16时，V=V+0.6
 //       用此结果进行显示、存储、代入公式计算。
 if(Result.WindSpeed < 3) {
     Result.WindSpeed = Result.WindSpeed - 0.1;
 }
 else if( Result.WindSpeed <13.0 && Result.WindSpeed >3 ) {
 	 ;//nothing to do
 }
 else if ( Result.WindSpeed >=13.0 && Result.WindSpeed<=16 )
 {
  	 Result.WindSpeed = Result.WindSpeed + 0.3; 
 }else if(Result.WindSpeed > 16){
 	   Result.WindSpeed = Result.WindSpeed + 0.6;
 }
  
 //四舍五入
 Result.WindSpeed=Round(Result.WindSpeed);
  //温度
 Result.Temperature=read_T_NUM(OUTSIDE_SENSOR); //读两次 避免出错
 Result.Temperature=read_T_NUM(OUTSIDE_SENSOR);
 //四舍五入
 Result.Temperature=Round(Result.Temperature);
 //WCI风冷指数
 Result.WCI = 4.18 *(10*SquareRootFloat(Result.WindSpeed) + 10.45 -  Result.WindSpeed  ) *( 33 - Result.Temperature );
 //ECT等价制冷温度
 Result.ECT=33.0f - 0.01085f*Result.WCI;
 //TEQ 相当温度
 Result.Teq = Result.Temperature +( (Result.Temperature -36)/10 ) * Result.WindSpeed ;
//将数据转换成字符串
sprintf(Result.WSChar, "%#.1lf", (float)Result.WindSpeed);
sprintf(Result.TempChar, "%#.1lf", (float)Result.Temperature); //PrintString_n(Result.TempChar);
sprintf(Result.WCIChar, "%#.1lf",  (float)Result.WCI); //PrintString_n(Result.WCIChar);
sprintf(Result.ECTChar, "%#.1lf", (float)Result.ECT);  //PrintString_n(Result.ECTChar);
sprintf(Result.TeqChar, "%#.1lf", (float)Result.Teq);
sprintf(Result.IndexChar, "%d", Result.Index);
Result.TempChar[6]='\0';
Result.WSChar[5]='\0';
Result.WCIChar[7]='\0';
Result.ECTChar[6]='\0';
Result.TeqChar[6]='\0';
 return ;
}
/*
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
*/
//////////////////////////////////////////////////////
//                  结构体 变字符串
// 将目前存于结构体的数据转换到Temp_Char中。
///////////////////////////////////////////////////////
void  StructToChar(void)
{ 
  unsigned char i;
  char otherbyte[]="0\t0\t0\t0";
  char *(ary[])={Result.IndexChar,Result.Date,Result.Time,
 	  			Result.TempChar,Result.WSChar,Result.WCIChar,Result.ECTChar,
				Result.TeqChar
			   };  //指向数组首地址的指针
  //strcat(Temp_Char,Result.Name);
  for(i=0;i<=80;i++) TempChar[i]='\0';  //清空数组
    for(i=0;i<=7;i++){
		strcat(TempChar,ary[i]);  // 按顺序复制字符串
		strcat(TempChar,tab);     // 字串结尾加上制表符
    }
				 
				 otherbyte[0]=otherbyte[0]+Result.WeiHai;
				 otherbyte[2]=otherbyte[0]+Result.LowLabor;
				 otherbyte[4]=otherbyte[0]+Result.MidLabor;
				 otherbyte[6]=otherbyte[0]+Result.HighLabor;
 
  strcat(TempChar,otherbyte);  
  strcat(TempChar,enter);  
  strcat(TempChar,"\0");
}

//////////////////////////////////////////////////////
//               字符串  变  结构体
// 
///////////////////////////////////////////////////////
void CharToStruct(char *buf)
{
  unsigned char j=0;
  unsigned char *p,*q;
  char *(ary[])={Result.IndexChar,Result.Date,Result.Time,
 	  			Result.TempChar,Result.WSChar,Result.WCIChar,Result.ECTChar,
				Result.TeqChar
			   };  //指向数组首地址的指针
    p=ary[j];
	q=buf;
	
	while(1){
    if(*q =='\n') {*p='\0'; return;} ;
	if(*q =='\t') {
		*p='\0';
		q++;
	    if(j>7) break ;
		j++;
		p=ary[j];
		continue ;
	}
    *p++=*q++;
	}
	return ;
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
