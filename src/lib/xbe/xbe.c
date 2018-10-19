#include "xbe.h"

// Kernel Import Table
//-----------------------------------------------------------------------------


#include "xdecl.h"

void *m_import_addrs[400] = {
#define KERNEL_IMPORT_NULL(i) [i] = 0,
#define KERNEL_IMPORT_FUNC(i, n) [i] = &n,
#define KERNEL_IMPORT_DATA(i, n) [i] = (void*)(0xfed0c030+i), // FIXME
#include "ximports.h"
KERNEL_IMPORTS
#undef KERNEL_IMPORT_NULL
#undef KERNEL_IMPORT_FUNC
#undef KERNEL_IMPORT_DATA
};

uint32_t xbe_unscramble(uint32_t addr, uint32_t debug, uint32_t retail)
{
    uint32_t addr_out;

    #define XBOX_RAM_SIZE (64*0x100000)

    addr_out = addr ^ retail;
    if (addr_out < XBOX_RAM_SIZE) {
        return addr_out;
    }

    return addr ^ debug;
}

void xbe_patch_imports(XBE_HEADER *hdr)
{
    // Patch Kernel Imports
    volatile uint32_t *imports = (volatile uint32_t*)xbe_unscramble(hdr->KernelThunkTable, XOR_KT_DEBUG, XOR_KT_RETAIL);
    for (int i = 0; imports[i] != 0; i++) {
        uint32_t import_num = imports[i] - 0x80000000;
        // assert(import_num < 379);
        imports[i] = (uint32_t)m_import_addrs[import_num];
    }
}

#include "boot.h"

XBE_HEADER *load_xbe(char *xbe_data)
{
    XBE_HEADER *header = (XBE_HEADER *)xbe_data;

    if (strncmp((char*)header->Magic, "XBEH", 4) != 0) {
        printf("Invalid Magic!\n");
        while (1);
    }

    printf("Base Address: %x\n", header->BaseAddress);

    XBE_SECTION *sections = (XBE_SECTION *)(xbe_data + header->Sections - header->BaseAddress);

    // Copy header data
    PVOID BaseAddress = (PVOID)header->BaseAddress;
    SIZE_T RegionSize = header->HeaderSize;
    printf("HeaderSize = %x\n", RegionSize);

    NtAllocateVirtualMemory(&BaseAddress, 0, &RegionSize, 0, 0);
    // FIXME: Leak, check return status (we assert now)
    memcpy((void*)(header->BaseAddress), xbe_data, header->HeaderSize);

    // Copy section data
    int i;
    for (i = 0; i < header->NumSections; i++) {
        XBE_SECTION *s = &sections[i];
        printf("[Section %d] %s\n", i, &xbe_data[s->SectionName-header->BaseAddress]);

        printf("\tVirtualAddress = %08x\n", s->VirtualAddress);
        printf("\tVirtualSize    = %08x\n", s->VirtualSize);
        printf("\tFileAddress    = %08x\n", s->FileAddress);
        printf("\tFileSize       = %08x\n", s->FileSize);

        BaseAddress = (void*)s->VirtualAddress;
        RegionSize = s->VirtualSize;
        NtAllocateVirtualMemory(&BaseAddress, 0, &RegionSize, 0, 0);
        // FIXME: Leak, check return status (we assert now)
        printf("Copying %x bytes from %x to %x\n", s->FileSize, &xbe_data[s->FileAddress], (void*)(s->VirtualAddress));
        memcpy((void*)(s->VirtualAddress), &xbe_data[s->FileAddress], s->FileSize);
        memset((void*)(s->VirtualAddress+s->FileSize), 0, s->VirtualSize-s->FileSize);

        printf("\tLoaded\n");
    }

    xbe_patch_imports(header);
    return (XBE_HEADER *)header->BaseAddress;
}

void *get_xbe_entry(XBE_HEADER *hdr)
{
    return (void*)xbe_unscramble(hdr->EntryPoint, XOR_EP_DEBUG, XOR_EP_RETAIL);
}
