FAMILY=-mpic14
MCU=-p12f683
CC=sdcc
LD=sdcc
CFLAGS=-I. -I/usr/local/share/sdcc/non-free/include
TARGET=Dado_Codigo # Cambia esto para coincidir con el nombre de tu archivo de código fuente sin la extensión .c

SRCS = Dado_Codigo.c  # Cambia esto para coincidir con el nombre de tu archivo de código fuente

all:
	${CC} --use-non-free ${FAMILY} ${MCU} ${CFLAGS} -o ${TARGET} ${SRCS}

clean:
	rm -f *.c~ *.h~ *.o *.elf *.hex *.asm