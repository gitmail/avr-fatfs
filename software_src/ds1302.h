#ifndef _DS1302_H_
#define _DS1302_H_

extern unsigned char time_buf[8];

void ds1302_read_time(void);
void ds1302_write_time(void);
void ds1302_init(void);
void ds1302_change_time(void);
#endif