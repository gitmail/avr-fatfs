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
                           idata   00D0   041C =   1052. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04EC  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04EC   89B2 =  35250. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0276  __start
       0276  __text_start
       0298  _exit
       0299  _disk_initialize
       02AF  _disk_status
       02B5  _disk_read
       02D5  _disk_write
       02ED  _disk_ioctl
       02F2  _get_fattime
       02F7  ff.c:mem_cpy
       030D  ff.c:mem_set
       031F  ff.c:mem_cmp
       0340  ff.c:chk_chr
       0350  ff.c:move_window
       03F2  ff.c:sync
       04C7  _clust2sect
       0519  _get_fat
       0669  _put_fat
       0828  ff.c:remove_chain
       08DB  ff.c:create_chain
       0A53  ff.c:clmt_clust
       0ACC  ff.c:dir_sdi
       0BD6  ff.c:dir_next
       0D84  ff.c:dir_find
       0DC9  ff.c:dir_read
       0E14  ff.c:dir_register
       0E77  ff.c:create_name
       0F7F  ff.c:get_fileinfo
       1022  ff.c:follow_path
       10A6  ff.c:check_fs
       116E  ff.c:chk_mounted
       1668  ff.c:validate
       1685  _f_mount
       16B0  _f_open
       184C  _f_read
       1AB7  _f_write
       1DD0  _f_sync
       1E81  _f_close
       1E91  _f_lseek
       234E  _f_opendir
       23C2  _f_readdir
       240B  _delayus
       2413  _delayms
       242A  _initDevices
       245F  _timer1_init
       2467  _main
       24C8  _selfTest
       2581  _WriteFileHead
       25FD  _WriteSDFile
       265F  _ReadSDFile
       26C4  _findIndex
       2824  _check
       2952  _ftochr
       2993  _itochr
       29A3  _StructToChar
       2A0C  _CharToStruct
       2A4C  _get_name
       2A8B  _SquareRootFloat
       2B27  _debug
       2B44  _SD_Write_cmd
       2B76  _SD_Init
       2BD6  _SD_Write_Sector
       2C5C  _SD_Read_Sector
       2CCA  _SD_Read_Sector_ndata
       2D4F  _GUI_mainmeu
       2E3E  _GUI_check
       30A7  __GUI_datashow
       32B3  _GUI_get_date
       32E1  _GUI_set_time
       3529  _GUI_readback
       3646  _GUI_welcome
       3663  _dateRefresh
       37B0  _uart1_init
       37C1  _uart1_rx_isr
       37CA  _Usart_Transmit
       37D1  _Puts
       37E7  _Send_nByte
       37FC  _PrintString
       380B  _PrintString_n
       381E  _PrintLong
       3966  _PrintChar
       3986  _SPI_IO_Init
       3990  _SPI_Write
       3994  _SPI_Read
       399A  _LCD_SW
       39A4  _LCD_INT
       39AD  _address
       39CE  _LCD_const_disp
       39FB  _LCD_var_disp
       3A28  _LCD_char_disp
       3A42  _LCD_Init
       3A74  _LCD_CLR
       3A94  _W_1byte
       3ACD  _Write_8bits
       3AF2  _Set_Draw
       3AFE  _Set_White
       3B90  _set_white_n
       3BDC  _clr_white
       3C64  _LCD_print2num
       3C90  _LCD_print4num
       3CB4  _LCD_print
       3CC9  _LCD_print1
       3CD3  _lp
       3D3B  _relay_init
       3D3E  _relay
       3D49  _beep
       3D72  _Delay_nus
       3D82  _reset_18B20
       3DEE  _write_bit_18B20
       3E36  _read_bit_18B20
       3E89  _write_byte_18B20
       3EAA  _read_byte_18B20
       3ECB  _convert_T
       3ED3  _read_T
       3F06  _read_T_NUM
       3F24  _ds1302_init
       3F29  _ds1302_write_byte
       3F4B  _ds1302_read_byte
       3F70  _ds1302_write_time
       3F95  _ds1302_read_time
       3FBD  _kbscan
       4002  _memset
       400D  _strcat
       401A  _strlen
       4026  push_arg4
       4028  push_arg2
       402B  asr32
       4037  mod16s
       403B  div16s
       4055  mod16u
       4057  div16u
       4058  xdiv16u
       4071  div32u
       4073  mod32u
       4077  div32s
       4079  mod32s
       40A5  long_div_prolog
       40B8  long_div_epilog
       40C8  tst_R16_R19
       40CD  tst_R24_R27
       40D2  neg_R24_R27
       40DB  mod8u
       40DD  div8u
       40DE  xdiv8u
       40F3  elpm32
       4107  empy16s
       4117  empy32u
       4117  empy32s
       414B  pop_xgset003C
       4150  pop_xgset00FC
       4157  pop_xgset30FC
       4160  pop_xgsetF0FC
       416B  push_xgsetF0FC
       416D  push_xgset30FC
       416F  push_xgset00FC
       4171  push_xgset003C
       4176  push_xgset300C
       417B  pop_xgset300C
       4180  push_xgsetF000
       4185  pop_xgsetF000
       418A  push_xgsetF00C
       4191  pop_xgsetF00C
       4198  push_xgset303C
       419F  pop_xgset303C
       41A6  push_xgsetF03C
       41AF  pop_xgsetF03C
       41B8  neg32
       41C1  long_prolog
       41CF  long_epilog
       41DA  tstzero1
       41E0  tstzero2
       41E6  lsl16
       41ED  lsl32
       41F9  lsl8
       41FF  lsr16
       4206  lsr32
       4212  asgnblk
       422A  fpsub
       422C  fpadd
       422D  fpadd_alt
       4294  fpadd2
       429F  fpsub2
       42AA  fpsub1x
       42B7  fpsub2x
       42C5  uint2fp
       42C7  int2fp
       42D0  ulong2fp
       42D2  long2fp
       42E9  fpdiv1
       42F2  fpdiv2
       42FC  fpdiv1x
       4308  fpdiv2x
       4383  unpacks
       438B  tstR16_R19
       4393  unpacku
       43AC  normalize_and_pack
       43E1  pack
       43F1  saveFPRegs
       4400  restoreFPRegs
       440F  fpmule
       4462  fpmule1
       446C  fpmule2
       4477  fpmule1x
       4484  fpcmp
       4491  fpcmp2
       449D  _itoa
       4508  _ltoa
       45C0  _ftoa
       474F  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   041C =   1052. bytes (rel,con,ram)

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
       04F8  lcd.c:p1
       04FA  lcd.c:p2
       04FC  lcd.c:p3
       04FE  lcd.c:p4
       0513  _T_NUM
       0514  _time_buf
       051C  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   051C   02E7 =    743. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       051C  __bss_start
       051C  ff.c:Fsid
       051E  ff.c:FatFs
       0520  _TempChar
       0570  _Result
       05CE  _buffer
       07CE  _t
       07E0  _config
       0803  __bss_end

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

