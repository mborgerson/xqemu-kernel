#ifndef sys_types_h
#define sys_types_h

typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long int u_int64_t;

#define FILE int


#include <stdint.h>

typedef unsigned size_t;
typedef unsigned ptrdiff_t;
typedef long int off_t;

void abort();
extern int errno;

enum {
	ENOMEM = -1,
	EINVAL = -2,
};

#endif /* #ifndef sys_types_h */
