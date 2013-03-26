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
                           idata   0270   0519 =   1305. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0270  __idata_start
       0789  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   078A   A922 =  43298. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       03C5  __text_start
       03C5  __start
       03E7  _exit
       03E8  _initDevices
       0426  _timer1_init
       042E  _main
       0492  _alwaysCheck
       04DA  _selfTest
       05B7  _WriteFileHead
       061E  _WriteSDFile
       0680  _ReadSDFile
       0732  _findIndex
       0884  _Round
       08F3  _check
       0A5D  _StructToChar
       0AC6  _CharToStruct
       0B0B  _get_name
       0B4A  _SquareRootFloat
       0BE6  _debug
       0BF6  _disk_initialize
       0C0C  _disk_status
       0C12  _disk_read
       0C32  _disk_write
       0C4A  _disk_ioctl
       0C4F  _get_fattime
       0C54  ff.c:mem_cpy
       0C6A  ff.c:mem_set
       0C7C  ff.c:mem_cmp
       0C9D  ff.c:chk_chr
       0CAD  ff.c:move_window
       0D4F  ff.c:sync
       0E24  _clust2sect
       0E76  _get_fat
       0FC6  _put_fat
       1185  ff.c:remove_chain
       1238  ff.c:create_chain
       13B0  ff.c:clmt_clust
       1429  ff.c:dir_sdi
       1533  ff.c:dir_next
       16E1  ff.c:dir_find
       1726  ff.c:dir_read
       1771  ff.c:dir_register
       17D4  ff.c:create_name
       18DC  ff.c:get_fileinfo
       197F  ff.c:follow_path
       1A03  ff.c:check_fs
       1ACB  ff.c:chk_mounted
       1FC5  ff.c:validate
       1FE2  _f_mount
       200D  _f_open
       21A9  _f_read
       2414  _f_write
       272D  _f_sync
       27DE  _f_close
       27EE  _f_lseek
       2CAB  _f_opendir
       2D1F  _f_readdir
       2D68  _delayus
       2D70  _delayms
       2D87  _SD_Write_cmd
       2DB9  _SD_Init
       2E19  _SD_Write_Sector
       2E9F  _SD_Read_Sector
       2F0D  _SD_Read_Sector_ndata
       2F92  _GUI_mainmeu
       308F  _GUI_check
       3390  __GUI_datashow
       359C  _GUI_get_date
       35CA  _GUI_set_time
       381F  _GUI_readback
       39CA  _GUI_welcome
       39E7  _dateRefresh
       3B30  _zigbee_init
       3B38  _RecAdd
       3B54  _RecRemove
       3B90  _RecRead
       3BAE  _CheckCRC
       3BB3  _RecDeal
       3C92  _Send_string
       3CEE  _zigbee_send_date
       3D34  _zigbee_send_id
       3D3D  _uart1_init
       3D4E  _uart1_rx_isr
       3D82  _Usart_Transmit
       3D89  _Puts
       3D9F  _Send_nByte
       3DB4  _PrintString
       3DC3  _PrintString_n
       3DD6  _PrintLong
       3F1E  _PrintChar
       3F3E  _SPI_IO_Init
       3F48  _SPI_Write
       3F4C  _SPI_Read
       3F52  _LCD_SW
       3F5C  _LCD_INT
       3F65  _address
       3F86  _LCD_const_disp
       3FB3  _LCD_var_disp
       3FE0  _LCD_char_disp
       3FFA  _LCD_Init
       402C  _LCD_CLR
       404C  _W_1byte
       4085  _Write_8bits
       40AA  _Set_Draw
       40B6  _Set_White
       4148  _set_white_n
       4194  _clr_white
       421C  _LCD_print2num
       4248  _LCD_print4num
       426C  _LCD_print
       4281  _LCD_print1
       428B  _lp
       42F3  _relay_init
       42F6  _relay
       4303  _beep
       432C  _Delay_nus
       433C  _reset_18B20
       43A8  _write_bit_18B20
       43F0  _read_bit_18B20
       4443  _write_byte_18B20
       4464  _read_byte_18B20
       4485  _convert_T
       448D  _read_T
       44BB  _read_T_NUM
       44D9  _readWithoutDelay
       44F3  _ds1302_init
       44F8  _ds1302_write_byte
       451A  _ds1302_read_byte
       453F  _ds1302_write_time
       4564  _ds1302_read_time
       458C  _kbscan
       45D5  __print
       4A42  _memset
       4A4D  _strcat
       4A5A  _strlen
       4A66  push_arg4
       4A68  push_arg2
       4A6B  asr32
       4A77  mod16s
       4A7B  div16s
       4A95  mod16u
       4A97  div16u
       4A98  xdiv16u
       4AB1  div32u
       4AB3  mod32u
       4AB7  div32s
       4AB9  mod32s
       4AE5  long_div_prolog
       4AF8  long_div_epilog
       4B08  tst_R16_R19
       4B0D  tst_R24_R27
       4B12  neg_R24_R27
       4B1B  mod8u
       4B1D  div8u
       4B1E  xdiv8u
       4B33  elpm32
       4B47  empy16s
       4B57  empy32s
       4B57  empy32u
       4B8B  pop_xgset003C
       4B90  pop_xgset00FC
       4B97  pop_xgset30FC
       4BA0  pop_xgsetF0FC
       4BAB  push_xgsetF0FC
       4BAD  push_xgset30FC
       4BAF  push_xgset00FC
       4BB1  push_xgset003C
       4BB6  push_xgset300C
       4BBB  pop_xgset300C
       4BC0  push_xgsetF000
       4BC5  pop_xgsetF000
       4BCA  push_xgsetF00C
       4BD1  pop_xgsetF00C
       4BD8  push_xgset303C
       4BDF  pop_xgset303C
       4BE6  push_xgsetF03C
       4BEF  pop_xgsetF03C
       4BF8  xicallx
       4C01  neg32
       4C0A  long_prolog
       4C18  long_epilog
       4C23  tstzero1
       4C29  tstzero2
       4C2F  lsl16
       4C36  lsl32
       4C42  lsl8
       4C48  lsr16
       4C4F  lsr32
       4C5B  asgnblk
       4C73  fpsub
       4C75  fpadd
       4C76  fpadd_alt
       4CDD  fpadd1
       4CE7  fpadd2
       4CF2  fpsub1
       4CFC  fpsub2
       4D07  fpsub1x
       4D14  fpsub2x
       4D22  fpint
       4D54  uint2fp
       4D56  int2fp
       4D5F  ulong2fp
       4D61  long2fp
       4D78  fpdiv1
       4D81  fpdiv2
       4D8B  fpdiv1x
       4D97  fpdiv2x
       4E12  unpacks
       4E1A  tstR16_R19
       4E22  unpacku
       4E3B  normalize_and_pack
       4E70  pack
       4E80  saveFPRegs
       4E8F  restoreFPRegs
       4E9E  fpmule
       4EF1  fpmule1
       4EFB  fpmule2
       4F06  fpmule1x
       4F13  fpcmp
       4F20  fpcmp1
       4F2B  fpcmp2
       4F37  _cstrcpy
       4F41  _cstrlen
       4F4E  _atoi
       4F94  _itoa
       4FFF  _ltoa
       50B7  _ultoa
       511E  _utoa
       515E  _ftoa
       52ED  _isdigit
       52F7  _islower
       5301  _isspace
       530B  _toupper
       531E  __sdepi
       5328  _sprintf
       536C  __FormatFP_1
       5856  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0519 =   1305. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _tab
       0100  __data_start
       0103  _enter
       0106  _now
       0118  main.c:last5s
       011C  main.c:next_sample_time
       02A2  _labelH
       02B0  _labelM
       02C0  _labelL
       02CE  _H01
       02DE  _H02
       02E9  _H03
       02FB  _M03
       0305  _M04
       030F  _L03
       031E  _H13
       032E  _M12
       0340  _M13
       0352  _L11
       0364  _L12
       0376  _M21
       0385  _str_blank
       0396  _GUI_date
       05E6  _CommonId
       05E7  _devicename
       05EF  _deviceId
       05F5  lcd.c:p1
       05F7  lcd.c:p2
       05F9  lcd.c:p3
       05FB  lcd.c:p4
       0610  _T_NUM
       0611  _time_buf
       0619  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0619   0365 =    869. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0619  __bss_start
       0619  main.c:indexoffset
       061B  _TempChar
       066B  _Result
       06CB  _buffer
       08CB  _t
       08DD  _config
       08F3  ff.c:Fsid
       08F5  ff.c:FatFs
       08F7  _Rec
       097E  __bss_end

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

