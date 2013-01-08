#include "config.h"
const char labelH[]="高强度作业：\0";
const char labelM[]="中等强度作业：\0";
const char labelL[]="低强度作业：\0";
const char H01[]="加强劳动监督；\0";
const char H02[]="增加饮水;\0" ;
const char H03[]="保持干燥禁裸露。\0";
#define M01 H01
#define M02 H03
const char M03[]="戴面罩。\0";
const char M04[]="禁油彩。\0";
#define L01 M03
#define L02 M04
const char L03[]="缩短作业时间。";
//-----//
#define H11 M04
#define H12 H03
const char H13[]="休息注意保暖。\0";
#define M11 H01
const char M12[]="减少非必须作业；\0";
const char M13[]="劳动时间<30min。\0";
const char L11[]="取消非必须的作业\0";
const char L12[]="劳动时间<15min；\0";
#define L13 H03
//-----//
#define H21 L11
#define H22 L12
#define H23 H03
const char M21[]="取消户外作业。"; 
#define L21 M21

//#define LEDON   PORTC&=~(1<<7)					   
//#define LEDOFF  PINC|=(1<<7)
char GUI_date[17]="09月19日18:00:00\0";

// 主菜单
unsigned char GUI_mainmeu( void )
{
 	unsigned char key=0; //init= nokey
	unsigned char select=3;
	LCD_CLR();
 	Set_White(1,1,8,1);
	Set_White(1,2,8,1);
	Set_White(1,3,8,1);
	Set_White(1,4,8,1);
	LCD_const_disp(2,1,"  检测  时钟调整");
	LCD_const_disp(3,1,"  查询  数据传输");
	LCD_const_disp(4,1,"  初始化");
	set_white_n(select,0);
	while(1)
	{
	 	key=kbscan();
		dateRefresh(1);
		LCD_const_disp(1,1,GUI_get_date()); //显示时间
		if((select>3) && (key==left || key==up ) )
		{
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 select--;
		 set_white_n(select,0);
		}
		if((select<7) && (key==right || key==down ) )
		{
		 Set_White(1,1,8,1);
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 select++;
		 set_white_n(select,0);
		}
		if(key == ok )
		{
		 Set_White(1,1,8,1);
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 beep(3,select);
		 return select;
		}
		
		
	}
	return 0xff; //error
	
}

//”检测 “菜单
void GUI_check(void)
{
 char key;
 char page=0,is_on=0;
 char selectCheckMode=config.autocheck;
 LCD_CLR();
 LCD_const_disp(1,1,"菜单/ 检测");
 LCD_const_disp(2,3,"自动");
 LCD_const_disp(3,3,"手动");
 if(selectCheckMode==1) {
 Set_White(1,2,8,0);
 Set_White(1,3,8,1);
 }
 else {
 Set_White(1,2,8,1);
 Set_White(1,3,8,0);
 }
 while(1){
 	key=kbscan();
	if(key==left && selectCheckMode > 0){  
		selectCheckMode=0;
		Set_White(1,2,8,0);
 		Set_White(1,3,8,1);
		//delayms(500);
		}
	if(key==right && selectCheckMode < 1){  
		selectCheckMode=1;
		Set_White(1,2,8,1);
 		Set_White(1,3,8,0);
	//delayms(500);
	}
	if(key == up) {
		config.autocheck=selectCheckMode; 
		Set_White(1,2,8,1);
 		Set_White(1,3,8,1);
		delayms(500);
		break ;		
	}
	if(key == down) {
		return ;		
	}
	
 }

 while(1)
 {    
     key=kbscan();
	 dateRefresh(1);
	
if(page == 0){
 	 //显示日期时间
	 LCD_var_disp(1,1,GUI_get_date());
	//显示温度
	 LCD_const_disp(2,1,"温度 (℃):");
	 LCD_var_disp(2,6,Result.TempChar);
	//显示风速
	 LCD_const_disp(3,1,"风速(m/s): ");
	 LCD_const_disp(3,6,Result.WSChar);
	 if(is_on == 1)
	 {
	  LCD_const_disp(4,1,"倒计时: ");
	 LCD_print4num(4,5,config.time1-config.now);
	 }else 
	 {LCD_const_disp(4,1,"            ");}
	 
	 
	} 
if(page == 1){
	LCD_var_disp(1,1,GUI_get_date());
	LCD_const_disp(2,1,"风冷指数: ");
	LCD_var_disp(2,6,Result.WCIChar);						
	LCD_const_disp(3,1,"等价温度: ");
	LCD_var_disp(3,6,Result.ECTChar);	 
	LCD_const_disp(4,1,"相当温度: ");
	LCD_var_disp(4,6,Result.TeqChar);	
	}
if(page == 2){
	LCD_var_disp(1,1,GUI_get_date());
	LCD_const_disp(2,1,"冻伤危害性:");
	if(Result.WeiHai==0){LCD_const_disp(3,1,"  冻伤危害性小");			 }
	else if(Result.WeiHai==1){	LCD_const_disp(3,1,"  冻伤危害性较大");	 }
	else if(Result.WeiHai==2){	LCD_const_disp(3,1,"  冻伤危害性很大");	 }
	else LCD_const_disp(3,1,"冻伤危害性小。");
	}	  
if(page==3){
	 LCD_const_disp(1,1,labelH);		
	 switch( Result.WeiHai )
	 {
			case 0 :
			LCD_const_disp(2,1,H01);
			LCD_const_disp(3,1,H02);
			LCD_const_disp(4,1,H03);
			break;
			case 1 : 
			LCD_const_disp(2,1,H11);
			LCD_const_disp(3,1,H12);
			LCD_const_disp(4,1,H13);
			break ;	
			case 2 :
			LCD_const_disp(2,1,H21);
			LCD_const_disp(3,1,H22);
			LCD_const_disp(4,1,H23);
			break;
			default :
			;
		}
			
} 
if(page==4){
	 LCD_const_disp(1,1,labelM);		
	 switch( Result.WeiHai )
	 {
	 		case 0 :
			LCD_const_disp(2,1,M01);
			LCD_const_disp(3,1,M02);
			if(Result.Temperature < 17.7) 
				{LCD_const_disp(4,1,"戴面罩；禁油彩。");}
			else if(Result.Temperature < 12)
				 {LCD_const_disp(4,1,"禁油彩。        \0");}
			break;
			
			case 1 : 
			LCD_const_disp(2,1,M11);
			LCD_const_disp(3,1,M12);
			LCD_const_disp(4,1,M13);
			break ;
			case 2 :
			LCD_const_disp(2,1,M21);
			break ;
			default :
			;
	}
			
}
if(page==5){
	 LCD_const_disp(1,1,labelL);		
	 switch( Result.WeiHai )
	  {	
			case 0 :
			LCD_const_disp(2,1,L01);
			if(Result.Temperature < -12) {
			LCD_const_disp(3,1,L02);
			LCD_const_disp(4,1,L03);
			} else 
			{
			 LCD_const_disp(3,1,L03);
			}
			break;
			case 1: 
			LCD_const_disp(2,1,L11);
			LCD_const_disp(3,1,L12);
			LCD_const_disp(3,1,L13);
			break ;
			case 2 :
			LCD_const_disp(2,1,L21);
			break;
			default :
			;
			} //end switch
			
}  //end if
	 //LCD_print2num(4,4,is_on);
	  if(key==ok){ //按ok键开始测量
	  			 beep(1,0);
	  			 //fwrite; 
				 config.time1=config.now+config.THRESHOLD_delta_sec;
				 is_on=1; //start count
	 //			 timer1_init(); //计数
				}			
	if(is_on == 1 && config.now>=config.time1 )
	{
	 is_on=0;
	 check(); //检测
	 //storage(); //存储
 
	} 	
	
	  
    if(key==left) //左键 : 页面减
	{ 
	  if(page>0) page--;
	  LCD_CLR();
	  LCD_Init();
	}
	 
  if(key==right) //右键 ： 页面加
	{ 
	  if(page<5) page++;
	  else page = 0;
	  LCD_CLR();
	  LCD_Init();
	}
	if(key==lright && is_on==0)	//长安右键 退出
	{ 
	 LCD_CLR();
	 LCD_Init();	  
 	 LCD_const_disp(4,5,"退出    "); 
	 delayms(200);
	 LCD_const_disp(4,7,".."); 
	 delayms(200);
	 LCD_const_disp(4,8,".."); 	
	 delayms(500);
	 LCD_CLR();
	 return ;
	}
    delayms(100); 
}//end while

}

char * GUI_get_date(void) 
{  
   //2012年12月11日19:00:00
  GUI_date[0]=Result.Date[4]; 
  GUI_date[1]=Result.Date[5];
  GUI_date[4]=Result.Date[6];
  GUI_date[5]=Result.Date[7];
  GUI_date[8]=Result.Time[0];
  GUI_date[9]=Result.Time[1];
  GUI_date[11]=Result.Time[4];
  GUI_date[12]=Result.Time[5];
  GUI_date[14]=Result.Time[8];
  GUI_date[15]=Result.Time[9];
  GUI_date[16]='\0';
  return GUI_date;
}
//设置时间 菜单 
void GUI_set_time(void)
 {
 
 unsigned char p=2;
 char GUI_up[]= "↑";
 char GUI_down[]= "↓";
 char *pD=NULL,*pT=NULL;
 char *ary=GUI_up;
 unsigned char i=0,keyc=NO_KEY;
LCD_CLR(); //清屏
pD="2012年12月31日\0";
pT=Result.Time;
LCD_const_disp(1,1,"时间设置:       ");
LCD_const_disp(4,7,"保存");
  
LCD_var_disp(3,p,ary);
LCD_var_disp(2,1,pD);
LCD_var_disp(4,1,pT);
delayms(250);
while(1)
{
keyc=kbscan();
pD[2]=Result.Date[2];
pD[3]=Result.Date[3];
pD[6]=Result.Date[4];
pD[7]=Result.Date[5];
pD[10]=Result.Date[6];
pD[11]=Result.Date[7];  

switch(i){
         case 0: p=2;ary=GUI_up;  //年
		 	  	 if(keyc==up){ if(time_buf[1]<0x99){ time_buf[1]++;
												  if((time_buf[1]&0x0f)==0x0a) time_buf[1]=time_buf[1]+6;
												   }
												     
								 }				  
 					        
			     else if(keyc==down){ if(time_buf[1]>0x00){  time_buf[1]--;
				 	  			   						 if((time_buf[1]&0x0f)==0x0f) time_buf[1]=time_buf[1]-6;
		 	  	 			  					        }
												   
								 }			   		
				else if(keyc==right) {i=1;}
				break;
		 case 1: p=4;ary=GUI_up;  //月
		  	  	if(keyc==up){ if(time_buf[2]<0x12){  time_buf[2]++;	
													if((time_buf[2]&0x0f)==0x0a) time_buf[2]+=6;
													 
													
												 }
							else time_buf[2]=0x01;
						  }						 
				if(keyc==down){ if(time_buf[2]>0x01){  time_buf[2]--;	
													if((time_buf[2]&0x0f)==0x0f) time_buf[2]-=6;
													
												 }
							 else time_buf[2]=0x12;						
						  }						 							
				if(keyc==left) {i=0;   }									
				if(keyc==right) {i=2;   }  
				 break;
				 
				 									
         
		 case 2: p=6;ary=GUI_up;
		 	  	 if(keyc==up){ if(time_buf[3]<0x31){ time_buf[3]++;
												  if ((time_buf[3]&0x0f)==0x0a) time_buf[3]=time_buf[3]+6;
											
											if(  //2 4 6 9 11 月最大30天
											( ((time_buf[2]==0x02) || (time_buf[2]==0x04)|| (time_buf[2]==0x06)||
											  (time_buf[2]==0x09)||(time_buf[2]==0x11))&&(time_buf[3]==0x31) 
											)  
											  )
											{time_buf[3]=0x30;}
											      }
 									  
 					         }
			     else if(keyc==down){ if(time_buf[3]>0x01){  time_buf[3]--;
				 	  			   						 if((time_buf[3]&0x0f)==0x0f) time_buf[3]=time_buf[3]-6;
		 	  	 			  					        }
								   else time_buf[3]=0x31;						
												   
								 }
				if(keyc==left) {i=1;  }						 			   		
				if(keyc==right) {i=3;    }  	
				 break;
							
				
 case 3:p=1;ary=GUI_down;
 	  	if(keyc==up){ if(time_buf[4]<0x23){  time_buf[4]++;	
													if((time_buf[4]&0x0f)==0x0a) time_buf[4]+=6;
													 
													
												 }
							else time_buf[4]=0x00;
						  }						 
				if(keyc==down){ if(time_buf[4]>0x00){  time_buf[4]--;	
													if((time_buf[4]&0x0f)==0x0f) time_buf[4]-=6;
													
												 }
							 else time_buf[4]=0x23;						
						  }	
		if(keyc==left ) {i=2;   } 				  
		if(keyc==right) {i=4;    } 
		break;						  					 			
 case 4:p=3;ary=GUI_down;
 	  	if(keyc==up){ if(time_buf[5]<0x59){  time_buf[5]++;	
											 if((time_buf[5]&0x0f)==0x0a) time_buf[5]+=6;
										  }
					  else time_buf[5]=0x00;
					}						 
		if(keyc==down){ if(time_buf[5]>0x00){  time_buf[5]--;	
												if((time_buf[5]&0x0f)==0x0f) time_buf[5]-=6;
											}
						else time_buf[5]=0x59;						
					  }
		if(keyc==left ) {i=3;    } 		  						 								  			
 		if(keyc==right) {i=5;   }	
		break;			   
 case 5:p=5;ary=GUI_down;
 	  	if(keyc==up){ if(time_buf[6]<0x59){  time_buf[6]++;	
											 if((time_buf[6]&0x0f)==0x0a) time_buf[6]+=6;
										 }
					  else time_buf[6]=0x00;
					}						 
		if(keyc==down){ if(time_buf[6]>0x00){  time_buf[6]--;	
						if((time_buf[6]&0x0f)==0x0f) time_buf[6]-=6;
					  }
		else time_buf[6]=0x59;		}				
		if(keyc==left ) {i=4;    } 		  				 														   
		if(keyc==right) {i=6;p=1;ary=NULL;}  
		break;           
							 
		 }//endcase
 		 dateRefresh(0);
		 
		 LCD_const_disp(3,1,"                "); //清空箭头 
 		 LCD_var_disp(3,p,ary); //显示箭头 
 		 LCD_var_disp(2,1,pD);  //显示日期
 		 LCD_var_disp(4,1,pT);  //显示时间
 if(keyc==lright) {		  
 		  LCD_const_disp(3,1,"        放弃修改"); 
		  delayms(500);
		  LCD_CLR(); //清屏
		  return ;} 
 keyc=NO_KEY;
 if(i==6){    //各值改变完成后 显示已保存 清屏 返回
		  ds1302_write_time(); 
          LCD_const_disp(4,7,"    ");		  
		  LCD_const_disp(3,1,"          已保存"); 
		  delayms(500);
		  LCD_CLR(); //清屏
		  return ;
		  }
 delayms(2);	  
}//endwhile(1)


}
////////////////////////////////////
//  函数作用
//   将ds1302中缓存的时钟数据转换进结构体中
////////////////////////////////////
void dateRefresh(unsigned char readhardware)
{	
	if( readhardware==1 ){
		ds1302_read_time();
	}
	t.tm_sec=(((time_buf[6]&0x70)>>4)*10)+(time_buf[6]&0x0f);
	t.tm_min=  (((time_buf[5]&0x70)>>4)*10)+(time_buf[5]&0x0f);
	t.tm_hour=  (((time_buf[4]&0x70)>>4)*10)+(time_buf[4]&0x0f);
	t.tm_mday=	(((time_buf[3]&0x70)>>4)*10)+(time_buf[3]&0x0f);
	t.tm_mon= (((time_buf[2]&0x70)>>4)*10)+(time_buf[2]&0x0f);
	t.tm_wday=	(time_buf[7]&0x0f);
    t.tm_year=	(((time_buf[1]&0x70)>>4)*10)+(time_buf[1]&0x0f);
	Result.Date[0]='2';
	Result.Date[1]='0';
	Result.Date[2]=t.tm_year/10+'0';
	Result.Date[3]=t.tm_year%10+'0';
	Result.Date[4]=t.tm_mon/10+'0';
	Result.Date[5]=t.tm_mon%10+'0';
	Result.Date[6]=t.tm_mday/10+'0';
	Result.Date[7]=t.tm_mday%10+'0';
    Result.Date[8]='\0';
	Result.Time[0]=t.tm_hour/10+'0';
	Result.Time[1]=t.tm_hour%10+'0';
	Result.Time[2]=':';
	Result.Time[3]=' ';
	Result.Time[4]=t.tm_min/10+'0';
	Result.Time[5]=t.tm_min%10+'0';
	Result.Time[6]=':';
	Result.Time[7]=' ';
	Result.Time[8]=t.tm_sec/10+'0';
	Result.Time[9]=t.tm_sec%10+'0';
	Result.Time[10]='\0'; 
	//
	config.now =t.tm_hour*3600 + t.tm_min*60 + t.tm_sec;
}