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
