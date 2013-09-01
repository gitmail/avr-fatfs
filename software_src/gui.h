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

 
extern const char labelH[];
extern const char labelM[];
extern const char labelL[];
extern const char H01[];
extern const char H02[];
extern const char H03[];
#define M01 H01
#define M02 H03
extern const char M03[];
extern const char M04[];
#define L01 M03
#define L02 M04
extern const char L03[];
//-----//
#define H11 M04
#define H12 H03
extern const char H13[];
#define M11 H01
extern const char M12[];
extern const char M13[];
extern const char L11[];
extern const char L12[];
#define L13 H03
//-----//
#define H21 L11
#define H22 L12
#define H23 H03
extern const char M21[]; 
#define L21 M21

extern const char str_weihai[3][17];


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