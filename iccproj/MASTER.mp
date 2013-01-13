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
                           idata   00D0   03EE =   1006. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04BE  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04BE   85E4 =  34276. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       025F  __start
       025F  __text_start
       0281  _exit
       0282  _disk_initialize
       0298  _disk_status
       029E  _disk_read
       02BE  _disk_write
       02D6  _disk_ioctl
       02DB  _get_fattime
       02E0  ff.c:mem_cpy
       02F6  ff.c:mem_set
       0308  ff.c:mem_cmp
       0329  ff.c:chk_chr
       0339  ff.c:move_window
       03DB  ff.c:sync
       04B0  _clust2sect
       0502  _get_fat
       0652  _put_fat
       0811  ff.c:remove_chain
       08C4  ff.c:create_chain
       0A3C  ff.c:clmt_clust
       0AB5  ff.c:dir_sdi
       0BBF  ff.c:dir_next
       0D6D  ff.c:dir_find
       0DB2  ff.c:dir_read
       0DFD  ff.c:dir_register
       0E60  ff.c:create_name
       0F68  ff.c:get_fileinfo
       100B  ff.c:follow_path
       108F  ff.c:check_fs
       1157  ff.c:chk_mounted
       1651  ff.c:validate
       166E  _f_mount
       1699  _f_open
       1835  _f_read
       1AA0  _f_write
       1DB9  _f_sync
       1E6A  _f_close
       1E7A  _f_lseek
       2337  _f_opendir
       23AB  _f_readdir
       23F4  _delayus
       23FC  _delayms
       2413  _initDevices
       2440  _main
       24A6  _selfTest
       255F  _WriteFileHead
       25DB  _WriteSDFile
       263D  _ReadSDFile
       26A2  _findIndex
       2802  _check
       2930  _ftochr
       2971  _itochr
       2981  _StructToChar
       29EA  _CharToStruct
       2A2A  _get_name
       2A69  _SquareRootFloat
       2B05  _debug
       2B22  _SD_Write_cmd
       2B54  _SD_Init
       2BB4  _SD_Write_Sector
       2C3A  _SD_Read_Sector
       2CA8  _SD_Read_Sector_ndata
       2D2D  _GUI_mainmeu
       2E15  _GUI_check
       2FDF  __GUI_datashow
       31F0  _GUI_get_date
       321E  _GUI_set_time
       3466  _dateRefresh
       35B2  _uart1_init
       35C3  _uart1_rx_isr
       35CC  _Usart_Transmit
       35D3  _Puts
       35E9  _Send_nByte
       35FE  _PrintString
       360D  _PrintString_n
       3620  _PrintLong
       3768  _PrintChar
       3788  _SPI_IO_Init
       3792  _SPI_Write
       3796  _SPI_Read
       379C  _LCD_SW
       37A6  _LCD_INT
       37AF  _address
       37D0  _LCD_const_disp
       37FD  _LCD_var_disp
       382A  _LCD_char_disp
       3844  _LCD_Init
       3876  _LCD_CLR
       3896  _W_1byte
       38CF  _Write_8bits
       38F4  _Set_Draw
       3900  _Set_White
       3992  _set_white_n
       39DE  _clr_white
       3A66  _LCD_print2num
       3A92  _LCD_print4num
       3AB6  _LCD_print
       3ACB  _LCD_print1
       3AD5  _lp
       3B3D  _relay_init
       3B40  _relay
       3B4B  _beep
       3B74  _Delay_nus
       3B84  _reset_18B20
       3BF0  _write_bit_18B20
       3C38  _read_bit_18B20
       3C8B  _write_byte_18B20
       3CAC  _read_byte_18B20
       3CCD  _convert_T
       3CD5  _read_T
       3D08  _read_T_NUM
       3D26  _ds1302_init
       3D2B  _ds1302_write_byte
       3D4D  _ds1302_read_byte
       3D72  _ds1302_write_time
       3D97  _ds1302_read_time
       3DBF  _kbscan
       3E04  _memset
       3E0F  _strcat
       3E1C  _strlen
       3E28  push_arg4
       3E2A  push_arg2
       3E2D  asr32
       3E39  mod16s
       3E3D  div16s
       3E57  mod16u
       3E59  div16u
       3E5A  xdiv16u
       3E73  div32u
       3E75  mod32u
       3E79  div32s
       3E7B  mod32s
       3EA7  long_div_prolog
       3EBA  long_div_epilog
       3ECA  tst_R16_R19
       3ECF  tst_R24_R27
       3ED4  neg_R24_R27
       3EDD  mod8u
       3EDF  div8u
       3EE0  xdiv8u
       3EF5  elpm32
       3F09  empy16s
       3F19  empy32u
       3F19  empy32s
       3F4D  pop_xgset003C
       3F52  pop_xgset00FC
       3F59  pop_xgset30FC
       3F62  pop_xgsetF0FC
       3F6D  push_xgsetF0FC
       3F6F  push_xgset30FC
       3F71  push_xgset00FC
       3F73  push_xgset003C
       3F78  push_xgset300C
       3F7D  pop_xgset300C
       3F82  push_xgsetF000
       3F87  pop_xgsetF000
       3F8C  push_xgsetF00C
       3F93  pop_xgsetF00C
       3F9A  push_xgset303C
       3FA1  pop_xgset303C
       3FA8  push_xgsetF03C
       3FB1  pop_xgsetF03C
       3FBA  neg32
       3FC3  long_prolog
       3FD1  long_epilog
       3FDC  tstzero1
       3FE2  tstzero2
       3FE8  lsl16
       3FEF  lsl32
       3FFB  lsl8
       4001  lsr16
       4008  lsr32
       4014  asgnblk
       402C  fpsub
       402E  fpadd
       402F  fpadd_alt
       4096  fpadd2
       40A1  fpsub2
       40AC  fpsub1x
       40B9  fpsub2x
       40C7  uint2fp
       40C9  int2fp
       40D2  ulong2fp
       40D4  long2fp
       40EB  fpdiv1
       40F4  fpdiv2
       40FE  fpdiv1x
       410A  fpdiv2x
       4185  unpacks
       418D  tstR16_R19
       4195  unpacku
       41AE  normalize_and_pack
       41E3  pack
       41F3  saveFPRegs
       4202  restoreFPRegs
       4211  fpmule
       4264  fpmule1
       426E  fpmule2
       4279  fpmule1x
       4286  fpcmp
       4293  fpcmp2
       429F  _itoa
       430A  _ltoa
       43C2  _ftoa
       4551  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   03EE =   1006. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0269  _labelH
       0277  _labelM
       0287  _labelL
       0295  _H01
       02A5  _H02
       02B0  _H03
       02C2  _M03
       02CC  _M04
       02D6  _L03
       02E5  _H13
       02F5  _M12
       0307  _M13
       0319  _L11
       032B  _L12
       033D  _M21
       034C  _GUI_date
       04CA  lcd.c:p1
       04CC  lcd.c:p2
       04CE  lcd.c:p3
       04D0  lcd.c:p4
       04E5  _T_NUM
       04E6  _time_buf
       04EE  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   04EE   02E4 =    740. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       04EE  __bss_start
       04EE  ff.c:Fsid
       04F0  ff.c:FatFs
       04F2  _TempChar
       0542  _Result
       05A0  _buffer
       07A0  _t
       07B2  _config
       07D2  __bss_end

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

