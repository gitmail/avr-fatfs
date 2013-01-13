NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008C   0044 =     68. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       00D0  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00D0   03F4 =   1012. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04C4  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04C4   85EC =  34284. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0262  __start
       0262  __text_start
       0284  _exit
       0285  _disk_initialize
       029B  _disk_status
       02A1  _disk_read
       02C1  _disk_write
       02D9  _disk_ioctl
       02DE  _get_fattime
       02E3  ff.c:mem_cpy
       02F9  ff.c:mem_set
       030B  ff.c:mem_cmp
       032C  ff.c:chk_chr
       033C  ff.c:move_window
       03DE  ff.c:sync
       04B3  _clust2sect
       0505  _get_fat
       0655  _put_fat
       0814  ff.c:remove_chain
       08C7  ff.c:create_chain
       0A3F  ff.c:clmt_clust
       0AB8  ff.c:dir_sdi
       0BC2  ff.c:dir_next
       0D70  ff.c:dir_find
       0DB5  ff.c:dir_read
       0E00  ff.c:dir_register
       0E63  ff.c:create_name
       0F6B  ff.c:get_fileinfo
       100E  ff.c:follow_path
       1092  ff.c:check_fs
       115A  ff.c:chk_mounted
       1654  ff.c:validate
       1671  _f_mount
       169C  _f_open
       1838  _f_read
       1AA3  _f_write
       1DBC  _f_sync
       1E6D  _f_close
       1E7D  _f_lseek
       233A  _f_opendir
       23AE  _f_readdir
       23F7  _delayus
       23FF  _delayms
       2416  _initDevices
       244B  _main
       24A2  _selfTest
       255B  _WriteFileHead
       25D7  _WriteSDFile
       2639  _ReadSDFile
       269E  _findIndex
       27FE  _check
       292C  _ftochr
       296D  _itochr
       297D  _StructToChar
       29E6  _CharToStruct
       2A26  _get_name
       2A65  _SquareRootFloat
       2B01  _debug
       2B1E  _SD_Write_cmd
       2B50  _SD_Init
       2BB0  _SD_Write_Sector
       2C36  _SD_Read_Sector
       2CA4  _SD_Read_Sector_ndata
       2D29  _GUI_mainmeu
       2E0D  _GUI_check
       2FC9  __GUI_datashow
       31DA  _GUI_get_date
       3208  _GUI_set_time
       3450  _GUI_welcome
       346D  _dateRefresh
       35B9  _uart1_init
       35CA  _uart1_rx_isr
       35D3  _Usart_Transmit
       35DA  _Puts
       35F0  _Send_nByte
       3605  _PrintString
       3614  _PrintString_n
       3627  _PrintLong
       376F  _PrintChar
       378F  _SPI_IO_Init
       3799  _SPI_Write
       379D  _SPI_Read
       37A3  _LCD_SW
       37AD  _LCD_INT
       37B6  _address
       37D7  _LCD_const_disp
       3804  _LCD_var_disp
       3831  _LCD_char_disp
       384B  _LCD_Init
       387D  _LCD_CLR
       389D  _W_1byte
       38D6  _Write_8bits
       38FB  _Set_Draw
       3907  _Set_White
       3999  _set_white_n
       39E5  _clr_white
       3A6D  _LCD_print2num
       3A99  _LCD_print4num
       3ABD  _LCD_print
       3AD2  _LCD_print1
       3ADC  _lp
       3B44  _relay_init
       3B47  _relay
       3B52  _beep
       3B7B  _Delay_nus
       3B8B  _reset_18B20
       3BF7  _write_bit_18B20
       3C3F  _read_bit_18B20
       3C92  _write_byte_18B20
       3CB3  _read_byte_18B20
       3CD4  _convert_T
       3CDC  _read_T
       3D0F  _read_T_NUM
       3D2D  _ds1302_init
       3D32  _ds1302_write_byte
       3D54  _ds1302_read_byte
       3D79  _ds1302_write_time
       3D9E  _ds1302_read_time
       3DC6  _kbscan
       3E0B  _memset
       3E16  _strcat
       3E23  _strlen
       3E2F  push_arg4
       3E31  push_arg2
       3E34  asr32
       3E40  mod16s
       3E44  div16s
       3E5E  mod16u
       3E60  div16u
       3E61  xdiv16u
       3E7A  div32u
       3E7C  mod32u
       3E80  div32s
       3E82  mod32s
       3EAE  long_div_prolog
       3EC1  long_div_epilog
       3ED1  tst_R16_R19
       3ED6  tst_R24_R27
       3EDB  neg_R24_R27
       3EE4  mod8u
       3EE6  div8u
       3EE7  xdiv8u
       3EFC  elpm32
       3F10  empy16s
       3F20  empy32u
       3F20  empy32s
       3F54  pop_xgset003C
       3F59  pop_xgset00FC
       3F60  pop_xgset30FC
       3F69  pop_xgsetF0FC
       3F74  push_xgsetF0FC
       3F76  push_xgset30FC
       3F78  push_xgset00FC
       3F7A  push_xgset003C
       3F7F  push_xgset300C
       3F84  pop_xgset300C
       3F89  push_xgsetF000
       3F8E  pop_xgsetF000
       3F93  push_xgsetF00C
       3F9A  pop_xgsetF00C
       3FA1  push_xgset303C
       3FA8  pop_xgset303C
       3FAF  push_xgsetF03C
       3FB8  pop_xgsetF03C
       3FC1  neg32
       3FCA  long_prolog
       3FD8  long_epilog
       3FE3  tstzero1
       3FE9  tstzero2
       3FEF  lsl16
       3FF6  lsl32
       4002  lsl8
       4008  lsr16
       400F  lsr32
       401B  asgnblk
       4033  fpsub
       4035  fpadd
       4036  fpadd_alt
       409D  fpadd2
       40A8  fpsub2
       40B3  fpsub1x
       40C0  fpsub2x
       40CE  uint2fp
       40D0  int2fp
       40D9  ulong2fp
       40DB  long2fp
       40F2  fpdiv1
       40FB  fpdiv2
       4105  fpdiv1x
       4111  fpdiv2x
       418C  unpacks
       4194  tstR16_R19
       419C  unpacku
       41B5  normalize_and_pack
       41EA  pack
       41FA  saveFPRegs
       4209  restoreFPRegs
       4218  fpmule
       426B  fpmule1
       4275  fpmule2
       4280  fpmule1x
       428D  fpcmp
       429A  fpcmp2
       42A6  _itoa
       4311  _ltoa
       43C9  _ftoa
       4558  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   03F4 =   1012. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0262  _labelH
       0270  _labelM
       0280  _labelL
       028E  _H01
       029E  _H02
       02A9  _H03
       02BB  _M03
       02C5  _M04
       02CF  _L03
       02DE  _H13
       02EE  _M12
       0300  _M13
       0312  _L11
       0324  _L12
       0336  _M21
       0345  _GUI_date
       04D0  lcd.c:p1
       04D2  lcd.c:p2
       04D4  lcd.c:p3
       04D6  lcd.c:p4
       04EB  _T_NUM
       04EC  _time_buf
       04F4  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   04F4   02E6 =    742. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       04F4  __bss_start
       04F4  ff.c:Fsid
       04F6  ff.c:FatFs
       04F8  _TempChar
       0548  _Result
       05A6  _buffer
       07A6  _t
       07B8  _config
       07DA  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

E:\PROGRA~1\icc\lib\crtatmega.o	[ crtatmega.s ]
diskio.o	[ diskio.c ]
ff.o	[ ff.c ]
delay.o	[ delay.c ]
main.o	[ main.c ]
sd.o	[ sd.c ]
gui.o	[ gui.c ]
usart.o	[ usart.c ]
SPI.o	[ SPI.c ]
lcd.o	[ lcd.c ]
relay.o	[ relay.c ]
beep.o	[ beep.c ]
DS18B20_driver.o	[ DS18B20_driver.c ]
ds1302.o	[ ds1302.c ]
key.o	[ key.c ]
<library>	[ memset.s, strcat.s, strlen.s, asave.s, asr32.s, div16s.s, div16u.s, div32.s, div8u.s, elpm32.s, emul16s.s ]
[ emul32.s, gpop2.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s, gpushb.s ]
[ lneg.s, longutil.s, lsl16.s, lsl32.s, lsl8.s, lsr16.s, lsr32.s, struct.s, fpadd.s, fpadd2.s, fpsub2.s ]
[ fpsub1x.s, fpsub2x.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s, fpmule1.s, fpmule2.s, fpmule1x.s ]
[ fpcmp.s, fpcmp2.s, itoa.s, ltoa.s, ftoa.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

