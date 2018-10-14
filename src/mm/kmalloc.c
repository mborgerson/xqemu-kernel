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

/*
 * Simple First-Fit Memory Allocator
 *
 * 00000 +----------------+
 *     | Region Header  |---,
 *     +----------------+<--'
 *     | Alloc 0 Header |---,
 *     +----------------+   |
 *     |                |   |
 *     |                |   |
 *     | Alloc 0 Data   |   |
 *     |                |   |
 *     |                |   |
 *     +----------------+<--'
 *     | Alloc 1 Header |---,
 *     +----------------+   |
 *     |                |   * NULL
 *     | Alloc 1 Data   |
 *     |                |
 *     +----------------+
 *     |                |
 *     | Free Space     |
 *     |                |
 * FFFFF +----------------+
 */

// #include "util.h"
// #include "mem.h"

#include "boot.h"


#define ALLOC_FREE (1<<0)

struct mem_region
{
	size_t                 size;
	struct mem_allocation *head;
};

struct mem_allocation
{
	size_t                 size;
	uint32_t               flags;
	struct mem_allocation *next;
};


struct mem_region *kheap;

struct mem_region *mem_create_region(void *start, size_t size);
void mem_merge_free_allocations(struct mem_region *region);

// extern struct mem_region kernel16_ram_start;
// extern int kernel16_ram_len;

/*
 * Initialize a memory region.
 */
struct mem_region *mem_create_region(void *start, size_t size)
{
	struct mem_region *region;
	size_t overhead;

	overhead = 0;
	overhead += sizeof(struct mem_region);
	overhead += sizeof(struct mem_allocation);

	if (size < overhead)
	{
		/* Region too small. */
		return NULL;
	}

	/* Initialize region struct */
	region = start;
	region->size = size;
	region->head = start + sizeof(struct mem_region);

	/* Initialize first allocation */
	region->head->size  = size - sizeof(struct mem_region);
	region->head->flags = ALLOC_FREE;
	region->head->next  = NULL;
	return region;
}

/*
 * Allocate memory in a region.
 */
void *mem_alloc(struct mem_region *region, size_t size)
{
	struct mem_allocation *cur, *next;

	mem_merge_free_allocations(region);

	/* Include overhead in allocation size */
	size += sizeof(struct mem_allocation);

	/* Ensure dword alignment */
	if (size % 4) size += 4 - size % 4;

	for (cur = region->head; cur != NULL; cur = cur->next)
	{
		/* Check for a fit */
		if ((cur->flags & ALLOC_FREE) == 0) continue;
		if (cur->size < size) continue;

		/* Split the region */
		next = (struct mem_allocation *)((uint8_t *) cur + size);
		next->size  = cur->size - size;
		next->flags = ALLOC_FREE;
		next->next  = cur->next;

		cur->size   = size;
		cur->next   = next;
		cur->flags &= ~ALLOC_FREE;

		/* Return ptr to data */
		return (uint8_t *) cur + sizeof(struct mem_allocation);
	}

	return NULL;
}

/*
 * Free an allocation.
 */
void mem_free(void *ptr)
{
	struct mem_allocation *cur;

	cur = (struct mem_allocation *)((uint8_t *) ptr \
	                                - sizeof(struct mem_allocation));
	cur->flags |= ALLOC_FREE;
}

/*
 * Coalesce free allocations.
 */
void mem_merge_free_allocations(struct mem_region *region)
{
	struct mem_allocation *cur, *next;

	for (cur = region->head; cur != NULL; cur = cur->next)
	{
		if ((cur->flags & ALLOC_FREE) == 0) continue;

		for (next = cur->next; next != NULL; next = cur->next)
		{
			if ((next->flags & ALLOC_FREE) == 0) break;
			cur->size += next->size;
			cur->next  = next->next;
		}
	}
}

/*
 * Initialize low-memory heap.
 */
// int mem_init_low(void)
void MemoryManagementInitialization(void * pvStartAddress, u32 dwTotalMemoryAllocLength)
{
	kheap = mem_create_region(pvStartAddress, dwTotalMemoryAllocLength);
}


void * malloc(size_t size) {
	return mem_alloc(kheap, size);
}

void free(void *ptr) {
	mem_free(ptr);
	mem_merge_free_allocations(kheap);
}
