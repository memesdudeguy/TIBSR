usbPipe0      = 0000h
usbPipe1      = 0100h
usbPipe2      = 0200h
usbPipe3      = 0300h

usbBulk       = 20h
usbInt        = 30h

usbPacket8    = 0100h
usbPacket16   = 0200h
usbPacket32   = 0400h
usbPacket64   = 0800h

pipeIn        = 1
pipeOut       = 2

pipeBitIn     = 0
pipeBitOut    = 1

cbNewData = 0
cbStall   = 1
cbNak     = 2

descDevice    = 0
descConfig    = 1
descString    = 2

uGetVersion		= 0
uDriverInit		= 1
uIsDeviceConnected	= 2
uHostInit		= 3
uHostKill		= 4
uReadDescriptor		= 5
uGetIDs			= 6
uGetClass		= 7
uConfigureDevice	= 8
uSetupOutPipe		= 9
uSetupInPipe		= 10
uFindDescriptor		= 11
uSendData		= 12
uAutoSetup		= 13
uSendControlData	= 14
uReqData             = 15
uDriverKill          = 16
uMouseInit           = 17
uMouseGetKey         = 18 
uWaitTimerB		= 19
uPipeInfo		= 20
uSetupLog		= 21
uSendDataPart		= 22
uFindPipe		= 23
uStopLog		= 24
uLogCustom		= 25
uKBDVersion		= 26
uMSDVersion		= 27
uMSD_Initialize		= 28
uUFI_Initialize		= 29
uUFI_Read		= 30
uUFI_Write		= 31
uFAT_Initialize		= 32
uFAT_lookupPath		= 33
uDOS_openFile		= 34
uDOS_fileSeek		= 35
uDOS_fileRead		= 36
uDOS_fileWrite		= 37
uDOS_createFile		= 38
uDOS_createDirectory	= 39
uDOS_deleteFileEntry	= 40
uDOS_countFilesInDir	= 41
uDOS_getNextFile	= 42
uFAT_getStartingCluster	= 43
uMSD_ImportVariable	= 44
uMSD_ExportVariable	= 45
uDOS_renameFileEntry	= 46
uFAT_nameConvertTo11	= 47
uFAT_nameConvertFrom11	= 48
uFAT_findFileInCluster	= 49
uDOS_getFileSize	= 50
uDOS_getDirEntry	= 51
uKBDInit             	= 52
uKBDGetKey           	= 53
uKBDGetMods         	= 54
uKBDCheckDirect      	= 55
uSilverInit          	= 56
uSilverSend           	= 57
uSetCallBack         	= 58
uPadInit             	= 59
uPadSetup            	= 60
uPadStart            	= 61
uGetErrorCode        	= 62
uPadVersion		= 63
uInternalInfo		= 64
uSendControlDataOut   	= 65
uVernierVersion      = 66
uVernierInit         = 67
uVernierSendCmd      = 68
uVernierQuickCmd     = 69
uVernierGetMeas      = 70
uVernierToDegree     = 71
uDOS_updateAttributes = 72
uPumpOn			= 73
uPumpOff		= 74
uPump			= 75
uMSD_cacheOn		= 76
uMSD_cacheOff		= 77
umsdDetect           = 78

USBDriverEntryPoint = 404Ch




mouseRight    = 1
mouseLeft     = 2
mouseUp       = 4
mouseDown     = 8

mouseBitRight = 0
mouseBitLeft  = 1
mouseBitUp    = 2
mouseBitDown  = 3

MSDBOTState					= 0			;1 - bulk-only transport state (0 - nothing, 1 - getting data, 2 - CSW)
MSDLBA						= MSDBOTState+1	;4 - LBA address for read/write routines
MSDPartStart					= MSDLBA+4		;4 - start of FAT16 partition
MSDBPS						= MSDPartStart+4	;2 - bytes per sector (typically 512)
MSDDataInAddr					= MSDBPS+2		;2 - address of incoming/outgoing data
MSDDataInExpected				= MSDDataInAddr+2	;2 - data expected to be received/sent
MSDSPC						= MSDDataInExpected+2	;1 - sectors per cluster (typically 2, 4, and so on)
MSDFATSectors					= MSDSPC+1		;2 - number of sectors per FAT
MSDRootDirSectors				= MSDFATSectors+2	;2 - number of root directory sectors (something like 32)
MSDFirstDataSector				= MSDRootDirSectors+2	;4 - first data sector
MSDFirstRootDirSecNum				= MSDFirstDataSector+4;2 - first sector of root
MSDFATStart					= MSDFirstRootDirSecNum+2;2 - first sector of first FAT
MSDOutPipe					= MSDFATStart+2	;1 - bulk out pipe
MSDInPipe					= MSDOutPipe+1	;1 - bulk in pipe
MSDFAT_sector					= MSDInPipe+1		;2 - temporary storage for FAT_getNextCluster output
MSDDescBuf					= MSDFAT_sector+2	;128 - buffer for descriptors
MSDBulkBuf					= MSDDescBuf+128	;31 - incoming data buffer
MSDPacketData					= MSDBulkBuf+31	;64 - buffer to build data packets

errPort82			= 1
errPort91Bit2			= 2 ;Stall
errPort91Bit4			= 3
errPort4C			= 4
errPort4D	    	       = 5
errPort3A	           	= 6
errPort81                   = 7
errPort8C                   = 8
errPort8F                   = 9
errEPIndex                  = 10
errEPGetDes                 = 11
errNoDevice                 = 12
errFindDescriptor           = 13
errBadClass                 = 14
errTimeout                  = 15
errBadID                    = 16
errReadDescriptor           = 17
errInit                     = 18
errAutoSetup                = 19
errDemo                     = 20
errFindPipe                 = 21
errStub                     = 22
errGetMaxPacketSize		= 23
errSetAddress               = 24
errMSDSendCmd               = 25	;Problem sending bulk-only in/out commands
errMSDLargeSect             = 26	;Bytes-per-sector is larger than 512 (not supported)
errMSDNoParts               = 27	;No FAT16 primary partitions were found
errMSDNoMoreMemory          = 28	;Function failed because no more memory available (this is a bad thing, delete incomplete file/directories)
errMSDInvalidPartition      = 29	;Partition is invalid (does not contain 0AA55h)
errMSDNotFile               = 30	;Path is a directory or volume label, not file
errMSDNotValidPath          = 31	;Path is not in any way valid :)
errMSDCorruptFile           = 32	;File is corrupted or otherwise not as expected
errMSDNotFound              = 33	;File/directory was not found
errMSDDuplicateFound        = 34 ;Duplicate calculator variable was found and was not overwritten
errMSDNotEnoughMem          = 35 ;Not enough memory to create new calculator variable
errMSDAlreadyExists         = 36	;*.8x* of same name already exists
errMSDStrNotFound           = 37 ;String variable from BASIC OpenLib/ExecLib function not found
errMSDVarEmpty              = 38 ;Variable was empty and transfer was not completed (this is bad, delete incomplete file)
errMSDNoParts32		= 39 ;FAT32 partitions were found, but none were FAT16 (just a friendly message)
errNoData                   = 40
errVersion                  = 41
errBadCmd                   = 42
errFeatureDisabled          = 43
errMSDFailedCmd             = 44
errMSDCmdTimeout            = 45
errMSDCmdRefused            = 46


descDevice    = 1
descConfig    = 2
descString    = 3
descInterface = 4
descEndpoint  = 5
descDQ        = 6
descOSC       = 7
descIP        = 8
descOnTheGo   = 9
descHID       = 21h
descReport    = 22h
descHub       = 29h


cacheFlagRAM = 0

kbdFlagNoLocks = 0
kbdFlagNumLock = 1
kbdFlagCapsLock = 2
kbdFlagScrollLock = 3
kbdFlagCallBack = 4

kbdLCtrlBit = 0
kbdLShiftBit = 1
kbdLAltBit = 2
kbdLGUIBit = 3
kbdRCtrlBit = 4
kbdRShiftBit = 5
kbdRAltBit = 6
kbdRGUIBit = 7

kbdLCtrl = 1
kbdLShift = 2
kbdLAlt = 4
kbdLGUI = 8
kbdRCtrl = 16
kbdRShift = 32
kbdRAlt = 64
kbdRGUI = 128

kbdK1         = 1Eh
kbdK2         = 1Fh
kbdK3         = 20h
kbdK4         = 21h
kbdK5         = 22h
kbdK6         = 23h
kbdK7         = 24h
kbdK8         = 25h
kbdK9         = 26h
kbdK0         = 27h

kbdKBackQuote = 35h       ;` ~
kbdKMinus     = 2Dh       ;- _
kbdKEqu       = 2Eh       ;= +
kbdKBackSpace = 2Ah
kbdKEsc       = 29h
kbdKTab       = 2Bh
kbdKCapsLock  = 39h
kbdKLBrack    = 2Fh
kbdKRBrack    = 30h
kbdKBackSlash = 31h
kbdKSemicolon = 33h
kbdKApostrophe = 34h
kbdKEnter     = 28h
kbdKComma     = 36h
kbdKPeriod    = 37h
kbdKSlash     = 38h
kbdKSpace     = 2Ch

kbdKA         = 4
kbdKB         = 5
kbdKC         = 6
kbdKD         = 7
kbdKE         = 8
kbdKF         = 9
kbdKG         = 0Ah
kbdKH         = 0Bh
kbdKI         = 0Ch
kbdKJ         = 0Dh
kbdKK         = 0Eh
kbdKL         = 0Fh
kbdKM         = 10h
kbdKN         = 11h
kbdKO         = 12h
kbdKP         = 13h
kbdKQ         = 14h
kbdKR         = 15h
kbdKS         = 16h
kbdKT         = 17h
kbdKU         = 18h
kbdKV         = 19h
kbdKW         = 1Ah
kbdKX         = 1Bh
kbdKY         = 1Ch
kbdKZ         = 1Dh

kbdKF1        = 3Ah
kbdKF2        = 3Bh
kbdKF3        = 3Ch
kbdKF4        = 3Dh
kbdKF5        = 3Eh
kbdKF6        = 3Fh
kbdKF7        = 40h
kbdKF8        = 41h
kbdKF9        = 42h
kbdKF10       = 43h
kbdKF11       = 44h
kbdKF12       = 45h

kbdKRight     = 4Fh
kbdKLeft      = 50h
kbdKDown      = 51h
kbdKUp        = 52h

kbdKSysRq     = 46h
kbdKScrollLock = 47h
kbdKBreak     = 48h
kbdKInsert    = 49h
kbdKHome      = 4Ah
kbdKPageUp    = 4Bh
kbdKDelete    = 4Ch
kbdKEnd       = 4Dh
kbdKPageDown  = 4Eh

kbdKNumLock   = 53h
kbdKNSlash    = 54h
kbdKNStar     = 55h
kbdKNMinus    = 56h
kbdKNPlus     = 57h
kbdKNEnter    = 58h
kbdKN1        = 59h
kbdKN2        = 5Ah
kbdKN3        = 5Bh
kbdKN4        = 5Ch
kbdKN5        = 5Dh
kbdKN6        = 5Eh
kbdKN7        = 5Fh
kbdKN8        = 60h
kbdKN9        = 61h
kbdKN0        = 62h
kbdKNPeriod   = 63h

.define U_CALL(label) ld a,u label\ call USBDriverCall

.define U_CALL2(label) ld a,label\ call USBDriverCall

.define U_CALL({SilverInit}) ld ix,USBDriverCall+offCallBack\ U_CALL2(uSilverInit)

.define U_CALL({KBDInit}) ld ix,USBDriverCall+offCallBack\ U_CALL2(uKBDInit)

.define U_CALL({AutoSetup}) ld de,USBDriverCall+offCallBack\ U_CALL2(uAutoSetup)

.define U_CALL({PadInit}) ld ix,USBDriverCall+offCallBack\ U_CALL2(uPadInit)

.define U_CALL({MouseInit}) ld ix,USBDriverCall+offCallBack\ U_CALL2(uMouseInit)

.define U_CALL({VernierInit}) ld ix,USBDriverCall+offCallBack\ U_CALL2(uVernierInit)
	
 
#define U_CALL_INIT(label) 	ld	hl,uuAppName
#defcont	\       rst    20h
#defcont	\       rst    28h
#defcont	\       .dw    $4C4E
#defcont	\       jr     c,uuDone
#defcont	\       ld     de,USBDriverCall
#defcont	\       ld     hl,uuDriverCode
#defcont	\       ld     bc,uuDriverSize
#defcont	\       ldir
#defcont	\       ld     (USBDriverCall+uuMod1 + 1),a
#defcont	\       in     a,(6)
#defcont	\       ld     (USBDriverCall+uuMod3 +1),a
#defcont	\       or     a
#defcont	\       jr     uuDone
#defcont	\uuAppName:
#defcont	\       .db     $14,"USBDRV8X",0
#defcont	\uuDriverCode:
#defcont	\       push   af
#defcont	\       in     a,(6)
#defcont	\       ld     (USBDriverCall+uuMod2 +1),a
#defcont	\       call	USBDriverCall+uuCall1
#defcont	\       pop    af
#defcont	\       call   USBDriverEntryPoint
#defcont	\       push   af
#defcont	\uuMod2 = $ - uuDriverCode
#defcont	\       ld     a,0
#defcont	\       out    (6),a
#defcont	\       pop    af
#defcont	\       ret
#defcont	\uuCallBack:
#defcont	\uuMod3 = $-uuDriverCode
#defcont	\       ld     a,0
#defcont	\       out    (6),a
#defcont	\       call   label
#defcont	\uuCall1 EQU $-uuDriverCode
#defcont	\uuMod1 EQU $-uuDriverCode
#defcont	\	ld	a,0
#defcont	\       out    (6),a
#defcont	\       ret
#defcont	\uuDriverSize = $ - uuDriverCode
#defcont	\uuDone:
#defcont	\offCallBack          = uuCallBack-uuDriverCode


.end



