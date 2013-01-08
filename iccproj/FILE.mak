CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = diskio.o ff.o delay.o main.o sd.o SPI.o usart.o 

FILE:	$(FILES)
	$(CC) -o FILE $(LFLAGS) @FILE.lk   -lcatm128
diskio.o: .\..\software_src\diskio.h .\..\software_src\integer.h .\..\software_src\sd.h .\..\software_src\config.h E:\PROGRA~1\icc\include\iom128v.h E:\PROGRA~1\icc\include\stdio.h E:\PROGRA~1\icc\include\stdarg.h E:\PROGRA~1\icc\include\_const.h E:\PROGRA~1\icc\include\stdlib.h E:\PROGRA~1\icc\include\limits.h E:\PROGRA~1\icc\include\string.h .\..\software_src\SPI.h .\..\software_src\usart.h .\..\software_src\delay.h .\..\software_src\ff.h .\..\software_src\ffconf.h
diskio.o:	..\software_src\diskio.c
	$(CC) -c $(CFLAGS) ..\software_src\diskio.c
ff.o: .\..\software_src\ff.h .\..\software_src\integer.h .\..\software_src\ffconf.h .\..\software_src\diskio.h E:\PROGRA~1\icc\include\string.h E:\PROGRA~1\icc\include\_const.h
ff.o:	..\software_src\ff.c
	$(CC) -c $(CFLAGS) ..\software_src\ff.c
delay.o:
delay.o:	..\software_src\delay.c
	$(CC) -c $(CFLAGS) ..\software_src\delay.c
main.o: .\..\software_src\config.h E:\PROGRA~1\icc\include\iom128v.h E:\PROGRA~1\icc\include\stdio.h E:\PROGRA~1\icc\include\stdarg.h E:\PROGRA~1\icc\include\_const.h E:\PROGRA~1\icc\include\stdlib.h E:\PROGRA~1\icc\include\limits.h E:\PROGRA~1\icc\include\string.h .\..\software_src\sd.h .\..\software_src\SPI.h .\..\software_src\usart.h .\..\software_src\delay.h .\..\software_src\diskio.h .\..\software_src\integer.h .\..\software_src\ff.h .\..\software_src\ffconf.h
main.o:	..\software_src\main.c
	$(CC) -c $(CFLAGS) ..\software_src\main.c
sd.o: .\..\software_src\sd.h .\..\software_src\config.h E:\PROGRA~1\icc\include\iom128v.h E:\PROGRA~1\icc\include\stdio.h E:\PROGRA~1\icc\include\stdarg.h E:\PROGRA~1\icc\include\_const.h E:\PROGRA~1\icc\include\stdlib.h E:\PROGRA~1\icc\include\limits.h E:\PROGRA~1\icc\include\string.h .\..\software_src\SPI.h .\..\software_src\usart.h .\..\software_src\delay.h .\..\software_src\diskio.h .\..\software_src\integer.h .\..\software_src\ff.h .\..\software_src\ffconf.h
sd.o:	..\software_src\sd.c
	$(CC) -c $(CFLAGS) ..\software_src\sd.c
SPI.o: .\..\software_src\SPI.h .\..\software_src\config.h E:\PROGRA~1\icc\include\iom128v.h E:\PROGRA~1\icc\include\stdio.h E:\PROGRA~1\icc\include\stdarg.h E:\PROGRA~1\icc\include\_const.h E:\PROGRA~1\icc\include\stdlib.h E:\PROGRA~1\icc\include\limits.h E:\PROGRA~1\icc\include\string.h .\..\software_src\sd.h .\..\software_src\usart.h .\..\software_src\delay.h .\..\software_src\diskio.h .\..\software_src\integer.h .\..\software_src\ff.h .\..\software_src\ffconf.h
SPI.o:	..\software_src\SPI.c
	$(CC) -c $(CFLAGS) ..\software_src\SPI.c
usart.o: .\..\software_src\config.h E:\PROGRA~1\icc\include\iom128v.h E:\PROGRA~1\icc\include\stdio.h E:\PROGRA~1\icc\include\stdarg.h E:\PROGRA~1\icc\include\_const.h E:\PROGRA~1\icc\include\stdlib.h E:\PROGRA~1\icc\include\limits.h E:\PROGRA~1\icc\include\string.h .\..\software_src\sd.h .\..\software_src\SPI.h .\..\software_src\usart.h .\..\software_src\delay.h .\..\software_src\diskio.h .\..\software_src\integer.h .\..\software_src\ff.h .\..\software_src\ffconf.h
usart.o:	..\software_src\usart.c
	$(CC) -c $(CFLAGS) ..\software_src\usart.c
