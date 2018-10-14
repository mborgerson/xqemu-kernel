xboxkrnl
========
* **The goal:** XQEMU-compatible kernel to boot games
* **Not the goal:** Creating a full-blown hardware-compatible kernel (maybe later..)

Currently able to boot [nxdk](https://github.com/XboxDev/nxdk) samples! It'll be
a little while before this can boot a real game.

For this to work you'll need to use a [development branch of
XQEMU](https://github.com/mborgerson/xqemu/tree/khle) which facilitates loading
an XBE.

## What's here

A very basic kernel that will:

* Switch to protected mode
* Enable the serial port, printk
* Barebones device init (PCI, VGA, etc)
* Read the EEPROM
* Use QEMU to load an XBE
* Patch XBE imports with barebones stubs
* Jump to XBE entry point

So far this is not much of a kernel...

Built using some stripped down portions of
[cromwell](https://github.com/XboxDev/cromwell).

## What's needed

High-level list of major things that need to be implemented next:

Core Stuff:
- Proper kernel memory allocator (SLAB, SLOB might be fine)
- Proper virtual memory allocator for title
- Thread/DPC Scheduler
- Interrupt stuff

HLE Interfaces:
- XQEMU HLE File IO
- etc.

Other Kernel things...
- Rtl functions
- Kernel data exports
- Lots of other kernel stuff

## How to build

Standard build tools and NASM are needed, then `make -C src`.

Check out run.sh to see how to use this with XQEMU. Please note that you'll need
the dev branch of XQEMU (mentioned above).