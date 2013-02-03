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
                           idata   0252   04E1 =   1249. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0252  __idata_start
       0733  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0734   A3A8 =  41896. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       039A  __start
       039A  __text_start
       03BC  _exit
       03BD  _disk_initialize
       03D3  _disk_status
       03D9  _disk_read
       03F9  _disk_write
       0411  _disk_ioctl
       0416  _get_fattime
       041B  ff.c:mem_cpy
       0431  ff.c:mem_set
       0443  ff.c:mem_cmp
       0464  ff.c:chk_chr
       0474  ff.c:move_window
       0516  ff.c:sync
       05EB  _clust2sect
       063D  _get_fat
       078D  _put_fat
       094C  ff.c:remove_chain
       09FF  ff.c:create_chain
       0B77  ff.c:clmt_clust
       0BF0  ff.c:dir_sdi
       0CFA  ff.c:dir_next
       0EA8  ff.c:dir_find
       0EED  ff.c:dir_read
       0F38  ff.c:dir_register
       0F9B  ff.c:create_name
       10A3  ff.c:get_fileinfo
       1146  ff.c:follow_path
       11CA  ff.c:check_fs
       1292  ff.c:chk_mounted
       178C  ff.c:validate
       17A9  _f_mount
       17D4  _f_open
       1970  _f_read
       1BDB  _f_write
       1EF4  _f_sync
       1FA5  _f_close
       1FB5  _f_lseek
       2472  _f_opendir
       24E6  _f_readdir
       252F  _delayus
       2537  _delayms
       254E  _initDevices
       2586  _timer1_init
       258E  _main
       25F0  _heaterSwitch
       2647  _selfTest
       2724  _WriteFileHead
       278B  _WriteSDFile
       27ED  _ReadSDFile
       289F  _findIndex
       29F1  _Round
       2A60  _check
       2BCA  _StructToChar
       2C33  _CharToStruct
       2C78  _get_name
       2CB7  _SquareRootFloat
       2D53  _debug
       2D63  _SD_Write_cmd
       2D95  _SD_Init
       2DF5  _SD_Write_Sector
       2E7B  _SD_Read_Sector
       2EE9  _SD_Read_Sector_ndata
       2F6E  _GUI_mainmeu
       305F  _GUI_check
       32E8  __GUI_datashow
       34F4  _GUI_get_date
       3522  _GUI_set_time
       3775  _GUI_readback
       391A  _GUI_welcome
       3937  _dateRefresh
       3A80  _uart1_init
       3A91  _uart1_rx_isr
       3A9A  _Usart_Transmit
       3AA1  _Puts
       3AB7  _Send_nByte
       3ACC  _PrintString
       3ADB  _PrintString_n
       3AEE  _PrintLong
       3C36  _PrintChar
       3C56  _SPI_IO_Init
       3C60  _SPI_Write
       3C64  _SPI_Read
       3C6A  _LCD_SW
       3C74  _LCD_INT
       3C7D  _address
       3C9E  _LCD_const_disp
       3CCB  _LCD_var_disp
       3CF8  _LCD_char_disp
       3D12  _LCD_Init
       3D44  _LCD_CLR
       3D64  _W_1byte
       3D9D  _Write_8bits
       3DC2  _Set_Draw
       3DCE  _Set_White
       3E60  _set_white_n
       3EAC  _clr_white
       3F34  _LCD_print2num
       3F60  _LCD_print4num
       3F84  _LCD_print
       3F99  _LCD_print1
       3FA3  _lp
       400B  _relay_init
       400E  _relay
       401B  _beep
       4044  _Delay_nus
       4054  _reset_18B20
       40C0  _write_bit_18B20
       4108  _read_bit_18B20
       415B  _write_byte_18B20
       417C  _read_byte_18B20
       419D  _convert_T
       41A5  _read_T
       41D3  _read_T_NUM
       41F1  _readWithoutDelay
       420B  _ds1302_init
       4210  _ds1302_write_byte
       4232  _ds1302_read_byte
       4257  _ds1302_write_time
       427C  _ds1302_read_time
       42A4  _kbscan
       42ED  __print
       475A  _memset
       4765  _strcat
       4772  _strlen
       477E  push_arg4
       4780  push_arg2
       4783  asr32
       478F  mod16s
       4793  div16s
       47AD  mod16u
       47AF  div16u
       47B0  xdiv16u
       47C9  div32u
       47CB  mod32u
       47CF  div32s
       47D1  mod32s
       47FD  long_div_prolog
       4810  long_div_epilog
       4820  tst_R16_R19
       4825  tst_R24_R27
       482A  neg_R24_R27
       4833  mod8u
       4835  div8u
       4836  xdiv8u
       484B  elpm32
       485F  empy16s
       486F  empy32u
       486F  empy32s
       48A3  pop_xgset003C
       48A8  pop_xgset00FC
       48AF  pop_xgset30FC
       48B8  pop_xgsetF0FC
       48C3  push_xgsetF0FC
       48C5  push_xgset30FC
       48C7  push_xgset00FC
       48C9  push_xgset003C
       48CE  push_xgset300C
       48D3  pop_xgset300C
       48D8  push_xgsetF000
       48DD  pop_xgsetF000
       48E2  push_xgsetF00C
       48E9  pop_xgsetF00C
       48F0  push_xgset303C
       48F7  pop_xgset303C
       48FE  push_xgsetF03C
       4907  pop_xgsetF03C
       4910  xicallx
       4919  neg32
       4922  long_prolog
       4930  long_epilog
       493B  tstzero1
       4941  tstzero2
       4947  lsl16
       494E  lsl32
       495A  lsl8
       4960  lsr16
       4967  lsr32
       4973  asgnblk
       498B  fpsub
       498D  fpadd
       498E  fpadd_alt
       49F5  fpadd1
       49FF  fpadd2
       4A0A  fpsub1
       4A14  fpsub2
       4A1F  fpsub1x
       4A2C  fpsub2x
       4A3A  fpint
       4A6C  uint2fp
       4A6E  int2fp
       4A77  ulong2fp
       4A79  long2fp
       4A90  fpdiv1
       4A99  fpdiv2
       4AA3  fpdiv1x
       4AAF  fpdiv2x
       4B2A  unpacks
       4B32  tstR16_R19
       4B3A  unpacku
       4B53  normalize_and_pack
       4B88  pack
       4B98  saveFPRegs
       4BA7  restoreFPRegs
       4BB6  fpmule
       4C09  fpmule1
       4C13  fpmule2
       4C1E  fpmule1x
       4C2B  fpcmp
       4C38  fpcmp1
       4C43  fpcmp2
       4C4F  _cstrcpy
       4C59  _cstrlen
       4C66  _atoi
       4CAC  _itoa
       4D17  _ltoa
       4DCF  _ultoa
       4E36  _utoa
       4E76  _ftoa
       5005  _isdigit
       500F  _islower
       5019  _isspace
       5023  _toupper
       5036  __sdepi
       5040  _sprintf
       5084  __FormatFP_1
       556E  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   04E1 =   1249. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0127  main.c:last
       02A7  _labelH
       02B5  _labelM
       02C5  _labelL
       02D3  _H01
       02E3  _H02
       02EE  _H03
       0300  _M03
       030A  _M04
       0314  _L03
       0323  _H13
       0333  _M12
       0345  _M13
       0357  _L11
       0369  _L12
       037B  _M21
       038A  _str_blank
       039B  _GUI_date
       05BD  lcd.c:p1
       05BF  lcd.c:p2
       05C1  lcd.c:p3
       05C3  lcd.c:p4
       05D8  _T_NUM
       05D9  _time_buf
       05E1  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   05E1   0307 =    775. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       05E1  __bss_start
       05E1  ff.c:Fsid
       05E3  ff.c:FatFs
       05E5  main.c:indexoffset
       05E7  _TempChar
       0637  _Result
       0697  _buffer
       0897  _t
       08A9  _config
       08E8  __bss_end

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

