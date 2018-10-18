CC           := gcc
CFLAGS       := -Wall -O0 -march=pentium -m32 -g -fno-stack-protector -ffreestanding -fno-pic
LD           := ld
LDFLAGS      := --script=rom.ld -m elf_i386 --gc-sections
NASM         := nasm
NASM_FLAGS   := -felf
OBJCOPY      := objcopy
OBJCOPYFLAGS := --output-target=binary
TARGET       := rom.bin
SOURCES      := \
	start.nasm \
	init.c \
	stubs.c \
	printk.c \
	mm/dlmalloc.c \
	mm/paging.c \
	drivers/cpu/cputools.c \
	drivers/cpu/ioapic.c \
	drivers/pci/int_handlers.S \
	drivers/pci/BootInterrupts.c \
	drivers/pci/i2cio.c \
	drivers/pci/pci.c \
	drivers/serial/serial.c \
	drivers/video/BootVgaInitialization.c \
	drivers/video/BootVideoHelpers.c \
	drivers/video/conexant.c \
	drivers/video/VideoInitialization.c \
	lib/eeprom/BootEEPROM.c \
	lib/misc/BootLibrary.c \
	lib/misc/vsprintf.c \
	lib/xbe/xbe.c \
	rtl/mem.c \

OBJECTS := $(SOURCES:%.nasm=%.o)
OBJECTS := $(OBJECTS:%.S=%.o)
OBJECTS := $(OBJECTS:%.c=%.o)

# C include dependency tracking
DEPS := $(filter %.c,$(SOURCES))
DEPS := $(DEPS:%.c=%.d)

INCLUDE = -I. -Iinclude -Ilib/eeprom -Ilib/misc -Ilib/font -Idrivers/video -Idrivers/cpu
CFLAGS += $(INCLUDE)

all: $(TARGET)
.PRECIOUS: $(OBJECTS) $(TARGET:.bin=.elf)

# Quiet (pass V=1 to make to get full commands)
V =
ifeq ($(V),)
	Q = @
endif

# Special flags for dlmalloc
mm/dlmalloc.o.cflags = -DHAVE_MORECORE=0 -DHAVE_MREMAP=0 \
	-DDEFAULT_GRANULARITY=4096 -DMSPACES=1 -DUSE_DL_PREFIX=1 \
	-DLACKS_ERRNO_H=1 \
	-DLACKS_FCNTL_H=1 \
	-DLACKS_SCHED_H=1 \
	-DLACKS_STRINGS_H=1 \
	-DLACKS_SYS_PARAM_H=1 \
	-DLACKS_TIME_H=1 \
	-DLACKS_UNISTD_H=1 \
	-DUSE_LOCKS=0

%.bin: %.elf
	@echo "objcopy  $@"
	$(Q) $(OBJCOPY) $(OBJCOPYFLAGS) $^ $@

%.elf: $(OBJECTS) rom.ld
	@echo "ld       $@"
	$(Q) $(LD) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	@echo "cc       $@"
	$(Q) $(CC) $(CFLAGS) $($@.cflags) -MMD -o $@ -c $<

%.o: %.S
	@echo "as       $@"
	$(Q) $(CC) $(CFLAGS) -o $@ -c $<

%.o: %.nasm
	@echo "nasm     $@"
	$(Q) $(NASM) -o $@ $(NASM_FLAGS) $<

.PHONY: clean
clean:
	$(Q) rm -f $(TARGET) $(TARGET:.bin=.elf) $(OBJECTS) $(DEPS)

-include $(DEPS)
