#ifndef video_h
#define video_h

#include "stdlib.h"

// video helpers
typedef struct {
	u8 * pData;
	u8 * pBackdrop;
	int width;
	int height;
	int bpp;
} JPEG;

int BootVideoOverlayString(u32 * pdwaTopLeftDestination, u32 m_dwCountBytesPerLineDestination, RGBA rgbaOpaqueness, const char * szString);
void BootVideoChunkedPrint(const char * szBuffer);
int VideoDumpAddressAndData(u32 dwAds, const u8 * baData, u32 dwCountBytesUsable);
unsigned int BootVideoGetStringTotalWidth(const char * szc);
void BootVideoClearScreen(JPEG * pJpeg, int nStartLine, int nEndLine);

void BootVideoEnableOutput(u8 bAvPack);
u8 * BootVideoGetPointerToEffectiveJpegTopLeft(JPEG * pJpeg);

extern u8 baBackdrop[60*72*4];
extern JPEG jpegBackdrop;

#endif /* #ifndef video_h */
