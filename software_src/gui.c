#include "config.h"
const char labelH[]="¸ßÇ¿¶È×÷Òµ£º\0";
const char labelM[]="ÖÐµÈÇ¿¶È×÷Òµ£º\0";
const char labelL[]="µÍÇ¿¶È×÷Òµ£º\0";
const char H01[]="¼ÓÇ¿ÀÍ¶¯¼à¶½£»\0";
const char H02[]="Ôö¼ÓÒûË®;\0" ;
const char H03[]="±£³Ö¸ÉÔï½ûÂãÂ¶¡£\0";
#define M01 H01
#define M02 H03
const char M03[]="´÷ÃæÕÖ¡£\0";
const char M04[]="½ûÓÍ²Ê¡£\0";
#define L01 M03
#define L02 M04
const char L03[]="Ëõ¶Ì×÷ÒµÊ±¼ä¡£";
//-----//
#define H11 M04
#define H12 H03
const char H13[]="ÐÝÏ¢×¢Òâ±£Å¯¡£\0";
#define M11 H01
const char M12[]="¼õÉÙ·Ç±ØÐë×÷Òµ£»\0";
const char M13[]="ÀÍ¶¯Ê±¼ä<30min¡£\0";
const char L11[]="È¡Ïû·Ç±ØÐëµÄ×÷Òµ\0";
const char L12[]="ÀÍ¶¯Ê±¼ä<15min£»\0";
#define L13 H03
//-----//
#define H21 L11
#define H22 L12
#define H23 H03
const char M21[]="È¡Ïû»§Íâ×÷Òµ¡£"; 
#define L21 M21

//#define LEDON   PORTC&=~(1<<7)					   
//#define LEDOFF  PINC|=(1<<7)
char GUI_date[17]="09ÔÂ19ÈÕ18:00:00\0";

// Ö÷²Ëµ¥
unsigned char GUI_mainmeu( void ){
 	unsigned char key=0; //init= nokey
	unsigned char select=3;
	LCD_CLR();
	
 	Set_White(1,1,8,1);
	Set_White(1,2,8,1);
	Set_White(1,3,8,1);
	Set_White(1,4,8,1);
	dateRefresh(1); //¸üÐÂÏµÍ³Ê±¼ä
	LCD_const_disp(1,1,GUI_get_date()); //ÏÔÊ¾Ê±¼ä
	LCD_const_disp(2,1,"  ¼ì²â  Ê±ÖÓµ÷Õû");
	LCD_const_disp(3,1,"  ²éÑ¯  Êý¾Ý´«Êä");
	LCD_const_disp(4,1,"  ³õÊ¼»¯");
	Set_White(1,1,8,1);
	Set_White(1,2,8,1);
	Set_White(1,3,8,1);
	Set_White(1,4,8,1);
	set_white_n(select,0);
	while(1)
	{
	 	key=kbscan();
		dateRefresh(1); //¸üÐÂÏµÍ³Ê±¼ä
		LCD_const_disp(1,1,GUI_get_date()); //ÏÔÊ¾Ê±¼ä
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
    }
	return 0xff; //error
	
}

//¡±¼ì²â ¡°²Ëµ¥
void GUI_check(void){
    char key;
	char page=0,is_on=0;
	char windcounter=0;
	unsigned long next_step_time=0;
	char selectCheckMode=config.autocheck; //×Ô¶¯¼ì²â¿ª¹Ø
RE_IN:
	dateRefresh(1);
	LCD_CLR();
	LCD_const_disp(1,1,"²Ëµ¥/ ¼ì²â");
	LCD_const_disp(2,3,"×Ô¶¯");		 
	LCD_const_disp(3,3,"ÊÖ¶¯");
	if(selectCheckMode==1) {
	    Set_White(1,2,8,0);
		Set_White(1,3,8,1);
	}
	else {
		 Set_White(1,2,8,1);
		 Set_White(1,3,8,0);
	}
	
//<<²Ëµ¥/¼ì²â/ÊÖ£¨×Ô£©¶¯>>
	while(1){
	 	key=kbscan();
		//ÉÏ¼ü¶Ì°´ Ñ¡Ôñ
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
		//×ó¼ü¶Ì°´  ½øÈë
		if(key == left) {
			config.autocheck=selectCheckMode; 
			Set_White(1,2,8,1);
	 		Set_White(1,3,8,1); 
			break ;		
		}
		//ÓÒ¼ü¶Ì°´  ·µ»Ø
		if(key == right) {
			return ;		
		}
		key=0;
	} //end of while
    //×Ô¶¯¿ªÆô¼ì²â
	dateRefresh(0);
	is_on =1 ;
	config.time1=config.now+config.THRESHOLD_delta_sec;
	Result.TempChar[0]=0; //Çå³ýÉÏ´Î½á¹û
	Result.WSChar[0]=0;
	while(1){
		key=kbscan();
		if(key != 0) beep(0,1);
		if(key==right){	//ÓÒ¼ü ÍË³ö
		    is_on=0;
			LCD_CLR();
		 	LCD_Init();	  
	 	 	LCD_const_disp(4,5,"ÍË³ö    "); 
		 	delayms(200);
		 	LCD_const_disp(4,7,".."); 
		 	delayms(200);
		 	LCD_const_disp(4,8,".."); 	
		 	delayms(500);
		 	LCD_CLR();
		 	goto RE_IN;
		}
		if(is_on==1){ 
			dateRefresh(1); 
		    _GUI_datashow(page); //¸üÐÂÊ±¼ä
		    if(config.now < config.time1) {
				//Ê±¼ä¸üÐÂ ¿ªÆô·çËÙ¼ì²â µÈ´ý¼ì²â ²»Ö§³Ö·­Ò³
				if(windcounter==0){
				    windcounter=1; //ÇåÁã¿ªÆô·çËÙ¼ÆÊýÆ÷
					timer1_init(); //¿ªÆô·çËÙ´«¸ÐÆ÷¼¼Êõ
				}
				if(page == 0 ){
				
				    LCD_const_disp(4,1,"ÕýÔÚ¼ì²â");
					LCD_print4num(4,5,config.time1-config.now);
					LCD_const_disp(2,6,"      ");
					LCD_const_disp(3,6,"      ");
				}
			} 
			else {
			   //¼ì²âÍê³É »ñµÃÊý¾Ý ×ª»»Êý¾Ý ´æ´¢Êý¾Ý ÇÐ»»µ½·Ç¼ì²â×´Ì¬
			    windcounter =0 ; //¹Ø±Õ·çËÙ´«¸ÐÆ÷¼ÆÊýÆ÷
				check();
				StructToChar(); //×ª³É×Ö·û´®
				WriteFileHead();//ÖØÐ´ÎÄ¼þÍ·
				WriteSDFile();  //Ð´Èësd¿¨
				//zigbee_send(); //·¢ËÍ
				Result.Index++; //Ë÷Òý×ÔÔöÒ»
				is_on=0; //ÇÐ»»µ½·Ç¼ì²â×´Ì¬
				next_step_time=config.now+config.checkDeltaTime;//×Ô¶¯·­Ò³Ê±¼ä¸üÐÂ
				page=0;
		   }
		}
		else { //is_on == 0 ·Ç¼ì²â×´Ì¬ ÊÖ¶¯·­Ò³/×Ô¶¯·­Ò³
		    dateRefresh(0);//²»¸üÐÂÊ±¼ä
			_GUI_datashow(page); 
			if(page == 0 ){
				
				    LCD_const_disp(4,1,"Íê³É¼ì²â        ");
					if(config.autocheck == 1){
					    LCD_const_disp(4,7,"×Ô¶¯");
					}
					else {
					    LCD_const_disp(4,7,"ÊÖ¶¯");
					}
					
				}
						//ÊÖ¶¯·­Ò³ 
			if(key==up){ //ÉÏ¼ü : Ò³Ãæ¼õ 
		        if(page>0) page--;
				else{
				page =5;
				next_step_time = config.now + config.checkDeltaTime;
				}
		    	LCD_CLR();
		    	LCD_Init();
			}
			if(key==down){//ÏÂ¼ü £º Ò³Ãæ¼Ó
		        page++;
				next_step_time = config.now + config.checkDeltaTime;
		  		LCD_CLR();
		    	LCD_Init();
			} 	
			//LCD_print2num(4,1,page);
			//LCD_print4num(4,3,config.now);
			//LCD_print4num(4,6,next_step_time);
			if( config.autocheck == 1 ){  //Èç¹û¿ªÆô×Ô¶¯·­Ò³
			      if(config.now >= next_step_time || page >=6 )	{
				      next_step_time = config.now + config.checkDeltaTime;
					  page++;
					  if( page>=6 ){
					      //×Ô¶¯·­µ½×îºóÒ³£¬Ò³ÃæÇåÁã¿ªÆôÏÂ´Î¼ì²â
					      page = 0;
						  dateRefresh(1); //Ë¢ÐÂÊ±¼ä
						  is_on =1 ; //¿ªÆô¼ì²â
						  config.time1=config.now+config.THRESHOLD_delta_sec; //¸üÐÂÏÂ´Î¼ì²âÊ±¼ä
						  Result.TempChar[0]=0; //Çå³ýÉÏ´Î½á¹û
						  Result.WSChar[0]=0;
					  }
				      LCD_CLR();      
					  key=0;
				  }  
			}

			

			 
		} 
	    delayms(10); 
	}//end while
}//end function
void _GUI_datashow(char page){
	if(page == 0){
 	//ÏÔÊ¾ÈÕÆÚÊ±¼ä
	    LCD_var_disp(1,1,GUI_get_date());
	//ÏÔÊ¾ÎÂ¶È
	 	LCD_const_disp(2,1,"ÎÂ¶È (¡æ):");
	 	LCD_var_disp(2,6,Result.TempChar);
	//ÏÔÊ¾·çËÙ
	    LCD_const_disp(3,1,"·çËÙ(m/s): ");
	 	LCD_const_disp(3,6,Result.WSChar);

	 } 
	 if(page == 1){
	     LCD_var_disp(1,1,GUI_get_date());
		 LCD_const_disp(2,1,"·çÀäÖ¸Êý: ");
		 LCD_var_disp(2,6,Result.WCIChar);						
		 LCD_const_disp(3,1,"µÈ¼ÛÎÂ¶È: ");
		 LCD_var_disp(3,6,Result.ECTChar);	 
		 LCD_const_disp(4,1,"Ïàµ±ÎÂ¶È: ");
		 LCD_var_disp(4,6,Result.TeqChar);	
	 }
	 if(page == 2){
	     LCD_var_disp(1,1,GUI_get_date());
		 LCD_const_disp(2,1,"¶³ÉËÎ£º¦ÐÔ:");
	 if(Result.WeiHai==0){LCD_const_disp(3,1,"  ¶³ÉËÎ£º¦ÐÔÐ¡");			 }
	 else if(Result.WeiHai==1){	LCD_const_disp(3,1,"  ¶³ÉËÎ£º¦ÐÔ½Ï´ó");	 }
	 else if(Result.WeiHai==2){	LCD_const_disp(3,1,"  ¶³ÉËÎ£º¦ÐÔºÜ´ó");	 }
	 else LCD_const_disp(3,1,"¶³ÉËÎ£º¦ÐÔÐ¡¡£");
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
				if(Result.Temperature < 17.7){
				    LCD_const_disp(4,1,"´÷ÃæÕÖ£»½ûÓÍ²Ê¡£");
				}
				else if(Result.Temperature < 12){
				    LCD_const_disp(4,1,"½ûÓÍ²Ê¡£        \0");
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
  //¸ñÊ½£12Äê12ÔÂ11ÈÕ19:00:00
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
//ÉèÖÃÊ±¼ä ²Ëµ¥ 
void GUI_set_time(void){
    unsigned char p=2;
	char GUI_up[]= "¡ü";
	char GUI_down[]= "¡ý";
	char *pD=NULL,*pT=NULL;
	char *ary=GUI_up;
	unsigned char i=0,keyc=NO_KEY;
	LCD_CLR(); //ÇåÆÁ
	pD="2012Äê12ÔÂ31ÈÕ\0";
	pT=Result.Time;
	LCD_const_disp(1,1,"Ê±¼äÉèÖÃ:       ");
	LCD_const_disp(4,7,"±£´æ");
	LCD_var_disp(3,p,ary);
	LCD_var_disp(2,1,pD);
	LCD_var_disp(4,1,pT);
	delayms(250);
	while(1){
	    keyc=kbscan();
		pD[2]=Result.Date[2];
		pD[3]=Result.Date[3];
		pD[6]=Result.Date[4];
		pD[7]=Result.Date[5];
		pD[10]=Result.Date[6];
		pD[11]=Result.Date[7];  

		switch(i){
            case 0: p=2;ary=GUI_up;  //Äê
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
				else if(keyc==right) {i=1;}
				break;
		 case 1:p=4;ary=GUI_up;  //ÔÂ
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
				    i=0;   
				}									
				if(keyc==right){
				    i=2;   
				}  
				break;
	 	 case 2: p=6;ary=GUI_up;
		 	  	 if(keyc==up){ 
				     if(time_buf[3]<0x31){ 
				         time_buf[3]++;
						 if ((time_buf[3]&0x0f)==0x0a) time_buf[3]=time_buf[3]+6;
						 if(  //2 4 6 9 11 ÔÂ×î´ó30Ìì
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
 		 dateRefresh(1);
		 
		 LCD_const_disp(3,1,"                "); //Çå¿Õ¼ýÍ· 
 		 LCD_var_disp(3,p,ary); //ÏÔÊ¾¼ýÍ· 
 		 LCD_var_disp(2,1,pD);  //ÏÔÊ¾ÈÕÆÚ
 		 LCD_var_disp(4,1,pT);  //ÏÔÊ¾Ê±¼ä
 if(keyc==lright) {		  
 		  LCD_const_disp(3,1,"        ·ÅÆúÐÞ¸Ä"); 
		  delayms(500);
		  LCD_CLR(); //ÇåÆÁ
		  return ;} 
 keyc=NO_KEY;
 if(i==6){    //¸÷Öµ¸Ä±äÍê³Éºó ÏÔÊ¾ÒÑ±£´æ ÇåÆÁ ·µ»Ø
		  ds1302_write_time(); 
          LCD_const_disp(4,7,"    ");		  
		  LCD_const_disp(3,1,"          ÒÑ±£´æ"); 
		  delayms(300);
		  LCD_CLR(); //ÇåÆÁ
		  return ;
		  }
 delayms(2);	  
}//endwhile(1)
}
void GUI_readback(char *buf){
    char key=0;
	char page=0;
	long index=Result.Index;
	LCD_CLR(); //ÇåÆÁ
	LCD_const_disp(1,1,"²Ëµ¥/ ¼ì²â");
    LCD_const_disp(2,3,"×îºóÒ»´Î");		 
	LCD_const_disp(3,3,"°´Ë³Ðò");
	//<<²Ëµ¥/¼ì²â/ÊÖ£¨×Ô£©¶¯>>
while(1){
 	key=kbscan();
	//ÉÏ¼ü¶Ì°´ Ñ¡Ôñ
	if(key==up || key ==down){
	    if(config.readMode == 0){
		    config.readMode=1;
			Set_White(1,2,8,0);
 			Set_White(1,3,8,1);
			index=Result.Index;	
		}
		else {
		    config.readMode=0;
			Set_White(1,2,8,1);
 			Set_White(1,3,8,0);
			index=0;
		}
		
	}
	//×ó¼ü¶Ì°´  ½øÈë
	if(key == left) {
		Set_White(1,2,8,1);
 		Set_White(1,3,8,1);
		delayms(100);
		break ;		
	}
	//ÓÒ¼ü¶Ì°´  ·µ»Ø
	if(key == right) {
		return ;		
	}
	key=0;
} //end of while
ReadSDFile(index,buf);
CharToStruct();
while(1){
	key=kbscan();
	if(key != 0) beep(0,1);
	dateRefresh(0);
	_GUI_datashow(page);
	if( key==left ){ //°´left¼üÏÂÒ»Ìõ
pre_item:
		if(index < Result.Index){
		    index++;
			ReadSDFile(index,buf);
			CharToStruct();
			page = 0;
		}
		key=0;
	}
	if( key==lleft ){ //³¤°´°´left¼üÉÏÒ»Ìõ
next_item:
		if(index > 0){
		    index--;
			ReadSDFile(index,buf);
			CharToStruct();
			page = 0;
		}
		key=0;
	}
	
	if(key==up){ //ÉÏ¼ü : Ò³Ãæ¼õ 
	    if(page>0) page--;
	    else goto pre_item;
		LCD_CLR();
	    LCD_Init();
		
	}
	if(key==down){ //ÏÂ¼ü £º Ò³Ãæ¼Ó
	    if(page<5) page++;
	  	else goto next_item;
	    LCD_CLR();
	    LCD_Init();
	}
	if(key==right){	//ÓÒ¼ü ÍË³ö
	    beep(0,1); 
	 	LCD_CLR();
	 	return ;
	}
	
    delayms(30); 
}//end while
}
void GUI_welcome(void){
    LCD_CLR(); //ÇåÆÁ
	LCD_const_disp(2,3,"»¶Ó­Ê¹ÓÃ");
	LCD_const_disp(3,1,"»·¾³ÀäÇ¿¶È¼ì²âÒÇ");
	delayms(800);
	beep(0,1);
	
}

////////////////////////////////////
//  º¯Êý×÷ÓÃ
//   ½«ds1302ÖÐ»º´æµÄÊ±ÖÓÊý¾Ý×ª»»½ø½á¹¹ÌåÖÐ
////////////////////////////////////
void dateRefresh(unsigned char readhardware)
{	//readhardware = 0 not refresh, =1 refresh
	ds1302_read_time();
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
	Result.Time[3]=' ';
	Result.Time[4]=t.tm_min/10+'0';
	Result.Time[5]=t.tm_min%10+'0';
	Result.Time[6]=':';
	Result.Time[7]=' ';
	Result.Time[8]=t.tm_sec/10+'0';
	Result.Time[9]=t.tm_sec%10+'0';
	Result.Time[10]='\0'; 
	}
    config.now =t.tm_hour*3600 + t.tm_min*60 + t.tm_sec; //¸üÐÂÏµÍ³ÐÄÌø
	
}