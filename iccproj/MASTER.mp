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
                           idata   00D0   0475 =   1141. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       0545  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0546   8BCA =  35786. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       02A3  __start
       02A3  __text_start
       02C5  _exit
       02C6  _disk_initialize
       02DC  _disk_status
       02E2  _disk_read
       0302  _disk_write
       031A  _disk_ioctl
       031F  _get_fattime
       0324  ff.c:mem_cpy
       033A  ff.c:mem_set
       034C  ff.c:mem_cmp
       036D  ff.c:chk_chr
       037D  ff.c:move_window
       041F  ff.c:sync
       04F4  _clust2sect
       0546  _get_fat
       0696  _put_fat
       0855  ff.c:remove_chain
       0908  ff.c:create_chain
       0A80  ff.c:clmt_clust
       0AF9  ff.c:dir_sdi
       0C03  ff.c:dir_next
       0DB1  ff.c:dir_find
       0DF6  ff.c:dir_read
       0E41  ff.c:dir_register
       0EA4  ff.c:create_name
       0FAC  ff.c:get_fileinfo
       104F  ff.c:follow_path
       10D3  ff.c:check_fs
       119B  ff.c:chk_mounted
       1695  ff.c:validate
       16B2  _f_mount
       16DD  _f_open
       1879  _f_read
       1AE4  _f_write
       1DFD  _f_sync
       1EAE  _f_close
       1EBE  _f_lseek
       237B  _f_opendir
       23EF  _f_readdir
       2438  _delayus
       2440  _delayms
       2457  _initDevices
       248C  _timer1_init
       2494  _main
       24F5  _selfTest
       25AE  _WriteFileHead
       262A  _WriteSDFile
       268C  _ReadSDFile
       273E  _findIndex
       289E  _scan_files
       28E5  _check
       2A1E  _ftochr
       2A5F  _itochr
       2A6F  _StructToChar
       2AD8  _CharToStruct
       2B1D  _get_name
       2B5C  _SquareRootFloat
       2BF8  _debug
       2C08  _SD_Write_cmd
       2C3A  _SD_Init
       2C9A  _SD_Write_Sector
       2D20  _SD_Read_Sector
       2D8E  _SD_Read_Sector_ndata
       2E13  _GUI_mainmeu
       2F02  _GUI_check
       3175  __GUI_datashow
       3381  _GUI_get_date
       33AF  _GUI_set_time
       35ED  _GUI_readback
       377E  _GUI_welcome
       379B  _dateRefresh
       38EA  _uart1_init
       38FB  _uart1_rx_isr
       3904  _Usart_Transmit
       390B  _Puts
       3921  _Send_nByte
       3936  _PrintString
       3945  _PrintString_n
       3958  _PrintLong
       3AA0  _PrintChar
       3AC0  _SPI_IO_Init
       3ACA  _SPI_Write
       3ACE  _SPI_Read
       3AD4  _LCD_SW
       3ADE  _LCD_INT
       3AE7  _address
       3B08  _LCD_const_disp
       3B35  _LCD_var_disp
       3B62  _LCD_char_disp
       3B7C  _LCD_Init
       3BAE  _LCD_CLR
       3BCE  _W_1byte
       3C07  _Write_8bits
       3C2C  _Set_Draw
       3C38  _Set_White
       3CCA  _set_white_n
       3D16  _clr_white
       3D9E  _LCD_print2num
       3DCA  _LCD_print4num
       3DEE  _LCD_print
       3E03  _LCD_print1
       3E0D  _lp
       3E75  _relay_init
       3E78  _relay
       3E83  _beep
       3EAC  _Delay_nus
       3EBC  _reset_18B20
       3F28  _write_bit_18B20
       3F70  _read_bit_18B20
       3FC3  _write_byte_18B20
       3FE4  _read_byte_18B20
       4005  _convert_T
       400D  _read_T
       403B  _read_T_NUM
       4059  _ds1302_init
       405E  _ds1302_write_byte
       4080  _ds1302_read_byte
       40A5  _ds1302_write_time
       40CA  _ds1302_read_time
       40F2  _kbscan
       413B  _memset
       4146  _strcat
       4153  _strlen
       415F  push_arg4
       4161  push_arg2
       4164  asr32
       4170  mod16s
       4174  div16s
       418E  mod16u
       4190  div16u
       4191  xdiv16u
       41AA  div32u
       41AC  mod32u
       41B0  div32s
       41B2  mod32s
       41DE  long_div_prolog
       41F1  long_div_epilog
       4201  tst_R16_R19
       4206  tst_R24_R27
       420B  neg_R24_R27
       4214  mod8u
       4216  div8u
       4217  xdiv8u
       422C  elpm32
       4240  empy16s
       4250  empy32u
       4250  empy32s
       4284  pop_xgset003C
       4289  pop_xgset00FC
       4290  pop_xgset30FC
       4299  pop_xgsetF0FC
       42A4  push_xgsetF0FC
       42A6  push_xgset30FC
       42A8  push_xgset00FC
       42AA  push_xgset003C
       42AF  push_xgset300C
       42B4  pop_xgset300C
       42B9  push_xgsetF000
       42BE  pop_xgsetF000
       42C3  push_xgsetF00C
       42CA  pop_xgsetF00C
       42D1  push_xgset303C
       42D8  pop_xgset303C
       42DF  push_xgsetF03C
       42E8  pop_xgsetF03C
       42F1  neg32
       42FA  long_prolog
       4308  long_epilog
       4313  tstzero1
       4319  tstzero2
       431F  lsl16
       4326  lsl32
       4332  lsl8
       4338  lsr16
       433F  lsr32
       434B  asgnblk
       4363  fpsub
       4365  fpadd
       4366  fpadd_alt
       43CD  fpadd2
       43D8  fpsub2
       43E3  fpsub1x
       43F0  fpsub2x
       43FE  uint2fp
       4400  int2fp
       4409  ulong2fp
       440B  long2fp
       4422  fpdiv1
       442B  fpdiv2
       4435  fpdiv1x
       4441  fpdiv2x
       44BC  unpacks
       44C4  tstR16_R19
       44CC  unpacku
       44E5  normalize_and_pack
       451A  pack
       452A  saveFPRegs
       4539  restoreFPRegs
       4548  fpmule
       459B  fpmule1
       45A5  fpmule2
       45B0  fpmule1x
       45BD  fpcmp
       45CA  fpcmp2
       45D6  _itoa
       4641  _ltoa
       46F9  _ftoa
       4888  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0475 =   1141. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       027D  _labelH
       028B  _labelM
       029B  _labelL
       02A9  _H01
       02B9  _H02
       02C4  _H03
       02D6  _M03
       02E0  _M04
       02EA  _L03
       02F9  _H13
       0309  _M12
       031B  _M13
       032D  _L11
       033F  _L12
       0351  _M21
       0360  _GUI_date
       0551  lcd.c:p1
       0553  lcd.c:p2
       0555  lcd.c:p3
       0557  lcd.c:p4
       056C  _T_NUM
       056D  _time_buf
       0575  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0575   02E9 =    745. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0575  __bss_start
       0575  ff.c:Fsid
       0577  ff.c:FatFs
       0579  main.c:indexoffset
       057B  _TempChar
       05CB  _Result
       0629  _buffer
       0829  _t
       083B  _config
       085E  __bss_end

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

