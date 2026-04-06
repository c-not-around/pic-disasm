; =====================================
;		Banks Definitions
; =====================================
BANK0			EQU	000h
BANK1			EQU	001h
BANK2			EQU	002h
BANK3			EQU	003h
BANK4			EQU	004h
BANK5			EQU	005h
BANK6			EQU	006h
BANK7			EQU	007h
BANK8			EQU	008h
BANK9			EQU	009h
BANK10			EQU	00Ah
BANK11			EQU	00Bh
BANK12			EQU	00Ch
BANK13			EQU	00Dh
BANK14			EQU	00Eh
BANK15			EQU	00Fh
BANK16			EQU	010h
BANK17			EQU	011h
BANK18			EQU	012h
BANK19			EQU	013h
BANK20			EQU	014h
BANK21			EQU	015h
BANK22			EQU	016h
BANK23			EQU	017h
BANK24			EQU	018h
BANK25			EQU	019h
BANK26			EQU	01Ah
BANK27			EQU	01Bh
BANK28			EQU	01Ch
BANK29			EQU	01Dh
BANK30			EQU	01Eh
BANK31			EQU	01Fh

; =====================================
;		SFR Definitions
; =====================================
INDF			EQU	(0000h & 07Fh)	; BANK0
TRIS			EQU	(0006h & 07Fh)	; BANK0
OPTION_REG		EQU	(0000h & 07Fh)	; BANK0
TMR0			EQU	(0001h & 07Fh)	; BANK0
PCL				EQU	(0002h & 07Fh)	; BANK0
STATUS			EQU	(0003h & 07Fh)	; BANK0
FSR				EQU	(0004h & 07Fh)	; BANK0
OSCCAL			EQU	(0005h & 07Fh)	; BANK0
PORTB			EQU	(0006h & 07Fh)	; BANK0
EECON			EQU	(0021h & 07Fh)	; BANK0
EEDATA			EQU	(0025h & 07Fh)	; BANK0
EEDATL			EQU	(0025h & 07Fh)	; BANK0
EEADR			EQU	(0026h & 07Fh)	; BANK0
EEADRL			EQU	(0026h & 07Fh)	; BANK0

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
PA0				EQU	5	; STATUS
RBWUF			EQU	6	; STATUS
; =====================================
CAL0			EQU	0	; OSCCAL
CAL1			EQU	1	; OSCCAL
CAL2			EQU	2	; OSCCAL
CAL3			EQU	3	; OSCCAL
CAL4			EQU	4	; OSCCAL
CAL5			EQU	5	; OSCCAL
CAL6			EQU	6	; OSCCAL
; =====================================
RB0				EQU	0	; PORTB
RB1				EQU	1	; PORTB
RB2				EQU	2	; PORTB
RB3				EQU	3	; PORTB
RB4				EQU	4	; PORTB
RB5				EQU	5	; PORTB
; =====================================
RD				EQU	0	; EECON
WR				EQU	1	; EECON
WREN			EQU	2	; EECON
WRERR			EQU	3	; EECON
FREE			EQU	4	; EECON

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	07FFh
CPD				EQU	0FBFh
OSC_8MHZ		EQU	0FFFh
OSC_4MHZ		EQU	0FDFh
MCLREN			EQU	0FFFh
MCLRDIS			EQU	0FEFh
UNPROTECT		EQU	0FFFh
PROTECT			EQU	0FF7h
WDTEN			EQU	0FFFh
WDTDIS			EQU	0FFBh
EXTRC			EQU	0FFFh
INTOSC			EQU	0FFEh
XT				EQU	0FFDh
LP				EQU	0FFCh
