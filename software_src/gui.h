#ifndef _GUI_H_
#define _GUI_H_
extern char GUI_date[17];
void GUI_set_time(void);
char * GUI_get_date(void) ;
void GUI_check(void);
unsigned char GUI_mainmeu( void );
void dateRefresh(unsigned char readhardware);
#endif