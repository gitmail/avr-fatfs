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
                           idata   00D0   040B =   1035. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04DB  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04DC   890E =  35086. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       026E  __start
       026E  __text_start
       0290  _exit
       0291  _disk_initialize
       02A7  _disk_status
       02AD  _disk_read
       02CD  _disk_write
       02E5  _disk_ioctl
       02EA  _get_fattime
       02EF  ff.c:mem_cpy
       0305  ff.c:mem_set
       0317  ff.c:mem_cmp
       0338  ff.c:chk_chr
       0348  ff.c:move_window
       03EA  ff.c:sync
       04BF  _clust2sect
       0511  _get_fat
       0661  _put_fat
       0820  ff.c:remove_chain
       08D3  ff.c:create_chain
       0A4B  ff.c:clmt_clust
       0AC4  ff.c:dir_sdi
       0BCE  ff.c:dir_next
       0D7C  ff.c:dir_find
       0DC1  ff.c:dir_read
       0E0C  ff.c:dir_register
       0E6F  ff.c:create_name
       0F77  ff.c:get_fileinfo
       101A  ff.c:follow_path
       109E  ff.c:check_fs
       1166  ff.c:chk_mounted
       1660  ff.c:validate
       167D  _f_mount
       16A8  _f_open
       1844  _f_read
       1AAF  _f_write
       1DC8  _f_sync
       1E79  _f_close
       1E89  _f_lseek
       2346  _f_opendir
       23BA  _f_readdir
       2403  _delayus
       240B  _delayms
       2422  _initDevices
       2457  _timer1_init
       245F  _main
       24C0  _selfTest
       2579  _WriteFileHead
       25F5  _WriteSDFile
       2657  _ReadSDFile
       26BC  _findIndex
       281C  _check
       294A  _ftochr
       298B  _itochr
       299B  _StructToChar
       2A04  _CharToStruct
       2A44  _get_name
       2A83  _SquareRootFloat
       2B1F  _debug
       2B3C  _SD_Write_cmd
       2B6E  _SD_Init
       2BCE  _SD_Write_Sector
       2C54  _SD_Read_Sector
       2CC2  _SD_Read_Sector_ndata
       2D47  _GUI_mainmeu
       2E2C  _GUI_check
       303A  __GUI_datashow
       3246  _GUI_get_date
       3274  _GUI_set_time
       34BC  _GUI_readback
       35D9  _GUI_welcome
       35F6  _dateRefresh
       3756  _uart1_init
       3767  _uart1_rx_isr
       3770  _Usart_Transmit
       3777  _Puts
       378D  _Send_nByte
       37A2  _PrintString
       37B1  _PrintString_n
       37C4  _PrintLong
       390C  _PrintChar
       392C  _SPI_IO_Init
       3936  _SPI_Write
       393A  _SPI_Read
       3940  _LCD_SW
       394A  _LCD_INT
       3953  _address
       3974  _LCD_const_disp
       39A1  _LCD_var_disp
       39CE  _LCD_char_disp
       39E8  _LCD_Init
       3A1A  _LCD_CLR
       3A3A  _W_1byte
       3A73  _Write_8bits
       3A98  _Set_Draw
       3AA4  _Set_White
       3B36  _set_white_n
       3B82  _clr_white
       3C0A  _LCD_print2num
       3C36  _LCD_print4num
       3C5A  _LCD_print
       3C6F  _LCD_print1
       3C79  _lp
       3CE1  _relay_init
       3CE4  _relay
       3CEF  _beep
       3D18  _Delay_nus
       3D28  _reset_18B20
       3D94  _write_bit_18B20
       3DDC  _read_bit_18B20
       3E2F  _write_byte_18B20
       3E50  _read_byte_18B20
       3E71  _convert_T
       3E79  _read_T
       3EAC  _read_T_NUM
       3ECA  _ds1302_init
       3ECF  _ds1302_write_byte
       3EF1  _ds1302_read_byte
       3F16  _ds1302_write_time
       3F3B  _ds1302_read_time
       3F63  _kbscan
       3FA8  _memset
       3FB3  _strcat
       3FC0  _strlen
       3FCC  push_arg4
       3FCE  push_arg2
       3FD1  asr32
       3FDD  mod16s
       3FE1  div16s
       3FFB  mod16u
       3FFD  div16u
       3FFE  xdiv16u
       4017  div32u
       4019  mod32u
       401D  div32s
       401F  mod32s
       404B  long_div_prolog
       405E  long_div_epilog
       406E  tst_R16_R19
       4073  tst_R24_R27
       4078  neg_R24_R27
       4081  mod8u
       4083  div8u
       4084  xdiv8u
       4099  elpm32
       40AD  empy16s
       40BD  empy32u
       40BD  empy32s
       40F1  pop_xgset003C
       40F6  pop_xgset00FC
       40FD  pop_xgset30FC
       4106  pop_xgsetF0FC
       4111  push_xgsetF0FC
       4113  push_xgset30FC
       4115  push_xgset00FC
       4117  push_xgset003C
       411C  push_xgset300C
       4121  pop_xgset300C
       4126  push_xgsetF000
       412B  pop_xgsetF000
       4130  push_xgsetF00C
       4137  pop_xgsetF00C
       413E  push_xgset303C
       4145  pop_xgset303C
       414C  push_xgsetF03C
       4155  pop_xgsetF03C
       415E  neg32
       4167  long_prolog
       4175  long_epilog
       4180  tstzero1
       4186  tstzero2
       418C  lsl16
       4193  lsl32
       419F  lsl8
       41A5  lsr16
       41AC  lsr32
       41B8  asgnblk
       41D0  fpsub
       41D2  fpadd
       41D3  fpadd_alt
       423A  fpadd2
       4245  fpsub2
       4250  fpsub1x
       425D  fpsub2x
       426B  uint2fp
       426D  int2fp
       4276  ulong2fp
       4278  long2fp
       428F  fpdiv1
       4298  fpdiv2
       42A2  fpdiv1x
       42AE  fpdiv2x
       4329  unpacks
       4331  tstR16_R19
       4339  unpacku
       4352  normalize_and_pack
       4387  pack
       4397  saveFPRegs
       43A6  restoreFPRegs
       43B5  fpmule
       4408  fpmule1
       4412  fpmule2
       441D  fpmule1x
       442A  fpcmp
       4437  fpcmp2
       4443  _itoa
       44AE  _ltoa
       4566  _ftoa
       46F5  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   040B =   1035. bytes (rel,con,ram)

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
       04E7  lcd.c:p1
       04E9  lcd.c:p2
       04EB  lcd.c:p3
       04ED  lcd.c:p4
       0502  _T_NUM
       0503  _time_buf
       050B  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   050B   02E7 =    743. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       050B  __bss_start
       050B  ff.c:Fsid
       050D  ff.c:FatFs
       050F  _TempChar
       055F  _Result
       05BD  _buffer
       07BD  _t
       07CF  _config
       07F2  __bss_end

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

