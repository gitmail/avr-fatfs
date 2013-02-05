NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   008C   0002 =      2. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __func_lit_start
       008E  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008E   01C4 =    452. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008E  __lit_start
       00E4  __ctype
       0252  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0252   04D8 =   1240. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0252  __idata_start
       072A  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   072A   A392 =  41874. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0395  __start
       0395  __text_start
       03B7  _exit
       03B8  _disk_initialize
       03CE  _disk_status
       03D4  _disk_read
       03F4  _disk_write
       040C  _disk_ioctl
       0411  _get_fattime
       0416  ff.c:mem_cpy
       042C  ff.c:mem_set
       043E  ff.c:mem_cmp
       045F  ff.c:chk_chr
       046F  ff.c:move_window
       0511  ff.c:sync
       05E6  _clust2sect
       0638  _get_fat
       0788  _put_fat
       0947  ff.c:remove_chain
       09FA  ff.c:create_chain
       0B72  ff.c:clmt_clust
       0BEB  ff.c:dir_sdi
       0CF5  ff.c:dir_next
       0EA3  ff.c:dir_find
       0EE8  ff.c:dir_read
       0F33  ff.c:dir_register
       0F96  ff.c:create_name
       109E  ff.c:get_fileinfo
       1141  ff.c:follow_path
       11C5  ff.c:check_fs
       128D  ff.c:chk_mounted
       1787  ff.c:validate
       17A4  _f_mount
       17CF  _f_open
       196B  _f_read
       1BD6  _f_write
       1EEF  _f_sync
       1FA0  _f_close
       1FB0  _f_lseek
       246D  _f_opendir
       24E1  _f_readdir
       252A  _delayus
       2532  _delayms
       2549  _initDevices
       2581  _timer1_init
       2589  _main
       25EB  _heaterSwitch
       262D  _selfTest
       270A  _WriteFileHead
       2771  _WriteSDFile
       27D3  _ReadSDFile
       2885  _findIndex
       29D7  _Round
       2A46  _check
       2BB0  _StructToChar
       2C19  _CharToStruct
       2C5E  _get_name
       2C9D  _SquareRootFloat
       2D39  _debug
       2D49  _SD_Write_cmd
       2D7B  _SD_Init
       2DDB  _SD_Write_Sector
       2E61  _SD_Read_Sector
       2ECF  _SD_Read_Sector_ndata
       2F54  _GUI_mainmeu
       3045  _GUI_check
       32D8  __GUI_datashow
       34E4  _GUI_get_date
       3512  _GUI_set_time
       3765  _GUI_readback
       390A  _GUI_welcome
       3927  _dateRefresh
       3A70  _uart1_init
       3A81  _uart1_rx_isr
       3A8A  _Usart_Transmit
       3A91  _Puts
       3AA7  _Send_nByte
       3ABC  _PrintString
       3ACB  _PrintString_n
       3ADE  _PrintLong
       3C26  _PrintChar
       3C46  _SPI_IO_Init
       3C50  _SPI_Write
       3C54  _SPI_Read
       3C5A  _LCD_SW
       3C64  _LCD_INT
       3C6D  _address
       3C8E  _LCD_const_disp
       3CBB  _LCD_var_disp
       3CE8  _LCD_char_disp
       3D02  _LCD_Init
       3D34  _LCD_CLR
       3D54  _W_1byte
       3D8D  _Write_8bits
       3DB2  _Set_Draw
       3DBE  _Set_White
       3E50  _set_white_n
       3E9C  _clr_white
       3F24  _LCD_print2num
       3F50  _LCD_print4num
       3F74  _LCD_print
       3F89  _LCD_print1
       3F93  _lp
       3FFB  _relay_init
       3FFE  _relay
       400B  _beep
       4034  _Delay_nus
       4044  _reset_18B20
       40B0  _write_bit_18B20
       40F8  _read_bit_18B20
       414B  _write_byte_18B20
       416C  _read_byte_18B20
       418D  _convert_T
       4195  _read_T
       41C3  _read_T_NUM
       41E1  _readWithoutDelay
       41FB  _ds1302_init
       4200  _ds1302_write_byte
       4222  _ds1302_read_byte
       4247  _ds1302_write_time
       426C  _ds1302_read_time
       4294  _kbscan
       42DD  __print
       474A  _memset
       4755  _strcat
       4762  _strlen
       476E  push_arg4
       4770  push_arg2
       4773  asr32
       477F  mod16s
       4783  div16s
       479D  mod16u
       479F  div16u
       47A0  xdiv16u
       47B9  div32u
       47BB  mod32u
       47BF  div32s
       47C1  mod32s
       47ED  long_div_prolog
       4800  long_div_epilog
       4810  tst_R16_R19
       4815  tst_R24_R27
       481A  neg_R24_R27
       4823  mod8u
       4825  div8u
       4826  xdiv8u
       483B  elpm32
       484F  empy16s
       485F  empy32u
       485F  empy32s
       4893  pop_xgset003C
       4898  pop_xgset00FC
       489F  pop_xgset30FC
       48A8  pop_xgsetF0FC
       48B3  push_xgsetF0FC
       48B5  push_xgset30FC
       48B7  push_xgset00FC
       48B9  push_xgset003C
       48BE  push_xgset300C
       48C3  pop_xgset300C
       48C8  push_xgsetF000
       48CD  pop_xgsetF000
       48D2  push_xgsetF00C
       48D9  pop_xgsetF00C
       48E0  push_xgset303C
       48E7  pop_xgset303C
       48EE  push_xgsetF03C
       48F7  pop_xgsetF03C
       4900  xicallx
       4909  neg32
       4912  long_prolog
       4920  long_epilog
       492B  tstzero1
       4931  tstzero2
       4937  lsl16
       493E  lsl32
       494A  lsl8
       4950  lsr16
       4957  lsr32
       4963  asgnblk
       497B  fpsub
       497D  fpadd
       497E  fpadd_alt
       49E5  fpadd1
       49EF  fpadd2
       49FA  fpsub1
       4A04  fpsub2
       4A0F  fpsub1x
       4A1C  fpsub2x
       4A2A  fpint
       4A5C  uint2fp
       4A5E  int2fp
       4A67  ulong2fp
       4A69  long2fp
       4A80  fpdiv1
       4A89  fpdiv2
       4A93  fpdiv1x
       4A9F  fpdiv2x
       4B1A  unpacks
       4B22  tstR16_R19
       4B2A  unpacku
       4B43  normalize_and_pack
       4B78  pack
       4B88  saveFPRegs
       4B97  restoreFPRegs
       4BA6  fpmule
       4BF9  fpmule1
       4C03  fpmule2
       4C0E  fpmule1x
       4C1B  fpcmp
       4C28  fpcmp1
       4C33  fpcmp2
       4C3F  _cstrcpy
       4C49  _cstrlen
       4C56  _atoi
       4C9C  _itoa
       4D07  _ltoa
       4DBF  _ultoa
       4E26  _utoa
       4E66  _ftoa
       4FF5  _isdigit
       4FFF  _islower
       5009  _isspace
       5013  _toupper
       5026  __sdepi
       5030  _sprintf
       5074  __FormatFP_1
       555E  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   04D8 =   1240. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0127  main.c:last
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
       05B4  lcd.c:p1
       05B6  lcd.c:p2
       05B8  lcd.c:p3
       05BA  lcd.c:p4
       05CF  _T_NUM
       05D0  _time_buf
       05D8  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   05D8   0307 =    775. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       05D8  __bss_start
       05D8  ff.c:Fsid
       05DA  ff.c:FatFs
       05DC  main.c:indexoffset
       05DE  _TempChar
       062E  _Result
       068E  _buffer
       088E  _t
       08A0  _config
       08DF  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\PROGRA~1\icc\lib\crtatmega.o	[ crtatmega.s ]
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

