COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf 

install: 
	(cd timerLib; make install)

#additional rules for files
main.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o main.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	(cd timerLib; make clean)
	rm -f *.o *.elf
