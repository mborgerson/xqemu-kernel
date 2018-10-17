CC           := gcc
CFLAGS       := -Werror -O0 -march=pentium -m32 -g  -fno-stack-protector -ffreestanding -fno-pic
LD           := ld
LDFLAGS      := --script=rom.ld -m elf_i386
#--gc-sections
NASM         := nasm
NASM_FLAGS   := -felf
OBJCOPY      := objcopy
OBJCOPYFLAGS := --output-target=binary
TARGET       := rom.bin
OBJECTS      := \
	start.o \
	init.o \
	stubs.o \
	printk.o \
	mm/dlmalloc.o \
	mm/vmalloc.o \
	mm/paging.o \
	drivers/cpu/cputools.o \
	drivers/cpu/ioapic.o \
	drivers/pci/int_handlers.o \
	drivers/pci/BootInterrupts.o \
	drivers/pci/i2cio.o \
	drivers/pci/pci.o \
	drivers/serial/serial.o \
	drivers/video/BootVgaInitialization.o \
	drivers/video/BootVideoHelpers.o \
	drivers/video/conexant.o \
	drivers/video/VideoInitialization.o \
	lib/eeprom/BootEEPROM.o \
	lib/misc/BootLibrary.o \
	lib/misc/vsprintf.o \
	lib/xbe/xbe.o \
	rtl/mem.o \

INCLUDE = -I. -Iinclude -Ilib/eeprom -Ilib/misc -Ilib/font -Idrivers/video -Idrivers/cpu
CFLAGS += $(INCLUDE)

all: clean $(TARGET)
.PRECIOUS: $(OBJECTS) $(TARGET:.bin=.elf)

# Quiet (pass V=1 to make to get full commands)
V =
ifeq ($(V),)
	Q = @
endif


mm/dlmalloc.o.cflags = -DLACKS_UNISTD_H -DHAVE_MORECORE=0 -DHAVE_MREMAP=0 \
	-DLACKS_ERRNO_H=1 -DDEFAULT_GRANULARITY=4096 -DMSPACES=1 -DUSE_DL_PREFIX=1

%.bin: %.elf
	@echo "[**] Converting $< to $@"
	$(Q) $(OBJCOPY) $(OBJCOPYFLAGS) $^ $@

%.elf: $(OBJECTS) rom.ld
	@echo "[**] Linking $@"
	$(Q) $(LD) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	@echo "[**] Compiling $<"
	$(Q) $(CC) $(CFLAGS) $($@.cflags) -o $@ -c $<

%.o: %.S
	@echo "[**] Assembling $<"
	$(Q) $(CC) $(CFLAGS) -o $@ -c $<

%.o: %.nasm
	@echo "[**] Assembling $<"
	$(Q) $(NASM) -o $@ $(NASM_FLAGS) $<

.PHONY: clean
clean:
	$(Q) rm -f $(TARGET) $(TARGET:.bin=.elf) $(OBJECTS)

.PHONY: run
run: $(TARGET)
	# Pad up to 64K
	dd if=/dev/zero of=$$.bin bs=1 count=65024 && \
	cat $(TARGET) >> $$.bin && \
	qemu-system-i386 -bios $$.bin --vnc none --serial stdio
