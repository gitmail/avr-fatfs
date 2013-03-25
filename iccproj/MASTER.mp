NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   008C   0020 =     32. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __func_lit_start
       00AC  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   00AC   01C4 =    452. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00AC  __lit_start
       0102  __ctype
       0270  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0270   04E7 =   1255. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0270  __idata_start
       0757  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0758   A838 =  43064. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       03AC  __text_start
       03AC  __start
       03CE  _exit
       03CF  _initDevices
       040B  _timer1_init
       0413  _main
       0477  _alwaysCheck
       04BF  _selfTest
       059C  _WriteFileHead
       0603  _WriteSDFile
       0665  _ReadSDFile
       0717  _findIndex
       0869  _Round
       08D8  _check
       0A42  _StructToChar
       0AAB  _CharToStruct
       0AF0  _get_name
       0B2F  _SquareRootFloat
       0BCB  _debug
       0BDB  _disk_initialize
       0BF1  _disk_status
       0BF7  _disk_read
       0C17  _disk_write
       0C2F  _disk_ioctl
       0C34  _get_fattime
       0C39  ff.c:mem_cpy
       0C4F  ff.c:mem_set
       0C61  ff.c:mem_cmp
       0C82  ff.c:chk_chr
       0C92  ff.c:move_window
       0D34  ff.c:sync
       0E09  _clust2sect
       0E5B  _get_fat
       0FAB  _put_fat
       116A  ff.c:remove_chain
       121D  ff.c:create_chain
       1395  ff.c:clmt_clust
       140E  ff.c:dir_sdi
       1518  ff.c:dir_next
       16C6  ff.c:dir_find
       170B  ff.c:dir_read
       1756  ff.c:dir_register
       17B9  ff.c:create_name
       18C1  ff.c:get_fileinfo
       1964  ff.c:follow_path
       19E8  ff.c:check_fs
       1AB0  ff.c:chk_mounted
       1FAA  ff.c:validate
       1FC7  _f_mount
       1FF2  _f_open
       218E  _f_read
       23F9  _f_write
       2712  _f_sync
       27C3  _f_close
       27D3  _f_lseek
       2C90  _f_opendir
       2D04  _f_readdir
       2D4D  _delayus
       2D55  _delayms
       2D6C  _SD_Write_cmd
       2D9E  _SD_Init
       2DFE  _SD_Write_Sector
       2E84  _SD_Read_Sector
       2EF2  _SD_Read_Sector_ndata
       2F77  _GUI_mainmeu
       306C  _GUI_check
       330E  __GUI_datashow
       351A  _GUI_get_date
       3548  _GUI_set_time
       379D  _GUI_readback
       3948  _GUI_welcome
       3965  _dateRefresh
       3AAE  _zigbee_init
       3AB6  _RecAdd
       3AD2  _RecRemove
       3B0E  _RecRead
       3B2C  _CheckCRC
       3B31  _RecDeal
       3C04  _Send_string
       3C60  _zigbee_send_date
       3CA6  _zigbee_send_id
       3CAF  _uart1_init
       3CC0  _uart1_rx_isr
       3CF4  _Usart_Transmit
       3CFB  _Puts
       3D11  _Send_nByte
       3D26  _PrintString
       3D35  _PrintString_n
       3D48  _PrintLong
       3E90  _PrintChar
       3EB0  _SPI_IO_Init
       3EBA  _SPI_Write
       3EBE  _SPI_Read
       3EC4  _LCD_SW
       3ECE  _LCD_INT
       3ED7  _address
       3EF8  _LCD_const_disp
       3F25  _LCD_var_disp
       3F52  _LCD_char_disp
       3F6C  _LCD_Init
       3F9E  _LCD_CLR
       3FBE  _W_1byte
       3FF7  _Write_8bits
       401C  _Set_Draw
       4028  _Set_White
       40BA  _set_white_n
       4106  _clr_white
       418E  _LCD_print2num
       41BA  _LCD_print4num
       41DE  _LCD_print
       41F3  _LCD_print1
       41FD  _lp
       4265  _relay_init
       4268  _relay
       4275  _beep
       429E  _Delay_nus
       42AE  _reset_18B20
       431A  _write_bit_18B20
       4362  _read_bit_18B20
       43B5  _write_byte_18B20
       43D6  _read_byte_18B20
       43F7  _convert_T
       43FF  _read_T
       442D  _read_T_NUM
       444B  _readWithoutDelay
       4465  _ds1302_init
       446A  _ds1302_write_byte
       448C  _ds1302_read_byte
       44B1  _ds1302_write_time
       44D6  _ds1302_read_time
       44FE  _kbscan
       4547  __print
       49B4  _memset
       49BF  _strcat
       49CC  _strlen
       49D8  push_arg4
       49DA  push_arg2
       49DD  asr32
       49E9  mod16s
       49ED  div16s
       4A07  mod16u
       4A09  div16u
       4A0A  xdiv16u
       4A23  div32u
       4A25  mod32u
       4A29  div32s
       4A2B  mod32s
       4A57  long_div_prolog
       4A6A  long_div_epilog
       4A7A  tst_R16_R19
       4A7F  tst_R24_R27
       4A84  neg_R24_R27
       4A8D  mod8u
       4A8F  div8u
       4A90  xdiv8u
       4AA5  elpm32
       4AB9  empy16s
       4AC9  empy32s
       4AC9  empy32u
       4AFD  pop_xgset003C
       4B02  pop_xgset00FC
       4B09  pop_xgset30FC
       4B12  pop_xgsetF0FC
       4B1D  push_xgsetF0FC
       4B1F  push_xgset30FC
       4B21  push_xgset00FC
       4B23  push_xgset003C
       4B28  push_xgset300C
       4B2D  pop_xgset300C
       4B32  push_xgsetF000
       4B37  pop_xgsetF000
       4B3C  push_xgsetF00C
       4B43  pop_xgsetF00C
       4B4A  push_xgset303C
       4B51  pop_xgset303C
       4B58  push_xgsetF03C
       4B61  pop_xgsetF03C
       4B6A  xicallx
       4B73  neg32
       4B7C  long_prolog
       4B8A  long_epilog
       4B95  tstzero1
       4B9B  tstzero2
       4BA1  lsl16
       4BA8  lsl32
       4BB4  lsl8
       4BBA  lsr16
       4BC1  lsr32
       4BCD  asgnblk
       4BE5  fpsub
       4BE7  fpadd
       4BE8  fpadd_alt
       4C4F  fpadd1
       4C59  fpadd2
       4C64  fpsub1
       4C6E  fpsub2
       4C79  fpsub1x
       4C86  fpsub2x
       4C94  fpint
       4CC6  uint2fp
       4CC8  int2fp
       4CD1  ulong2fp
       4CD3  long2fp
       4CEA  fpdiv1
       4CF3  fpdiv2
       4CFD  fpdiv1x
       4D09  fpdiv2x
       4D84  unpacks
       4D8C  tstR16_R19
       4D94  unpacku
       4DAD  normalize_and_pack
       4DE2  pack
       4DF2  saveFPRegs
       4E01  restoreFPRegs
       4E10  fpmule
       4E63  fpmule1
       4E6D  fpmule2
       4E78  fpmule1x
       4E85  fpcmp
       4E92  fpcmp1
       4E9D  fpcmp2
       4EA9  _cstrcpy
       4EB3  _cstrlen
       4EC0  _atoi
       4F06  _itoa
       4F71  _ltoa
       5029  _ultoa
       5090  _utoa
       50D0  _ftoa
       525F  _isdigit
       5269  _islower
       5273  _isspace
       527D  _toupper
       5290  __sdepi
       529A  _sprintf
       52DE  __FormatFP_1
       57C8  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   04E7 =   1255. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _tab
       0100  __data_start
       0103  _enter
       0106  _now
       0118  main.c:last
       029E  _labelH
       02AC  _labelM
       02BC  _labelL
       02CA  _H01
       02DA  _H02
       02E5  _H03
       02F7  _M03
       0301  _M04
       030B  _L03
       031A  _H13
       032A  _M12
       033C  _M13
       034E  _L11
       0360  _L12
       0372  _M21
       0381  _str_blank
       0392  _GUI_date
       05B4  _CommonId
       05B5  _devicename
       05BD  _deviceId
       05C3  lcd.c:p1
       05C5  lcd.c:p2
       05C7  lcd.c:p3
       05C9  lcd.c:p4
       05DE  _T_NUM
       05DF  _time_buf
       05E7  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   05E7   0365 =    869. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       05E7  __bss_start
       05E7  main.c:indexoffset
       05E9  _TempChar
       0639  _Result
       0699  _buffer
       0899  _t
       08AB  _config
       08C1  ff.c:Fsid
       08C3  ff.c:FatFs
       08C5  _Rec
       094C  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\PROGRA~1\icc\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
diskio.o	[ diskio.c ]
ff.o	[ ff.c ]
delay.o	[ delay.c ]
sd.o	[ sd.c ]
gui.o	[ gui.c ]
zigbee.o	[ zigbee.c ]
usart.o	[ usart.c ]
SPI.o	[ SPI.c ]
lcd.o	[ lcd.c ]
relay.o	[ relay.c ]
beep.o	[ beep.c ]
DS18B20_driver.o	[ DS18B20_driver.c ]
ds1302.o	[ ds1302.c ]
key.o	[ key.c ]
<library>	[ _printf.s, memset.s, strcat.s, strlen.s, asave.s, asr32.s, div16s.s, div16u.s, div32.s, div8u.s, elpm32.s ]
[ emul16s.s, emul32.s, gpop2.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s ]
[ gpushb.s, icallx.s, lneg.s, longutil.s, lsl16.s, lsl32.s, lsl8.s, lsr16.s, lsr32.s, struct.s, fpadd.s ]
[ fpadd1.s, fpadd2.s, fpsub1.s, fpsub2.s, fpsub1x.s, fpsub2x.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s ]
[ fpmule.s, fpmule1.s, fpmule2.s, fpmule1x.s, fpcmp.s, fpcmp1.s, fpcmp2.s, cstrcpy.s, cstrlen.s, atoi.s ]
[ itoa.s, ltoa.s, ultoa.s, utoa.s, ftoa.s, isdigit.s, islower.s, isspace.s, ctype.s, toupper.s, sprintf.s ]
[ formatfp1.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x100

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

