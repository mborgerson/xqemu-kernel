#ifndef stdio_h
#define stdio_h

#include "sys/types.h"

#include "boot.h"
#define fprintf(f, ...) printk(__VA_ARGS__)
#define stderr 2

#endif /* #ifndef stdio_h */
