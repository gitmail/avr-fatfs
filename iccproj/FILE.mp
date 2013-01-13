NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   00B1 =    177. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       013D  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   013E   4F1E =  20254. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       009F  __text_start
       009F  __start
       00C1  _exit
       00C2  _disk_initialize
       00D8  _disk_status
       00DE  _disk_read
       00FE  _disk_write
       0116  _disk_ioctl
       011B  _get_fattime
       0120  ff.c:mem_cpy
       0136  ff.c:mem_set
       0148  ff.c:mem_cmp
       0169  ff.c:chk_chr
       0179  ff.c:move_window
       021B  ff.c:sync
       02F0  _clust2sect
       0342  _get_fat
       0492  _put_fat
       0651  ff.c:remove_chain
       0704  ff.c:create_chain
       087C  ff.c:clmt_clust
       08F5  ff.c:dir_sdi
       09FF  ff.c:dir_next
       0BAD  ff.c:dir_find
       0BF2  ff.c:dir_read
       0C3D  ff.c:dir_register
       0CA0  ff.c:create_name
       0DA8  ff.c:get_fileinfo
       0E4B  ff.c:follow_path
       0ECF  ff.c:check_fs
       0F97  ff.c:chk_mounted
       1491  ff.c:validate
       14AE  _f_mount
       14D9  _f_open
       1675  _f_read
       18E0  _f_write
       1BF9  _f_sync
       1CAA  _f_close
       1CBA  _f_lseek
       2177  _f_opendir
       21EB  _f_readdir
       2234  _delayus
       223C  _delayms
       2253  _initDevices
       2259  _main
       2265  _WriteFileHead
       22BD  _SD_Write_cmd
       22EF  _SD_Init
       233B  _SD_Write_Sector
       23C1  _SD_Read_Sector
       242F  _SD_Read_Sector_ndata
       24B4  _SPI_IO_Init
       24BE  _SPI_Write
       24C2  _SPI_Read
       24C8  _uart1_init
       24D9  _uart1_rx_isr
       24E2  _Usart_Transmit
       24E9  _Puts
       24FF  _Send_nByte
       2514  _PrintString
       2523  _PrintString_n
       2536  _PrintLong
       267E  _PrintChar
       269E  _memset
       26A9  push_arg4
       26AB  push_arg2
       26AE  div32u
       26B0  mod32u
       26B4  div32s
       26B6  mod32s
       26E2  long_div_prolog
       26F5  long_div_epilog
       2705  tst_R16_R19
       270A  tst_R24_R27
       270F  neg_R24_R27
       2718  empy16s
       2728  empy32s
       2728  empy32u
       275C  pop_xgset003C
       2761  pop_xgset00FC
       2768  pop_xgset30FC
       2771  pop_xgsetF0FC
       277C  push_xgsetF0FC
       277E  push_xgset30FC
       2780  push_xgset00FC
       2782  push_xgset003C
       2787  push_xgset300C
       278C  pop_xgset300C
       2791  push_xgsetF000
       2796  pop_xgsetF000
       279B  push_xgsetF00C
       27A2  pop_xgsetF00C
       27A9  push_xgset303C
       27B0  pop_xgset303C
       27B7  push_xgsetF03C
       27C0  pop_xgsetF03C
       27C9  neg32
       27D2  long_prolog
       27E0  long_epilog
       27EB  tstzero1
       27F1  tstzero2
       27F7  lsl32
       2803  lsr16
       280A  lsr32
       2816  asgnblk
       282E  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   00B1 =    177. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       01B1  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   01B1   0204 =    516. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       01B1  __bss_start
       01B1  ff.c:Fsid
       01B3  ff.c:FatFs
       01B5  _buffer
       03B5  __bss_end

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
SPI.o	[ SPI.c ]
usart.o	[ usart.c ]
<library>	[ memset.s, asave.s, div32.s, emul16s.s, emul32.s, gpop2.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, gpushx.s ]
[ gpushy.s, gpushz.s, gpusha.s, gpushb.s, lneg.s, longutil.s, lsl32.s, lsr16.s, lsr32.s, struct.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

