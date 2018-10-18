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
#include "memory_layout.h" // FIXME: Factor this out


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

#define DEBUG_PAGING 1
#if DEBUG_PAGING
#define DPRINTK printk
#else
#define DPRINTK(...) do {} while(0)
#endif

typedef uint32_t hwaddr;

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

#define PAGE_BITS 12
#define PAGE_SIZE (1<<PAGE_BITS)

#define addr_to_pdn(x) ((x) >> 22) // One 32b PDE covers 4 MiB
#define addr_to_pfn(x) ((x) >> PAGE_BITS) // One 32b PTE covers 4 KiB

extern unsigned char PDB[];
extern int32_t page_tables[];

// Statically allocated kernel memory
extern char KRESERVED_START[];
extern char KRESERVED_SIZE[];

static inline void *phys_to_virt(void *phys)
{
	return (void*)((uint32_t)phys | 0x80000000);
}

static inline void *virt_to_phys(void *virt)
{
	return (void*)((uint32_t)virt & 0x7fffffff);
}

/*
 * Early initialization of page tables.
 *
 * Called pretty early from assembly code (start.nasm) to set up the address
 * space. Keep in mind that this runs out of physical memory (kernel data
 * and BSS not initialized yet)!
 */
void early_paging_init()
{
	volatile unsigned int *pde = (unsigned int *)PDB;
	unsigned int i, addr;

	// Zero out PDE
	for (i = 0; i < 1024; i++) {
		pde[i] = 0;
	}

	// Map 128M of virtual address space page tables into PD
	for (i=0; i < 128/4; i++) {
		// One 4 KiB page covers 4 MiB of addresses
		addr = (uint32_t)virt_to_phys(page_tables) + (i << PAGE_BITS);
		pde[i] = addr | PDE_P | PDE_RW | PDE_U | PDE_A;
	}

	// Map 128M of physical RAM at 0x800000000
	for (i=0; i < 128/4; i++) {
		addr = 0x80000000 + (i << 22);
		pde[addr_to_pdn(addr)] = (i << 22) | PDE_P | PDE_RW | PDE_U | PDE_S;
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
		pde[addr_to_pdn(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_S; // Should be write-combine
	}

	// Other MMIO [0xf8000000, 0xffffffff]
	for (i=0; i < 128/4; i++) {
		addr = 0xf8000000 + (i << 22);
		pde[addr_to_pdn(addr)] = addr | PDE_P | PDE_RW | PDE_U | PDE_D | PDE_S;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Dumb first-fit page allocator to keep track of contiguous page allocations
// in an arena. This should probably just be replaced with a buddy allocator.

struct mem_arena {
	hwaddr min, max;
	struct list_head h;
};

struct mem_alloc {
	struct list_head h;
	hwaddr addr;
	size_t len;
};

// Given obj x, return internal list_head*
#define LHEAD(x) (&((x)->h))

hwaddr alloc_pages(struct mem_arena *arena, size_t num_pages, size_t alignment);
void free_pages(struct mem_arena *arena, hwaddr addr);
int reserve_pages(struct mem_arena *arena, hwaddr addr, size_t num_pages);

/*
 * Find available block of contiguous pages in arena
 */
hwaddr alloc_pages(struct mem_arena *arena, size_t num_bytes, size_t alignment)
{
	struct mem_alloc *cur, *after = NULL;
	ssize_t gap;

	if (alignment == 0) {
		alignment = PAGE_SIZE;
	}

	num_bytes = align_up(num_bytes, PAGE_SIZE);
	hwaddr limit_l = align_up(arena->min, alignment);
	hwaddr limit_u = arena->max;

	// List is sorted. Step through each node, compare space between it and last
	list_for_each_entry(cur, &arena->h, h) {
		gap = cur->addr - limit_l;

		// Check gap. Note: cast here as compiler would otherwise cast
		// `gap` to unsigned and not handle negatives correctly!
		if (gap >= (ssize_t)num_bytes) {
			// Found first fit!
			limit_u = cur->addr;
			break;
		}

		limit_l = cur->addr + ((cur->len + 1) << PAGE_BITS);
		limit_l = align_up(limit_l, alignment);
		after = cur;
	}

	// Check bounds
	if ((limit_l + num_bytes) > limit_u) {
		return 0;
	}

	struct mem_alloc *new = malloc(sizeof(struct mem_alloc));
	new->addr = limit_l;
	new->len = (num_bytes >> PAGE_BITS) - 1;
	list_add(LHEAD(new), (after != NULL) ? LHEAD(after) : &arena->h);
	return new->addr;
}

/*
 * Reserve a range of addresses in the arena
 */
int reserve_pages(struct mem_arena *arena, hwaddr addr, size_t num_bytes)
{
	struct mem_alloc *cur, *after = NULL;
	hwaddr limit_l = arena->min;
	hwaddr limit_u = arena->max;

	num_bytes = align_up(num_bytes, PAGE_SIZE);

	// List is sorted. Find left-most, non-overlapping block
	list_for_each_entry(cur, &arena->h, h) {
		if (cur->addr > addr) {
			limit_u = cur->addr;
			break;
		}
		limit_l = cur->addr + ((cur->len + 1) << PAGE_BITS);
		after = cur;
	}

	// Check bounds
	if ((addr < limit_l) || ((addr + num_bytes) > limit_u)) {
		return -1;
	}

	struct mem_alloc *new = malloc(sizeof(struct mem_alloc));
	new->addr = addr;
	new->len = (num_bytes >> PAGE_BITS) - 1;
	list_add(LHEAD(new), (after != NULL) ? LHEAD(after) : &arena->h);

	return 0;
}

/*
 * Free an allocation
 */
void free_pages(struct mem_arena *arena, hwaddr addr)
{
	struct mem_alloc *cur;

	list_for_each_entry(cur, &arena->h, h) {
		if (cur->addr == addr) {
			list_del(LHEAD(cur));
			free(cur);
			return;
		}
	}

	assert(0); // bad addr!
}

/*
 * Print all allocations in the arena
 */
void print_allocations(struct mem_arena *arena)
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


void MemoryManagementInitialization(void * pvStartAddress, u32 dwTotalMemoryAllocLength)
{
	// Initialize statically-allocated heap
	// FIXME: should grow on-demand, but malloc depends on the page allocator, which depends on malloc
	kheap = create_mspace_with_base(pvStartAddress, dwTotalMemoryAllocLength, 0);

	xbox_ram = 128; // FIXME: Not set yet, must set it ourselves for now

	// Set up page allocator
	INIT_LIST_HEAD(&phys_arena.h);
	phys_arena.min = 0;
	phys_arena.max = xbox_ram * 1024 * 1024;

	INIT_LIST_HEAD(&virt_arena.h);
	virt_arena.min = 0;
	virt_arena.max = 128 * 1024 * 1024;

	// Reserve 0-0x10000
	reserve_pages(&phys_arena, 0, 0x10000);
	reserve_pages(&virt_arena, 0, 0x10000);

	// Reserve pre-allocated kernel pages (.data/.bss)
	reserve_pages(&phys_arena, (hwaddr)virt_to_phys(KRESERVED_START), (size_t)KRESERVED_SIZE);

	// Reserve framebuffer area
	reserve_pages(&phys_arena, phys_arena.max - FB_SIZE, FB_SIZE);
	
	// TEMP: Reserve 1 MiB range at 0x10000 where XBE is loaded
	reserve_pages(&phys_arena, 0x10000, 0x100000);

#if DEBUG_PAGING
	printk("Early MMAP:\n");
	print_allocations(&phys_arena);
#endif

	// Identity map the PD
	uint32_t addr;
	addr = (uint32_t)PDB;
	page_tables[addr_to_pfn(addr)] = addr | PTE_P | PTE_RW | PTE_U | PTE_A;
}

////////////////////////////////////////////////////////////////////////////////
// Pool allocation helpers

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

////////////////////////////////////////////////////////////////////////////////
// Finally, our contiguous and virtual memory allocation

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
	DPRINTK("MmAllocateContiguousMemoryEx(%x, %x, %x, %x, %x) = ",
		NumberOfBytes,
		LowestAcceptableAddress,
		HighestAcceptableAddress,
		Alignment,
		Protect);
	uint32_t xbe_mem = alloc_pages(&phys_arena, NumberOfBytes, Alignment);
	if (xbe_mem == 0) {
		printk("alloc failed!\n");
		abort();
	}
	xbe_mem |= 0x80000000;
	DPRINTK("%x\n", xbe_mem);
	return (PVOID)xbe_mem;
}

/**
 * NtAllocateVirtualMemory
 */
XBAPI NTSTATUS NTAPI
NtAllocateVirtualMemory(
	PPVOID    BaseAddress,
	ULONG_PTR ZeroBits,
	PSIZE_T   RegionSize,
	ULONG     AllocationType,
	ULONG     Protect
	)
{
	DPRINTK("NtAllocateVirtualMemory(%x, %x, %x, %x, %x)\n",
		BaseAddress,
		ZeroBits,
		RegionSize,
		AllocationType,
		Protect);

	assert(BaseAddress != NULL);
	assert(ZeroBits == 0); // FIXME: if (ZeroBits < 32) { # high order zero bits } else { bitmask }
	assert(RegionSize != NULL);

	// Let's first try to allocate some memory from physical address space
	// FIXME: allocating contiguously here for now, should support getting
	// smaller chunks too...
	size_t num_bytes = align_up(*RegionSize, PAGE_SIZE);
	uint32_t phys_mem = alloc_pages(&phys_arena, num_bytes, 0 /* FIXME */);
	assert(phys_mem != 0);

	hwaddr virt_mem = (hwaddr)*BaseAddress;
	DPRINTK("  *BaseAddress = %x\n", virt_mem);

	if (virt_mem == 0) {
		// Try to allocate from virtual memory
		virt_mem = alloc_pages(&virt_arena, num_bytes, 0 /* FIXME */);
		assert(virt_mem != 0);
	} else {
		// Specific address requested, try to reserve it
		int status = reserve_pages(&virt_arena, virt_mem, num_bytes);
		assert(status == 0);
	}

	// Now map the virtual memory to physical memory
	unsigned int i;
	for (i=0; i < (num_bytes >> PAGE_BITS); i++) {
		hwaddr vaddr = virt_mem + (i << PAGE_BITS);
		hwaddr paddr = phys_mem + (i << PAGE_BITS);
		DPRINTK("  %x -> %x\n", vaddr, paddr);
		page_tables[addr_to_pfn(vaddr)] = paddr | PTE_P | PTE_RW | PTE_U | PTE_A;
		asm volatile ("invlpg (%%eax);" : : "a" (vaddr)); // Update TLB
	}

	*BaseAddress = (void*)virt_mem;
	*RegionSize = num_bytes;
}

/**
 * NtFreeVirtualMemory
 */
XBAPI NTSTATUS NTAPI
NtFreeVirtualMemory(
	PPVOID  BaseAddress,
	PSIZE_T RegionSize,
	ULONG   FreeType
	)
{
	assert(0);
}
