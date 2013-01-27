#include "config.h"
//键盘扫描函数
unsigned char kbscan(void)
  {
   unsigned char key;
   unsigned long temp=0;
   DDR_SET;
   
   if((KEY_PIN) != KEY_MASK)         //检测A口按键引脚电平，如果全是高电平则退出
    {
     delayms(20);           //防抖
     if((KEY_PIN) != KEY_MASK )      //再次检测A口电平，如果不全是高电平则继续执行程序
      {
       key = KEY_PIN ;          //读取PINA，将其存放在key中
        while((KEY_PIN) != KEY_MASK)
		{
		 temp++ ;
		 if(temp>LONGKEY) {  
		     delayms(30);
			 return key+0x80;  
		 };
		}
		; //当前有按键处于按下状态，再按其他按键时程序维持当前状态 
      	
		return key;
	  
	  }
    }
	else return NO_KEY;
	
	return NO_KEY;
	}	



/*
unsigned char kbscan(void)
{
   unsigned  int i=0;
   unsigned char tmp;
   unsigned char ReadData=KEY_PIN ^ 0XFF; //0  1 0   1
  Try = ReadData & ( ReadData ^ Cont );   //0 1 0   0
  Cont = ReadData; 	 		  		 	  //0 1	0   1
 return Cont;

 
     
      char key_in; 
      char key_return = NO_KEY,key_temp= NO_KEY;
      unsigned int holdtime=0;
	  unsigned char i;
	DDR_SET;
	key_in=KEY_PIN & KEY_MASK;
	key_in=KEY_PIN & KEY_MASK;
	//
	if(key_in!=KEY_MASK)
		 {	
		 	delayms(30); 
			key_in=KEY_PIN & KEY_MASK;
			if(key_in!=KEY_MASK) 
				{   RELAY_ON();delayms(5); RELAY_OFF();delayms(5);
				  	do { 
					    key_return = key_temp>>3;
					    delayms(1);
						key_temp=KEY_PIN & KEY_MASK	;					 				 
						holdtime++;
					}while( key_temp !=KEY_MASK )	;
					
					if ( holdtime>LOMGKEY ) holdtime=10;
					else holdtime=0;
					 
					for(i=0;i<5;i++)
					{
					key_return=key_return>>i;
					if( !(key_return & 0x01) ){
						return i+holdtime;
					 }
					
					}
					return NO_KEY;
								 			
			}
		 }
	
	 			   
            
 
}
*/