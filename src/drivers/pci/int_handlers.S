/*
 *
 *  BIOS ROM Startup Assembler
 */

 /***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "consts.h"
#include "memory_layout.h"


        .code32

.section .text, "ax"

///////////////////////////////////////////
//
//  Interrupt Service Routines
//


                .global IntHandlerTimer0
IntHandlerTimer0:
        cli
        pusha
        pushf
        call    IntHandlerCTimer0
        mov     $0x20, %al
        outb    %al, $0x20
        popf
//      sti
        popa
        iret


                .global IntHandler1
IntHandler1:
        pusha
        pushf
        cli
        call    IntHandler1C
        mov     $0x21, %al
        outb    %al, $0x20
        popf
//      sti
        popa
        iret


                .global IntHandler2
IntHandler2:
        cli
        pusha
        pushf
        call    IntHandler2C
        mov     $0x22, %al
        outb    %al, $0x20
        popf
        popa
//      sti
        iret



                .global IntHandler3
IntHandler3:
        cli
        pusha
        pushf
        call    IntHandler3VsyncC
        mov     $0x23, %al
        outb    %al, $0x20
        popf
        popa
//      sti
        iret


                .global IntHandler4
IntHandler4:
        cli
        pusha
        pushf
        call    IntHandler4C
        mov     $0x24, %al
        outb    %al, $0x20
        popf
        popa
//      sti
        iret


                .global IntHandler5
IntHandler5:
        cli
        pusha
        pushf
        call    IntHandler5C
        mov     $0x25, %al
        outb    %al, $0x20
        popf
        popa
//      sti
        iret


                .global IntHandler6
IntHandler6:
        cli
        pusha
        pushf
        call    IntHandler6C
        mov     $0x26, %al
        outb    %al, $0x20
        popf
        popa
        sti
        iret



                .global IntHandler7
IntHandler7:
        cli
        pusha
        pushf
        call    IntHandler7C
        mov     $0x27, %al
        outb    %al, $0x20
        popf
        popa
        sti
        iret



        .global IntHandler8
IntHandler8:
        cli
        pusha
        pushf
        call    IntHandler8C
                // EOI on master and slave needed
        mov     $0x60, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret




        .global IntHandler9
IntHandler9:
        pusha
        pushf
        cli
        call    IntHandler9C
                // EOI on master and slave needed
        mov     $0x61, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

                // Int 10 interrupts

        .global IntHandler10
IntHandler10:
        pusha
        pushf
        cli
        call    IntHandler10C
                // EOI on master and slave needed
        mov     $0x62, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

                // Int 11 interrupts

        .global IntHandlerI2C
IntHandlerI2C:
        pusha
        pushf
        cli
        call    IntHandlerCI2C

                // EOI on master and slave needed
        mov     $0x63, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

                // Int 12 interrupts

        .global IntHandlerSmc
IntHandlerSmc:
        cli
        pusha
        pushf

        call    IntHandlerCSmc

                // acknowledge EXTSMI# action (from PIC p6)

        mov     $0x8020, %dx
        inw %dx, %ax
        or $0x0200, %ax
        outw    %ax, %dx

                // EOI on master and slave needed
        mov     $0x64, %al // is int12
        out     %al, $0xa0
        mov     $0x62, %al // do cascaded master
        out     %al, $0x20
        popf
        popa
        iret

                // Int 13 interrupts

        .global IntHandler13
IntHandler13:
        cli
        pusha
        pushf

        call    IntHandler13C
                // EOI on master and slave needed
        mov     $0x65, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

                        // Int 14 interrupts

        .global IntHandlerIde
IntHandlerIde:
        cli
        pusha
        pushf

        call    IntHandlerCIde

                // EOI on master and slave needed
        mov     $0x66, %al // was $0x20
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

                // Int 15 interrupts

        .global IntHandler15
IntHandler15:
        cli
        pusha
        pushf

        call    IntHandler15C
                // EOI on master and slave needed
        mov     $0x67, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret


                // unused interrupts on master PIC

        .global IntHandlerUnused
IntHandlerUnused:
        cli
        pusha
        pushf

        call    IntHandlerUnusedC
        mov     $0x20, %al
        out     %al, $0x20
        popf
        popa
        iret

                // unused interrupts on slave PIC

        .global IntHandlerUnusedPic2
IntHandlerUnusedPic2:
        cli
        pusha
        pushf

        call    IntHandlerUnusedC2
        mov $0xffff, %ax
        mov     $0x8028, %dx
        outw    %ax, %dx
        mov     $0x80cc, %dx
        mov     $0x40, %al
        outb    %al, %dx

        mov     $0x20, %al
        out     %al, $0xa0
        mov     $0x62, %al
        out     %al, $0x20
        popf
        popa
        iret

        .global SpareIntNop
SpareIntNop:
        iret


                // CPU Exception Interrupts

        .global IntHandlerException0
IntHandlerException0:
        pusha
        pushf
        cli
        call    IntHandlerException0C
        popf
        popa
        iret

        .global IntHandlerException1
IntHandlerException1:
        pusha
        pushf
        cli
        call    IntHandlerException1C
        popf
        popa
        iret

        .global IntHandlerException2
IntHandlerException2:
        pusha
        pushf
        cli
        call    IntHandlerException2C
        popf
        popa
        iret

        .global IntHandlerException3
IntHandlerException3:
        pusha
        pushf
        cli
        call    IntHandlerException3C
        popf
        popa
        iret

        .global IntHandlerException4
IntHandlerException4:
        pusha
        pushf
        cli
        call    IntHandlerException4C
        popf
        popa
        iret

        .global IntHandlerException5
IntHandlerException5:
        pusha
        pushf
        cli
        call    IntHandlerException5C
        popf
        popa
        iret

        .global IntHandlerException6
IntHandlerException6:
        pusha
        pushf
        cli
        call    IntHandlerException6C
        popf
        popa
        iret

        .global IntHandlerException7
IntHandlerException7:
        pusha
        pushf
        cli
        call    IntHandlerException7C
        popf
        popa
        iret

        .global IntHandlerException8
IntHandlerException8:
        pusha
        pushf
        cli
        call    IntHandlerException8C
        popf
        popa
        iret

        .global IntHandlerException9
IntHandlerException9:
        pusha
        pushf
        cli
        call    IntHandlerException9C
        popf
        popa
        iret

        .global IntHandlerExceptionA
IntHandlerExceptionA:
        pusha
        pushf
        cli
        call    IntHandlerExceptionAC
        popf
        popa
        iret

        .global IntHandlerExceptionB
IntHandlerExceptionB:
        pusha
        pushf
        cli
        call    IntHandlerExceptionBC
        popf
        popa
        iret

        .global IntHandlerExceptionC
IntHandlerExceptionC:
        pusha
        pushf
        cli
        call    IntHandlerExceptionCC
        popf
        popa
        iret

        .global IntHandlerExceptionD
IntHandlerExceptionD:
        pusha
        pushf
        cli
        call    IntHandlerExceptionDC
        popf
        popa
        iret

        .global IntHandlerExceptionE
IntHandlerExceptionE:
        pusha
        pushf
        cli
        call    IntHandlerExceptionEC
        popf
        popa
        iret

        .global IntHandlerExceptionF
IntHandlerExceptionF:
        pusha
        pushf
        cli
        call    IntHandlerExceptionFC
        popf
        popa
        iret

        .global IntHandlerException10
IntHandlerException10:
        pusha
        pushf
        cli
        call    IntHandlerException10C
        popf
        popa
        iret





