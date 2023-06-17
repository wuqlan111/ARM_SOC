
.PHNOY= all  clean
CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump

TARGET_NAME = armv7
OUTDIR = ./target

CFLAGS   =  -mcpu=cortex-m3 -mthumb -g -Wall -fno-builtin -fno-strict-aliasing 
CFLAGS  +=  -ffunction-sections -fdata-sections -fno-common
CFLAGS  +=  --specs=nosys.specs -ggdb -fno-exceptions
CFLAGS  +=  -O0

LDFLAGS = -T ./boot/boot.ld  -Wl,-Map=$(OUTDIR)/$(TARGET_NAME).map

INCLUDES =  -I./include/asm -I./include/

SRCS +=  ./boot/init.S   ./kernel/*.c    ./mm/*.c   ./test/*.c


all:
	mkdir   $(OUTDIR)
	$(CC)  -o $(OUTDIR)/$(TARGET_NAME).elf    $(CFLAGS) $(LDFLAGS)  $(SRCS) $(INCLUDES)
	$(OBJCOPY)  -O   ihex  $(OUTDIR)/$(TARGET_NAME).elf   $(OUTDIR)/$(TARGET_NAME).hex
	$(OBJCOPY)  -O   binary  $(OUTDIR)/$(TARGET_NAME).elf   $(OUTDIR)/$(TARGET_NAME).bin



clean:
	rm -rf  *.o   $(OUTDIR)


