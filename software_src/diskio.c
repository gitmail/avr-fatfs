

/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2007        */
/*-----------------------------------------------------------------------*/
/* This is a stub disk I/O module that acts as front end of the existing */
/* disk I/O modules and attach it to FatFs module with common interface. */
/*-----------------------------------------------------------------------*/

#include "diskio.h"
#include "sd.h"


/*-----------------------------------------------------------------------*/
/* Correspondence between physical drive number and physical drive.      */
/* Note that Tiny-FatFs supports only single drive and always            */
                                      

////////////////////////////
/*
   struct tm {
   	int tm_sec;   // 秒 seconds after the minute, 0 to 60
   	int tm_min;   // 分 minutes after the hour, 0 to 59
	int tm_hour;  // 时 hours since midnight, 0 to 23*
	int tm_mday;  // 日 day of the month, 1 to 31
	int tm_mon;   // 月 months since January, 0 to 11
	int tm_year;  // 年 years since 1900
	int tm_wday;  // 星期 days since Sunday, 0 to 6
	int tm_yday;  // 从元旦起的天数 days since January 1, 0 to 365
 	int tm_isdst; // 夏令时？？Daylight Savings Time flag
 	};
*/
/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */

DSTATUS disk_initialize ( 
BYTE drv				/* Physical drive nmuber (0..) */
)
{
    unsigned char state;

    if(drv)
    {
        return STA_NOINIT;  //仅支持磁盘0的操作
    }

    state = SD_Init();
    if(state == STA_NODISK)
    {
        return STA_NODISK;
    }
    else if(state != 0)
    {
        return STA_NOINIT;  //其他错误：初始化失败
    }
    else
    {
        return 0;           //初始化成功
    }
}



/*-----------------------------------------------------------------------*/
/* Return Disk Status                                                    */

DSTATUS disk_status (
	BYTE drv		/* Physical drive nmuber (0..) */
)
{
    if(drv)
    {
        return STA_NOINIT;  //仅支持磁盘0操作
    }
    return 0;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */

DRESULT disk_read (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	BYTE count		/* Number of sectors to read (1..255) */
)
{
	unsigned char res=0;
    if (drv || !count)
    {    
        return RES_PARERR;  //仅支持单磁盘操作，count不能等于0，否则返回参数错误
    }

    if(count==1)            //1个sector的读操作      
    {                                                
        res = SD_Read_Sector(sector, buff);      
    }                                                                                                 

    //处理返回值，将SD_driver.c的返回值转成ff.c的返回值
    if(res == 0x00)
    {
        return RES_OK;
    }
    else
    {
        return RES_ERROR;
    }
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */

#if _READONLY == 0
DRESULT disk_write (
	BYTE drv,			/* Physical drive nmuber (0..) */
	BYTE *buff,	        /* Data to be written */
	DWORD sector,		/* Sector address (LBA) */
	BYTE count			/* Number of sectors to write (1..255) */
)
{
    if (drv || !count)
    {    
        return RES_PARERR;  //仅支持单磁盘操作，count不能等于0，否则返回参数错误
    }   
   // 读写操作
    SD_Write_Sector(sector,buff);
	  
    return RES_OK;
}
#endif /* _READONLY */



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
DRESULT disk_ioctl (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE ctrl,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
 	drv=drv;
	ctrl=ctrl;
	buff=buff;
	return 0;
}
DWORD get_fattime (void)
{

  return 1950466005;
}
