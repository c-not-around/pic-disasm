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
INDF			EQU	(000h & 07Fh)	; BANK0
TMR0			EQU	(0001h & 07Fh)	; BANK0
PCL				EQU	(0002h & 07Fh)	; BANK0
STATUS			EQU	(0003h & 07Fh)	; BANK0
FSR				EQU	(0004h & 07Fh)	; BANK0
OSCCAL			EQU	(0005h & 07Fh)	; BANK0
GPIO			EQU	(0006h & 07Fh)	; BANK0
ADCON0			EQU	(0007h & 07Fh)	; BANK0
ADRES			EQU	(0008h & 07Fh)	; BANK0
OPTION_REG		EQU	(000h & 07Fh)	; BANK0
TRISGPIO		EQU	(006h & 07Fh)	; BANK0
TRIS			EQU	(006h & 07Fh)	; BANK0

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
GPWUF			EQU	7	; STATUS
; =====================================
FOSC4			EQU	0	; OSCCAL
CAL0			EQU	1	; OSCCAL
CAL1			EQU	2	; OSCCAL
CAL2			EQU	3	; OSCCAL
CAL3			EQU	4	; OSCCAL
CAL4			EQU	5	; OSCCAL
CAL5			EQU	6	; OSCCAL
CAL6			EQU	7	; OSCCAL
; =====================================
GP0				EQU	0	; GPIO
GP1				EQU	1	; GPIO
GP2				EQU	2	; GPIO
GP3				EQU	3	; GPIO
; =====================================
ADON			EQU	0	; ADCON0
GODONE			EQU	1	; ADCON0
CHS0			EQU	2	; ADCON0
CHS1			EQU	3	; ADCON0
ANS0			EQU	6	; ADCON0
ANS1			EQU	7	; ADCON0

; =====================================
;		Configuration Definitions
; =====================================
OSC_8MHZ		EQU	0FFFh
OSC_4MHZ		EQU	0FFEh
MCPUEN			EQU	0FFDh
MCPUDIS			EQU	0FFFh
WDTEN			EQU	0FFFh
WDTDIS			EQU	0FFBh
PROTECT			EQU	0FF7h
UNPROTECT		EQU	0FFFh
MCLREN			EQU	0FFFh
MCLRDIS			EQU	0FEFh
