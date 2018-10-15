xqemu-kernel
============

An open-source Xbox kernel designed for use with XQEMU.

## Introduction

[XQEMU](https://xqemu.com) is a low-level machine emulator, which needs a copy
of the Xbox system software to start and run games. Unfortunately, this system
software cannot be freely distributed due to it being copyrighted material. This
means that in order to run XQEMU, the user must dump the MCPX ROM and TSOP flash
images from their physical Xbox. This, of course, can be a significant barrier
to entry.

Though it as a goal for XQEMU to always maintain compatibility with the official
Xbox system software, it is benificial to have an open-source alternative for
multiple reasons. Firstly, an open-source alternative can be freely distributed
and allow users to easily run XQEMU. Second, it opens the door to additional
performance optimizations, for example: eliminating hardware initialization that
is not strictly necessary for XQEMU, paravirtualization, custom memory
allocation, custom thread scheduling, and more!

**Note:** by design, this project contains no copyrighted code from the official
Xbox kernel.

## Current State

Currently able to boot [nxdk](https://github.com/XboxDev/nxdk) samples! It'll be
a little while before this can boot a real game.

In order to use this kernel, you'll need to use a [development branch of
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
