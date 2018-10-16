#include "xtypes.h"
#include "xdecl.h"

#define K_ENTER()            do { } while(0)
#define K_VMEXIT(a)          do { *((volatile unsigned int *)0xfed0c000) = 0x7fffffff & (unsigned int)&a; } while (0)
#define K_EXIT_WITH_VALUE(v) do { return v; } while(0)
#define K_EXIT()             do { } while(0)


/**
 * AvGetSavedDataAddress
 */
XBAPI PVOID NTAPI __attribute__((weak))
AvGetSavedDataAddress(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID rval;
	} args;
	args._id = 1;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * AvSendTVEncoderOption
 */
XBAPI VOID NTAPI __attribute__((weak))
AvSendTVEncoderOption(
	PVOID  RegisterBase,
	ULONG  Option,
	ULONG  Param,
	PULONG Result
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  RegisterBase;
		ULONG  Option;
		ULONG  Param;
		PULONG Result;
	} args;
	args._id = 2;
	args._size = sizeof(args);
	args.RegisterBase = RegisterBase;
	args.Option = Option;
	args.Param = Param;
	args.Result = Result;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * AvSetDisplayMode
 */
XBAPI ULONG NTAPI __attribute__((weak))
AvSetDisplayMode(
	PVOID RegisterBase,
	ULONG Step,
	ULONG DisplayMode,
	ULONG SourceColorFormat,
	ULONG Pitch,
	ULONG FrameBuffer
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID RegisterBase;
		ULONG Step;
		ULONG DisplayMode;
		ULONG SourceColorFormat;
		ULONG Pitch;
		ULONG FrameBuffer;
		ULONG rval;
	} args;
	args._id = 3;
	args._size = sizeof(args);
	args.RegisterBase = RegisterBase;
	args.Step = Step;
	args.DisplayMode = DisplayMode;
	args.SourceColorFormat = SourceColorFormat;
	args.Pitch = Pitch;
	args.FrameBuffer = FrameBuffer;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * AvSetSavedDataAddress
 */
XBAPI VOID NTAPI __attribute__((weak))
AvSetSavedDataAddress(
	PVOID Address
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID Address;
	} args;
	args._id = 4;
	args._size = sizeof(args);
	args.Address = Address;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * DbgBreakPoint
 */
XBAPI VOID NTAPI __attribute__((weak))
DbgBreakPoint(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 5;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * DbgBreakPointWithStatus
 */
XBAPI VOID NTAPI __attribute__((weak))
DbgBreakPointWithStatus(
	ULONG Status
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG Status;
	} args;
	args._id = 6;
	args._size = sizeof(args);
	args.Status = Status;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * DbgLoadImageSymbols
 */
XBAPI VOID NTAPI __attribute__((weak))
DbgLoadImageSymbols(
	PSTRING   FileName,
	PVOID     ImageBase,
	ULONG_PTR ProcessId
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING   FileName;
		PVOID     ImageBase;
		ULONG_PTR ProcessId;
	} args;
	args._id = 7;
	args._size = sizeof(args);
	args.FileName = FileName;
	args.ImageBase = ImageBase;
	args.ProcessId = ProcessId;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * DbgPrint
 */
XBAPI ULONG CDECL __attribute__((weak))
DbgPrint(
	PCH Format,
	...
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCH Format;
		ULONG rval;
	} args;
	args._id = 8;
	args._size = sizeof(args);
	args.Format = Format;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * DbgPrompt
 */
XBAPI ULONG NTAPI __attribute__((weak))
DbgPrompt(
	PCH   Prompt,
	PCH   Response,
	ULONG MaximumResponseLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCH   Prompt;
		PCH   Response;
		ULONG MaximumResponseLength;
		ULONG rval;
	} args;
	args._id = 10;
	args._size = sizeof(args);
	args.Prompt = Prompt;
	args.Response = Response;
	args.MaximumResponseLength = MaximumResponseLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * DbgUnLoadImageSymbols
 */
XBAPI VOID NTAPI __attribute__((weak))
DbgUnLoadImageSymbols(
	PSTRING   FileName,
	PVOID     ImageBase,
	ULONG_PTR ProcessId
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING   FileName;
		PVOID     ImageBase;
		ULONG_PTR ProcessId;
	} args;
	args._id = 11;
	args._size = sizeof(args);
	args.FileName = FileName;
	args.ImageBase = ImageBase;
	args.ProcessId = ProcessId;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExAcquireReadWriteLockExclusive
 */
XBAPI VOID NTAPI __attribute__((weak))
ExAcquireReadWriteLockExclusive(
	PERWLOCK ReadWriteLock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PERWLOCK ReadWriteLock;
	} args;
	args._id = 12;
	args._size = sizeof(args);
	args.ReadWriteLock = ReadWriteLock;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExAcquireReadWriteLockShared
 */
XBAPI VOID NTAPI __attribute__((weak))
ExAcquireReadWriteLockShared(
	PERWLOCK ReadWriteLock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PERWLOCK ReadWriteLock;
	} args;
	args._id = 13;
	args._size = sizeof(args);
	args.ReadWriteLock = ReadWriteLock;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExAllocatePool
 */
XBAPI PVOID NTAPI __attribute__((weak))
ExAllocatePool(
	SIZE_T NumberOfBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T NumberOfBytes;
		PVOID rval;
	} args;
	args._id = 14;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExAllocatePoolWithTag
 */
XBAPI PVOID NTAPI __attribute__((weak))
ExAllocatePoolWithTag(
	SIZE_T NumberOfBytes,
	ULONG  Tag
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T NumberOfBytes;
		ULONG  Tag;
		PVOID rval;
	} args;
	args._id = 15;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.Tag = Tag;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExFreePool
 */
XBAPI VOID NTAPI __attribute__((weak))
ExFreePool(
	PVOID P
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID P;
	} args;
	args._id = 17;
	args._size = sizeof(args);
	args.P = P;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExInitializeReadWriteLock
 */
XBAPI VOID NTAPI __attribute__((weak))
ExInitializeReadWriteLock(
	PERWLOCK ReadWriteLock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PERWLOCK ReadWriteLock;
	} args;
	args._id = 18;
	args._size = sizeof(args);
	args.ReadWriteLock = ReadWriteLock;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExInterlockedAddLargeInteger
 */
XBAPI LARGE_INTEGER NTAPI __attribute__((weak))
ExInterlockedAddLargeInteger(
	PLARGE_INTEGER Addend,
	LARGE_INTEGER  Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLARGE_INTEGER Addend;
		LARGE_INTEGER  Increment;
		LARGE_INTEGER rval;
	} args;
	args._id = 19;
	args._size = sizeof(args);
	args.Addend = Addend;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExInterlockedAddLargeStatistic
 */
XBAPI VOID FASTCALL __attribute__((weak))
ExInterlockedAddLargeStatistic(
	PLARGE_INTEGER Addend,
	ULONG          Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLARGE_INTEGER Addend;
		ULONG          Increment;
	} args;
	args._id = 20;
	args._size = sizeof(args);
	args.Addend = Addend;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExInterlockedCompareExchange64
 */
XBAPI LONGLONG FASTCALL __attribute__((weak))
ExInterlockedCompareExchange64(
	PLONGLONG Destination,
	PLONGLONG Exchange,
	PLONGLONG Comparand
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONGLONG Destination;
		PLONGLONG Exchange;
		PLONGLONG Comparand;
		LONGLONG rval;
	} args;
	args._id = 21;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Exchange = Exchange;
	args.Comparand = Comparand;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExQueryNonVolatileSetting
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ExQueryNonVolatileSetting(
	ULONG  ValueIndex,
	PULONG Type,
	PVOID  Value,
	ULONG  ValueLength,
	PULONG ResultLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  ValueIndex;
		PULONG Type;
		PVOID  Value;
		ULONG  ValueLength;
		PULONG ResultLength;
		NTSTATUS rval;
	} args;
	args._id = 24;
	args._size = sizeof(args);
	args.ValueIndex = ValueIndex;
	args.Type = Type;
	args.Value = Value;
	args.ValueLength = ValueLength;
	args.ResultLength = ResultLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExQueryPoolBlockSize
 */
XBAPI ULONG NTAPI __attribute__((weak))
ExQueryPoolBlockSize(
	PVOID PoolBlock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID PoolBlock;
		ULONG rval;
	} args;
	args._id = 23;
	args._size = sizeof(args);
	args.PoolBlock = PoolBlock;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExRaiseException
 */
XBAPI VOID NTAPI __attribute__((weak))
ExRaiseException(
	PEXCEPTION_RECORD ExceptionRecord
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PEXCEPTION_RECORD ExceptionRecord;
	} args;
	args._id = 26;
	args._size = sizeof(args);
	args.ExceptionRecord = ExceptionRecord;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExRaiseStatus
 */
XBAPI VOID NTAPI __attribute__((weak))
ExRaiseStatus(
	NTSTATUS Status
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		NTSTATUS Status;
	} args;
	args._id = 27;
	args._size = sizeof(args);
	args.Status = Status;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExReadWriteRefurbInfo
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ExReadWriteRefurbInfo(
	PXBOX_REFURB_INFO RefurbInfo,
	ULONG             ValueLength,
	BOOLEAN           DoWrite
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PXBOX_REFURB_INFO RefurbInfo;
		ULONG             ValueLength;
		BOOLEAN           DoWrite;
		NTSTATUS rval;
	} args;
	args._id = 25;
	args._size = sizeof(args);
	args.RefurbInfo = RefurbInfo;
	args.ValueLength = ValueLength;
	args.DoWrite = DoWrite;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExReleaseReadWriteLock
 */
XBAPI VOID NTAPI __attribute__((weak))
ExReleaseReadWriteLock(
	PERWLOCK ReadWriteLock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PERWLOCK ReadWriteLock;
	} args;
	args._id = 28;
	args._size = sizeof(args);
	args.ReadWriteLock = ReadWriteLock;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ExSaveNonVolatileSetting
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ExSaveNonVolatileSetting(
	ULONG ValueIndex,
	ULONG Type,
	PVOID Value,
	ULONG ValueLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG ValueIndex;
		ULONG Type;
		PVOID Value;
		ULONG ValueLength;
		NTSTATUS rval;
	} args;
	args._id = 29;
	args._size = sizeof(args);
	args.ValueIndex = ValueIndex;
	args.Type = Type;
	args.Value = Value;
	args.ValueLength = ValueLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExfInterlockedInsertHeadList
 */
XBAPI PLIST_ENTRY FASTCALL __attribute__((weak))
ExfInterlockedInsertHeadList(
	PLIST_ENTRY ListHead,
	PLIST_ENTRY ListEntry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLIST_ENTRY ListHead;
		PLIST_ENTRY ListEntry;
		PLIST_ENTRY rval;
	} args;
	args._id = 32;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	args.ListEntry = ListEntry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExfInterlockedInsertTailList
 */
XBAPI PLIST_ENTRY FASTCALL __attribute__((weak))
ExfInterlockedInsertTailList(
	PLIST_ENTRY ListHead,
	PLIST_ENTRY ListEntry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLIST_ENTRY ListHead;
		PLIST_ENTRY ListEntry;
		PLIST_ENTRY rval;
	} args;
	args._id = 33;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	args.ListEntry = ListEntry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ExfInterlockedRemoveHeadList
 */
XBAPI PLIST_ENTRY FASTCALL __attribute__((weak))
ExfInterlockedRemoveHeadList(
	PLIST_ENTRY ListHead
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLIST_ENTRY ListHead;
		PLIST_ENTRY rval;
	} args;
	args._id = 34;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * FscGetCacheSize
 */
XBAPI PFN_COUNT NTAPI __attribute__((weak))
FscGetCacheSize(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFN_COUNT rval;
	} args;
	args._id = 35;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * FscInvalidateIdleBlocks
 */
XBAPI VOID NTAPI __attribute__((weak))
FscInvalidateIdleBlocks(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 36;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * FscSetCacheSize
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
FscSetCacheSize(
	PFN_COUNT NumberOfCachePages
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFN_COUNT NumberOfCachePages;
		NTSTATUS rval;
	} args;
	args._id = 37;
	args._size = sizeof(args);
	args.NumberOfCachePages = NumberOfCachePages;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalBootSMCVideoMode
 */
XBAPI DWORD NTAPI __attribute__((weak))
HalBootSMCVideoMode(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		DWORD rval;
	} args;
	args._id = 356;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalClearSoftwareInterrupt
 */
XBAPI VOID FASTCALL __attribute__((weak))
HalClearSoftwareInterrupt(
	KIRQL RequestIrql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL RequestIrql;
	} args;
	args._id = 38;
	args._size = sizeof(args);
	args.RequestIrql = RequestIrql;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalDisableSystemInterrupt
 */
XBAPI VOID NTAPI __attribute__((weak))
HalDisableSystemInterrupt(
	ULONG BusInterruptLevel
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG BusInterruptLevel;
	} args;
	args._id = 39;
	args._size = sizeof(args);
	args.BusInterruptLevel = BusInterruptLevel;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalEnableSecureTrayEject
 */
XBAPI VOID NTAPI __attribute__((weak))
HalEnableSecureTrayEject(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 365;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalEnableSystemInterrupt
 */
XBAPI VOID NTAPI __attribute__((weak))
HalEnableSystemInterrupt(
	ULONG           BusInterruptLevel,
	KINTERRUPT_MODE InterruptMode
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG           BusInterruptLevel;
		KINTERRUPT_MODE InterruptMode;
	} args;
	args._id = 43;
	args._size = sizeof(args);
	args.BusInterruptLevel = BusInterruptLevel;
	args.InterruptMode = InterruptMode;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalGetInterruptVector
 */
XBAPI ULONG NTAPI __attribute__((weak))
HalGetInterruptVector(
	ULONG  BusInterruptLevel,
	PKIRQL Irql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  BusInterruptLevel;
		PKIRQL Irql;
		ULONG rval;
	} args;
	args._id = 44;
	args._size = sizeof(args);
	args.BusInterruptLevel = BusInterruptLevel;
	args.Irql = Irql;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalInitiateShutdown
 */
XBAPI VOID NTAPI __attribute__((weak))
HalInitiateShutdown(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 360;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalIsResetOrShutdownPending
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
HalIsResetOrShutdownPending(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		BOOLEAN rval;
	} args;
	args._id = 358;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalReadSMBusValue
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
HalReadSMBusValue(
	UCHAR   SlaveAddress,
	UCHAR   CommandCode,
	BOOLEAN ReadWordValue,
	PULONG  DataValue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		UCHAR   SlaveAddress;
		UCHAR   CommandCode;
		BOOLEAN ReadWordValue;
		PULONG  DataValue;
		NTSTATUS rval;
	} args;
	args._id = 45;
	args._size = sizeof(args);
	args.SlaveAddress = SlaveAddress;
	args.CommandCode = CommandCode;
	args.ReadWordValue = ReadWordValue;
	args.DataValue = DataValue;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalReadSMCTrayState
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
HalReadSMCTrayState(
	PULONG TrayState,
	PULONG TrayStateChangeCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG TrayState;
		PULONG TrayStateChangeCount;
		NTSTATUS rval;
	} args;
	args._id = 9;
	args._size = sizeof(args);
	args.TrayState = TrayState;
	args.TrayStateChangeCount = TrayStateChangeCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalReadWritePCISpace
 */
XBAPI VOID NTAPI __attribute__((weak))
HalReadWritePCISpace(
	ULONG   BusNumber,
	ULONG   SlotNumber,
	ULONG   RegisterNumber,
	PVOID   Buffer,
	ULONG   Length,
	BOOLEAN WritePCISpace
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG   BusNumber;
		ULONG   SlotNumber;
		ULONG   RegisterNumber;
		PVOID   Buffer;
		ULONG   Length;
		BOOLEAN WritePCISpace;
	} args;
	args._id = 46;
	args._size = sizeof(args);
	args.BusNumber = BusNumber;
	args.SlotNumber = SlotNumber;
	args.RegisterNumber = RegisterNumber;
	args.Buffer = Buffer;
	args.Length = Length;
	args.WritePCISpace = WritePCISpace;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalRegisterShutdownNotification
 */
XBAPI VOID NTAPI __attribute__((weak))
HalRegisterShutdownNotification(
	PHAL_SHUTDOWN_REGISTRATION ShutdownRegistration,
	BOOLEAN                    Register
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHAL_SHUTDOWN_REGISTRATION ShutdownRegistration;
		BOOLEAN                    Register;
	} args;
	args._id = 47;
	args._size = sizeof(args);
	args.ShutdownRegistration = ShutdownRegistration;
	args.Register = Register;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalRequestSoftwareInterrupt
 */
XBAPI VOID FASTCALL __attribute__((weak))
HalRequestSoftwareInterrupt(
	KIRQL RequestIrql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL RequestIrql;
	} args;
	args._id = 48;
	args._size = sizeof(args);
	args.RequestIrql = RequestIrql;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * HalReturnToFirmware
 */
XBAPI VOID NTAPI __attribute__((weak))
HalReturnToFirmware(
	FIRMWARE_REENTRY Routine
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		FIRMWARE_REENTRY Routine;
	} args;
	args._id = 49;
	args._size = sizeof(args);
	args.Routine = Routine;
	K_VMEXIT(args);
	K_EXIT();
	while (1);
}


/**
 * HalWriteSMBusValue
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
HalWriteSMBusValue(
	UCHAR   SlaveAddress,
	UCHAR   CommandCode,
	BOOLEAN WriteWordValue,
	ULONG   DataValue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		UCHAR   SlaveAddress;
		UCHAR   CommandCode;
		BOOLEAN WriteWordValue;
		ULONG   DataValue;
		NTSTATUS rval;
	} args;
	args._id = 50;
	args._size = sizeof(args);
	args.SlaveAddress = SlaveAddress;
	args.CommandCode = CommandCode;
	args.WriteWordValue = WriteWordValue;
	args.DataValue = DataValue;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * HalWriteSMCScratchRegister
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
HalWriteSMCScratchRegister(
	ULONG ScratchRegister
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG ScratchRegister;
		NTSTATUS rval;
	} args;
	args._id = 366;
	args._size = sizeof(args);
	args.ScratchRegister = ScratchRegister;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedCompareExchange
 */
XBAPI LONG FASTCALL __attribute__((weak))
InterlockedCompareExchange(
	PLONG Destination,
	LONG  ExChange,
	LONG  Comparand
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONG Destination;
		LONG  ExChange;
		LONG  Comparand;
		LONG rval;
	} args;
	args._id = 51;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.ExChange = ExChange;
	args.Comparand = Comparand;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedDecrement
 */
XBAPI LONG FASTCALL __attribute__((weak))
InterlockedDecrement(
	PLONG Addend
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONG Addend;
		LONG rval;
	} args;
	args._id = 52;
	args._size = sizeof(args);
	args.Addend = Addend;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedExchange
 */
XBAPI LONG FASTCALL __attribute__((weak))
InterlockedExchange(
	PLONG Target,
	LONG  Value
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONG Target;
		LONG  Value;
		LONG rval;
	} args;
	args._id = 54;
	args._size = sizeof(args);
	args.Target = Target;
	args.Value = Value;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedExchangeAdd
 */
XBAPI LONG FASTCALL __attribute__((weak))
InterlockedExchangeAdd(
	PLONG Addend,
	LONG  Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONG Addend;
		LONG  Increment;
		LONG rval;
	} args;
	args._id = 55;
	args._size = sizeof(args);
	args.Addend = Addend;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedFlushSList
 */
XBAPI PSINGLE_LIST_ENTRY FASTCALL __attribute__((weak))
InterlockedFlushSList(
	PSLIST_HEADER ListHead
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSLIST_HEADER ListHead;
		PSINGLE_LIST_ENTRY rval;
	} args;
	args._id = 56;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedIncrement
 */
XBAPI LONG FASTCALL __attribute__((weak))
InterlockedIncrement(
	PLONG Addend
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLONG Addend;
		LONG rval;
	} args;
	args._id = 53;
	args._size = sizeof(args);
	args.Addend = Addend;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedPopEntrySList
 */
XBAPI PSINGLE_LIST_ENTRY FASTCALL __attribute__((weak))
InterlockedPopEntrySList(
	PSLIST_HEADER ListHead
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSLIST_HEADER ListHead;
		PSINGLE_LIST_ENTRY rval;
	} args;
	args._id = 57;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * InterlockedPushEntrySList
 */
XBAPI PSINGLE_LIST_ENTRY FASTCALL __attribute__((weak))
InterlockedPushEntrySList(
	PSLIST_HEADER      ListHead,
	PSINGLE_LIST_ENTRY ListEntry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSLIST_HEADER      ListHead;
		PSINGLE_LIST_ENTRY ListEntry;
		PSINGLE_LIST_ENTRY rval;
	} args;
	args._id = 58;
	args._size = sizeof(args);
	args.ListHead = ListHead;
	args.ListEntry = ListEntry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoAllocateIrp
 */
XBAPI PIRP NTAPI __attribute__((weak))
IoAllocateIrp(
	CCHAR StackSize
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		CCHAR StackSize;
		PIRP rval;
	} args;
	args._id = 59;
	args._size = sizeof(args);
	args.StackSize = StackSize;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoBuildAsynchronousFsdRequest
 */
XBAPI PIRP NTAPI __attribute__((weak))
IoBuildAsynchronousFsdRequest(
	ULONG            MajorFunction,
	PDEVICE_OBJECT   DeviceObject,
	PVOID            Buffer,
	ULONG            Length,
	PLARGE_INTEGER   StartingOffset,
	PIO_STATUS_BLOCK IoStatusBlock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG            MajorFunction;
		PDEVICE_OBJECT   DeviceObject;
		PVOID            Buffer;
		ULONG            Length;
		PLARGE_INTEGER   StartingOffset;
		PIO_STATUS_BLOCK IoStatusBlock;
		PIRP rval;
	} args;
	args._id = 60;
	args._size = sizeof(args);
	args.MajorFunction = MajorFunction;
	args.DeviceObject = DeviceObject;
	args.Buffer = Buffer;
	args.Length = Length;
	args.StartingOffset = StartingOffset;
	args.IoStatusBlock = IoStatusBlock;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoBuildDeviceIoControlRequest
 */
XBAPI PIRP NTAPI __attribute__((weak))
IoBuildDeviceIoControlRequest(
	ULONG            IoControlCode,
	PDEVICE_OBJECT   DeviceObject,
	PVOID            InputBuffer,
	ULONG            InputBufferLength,
	PVOID            OutputBuffer,
	ULONG            OutputBufferLength,
	BOOLEAN          InternalDeviceIoControl,
	PKEVENT          Event,
	PIO_STATUS_BLOCK IoStatusBlock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG            IoControlCode;
		PDEVICE_OBJECT   DeviceObject;
		PVOID            InputBuffer;
		ULONG            InputBufferLength;
		PVOID            OutputBuffer;
		ULONG            OutputBufferLength;
		BOOLEAN          InternalDeviceIoControl;
		PKEVENT          Event;
		PIO_STATUS_BLOCK IoStatusBlock;
		PIRP rval;
	} args;
	args._id = 61;
	args._size = sizeof(args);
	args.IoControlCode = IoControlCode;
	args.DeviceObject = DeviceObject;
	args.InputBuffer = InputBuffer;
	args.InputBufferLength = InputBufferLength;
	args.OutputBuffer = OutputBuffer;
	args.OutputBufferLength = OutputBufferLength;
	args.InternalDeviceIoControl = InternalDeviceIoControl;
	args.Event = Event;
	args.IoStatusBlock = IoStatusBlock;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoBuildSynchronousFsdRequest
 */
XBAPI PIRP NTAPI __attribute__((weak))
IoBuildSynchronousFsdRequest(
	ULONG            MajorFunction,
	PDEVICE_OBJECT   DeviceObject,
	PVOID            Buffer,
	ULONG            Length,
	PLARGE_INTEGER   StartingOffset,
	PKEVENT          Event,
	PIO_STATUS_BLOCK IoStatusBlock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG            MajorFunction;
		PDEVICE_OBJECT   DeviceObject;
		PVOID            Buffer;
		ULONG            Length;
		PLARGE_INTEGER   StartingOffset;
		PKEVENT          Event;
		PIO_STATUS_BLOCK IoStatusBlock;
		PIRP rval;
	} args;
	args._id = 62;
	args._size = sizeof(args);
	args.MajorFunction = MajorFunction;
	args.DeviceObject = DeviceObject;
	args.Buffer = Buffer;
	args.Length = Length;
	args.StartingOffset = StartingOffset;
	args.Event = Event;
	args.IoStatusBlock = IoStatusBlock;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoCheckShareAccess
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoCheckShareAccess(
	ACCESS_MASK   DesiredAccess,
	ULONG         DesiredShareAccess,
	PFILE_OBJECT  FileObject,
	PSHARE_ACCESS ShareAccess,
	BOOLEAN       Update
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ACCESS_MASK   DesiredAccess;
		ULONG         DesiredShareAccess;
		PFILE_OBJECT  FileObject;
		PSHARE_ACCESS ShareAccess;
		BOOLEAN       Update;
		NTSTATUS rval;
	} args;
	args._id = 63;
	args._size = sizeof(args);
	args.DesiredAccess = DesiredAccess;
	args.DesiredShareAccess = DesiredShareAccess;
	args.FileObject = FileObject;
	args.ShareAccess = ShareAccess;
	args.Update = Update;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoCreateDevice
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoCreateDevice(
	PDRIVER_OBJECT  DriverObject,
	ULONG           DeviceExtensionSize,
	POBJECT_STRING  DeviceName,
	DEVICE_TYPE     DeviceType,
	BOOLEAN         Exclusive,
	PPDEVICE_OBJECT DeviceObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDRIVER_OBJECT  DriverObject;
		ULONG           DeviceExtensionSize;
		POBJECT_STRING  DeviceName;
		DEVICE_TYPE     DeviceType;
		BOOLEAN         Exclusive;
		PPDEVICE_OBJECT DeviceObject;
		NTSTATUS rval;
	} args;
	args._id = 65;
	args._size = sizeof(args);
	args.DriverObject = DriverObject;
	args.DeviceExtensionSize = DeviceExtensionSize;
	args.DeviceName = DeviceName;
	args.DeviceType = DeviceType;
	args.Exclusive = Exclusive;
	args.DeviceObject = DeviceObject;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoCreateFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoCreateFile(
	PHANDLE            FileHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK   IoStatusBlock,
	PLARGE_INTEGER     AllocationSize,
	ULONG              FileAttributes,
	ULONG              ShareAccess,
	ULONG              Disposition,
	ULONG              CreateOptions,
	ULONG              Options
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            FileHandle;
		ACCESS_MASK        DesiredAccess;
		POBJECT_ATTRIBUTES ObjectAttributes;
		PIO_STATUS_BLOCK   IoStatusBlock;
		PLARGE_INTEGER     AllocationSize;
		ULONG              FileAttributes;
		ULONG              ShareAccess;
		ULONG              Disposition;
		ULONG              CreateOptions;
		ULONG              Options;
		NTSTATUS rval;
	} args;
	args._id = 66;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.DesiredAccess = DesiredAccess;
	args.ObjectAttributes = ObjectAttributes;
	args.IoStatusBlock = IoStatusBlock;
	args.AllocationSize = AllocationSize;
	args.FileAttributes = FileAttributes;
	args.ShareAccess = ShareAccess;
	args.Disposition = Disposition;
	args.CreateOptions = CreateOptions;
	args.Options = Options;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoCreateSymbolicLink
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoCreateSymbolicLink(
	POBJECT_STRING SymbolicLinkName,
	POBJECT_STRING DeviceName
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_STRING SymbolicLinkName;
		POBJECT_STRING DeviceName;
		NTSTATUS rval;
	} args;
	args._id = 67;
	args._size = sizeof(args);
	args.SymbolicLinkName = SymbolicLinkName;
	args.DeviceName = DeviceName;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoDeleteDevice
 */
XBAPI VOID NTAPI __attribute__((weak))
IoDeleteDevice(
	PDEVICE_OBJECT DeviceObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
	} args;
	args._id = 68;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoDeleteSymbolicLink
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoDeleteSymbolicLink(
	POBJECT_STRING SymbolicLinkName
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_STRING SymbolicLinkName;
		NTSTATUS rval;
	} args;
	args._id = 69;
	args._size = sizeof(args);
	args.SymbolicLinkName = SymbolicLinkName;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoDismountVolume
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoDismountVolume(
	PDEVICE_OBJECT DeviceObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
		NTSTATUS rval;
	} args;
	args._id = 90;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoDismountVolumeByName
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoDismountVolumeByName(
	POBJECT_STRING DeviceName
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_STRING DeviceName;
		NTSTATUS rval;
	} args;
	args._id = 91;
	args._size = sizeof(args);
	args.DeviceName = DeviceName;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoFreeIrp
 */
XBAPI VOID NTAPI __attribute__((weak))
IoFreeIrp(
	PIRP Irp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PIRP Irp;
	} args;
	args._id = 72;
	args._size = sizeof(args);
	args.Irp = Irp;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoInitializeIrp
 */
XBAPI VOID NTAPI __attribute__((weak))
IoInitializeIrp(
	PIRP   Irp,
	USHORT PacketSize,
	CCHAR  StackSize
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PIRP   Irp;
		USHORT PacketSize;
		CCHAR  StackSize;
	} args;
	args._id = 73;
	args._size = sizeof(args);
	args.Irp = Irp;
	args.PacketSize = PacketSize;
	args.StackSize = StackSize;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoInvalidDeviceRequest
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoInvalidDeviceRequest(
	PDEVICE_OBJECT DeviceObject,
	PIRP           Irp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
		PIRP           Irp;
		NTSTATUS rval;
	} args;
	args._id = 74;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	args.Irp = Irp;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoMarkIrpMustComplete
 */
XBAPI VOID NTAPI __attribute__((weak))
IoMarkIrpMustComplete(
	PIRP Irp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PIRP Irp;
	} args;
	args._id = 359;
	args._size = sizeof(args);
	args.Irp = Irp;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoQueryFileInformation
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoQueryFileInformation(
	PFILE_OBJECT           FileObject,
	FILE_INFORMATION_CLASS FileInformationClass,
	ULONG                  Length,
	PVOID                  FileInformation,
	PULONG                 ReturnedLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFILE_OBJECT           FileObject;
		FILE_INFORMATION_CLASS FileInformationClass;
		ULONG                  Length;
		PVOID                  FileInformation;
		PULONG                 ReturnedLength;
		NTSTATUS rval;
	} args;
	args._id = 75;
	args._size = sizeof(args);
	args.FileObject = FileObject;
	args.FileInformationClass = FileInformationClass;
	args.Length = Length;
	args.FileInformation = FileInformation;
	args.ReturnedLength = ReturnedLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoQueryVolumeInformation
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoQueryVolumeInformation(
	PFILE_OBJECT         FileObject,
	FS_INFORMATION_CLASS FsInformationClass,
	ULONG                Length,
	PVOID                FsInformation,
	PULONG               ReturnedLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFILE_OBJECT         FileObject;
		FS_INFORMATION_CLASS FsInformationClass;
		ULONG                Length;
		PVOID                FsInformation;
		PULONG               ReturnedLength;
		NTSTATUS rval;
	} args;
	args._id = 76;
	args._size = sizeof(args);
	args.FileObject = FileObject;
	args.FsInformationClass = FsInformationClass;
	args.Length = Length;
	args.FsInformation = FsInformation;
	args.ReturnedLength = ReturnedLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoQueueThreadIrp
 */
XBAPI VOID NTAPI __attribute__((weak))
IoQueueThreadIrp(
	PIRP Irp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PIRP Irp;
	} args;
	args._id = 77;
	args._size = sizeof(args);
	args.Irp = Irp;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoRemoveShareAccess
 */
XBAPI VOID NTAPI __attribute__((weak))
IoRemoveShareAccess(
	PFILE_OBJECT  FileObject,
	PSHARE_ACCESS ShareAccess
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFILE_OBJECT  FileObject;
		PSHARE_ACCESS ShareAccess;
	} args;
	args._id = 78;
	args._size = sizeof(args);
	args.FileObject = FileObject;
	args.ShareAccess = ShareAccess;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoSetIoCompletion
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoSetIoCompletion(
	PVOID     IoCompletion,
	PVOID     KeyContext,
	PVOID     ApcContext,
	NTSTATUS  IoStatus,
	ULONG_PTR IoStatusInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID     IoCompletion;
		PVOID     KeyContext;
		PVOID     ApcContext;
		NTSTATUS  IoStatus;
		ULONG_PTR IoStatusInformation;
		NTSTATUS rval;
	} args;
	args._id = 79;
	args._size = sizeof(args);
	args.IoCompletion = IoCompletion;
	args.KeyContext = KeyContext;
	args.ApcContext = ApcContext;
	args.IoStatus = IoStatus;
	args.IoStatusInformation = IoStatusInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoSetShareAccess
 */
XBAPI VOID NTAPI __attribute__((weak))
IoSetShareAccess(
	ACCESS_MASK   DesiredAccess,
	ULONG         DesiredShareAccess,
	PFILE_OBJECT  FileObject,
	PSHARE_ACCESS ShareAccess
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ACCESS_MASK   DesiredAccess;
		ULONG         DesiredShareAccess;
		PFILE_OBJECT  FileObject;
		PSHARE_ACCESS ShareAccess;
	} args;
	args._id = 80;
	args._size = sizeof(args);
	args.DesiredAccess = DesiredAccess;
	args.DesiredShareAccess = DesiredShareAccess;
	args.FileObject = FileObject;
	args.ShareAccess = ShareAccess;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoStartNextPacket
 */
XBAPI VOID NTAPI __attribute__((weak))
IoStartNextPacket(
	PDEVICE_OBJECT DeviceObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
	} args;
	args._id = 81;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoStartNextPacketByKey
 */
XBAPI VOID NTAPI __attribute__((weak))
IoStartNextPacketByKey(
	PDEVICE_OBJECT DeviceObject,
	ULONG          Key
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
		ULONG          Key;
	} args;
	args._id = 82;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	args.Key = Key;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoStartPacket
 */
XBAPI VOID NTAPI __attribute__((weak))
IoStartPacket(
	PDEVICE_OBJECT DeviceObject,
	PIRP           Irp,
	PULONG         Key
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
		PIRP           Irp;
		PULONG         Key;
	} args;
	args._id = 83;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	args.Irp = Irp;
	args.Key = Key;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * IoSynchronousDeviceIoControlRequest
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoSynchronousDeviceIoControlRequest(
	ULONG          IoControlCode,
	PDEVICE_OBJECT DeviceObject,
	PVOID          InputBuffer,
	ULONG          InputBufferLength,
	PVOID          OutputBuffer,
	ULONG          OutputBufferLength,
	PULONG         ReturnedOutputBufferLength,
	BOOLEAN        InternalDeviceIoControl
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG          IoControlCode;
		PDEVICE_OBJECT DeviceObject;
		PVOID          InputBuffer;
		ULONG          InputBufferLength;
		PVOID          OutputBuffer;
		ULONG          OutputBufferLength;
		PULONG         ReturnedOutputBufferLength;
		BOOLEAN        InternalDeviceIoControl;
		NTSTATUS rval;
	} args;
	args._id = 84;
	args._size = sizeof(args);
	args.IoControlCode = IoControlCode;
	args.DeviceObject = DeviceObject;
	args.InputBuffer = InputBuffer;
	args.InputBufferLength = InputBufferLength;
	args.OutputBuffer = OutputBuffer;
	args.OutputBufferLength = OutputBufferLength;
	args.ReturnedOutputBufferLength = ReturnedOutputBufferLength;
	args.InternalDeviceIoControl = InternalDeviceIoControl;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IoSynchronousFsdRequest
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
IoSynchronousFsdRequest(
	ULONG          MajorFunction,
	PDEVICE_OBJECT DeviceObject,
	PVOID          Buffer,
	ULONG          Length,
	PLARGE_INTEGER StartingOffset
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG          MajorFunction;
		PDEVICE_OBJECT DeviceObject;
		PVOID          Buffer;
		ULONG          Length;
		PLARGE_INTEGER StartingOffset;
		NTSTATUS rval;
	} args;
	args._id = 85;
	args._size = sizeof(args);
	args.MajorFunction = MajorFunction;
	args.DeviceObject = DeviceObject;
	args.Buffer = Buffer;
	args.Length = Length;
	args.StartingOffset = StartingOffset;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IofCallDriver
 */
XBAPI NTSTATUS FASTCALL __attribute__((weak))
IofCallDriver(
	PDEVICE_OBJECT DeviceObject,
	PIRP           Irp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
		PIRP           Irp;
		NTSTATUS rval;
	} args;
	args._id = 86;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	args.Irp = Irp;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * IofCompleteRequest
 */
XBAPI VOID FASTCALL __attribute__((weak))
IofCompleteRequest(
	PDEVICE_OBJECT DeviceObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PDEVICE_OBJECT DeviceObject;
	} args;
	args._id = 87;
	args._size = sizeof(args);
	args.DeviceObject = DeviceObject;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeAlertResumeThread
 */
XBAPI ULONG NTAPI __attribute__((weak))
KeAlertResumeThread(
	PKTHREAD Thread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		ULONG rval;
	} args;
	args._id = 92;
	args._size = sizeof(args);
	args.Thread = Thread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeAlertThread
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeAlertThread(
	PKTHREAD        Thread,
	KPROCESSOR_MODE ProcessorMode
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD        Thread;
		KPROCESSOR_MODE ProcessorMode;
		BOOLEAN rval;
	} args;
	args._id = 93;
	args._size = sizeof(args);
	args.Thread = Thread;
	args.ProcessorMode = ProcessorMode;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeBoostPriorityThread
 */
XBAPI VOID NTAPI __attribute__((weak))
KeBoostPriorityThread(
	PKTHREAD  Thread,
	KPRIORITY Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD  Thread;
		KPRIORITY Increment;
	} args;
	args._id = 94;
	args._size = sizeof(args);
	args.Thread = Thread;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeBugCheck
 */
XBAPI VOID NTAPI __attribute__((weak))
KeBugCheck(
	ULONG BugCheckCode
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG BugCheckCode;
	} args;
	args._id = 95;
	args._size = sizeof(args);
	args.BugCheckCode = BugCheckCode;
	K_VMEXIT(args);
	K_EXIT();
	while (1);
}


/**
 * KeBugCheckEx
 */
XBAPI VOID NTAPI __attribute__((weak))
KeBugCheckEx(
	ULONG     BugCheckCode,
	ULONG_PTR BugCheckParameter1,
	ULONG_PTR BugCheckParameter2,
	ULONG_PTR BugCheckParameter3,
	ULONG_PTR BugCheckParameter4
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG     BugCheckCode;
		ULONG_PTR BugCheckParameter1;
		ULONG_PTR BugCheckParameter2;
		ULONG_PTR BugCheckParameter3;
		ULONG_PTR BugCheckParameter4;
	} args;
	args._id = 96;
	args._size = sizeof(args);
	args.BugCheckCode = BugCheckCode;
	args.BugCheckParameter1 = BugCheckParameter1;
	args.BugCheckParameter2 = BugCheckParameter2;
	args.BugCheckParameter3 = BugCheckParameter3;
	args.BugCheckParameter4 = BugCheckParameter4;
	K_VMEXIT(args);
	K_EXIT();
	while (1);
}


/**
 * KeCancelTimer
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeCancelTimer(
	PKTIMER Timer
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTIMER Timer;
		BOOLEAN rval;
	} args;
	args._id = 97;
	args._size = sizeof(args);
	args.Timer = Timer;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeConnectInterrupt
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeConnectInterrupt(
	PKINTERRUPT Interrupt
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKINTERRUPT Interrupt;
		BOOLEAN rval;
	} args;
	args._id = 98;
	args._size = sizeof(args);
	args.Interrupt = Interrupt;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeDelayExecutionThread
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
KeDelayExecutionThread(
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Interval
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Interval;
		NTSTATUS rval;
	} args;
	args._id = 99;
	args._size = sizeof(args);
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Interval = Interval;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeDisconnectInterrupt
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeDisconnectInterrupt(
	PKINTERRUPT Interrupt
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKINTERRUPT Interrupt;
		BOOLEAN rval;
	} args;
	args._id = 100;
	args._size = sizeof(args);
	args.Interrupt = Interrupt;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeEnterCriticalRegion
 */
XBAPI VOID NTAPI __attribute__((weak))
KeEnterCriticalRegion(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 101;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeGetCurrentIrql
 */
XBAPI KIRQL NTAPI __attribute__((weak))
KeGetCurrentIrql(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL rval;
	} args;
	args._id = 103;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeGetCurrentThread
 */
XBAPI PKTHREAD NTAPI __attribute__((weak))
KeGetCurrentThread(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD rval;
	} args;
	args._id = 104;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInitializeApc
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeApc(
	PRKAPC            Apc,
	PRKTHREAD         Thread,
	PKKERNEL_ROUTINE  KernelRoutine,
	PKRUNDOWN_ROUTINE RundownRoutine,
	PKNORMAL_ROUTINE  NormalRoutine,
	KPROCESSOR_MODE   ProcessorMode,
	PVOID             NormalContext
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKAPC            Apc;
		PRKTHREAD         Thread;
		PKKERNEL_ROUTINE  KernelRoutine;
		PKRUNDOWN_ROUTINE RundownRoutine;
		PKNORMAL_ROUTINE  NormalRoutine;
		KPROCESSOR_MODE   ProcessorMode;
		PVOID             NormalContext;
	} args;
	args._id = 105;
	args._size = sizeof(args);
	args.Apc = Apc;
	args.Thread = Thread;
	args.KernelRoutine = KernelRoutine;
	args.RundownRoutine = RundownRoutine;
	args.NormalRoutine = NormalRoutine;
	args.ProcessorMode = ProcessorMode;
	args.NormalContext = NormalContext;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeDeviceQueue
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeDeviceQueue(
	PKDEVICE_QUEUE DeviceQueue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE DeviceQueue;
	} args;
	args._id = 106;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeDpc
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeDpc(
	PKDPC              Dpc,
	PKDEFERRED_ROUTINE DeferredRoutine,
	PVOID              DeferredContext
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDPC              Dpc;
		PKDEFERRED_ROUTINE DeferredRoutine;
		PVOID              DeferredContext;
	} args;
	args._id = 107;
	args._size = sizeof(args);
	args.Dpc = Dpc;
	args.DeferredRoutine = DeferredRoutine;
	args.DeferredContext = DeferredContext;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeEvent
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeEvent(
	PRKEVENT   Event,
	EVENT_TYPE Type,
	BOOLEAN    State
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKEVENT   Event;
		EVENT_TYPE Type;
		BOOLEAN    State;
	} args;
	args._id = 108;
	args._size = sizeof(args);
	args.Event = Event;
	args.Type = Type;
	args.State = State;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeInterrupt
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeInterrupt(
	PKINTERRUPT       Interrupt,
	PKSERVICE_ROUTINE ServiceRoutine,
	PVOID             ServiceContext,
	ULONG             Vector,
	KIRQL             Irql,
	KINTERRUPT_MODE   InterruptMode,
	BOOLEAN           ShareVector
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKINTERRUPT       Interrupt;
		PKSERVICE_ROUTINE ServiceRoutine;
		PVOID             ServiceContext;
		ULONG             Vector;
		KIRQL             Irql;
		KINTERRUPT_MODE   InterruptMode;
		BOOLEAN           ShareVector;
	} args;
	args._id = 109;
	args._size = sizeof(args);
	args.Interrupt = Interrupt;
	args.ServiceRoutine = ServiceRoutine;
	args.ServiceContext = ServiceContext;
	args.Vector = Vector;
	args.Irql = Irql;
	args.InterruptMode = InterruptMode;
	args.ShareVector = ShareVector;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeMutant
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeMutant(
	PRKMUTANT Mutant,
	BOOLEAN   InitialOwner
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKMUTANT Mutant;
		BOOLEAN   InitialOwner;
	} args;
	args._id = 110;
	args._size = sizeof(args);
	args.Mutant = Mutant;
	args.InitialOwner = InitialOwner;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeQueue
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeQueue(
	PRKQUEUE Queue,
	ULONG    Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKQUEUE Queue;
		ULONG    Count;
	} args;
	args._id = 111;
	args._size = sizeof(args);
	args.Queue = Queue;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeSemaphore
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeSemaphore(
	PRKSEMAPHORE Semaphore,
	LONG         Count,
	LONG         Limit
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKSEMAPHORE Semaphore;
		LONG         Count;
		LONG         Limit;
	} args;
	args._id = 112;
	args._size = sizeof(args);
	args.Semaphore = Semaphore;
	args.Count = Count;
	args.Limit = Limit;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInitializeTimerEx
 */
XBAPI VOID NTAPI __attribute__((weak))
KeInitializeTimerEx(
	PKTIMER    Timer,
	TIMER_TYPE Type
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTIMER    Timer;
		TIMER_TYPE Type;
	} args;
	args._id = 113;
	args._size = sizeof(args);
	args.Timer = Timer;
	args.Type = Type;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeInsertByKeyDeviceQueue
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeInsertByKeyDeviceQueue(
	PKDEVICE_QUEUE       DeviceQueue,
	PKDEVICE_QUEUE_ENTRY DeviceQueueEntry,
	ULONG                SortKey
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE       DeviceQueue;
		PKDEVICE_QUEUE_ENTRY DeviceQueueEntry;
		ULONG                SortKey;
		BOOLEAN rval;
	} args;
	args._id = 114;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	args.DeviceQueueEntry = DeviceQueueEntry;
	args.SortKey = SortKey;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInsertDeviceQueue
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeInsertDeviceQueue(
	PKDEVICE_QUEUE       DeviceQueue,
	PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE       DeviceQueue;
		PKDEVICE_QUEUE_ENTRY DeviceQueueEntry;
		BOOLEAN rval;
	} args;
	args._id = 115;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	args.DeviceQueueEntry = DeviceQueueEntry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInsertHeadQueue
 */
XBAPI LONG NTAPI __attribute__((weak))
KeInsertHeadQueue(
	PRKQUEUE    Queue,
	PLIST_ENTRY Entry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKQUEUE    Queue;
		PLIST_ENTRY Entry;
		LONG rval;
	} args;
	args._id = 116;
	args._size = sizeof(args);
	args.Queue = Queue;
	args.Entry = Entry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInsertQueue
 */
XBAPI LONG NTAPI __attribute__((weak))
KeInsertQueue(
	PRKQUEUE    Queue,
	PLIST_ENTRY Entry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKQUEUE    Queue;
		PLIST_ENTRY Entry;
		LONG rval;
	} args;
	args._id = 117;
	args._size = sizeof(args);
	args.Queue = Queue;
	args.Entry = Entry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInsertQueueApc
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeInsertQueueApc(
	PRKAPC    Apc,
	PVOID     SystemArgument1,
	PVOID     SystemArgument2,
	KPRIORITY Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKAPC    Apc;
		PVOID     SystemArgument1;
		PVOID     SystemArgument2;
		KPRIORITY Increment;
		BOOLEAN rval;
	} args;
	args._id = 118;
	args._size = sizeof(args);
	args.Apc = Apc;
	args.SystemArgument1 = SystemArgument1;
	args.SystemArgument2 = SystemArgument2;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeInsertQueueDpc
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeInsertQueueDpc(
	PRKDPC Dpc,
	PVOID  SystemArgument1,
	PVOID  SystemArgument2
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKDPC Dpc;
		PVOID  SystemArgument1;
		PVOID  SystemArgument2;
		BOOLEAN rval;
	} args;
	args._id = 119;
	args._size = sizeof(args);
	args.Dpc = Dpc;
	args.SystemArgument1 = SystemArgument1;
	args.SystemArgument2 = SystemArgument2;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeIsExecutingDpc
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeIsExecutingDpc(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		BOOLEAN rval;
	} args;
	args._id = 121;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeLeaveCriticalRegion
 */
XBAPI VOID NTAPI __attribute__((weak))
KeLeaveCriticalRegion(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
	} args;
	args._id = 122;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KePulseEvent
 */
XBAPI LONG NTAPI __attribute__((weak))
KePulseEvent(
	PRKEVENT  Event,
	KPRIORITY Increment,
	BOOLEAN   Wait
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKEVENT  Event;
		KPRIORITY Increment;
		BOOLEAN   Wait;
		LONG rval;
	} args;
	args._id = 123;
	args._size = sizeof(args);
	args.Event = Event;
	args.Increment = Increment;
	args.Wait = Wait;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeQueryBasePriorityThread
 */
XBAPI LONG NTAPI __attribute__((weak))
KeQueryBasePriorityThread(
	PKTHREAD Thread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		LONG rval;
	} args;
	args._id = 124;
	args._size = sizeof(args);
	args.Thread = Thread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeQueryInterruptTime
 */
XBAPI ULONGLONG NTAPI __attribute__((weak))
KeQueryInterruptTime(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONGLONG rval;
	} args;
	args._id = 125;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeQueryPerformanceCounter
 */
XBAPI ULONGLONG NTAPI __attribute__((weak))
KeQueryPerformanceCounter(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONGLONG rval;
	} args;
	args._id = 126;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeQueryPerformanceFrequency
 */
XBAPI ULONGLONG NTAPI __attribute__((weak))
KeQueryPerformanceFrequency(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONGLONG rval;
	} args;
	args._id = 127;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeQuerySystemTime
 */
XBAPI VOID NTAPI __attribute__((weak))
KeQuerySystemTime(
	PLARGE_INTEGER CurrentTime
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLARGE_INTEGER CurrentTime;
	} args;
	args._id = 128;
	args._size = sizeof(args);
	args.CurrentTime = CurrentTime;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeRaiseIrqlToDpcLevel
 */
XBAPI KIRQL NTAPI __attribute__((weak))
KeRaiseIrqlToDpcLevel(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL rval;
	} args;
	args._id = 129;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRaiseIrqlToSynchLevel
 */
XBAPI KIRQL NTAPI __attribute__((weak))
KeRaiseIrqlToSynchLevel(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL rval;
	} args;
	args._id = 130;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeReleaseMutant
 */
XBAPI LONG NTAPI __attribute__((weak))
KeReleaseMutant(
	PRKMUTANT Mutant,
	KPRIORITY Increment,
	BOOLEAN   Abandoned,
	BOOLEAN   Wait
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKMUTANT Mutant;
		KPRIORITY Increment;
		BOOLEAN   Abandoned;
		BOOLEAN   Wait;
		LONG rval;
	} args;
	args._id = 131;
	args._size = sizeof(args);
	args.Mutant = Mutant;
	args.Increment = Increment;
	args.Abandoned = Abandoned;
	args.Wait = Wait;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeReleaseSemaphore
 */
XBAPI LONG NTAPI __attribute__((weak))
KeReleaseSemaphore(
	PRKSEMAPHORE Semaphore,
	KPRIORITY    Increment,
	LONG         Adjustment,
	BOOLEAN      Wait
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKSEMAPHORE Semaphore;
		KPRIORITY    Increment;
		LONG         Adjustment;
		BOOLEAN      Wait;
		LONG rval;
	} args;
	args._id = 132;
	args._size = sizeof(args);
	args.Semaphore = Semaphore;
	args.Increment = Increment;
	args.Adjustment = Adjustment;
	args.Wait = Wait;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRemoveByKeyDeviceQueue
 */
XBAPI PKDEVICE_QUEUE_ENTRY NTAPI __attribute__((weak))
KeRemoveByKeyDeviceQueue(
	PKDEVICE_QUEUE DeviceQueue,
	ULONG          SortKey
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE DeviceQueue;
		ULONG          SortKey;
		PKDEVICE_QUEUE_ENTRY rval;
	} args;
	args._id = 133;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	args.SortKey = SortKey;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRemoveDeviceQueue
 */
XBAPI PKDEVICE_QUEUE_ENTRY NTAPI __attribute__((weak))
KeRemoveDeviceQueue(
	PKDEVICE_QUEUE DeviceQueue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE DeviceQueue;
		PKDEVICE_QUEUE_ENTRY rval;
	} args;
	args._id = 134;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRemoveEntryDeviceQueue
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeRemoveEntryDeviceQueue(
	PKDEVICE_QUEUE DeviceQueue,
	PKDEVICE_QUEUE DeviceQueueEntry
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKDEVICE_QUEUE DeviceQueue;
		PKDEVICE_QUEUE DeviceQueueEntry;
		BOOLEAN rval;
	} args;
	args._id = 135;
	args._size = sizeof(args);
	args.DeviceQueue = DeviceQueue;
	args.DeviceQueueEntry = DeviceQueueEntry;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRemoveQueue
 */
XBAPI PLIST_ENTRY NTAPI __attribute__((weak))
KeRemoveQueue(
	PRKQUEUE        Queue,
	KPROCESSOR_MODE WaitMode,
	PLARGE_INTEGER  Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKQUEUE        Queue;
		KPROCESSOR_MODE WaitMode;
		PLARGE_INTEGER  Timeout;
		PLIST_ENTRY rval;
	} args;
	args._id = 136;
	args._size = sizeof(args);
	args.Queue = Queue;
	args.WaitMode = WaitMode;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRemoveQueueDpc
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeRemoveQueueDpc(
	PRKDPC Dpc
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKDPC Dpc;
		BOOLEAN rval;
	} args;
	args._id = 137;
	args._size = sizeof(args);
	args.Dpc = Dpc;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeResetEvent
 */
XBAPI LONG NTAPI __attribute__((weak))
KeResetEvent(
	PRKEVENT Event
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKEVENT Event;
		LONG rval;
	} args;
	args._id = 138;
	args._size = sizeof(args);
	args.Event = Event;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRestoreFloatingPointState
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
KeRestoreFloatingPointState(
	PKFLOATING_SAVE FloatSave
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKFLOATING_SAVE FloatSave;
		NTSTATUS rval;
	} args;
	args._id = 139;
	args._size = sizeof(args);
	args.FloatSave = FloatSave;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeResumeThread
 */
XBAPI ULONG NTAPI __attribute__((weak))
KeResumeThread(
	PKTHREAD Thread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		ULONG rval;
	} args;
	args._id = 140;
	args._size = sizeof(args);
	args.Thread = Thread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeRundownQueue
 */
XBAPI PLIST_ENTRY NTAPI __attribute__((weak))
KeRundownQueue(
	PRKQUEUE Queue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKQUEUE Queue;
		PLIST_ENTRY rval;
	} args;
	args._id = 141;
	args._size = sizeof(args);
	args.Queue = Queue;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSaveFloatingPointState
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
KeSaveFloatingPointState(
	PKFLOATING_SAVE FloatSave
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKFLOATING_SAVE FloatSave;
		NTSTATUS rval;
	} args;
	args._id = 142;
	args._size = sizeof(args);
	args.FloatSave = FloatSave;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetBasePriorityThread
 */
XBAPI LONG NTAPI __attribute__((weak))
KeSetBasePriorityThread(
	PKTHREAD Thread,
	LONG     Increment
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		LONG     Increment;
		LONG rval;
	} args;
	args._id = 143;
	args._size = sizeof(args);
	args.Thread = Thread;
	args.Increment = Increment;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetDisableBoostThread
 */
XBAPI LOGICAL NTAPI __attribute__((weak))
KeSetDisableBoostThread(
	PKTHREAD Thread,
	LOGICAL  Disable
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		LOGICAL  Disable;
		LOGICAL rval;
	} args;
	args._id = 144;
	args._size = sizeof(args);
	args.Thread = Thread;
	args.Disable = Disable;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetEvent
 */
XBAPI LONG NTAPI __attribute__((weak))
KeSetEvent(
	PRKEVENT  Event,
	KPRIORITY Increment,
	BOOLEAN   Wait
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKEVENT  Event;
		KPRIORITY Increment;
		BOOLEAN   Wait;
		LONG rval;
	} args;
	args._id = 145;
	args._size = sizeof(args);
	args.Event = Event;
	args.Increment = Increment;
	args.Wait = Wait;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetEventBoostPriority
 */
XBAPI VOID NTAPI __attribute__((weak))
KeSetEventBoostPriority(
	PRKEVENT   Event,
	PPRKTHREAD Thread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRKEVENT   Event;
		PPRKTHREAD Thread;
	} args;
	args._id = 146;
	args._size = sizeof(args);
	args.Event = Event;
	args.Thread = Thread;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeSetPriorityProcess
 */
XBAPI KPRIORITY NTAPI __attribute__((weak))
KeSetPriorityProcess(
	PKPROCESS Process,
	KPRIORITY BasePriority
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKPROCESS Process;
		KPRIORITY BasePriority;
		KPRIORITY rval;
	} args;
	args._id = 147;
	args._size = sizeof(args);
	args.Process = Process;
	args.BasePriority = BasePriority;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetPriorityThread
 */
XBAPI KPRIORITY NTAPI __attribute__((weak))
KeSetPriorityThread(
	PKTHREAD  Thread,
	KPRIORITY Priority
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD  Thread;
		KPRIORITY Priority;
		KPRIORITY rval;
	} args;
	args._id = 148;
	args._size = sizeof(args);
	args.Thread = Thread;
	args.Priority = Priority;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetTimer
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeSetTimer(
	PKTIMER       Timer,
	LARGE_INTEGER DueTime,
	PKDPC         Dpc
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTIMER       Timer;
		LARGE_INTEGER DueTime;
		PKDPC         Dpc;
		BOOLEAN rval;
	} args;
	args._id = 149;
	args._size = sizeof(args);
	args.Timer = Timer;
	args.DueTime = DueTime;
	args.Dpc = Dpc;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSetTimerEx
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeSetTimerEx(
	PKTIMER       Timer,
	LARGE_INTEGER DueTime,
	LONG          Period,
	PKDPC         Dpc
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTIMER       Timer;
		LARGE_INTEGER DueTime;
		LONG          Period;
		PKDPC         Dpc;
		BOOLEAN rval;
	} args;
	args._id = 150;
	args._size = sizeof(args);
	args.Timer = Timer;
	args.DueTime = DueTime;
	args.Period = Period;
	args.Dpc = Dpc;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeStallExecutionProcessor
 */
XBAPI VOID NTAPI __attribute__((weak))
KeStallExecutionProcessor(
	ULONG MicroSeconds
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG MicroSeconds;
	} args;
	args._id = 151;
	args._size = sizeof(args);
	args.MicroSeconds = MicroSeconds;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KeSuspendThread
 */
XBAPI ULONG NTAPI __attribute__((weak))
KeSuspendThread(
	PKTHREAD Thread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKTHREAD Thread;
		ULONG rval;
	} args;
	args._id = 152;
	args._size = sizeof(args);
	args.Thread = Thread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeSynchronizeExecution
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeSynchronizeExecution(
	PKINTERRUPT           Interrupt,
	PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
	PVOID                 SynchronizeContext
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PKINTERRUPT           Interrupt;
		PKSYNCHRONIZE_ROUTINE SynchronizeRoutine;
		PVOID                 SynchronizeContext;
		BOOLEAN rval;
	} args;
	args._id = 153;
	args._size = sizeof(args);
	args.Interrupt = Interrupt;
	args.SynchronizeRoutine = SynchronizeRoutine;
	args.SynchronizeContext = SynchronizeContext;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeTestAlertThread
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
KeTestAlertThread(
	KPROCESSOR_MODE ProcessorMode
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KPROCESSOR_MODE ProcessorMode;
		BOOLEAN rval;
	} args;
	args._id = 155;
	args._size = sizeof(args);
	args.ProcessorMode = ProcessorMode;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeWaitForMultipleObjects
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
KeWaitForMultipleObjects(
	ULONG           Count,
	PVOID           Object[],
	WAIT_TYPE       WaitType,
	KWAIT_REASON    WaitReason,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Timeout,
	PKWAIT_BLOCK    WaitBlockArray
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG           Count;
		PVOID           Object;
		WAIT_TYPE       WaitType;
		KWAIT_REASON    WaitReason;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Timeout;
		PKWAIT_BLOCK    WaitBlockArray;
		NTSTATUS rval;
	} args;
	args._id = 158;
	args._size = sizeof(args);
	args.Count = Count;
	args.Object = Object;
	args.WaitType = WaitType;
	args.WaitReason = WaitReason;
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	args.WaitBlockArray = WaitBlockArray;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KeWaitForSingleObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
KeWaitForSingleObject(
	PVOID           Object,
	KWAIT_REASON    WaitReason,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID           Object;
		KWAIT_REASON    WaitReason;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Timeout;
		NTSTATUS rval;
	} args;
	args._id = 159;
	args._size = sizeof(args);
	args.Object = Object;
	args.WaitReason = WaitReason;
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KfLowerIrql
 */
XBAPI VOID FASTCALL __attribute__((weak))
KfLowerIrql(
	KIRQL NewIrql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL NewIrql;
	} args;
	args._id = 161;
	args._size = sizeof(args);
	args.NewIrql = NewIrql;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * KfRaiseIrql
 */
XBAPI KIRQL FASTCALL __attribute__((weak))
KfRaiseIrql(
	KIRQL NewIrql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL NewIrql;
		KIRQL rval;
	} args;
	args._id = 160;
	args._size = sizeof(args);
	args.NewIrql = NewIrql;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * KiUnlockDispatcherDatabase
 */
XBAPI VOID FASTCALL __attribute__((weak))
KiUnlockDispatcherDatabase(
	KIRQL OldIrql
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		KIRQL OldIrql;
	} args;
	args._id = 163;
	args._size = sizeof(args);
	args.OldIrql = OldIrql;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmAllocateContiguousMemory
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmAllocateContiguousMemory(
	SIZE_T NumberOfBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T NumberOfBytes;
		PVOID rval;
	} args;
	args._id = 165;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmAllocateContiguousMemoryEx
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmAllocateContiguousMemoryEx(
	SIZE_T    NumberOfBytes,
	ULONG_PTR LowestAcceptableAddress,
	ULONG_PTR HighestAcceptableAddress,
	ULONG_PTR Alignment,
	ULONG     Protect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T    NumberOfBytes;
		ULONG_PTR LowestAcceptableAddress;
		ULONG_PTR HighestAcceptableAddress;
		ULONG_PTR Alignment;
		ULONG     Protect;
		PVOID rval;
	} args;
	args._id = 166;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.LowestAcceptableAddress = LowestAcceptableAddress;
	args.HighestAcceptableAddress = HighestAcceptableAddress;
	args.Alignment = Alignment;
	args.Protect = Protect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmAllocateSystemMemory
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmAllocateSystemMemory(
	SIZE_T NumberOfBytes,
	ULONG  Protect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T NumberOfBytes;
		ULONG  Protect;
		PVOID rval;
	} args;
	args._id = 167;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.Protect = Protect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmClaimGpuInstanceMemory
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmClaimGpuInstanceMemory(
	SIZE_T  NumberOfBytes,
	PSIZE_T NumberOfPaddingBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T  NumberOfBytes;
		PSIZE_T NumberOfPaddingBytes;
		PVOID rval;
	} args;
	args._id = 168;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.NumberOfPaddingBytes = NumberOfPaddingBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmCreateKernelStack
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmCreateKernelStack(
	SIZE_T  NumberOfBytes,
	BOOLEAN DebuggerThread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T  NumberOfBytes;
		BOOLEAN DebuggerThread;
		PVOID rval;
	} args;
	args._id = 169;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.DebuggerThread = DebuggerThread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmDbgAllocateMemory
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmDbgAllocateMemory(
	SIZE_T NumberOfBytes,
	ULONG  Protect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		SIZE_T NumberOfBytes;
		ULONG  Protect;
		PVOID rval;
	} args;
	args._id = 374;
	args._size = sizeof(args);
	args.NumberOfBytes = NumberOfBytes;
	args.Protect = Protect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmDbgFreeMemory
 */
XBAPI ULONG NTAPI __attribute__((weak))
MmDbgFreeMemory(
	PVOID  BaseAddress,
	SIZE_T NumberOfBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  BaseAddress;
		SIZE_T NumberOfBytes;
		ULONG rval;
	} args;
	args._id = 375;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmDbgQueryAvailablePages
 */
XBAPI PFN_COUNT NTAPI __attribute__((weak))
MmDbgQueryAvailablePages(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PFN_COUNT rval;
	} args;
	args._id = 376;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmDbgReleaseAddress
 */
XBAPI VOID NTAPI __attribute__((weak))
MmDbgReleaseAddress(
	PVOID         VirtualAddress,
	PHARDWARE_PTE Opaque
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID         VirtualAddress;
		PHARDWARE_PTE Opaque;
	} args;
	args._id = 377;
	args._size = sizeof(args);
	args.VirtualAddress = VirtualAddress;
	args.Opaque = Opaque;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmDbgWriteCheck
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmDbgWriteCheck(
	PVOID         VirtualAddress,
	PHARDWARE_PTE Opaque
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID         VirtualAddress;
		PHARDWARE_PTE Opaque;
		PVOID rval;
	} args;
	args._id = 378;
	args._size = sizeof(args);
	args.VirtualAddress = VirtualAddress;
	args.Opaque = Opaque;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmDeleteKernelStack
 */
XBAPI VOID NTAPI __attribute__((weak))
MmDeleteKernelStack(
	PVOID KernelStackBase,
	PVOID KernelStackLimit
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID KernelStackBase;
		PVOID KernelStackLimit;
	} args;
	args._id = 170;
	args._size = sizeof(args);
	args.KernelStackBase = KernelStackBase;
	args.KernelStackLimit = KernelStackLimit;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmFreeContiguousMemory
 */
XBAPI VOID NTAPI __attribute__((weak))
MmFreeContiguousMemory(
	PVOID BaseAddress
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID BaseAddress;
	} args;
	args._id = 171;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmFreeSystemMemory
 */
XBAPI ULONG NTAPI __attribute__((weak))
MmFreeSystemMemory(
	PVOID  BaseAddress,
	SIZE_T NumberOfBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  BaseAddress;
		SIZE_T NumberOfBytes;
		ULONG rval;
	} args;
	args._id = 172;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmGetPhysicalAddress
 */
XBAPI ULONG_PTR NTAPI __attribute__((weak))
MmGetPhysicalAddress(
	PVOID BaseAddress
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID BaseAddress;
		ULONG_PTR rval;
	} args;
	args._id = 173;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmIsAddressValid
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
MmIsAddressValid(
	PVOID VirtualAddress
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID VirtualAddress;
		BOOLEAN rval;
	} args;
	args._id = 174;
	args._size = sizeof(args);
	args.VirtualAddress = VirtualAddress;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmLockUnlockBufferPages
 */
XBAPI VOID NTAPI __attribute__((weak))
MmLockUnlockBufferPages(
	PVOID   BaseAddress,
	SIZE_T  NumberOfBytes,
	BOOLEAN UnlockPages
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID   BaseAddress;
		SIZE_T  NumberOfBytes;
		BOOLEAN UnlockPages;
	} args;
	args._id = 175;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	args.UnlockPages = UnlockPages;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmLockUnlockPhysicalPage
 */
XBAPI VOID NTAPI __attribute__((weak))
MmLockUnlockPhysicalPage(
	ULONG_PTR PhysicalAddress,
	BOOLEAN   UnlockPage
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG_PTR PhysicalAddress;
		BOOLEAN   UnlockPage;
	} args;
	args._id = 176;
	args._size = sizeof(args);
	args.PhysicalAddress = PhysicalAddress;
	args.UnlockPage = UnlockPage;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmMapIoSpace
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmMapIoSpace(
	ULONG_PTR PhysicalAddress,
	SIZE_T    NumberOfBytes,
	ULONG     Protect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG_PTR PhysicalAddress;
		SIZE_T    NumberOfBytes;
		ULONG     Protect;
		PVOID rval;
	} args;
	args._id = 177;
	args._size = sizeof(args);
	args.PhysicalAddress = PhysicalAddress;
	args.NumberOfBytes = NumberOfBytes;
	args.Protect = Protect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmPersistContiguousMemory
 */
XBAPI VOID NTAPI __attribute__((weak))
MmPersistContiguousMemory(
	PVOID   BaseAddress,
	SIZE_T  NumberOfBytes,
	BOOLEAN Persist
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID   BaseAddress;
		SIZE_T  NumberOfBytes;
		BOOLEAN Persist;
	} args;
	args._id = 178;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	args.Persist = Persist;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmQueryAddressProtect
 */
XBAPI ULONG NTAPI __attribute__((weak))
MmQueryAddressProtect(
	PVOID VirtualAddress
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID VirtualAddress;
		ULONG rval;
	} args;
	args._id = 179;
	args._size = sizeof(args);
	args.VirtualAddress = VirtualAddress;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmQueryAllocationSize
 */
XBAPI SIZE_T NTAPI __attribute__((weak))
MmQueryAllocationSize(
	PVOID BaseAddress
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID BaseAddress;
		SIZE_T rval;
	} args;
	args._id = 180;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmQueryStatistics
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
MmQueryStatistics(
	PMM_STATISTICS MemoryStatistics
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PMM_STATISTICS MemoryStatistics;
		NTSTATUS rval;
	} args;
	args._id = 181;
	args._size = sizeof(args);
	args.MemoryStatistics = MemoryStatistics;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * MmSetAddressProtect
 */
XBAPI VOID NTAPI __attribute__((weak))
MmSetAddressProtect(
	PVOID BaseAddress,
	ULONG NumberOfBytes,
	ULONG NewProtect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID BaseAddress;
		ULONG NumberOfBytes;
		ULONG NewProtect;
	} args;
	args._id = 182;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	args.NewProtect = NewProtect;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * MmUnmapIoSpace
 */
XBAPI PVOID NTAPI __attribute__((weak))
MmUnmapIoSpace(
	PVOID  BaseAddress,
	SIZE_T NumberOfBytes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  BaseAddress;
		SIZE_T NumberOfBytes;
		PVOID rval;
	} args;
	args._id = 183;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.NumberOfBytes = NumberOfBytes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtAllocateVirtualMemory
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtAllocateVirtualMemory(
	PPVOID    BaseAddress,
	ULONG_PTR ZeroBits,
	PSIZE_T   RegionSize,
	ULONG     AllocationType,
	ULONG     Protect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPVOID    BaseAddress;
		ULONG_PTR ZeroBits;
		PSIZE_T   RegionSize;
		ULONG     AllocationType;
		ULONG     Protect;
		NTSTATUS rval;
	} args;
	args._id = 184;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.ZeroBits = ZeroBits;
	args.RegionSize = RegionSize;
	args.AllocationType = AllocationType;
	args.Protect = Protect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCancelTimer
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCancelTimer(
	HANDLE   TimerHandle,
	PBOOLEAN CurrentState
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE   TimerHandle;
		PBOOLEAN CurrentState;
		NTSTATUS rval;
	} args;
	args._id = 185;
	args._size = sizeof(args);
	args.TimerHandle = TimerHandle;
	args.CurrentState = CurrentState;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtClearEvent
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtClearEvent(
	HANDLE EventHandle
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE EventHandle;
		NTSTATUS rval;
	} args;
	args._id = 186;
	args._size = sizeof(args);
	args.EventHandle = EventHandle;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtClose
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtClose(
	HANDLE Handle
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE Handle;
		NTSTATUS rval;
	} args;
	args._id = 187;
	args._size = sizeof(args);
	args.Handle = Handle;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateDirectoryObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateDirectoryObject(
	PHANDLE            DirectoryHandle,
	POBJECT_ATTRIBUTES ObjectAttributes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            DirectoryHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		NTSTATUS rval;
	} args;
	args._id = 188;
	args._size = sizeof(args);
	args.DirectoryHandle = DirectoryHandle;
	args.ObjectAttributes = ObjectAttributes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateEvent
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateEvent(
	PHANDLE            EventHandle,
	POBJECT_ATTRIBUTES ObjectAttributes,
	EVENT_TYPE         EventType,
	BOOLEAN            InitialState
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            EventHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		EVENT_TYPE         EventType;
		BOOLEAN            InitialState;
		NTSTATUS rval;
	} args;
	args._id = 189;
	args._size = sizeof(args);
	args.EventHandle = EventHandle;
	args.ObjectAttributes = ObjectAttributes;
	args.EventType = EventType;
	args.InitialState = InitialState;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateFile(
	PHANDLE            FileHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK   IoStatusBlock,
	PLARGE_INTEGER     AllocationSize,
	ULONG              FileAttributes,
	ULONG              ShareAccess,
	ULONG              CreateDisposition,
	ULONG              CreateOptions
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            FileHandle;
		ACCESS_MASK        DesiredAccess;
		POBJECT_ATTRIBUTES ObjectAttributes;
		PIO_STATUS_BLOCK   IoStatusBlock;
		PLARGE_INTEGER     AllocationSize;
		ULONG              FileAttributes;
		ULONG              ShareAccess;
		ULONG              CreateDisposition;
		ULONG              CreateOptions;
		NTSTATUS rval;
	} args;
	args._id = 190;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.DesiredAccess = DesiredAccess;
	args.ObjectAttributes = ObjectAttributes;
	args.IoStatusBlock = IoStatusBlock;
	args.AllocationSize = AllocationSize;
	args.FileAttributes = FileAttributes;
	args.ShareAccess = ShareAccess;
	args.CreateDisposition = CreateDisposition;
	args.CreateOptions = CreateOptions;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateIoCompletion
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateIoCompletion(
	PHANDLE            IoCompletionHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	ULONG              Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            IoCompletionHandle;
		ACCESS_MASK        DesiredAccess;
		POBJECT_ATTRIBUTES ObjectAttributes;
		ULONG              Count;
		NTSTATUS rval;
	} args;
	args._id = 191;
	args._size = sizeof(args);
	args.IoCompletionHandle = IoCompletionHandle;
	args.DesiredAccess = DesiredAccess;
	args.ObjectAttributes = ObjectAttributes;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateMutant
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateMutant(
	PHANDLE            MutantHandle,
	POBJECT_ATTRIBUTES ObjectAttributes,
	BOOLEAN            InitialOwner
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            MutantHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		BOOLEAN            InitialOwner;
		NTSTATUS rval;
	} args;
	args._id = 192;
	args._size = sizeof(args);
	args.MutantHandle = MutantHandle;
	args.ObjectAttributes = ObjectAttributes;
	args.InitialOwner = InitialOwner;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateSemaphore
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateSemaphore(
	PHANDLE            SemaphoreHandle,
	POBJECT_ATTRIBUTES ObjectAttributes,
	LONG               InitialCount,
	LONG               MaximumCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            SemaphoreHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		LONG               InitialCount;
		LONG               MaximumCount;
		NTSTATUS rval;
	} args;
	args._id = 193;
	args._size = sizeof(args);
	args.SemaphoreHandle = SemaphoreHandle;
	args.ObjectAttributes = ObjectAttributes;
	args.InitialCount = InitialCount;
	args.MaximumCount = MaximumCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtCreateTimer
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtCreateTimer(
	PHANDLE            TimerHandle,
	POBJECT_ATTRIBUTES ObjectAttributes,
	TIMER_TYPE         TimerType
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            TimerHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		TIMER_TYPE         TimerType;
		NTSTATUS rval;
	} args;
	args._id = 194;
	args._size = sizeof(args);
	args.TimerHandle = TimerHandle;
	args.ObjectAttributes = ObjectAttributes;
	args.TimerType = TimerType;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtDeleteFile
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
NtDeleteFile(
	POBJECT_ATTRIBUTES ObjectAttributes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_ATTRIBUTES ObjectAttributes;
		BOOLEAN rval;
	} args;
	args._id = 195;
	args._size = sizeof(args);
	args.ObjectAttributes = ObjectAttributes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtDeviceIoControlFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtDeviceIoControlFile(
	HANDLE           FileHandle,
	HANDLE           Event,
	PIO_APC_ROUTINE  ApcRoutine,
	PVOID            ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	ULONG            IoControlCode,
	PVOID            InputBuffer,
	ULONG            InputBufferLength,
	PVOID            OutputBuffer,
	ULONG            OutputBufferLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           FileHandle;
		HANDLE           Event;
		PIO_APC_ROUTINE  ApcRoutine;
		PVOID            ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		ULONG            IoControlCode;
		PVOID            InputBuffer;
		ULONG            InputBufferLength;
		PVOID            OutputBuffer;
		ULONG            OutputBufferLength;
		NTSTATUS rval;
	} args;
	args._id = 196;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.IoControlCode = IoControlCode;
	args.InputBuffer = InputBuffer;
	args.InputBufferLength = InputBufferLength;
	args.OutputBuffer = OutputBuffer;
	args.OutputBufferLength = OutputBufferLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtDuplicateObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtDuplicateObject(
	HANDLE  SourceHandle,
	PHANDLE TargetHandle,
	ULONG   Options
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE  SourceHandle;
		PHANDLE TargetHandle;
		ULONG   Options;
		NTSTATUS rval;
	} args;
	args._id = 197;
	args._size = sizeof(args);
	args.SourceHandle = SourceHandle;
	args.TargetHandle = TargetHandle;
	args.Options = Options;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtFlushBuffersFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtFlushBuffersFile(
	HANDLE           FileHandle,
	PIO_STATUS_BLOCK IoStatusBlock
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           FileHandle;
		PIO_STATUS_BLOCK IoStatusBlock;
		NTSTATUS rval;
	} args;
	args._id = 198;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.IoStatusBlock = IoStatusBlock;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtFreeVirtualMemory
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtFreeVirtualMemory(
	PPVOID  BaseAddress,
	PSIZE_T RegionSize,
	ULONG   FreeType
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPVOID  BaseAddress;
		PSIZE_T RegionSize;
		ULONG   FreeType;
		NTSTATUS rval;
	} args;
	args._id = 199;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.RegionSize = RegionSize;
	args.FreeType = FreeType;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtFsControlFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtFsControlFile(
	HANDLE           FileHandle,
	HANDLE           Event,
	PIO_APC_ROUTINE  ApcRoutine,
	PVOID            ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	ULONG            FsControlCode,
	PVOID            InputBuffer,
	ULONG            InputBufferLength,
	PVOID            OutputBuffer,
	ULONG            OutputBufferLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           FileHandle;
		HANDLE           Event;
		PIO_APC_ROUTINE  ApcRoutine;
		PVOID            ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		ULONG            FsControlCode;
		PVOID            InputBuffer;
		ULONG            InputBufferLength;
		PVOID            OutputBuffer;
		ULONG            OutputBufferLength;
		NTSTATUS rval;
	} args;
	args._id = 200;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.FsControlCode = FsControlCode;
	args.InputBuffer = InputBuffer;
	args.InputBufferLength = InputBufferLength;
	args.OutputBuffer = OutputBuffer;
	args.OutputBufferLength = OutputBufferLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtOpenDirectoryObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtOpenDirectoryObject(
	PHANDLE            DirectoryHandle,
	POBJECT_ATTRIBUTES ObjectAttributes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            DirectoryHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		NTSTATUS rval;
	} args;
	args._id = 201;
	args._size = sizeof(args);
	args.DirectoryHandle = DirectoryHandle;
	args.ObjectAttributes = ObjectAttributes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtOpenFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtOpenFile(
	PHANDLE            FileHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK   IoStatusBlock,
	ULONG              ShareAccess,
	ULONG              OpenOptions
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            FileHandle;
		ACCESS_MASK        DesiredAccess;
		POBJECT_ATTRIBUTES ObjectAttributes;
		PIO_STATUS_BLOCK   IoStatusBlock;
		ULONG              ShareAccess;
		ULONG              OpenOptions;
		NTSTATUS rval;
	} args;
	args._id = 202;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.DesiredAccess = DesiredAccess;
	args.ObjectAttributes = ObjectAttributes;
	args.IoStatusBlock = IoStatusBlock;
	args.ShareAccess = ShareAccess;
	args.OpenOptions = OpenOptions;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtOpenSymbolicLinkObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtOpenSymbolicLinkObject(
	PHANDLE            LinkHandle,
	POBJECT_ATTRIBUTES ObjectAttributes
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE            LinkHandle;
		POBJECT_ATTRIBUTES ObjectAttributes;
		NTSTATUS rval;
	} args;
	args._id = 203;
	args._size = sizeof(args);
	args.LinkHandle = LinkHandle;
	args.ObjectAttributes = ObjectAttributes;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtProtectVirtualMemory
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtProtectVirtualMemory(
	PPVOID  BaseAddress,
	PSIZE_T RegionSize,
	ULONG   NewProtect,
	PULONG  OldProtect
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPVOID  BaseAddress;
		PSIZE_T RegionSize;
		ULONG   NewProtect;
		PULONG  OldProtect;
		NTSTATUS rval;
	} args;
	args._id = 204;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.RegionSize = RegionSize;
	args.NewProtect = NewProtect;
	args.OldProtect = OldProtect;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtPulseEvent
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtPulseEvent(
	HANDLE EventHandle,
	PLONG  PreviousState
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE EventHandle;
		PLONG  PreviousState;
		NTSTATUS rval;
	} args;
	args._id = 205;
	args._size = sizeof(args);
	args.EventHandle = EventHandle;
	args.PreviousState = PreviousState;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryDirectoryFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryDirectoryFile(
	HANDLE                 FileHandle,
	HANDLE                 Event,
	PIO_APC_ROUTINE        ApcRoutine,
	PVOID                  ApcContext,
	PIO_STATUS_BLOCK       IoStatusBlock,
	PVOID                  FileInformation,
	ULONG                  Length,
	FILE_INFORMATION_CLASS FileInformationClass,
	POBJECT_STRING         FileName,
	BOOLEAN                RestartScan
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                 FileHandle;
		HANDLE                 Event;
		PIO_APC_ROUTINE        ApcRoutine;
		PVOID                  ApcContext;
		PIO_STATUS_BLOCK       IoStatusBlock;
		PVOID                  FileInformation;
		ULONG                  Length;
		FILE_INFORMATION_CLASS FileInformationClass;
		POBJECT_STRING         FileName;
		BOOLEAN                RestartScan;
		NTSTATUS rval;
	} args;
	args._id = 207;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.FileInformation = FileInformation;
	args.Length = Length;
	args.FileInformationClass = FileInformationClass;
	args.FileName = FileName;
	args.RestartScan = RestartScan;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryDirectoryObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryDirectoryObject(
	HANDLE  DirectoryHandle,
	PVOID   Buffer,
	ULONG   Length,
	BOOLEAN RestartScan,
	PULONG  Context,
	PULONG  ReturnLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE  DirectoryHandle;
		PVOID   Buffer;
		ULONG   Length;
		BOOLEAN RestartScan;
		PULONG  Context;
		PULONG  ReturnLength;
		NTSTATUS rval;
	} args;
	args._id = 208;
	args._size = sizeof(args);
	args.DirectoryHandle = DirectoryHandle;
	args.Buffer = Buffer;
	args.Length = Length;
	args.RestartScan = RestartScan;
	args.Context = Context;
	args.ReturnLength = ReturnLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryEvent
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryEvent(
	HANDLE                   EventHandle,
	PEVENT_BASIC_INFORMATION EventInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                   EventHandle;
		PEVENT_BASIC_INFORMATION EventInformation;
		NTSTATUS rval;
	} args;
	args._id = 209;
	args._size = sizeof(args);
	args.EventHandle = EventHandle;
	args.EventInformation = EventInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryFullAttributesFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryFullAttributesFile(
	POBJECT_ATTRIBUTES             ObjectAttributes,
	PFILE_NETWORK_OPEN_INFORMATION FileInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_ATTRIBUTES             ObjectAttributes;
		PFILE_NETWORK_OPEN_INFORMATION FileInformation;
		NTSTATUS rval;
	} args;
	args._id = 210;
	args._size = sizeof(args);
	args.ObjectAttributes = ObjectAttributes;
	args.FileInformation = FileInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryInformationFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryInformationFile(
	HANDLE                 FileHandle,
	PIO_STATUS_BLOCK       IoStatusBlock,
	PVOID                  FileInformation,
	ULONG                  Length,
	FILE_INFORMATION_CLASS FileInformationClass
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                 FileHandle;
		PIO_STATUS_BLOCK       IoStatusBlock;
		PVOID                  FileInformation;
		ULONG                  Length;
		FILE_INFORMATION_CLASS FileInformationClass;
		NTSTATUS rval;
	} args;
	args._id = 211;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.IoStatusBlock = IoStatusBlock;
	args.FileInformation = FileInformation;
	args.Length = Length;
	args.FileInformationClass = FileInformationClass;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryIoCompletion
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryIoCompletion(
	HANDLE                           IoCompletionHandle,
	PIO_COMPLETION_BASIC_INFORMATION IoCompletionInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                           IoCompletionHandle;
		PIO_COMPLETION_BASIC_INFORMATION IoCompletionInformation;
		NTSTATUS rval;
	} args;
	args._id = 212;
	args._size = sizeof(args);
	args.IoCompletionHandle = IoCompletionHandle;
	args.IoCompletionInformation = IoCompletionInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryMutant
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryMutant(
	HANDLE                    MutantHandle,
	PMUTANT_BASIC_INFORMATION MutantInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                    MutantHandle;
		PMUTANT_BASIC_INFORMATION MutantInformation;
		NTSTATUS rval;
	} args;
	args._id = 213;
	args._size = sizeof(args);
	args.MutantHandle = MutantHandle;
	args.MutantInformation = MutantInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQuerySemaphore
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQuerySemaphore(
	HANDLE                       SemaphoreHandle,
	PSEMAPHORE_BASIC_INFORMATION SemaphoreInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                       SemaphoreHandle;
		PSEMAPHORE_BASIC_INFORMATION SemaphoreInformation;
		NTSTATUS rval;
	} args;
	args._id = 214;
	args._size = sizeof(args);
	args.SemaphoreHandle = SemaphoreHandle;
	args.SemaphoreInformation = SemaphoreInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQuerySymbolicLinkObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQuerySymbolicLinkObject(
	HANDLE         LinkHandle,
	POBJECT_STRING LinkTarget,
	PULONG         ReturnedLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE         LinkHandle;
		POBJECT_STRING LinkTarget;
		PULONG         ReturnedLength;
		NTSTATUS rval;
	} args;
	args._id = 215;
	args._size = sizeof(args);
	args.LinkHandle = LinkHandle;
	args.LinkTarget = LinkTarget;
	args.ReturnedLength = ReturnedLength;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryTimer
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryTimer(
	HANDLE                   TimerHandle,
	PTIMER_BASIC_INFORMATION TimerInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                   TimerHandle;
		PTIMER_BASIC_INFORMATION TimerInformation;
		NTSTATUS rval;
	} args;
	args._id = 216;
	args._size = sizeof(args);
	args.TimerHandle = TimerHandle;
	args.TimerInformation = TimerInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryVirtualMemory
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryVirtualMemory(
	PVOID                     BaseAddress,
	PMEMORY_BASIC_INFORMATION MemoryInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID                     BaseAddress;
		PMEMORY_BASIC_INFORMATION MemoryInformation;
		NTSTATUS rval;
	} args;
	args._id = 217;
	args._size = sizeof(args);
	args.BaseAddress = BaseAddress;
	args.MemoryInformation = MemoryInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueryVolumeInformationFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueryVolumeInformationFile(
	HANDLE               FileHandle,
	PIO_STATUS_BLOCK     IoStatusBlock,
	PVOID                FsInformation,
	ULONG                Length,
	FS_INFORMATION_CLASS FsInformationClass
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE               FileHandle;
		PIO_STATUS_BLOCK     IoStatusBlock;
		PVOID                FsInformation;
		ULONG                Length;
		FS_INFORMATION_CLASS FsInformationClass;
		NTSTATUS rval;
	} args;
	args._id = 218;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.IoStatusBlock = IoStatusBlock;
	args.FsInformation = FsInformation;
	args.Length = Length;
	args.FsInformationClass = FsInformationClass;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtQueueApcThread
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtQueueApcThread(
	HANDLE          ThreadHandle,
	PPS_APC_ROUTINE ApcRoutine,
	PVOID           ApcArgument1,
	PVOID           ApcArgument2,
	PVOID           ApcArgument3
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE          ThreadHandle;
		PPS_APC_ROUTINE ApcRoutine;
		PVOID           ApcArgument1;
		PVOID           ApcArgument2;
		PVOID           ApcArgument3;
		NTSTATUS rval;
	} args;
	args._id = 206;
	args._size = sizeof(args);
	args.ThreadHandle = ThreadHandle;
	args.ApcRoutine = ApcRoutine;
	args.ApcArgument1 = ApcArgument1;
	args.ApcArgument2 = ApcArgument2;
	args.ApcArgument3 = ApcArgument3;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtReadFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtReadFile(
	HANDLE           FileHandle,
	HANDLE           Event,
	PIO_APC_ROUTINE  ApcRoutine,
	PVOID            ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	PVOID            Buffer,
	ULONG            Length,
	PLARGE_INTEGER   ByteOffset
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           FileHandle;
		HANDLE           Event;
		PIO_APC_ROUTINE  ApcRoutine;
		PVOID            ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		PVOID            Buffer;
		ULONG            Length;
		PLARGE_INTEGER   ByteOffset;
		NTSTATUS rval;
	} args;
	args._id = 219;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.Buffer = Buffer;
	args.Length = Length;
	args.ByteOffset = ByteOffset;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtReadFileScatter
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtReadFileScatter(
	HANDLE                FileHandle,
	HANDLE                Event,
	PIO_APC_ROUTINE       ApcRoutine,
	PVOID                 ApcContext,
	PIO_STATUS_BLOCK      IoStatusBlock,
	PFILE_SEGMENT_ELEMENT SegmentArray,
	ULONG                 Length,
	PLARGE_INTEGER        ByteOffset
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                FileHandle;
		HANDLE                Event;
		PIO_APC_ROUTINE       ApcRoutine;
		PVOID                 ApcContext;
		PIO_STATUS_BLOCK      IoStatusBlock;
		PFILE_SEGMENT_ELEMENT SegmentArray;
		ULONG                 Length;
		PLARGE_INTEGER        ByteOffset;
		NTSTATUS rval;
	} args;
	args._id = 220;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.SegmentArray = SegmentArray;
	args.Length = Length;
	args.ByteOffset = ByteOffset;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtReleaseMutant
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtReleaseMutant(
	HANDLE MutantHandle,
	PLONG  PreviousCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE MutantHandle;
		PLONG  PreviousCount;
		NTSTATUS rval;
	} args;
	args._id = 221;
	args._size = sizeof(args);
	args.MutantHandle = MutantHandle;
	args.PreviousCount = PreviousCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtReleaseSemaphore
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtReleaseSemaphore(
	HANDLE SemaphoreHandle,
	LONG   ReleaseCount,
	PLONG  PreviousCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE SemaphoreHandle;
		LONG   ReleaseCount;
		PLONG  PreviousCount;
		NTSTATUS rval;
	} args;
	args._id = 222;
	args._size = sizeof(args);
	args.SemaphoreHandle = SemaphoreHandle;
	args.ReleaseCount = ReleaseCount;
	args.PreviousCount = PreviousCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtRemoveIoCompletion
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtRemoveIoCompletion(
	HANDLE           IoCompletionHandle,
	PPVOID           KeyContext,
	PPVOID           ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	PLARGE_INTEGER   Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           IoCompletionHandle;
		PPVOID           KeyContext;
		PPVOID           ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		PLARGE_INTEGER   Timeout;
		NTSTATUS rval;
	} args;
	args._id = 223;
	args._size = sizeof(args);
	args.IoCompletionHandle = IoCompletionHandle;
	args.KeyContext = KeyContext;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtResumeThread
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtResumeThread(
	HANDLE ThreadHandle,
	PULONG PreviousSuspendCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE ThreadHandle;
		PULONG PreviousSuspendCount;
		NTSTATUS rval;
	} args;
	args._id = 224;
	args._size = sizeof(args);
	args.ThreadHandle = ThreadHandle;
	args.PreviousSuspendCount = PreviousSuspendCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSetEvent
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSetEvent(
	HANDLE EventHandle,
	PLONG  PreviousState
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE EventHandle;
		PLONG  PreviousState;
		NTSTATUS rval;
	} args;
	args._id = 225;
	args._size = sizeof(args);
	args.EventHandle = EventHandle;
	args.PreviousState = PreviousState;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSetInformationFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSetInformationFile(
	HANDLE                 FileHandle,
	PIO_STATUS_BLOCK       IoStatusBlock,
	PVOID                  FileInformation,
	ULONG                  Length,
	FILE_INFORMATION_CLASS FileInformationClass
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                 FileHandle;
		PIO_STATUS_BLOCK       IoStatusBlock;
		PVOID                  FileInformation;
		ULONG                  Length;
		FILE_INFORMATION_CLASS FileInformationClass;
		NTSTATUS rval;
	} args;
	args._id = 226;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.IoStatusBlock = IoStatusBlock;
	args.FileInformation = FileInformation;
	args.Length = Length;
	args.FileInformationClass = FileInformationClass;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSetIoCompletion
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSetIoCompletion(
	HANDLE    IoCompletionHandle,
	PVOID     KeyContext,
	PVOID     ApcContext,
	NTSTATUS  IoStatus,
	ULONG_PTR IoStatusInformation
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE    IoCompletionHandle;
		PVOID     KeyContext;
		PVOID     ApcContext;
		NTSTATUS  IoStatus;
		ULONG_PTR IoStatusInformation;
		NTSTATUS rval;
	} args;
	args._id = 227;
	args._size = sizeof(args);
	args.IoCompletionHandle = IoCompletionHandle;
	args.KeyContext = KeyContext;
	args.ApcContext = ApcContext;
	args.IoStatus = IoStatus;
	args.IoStatusInformation = IoStatusInformation;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSetSystemTime
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSetSystemTime(
	PLARGE_INTEGER SystemTime,
	PLARGE_INTEGER PreviousTime
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLARGE_INTEGER SystemTime;
		PLARGE_INTEGER PreviousTime;
		NTSTATUS rval;
	} args;
	args._id = 228;
	args._size = sizeof(args);
	args.SystemTime = SystemTime;
	args.PreviousTime = PreviousTime;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSetTimerEx
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSetTimerEx(
	HANDLE             TimerHandle,
	PLARGE_INTEGER     DueTime,
	PTIMER_APC_ROUTINE TimerApcRoutine,
	KPROCESSOR_MODE    ApcMode,
	PVOID              TimerContext,
	BOOLEAN            ResumeTimer,
	LONG               Period,
	PBOOLEAN           PreviousState
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE             TimerHandle;
		PLARGE_INTEGER     DueTime;
		PTIMER_APC_ROUTINE TimerApcRoutine;
		KPROCESSOR_MODE    ApcMode;
		PVOID              TimerContext;
		BOOLEAN            ResumeTimer;
		LONG               Period;
		PBOOLEAN           PreviousState;
		NTSTATUS rval;
	} args;
	args._id = 229;
	args._size = sizeof(args);
	args.TimerHandle = TimerHandle;
	args.DueTime = DueTime;
	args.TimerApcRoutine = TimerApcRoutine;
	args.ApcMode = ApcMode;
	args.TimerContext = TimerContext;
	args.ResumeTimer = ResumeTimer;
	args.Period = Period;
	args.PreviousState = PreviousState;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSignalAndWaitForSingleObjectEx
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSignalAndWaitForSingleObjectEx(
	HANDLE          SignalHandle,
	HANDLE          WaitHandle,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE          SignalHandle;
		HANDLE          WaitHandle;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Timeout;
		NTSTATUS rval;
	} args;
	args._id = 230;
	args._size = sizeof(args);
	args.SignalHandle = SignalHandle;
	args.WaitHandle = WaitHandle;
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtSuspendThread
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtSuspendThread(
	HANDLE ThreadHandle,
	PULONG PreviousSuspendCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE ThreadHandle;
		PULONG PreviousSuspendCount;
		NTSTATUS rval;
	} args;
	args._id = 231;
	args._size = sizeof(args);
	args.ThreadHandle = ThreadHandle;
	args.PreviousSuspendCount = PreviousSuspendCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtUserIoApcDispatcher
 */
XBAPI VOID NTAPI __attribute__((weak))
NtUserIoApcDispatcher(
	PVOID            ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	ULONG            Reserved
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID            ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		ULONG            Reserved;
	} args;
	args._id = 232;
	args._size = sizeof(args);
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.Reserved = Reserved;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * NtWaitForMultipleObjectsEx
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtWaitForMultipleObjectsEx(
	ULONG           Count,
	HANDLE          Handles[],
	WAIT_TYPE       WaitType,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG           Count;
		HANDLE          Handles;
		WAIT_TYPE       WaitType;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Timeout;
		NTSTATUS rval;
	} args;
	args._id = 235;
	args._size = sizeof(args);
	args.Count = Count;
	args.Handles = Handles;
	args.WaitType = WaitType;
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtWaitForSingleObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtWaitForSingleObject(
	HANDLE         Handle,
	BOOLEAN        Alertable,
	PLARGE_INTEGER Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE         Handle;
		BOOLEAN        Alertable;
		PLARGE_INTEGER Timeout;
		NTSTATUS rval;
	} args;
	args._id = 233;
	args._size = sizeof(args);
	args.Handle = Handle;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtWaitForSingleObjectEx
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtWaitForSingleObjectEx(
	HANDLE          Handle,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN         Alertable,
	PLARGE_INTEGER  Timeout
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE          Handle;
		KPROCESSOR_MODE WaitMode;
		BOOLEAN         Alertable;
		PLARGE_INTEGER  Timeout;
		NTSTATUS rval;
	} args;
	args._id = 234;
	args._size = sizeof(args);
	args.Handle = Handle;
	args.WaitMode = WaitMode;
	args.Alertable = Alertable;
	args.Timeout = Timeout;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtWriteFile
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtWriteFile(
	HANDLE           FileHandle,
	HANDLE           Event,
	PIO_APC_ROUTINE  ApcRoutine,
	PVOID            ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	PVOID            Buffer,
	ULONG            Length,
	PLARGE_INTEGER   ByteOffset
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE           FileHandle;
		HANDLE           Event;
		PIO_APC_ROUTINE  ApcRoutine;
		PVOID            ApcContext;
		PIO_STATUS_BLOCK IoStatusBlock;
		PVOID            Buffer;
		ULONG            Length;
		PLARGE_INTEGER   ByteOffset;
		NTSTATUS rval;
	} args;
	args._id = 236;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.Buffer = Buffer;
	args.Length = Length;
	args.ByteOffset = ByteOffset;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtWriteFileGather
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
NtWriteFileGather(
	HANDLE                FileHandle,
	HANDLE                Event,
	PIO_APC_ROUTINE       ApcRoutine,
	PVOID                 ApcContext,
	PIO_STATUS_BLOCK      IoStatusBlock,
	PFILE_SEGMENT_ELEMENT SegmentArray,
	ULONG                 Length,
	PLARGE_INTEGER        ByteOffset
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE                FileHandle;
		HANDLE                Event;
		PIO_APC_ROUTINE       ApcRoutine;
		PVOID                 ApcContext;
		PIO_STATUS_BLOCK      IoStatusBlock;
		PFILE_SEGMENT_ELEMENT SegmentArray;
		ULONG                 Length;
		PLARGE_INTEGER        ByteOffset;
		BOOLEAN rval;
	} args;
	args._id = 237;
	args._size = sizeof(args);
	args.FileHandle = FileHandle;
	args.Event = Event;
	args.ApcRoutine = ApcRoutine;
	args.ApcContext = ApcContext;
	args.IoStatusBlock = IoStatusBlock;
	args.SegmentArray = SegmentArray;
	args.Length = Length;
	args.ByteOffset = ByteOffset;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * NtYieldExecution
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
NtYieldExecution(
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		NTSTATUS rval;
	} args;
	args._id = 238;
	args._size = sizeof(args);
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObCreateObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObCreateObject(
	POBJECT_TYPE       ObjectType,
	POBJECT_ATTRIBUTES ObjectAttributes,
	ULONG              ObjectBodySize,
	PPVOID             Object
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_TYPE       ObjectType;
		POBJECT_ATTRIBUTES ObjectAttributes;
		ULONG              ObjectBodySize;
		PPVOID             Object;
		NTSTATUS rval;
	} args;
	args._id = 239;
	args._size = sizeof(args);
	args.ObjectType = ObjectType;
	args.ObjectAttributes = ObjectAttributes;
	args.ObjectBodySize = ObjectBodySize;
	args.Object = Object;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObInsertObject
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObInsertObject(
	PVOID              Object,
	POBJECT_ATTRIBUTES ObjectAttributes,
	ULONG              ObjectPointerBias,
	PHANDLE            Handle
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID              Object;
		POBJECT_ATTRIBUTES ObjectAttributes;
		ULONG              ObjectPointerBias;
		PHANDLE            Handle;
		NTSTATUS rval;
	} args;
	args._id = 241;
	args._size = sizeof(args);
	args.Object = Object;
	args.ObjectAttributes = ObjectAttributes;
	args.ObjectPointerBias = ObjectPointerBias;
	args.Handle = Handle;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObMakeTemporaryObject
 */
XBAPI VOID NTAPI __attribute__((weak))
ObMakeTemporaryObject(
	PVOID Object
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID Object;
	} args;
	args._id = 242;
	args._size = sizeof(args);
	args.Object = Object;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ObOpenObjectByName
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObOpenObjectByName(
	POBJECT_ATTRIBUTES ObjectAttributes,
	POBJECT_TYPE       ObjectType,
	PVOID              ParseContext,
	PHANDLE            Handle
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_ATTRIBUTES ObjectAttributes;
		POBJECT_TYPE       ObjectType;
		PVOID              ParseContext;
		PHANDLE            Handle;
		NTSTATUS rval;
	} args;
	args._id = 243;
	args._size = sizeof(args);
	args.ObjectAttributes = ObjectAttributes;
	args.ObjectType = ObjectType;
	args.ParseContext = ParseContext;
	args.Handle = Handle;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObOpenObjectByPointer
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObOpenObjectByPointer(
	PVOID        Object,
	POBJECT_TYPE ObjectType,
	PHANDLE      Handle
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID        Object;
		POBJECT_TYPE ObjectType;
		PHANDLE      Handle;
		NTSTATUS rval;
	} args;
	args._id = 244;
	args._size = sizeof(args);
	args.Object = Object;
	args.ObjectType = ObjectType;
	args.Handle = Handle;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObReferenceObjectByHandle
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
ObReferenceObjectByHandle(
	HANDLE       Handle,
	POBJECT_TYPE ObjectType,
	PPVOID       ReturnedObject
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		HANDLE       Handle;
		POBJECT_TYPE ObjectType;
		PPVOID       ReturnedObject;
		BOOLEAN rval;
	} args;
	args._id = 246;
	args._size = sizeof(args);
	args.Handle = Handle;
	args.ObjectType = ObjectType;
	args.ReturnedObject = ReturnedObject;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObReferenceObjectByName
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObReferenceObjectByName(
	POBJECT_STRING ObjectName,
	ULONG          Attributes,
	POBJECT_TYPE   ObjectType,
	PVOID          ParseContext,
	PPVOID         Object
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		POBJECT_STRING ObjectName;
		ULONG          Attributes;
		POBJECT_TYPE   ObjectType;
		PVOID          ParseContext;
		PPVOID         Object;
		NTSTATUS rval;
	} args;
	args._id = 247;
	args._size = sizeof(args);
	args.ObjectName = ObjectName;
	args.Attributes = Attributes;
	args.ObjectType = ObjectType;
	args.ParseContext = ParseContext;
	args.Object = Object;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObReferenceObjectByPointer
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
ObReferenceObjectByPointer(
	PVOID        Object,
	POBJECT_TYPE ObjectType
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID        Object;
		POBJECT_TYPE ObjectType;
		NTSTATUS rval;
	} args;
	args._id = 248;
	args._size = sizeof(args);
	args.Object = Object;
	args.ObjectType = ObjectType;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * ObfDereferenceObject
 */
XBAPI VOID FASTCALL __attribute__((weak))
ObfDereferenceObject(
	PVOID Object
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID Object;
	} args;
	args._id = 250;
	args._size = sizeof(args);
	args.Object = Object;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * ObfReferenceObject
 */
XBAPI VOID FASTCALL __attribute__((weak))
ObfReferenceObject(
	PVOID Object
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID Object;
	} args;
	args._id = 251;
	args._size = sizeof(args);
	args.Object = Object;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * PhyGetLinkState
 */
XBAPI DWORD NTAPI __attribute__((weak))
PhyGetLinkState(
	BOOLEAN update
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		BOOLEAN update;
		DWORD rval;
	} args;
	args._id = 252;
	args._size = sizeof(args);
	args.update = update;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PhyInitialize
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
PhyInitialize(
	BOOLEAN forceReset,
	PVOID   param
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		BOOLEAN forceReset;
		PVOID   param;
		NTSTATUS rval;
	} args;
	args._id = 253;
	args._size = sizeof(args);
	args.forceReset = forceReset;
	args.param = param;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PsCreateSystemThread
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
PsCreateSystemThread(
	PHANDLE         ThreadHandle,
	PHANDLE         ThreadId,
	PKSTART_ROUTINE StartRoutine,
	PVOID           StartContext,
	BOOLEAN         DebuggerThread
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE         ThreadHandle;
		PHANDLE         ThreadId;
		PKSTART_ROUTINE StartRoutine;
		PVOID           StartContext;
		BOOLEAN         DebuggerThread;
		NTSTATUS rval;
	} args;
	args._id = 254;
	args._size = sizeof(args);
	args.ThreadHandle = ThreadHandle;
	args.ThreadId = ThreadId;
	args.StartRoutine = StartRoutine;
	args.StartContext = StartContext;
	args.DebuggerThread = DebuggerThread;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PsCreateSystemThreadEx
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
PsCreateSystemThreadEx(
	PHANDLE          ThreadHandle,
	SIZE_T           ThreadExtensionSize,
	SIZE_T           KernelStackSize,
	SIZE_T           TlsDataSize,
	PHANDLE          ThreadId,
	PKSTART_ROUTINE  StartRoutine,
	PVOID            StartContext,
	BOOLEAN          CreateSuspended,
	BOOLEAN          DebuggerThread,
	PKSYSTEM_ROUTINE SystemRoutine
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PHANDLE          ThreadHandle;
		SIZE_T           ThreadExtensionSize;
		SIZE_T           KernelStackSize;
		SIZE_T           TlsDataSize;
		PHANDLE          ThreadId;
		PKSTART_ROUTINE  StartRoutine;
		PVOID            StartContext;
		BOOLEAN          CreateSuspended;
		BOOLEAN          DebuggerThread;
		PKSYSTEM_ROUTINE SystemRoutine;
		NTSTATUS rval;
	} args;
	args._id = 255;
	args._size = sizeof(args);
	args.ThreadHandle = ThreadHandle;
	args.ThreadExtensionSize = ThreadExtensionSize;
	args.KernelStackSize = KernelStackSize;
	args.TlsDataSize = TlsDataSize;
	args.ThreadId = ThreadId;
	args.StartRoutine = StartRoutine;
	args.StartContext = StartContext;
	args.CreateSuspended = CreateSuspended;
	args.DebuggerThread = DebuggerThread;
	args.SystemRoutine = SystemRoutine;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PsQueryStatistics
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
PsQueryStatistics(
	PPS_STATISTICS ProcessStatistics
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPS_STATISTICS ProcessStatistics;
		NTSTATUS rval;
	} args;
	args._id = 256;
	args._size = sizeof(args);
	args.ProcessStatistics = ProcessStatistics;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PsSetCreateThreadNotifyRoutine
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
PsSetCreateThreadNotifyRoutine(
	PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine;
		NTSTATUS rval;
	} args;
	args._id = 257;
	args._size = sizeof(args);
	args.NotifyRoutine = NotifyRoutine;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * PsTerminateSystemThread
 */
XBAPI VOID NTAPI __attribute__((weak))
PsTerminateSystemThread(
	NTSTATUS ExitStatus
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		NTSTATUS ExitStatus;
	} args;
	args._id = 258;
	args._size = sizeof(args);
	args.ExitStatus = ExitStatus;
	K_VMEXIT(args);
	K_EXIT();
	while (1);
}


/**
 * READ_PORT_BUFFER_UCHAR
 */
XBAPI VOID NTAPI __attribute__((weak))
READ_PORT_BUFFER_UCHAR(
	PUCHAR Port,
	PUCHAR Buffer,
	ULONG  Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR Port;
		PUCHAR Buffer;
		ULONG  Count;
	} args;
	args._id = 329;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * READ_PORT_BUFFER_ULONG
 */
XBAPI VOID NTAPI __attribute__((weak))
READ_PORT_BUFFER_ULONG(
	PULONG Port,
	PULONG Buffer,
	PULONG Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG Port;
		PULONG Buffer;
		PULONG Count;
	} args;
	args._id = 331;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * READ_PORT_BUFFER_USHORT
 */
XBAPI VOID NTAPI __attribute__((weak))
READ_PORT_BUFFER_USHORT(
	PUSHORT Port,
	PUSHORT Buffer,
	ULONG   Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUSHORT Port;
		PUSHORT Buffer;
		ULONG   Count;
	} args;
	args._id = 330;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlAnsiStringToUnicodeString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlAnsiStringToUnicodeString(
	PUNICODE_STRING DestinationString,
	PSTRING         SourceString,
	BOOLEAN         AllocateDestinationString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING DestinationString;
		PSTRING         SourceString;
		BOOLEAN         AllocateDestinationString;
		NTSTATUS rval;
	} args;
	args._id = 260;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	args.AllocateDestinationString = AllocateDestinationString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlAppendStringToString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlAppendStringToString(
	PSTRING Destination,
	PSTRING Source
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING Destination;
		PSTRING Source;
		NTSTATUS rval;
	} args;
	args._id = 261;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Source = Source;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlAppendUnicodeStringToString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlAppendUnicodeStringToString(
	PUNICODE_STRING Destination,
	PUNICODE_STRING Source
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING Destination;
		PUNICODE_STRING Source;
		NTSTATUS rval;
	} args;
	args._id = 262;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Source = Source;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlAppendUnicodeToString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlAppendUnicodeToString(
	PUNICODE_STRING Destination,
	PCWSTR          Source
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING Destination;
		PCWSTR          Source;
		NTSTATUS rval;
	} args;
	args._id = 263;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Source = Source;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlAssert
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlAssert(
	PVOID FailedAssertion,
	PVOID FileName,
	ULONG LineNumber,
	PCHAR Message
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID FailedAssertion;
		PVOID FileName;
		ULONG LineNumber;
		PCHAR Message;
	} args;
	args._id = 264;
	args._size = sizeof(args);
	args.FailedAssertion = FailedAssertion;
	args.FileName = FileName;
	args.LineNumber = LineNumber;
	args.Message = Message;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlCaptureContext
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlCaptureContext(
	PCONTEXT ContextRecord
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCONTEXT ContextRecord;
	} args;
	args._id = 265;
	args._size = sizeof(args);
	args.ContextRecord = ContextRecord;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlCaptureStackBackTrace
 */
XBAPI USHORT NTAPI __attribute__((weak))
RtlCaptureStackBackTrace(
	ULONG  FramesToSkip,
	ULONG  FramesToCapture,
	PPVOID BackTrace,
	PULONG BackTraceHash
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  FramesToSkip;
		ULONG  FramesToCapture;
		PPVOID BackTrace;
		PULONG BackTraceHash;
		USHORT rval;
	} args;
	args._id = 266;
	args._size = sizeof(args);
	args.FramesToSkip = FramesToSkip;
	args.FramesToCapture = FramesToCapture;
	args.BackTrace = BackTrace;
	args.BackTraceHash = BackTraceHash;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCharToInteger
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlCharToInteger(
	PCSZ   String,
	ULONG  Base,
	PULONG Value
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCSZ   String;
		ULONG  Base;
		PULONG Value;
		NTSTATUS rval;
	} args;
	args._id = 267;
	args._size = sizeof(args);
	args.String = String;
	args.Base = Base;
	args.Value = Value;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCompareMemory
 */
XBAPI SIZE_T NTAPI __attribute__((weak))
RtlCompareMemory(
	PVOID  Source1,
	PVOID  Source2,
	SIZE_T Length
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  Source1;
		PVOID  Source2;
		SIZE_T Length;
		SIZE_T rval;
	} args;
	args._id = 268;
	args._size = sizeof(args);
	args.Source1 = Source1;
	args.Source2 = Source2;
	args.Length = Length;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCompareMemoryUlong
 */
XBAPI SIZE_T NTAPI __attribute__((weak))
RtlCompareMemoryUlong(
	PVOID  Source,
	SIZE_T Length,
	ULONG  Pattern
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  Source;
		SIZE_T Length;
		ULONG  Pattern;
		SIZE_T rval;
	} args;
	args._id = 269;
	args._size = sizeof(args);
	args.Source = Source;
	args.Length = Length;
	args.Pattern = Pattern;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCompareString
 */
XBAPI LONG NTAPI __attribute__((weak))
RtlCompareString(
	PSTRING String1,
	PSTRING String2,
	BOOLEAN CaseInSensitive
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING String1;
		PSTRING String2;
		BOOLEAN CaseInSensitive;
		LONG rval;
	} args;
	args._id = 270;
	args._size = sizeof(args);
	args.String1 = String1;
	args.String2 = String2;
	args.CaseInSensitive = CaseInSensitive;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCompareUnicodeString
 */
XBAPI LONG NTAPI __attribute__((weak))
RtlCompareUnicodeString(
	PUNICODE_STRING String1,
	PUNICODE_STRING String2,
	BOOLEAN         CaseInSensitive
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING String1;
		PUNICODE_STRING String2;
		BOOLEAN         CaseInSensitive;
		LONG rval;
	} args;
	args._id = 271;
	args._size = sizeof(args);
	args.String1 = String1;
	args.String2 = String2;
	args.CaseInSensitive = CaseInSensitive;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlCopyString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlCopyString(
	PSTRING DestinationString,
	PSTRING SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING DestinationString;
		PSTRING SourceString;
	} args;
	args._id = 272;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlCopyUnicodeString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlCopyUnicodeString(
	PUNICODE_STRING DestinationString,
	PUNICODE_STRING SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING DestinationString;
		PUNICODE_STRING SourceString;
	} args;
	args._id = 273;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlCreateUnicodeString
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
RtlCreateUnicodeString(
	PUNICODE_STRING DestinationString,
	PCWSTR          SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING DestinationString;
		PCWSTR          SourceString;
		BOOLEAN rval;
	} args;
	args._id = 274;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlDowncaseUnicodeChar
 */
XBAPI WCHAR NTAPI __attribute__((weak))
RtlDowncaseUnicodeChar(
	WCHAR SourceCharacter
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		WCHAR SourceCharacter;
		WCHAR rval;
	} args;
	args._id = 275;
	args._size = sizeof(args);
	args.SourceCharacter = SourceCharacter;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlDowncaseUnicodeString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlDowncaseUnicodeString(
	PUNICODE_STRING DestinationString,
	PUNICODE_STRING SourceString,
	BOOLEAN         AllocateDestinationString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING DestinationString;
		PUNICODE_STRING SourceString;
		BOOLEAN         AllocateDestinationString;
		NTSTATUS rval;
	} args;
	args._id = 276;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	args.AllocateDestinationString = AllocateDestinationString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlEnterCriticalSection
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlEnterCriticalSection(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
	} args;
	args._id = 277;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlEnterCriticalSectionAndRegion
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlEnterCriticalSectionAndRegion(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
	} args;
	args._id = 278;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlEqualString
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
RtlEqualString(
	PSTRING String1,
	PSTRING String2,
	BOOLEAN CaseInSensitive
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING String1;
		PSTRING String2;
		BOOLEAN CaseInSensitive;
		BOOLEAN rval;
	} args;
	args._id = 279;
	args._size = sizeof(args);
	args.String1 = String1;
	args.String2 = String2;
	args.CaseInSensitive = CaseInSensitive;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlEqualUnicodeString
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
RtlEqualUnicodeString(
	PUNICODE_STRING String1,
	PUNICODE_STRING String2,
	BOOLEAN         CaseInSensitive
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING String1;
		PUNICODE_STRING String2;
		BOOLEAN         CaseInSensitive;
		BOOLEAN rval;
	} args;
	args._id = 280;
	args._size = sizeof(args);
	args.String1 = String1;
	args.String2 = String2;
	args.CaseInSensitive = CaseInSensitive;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlExtendedIntegerMultiply
 */
XBAPI LARGE_INTEGER NTAPI __attribute__((weak))
RtlExtendedIntegerMultiply(
	LARGE_INTEGER Multiplicand,
	LONG          Multiplier
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		LARGE_INTEGER Multiplicand;
		LONG          Multiplier;
		LARGE_INTEGER rval;
	} args;
	args._id = 281;
	args._size = sizeof(args);
	args.Multiplicand = Multiplicand;
	args.Multiplier = Multiplier;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlExtendedLargeIntegerDivide
 */
XBAPI LARGE_INTEGER NTAPI __attribute__((weak))
RtlExtendedLargeIntegerDivide(
	LARGE_INTEGER Dividend,
	ULONG         Divisor,
	PULONG        Remainder
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		LARGE_INTEGER Dividend;
		ULONG         Divisor;
		PULONG        Remainder;
		LARGE_INTEGER rval;
	} args;
	args._id = 282;
	args._size = sizeof(args);
	args.Dividend = Dividend;
	args.Divisor = Divisor;
	args.Remainder = Remainder;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlExtendedMagicDivide
 */
XBAPI LARGE_INTEGER NTAPI __attribute__((weak))
RtlExtendedMagicDivide(
	LARGE_INTEGER Dividend,
	LARGE_INTEGER MagicDivisor,
	CCHAR         ShiftCount
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		LARGE_INTEGER Dividend;
		LARGE_INTEGER MagicDivisor;
		CCHAR         ShiftCount;
		LARGE_INTEGER rval;
	} args;
	args._id = 283;
	args._size = sizeof(args);
	args.Dividend = Dividend;
	args.MagicDivisor = MagicDivisor;
	args.ShiftCount = ShiftCount;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlFillMemory
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlFillMemory(
	PVOID Destination,
	ULONG Length,
	UCHAR Fill
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID Destination;
		ULONG Length;
		UCHAR Fill;
	} args;
	args._id = 284;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Length = Length;
	args.Fill = Fill;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlFillMemoryUlong
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlFillMemoryUlong(
	PVOID  Destination,
	SIZE_T Length,
	ULONG  Pattern
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  Destination;
		SIZE_T Length;
		ULONG  Pattern;
	} args;
	args._id = 285;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Length = Length;
	args.Pattern = Pattern;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlFreeAnsiString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlFreeAnsiString(
	PANSI_STRING AnsiString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PANSI_STRING AnsiString;
	} args;
	args._id = 286;
	args._size = sizeof(args);
	args.AnsiString = AnsiString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlFreeUnicodeString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlFreeUnicodeString(
	PUNICODE_STRING UnicodeString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING UnicodeString;
	} args;
	args._id = 287;
	args._size = sizeof(args);
	args.UnicodeString = UnicodeString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlGetCallersAddress
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlGetCallersAddress(
	PPVOID CallersAddress,
	PPVOID CallersCaller
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPVOID CallersAddress;
		PPVOID CallersCaller;
	} args;
	args._id = 288;
	args._size = sizeof(args);
	args.CallersAddress = CallersAddress;
	args.CallersCaller = CallersCaller;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlInitAnsiString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlInitAnsiString(
	PANSI_STRING DestinationString,
	PCSZ         SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PANSI_STRING DestinationString;
		PCSZ         SourceString;
	} args;
	args._id = 289;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlInitUnicodeString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlInitUnicodeString(
	PUNICODE_STRING DestinationString,
	PCWSTR          SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING DestinationString;
		PCWSTR          SourceString;
	} args;
	args._id = 290;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlInitializeCriticalSection
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlInitializeCriticalSection(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
	} args;
	args._id = 291;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlIntegerToChar
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlIntegerToChar(
	ULONG Value,
	ULONG Base,
	LONG  OutputLength,
	PSZ   String
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG Value;
		ULONG Base;
		LONG  OutputLength;
		PSZ   String;
		NTSTATUS rval;
	} args;
	args._id = 292;
	args._size = sizeof(args);
	args.Value = Value;
	args.Base = Base;
	args.OutputLength = OutputLength;
	args.String = String;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlIntegerToUnicodeString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlIntegerToUnicodeString(
	ULONG           Value,
	ULONG           Base,
	PUNICODE_STRING String
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG           Value;
		ULONG           Base;
		PUNICODE_STRING String;
		NTSTATUS rval;
	} args;
	args._id = 293;
	args._size = sizeof(args);
	args.Value = Value;
	args.Base = Base;
	args.String = String;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlLeaveCriticalSection
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlLeaveCriticalSection(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
	} args;
	args._id = 294;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlLeaveCriticalSectionAndRegion
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlLeaveCriticalSectionAndRegion(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
	} args;
	args._id = 295;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlLowerChar
 */
XBAPI CHAR NTAPI __attribute__((weak))
RtlLowerChar(
	CHAR Character
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		CHAR Character;
		CHAR rval;
	} args;
	args._id = 296;
	args._size = sizeof(args);
	args.Character = Character;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlMapGenericMask
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlMapGenericMask(
	PACCESS_MASK     AccessMask,
	PGENERIC_MAPPING GenericMapping
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PACCESS_MASK     AccessMask;
		PGENERIC_MAPPING GenericMapping;
	} args;
	args._id = 297;
	args._size = sizeof(args);
	args.AccessMask = AccessMask;
	args.GenericMapping = GenericMapping;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlMoveMemory
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlMoveMemory(
	PVOID       Destination,
	CONST PVOID Source,
	ULONG       Length
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  Destination;
		PPVOID Source;
		ULONG  Length;
	} args;
	args._id = 298;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Source = Source;
	args.Length = Length;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlMultiByteToUnicodeN
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlMultiByteToUnicodeN(
	PWSTR  UnicodeString,
	ULONG  MaxBytesInUnicodeString,
	PULONG BytesInUnicodeString,
	PCHAR  MultiByteString,
	ULONG  BytesInMultiByteString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PWSTR  UnicodeString;
		ULONG  MaxBytesInUnicodeString;
		PULONG BytesInUnicodeString;
		PCHAR  MultiByteString;
		ULONG  BytesInMultiByteString;
		NTSTATUS rval;
	} args;
	args._id = 299;
	args._size = sizeof(args);
	args.UnicodeString = UnicodeString;
	args.MaxBytesInUnicodeString = MaxBytesInUnicodeString;
	args.BytesInUnicodeString = BytesInUnicodeString;
	args.MultiByteString = MultiByteString;
	args.BytesInMultiByteString = BytesInMultiByteString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlMultiByteToUnicodeSize
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlMultiByteToUnicodeSize(
	PULONG BytesInUnicodeString,
	PCHAR  MultiByteString,
	ULONG  BytesInMultiByteString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG BytesInUnicodeString;
		PCHAR  MultiByteString;
		ULONG  BytesInMultiByteString;
		NTSTATUS rval;
	} args;
	args._id = 300;
	args._size = sizeof(args);
	args.BytesInUnicodeString = BytesInUnicodeString;
	args.MultiByteString = MultiByteString;
	args.BytesInMultiByteString = BytesInMultiByteString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlNtStatusToDosError
 */
XBAPI ULONG NTAPI __attribute__((weak))
RtlNtStatusToDosError(
	NTSTATUS Status
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		NTSTATUS Status;
		ULONG rval;
	} args;
	args._id = 301;
	args._size = sizeof(args);
	args.Status = Status;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlRaiseException
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlRaiseException(
	PEXCEPTION_RECORD ExceptionRecord
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PEXCEPTION_RECORD ExceptionRecord;
	} args;
	args._id = 302;
	args._size = sizeof(args);
	args.ExceptionRecord = ExceptionRecord;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlRaiseStatus
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlRaiseStatus(
	NTSTATUS Status
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		NTSTATUS Status;
	} args;
	args._id = 303;
	args._size = sizeof(args);
	args.Status = Status;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlRip
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlRip(
	PVOID ApiName,
	PVOID Expression,
	PVOID Message
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID ApiName;
		PVOID Expression;
		PVOID Message;
	} args;
	args._id = 352;
	args._size = sizeof(args);
	args.ApiName = ApiName;
	args.Expression = Expression;
	args.Message = Message;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlSnprintf
 */
XBAPI VOID CDECL __attribute__((weak))
RtlSnprintf(
	PCHAR  pszDest,
	SIZE_T cbDest,
	LPCSTR pszFormat,
	...
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  pszDest;
		SIZE_T cbDest;
		LPCSTR pszFormat;
	} args;
	args._id = 361;
	args._size = sizeof(args);
	args.pszDest = pszDest;
	args.cbDest = cbDest;
	args.pszFormat = pszFormat;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlSprintf
 */
XBAPI VOID CDECL __attribute__((weak))
RtlSprintf(
	PCHAR  pszDest,
	LPCSTR pszFormat,
	...
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  pszDest;
		LPCSTR pszFormat;
	} args;
	args._id = 362;
	args._size = sizeof(args);
	args.pszDest = pszDest;
	args.pszFormat = pszFormat;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlTimeFieldsToTime
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
RtlTimeFieldsToTime(
	PTIME_FIELDS   TimeFields,
	PLARGE_INTEGER Time
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PTIME_FIELDS   TimeFields;
		PLARGE_INTEGER Time;
		BOOLEAN rval;
	} args;
	args._id = 304;
	args._size = sizeof(args);
	args.TimeFields = TimeFields;
	args.Time = Time;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlTimeToTimeFields
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlTimeToTimeFields(
	PLARGE_INTEGER Time,
	PTIME_FIELDS   TimeFields
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PLARGE_INTEGER Time;
		PTIME_FIELDS   TimeFields;
	} args;
	args._id = 305;
	args._size = sizeof(args);
	args.Time = Time;
	args.TimeFields = TimeFields;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlTryEnterCriticalSection
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
RtlTryEnterCriticalSection(
	PRTL_CRITICAL_SECTION CriticalSection
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PRTL_CRITICAL_SECTION CriticalSection;
		BOOLEAN rval;
	} args;
	args._id = 306;
	args._size = sizeof(args);
	args.CriticalSection = CriticalSection;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUlongByteSwap
 */
XBAPI ULONG FASTCALL __attribute__((weak))
RtlUlongByteSwap(
	ULONG Source
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG Source;
		ULONG rval;
	} args;
	args._id = 307;
	args._size = sizeof(args);
	args.Source = Source;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUnicodeStringToAnsiString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUnicodeStringToAnsiString(
	PSTRING         DestinationString,
	PUNICODE_STRING SourceString,
	BOOLEAN         AllocateDestinationString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING         DestinationString;
		PUNICODE_STRING SourceString;
		BOOLEAN         AllocateDestinationString;
		NTSTATUS rval;
	} args;
	args._id = 308;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	args.AllocateDestinationString = AllocateDestinationString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUnicodeStringToInteger
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUnicodeStringToInteger(
	PUNICODE_STRING String,
	ULONG           Base,
	PULONG          Value
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING String;
		ULONG           Base;
		PULONG          Value;
		NTSTATUS rval;
	} args;
	args._id = 309;
	args._size = sizeof(args);
	args.String = String;
	args.Base = Base;
	args.Value = Value;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUnicodeToMultiByteN
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUnicodeToMultiByteN(
	PCHAR  MultiByteString,
	ULONG  MaxBytesInMultiByteString,
	PULONG BytesInMultiByteString,
	PWSTR  UnicodeString,
	ULONG  BytesInUnicodeString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  MultiByteString;
		ULONG  MaxBytesInMultiByteString;
		PULONG BytesInMultiByteString;
		PWSTR  UnicodeString;
		ULONG  BytesInUnicodeString;
		NTSTATUS rval;
	} args;
	args._id = 310;
	args._size = sizeof(args);
	args.MultiByteString = MultiByteString;
	args.MaxBytesInMultiByteString = MaxBytesInMultiByteString;
	args.BytesInMultiByteString = BytesInMultiByteString;
	args.UnicodeString = UnicodeString;
	args.BytesInUnicodeString = BytesInUnicodeString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUnicodeToMultiByteSize
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUnicodeToMultiByteSize(
	PULONG BytesInMultiByteString,
	PWSTR  UnicodeString,
	ULONG  BytesInUnicodeString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG BytesInMultiByteString;
		PWSTR  UnicodeString;
		ULONG  BytesInUnicodeString;
		NTSTATUS rval;
	} args;
	args._id = 311;
	args._size = sizeof(args);
	args.BytesInMultiByteString = BytesInMultiByteString;
	args.UnicodeString = UnicodeString;
	args.BytesInUnicodeString = BytesInUnicodeString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUnwind
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlUnwind(
	PVOID             TargetFrame,
	PVOID             TargetIp,
	PEXCEPTION_RECORD ExceptionRecord,
	PVOID             ReturnValue
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID             TargetFrame;
		PVOID             TargetIp;
		PEXCEPTION_RECORD ExceptionRecord;
		PVOID             ReturnValue;
	} args;
	args._id = 312;
	args._size = sizeof(args);
	args.TargetFrame = TargetFrame;
	args.TargetIp = TargetIp;
	args.ExceptionRecord = ExceptionRecord;
	args.ReturnValue = ReturnValue;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlUpcaseUnicodeChar
 */
XBAPI WCHAR NTAPI __attribute__((weak))
RtlUpcaseUnicodeChar(
	WCHAR SourceCharacter
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		WCHAR SourceCharacter;
		WCHAR rval;
	} args;
	args._id = 313;
	args._size = sizeof(args);
	args.SourceCharacter = SourceCharacter;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUpcaseUnicodeString
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUpcaseUnicodeString(
	PUNICODE_STRING  DestinationString,
	PCUNICODE_STRING SourceString,
	BOOLEAN          AllocateDestinationString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUNICODE_STRING  DestinationString;
		PCUNICODE_STRING SourceString;
		BOOLEAN          AllocateDestinationString;
		NTSTATUS rval;
	} args;
	args._id = 314;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	args.AllocateDestinationString = AllocateDestinationString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUpcaseUnicodeToMultiByteN
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
RtlUpcaseUnicodeToMultiByteN(
	PCHAR  MultiByteString,
	ULONG  MaxBytesInMultiByteString,
	PULONG BytesInMultiByteString,
	PWSTR  UnicodeString,
	ULONG  BytesInUnicodeString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  MultiByteString;
		ULONG  MaxBytesInMultiByteString;
		PULONG BytesInMultiByteString;
		PWSTR  UnicodeString;
		ULONG  BytesInUnicodeString;
		NTSTATUS rval;
	} args;
	args._id = 315;
	args._size = sizeof(args);
	args.MultiByteString = MultiByteString;
	args.MaxBytesInMultiByteString = MaxBytesInMultiByteString;
	args.BytesInMultiByteString = BytesInMultiByteString;
	args.UnicodeString = UnicodeString;
	args.BytesInUnicodeString = BytesInUnicodeString;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUpperChar
 */
XBAPI CHAR NTAPI __attribute__((weak))
RtlUpperChar(
	CHAR Character
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		CHAR Character;
		CHAR rval;
	} args;
	args._id = 316;
	args._size = sizeof(args);
	args.Character = Character;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlUpperString
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlUpperString(
	PSTRING DestinationString,
	PSTRING SourceString
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PSTRING DestinationString;
		PSTRING SourceString;
	} args;
	args._id = 317;
	args._size = sizeof(args);
	args.DestinationString = DestinationString;
	args.SourceString = SourceString;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlUshortByteSwap
 */
XBAPI USHORT FASTCALL __attribute__((weak))
RtlUshortByteSwap(
	USHORT Source
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		USHORT Source;
		USHORT rval;
	} args;
	args._id = 318;
	args._size = sizeof(args);
	args.Source = Source;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlVsnprintf
 */
XBAPI VOID CDECL __attribute__((weak))
RtlVsnprintf(
	PCHAR  pszDest,
	SIZE_T cbDest,
	LPCSTR pszFormat,
	...
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  pszDest;
		SIZE_T cbDest;
		LPCSTR pszFormat;
	} args;
	args._id = 363;
	args._size = sizeof(args);
	args.pszDest = pszDest;
	args.cbDest = cbDest;
	args.pszFormat = pszFormat;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlVsprintf
 */
XBAPI VOID CDECL __attribute__((weak))
RtlVsprintf(
	PCHAR  pszDest,
	LPCSTR pszFormat,
	...
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCHAR  pszDest;
		LPCSTR pszFormat;
	} args;
	args._id = 364;
	args._size = sizeof(args);
	args.pszDest = pszDest;
	args.pszFormat = pszFormat;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * RtlWalkFrameChain
 */
XBAPI ULONG NTAPI __attribute__((weak))
RtlWalkFrameChain(
	PPVOID Callers,
	ULONG  Count,
	ULONG  Flags
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PPVOID Callers;
		ULONG  Count;
		ULONG  Flags;
		ULONG rval;
	} args;
	args._id = 319;
	args._size = sizeof(args);
	args.Callers = Callers;
	args.Count = Count;
	args.Flags = Flags;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * RtlZeroMemory
 */
XBAPI VOID NTAPI __attribute__((weak))
RtlZeroMemory(
	PVOID  Destination,
	SIZE_T Length
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PVOID  Destination;
		SIZE_T Length;
	} args;
	args._id = 320;
	args._size = sizeof(args);
	args.Destination = Destination;
	args.Length = Length;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * WRITE_PORT_BUFFER_UCHAR
 */
XBAPI VOID NTAPI __attribute__((weak))
WRITE_PORT_BUFFER_UCHAR(
	PUCHAR Port,
	PUCHAR Buffer,
	ULONG  Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR Port;
		PUCHAR Buffer;
		ULONG  Count;
	} args;
	args._id = 332;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * WRITE_PORT_BUFFER_ULONG
 */
XBAPI VOID NTAPI __attribute__((weak))
WRITE_PORT_BUFFER_ULONG(
	PULONG Port,
	PULONG Buffer,
	ULONG  Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG Port;
		PULONG Buffer;
		ULONG  Count;
	} args;
	args._id = 334;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * WRITE_PORT_BUFFER_USHORT
 */
XBAPI VOID NTAPI __attribute__((weak))
WRITE_PORT_BUFFER_USHORT(
	PUSHORT Port,
	PUSHORT Buffer,
	ULONG   Count
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUSHORT Port;
		PUSHORT Buffer;
		ULONG   Count;
	} args;
	args._id = 333;
	args._size = sizeof(args);
	args.Port = Port;
	args.Buffer = Buffer;
	args.Count = Count;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcBlockCrypt
 */
XBAPI VOID NTAPI __attribute__((weak))
XcBlockCrypt(
	ULONG  dwCipher,
	PUCHAR pbOutput,
	PUCHAR pbInput,
	PUCHAR pbKeyTable,
	ULONG  dwOp
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  dwCipher;
		PUCHAR pbOutput;
		PUCHAR pbInput;
		PUCHAR pbKeyTable;
		ULONG  dwOp;
	} args;
	args._id = 348;
	args._size = sizeof(args);
	args.dwCipher = dwCipher;
	args.pbOutput = pbOutput;
	args.pbInput = pbInput;
	args.pbKeyTable = pbKeyTable;
	args.dwOp = dwOp;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcBlockCryptCBC
 */
XBAPI VOID NTAPI __attribute__((weak))
XcBlockCryptCBC(
	ULONG  dwCipher,
	ULONG  dwInputLength,
	PUCHAR pbOutput,
	PUCHAR pbInput,
	PUCHAR pbKeyTable,
	ULONG  dwOp,
	PUCHAR pbFeedback
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  dwCipher;
		ULONG  dwInputLength;
		PUCHAR pbOutput;
		PUCHAR pbInput;
		PUCHAR pbKeyTable;
		ULONG  dwOp;
		PUCHAR pbFeedback;
	} args;
	args._id = 349;
	args._size = sizeof(args);
	args.dwCipher = dwCipher;
	args.dwInputLength = dwInputLength;
	args.pbOutput = pbOutput;
	args.pbInput = pbInput;
	args.pbKeyTable = pbKeyTable;
	args.dwOp = dwOp;
	args.pbFeedback = pbFeedback;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcCryptService
 */
XBAPI ULONG NTAPI __attribute__((weak))
XcCryptService(
	ULONG dwOp,
	PVOID pArgs
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG dwOp;
		PVOID pArgs;
		ULONG rval;
	} args;
	args._id = 350;
	args._size = sizeof(args);
	args.dwOp = dwOp;
	args.pArgs = pArgs;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XcDESKeyParity
 */
XBAPI VOID NTAPI __attribute__((weak))
XcDESKeyParity(
	PUCHAR pbKey,
	ULONG  dwKeyLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbKey;
		ULONG  dwKeyLength;
	} args;
	args._id = 346;
	args._size = sizeof(args);
	args.pbKey = pbKey;
	args.dwKeyLength = dwKeyLength;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcHMAC
 */
XBAPI VOID NTAPI __attribute__((weak))
XcHMAC(
	PUCHAR pbKey,
	ULONG  dwKeyLength,
	PUCHAR pbInput,
	ULONG  dwInputLength,
	PUCHAR pbInput2,
	ULONG  dwInputLength2,
	PUCHAR pbDigest
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbKey;
		ULONG  dwKeyLength;
		PUCHAR pbInput;
		ULONG  dwInputLength;
		PUCHAR pbInput2;
		ULONG  dwInputLength2;
		PUCHAR pbDigest;
	} args;
	args._id = 340;
	args._size = sizeof(args);
	args.pbKey = pbKey;
	args.dwKeyLength = dwKeyLength;
	args.pbInput = pbInput;
	args.dwInputLength = dwInputLength;
	args.pbInput2 = pbInput2;
	args.dwInputLength2 = dwInputLength2;
	args.pbDigest = pbDigest;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcKeyTable
 */
XBAPI VOID NTAPI __attribute__((weak))
XcKeyTable(
	ULONG  dwCipher,
	PUCHAR pbKeyTable,
	PUCHAR pbKey
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		ULONG  dwCipher;
		PUCHAR pbKeyTable;
		PUCHAR pbKey;
	} args;
	args._id = 347;
	args._size = sizeof(args);
	args.dwCipher = dwCipher;
	args.pbKeyTable = pbKeyTable;
	args.pbKey = pbKey;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcModExp
 */
XBAPI ULONG NTAPI __attribute__((weak))
XcModExp(
	PULONG pA,
	PULONG pB,
	PULONG pC,
	PULONG pD,
	ULONG  dwN
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PULONG pA;
		PULONG pB;
		PULONG pC;
		PULONG pD;
		ULONG  dwN;
		ULONG rval;
	} args;
	args._id = 345;
	args._size = sizeof(args);
	args.pA = pA;
	args.pB = pB;
	args.pC = pC;
	args.pD = pD;
	args.dwN = dwN;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XcPKDecPrivate
 */
XBAPI ULONG NTAPI __attribute__((weak))
XcPKDecPrivate(
	PUCHAR pbPrvKey,
	PUCHAR pbInput,
	PUCHAR pbOutput
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbPrvKey;
		PUCHAR pbInput;
		PUCHAR pbOutput;
		ULONG rval;
	} args;
	args._id = 342;
	args._size = sizeof(args);
	args.pbPrvKey = pbPrvKey;
	args.pbInput = pbInput;
	args.pbOutput = pbOutput;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XcPKEncPublic
 */
XBAPI ULONG NTAPI __attribute__((weak))
XcPKEncPublic(
	PUCHAR pbPubKey,
	PUCHAR pbInput,
	PUCHAR pbOutput
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbPubKey;
		PUCHAR pbInput;
		PUCHAR pbOutput;
		ULONG rval;
	} args;
	args._id = 341;
	args._size = sizeof(args);
	args.pbPubKey = pbPubKey;
	args.pbInput = pbInput;
	args.pbOutput = pbOutput;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XcPKGetKeyLen
 */
XBAPI ULONG NTAPI __attribute__((weak))
XcPKGetKeyLen(
	PUCHAR pbPubKey
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbPubKey;
		ULONG rval;
	} args;
	args._id = 343;
	args._size = sizeof(args);
	args.pbPubKey = pbPubKey;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XcRC4Crypt
 */
XBAPI VOID NTAPI __attribute__((weak))
XcRC4Crypt(
	PUCHAR pbKeyStruct,
	ULONG  dwInputLength,
	PUCHAR pbInput
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbKeyStruct;
		ULONG  dwInputLength;
		PUCHAR pbInput;
	} args;
	args._id = 339;
	args._size = sizeof(args);
	args.pbKeyStruct = pbKeyStruct;
	args.dwInputLength = dwInputLength;
	args.pbInput = pbInput;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcRC4Key
 */
XBAPI VOID NTAPI __attribute__((weak))
XcRC4Key(
	PUCHAR pbKeyStruct,
	ULONG  dwKeyLength,
	PUCHAR pbKey
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbKeyStruct;
		ULONG  dwKeyLength;
		PUCHAR pbKey;
	} args;
	args._id = 338;
	args._size = sizeof(args);
	args.pbKeyStruct = pbKeyStruct;
	args.dwKeyLength = dwKeyLength;
	args.pbKey = pbKey;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcSHAFinal
 */
XBAPI VOID NTAPI __attribute__((weak))
XcSHAFinal(
	PUCHAR pbSHAContext,
	PUCHAR pbDigest
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbSHAContext;
		PUCHAR pbDigest;
	} args;
	args._id = 337;
	args._size = sizeof(args);
	args.pbSHAContext = pbSHAContext;
	args.pbDigest = pbDigest;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcSHAInit
 */
XBAPI VOID NTAPI __attribute__((weak))
XcSHAInit(
	PUCHAR pbSHAContext
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbSHAContext;
	} args;
	args._id = 335;
	args._size = sizeof(args);
	args.pbSHAContext = pbSHAContext;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcSHAUpdate
 */
XBAPI VOID NTAPI __attribute__((weak))
XcSHAUpdate(
	PUCHAR pbSHAContext,
	PUCHAR pbInput,
	ULONG  dwInputLength
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbSHAContext;
		PUCHAR pbInput;
		ULONG  dwInputLength;
	} args;
	args._id = 336;
	args._size = sizeof(args);
	args.pbSHAContext = pbSHAContext;
	args.pbInput = pbInput;
	args.dwInputLength = dwInputLength;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcUpdateCrypto
 */
XBAPI VOID NTAPI __attribute__((weak))
XcUpdateCrypto(
	PCRYPTO_VECTOR pNewVector,
	PCRYPTO_VECTOR pROMVector
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PCRYPTO_VECTOR pNewVector;
		PCRYPTO_VECTOR pROMVector;
	} args;
	args._id = 351;
	args._size = sizeof(args);
	args.pNewVector = pNewVector;
	args.pROMVector = pROMVector;
	K_VMEXIT(args);
	K_EXIT();
}


/**
 * XcVerifyPKCS1Signature
 */
XBAPI BOOLEAN NTAPI __attribute__((weak))
XcVerifyPKCS1Signature(
	PUCHAR pbSig,
	PUCHAR pbPubKey,
	PUCHAR pbDigest
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PUCHAR pbSig;
		PUCHAR pbPubKey;
		PUCHAR pbDigest;
		BOOLEAN rval;
	} args;
	args._id = 344;
	args._size = sizeof(args);
	args.pbSig = pbSig;
	args.pbPubKey = pbPubKey;
	args.pbDigest = pbDigest;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XeLoadSection
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
XeLoadSection(
	PXBEIMAGE_SECTION Section
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PXBEIMAGE_SECTION Section;
		NTSTATUS rval;
	} args;
	args._id = 327;
	args._size = sizeof(args);
	args.Section = Section;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}


/**
 * XeUnloadSection
 */
XBAPI NTSTATUS NTAPI __attribute__((weak))
XeUnloadSection(
	PXBEIMAGE_SECTION Section
	)
{
	K_ENTER();
	volatile struct {
		DWORD _id;
		DWORD _size;
		PXBEIMAGE_SECTION Section;
		NTSTATUS rval;
	} args;
	args._id = 328;
	args._size = sizeof(args);
	args.Section = Section;
	K_VMEXIT(args);
	K_EXIT_WITH_VALUE(args.rval);
}
