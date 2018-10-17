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

// A very dumb memory allocator
//-----------------------------------------------------------------------------

// Let the XBE allocate memory starting at 1M
uint32_t alloc_ptr = 0x100000;

static inline uint32_t align_up(uint32_t addr, uint32_t alignment)
{
	addr += alignment-1;
	addr &= ~(alignment-1);
	return addr;
}

uint32_t dumb_valloc(uint32_t size, uint32_t alignment)
{

	if (alignment != 0) {
		// Align to desired alignment
		alloc_ptr = align_up(alloc_ptr, alignment);
	}

	// Allocate the memory
	uint32_t xbe_mem = alloc_ptr;
	alloc_ptr += size;

	// Align up to page boundary
	alloc_ptr = align_up(alloc_ptr, 0x1000);

	return xbe_mem;
}
