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
TMR0			EQU	(0001h & 07Fh)	; BANK0
PCL				EQU	(0002h & 07Fh)	; BANK0
STATUS			EQU	(0003h & 07Fh)	; BANK0
FSR				EQU	(0004h & 07Fh)	; BANK0
OSCCAL			EQU	(0005h & 07Fh)	; BANK0
PORTB			EQU	(0006h & 07Fh)	; BANK0
EECON			EQU	(0021h & 07Fh)	; BANK0
EEDATA			EQU	(0025h & 07Fh)	; BANK0
EEADR			EQU	(0026h & 07Fh)	; BANK0
WREG			EQU	(0051h & 07Fh)	; BANK0
STKPTR			EQU	(0052h & 07Fh)	; BANK0
TRISB			EQU	(0053h & 07Fh)	; BANK0
OPTION_REG		EQU	(0054h & 07Fh)	; BANK0

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
nPD				EQU	3	; STATUS
nTO				EQU	4	; STATUS
PA0				EQU	5	; STATUS
PA1				EQU	6	; STATUS
RBWUF			EQU	7	; STATUS
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
TRISB0			EQU	0	; TRISB
TRISB1			EQU	1	; TRISB
TRISB2			EQU	2	; TRISB
TRISB3			EQU	3	; TRISB
TRISB4			EQU	4	; TRISB
TRISB5			EQU	5	; TRISB
; =====================================
PSA				EQU	3	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
nRBPU			EQU	6	; OPTION_REG
nRBWU			EQU	7	; OPTION_REG

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG			EQU	00FFFh
OSC_LP			EQU	0FFFCh
OSC_XT			EQU	0FFFDh
OSC_INTRC		EQU	0FFFEh
OSC_EXTRC		EQU	0FFFFh
WDT_ON			EQU	0FFFFh
WDT_OFF			EQU	0FFFBh
CP_OFF			EQU	0FFFFh
CP_ON			EQU	0FFF7h
MCLR_ON			EQU	0FFFFh
MCLR_OFF		EQU	0FFEFh
IOSCFS_8MHZ		EQU	0FFFFh
IOSCFS_4MHZ		EQU	0FFDFh
CPDF_OFF		EQU	0FFFFh
CPDF_ON			EQU	0FFBFh
