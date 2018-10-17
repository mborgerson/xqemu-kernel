;
; Copyright (C) 2018 Matt Borgerson
;
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.
;
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
;
; You should have received a copy of the GNU General Public License along
; with this program; if not, write to the Free Software Foundation, Inc.,
; 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
;

global start_16
extern PDB
extern EARLY_STACK_END
extern STACK_END
extern BSS_SIZE_L
extern BSS_BASE
extern DATA_SIZE_L
extern DATA_BASE
extern DATA_LOAD

extern early_paging_init
extern init

%macro WR_MSR 3 ; addr, hi, lo
    mov ecx, %1
    mov edx, %2
    mov eax, %3
    wrmsr
%endmacro

;
;
; Protected Mode Entry - Early system init before jumping to C code
;
;

section .text
bits 32

start_32:
    ; Setup Segment Selectors
    xor eax, eax
    mov al, GDT_DATA_SEL
    mov ds, eax
    mov ss, eax
    mov es, eax
    xor eax, eax
    mov fs, eax
    mov gs, eax

    ;
    ; Initialize MTRRs
    ;

    WR_MSR 0x2ff, 0, 0

    ; 0 +128M WB (RAM)
    WR_MSR 0x200, 0x00000000, 0x00000006 ; Base
    WR_MSR 0x201, 0x0000000f, 0xf8000800 ; Mask

    ; 0xf0000000 +128M WC (VRAM)
    WR_MSR 0x202, 0x00000000, 0xf0000001 ; Base
    WR_MSR 0x203, 0x0000000f, 0xf8000800 ; Mask

    ; 0xfff00000 +1M WP (Flash)
    WR_MSR 0x204, 0x00000000, 0xfff00005 ; Base
    WR_MSR 0x205, 0x0000000f, 0xfff00800 ; Mask

    ; Clear other MTTRs
    xor eax, eax
    xor edx, edx
    mov ecx, 0x206
.clear:
    wrmsr
    inc cl
    cmp cl, 0x0f
    jbe .clear

    ; Enable MTRRs
    WR_MSR 0x2ff, 0x00000000, 0x00000800

    ; Enable Caching
    mov eax, cr0
    and eax,0x9fffffff
    mov cr0, eax

    ;
    ; Initialize Page Tables
    ;

    mov esp, EARLY_STACK_END
    call early_paging_init

    mov eax, PDB                       ; Load Page Directory
    mov cr3, eax

    mov eax, cr4                       ; Enable PSE (4 MiB pages)
    or  eax, 0x10
    mov cr4, eax

    mov eax, cr0                       ; Enable Paging
    or  eax, 0x80000000
    mov cr0, eax

    ; Setup stack
    mov esp, STACK_END

    ; Clear out .bss
    xor eax, eax
    mov ecx, BSS_SIZE_L
    mov edi, BSS_BASE
    rep stosd

    ; Load .data
    mov ecx, DATA_SIZE_L
    mov edi, DATA_BASE
    mov esi, DATA_LOAD
    rep movsd

    ; Enable Floating Point
    mov eax, cr4                       ; Enable SSE and SSE exceptions
    or  eax, (1<<9 | 1<<10)
    mov cr4, eax
    clts
    fninit

    ; Jump to C init code
    jmp init

;
;
; Initial 16-bit x86 Boot Block
;
;

section .reset_vector
%define RB_SIZE 64                     ; Fixed size of this reset vector block

;
; x86 Global Descriptor Table (GDT)
;

align 0x10
gdt:
    GDT_NULL_SEL equ $-gdt             ; Null Segment
    dq 0                               ;   Invalid

    GDT_CODE_SEL equ $-gdt             ; Code Segment
    dq 0x00cf9b000000ffff              ;   [0-ffffffff], Ring 0, R/X

    GDT_DATA_SEL equ $-gdt             ; Data Segment
    dq 0x00cf93000000ffff              ;   [0-ffffffff], Ring 0, R/W

    GDT_SIZE equ $-gdt

gdt_desc:
    dw GDT_SIZE-1
    dd gdt

    times RB_SIZE-32-($-$$) db 0x90    ; Pad up to Reset Vector

;
; x86 Reset Vector (start of execution)
;

bits 16

_switch_to_protected_mode:
    mov eax, cr0                       ; Enable "Protected Mode"
    or  al, 1                          ;   - Bit 0: Protected Mode Enable
    mov cr0, eax                       ;
    jmp dword GDT_CODE_SEL:start_32    ; Far jump to complete switch

    times RB_SIZE-16-($-$$) db 0x90    ; Pad up to Reset Vector

start_16:                              ; ** Entry point **
    cli                                ; Disable interrupts
    o32 lgdt [cs:gdt_desc]             ; Load 32-bit GDT
    jmp _switch_to_protected_mode
    times start_16+16-$ db 0x90        ; Pad up to 16 byte boundary
