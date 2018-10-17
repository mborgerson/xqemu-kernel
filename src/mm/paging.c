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

#define PDE_P  (1<<0) // Present
#define PDE_RW (1<<1) // Read/Write
#define PDE_U  (1<<2) // User/Supervisor
#define PDE_W  (1<<3) // Write Through
#define PDE_D  (1<<4) // Cache Disabled
#define PDE_A  (1<<5) // Accessed
#define PDE_S  (1<<7) // Size

#define PTE_P  (1<<0) // Present
#define PTE_RW (1<<1) // Read/Write
#define PTE_U  (1<<2) // User/Supervisor
#define PTE_W  (1<<3) // Write Through
#define PTE_C  (1<<4) // Cache Disabled
#define PTE_A  (1<<5) // Accessed
#define PTE_D  (1<<6) // Dirty
#define PTE_G  (1<<8) // Global

#define PDE_PT_MASK (0xfffff000)
#define PTE_PA_MASK (0xfffff000)

#define addr_to_pfn(x) ((x) >> 22) // One 32b PTE covers 4 KiB

extern unsigned char PDB[];

/*
 * Early initialization of page tables.
 *
 * Called pretty early from assembly code (start.nasm) to set up the address
 * space.
 */
void early_paging_init()
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
		pde[addr_to_pfn(addr)] = (i << 22) | PDE_P | PDE_RW | PDE_U | PDE_S;
	}

	// Map 128M of physical RAM at 0x800000000
	for (i=0; i < 128/4; i++) {
		addr = 0x80000000 + (i << 22);
		pde[addr_to_pfn(addr)] = (i << 22) | PDE_P | PDE_RW | PDE_U | PDE_S;
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
		pde[addr_to_pfn(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_S; // Should be write-combine
	}

	// Other MMIO [0xf8000000, 0xffffffff]
	for (i=0; i < 128/4; i++) {
		addr = 0xf8000000 + (i << 22);
		pde[addr_to_pfn(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_D | PDE_S;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Dumb first-fit page allocator to keep track of contiguous page allocations
// in an arena. This should probably just be replaced with a buddy allocator.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// FIXME: create assert.h file
// #include <assert.h>
#define assert(x) do { \
	if (!(x)) { \
		printf("ASSERTION FAILED %s:%d\n", __FILE__, __LINE__); \
		while(1); \
	} \
} while(0)
#include "list.h"

typedef uint32_t hwaddr;

#define PAGE_BITS 12
#define PAGE_SIZE (1<<PAGE_BITS)

// Memory area
struct mem_arena {
	hwaddr min, max;
	struct list_head h;
};

// Allocation object
struct mem_alloc {
	struct list_head h;
	hwaddr addr;
	size_t len;
};

// Given obj x, return internal list_head*
#define LHEAD(x) (&((x)->h))

// Given list_head*, return parent object
#define LHEAD_PARENT(x) list_entry(x, struct mem_alloc, h)

static inline uint32_t align_up(uint32_t addr, uint32_t alignment)
{
	addr += alignment-1;
	addr &= ~(alignment-1);
	return addr;
}

hwaddr alloc_pages(struct mem_arena *arena, size_t num_pages, size_t alignment);
void free_pages(struct mem_arena *arena, hwaddr addr);
int reserve_pages(struct mem_arena *arena, hwaddr addr, size_t num_pages);


// Find available block of contiguous pages in arena
hwaddr alloc_pages(struct mem_arena *arena, size_t num_pages, size_t alignment)
{
	struct mem_alloc *cur, *after = NULL;

	if (alignment == 0) {
		alignment = PAGE_SIZE;
	}

	hwaddr l = align_up(arena->min, alignment);
	hwaddr r = arena->max;
	int gap, gap_required = num_pages << PAGE_BITS;

	list_for_each_entry(cur, &arena->h, h) {
		// Determine gap between last node and this one
		gap = cur->addr - l;

		if (gap >= gap_required) {
			// Found first fit!
			r = cur->addr;
			break;
		}

		l = cur->addr + ((cur->len + 1) << PAGE_BITS);
		l = align_up(l, alignment);
		after = cur;
		continue;
	}

	// Check bounds
	if ((l + (num_pages << PAGE_BITS)) > r) {
		return 0;
	}

	struct mem_alloc *new = malloc(sizeof(struct mem_alloc));
	new->addr = l;
	new->len = num_pages - 1;
	list_add(LHEAD(new), (after != NULL) ? LHEAD(after) : &arena->h);
	return new->addr;
}

// Free an allocation
void free_pages(struct mem_arena *arena, hwaddr addr)
{
	struct mem_alloc *cur;

	assert((addr & (PAGE_SIZE-1)) == 0);

	list_for_each_entry(cur, &arena->h, h) {
		if (cur->addr == addr) {
			list_del(LHEAD(cur));
			free(LHEAD_PARENT(cur));
			return;
		}
	}

	assert(0); // bad addr!
}

int reserve_pages(struct mem_arena *arena, hwaddr addr, size_t num_pages)
{
	struct mem_alloc *cur, *after = NULL;
	hwaddr l, r;

	l = arena->min;
	r = arena->max;

	printf("reserving %x, %d pages\n", addr, num_pages);

	// List is sorted. Find left-most, non-overlapping block
	list_for_each_entry(cur, &arena->h, h) {
		if (cur->addr > addr) {
			r = cur->addr;
			break;
		}
		l = cur->addr + ((cur->len + 1) << PAGE_BITS);
		after = cur;
	}

	// Check bounds
	printf("l = %x, r = %x\n", l, r);

	if ((addr < l) || ((addr + (num_pages << PAGE_BITS)) > r)) {
		return -1;
	}

	printf("here\n");

	struct mem_alloc *new = malloc(sizeof(struct mem_alloc));
	new->addr = addr;
	new->len = num_pages - 1;
	list_add(LHEAD(new), (after != NULL) ? LHEAD(after) : &arena->h);

	return 0;
}

// Print all allocations in the arena
void xalloc_print(struct mem_arena *arena)
{
	struct mem_alloc *cur;
	list_for_each_entry(cur, &arena->h, h) {
		hwaddr cur_end = cur->addr + ((cur->len + 1) << PAGE_BITS);
		printf("[%08x, %08x)\n", cur->addr, cur_end);
	}
}

////////////////////////////////////////////////////////////////////////////////

#include <sys/types.h>

typedef void *mspace;
static mspace kheap;

mspace create_mspace_with_base(void *base, size_t capacity, int locked);
void *mspace_malloc(mspace msp, size_t bytes);
void mspace_free(mspace msp, void *mem);

struct mem_arena phys_arena; // Keeps track of physical memory
struct mem_arena virt_arena; // Keeps track of virtual memory (0-128MiB addrs)

extern char KRESERVED_START[];
extern char KRESERVED_SIZE[];

static inline void *virt_to_phys(void *virt)
{
	return (void*)((uint32_t)virt & 0x7fffffff);
}

#include "memory_layout.h"

void MemoryManagementInitialization(void * pvStartAddress, u32 dwTotalMemoryAllocLength)
{
	// Initialize initial statically-allocated heap
	kheap = create_mspace_with_base(pvStartAddress, dwTotalMemoryAllocLength, 0);

	xbox_ram = 128;

	// Set up page allocator
	INIT_LIST_HEAD(&phys_arena.h);
	phys_arena.min = 0;
	phys_arena.max = xbox_ram * 1024 * 1024;

	INIT_LIST_HEAD(&virt_arena.h);
	virt_arena.min = 0;
	virt_arena.max = 128 * 1024 * 1024;

	// Reserve the 0 page
	reserve_pages(&phys_arena, 0, 1);


	printk("Early MMAP:\n");
	xalloc_print(&phys_arena);

	// Reserve pre-allocated kernel pages (.data/.bss)
	reserve_pages(&phys_arena, (hwaddr)virt_to_phys(KRESERVED_START), (uint32_t)KRESERVED_SIZE >> PAGE_BITS);


	printk("Early MMAP:\n");
	xalloc_print(&phys_arena);

	// Reserve framebuffer area
	reserve_pages(&phys_arena, phys_arena.max - FB_SIZE, FB_SIZE >> PAGE_BITS);
	
	// TEMP: Reserve 1 MiB range at 0x10000 where XBE is loaded
	reserve_pages(&phys_arena, 0x10000, 0x100);

	printk("Early MMAP:\n");
	xalloc_print(&phys_arena);

	// Enable page allocator
	// ...
}

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	printk("mmap(%x, %x, %x, %x, %x, %x)\n",
		addr, length, prot, flags, fd, offset);
	printk("mmap page allocator not ready yet!\n");
	abort();
	return NULL;
}

int munmap(void *addr, size_t length)
{
	printk("munmap(%x, %x)\n", addr, length);
	return 0;
}

void *malloc(size_t bytes)
{
	return mspace_malloc(kheap, bytes);
}

void free(void *ptr)
{
	mspace_free(kheap, ptr);
}




#include "xdecl.h"

/**
 * MmAllocateContiguousMemoryEx
 */
XBAPI PVOID NTAPI
MmAllocateContiguousMemoryEx(
	SIZE_T    NumberOfBytes,
	ULONG_PTR LowestAcceptableAddress,
	ULONG_PTR HighestAcceptableAddress,
	ULONG_PTR Alignment,
	ULONG     Protect
	)
{
	printk("MmAllocateContiguousMemoryEx(%x, %x, %x, %x, %x) = ",
		NumberOfBytes,
		LowestAcceptableAddress,
		HighestAcceptableAddress,
		Alignment,
		Protect);
	uint32_t xbe_mem = alloc_pages(&phys_arena,
		align_up(NumberOfBytes, PAGE_SIZE) >> PAGE_BITS,
		Alignment);
	xbe_mem |= 0x80000000;
	printk("%x\n", xbe_mem);
	return (PVOID)xbe_mem;
}
