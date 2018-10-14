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

#include "boot.h"

#define SERIAL_PORT 0x3f8
#define SERIAL_THR 0
#define SERIAL_LSR 5

void serial_init()
{
    IoOutputByte(0x2e, 0x55); /* Enter Configuration */

    /* Select serial device */
    IoOutputByte(0x2e, 0x07);
    IoOutputByte(0x2f, 0x04);

    /* Enable device */
    IoOutputByte(0x2e, 0x30);
    IoOutputByte(0x2f, 0x01);

    /* Set Serial Base = 0x3f8 */
    IoOutputByte(0x2e, 0x61);
    IoOutputByte(0x2f, SERIAL_PORT & 0xff);

    IoOutputByte(0x2e, 0x60);
    IoOutputByte(0x2f, SERIAL_PORT >> 8);

    IoOutputByte(0x2e, 0xAA); /* Exit Configuration */
}

int serial_putchar(int ch)
{
    /* Wait for THRE (bit 5) to be high */
    while ((IoInputByte(SERIAL_PORT + SERIAL_LSR) & (1<<5)) == 0);
    IoOutputByte(SERIAL_PORT + SERIAL_THR, ch);
    return ch;
}
