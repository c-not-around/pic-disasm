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
PORTC			EQU	(0007h & 07Fh)	; BANK0
CM1CON0			EQU	(0008h & 07Fh)	; BANK0
ADCON0			EQU	(0009h & 07Fh)	; BANK0
ADRES			EQU	(000Ah & 07Fh)	; BANK0
CM2CON0			EQU	(000Bh & 07Fh)	; BANK0
VRCON			EQU	(000Ch & 07Fh)	; BANK0
OPTION_REG		EQU	(0000h & 07Fh)	; BANK0
TRISB			EQU	(0006h & 07Fh)	; BANK0
TRISC			EQU	(0007h & 07Fh)	; BANK0

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
PA0				EQU	5	; STATUS
CWUF			EQU	6	; STATUS
RBWUF			EQU	7	; STATUS
; =====================================
CAL0			EQU	1	; OSCCAL
CAL1			EQU	2	; OSCCAL
CAL2			EQU	3	; OSCCAL
CAL3			EQU	4	; OSCCAL
CAL4			EQU	5	; OSCCAL
CAL5			EQU	6	; OSCCAL
CAL6			EQU	7	; OSCCAL
; =====================================
RB0				EQU	0	; PORTB
RB1				EQU	1	; PORTB
RB2				EQU	2	; PORTB
RB3				EQU	3	; PORTB
RB4				EQU	4	; PORTB
RB5				EQU	5	; PORTB
; =====================================
RC0				EQU	0	; PORTC
RC1				EQU	1	; PORTC
RC2				EQU	2	; PORTC
RC3				EQU	3	; PORTC
RC4				EQU	4	; PORTC
RC5				EQU	5	; PORTC
; =====================================
C1WU			EQU	0	; CM1CON0
C1PREF			EQU	1	; CM1CON0
C1NREF			EQU	2	; CM1CON0
C1ON			EQU	3	; CM1CON0
C1T0CS			EQU	4	; CM1CON0
C1POL			EQU	5	; CM1CON0
C1OUTEN			EQU	6	; CM1CON0
C1OUT			EQU	7	; CM1CON0
; =====================================
ADON			EQU	0	; ADCON0
GODONE			EQU	1	; ADCON0
CHS0			EQU	2	; ADCON0
CHS1			EQU	3	; ADCON0
ADCS0			EQU	4	; ADCON0
ADCS1			EQU	5	; ADCON0
ANS0			EQU	6	; ADCON0
ANS1			EQU	7	; ADCON0
; =====================================
C2WU			EQU	0	; CM2CON0
C2PREF1			EQU	1	; CM2CON0
C2NREF			EQU	2	; CM2CON0
C2ON			EQU	3	; CM2CON0
C2PREF2			EQU	4	; CM2CON0
C2POL			EQU	5	; CM2CON0
C2OUTEN			EQU	6	; CM2CON0
C2OUT			EQU	7	; CM2CON0
; =====================================
VR0				EQU	0	; VRCON
VR1				EQU	1	; VRCON
VR2				EQU	2	; VRCON
VR3				EQU	3	; VRCON
VRR				EQU	5	; VRCON
VROE			EQU	6	; VRCON
VREN			EQU	7	; VRCON

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	0FFFh
EXTCLKO			EQU	0FFFh
EXTIO			EQU	0FFEh
INTCLKO			EQU	0FFDh
INTIO			EQU	0FFCh
EC				EQU	0FFBh
HS				EQU	0FFAh
XT				EQU	0FF9h
LP				EQU	0FF8h
WDTEN			EQU	0FFFh
WDTDIS			EQU	0FF7h
UNPROTECT		EQU	0FFFh
CP				EQU	0FEFh
MCLREN			EQU	0FFFh
MCLRDIS			EQU	0FDFh
INTOSC8			EQU	0FFFh
INTOSC4			EQU	0FBFh
