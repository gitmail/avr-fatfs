#ifndef _GUI_H_
#define _GUI_H_
extern char GUI_date[17];
void GUI_set_time(void);
char *GUI_get_date(void) ;
void GUI_check(void);
unsigned char GUI_mainmeu( void );
void dateRefresh(unsigned char readhardware);
void _GUI_datashow(char page);
void GUI_welcome(void);
void GUI_readback(char *buf);
//按键操作 基本规则
//1 up   上键/左键
//2 down 下键/右键
//3 left  确认 
//4 right 取消/返回
//长按
//5 lup      
//6 ldown
//7 lleft
//8 ldown
//
#endif