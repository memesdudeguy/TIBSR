; TI-83 Plus Include File
; Provides constants, macros, and system routines for assembly programming

; === Constants ===
#define kClear   $09      ; [CLEAR] key
#define kEnter   $05      ; [ENTER] key
#define kLeft    $02      ; [LEFT] key
#define kRight   $03      ; [RIGHT] key
#define kUp      $01      ; [UP] key
#define kDown    $04      ; [DOWN] key

; === Graphics Buffer ===
#define _GrBufClr  $4BFC  ; Clear graph buffer
#define _GrBufCpy  $4C0F  ; Copy graph buffer to LCD

; === System Routines ===
#define _GetKey    $4010  ; Wait for key press
#define _IPoint    $50B0  ; Set a pixel on
#define _ClrPixel  $50B3  ; Clear a pixel

; === Port Addresses ===
#define LCD_MEM    $FC00  ; Start of LCD memory
#define GRAPH_MEM  $FC00  ; Alias for graph buffer

; === Macros ===
.macro WaitForKey
    CALL _GetKey
.endm

; === Pixel Manipulation ===
; Turn a pixel on at (L, H)
_pixel_on:
    LD A, L            ; Load X coordinate into A
    LD E, A            ; Save X to E
    LD A, H            ; Load Y coordinate into A
    LD D, A            ; Save Y to D
    CALL _IPoint       ; Call TI-83 Plus ROM function to set a pixel
    RET

; Turn a pixel off at (L, H)
_pixel_off:
    LD A, L            ; Load X coordinate into A
    LD E, A            ; Save X to E
    LD A, H            ; Load Y coordinate into
