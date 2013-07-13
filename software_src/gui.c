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
const char str_blank[]="----------------"; 
//#define LEDON   PORTC&=~(1<<7)					   
//#define LEDOFF  PINC|=(1<<7)
char GUI_date[17]="09月19日18:00:00\0";
#define SW_ON 1
#define SW_OFF 0
// 主菜单
unsigned char GUI_mainmeu( void ){
 	unsigned char key=0; //init= nokey
	unsigned char select=3;
	LCD_CLR();
	
 	Set_White(1,1,8,1);
	Set_White(1,2,8,1);
	Set_White(1,3,8,1);
	Set_White(1,4,8,1);
	dateRefresh(1); //更新系统时间
	LCD_const_disp(1,1,GUI_get_date()); //显示时间
	LCD_const_disp(2,1,"  检测  时钟调整");
	LCD_const_disp(3,1,"  查询  数据传输");
	LCD_const_disp(4,1,"  初始化");
	
	//LCD_print2num(4,8,config.comCmd);
	Set_White(1,1,8,1);
	Set_White(1,2,8,1);
	Set_White(1,3,8,1);
	Set_White(1,4,8,1);
	set_white_n(select,0);
	//处理上位机自动检测命令

		
	while(alwaysCheck())
	{
		if(config.comCmd == 0x01 || config.comCmd == 0x02) {
	        
			return 3; //goto check();
		}
		
		if(config.is_lowpower) {
	        LCD_const_disp(4,6,"电量低"); //devicename[7] = 'F';// DDRC|=(1<<LED_PIN);LED_PORT |=  (1 << LED_PIN) ;
		}
		else{
	   		LCD_const_disp(4,6,"      ");// devicename[7] = 'U'; DDRC|=(1<<LED_PIN);LED_PORT &= ~(1 << LED_PIN);
		}
		
	 	key=kbscan();
		dateRefresh(1); //更新系统时间
		LCD_const_disp(1,1,GUI_get_date()); //显示时间
		if((select>3) && ( key==up ) ){
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 select--;
		 set_white_n(select,0);
		}
		if((select<7) && ( key==down ) ){
		 Set_White(1,1,8,1);
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 select++;
		 set_white_n(select,0);
		}
		if(key == left ){
		 Set_White(1,1,8,1);
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,1);
		 Set_White(1,4,8,1);
		 //beep(3,select);
		 return select;
		}
		delayms(5);
    }
	return 0xff; //error
	
}

//”检测 “菜单
void GUI_check(void){
    char key;
	char page=0,is_on=0;
	char windcounter=0;
	unsigned long next_step_time=0;
	char selectCheckMode=config.autocheck; //自动检测开关
	
RE_IN:
	key=0;
	page=0;
	is_on=0;
	windcounter=0;
	next_step_time=0;
	dateRefresh(1);
if(config.comCmd == 0x02 && config.checkDelta > 60) {  //循环检测 且 间隔>60s
	 config.autocheck = 0x02;
	 LCD_CLR();
	 LCD_const_disp(1,1,"收到命令：");
	 LCD_const_disp(2,1,"  循环检测");
	 LCD_const_disp(3,1,"检测间隔(s):");
	 LCD_print4num(4,2,config.checkDelta/10000);
	 LCD_print4num(4,4,config.checkDelta%10000);
	 delayms(1000);
}
else if(config.comCmd == 0x01 || config.comCmd == 0x02){  //单次检测 或（循环检测但不满足检测间隔）
	config.autocheck = SW_OFF;
	 LCD_CLR();
	 LCD_const_disp(1,1,"收到命令：");
	 LCD_const_disp(2,1,"  单次检测");
	 config.comCmd = 0x00; //单次检测情况下检测设置完成则清除检测标志
	 delayms(1000); 
}
else {	  

	      LCD_CLR();
		  LCD_const_disp(1,1,"菜单/ 检测");
		  LCD_const_disp(2,3,"自动");		 
		  LCD_const_disp(3,3,"手动");
		  if(selectCheckMode==SW_ON) {
	          Set_White(1,2,8,0);
			  Set_White(1,3,8,1);
		  }
		  else {
		      Set_White(1,2,8,1);
		      Set_White(1,3,8,0);
		  }
	
    //<<菜单/检测/手（自）动>>
	while(alwaysCheck()){
		if(config.comCmd!=0 ){
			if(config.comCmd == 3) config.comCmd =0;				
		  	return ;
		}
	 	key=kbscan();
		dateRefresh(0); //只刷新后台时间
		//上键短按 选择
		if(key==up || key ==down){
		    if(selectCheckMode >0){
			    selectCheckMode=0;
				Set_White(1,2,8,1);
	 			Set_White(1,3,8,0);
			}
			else {
			    selectCheckMode=1;
				Set_White(1,2,8,0);
	 			Set_White(1,3,8,1);
			}
			
		}
		//左键短按  进入
		if(key == left) {
			config.autocheck=selectCheckMode; 
			Set_White(1,2,8,1);
	 		Set_White(1,3,8,1); 
			break ;		
		}
		//右键短按  返回
		if(key == right) {
			return ;		
		}
		key=0;	
	} //end of while
}//end if	
	
    //自动开启检测
	dateRefresh(0);
	is_on =1 ;
	config.time1=config.now+config.THRESHOLD_delta_sec;
	Result.TempChar[0]=0; //清除上次结果
	Result.WSChar[0]=0;
	while(alwaysCheck()){
		dateRefresh(0); //只刷新后台时间
		key=kbscan();
		if(key != 0) beep(0,1);
		if(key==right || config.comCmd == 0x03){	//右键 退出
		    is_on=0;
			LCD_CLR();
		 	LCD_Init();	  
	 	 	LCD_const_disp(4,5,"退出    "); 
		 	delayms(200);
		 	LCD_const_disp(4,7,".."); 
		 	delayms(200);
		 	LCD_const_disp(4,8,".."); 	
		 	delayms(500);
		 	LCD_CLR();
			config.comCmd = 0;//清除自动检测命令
		 	goto RE_IN;
		}
		if(is_on==1){ 
			dateRefresh(1); //更新时间
		    _GUI_datashow(page); 
		    if(config.now < config.time1) {
				//时间更新 开启风速检测 等待检测 不支持翻页
				if(windcounter==0){
				    windcounter=1; //清零开启风速计数器
					timer1_init(); //开启风速传感器技术
				}
				if(page == 0 ){
				
				    LCD_const_disp(4,1,"正在检测：");
					LCD_print4num(4,6,config.time1-config.now);
					LCD_const_disp(2,6,"      ");
					LCD_const_disp(3,6,"      ");
				}
			} 
			else {
			   //检测完成 获得数据 转换数据 存储数据 切换到非检测状态
			    windcounter =0 ; //关闭风速传感器计数器
				beep(1,1);
				LCD_const_disp(4,1,"--计算并存储--       ");
				check();
				StructToChar(); //转成字符串
				WriteFileHead();//重写文件头
				WriteSDFile();  //写入sd卡
				if(config.autoSend>=1) {
					 zigbee_send_date(); //zigbee发送
				}
				Result.Index++; //索引自增一
				is_on=0; //切换到非检测状态
				next_step_time=config.now+config.checkDeltaTime;//自动翻页时间更新
				page=0;
				if(config.autocheck == 0) config.comCmd = 0;
		   }
		}
		else { //is_on == 0 非检测状态 手动翻页/自动翻页
		    dateRefresh(0);//不更新时间
			_GUI_datashow(page); 
			if(page == 0 ){
				
				    LCD_const_disp(4,1,"完成检测        ");
					if(config.autocheck >= 1){
					    LCD_const_disp(4,7,"自动");
					}
					else {
					    LCD_const_disp(4,7,"手动");
					}
					
				}
						//手动翻页 
			
			if(key==up){ //上键 : 页面减 
		        if(page>0) page--;
				else{
				page =5;
				next_step_time = config.now + config.checkDeltaTime;
				}
		    	LCD_CLR();
		    	LCD_Init();
			}
			if(key==down){//下键 ： 页面加
		        page++;
				next_step_time = config.now + config.checkDeltaTime;
		  		LCD_CLR();
		    	LCD_Init();
				if(page >= 6 ) {
					page=0;
					continue ;
				}
			} 	
			//LCD_print2num(4,1,page);
			//LCD_print4num(4,3,config.now);
			//LCD_print4num(4,6,next_step_time);
			if( config.autocheck == 2  ){ 
			      if(config.now >= next_step_time && page <5 )	{   //自动翻页
				      next_step_time = config.now + config.checkDeltaTime;
					  page++;
					  LCD_CLR(); 
					  key=0;
				  }
			}
			else if( config.autocheck == 1 ){
				 if(config.now >= next_step_time || page >=6 )	{   //自动翻页
				      next_step_time = config.now + config.checkDeltaTime;
					  page++;
					  LCD_CLR(); 
					  key=0;
				  }
			}
			if(config.autocheck==2 && page==5 ){
				 LCD_const_disp(4,1,"距下次:");
				 LCD_print4num(4,5,(config.checkDelta+config.time1-config.now)/10000);
				 LCD_print4num(4,7,(config.checkDelta+config.time1-config.now)%10000);
			}
			if(config.autocheck == 0 && config.comCmd !=0) return;
			
			if( page>=6 || key == left ||(config.comCmd == 0x02 && config.now > config.time1+config.checkDelta) ){
			    //翻到最后页（且处于自动检测模式）或 左键按下 或 （自动检测模式下且下次检测时间已到） 
				// 页面清零开启下次检测
				page = 0;
				dateRefresh(1); //刷新时间
				is_on =1 ; //开启检测
				config.time1=config.now+config.THRESHOLD_delta_sec; //更新下次检测风速计数器停止时间
				Result.TempChar[0]=0; //清除上次结果
				Result.WSChar[0]=0;
				LCD_CLR();
				key = 0;  
			}
				         
				

		} 
		  				 
	    delayms(10); 
	}//end while
}//end function
void _GUI_datashow(char page){
	if(page == 0){
 	//显示日期时间
	    LCD_var_disp(1,1,GUI_get_date());
	//显示温度
	 	LCD_const_disp(2,1,"温度 (℃):      ");
	 	LCD_var_disp(2,6,Result.TempChar);
	//显示风速
	    LCD_const_disp(3,1,"风速(m/s):      ");
	 	LCD_const_disp(3,6,Result.WSChar);

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
	 	 switch( Result.WeiHai ){
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
			default : ;
		}
	 } 
	 if(page==4){
	 		LCD_const_disp(1,1,labelM);		
	 		switch( Result.WeiHai ){
	 			case 0 :
				LCD_const_disp(2,1,M01);
				LCD_const_disp(3,1,M02);
				if(Result.Temperature < -17.7){
				    LCD_const_disp(4,1,"戴面罩；禁油彩。");
				}
				else if(Result.Temperature < -12){
				    LCD_const_disp(4,1,"禁油彩。        \0");
				}
				break;
				case 1 : 
			    LCD_const_disp(2,1,M11);
				LCD_const_disp(3,1,M12);
				LCD_const_disp(4,1,M13);
				break ;
				case 2 :
				LCD_const_disp(2,1,M21);
				break ;
				default :;
	 		}
	 }
	 if(page==5){
	     LCD_const_disp(1,1,labelL);		
	 	 switch( Result.WeiHai ){	
		     case 0 :
			 LCD_const_disp(2,1,L01);
			 if(Result.Temperature < -12) {
			 LCD_const_disp(3,1,L02);
			 LCD_const_disp(4,1,L03);
			 } 
			 else {
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
			 default : ;
		} //end switch
	}  //end if
}
char * GUI_get_date(void) {  
  //格式:12月11日19:00:00
    GUI_date[0]=Result.Date[4]; 
    GUI_date[1]=Result.Date[5];
    GUI_date[4]=Result.Date[6];
    GUI_date[5]=Result.Date[7];
    GUI_date[8]=Result.Time[0];
    GUI_date[9]=Result.Time[1];
    GUI_date[11]=Result.Time[3];
    GUI_date[12]=Result.Time[4];
    GUI_date[14]=Result.Time[6];
    GUI_date[15]=Result.Time[7];
    GUI_date[16]='\0';
    return GUI_date;
}
//设置时间 菜单 
void GUI_set_time(void){
    unsigned char p=2;
	char GUI_up[]= "↑";
	char GUI_down[]= "↓";
	char *pD=NULL,*pT=NULL;
	char *ary=GUI_up;
	unsigned char i=0,keyc=NO_KEY;
	LCD_CLR(); //清屏
	pD="2012年12月31日\0";
	pT="12: 30: 59\0";
	LCD_const_disp(1,1,"时间设置:       ");
	LCD_const_disp(4,7,"保存");
	LCD_var_disp(3,p,ary);
	LCD_var_disp(2,1,pD);
	LCD_var_disp(4,1,pT);
	delayms(250);
	while(alwaysCheck()){
	    keyc=kbscan();
		pD[2]=Result.Date[2];
		pD[3]=Result.Date[3];
		pD[6]=Result.Date[4];
		pD[7]=Result.Date[5];
		pD[10]=Result.Date[6];
		pD[11]=Result.Date[7];  
		pT[0] = Result.Time[0];
		pT[1] = Result.Time[1];
		pT[4] = Result.Time[3];
		pT[5] = Result.Time[4];
		pT[8] = Result.Time[6];
		pT[9] = Result.Time[7];
		
		switch(i){
            case 0: p=2;ary=GUI_up;  //年
		 	  	 if(keyc==up){
				     if(time_buf[1]<0x99){ 
					     time_buf[1]++;
						 if((time_buf[1]&0x0f)==0x0a) 
						     time_buf[1]=time_buf[1]+6;
					 }
												     
				}				  
 					        
			    else if(keyc==down){ 
				    if(time_buf[1]>0x00){
				        time_buf[1]--;
						if((time_buf[1]&0x0f)==0x0f) 
						    time_buf[1]=time_buf[1]-6;
		 	  	 		 }
												   
					}			   		
				else if(keyc==left) {i=1;}
				break;
		 case 1:p=4;ary=GUI_up;  //月
		  	  	if(keyc==up){
				    if(time_buf[2]<0x12){  
					    time_buf[2]++;	
						if((time_buf[2]&0x0f)==0x0a) time_buf[2]+=6;
					}
					else 
					    time_buf[2]=0x01;
				}						 
				if(keyc==down){ 
				    if(time_buf[2]>0x01){  
					    time_buf[2]--;	
						if((time_buf[2]&0x0f)==0x0f) 
						    time_buf[2]-=6;
			  		}
				    else 
					    time_buf[2]=0x12;						
				}						 							
 								
				if(keyc==left){
				    i=2;   
				}  
				break;
	 	 case 2: p=6;ary=GUI_up;
		 	  	 if(keyc==up){ 
				     if(time_buf[3]<0x31){ 
				         time_buf[3]++;
						 if ((time_buf[3]&0x0f)==0x0a) time_buf[3]=time_buf[3]+6;
						 if(  //2 4 6 9 11 月最大30天
						  ( ((time_buf[2]==0x02) || (time_buf[2]==0x04)|| (time_buf[2]==0x06)||
						  (time_buf[2]==0x09)||(time_buf[2]==0x11))&&(time_buf[3]==0x31))){
						      time_buf[3]=0x30;
						}
				     }
 									  
 				 }
			     else if(keyc==down){ 
				      if(time_buf[3]>0x01){  
					     time_buf[3]--;
				 	  	 if((time_buf[3]&0x0f)==0x0f) time_buf[3]=time_buf[3]-6;
		 	  	 	 }
					 else time_buf[3]=0x31;						
											   
				}
				if(keyc==left) {i=3;  }						 			   		
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
		if(keyc==left) {i=4;    } 
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
		if(keyc==left ) {i=5;    } 		  						 								  			
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
		if(keyc==left) {i=6;p=1;ary=NULL;}  
		break;           
							 
		 }//endcase
 		 dateRefresh(88); //set clock mode
		 
		 LCD_const_disp(3,1,"                "); //清空箭头 
 		 LCD_var_disp(3,p,ary); //显示箭头 
 		 LCD_var_disp(2,1,pD);  //显示日期
 		 LCD_var_disp(4,1,pT);  //显示时间
 if(keyc==right) {		  
 		  LCD_const_disp(3,1,"        放弃修改"); 
		  delayms(500);
		  LCD_CLR(); //清屏
		  return ;} 
 keyc=NO_KEY;
 if(i==6){    //各值改变完成后 显示已保存 清屏 返回
		  ds1302_write_time(); 
          LCD_const_disp(4,7,"    ");		  
		  LCD_const_disp(3,1,"          已保存"); 
		  delayms(300);
		  LCD_CLR(); //清屏
		  return ;
		  }
 delayms(2);	  
}//endwhile(1)
}
void GUI_readback(char *buf){
    char key=0;
	char page=0;
	char res=0;
	char file_buf[]="201201.xls\0\0";
	LCD_CLR(); //清屏
	//1 检测SD状态
		//无SD卡 显示无卡 退出
	if((SD_DET()==0)) {
		LCD_const_disp(2,1,"未检测到SD卡..");
			#ifdef _DBG_RD_
		   PrintString_n("not find sd");
		   #endif
		delayms(500);
		return ;
	}
	//2 显示当前月份
	get_name(file_buf);
	LCD_const_disp(1,1,"查找数据:");
	LCD_const_disp(2,2,file_buf);
	#ifdef _DBG_RD_
		   PrintString_n(file_buf);
	#endif
	//3 查找文件是否存在
		//存在-> 进入读取顺序的选择
		//不存在 -> 询问查找上月
	//4 选择 查询顺序
		//计算总条数
		//顺序 增量为1， 查询第一条 
		//逆序 增量为-1，查询最后一条
	//5 读取	
	//6 显示
	//7 上一条 下一条  退出
		//设置条数 判断边界 进入5
		//退出 返回主程序	
	//!!res=checkFile(file_buf);
label_recheck:	
	LCD_Init(); //清屏
	LCD_CLR();  
	if(res == 0){ //找到并已经确认文件
		   LCD_const_disp(1,1,"菜单/ 查询");
   		   LCD_const_disp(2,3,"按顺序");
		   LCD_const_disp(3,3,"最后一次");		 
	       if(config.readMode == READ_MODE_LAST){
		       config.readMode=READ_MODE_FIRST;
			   Set_White(1,2,8,0);
 			   Set_White(1,3,8,1);
		  }
		  else {
		       config.readMode=READ_MODE_LAST;
			   Set_White(1,2,8,1);
 			   Set_White(1,3,8,0);
		 }
		   // 菜单/查询   按顺序/最后一次
		   while(alwaysCheck()){
 		       key=kbscan();
			   dateRefresh(0); //只刷新后台时间
			   //上键短按 选择
			   if(key==up || key ==down){
	    	       if(config.readMode == READ_MODE_LAST){
		    	       config.readMode=READ_MODE_FIRST;
					   Set_White(1,2,8,0);
 					   Set_White(1,3,8,1);
				   }
				   else {
		    	       config.readMode=READ_MODE_LAST;
					   Set_White(1,2,8,1);
 					   Set_White(1,3,8,0);
				   }
				}      
				//左键短按  进入
				if(key == left) {
				    Set_White(1,2,8,1);
 				    Set_White(1,3,8,1);
					delayms(100);
				break ;		
				}
				//右键短按  返回
				if(key == right) {
				    LCD_CLR();
	    			LCD_Init(); //清屏
					return ;	//返回主界面	
				}
				key=0;
		    } //end of while
			if(config.readMode==READ_MODE_LAST){
			    ReadSDFile(file_buf,65535,buf,0); //最后一条
			}
			else {
			    ReadSDFile(file_buf,1,buf,0); //读第一条
			}
			CharToStruct(buf);      //转换
			while(alwaysCheck()){
			    key=kbscan();     //键盘扫描
				dateRefresh(0); //只刷新后台时间
				if(key != 0){ 
					   beep(0,1);
				}
				//dateRefresh(0);  //刷新
				_GUI_datashow(page); //显示
				if( key==left ){ //按left键下一条
					next_item:  //下一条
				    ReadSDFile(file_buf,1,buf,1); //偏移到下一条
					CharToStruct(buf);
					LCD_CLR();
		    		LCD_Init();
					page = 0;
					key=0;
				}
				if( key==lleft ){ //长按left键上一条
		    	    pre_item: //上一条
					ReadSDFile(file_buf,-1,buf,1); //偏移到上一条
					CharToStruct(buf);
					LCD_CLR();
		    		LCD_Init();
					page = 0;
					key=0;
				}
				if(key==up){ //上键 : 页面减 
	    		     LCD_CLR();
		    		 LCD_Init();
					 if(page>0) page--;
	    			 else{ 
					    goto pre_item;
					 }
				}
				if(key==lup){ //长按上键 : -10 条 
	    		     LCD_CLR();
		    		 LCD_Init();
					 ReadSDFile(file_buf,-10,buf,1); //偏移到下10条
					 CharToStruct(buf);
					 page = 0;
					 key = 0;
				}
				if(key==down){ //下键 ： 页面加
					LCD_CLR();
		    		LCD_Init();
					if(page<5) page++;
	  				else{
						goto next_item;
					}
				}
				if(key==ldown){ //长按下键 ： 页面加10条·
					LCD_CLR();
		    		LCD_Init();
					page = 0;
					key = 0;
	 				ReadSDFile(file_buf,10,buf,1); //偏移到下10条
					CharToStruct(buf);
				}
				//右键短按  返回
				if(key == right) {
				    LCD_CLR();
		    		LCD_Init();
					goto label_recheck;	   
				}
				if(page == 0 ){
					LCD_const_disp(4,1,"ID:             ");
					LCD_const_disp(4,3,Result.IndexChar);
				}

    			delayms(30); 
		 }//end while
		   
	}
	else { //未找到或未确认文件
		 //逆序查找文件，直到月份小于 200001.xls
		 //或是手工确认的方式
	}

}
void GUI_welcome(void){
    LCD_CLR(); //清屏
	LCD_const_disp(2,3,"欢迎使用");
	LCD_const_disp(3,1,"环境冷强度检测仪");
	delayms(800);
	beep(0,1);
	
}

////////////////////////////////////
//  函数作用
//   将ds1302中缓存的时钟数据转换进结构体中
////////////////////////////////////
void dateRefresh(unsigned char readhardware)
{	//readhardware = 0 not refresh, =1 refresh

 if( readhardware!=88 )	ds1302_read_time();
	t.tm_sec=(((time_buf[6]&0x70)>>4)*10)+(time_buf[6]&0x0f);
	t.tm_min=  (((time_buf[5]&0x70)>>4)*10)+(time_buf[5]&0x0f);
	t.tm_hour=  (((time_buf[4]&0x70)>>4)*10)+(time_buf[4]&0x0f);
	t.tm_mday=	(((time_buf[3]&0x70)>>4)*10)+(time_buf[3]&0x0f);
	t.tm_mon= (((time_buf[2]&0x70)>>4)*10)+(time_buf[2]&0x0f);
	t.tm_wday=	(time_buf[7]&0x0f);
    t.tm_year=	(((time_buf[1]&0x70)>>4)*10)+(time_buf[1]&0x0f);
	if(readhardware != 0){
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
	//Result.Time[3]=' ';
	Result.Time[3]=t.tm_min/10+'0';
	Result.Time[4]=t.tm_min%10+'0';
	Result.Time[5]=':';
	//Result.Time[7]=' ';
	Result.Time[6]=t.tm_sec/10+'0';
	Result.Time[7]=t.tm_sec%10+'0';
	Result.Time[8]='\0'; 
	}
    config.now =t.tm_hour*3600 + t.tm_min*60 + t.tm_sec; //更新系统心跳
	
}