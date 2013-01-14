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
                           idata   00D0   0404 =   1028. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04D4  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04D4   8842 =  34882. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       026A  __start
       026A  __text_start
       028C  _exit
       028D  _disk_initialize
       02A3  _disk_status
       02A9  _disk_read
       02C9  _disk_write
       02E1  _disk_ioctl
       02E6  _get_fattime
       02EB  ff.c:mem_cpy
       0301  ff.c:mem_set
       0313  ff.c:mem_cmp
       0334  ff.c:chk_chr
       0344  ff.c:move_window
       03E6  ff.c:sync
       04BB  _clust2sect
       050D  _get_fat
       065D  _put_fat
       081C  ff.c:remove_chain
       08CF  ff.c:create_chain
       0A47  ff.c:clmt_clust
       0AC0  ff.c:dir_sdi
       0BCA  ff.c:dir_next
       0D78  ff.c:dir_find
       0DBD  ff.c:dir_read
       0E08  ff.c:dir_register
       0E6B  ff.c:create_name
       0F73  ff.c:get_fileinfo
       1016  ff.c:follow_path
       109A  ff.c:check_fs
       1162  ff.c:chk_mounted
       165C  ff.c:validate
       1679  _f_mount
       16A4  _f_open
       1840  _f_read
       1AAB  _f_write
       1DC4  _f_sync
       1E75  _f_close
       1E85  _f_lseek
       2342  _f_opendir
       23B6  _f_readdir
       23FF  _delayus
       2407  _delayms
       241E  _initDevices
       2455  _timer1_init
       245D  _main
       24C4  _selfTest
       257D  _WriteFileHead
       25F9  _WriteSDFile
       265B  _ReadSDFile
       26C0  _findIndex
       2820  _check
       294E  _ftochr
       298F  _itochr
       299F  _StructToChar
       2A08  _CharToStruct
       2A48  _get_name
       2A87  _SquareRootFloat
       2B23  _debug
       2B40  _SD_Write_cmd
       2B72  _SD_Init
       2BD2  _SD_Write_Sector
       2C58  _SD_Read_Sector
       2CC6  _SD_Read_Sector_ndata
       2D4B  _GUI_mainmeu
       2E2F  _GUI_check
       2FDF  __GUI_datashow
       31F0  _GUI_get_date
       321E  _GUI_set_time
       3466  _GUI_readback
       3582  _GUI_welcome
       359F  _dateRefresh
       36EC  _uart1_init
       36FD  _uart1_rx_isr
       3706  _Usart_Transmit
       370D  _Puts
       3723  _Send_nByte
       3738  _PrintString
       3747  _PrintString_n
       375A  _PrintLong
       38A2  _PrintChar
       38C2  _SPI_IO_Init
       38CC  _SPI_Write
       38D0  _SPI_Read
       38D6  _LCD_SW
       38E0  _LCD_INT
       38E9  _address
       390A  _LCD_const_disp
       3937  _LCD_var_disp
       3964  _LCD_char_disp
       397E  _LCD_Init
       39B0  _LCD_CLR
       39D0  _W_1byte
       3A09  _Write_8bits
       3A2E  _Set_Draw
       3A3A  _Set_White
       3ACC  _set_white_n
       3B18  _clr_white
       3BA0  _LCD_print2num
       3BCC  _LCD_print4num
       3BF0  _LCD_print
       3C05  _LCD_print1
       3C0F  _lp
       3C77  _relay_init
       3C7A  _relay
       3C85  _beep
       3CAE  _Delay_nus
       3CBE  _reset_18B20
       3D2A  _write_bit_18B20
       3D72  _read_bit_18B20
       3DC5  _write_byte_18B20
       3DE6  _read_byte_18B20
       3E07  _convert_T
       3E0F  _read_T
       3E42  _read_T_NUM
       3E60  _ds1302_init
       3E65  _ds1302_write_byte
       3E87  _ds1302_read_byte
       3EAC  _ds1302_write_time
       3ED1  _ds1302_read_time
       3EF9  _kbscan
       3F3E  _memset
       3F49  _strcat
       3F56  _strlen
       3F62  push_arg4
       3F64  push_arg2
       3F67  asr32
       3F73  mod16s
       3F77  div16s
       3F91  mod16u
       3F93  div16u
       3F94  xdiv16u
       3FAD  div32u
       3FAF  mod32u
       3FB3  div32s
       3FB5  mod32s
       3FE1  long_div_prolog
       3FF4  long_div_epilog
       4004  tst_R16_R19
       4009  tst_R24_R27
       400E  neg_R24_R27
       4017  mod8u
       4019  div8u
       401A  xdiv8u
       402F  elpm32
       4043  empy16s
       4053  empy32u
       4053  empy32s
       4087  pop_xgset003C
       408C  pop_xgset00FC
       4093  pop_xgset30FC
       409C  pop_xgsetF0FC
       40A7  push_xgsetF0FC
       40A9  push_xgset30FC
       40AB  push_xgset00FC
       40AD  push_xgset003C
       40B2  push_xgset300C
       40B7  pop_xgset300C
       40BC  push_xgsetF000
       40C1  pop_xgsetF000
       40C6  push_xgsetF00C
       40CD  pop_xgsetF00C
       40D4  push_xgset303C
       40DB  pop_xgset303C
       40E2  push_xgsetF03C
       40EB  pop_xgsetF03C
       40F4  neg32
       40FD  long_prolog
       410B  long_epilog
       4116  tstzero1
       411C  tstzero2
       4122  lsl16
       4129  lsl32
       4135  lsl8
       413B  lsr16
       4142  lsr32
       414E  asgnblk
       4166  fpsub
       4168  fpadd
       4169  fpadd_alt
       41D0  fpadd2
       41DB  fpsub2
       41E6  fpsub1x
       41F3  fpsub2x
       4201  uint2fp
       4203  int2fp
       420C  ulong2fp
       420E  long2fp
       4225  fpdiv1
       422E  fpdiv2
       4238  fpdiv1x
       4244  fpdiv2x
       42BF  unpacks
       42C7  tstR16_R19
       42CF  unpacku
       42E8  normalize_and_pack
       431D  pack
       432D  saveFPRegs
       433C  restoreFPRegs
       434B  fpmule
       439E  fpmule1
       43A8  fpmule2
       43B3  fpmule1x
       43C0  fpcmp
       43CD  fpcmp2
       43D9  _itoa
       4444  _ltoa
       44FC  _ftoa
       468B  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0404 =   1028. bytes (rel,con,ram)

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
       04E0  lcd.c:p1
       04E2  lcd.c:p2
       04E4  lcd.c:p3
       04E6  lcd.c:p4
       04FB  _T_NUM
       04FC  _time_buf
       0504  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0504   02E7 =    743. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0504  __bss_start
       0504  ff.c:Fsid
       0506  ff.c:FatFs
       0508  _TempChar
       0558  _Result
       05B6  _buffer
       07B6  _t
       07C8  _config
       07EB  __bss_end

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

