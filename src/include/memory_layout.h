#ifndef memory_layout_h
#define memory_layout_h

/* a retail Xbox has 64 MB of RAM */
#define RAMSIZE  (64 * 1024*1024)
#define FB_SIZE   0x00400000
#define FB_START (0xf0000000 | (RAMSIZE - FB_SIZE))

/* let's reserve 4 MB at the top for the framebuffer */
#define RAMSIZE_USE (RAMSIZE - FB_SIZE)

#endif /* #ifndef memory_layout_h */
