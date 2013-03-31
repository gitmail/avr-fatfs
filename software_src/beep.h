//函数说明
//硬件接口见beep.c文件
//beep(l,s);  报警音函数 l代表长音  s代表短音
//使用举例 beep(3,2);  三长两短    
//         beep(0,10); 0长10短

//声音约定
//自检通过 两短
//出现故障 
//-------------------硬件故障1长+
// 传感器丢失 A B C 风速 = 1、2、3、4短
//风速传感器（5短）  实时时钟故障（6短）
         
//-------------------函数意外2长+
//sd卡函数。。
//

  
//------------------其他故障 ：三长两短 


//未完待续         


#ifndef _BEEP_H_
#define _BEEP_H_


void beep(unsigned char long_beep,unsigned char short_beep);
void beep_rec(void);
#endif