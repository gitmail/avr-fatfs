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
                           idata   00D0   03D6 =    982. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00D0  __idata_start
       04A6  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   04A6   800C =  32780. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0253  __start
       0253  __text_start
       0275  _exit
       0276  _disk_initialize
       028C  _disk_status
       0292  _disk_read
       02B2  _disk_write
       02CA  _disk_ioctl
       02CF  _get_fattime
       02D4  ff.c:mem_cpy
       02EA  ff.c:mem_set
       02FC  ff.c:mem_cmp
       031D  ff.c:chk_chr
       032D  ff.c:move_window
       03CF  ff.c:sync
       04A4  _clust2sect
       04F6  _get_fat
       0646  _put_fat
       0805  ff.c:remove_chain
       08B8  ff.c:create_chain
       0A30  ff.c:clmt_clust
       0AA9  ff.c:dir_sdi
       0BB3  ff.c:dir_next
       0D61  ff.c:dir_find
       0DA6  ff.c:dir_read
       0DF1  ff.c:dir_register
       0E54  ff.c:create_name
       0F5C  ff.c:get_fileinfo
       0FFF  ff.c:follow_path
       1083  ff.c:check_fs
       114B  ff.c:chk_mounted
       1645  ff.c:validate
       1662  _f_mount
       168D  _f_open
       1829  _f_read
       1A94  _f_write
       1DAD  _f_sync
       1E5E  _f_close
       1E6E  _f_lseek
       232B  _f_opendir
       239F  _f_readdir
       23E8  _delayus
       23F0  _delayms
       2407  _initDevices
       2434  _main
       2463  _selfTest
       251C  _WriteFileHead
       2597  _check
       26C5  _ftochr
       2706  _itochr
       2716  _StructToChar
       2790  _CharToStruct
       27D0  _get_name
       280F  _SquareRootFloat
       28AB  _debug
       28C8  _SD_Write_cmd
       28FA  _SD_Init
       295A  _SD_Write_Sector
       29E0  _SD_Read_Sector
       2A4E  _SD_Read_Sector_ndata
       2AD3  _GUI_mainmeu
       2B9F  _GUI_check
       2EF8  _GUI_get_date
       2F26  _GUI_set_time
       316E  _dateRefresh
       32BA  _uart1_init
       32CB  _uart1_rx_isr
       32D4  _Usart_Transmit
       32DB  _Puts
       32F1  _Send_nByte
       3306  _PrintString
       3315  _PrintString_n
       3328  _PrintLong
       3470  _PrintChar
       3490  _SPI_IO_Init
       349A  _SPI_Write
       349E  _SPI_Read
       34A4  _LCD_SW
       34AE  _LCD_INT
       34B7  _address
       34D8  _LCD_const_disp
       3505  _LCD_var_disp
       3532  _LCD_char_disp
       354C  _LCD_Init
       357E  _LCD_CLR
       359E  _W_1byte
       35D7  _Write_8bits
       35FC  _Set_Draw
       3608  _Set_White
       369A  _set_white_n
       36E6  _clr_white
       376E  _LCD_print2num
       379A  _LCD_print4num
       37BE  _LCD_print
       37D3  _LCD_print1
       37DD  _lp
       3845  _relay_init
       3848  _relay
       3853  _beep
       387C  _Delay_nus
       388C  _reset_18B20
       38F8  _write_bit_18B20
       3940  _read_bit_18B20
       3993  _write_byte_18B20
       39B4  _read_byte_18B20
       39D5  _convert_T
       39DD  _read_T
       3A10  _read_T_NUM
       3A2E  _ds1302_init
       3A33  _ds1302_write_byte
       3A55  _ds1302_read_byte
       3A7A  _ds1302_write_time
       3A9F  _ds1302_read_time
       3AC7  _kbscan
       3B0C  _memset
       3B17  _strcat
       3B24  _strlen
       3B30  push_arg4
       3B32  push_arg2
       3B35  asr32
       3B41  mod16s
       3B45  div16s
       3B5F  mod16u
       3B61  div16u
       3B62  xdiv16u
       3B7B  div32u
       3B7D  mod32u
       3B81  div32s
       3B83  mod32s
       3BAF  long_div_prolog
       3BC2  long_div_epilog
       3BD2  tst_R16_R19
       3BD7  tst_R24_R27
       3BDC  neg_R24_R27
       3BE5  mod8u
       3BE7  div8u
       3BE8  xdiv8u
       3BFD  elpm32
       3C11  empy16s
       3C21  empy32s
       3C21  empy32u
       3C55  pop_xgset003C
       3C5A  pop_xgset00FC
       3C61  pop_xgset30FC
       3C6A  pop_xgsetF0FC
       3C75  push_xgsetF0FC
       3C77  push_xgset30FC
       3C79  push_xgset00FC
       3C7B  push_xgset003C
       3C80  push_xgset300C
       3C85  pop_xgset300C
       3C8A  push_xgsetF000
       3C8F  pop_xgsetF000
       3C94  push_xgsetF00C
       3C9B  pop_xgsetF00C
       3CA2  push_xgset303C
       3CA9  pop_xgset303C
       3CB0  push_xgsetF03C
       3CB9  pop_xgsetF03C
       3CC2  neg32
       3CCB  long_prolog
       3CD9  long_epilog
       3CE4  tstzero1
       3CEA  tstzero2
       3CF0  lsl16
       3CF7  lsl32
       3D03  lsl8
       3D09  lsr16
       3D10  lsr32
       3D1C  asgnblk
       3D34  fpsub
       3D36  fpadd
       3D37  fpadd_alt
       3D9E  fpadd2
       3DA9  fpsub2
       3DB4  fpsub1x
       3DC1  fpsub2x
       3DCF  uint2fp
       3DD1  int2fp
       3DDA  ulong2fp
       3DDC  long2fp
       3DF3  fpdiv1
       3DFC  fpdiv2
       3E06  fpdiv1x
       3E12  fpdiv2x
       3E8D  unpacks
       3E95  tstR16_R19
       3E9D  unpacku
       3EB6  normalize_and_pack
       3EEB  pack
       3EFB  saveFPRegs
       3F0A  restoreFPRegs
       3F19  fpmule
       3F6C  fpmule1
       3F76  fpmule2
       3F81  fpmule1x
       3F8E  fpcmp
       3F9B  fpcmp2
       3FA7  _itoa
       4012  _ltoa
       40CA  _ftoa
       4259  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   03D6 =    982. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0251  _labelH
       025F  _labelM
       026F  _labelL
       027D  _H01
       028D  _H02
       0298  _H03
       02AA  _M03
       02B4  _M04
       02BE  _L03
       02CD  _H13
       02DD  _M12
       02EF  _M13
       0301  _L11
       0313  _L12
       0325  _M21
       0334  _GUI_date
       04B2  lcd.c:p1
       04B4  lcd.c:p2
       04B6  lcd.c:p3
       04B8  lcd.c:p4
       04CD  _T_NUM
       04CE  _time_buf
       04D6  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   04D6   0290 =    656. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       04D6  __bss_start
       04D6  ff.c:Fsid
       04D8  ff.c:FatFs
       04DA  _Result
       0534  _buffer
       0734  _t
       0746  _config
       0766  __bss_end

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

