/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <stdint.h>

#ifndef XBE_H
#define XBE_H

// XBE header information
typedef struct _XBE_HEADER {
	uint8_t   Magic[4];                // 000 "XBEH"
	uint8_t   HeaderSignature[256];    // 004 RSA digital signature of the entire header area
	uint32_t  BaseAddress;             // 104 Base address of XBE image (must be 0x00010000?)
	uint32_t  HeaderSize;              // 108 Size of all headers combined - other headers must be within this
	uint32_t  ImageSize;               // 10C Size of entire image
	uint32_t  XbeHeaderSize;           // 110 Size of this header (always 0x178?)
	uint32_t  Timestamp;               // 114 Image timestamp - unknown format
	uint32_t  Certificate;             // 118 Pointer to certificate data (must be within HeaderSize)
	int32_t   NumSections;             // 11C Number of sections
	uint32_t  Sections;                // 120 Pointer to section headers (must be within HeaderSize)
	uint32_t  InitFlags;               // 124 Initialization flags
	uint32_t  EntryPoint;              // 128 Entry point
	uint32_t  TlsDirectory;            // 12C Pointer to TLS directory
	uint32_t  StackCommit;             // 130 Stack commit size
	uint32_t  HeapReserve;             // 134 Heap reserve size
	uint32_t  HeapCommit;              // 138 Heap commit size
	uint32_t  PeBaseAddress;           // 13C PE base address (?)
	uint32_t  PeImageSize;             // 140 PE image size (?)
	uint32_t  PeChecksum;              // 144 PE checksum (?)
	uint32_t  PeTimestamp;             // 148 PE timestamp (?)
	uint32_t  PcExePath;               // 14C PC path and filename to EXE file from which XBE is derived
	uint32_t  PcExeFilename;           // 150 PC filename (last part of PcExePath) from which XBE is derived
	uint32_t  PcExeFilenameUnicode;    // 154 PC filename (Unicode version of PcExeFilename)
	uint32_t  KernelThunkTable;        // 158 Pointer to kernel thunk table (XOR'd; EFB1F152 debug)
	uint32_t  DebugImportTable;        // 15C Non-kernel import table (debug only)
	int32_t   NumLibraries;            // 160 Number of library headers
	uint32_t  Libraries;               // 164 Pointer to library headers
	uint32_t  KernelLibrary;           // 168 Pointer to kernel library header
	uint32_t  XapiLibrary;             // 16C Pointer to XAPI library
	uint32_t  LogoBitmap;              // 170 Pointer to logo bitmap (NULL = use default of Microsoft)
	uint32_t  LogoBitmapSize;          // 174 Size of logo bitmap
} XBE_HEADER, *PXBE_HEADER;

// Certificate structure
typedef struct _XBE_CERTIFICATE {
	uint32_t  Size;                    // 000 Size of certificate
	uint32_t  Timestamp;               // 004 Certificate timestamp (unknown format)
	uint32_t  TitleId;                 // 008 Title ID
	int16_t   TitleName[40];           // 00C Name of the game (Unicode)
	uint32_t  AlternateTitleIds[16];   // 05C Alternate title ID's (0-terminated)
	uint32_t  MediaTypes;              // 09C Allowed media types - 1 bit match between XBE and media = boots
	uint32_t  GameRegion;              // 0A0 Allowed game regions - 1 bit match between this and XBOX = boots
	uint32_t  GameRating;              // 0A4 Allowed game ratings - 1 bit match between this and XBOX = boots
	uint32_t  DiskNumber;              // 0A8 Disk number (?)
	uint32_t  Version;                 // 0AC Version (?)
	uint8_t   LanKey[16];              // 0B0 LAN key for this game
	uint8_t   SignatureKey[16];        // 0C0 Signature key for this game
	uint8_t   AlternateSignatureKeys[16][16]; // 0D0 Signature keys for the alternate title ID's
	// 1D0
} XBE_CERTIFICATE, *PXBE_CERTIFICATE;

// Section headers
typedef struct _XBE_SECTION {
	uint32_t  Flags;                   // 000 Flags
	uint32_t  VirtualAddress;          // 004 Virtual address (where this section loads in RAM)
	uint32_t  VirtualSize;             // 008 Virtual size (size of section in RAM; after FileSize it's 00'd)
	uint32_t  FileAddress;             // 00C File address (where in the file from which this section comes)
	uint32_t  FileSize;                // 010 File size (size of the section in the XBE file)
	uint32_t  SectionName;             // 014 Pointer to section name
	int32_t   SectionReferenceCount;   // 018 Section reference count - when >= 1, section is loaded
	uint32_t  HeadReferenceCount;      // 01C Pointer to head shared page reference count
	uint32_t  TailReferenceCount;      // 020 Pointer to tail shared page reference count
	uint8_t   ShaHash[20];             // 024 SHA1 hash.  Hash int32_t containing FileSize, then hash section.
} XBE_SECTION, *PXBE_SECTION;

// TLS directory information
typedef struct _XBE_TLS {
    int32_t   RawStart;                // 000 raw data start address
    int32_t   RawEnd;                  // 004 raw data end address
    int32_t   TlsIndex;                // 008 TLS index address
    int32_t   TlsCallbacks;            // 00C TLS callbacks address
    int32_t   SizeZeroFill;            // 010 size of zero fill
    uint8_t   Characteristics[8];      // 014 Characteristics
} XBE_TLS, *PXBE_TLS;

// Library version data
typedef struct _XBE_LIBRARY {
    uint8_t   Name[8];                 // 000 Library Name
    int16_t   MajorVersion;            // 008 Major Version
    int16_t   MiddleVersion;           // 00A Middle Version
    int16_t   MinorVersion;            // 00C Minor Version
    int16_t   Flags;                   // 00E Flags
} XBE_LIBRARY, *PXBELIBRARY;

// Initialization flags
#define XBE_INIT_MOUNT_UTILITY          0x00000001
#define XBE_INIT_FORMAT_UTILITY         0x00000002
#define XBE_INIT_64M_RAM_ONLY           0x00000004
#define XBE_INIT_DONT_SETUP_HDD         0x00000008

// Region codes
#define XBE_REGION_US_CANADA            0x00000001
#define XBE_REGION_JAPAN                0x00000002
#define XBE_REGION_ELSEWHERE            0x00000004
#define XBE_REGION_DEBUG                0x80000000

// Media types
#define XBE_MEDIA_HDD                   0x00000001
#define XBE_MEDIA_XBOX_DVD              0x00000002
#define XBE_MEDIA_ANY_CD_OR_DVD         0x00000004
#define XBE_MEDIA_CD                    0x00000008
#define XBE_MEDIA_1LAYER_DVDROM         0x00000010
#define XBE_MEDIA_2LAYER_DVDROM         0x00000020
#define XBE_MEDIA_1LAYER_DVDR           0x00000040
#define XBE_MEDIA_2LAYER_DVDR           0x00000080
#define XBE_MEDIA_USB                   0x00000100
#define XBE_MEDIA_ALLOW_UNLOCKED_HDD    0x40000000

// Section flags
#define XBE_SEC_WRITABLE                0x00000001
#define XBE_SEC_PRELOAD                 0x00000002
#define XBE_SEC_EXECUTABLE              0x00000004
#define XBE_SEC_INSERTED_FILE           0x00000008
#define XBE_SEC_RO_HEAD_PAGE            0x00000010
#define XBE_SEC_RO_TAIL_PAGE            0x00000020

// XOR keys
#define XOR_EP_DEBUG                    0x94859D4B // Entry Point (Debug)
#define XOR_EP_RETAIL                   0xA8FC57AB // Entry Point (Retail)
#define XOR_KT_DEBUG                    0xEFB1F152 // Kernel Thunk (Debug)
#define XOR_KT_RETAIL                   0x5B6D40B6 // Kernel Thunk (Retail)

uint32_t xbe_unscramble(uint32_t addr, uint32_t debug, uint32_t retail);
void xbe_patch_imports(XBE_HEADER *hdr);

extern void *m_import_addrs[400];

#endif
