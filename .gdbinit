set architecture i386
set disassembly-flavor intel
symbol-file src/rom.elf

# If you're debugging an nxdk-built XBE, you can uncomment the following line.
# You'll need to double-check the .text address though.
# add-symbol-file /path/to/nxdk/samples/triangle/main.exe 0x17000

# If you built using a different path (e.g. via Docker), you'll need to set
# a substitution path for GDB to locate the source files.
# set substitute-path /work /path/to/src/

target remote 127.0.0.1:1234
layout src
b init
