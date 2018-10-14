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

void init_paging()
{
	volatile unsigned int *pde = (unsigned int *)PDB;
	unsigned int i, addr;

	// Zero out PDE
	for (i = 0; i < 1024; i++) {
		pde[i] = 0;
	}

	// Identity Map 128M of physical RAM for now
	// FIXME: Replace with allocator
	for (i=0; i < 128/4; i++) {
		addr = 0x00000000 + (i << 22);
		pde[ADDR_TO_PTE_INDEX(addr)] = (i << 22) | PDE_P | PDE_RW | PDE_U | PDE_S;
	}

	// Map 128M of physical RAM at 0x800000000
	for (i=0; i < 128/4; i++) {
		addr = 0x80000000 + (i << 22);
		pde[ADDR_TO_PTE_INDEX(addr)] = (i << 22) | PDE_P | PDE_RW | PDE_U | PDE_S;
	}

	// Not sure about c0XXXXXX
	//   c0000000 ->  be000
	//   c010XXXX -> 3ffXXX
	//   c0300000 ->   f000
	//   c03c0000 -> f0000000
	//   c03c1000 -> f0400000
	//   c03c2000 -> f0800000
	//   ...
	// Not sure about d00XXXXX (maps to low mem)

	// -> jfr: 0xC0000000 is the block used for MmIoMapSpace etc - so various
	// mappings to hardware. and 0xD0000000 is the block used for kernel pools
	// iirc [ExAllocatePool]

	// Identity map MMIO
	//   mem at 0xf0000000 [0xf3ffffff] // (nv2a, bar 1)
	//   mem at 0xfd000000 [0xfdffffff] // (nv2a, bar 0)
	//   mem at 0xfe800000 [0xfe87ffff] // (apu, bar 0)
	//   mem at 0xfec00000 [0xfec00fff] // (aci, bar 2)
	//   mem at 0xfed00000 [0xfed000ff] // (ohci, bar 0)
	//   mem at 0xfed08000 [0xfed080ff] // (ohci, bar 0)
	//   mem at 0xfef00000 [0xfef003ff] // (nvnet, bar 0)

	// GPU MEM [0xf0000000, 0xf8000000)
	for (i=0; i < 128/4; i++) {
		addr = 0xf0000000 + (i << 22);
		pde[ADDR_TO_PTE_INDEX(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_S; // Should be write-combine
	}

	// Other MMIO [0xf8000000, 0xffffffff]
	for (i=0; i < 128/4; i++) {
		addr = 0xf8000000 + (i << 22);
		pde[ADDR_TO_PTE_INDEX(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_D | PDE_S;
	}
}
