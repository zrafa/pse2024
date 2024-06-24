
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJETOS=main.o delaysw.o

BOOTCODE=bootrom.elf
BOOTCODE.BIN=bootrom.bin
APP=app.elf
APP.BIN=app.bin
APP.UF2=app.uf2

CFLAGS=-Wall -Werror -O2 -ffreestanding -mcpu=cortex-m0 -mthumb
LDFLAGS=-nostdlib

# $@:Se sustituye por el nombre del objetivo de la presente regla.
# $*:Se sustituye por la raíz de un nombre de fichero.
# $<:Se sustituye por la primera dependencia de la presente regla.
# $^:Se sustituye por una lista separada por espacios de cada una de las dependencias de la presente regla.

all: uf2

uf2: $(BOOTCODE.BIN) $(APP.BIN)
	uf2-util --bootrom $(BOOTCODE.BIN) --progdata $(APP.BIN) --output $(APP.UF2)

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

$(APP): $(OBJETOS)
	$(CC) $(LDFLAGS) -T linker.ld -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(BOOTCODE): bootrom.c bootrom.S
	$(CC) $(CFLAGS) -c bootrom.S -o start.o
	$(CC) $(CFLAGS) -c bootrom.c -o bootrom.o
	$(CC) $(LDFLAGS) start.o bootrom.o -o bootrom.elf

clean:
	rm $(OBJETOS) $(APP) $(FIRMWARE) *.bin *.uf2 *.o *.elf
