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
TMR0			EQU	(001h & 07Fh)	; BANK0
PCL				EQU	(002h & 07Fh)	; BANK0
STATUS			EQU	(003h & 07Fh)	; BANK0
FSR				EQU	(004h & 07Fh)	; BANK0
PORTA			EQU	(005h & 07Fh)	; BANK0
PORTB			EQU	(006h & 07Fh)	; BANK0
PORTC			EQU	(007h & 07Fh)	; BANK0
PORTD			EQU	(008h & 07Fh)	; BANK0
PORTE			EQU	(009h & 07Fh)	; BANK0
TRISA			EQU	(005h & 07Fh)	; BANK0
TRISB			EQU	(006h & 07Fh)	; BANK0
TRISC			EQU	(007h & 07Fh)	; BANK0
TRISD			EQU	(008h & 07Fh)	; BANK0
TRISE			EQU	(009h & 07Fh)	; BANK0
OPTION_REG		EQU	(000h & 07Fh)	; BANK0

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
PA0				EQU	5	; STATUS
PA1				EQU	6	; STATUS
PA2				EQU	7	; STATUS
; =====================================
RA0				EQU	0	; PORTA
RA1				EQU	1	; PORTA
RA2				EQU	2	; PORTA
RA3				EQU	3	; PORTA
; =====================================
RB0				EQU	0	; PORTB
RB1				EQU	1	; PORTB
RB2				EQU	2	; PORTB
RB3				EQU	3	; PORTB
RB4				EQU	4	; PORTB
RB5				EQU	5	; PORTB
RB6				EQU	6	; PORTB
RB7				EQU	7	; PORTB
; =====================================
RC0				EQU	0	; PORTC
RC1				EQU	1	; PORTC
RC2				EQU	2	; PORTC
RC3				EQU	3	; PORTC
RC4				EQU	4	; PORTC
RC5				EQU	5	; PORTC
RC6				EQU	6	; PORTC
RC7				EQU	7	; PORTC
; =====================================
RD0				EQU	0	; PORTD
RD1				EQU	1	; PORTD
RD2				EQU	2	; PORTD
RD3				EQU	3	; PORTD
RD4				EQU	4	; PORTD
RD5				EQU	5	; PORTD
RD6				EQU	6	; PORTD
RD7				EQU	7	; PORTD
; =====================================
RE4				EQU	4	; PORTE
RE5				EQU	5	; PORTE
RE6				EQU	6	; PORTE
RE7				EQU	7	; PORTE

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	0FFFh
RC				EQU	0FFFh
LP				EQU	0FFCh
XT				EQU	0FFDh
HS				EQU	0FFEh
WDTEN			EQU	0FFFh
WDTDIS			EQU	0FFBh
UNPROTECT		EQU	0FFFh
CP				EQU	0FF7h
