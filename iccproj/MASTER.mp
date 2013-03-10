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
                           idata   0252   04E7 =   1255. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0252  __idata_start
       0739  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   073A   A82A =  43050. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       039D  __text_start
       039D  __start
       03BF  _exit
       03C0  _disk_initialize
       03D6  _disk_status
       03DC  _disk_read
       03FC  _disk_write
       0414  _disk_ioctl
       0419  _get_fattime
       041E  ff.c:mem_cpy
       0434  ff.c:mem_set
       0446  ff.c:mem_cmp
       0467  ff.c:chk_chr
       0477  ff.c:move_window
       0519  ff.c:sync
       05EE  _clust2sect
       0640  _get_fat
       0790  _put_fat
       094F  ff.c:remove_chain
       0A02  ff.c:create_chain
       0B7A  ff.c:clmt_clust
       0BF3  ff.c:dir_sdi
       0CFD  ff.c:dir_next
       0EAB  ff.c:dir_find
       0EF0  ff.c:dir_read
       0F3B  ff.c:dir_register
       0F9E  ff.c:create_name
       10A6  ff.c:get_fileinfo
       1149  ff.c:follow_path
       11CD  ff.c:check_fs
       1295  ff.c:chk_mounted
       178F  ff.c:validate
       17AC  _f_mount
       17D7  _f_open
       1973  _f_read
       1BDE  _f_write
       1EF7  _f_sync
       1FA8  _f_close
       1FB8  _f_lseek
       2475  _f_opendir
       24E9  _f_readdir
       2532  _delayus
       253A  _delayms
       2551  _initDevices
       258B  _timer1_init
       2593  _main
       25F7  _alwaysCheck
       263D  _selfTest
       271E  _WriteFileHead
       2785  _WriteSDFile
       27E7  _ReadSDFile
       2899  _findIndex
       29EB  _Round
       2A5A  _check
       2BC4  _StructToChar
       2C2D  _CharToStruct
       2C72  _get_name
       2CB1  _SquareRootFloat
       2D4D  _debug
       2D5D  _SD_Write_cmd
       2D8F  _SD_Init
       2DEF  _SD_Write_Sector
       2E75  _SD_Read_Sector
       2EE3  _SD_Read_Sector_ndata
       2F68  _GUI_mainmeu
       305D  _GUI_check
       32FF  __GUI_datashow
       350B  _GUI_get_date
       3539  _GUI_set_time
       378E  _GUI_readback
       3939  _GUI_welcome
       3956  _dateRefresh
       3A9F  _zigbee_init
       3AA7  _RecAdd
       3AC3  _RecRemove
       3AFF  _RecRead
       3B1D  _CheckCRC
       3B22  _RecDeal
       3C00  _Send_string
       3C5C  _zigbee_send_date
       3C99  _uart1_init
       3CAA  _uart1_rx_isr
       3CDE  _Usart_Transmit
       3CE5  _Puts
       3CFB  _Send_nByte
       3D10  _PrintString
       3D1F  _PrintString_n
       3D32  _PrintLong
       3E7A  _PrintChar
       3E9A  _SPI_IO_Init
       3EA4  _SPI_Write
       3EA8  _SPI_Read
       3EAE  _LCD_SW
       3EB8  _LCD_INT
       3EC1  _address
       3EE2  _LCD_const_disp
       3F0F  _LCD_var_disp
       3F3C  _LCD_char_disp
       3F56  _LCD_Init
       3F88  _LCD_CLR
       3FA8  _W_1byte
       3FE1  _Write_8bits
       4006  _Set_Draw
       4012  _Set_White
       40A4  _set_white_n
       40F0  _clr_white
       4178  _LCD_print2num
       41A4  _LCD_print4num
       41C8  _LCD_print
       41DD  _LCD_print1
       41E7  _lp
       424F  _relay_init
       4252  _relay
       425F  _beep
       4288  _Delay_nus
       4298  _reset_18B20
       4304  _write_bit_18B20
       434C  _read_bit_18B20
       439F  _write_byte_18B20
       43C0  _read_byte_18B20
       43E1  _convert_T
       43E9  _read_T
       4417  _read_T_NUM
       4435  _readWithoutDelay
       444F  _ds1302_init
       4454  _ds1302_write_byte
       4476  _ds1302_read_byte
       449B  _ds1302_write_time
       44C0  _ds1302_read_time
       44E8  _kbscan
       4531  __print
       499E  _memset
       49A9  _strcat
       49B6  _strlen
       49C2  push_arg4
       49C4  push_arg2
       49C7  asr32
       49D3  mod16s
       49D7  div16s
       49F1  mod16u
       49F3  div16u
       49F4  xdiv16u
       4A0D  div32u
       4A0F  mod32u
       4A13  div32s
       4A15  mod32s
       4A41  long_div_prolog
       4A54  long_div_epilog
       4A64  tst_R16_R19
       4A69  tst_R24_R27
       4A6E  neg_R24_R27
       4A77  mod8u
       4A79  div8u
       4A7A  xdiv8u
       4A8F  elpm32
       4AA3  empy16s
       4AB3  empy32s
       4AB3  empy32u
       4AE7  pop_xgset003C
       4AEC  pop_xgset00FC
       4AF3  pop_xgset30FC
       4AFC  pop_xgsetF0FC
       4B07  push_xgsetF0FC
       4B09  push_xgset30FC
       4B0B  push_xgset00FC
       4B0D  push_xgset003C
       4B12  push_xgset300C
       4B17  pop_xgset300C
       4B1C  push_xgsetF000
       4B21  pop_xgsetF000
       4B26  push_xgsetF00C
       4B2D  pop_xgsetF00C
       4B34  push_xgset303C
       4B3B  pop_xgset303C
       4B42  push_xgsetF03C
       4B4B  pop_xgsetF03C
       4B54  xicallx
       4B5D  neg32
       4B66  long_prolog
       4B74  long_epilog
       4B7F  tstzero1
       4B85  tstzero2
       4B8B  lsl16
       4B92  lsl32
       4B9E  lsl8
       4BA4  lsr16
       4BAB  lsr32
       4BB7  asgnblk
       4BCF  fpsub
       4BD1  fpadd
       4BD2  fpadd_alt
       4C39  fpadd1
       4C43  fpadd2
       4C4E  fpsub1
       4C58  fpsub2
       4C63  fpsub1x
       4C70  fpsub2x
       4C7E  fpint
       4CB0  uint2fp
       4CB2  int2fp
       4CBB  ulong2fp
       4CBD  long2fp
       4CD4  fpdiv1
       4CDD  fpdiv2
       4CE7  fpdiv1x
       4CF3  fpdiv2x
       4D6E  unpacks
       4D76  tstR16_R19
       4D7E  unpacku
       4D97  normalize_and_pack
       4DCC  pack
       4DDC  saveFPRegs
       4DEB  restoreFPRegs
       4DFA  fpmule
       4E4D  fpmule1
       4E57  fpmule2
       4E62  fpmule1x
       4E6F  fpcmp
       4E7C  fpcmp1
       4E87  fpcmp2
       4E93  _cstrcpy
       4E9D  _cstrlen
       4EAA  _atoi
       4EF0  _itoa
       4F5B  _ltoa
       5013  _ultoa
       507A  _utoa
       50BA  _ftoa
       5249  _isdigit
       5253  _islower
       525D  _isspace
       5267  _toupper
       527A  __sdepi
       5284  _sprintf
       52C8  __FormatFP_1
       57B2  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   04E7 =   1255. bytes (rel,con,ram)

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
       05E7  ff.c:Fsid
       05E9  ff.c:FatFs
       05EB  main.c:indexoffset
       05ED  _TempChar
       063D  _Result
       069D  _buffer
       089D  _t
       08AF  _config
       08C5  _Rec
       094C  __bss_end

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

