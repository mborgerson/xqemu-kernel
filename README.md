xqemu-kernel
============

An open-source Xbox kernel alternative, designed for use with XQEMU.

![Build Status](https://travis-ci.org/mborgerson/xboxkrnl.svg?branch=master)

## Introduction

[XQEMU](https://xqemu.com) is a low-level machine emulator, which needs a copy
of the Xbox system software to start and run games. Unfortunately, this system
software cannot be freely distributed due to it being copyrighted material. This
means that in order to run XQEMU, the user must dump the MCPX ROM and TSOP flash
images from their own physical Xbox. This, of course, can be a significant
barrier to entry for many users.

Though it is a goal for XQEMU to continue to maintain compatibility with the
official Xbox system software, it is benificial to also have an open-source
alternative path for multiple reasons, namely licensing and performance
optimizations. Fortunately, the interface between title and the kernel (API) is
simple, clean, and largely documented and can therefore be implemented by an
open-source alternative kernel, maintaining binary compatibility with
unmodified title code.

**Please note:** by design, this project contains no copyrighted code from the
official Xbox kernel.

## Current State

Currently able to boot [nxdk](https://github.com/XboxDev/nxdk) samples with full
3D graphics! It'll be a little while before this can boot a real game.

In order to use this kernel, you'll need to use a [development branch of
XQEMU](https://github.com/mborgerson/xqemu/tree/khle) which facilitates loading
an XBE.

## What's Here

A very basic kernel that will:

* Switch to protected mode
* Enable the serial port (`printk`)
* Perform barebones device init (PCI, VGA, etc)
* Read the EEPROM
* Poke XQEMU to load an XBE into memory
* Patch XBE imports with stub functions
* Jump to XBE entry point
* Handle a handful of kernel function calls

## What's Needed

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

## Getting Started

### How to Build
Standard build tools and NASM are needed, then `make -C src`.

### How to Run
Check out run.sh to see how to use this with XQEMU. Please note that you'll need
the dev branch of XQEMU (mentioned above). Also note that you should **not**
provide a `bootrom` image when running this kernel.
