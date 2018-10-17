XQEMU=$PWD/../xqemu/i386-softmmu/qemu-system-i386
BIOS=$PWD/src/rom.bin
export KHLE_XBE=$PWD/../nxdk/samples/mesh/bin/default.xbe

export QEMU_AUDIO_DRV=none
$XQEMU \
	-cpu pentium3 \
	-machine xbox -m 64 \
	-bios $BIOS \
	-net nic,model=nvnet  \
	-usb \
	-device usb-xbox-gamepad \
	-accel tcg \
	-display sdl \
	-device lpc47m157 \
	-serial stdio \
	 \
	2>&1
