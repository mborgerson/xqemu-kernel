#include "boot.h" // FIXME
#include "xdecl.h"


/**
 * RtlFillMemory
 */
XBAPI VOID NTAPI
RtlFillMemory(
	PVOID Destination,
	ULONG Length,
	UCHAR Fill
	)
{
	memset(Destination, Fill, Length);
}

/**
 * RtlMoveMemory
 */
XBAPI VOID NTAPI
RtlMoveMemory(
	PVOID       Destination,
	CONST PVOID Source,
	ULONG       Length
	)
{
	memmove(Destination, Source, Length);
}
