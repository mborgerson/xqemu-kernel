/*
 * Copyright (C) 2018 Matt Borgerson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

ENTRY(start_16)

MEMORY
{
    ROM   (RX) : ORIGIN = (4096M-1M),   LENGTH = 1M,
    PRAM  (RW) : ORIGIN = 0,            LENGTH = 128M,
    RAM   (RW) : ORIGIN = 0x80000000,   LENGTH = 128M,
    KRAM  (RW) : ORIGIN = 0x83010000,   LENGTH = 16K
}

EARLY_STACK_END = 0x100000;
PDB = 0xf000;

ROM_BASE = ORIGIN(ROM);
ROM_SIZE = LENGTH(ROM);
ROM_END  = ROM_BASE + ROM_SIZE;

RESET_VECTOR_BLOCK_SIZE = 64;
RESET_VECTOR_BLOCK_BASE = ROM_END - RESET_VECTOR_BLOCK_SIZE;

SECTIONS
{
    .text : {
        *(.text*)
    } >ROM = 0xff

    .rodata : {
        . = ALIGN(4);
        *(.rodata*)
    } >ROM = 0xff

    .data : {
        . = ALIGN(4K);
        KRESERVED_START = .;
        DATA_BASE = .;

        *(.data*)

        BYTE(0xFF)
        . = ALIGN(0x10);

        DATA_END = .;
    } >KRAM AT>ROM = 0x00

    .bss (NOLOAD) : {
        . = ALIGN(4K);

        HEAP_BASE = .;
        . += 4K;
        HEAP_END = .;

        BSS_BASE = .;
        *(.bss COMMON)
        BSS_END = .;
    } >KRAM

    .stack (NOLOAD) : {
        . = ALIGN(4K);
        STACK_BASE = .;
        . += 4K;
        STACK_END = .;

        KRESERVED_END = .;
    } >KRAM

    .fill : {
        FREE_ROM_BASE = .;
        . = ORIGIN(ROM) + LENGTH(ROM) - RESET_VECTOR_BLOCK_SIZE - 1;
        BYTE(0xff);
        FREE_ROM_END = .;
    } >ROM = 0xff

    .reset_vector (RESET_VECTOR_BLOCK_BASE) : {
        *(.reset_vector*)
    } >ROM = 0xff

    /DISCARD/ : {
        *(.comment)
        *(.note.GNU-stack)
        *(.eh_frame)
        *(.rela.eh_frame)
        *(.shstrtab)
        *(.symtab)
        *(.strtab)
        *(.got.plt)
    }
}

DATA_LOAD = LOADADDR(.data);
DATA_SIZE = DATA_END - DATA_BASE;
DATA_SIZE_L = DATA_SIZE / 4;

BSS_SIZE = BSS_END - BSS_BASE;
BSS_SIZE_L = BSS_SIZE / 4;

HEAP_SIZE = HEAP_END - HEAP_BASE;

STACK_SIZE = STACK_END - STACK_BASE;
FREE_ROM_SIZE = FREE_ROM_END - FREE_ROM_BASE;


KRESERVED_SIZE = KRESERVED_END - KRESERVED_START;
