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
                             lit   008E   01CC =    460. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008E  __lit_start
       00EC  __ctype
       025A  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   025A   048D =   1165. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       025A  __idata_start
       06E7  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   06E8   A294 =  41620. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0374  __start
       0374  __text_start
       0396  _exit
       0397  _disk_initialize
       03AD  _disk_status
       03B3  _disk_read
       03D3  _disk_write
       03EB  _disk_ioctl
       03F0  _get_fattime
       03F5  ff.c:mem_cpy
       040B  ff.c:mem_set
       041D  ff.c:mem_cmp
       043E  ff.c:chk_chr
       044E  ff.c:move_window
       04F0  ff.c:sync
       05C5  _clust2sect
       0617  _get_fat
       0767  _put_fat
       0926  ff.c:remove_chain
       09D9  ff.c:create_chain
       0B51  ff.c:clmt_clust
       0BCA  ff.c:dir_sdi
       0CD4  ff.c:dir_next
       0E82  ff.c:dir_find
       0EC7  ff.c:dir_read
       0F12  ff.c:dir_register
       0F75  ff.c:create_name
       107D  ff.c:get_fileinfo
       1120  ff.c:follow_path
       11A4  ff.c:check_fs
       126C  ff.c:chk_mounted
       1766  ff.c:validate
       1783  _f_mount
       17AE  _f_open
       194A  _f_read
       1BB5  _f_write
       1ECE  _f_sync
       1F7F  _f_close
       1F8F  _f_lseek
       244C  _f_opendir
       24C0  _f_readdir
       2509  _delayus
       2511  _delayms
       2528  _initDevices
       255D  _timer1_init
       2565  _main
       25E5  _selfTest
       269E  _WriteFileHead
       2719  _WriteSDFile
       277B  _ReadSDFile
       282D  _findIndex
       298D  _scan_files
       29D4  _check
       2B44  _ftochr
       2B85  _itochr
       2B95  _StructToChar
       2BFE  _CharToStruct
       2C43  _get_name
       2C82  _SquareRootFloat
       2D1E  _debug
       2D2E  _SD_Write_cmd
       2D60  _SD_Init
       2DC0  _SD_Write_Sector
       2E46  _SD_Read_Sector
       2EB4  _SD_Read_Sector_ndata
       2F39  _GUI_mainmeu
       3028  _GUI_check
       329C  __GUI_datashow
       34A8  _GUI_get_date
       34D6  _GUI_set_time
       3727  _GUI_readback
       38B8  _GUI_welcome
       38D5  _dateRefresh
       3A1E  _uart1_init
       3A2F  _uart1_rx_isr
       3A38  _Usart_Transmit
       3A3F  _Puts
       3A55  _Send_nByte
       3A6A  _PrintString
       3A79  _PrintString_n
       3A8C  _PrintLong
       3BD4  _PrintChar
       3BF4  _SPI_IO_Init
       3BFE  _SPI_Write
       3C02  _SPI_Read
       3C08  _LCD_SW
       3C12  _LCD_INT
       3C1B  _address
       3C3C  _LCD_const_disp
       3C69  _LCD_var_disp
       3C96  _LCD_char_disp
       3CB0  _LCD_Init
       3CE2  _LCD_CLR
       3D02  _W_1byte
       3D3B  _Write_8bits
       3D60  _Set_Draw
       3D6C  _Set_White
       3DFE  _set_white_n
       3E4A  _clr_white
       3ED2  _LCD_print2num
       3EFE  _LCD_print4num
       3F22  _LCD_print
       3F37  _LCD_print1
       3F41  _lp
       3FA9  _relay_init
       3FAC  _relay
       3FB7  _beep
       3FE0  _Delay_nus
       3FF0  _reset_18B20
       405C  _write_bit_18B20
       40A4  _read_bit_18B20
       40F7  _write_byte_18B20
       4118  _read_byte_18B20
       4139  _convert_T
       4141  _read_T
       416F  _read_T_NUM
       418D  _ds1302_init
       4192  _ds1302_write_byte
       41B4  _ds1302_read_byte
       41D9  _ds1302_write_time
       41FE  _ds1302_read_time
       4226  _kbscan
       426F  __print
       46DC  _memset
       46E7  _strcat
       46F4  _strlen
       4700  push_arg4
       4702  push_arg2
       4705  asr32
       4711  mod16s
       4715  div16s
       472F  mod16u
       4731  div16u
       4732  xdiv16u
       474B  div32u
       474D  mod32u
       4751  div32s
       4753  mod32s
       477F  long_div_prolog
       4792  long_div_epilog
       47A2  tst_R16_R19
       47A7  tst_R24_R27
       47AC  neg_R24_R27
       47B5  mod8u
       47B7  div8u
       47B8  xdiv8u
       47CD  elpm32
       47E1  empy16s
       47F1  empy32s
       47F1  empy32u
       4825  pop_xgset003C
       482A  pop_xgset00FC
       4831  pop_xgset30FC
       483A  pop_xgsetF0FC
       4845  push_xgsetF0FC
       4847  push_xgset30FC
       4849  push_xgset00FC
       484B  push_xgset003C
       4850  push_xgset300C
       4855  pop_xgset300C
       485A  push_xgsetF000
       485F  pop_xgsetF000
       4864  push_xgsetF00C
       486B  pop_xgsetF00C
       4872  push_xgset303C
       4879  pop_xgset303C
       4880  push_xgsetF03C
       4889  pop_xgsetF03C
       4892  xicallx
       489B  neg32
       48A4  long_prolog
       48B2  long_epilog
       48BD  tstzero1
       48C3  tstzero2
       48C9  lsl16
       48D0  lsl32
       48DC  lsl8
       48E2  lsr16
       48E9  lsr32
       48F5  asgnblk
       490D  fpsub
       490F  fpadd
       4910  fpadd_alt
       4977  fpadd1
       4981  fpadd2
       498C  fpsub1
       4996  fpsub2
       49A1  fpsub1x
       49AE  fpsub2x
       49BC  uint2fp
       49BE  int2fp
       49C7  ulong2fp
       49C9  long2fp
       49E0  fpdiv1
       49E9  fpdiv2
       49F3  fpdiv1x
       49FF  fpdiv2x
       4A7A  unpacks
       4A82  tstR16_R19
       4A8A  unpacku
       4AA3  normalize_and_pack
       4AD8  pack
       4AE8  saveFPRegs
       4AF7  restoreFPRegs
       4B06  fpmule
       4B59  fpmule1
       4B63  fpmule2
       4B6E  fpmule1x
       4B7B  fpcmp
       4B88  fpcmp1
       4B93  fpcmp2
       4B9F  _cstrcpy
       4BA9  _cstrlen
       4BB6  _atoi
       4BFC  _itoa
       4C67  _ltoa
       4D1F  _ultoa
       4D86  _utoa
       4DC6  _ftoa
       4F55  _isdigit
       4F5F  _islower
       4F69  _isspace
       4F73  _toupper
       4F86  __sdepi
       4F90  _sprintf
       4FD4  __FormatFP_1
       54BE  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   048D =   1165. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _tab
       0112  _enter
       0115  _now
       0289  _labelH
       0297  _labelM
       02A7  _labelL
       02B5  _H01
       02C5  _H02
       02D0  _H03
       02E2  _M03
       02EC  _M04
       02F6  _L03
       0305  _H13
       0315  _M12
       0327  _M13
       0339  _L11
       034B  _L12
       035D  _M21
       036C  _GUI_date
       0569  lcd.c:p1
       056B  lcd.c:p2
       056D  lcd.c:p3
       056F  lcd.c:p4
       0584  _T_NUM
       0585  _time_buf
       058D  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   058D   0304 =    772. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       058D  __bss_start
       058D  ff.c:Fsid
       058F  ff.c:FatFs
       0591  main.c:indexoffset
       0593  _TempChar
       05E3  _Result
       0641  _buffer
       0841  _t
       0853  _config
       0891  __bss_end

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
[ fpadd1.s, fpadd2.s, fpsub1.s, fpsub2.s, fpsub1x.s, fpsub2x.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s ]
[ fpmule1.s, fpmule2.s, fpmule1x.s, fpcmp.s, fpcmp1.s, fpcmp2.s, cstrcpy.s, cstrlen.s, atoi.s, itoa.s ]
[ ltoa.s, ultoa.s, utoa.s, ftoa.s, isdigit.s, islower.s, isspace.s, ctype.s, toupper.s, sprintf.s, formatfp1.s ]


User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x100

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

