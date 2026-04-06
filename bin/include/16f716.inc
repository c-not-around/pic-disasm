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
PCLATH			EQU	(00Ah & 07Fh)	; BANK0
INTCON			EQU	(00Bh & 07Fh)	; BANK0
PIR1			EQU	(00Ch & 07Fh)	; BANK0
TMR1L			EQU	(00Eh & 07Fh)	; BANK0
TMR1H			EQU	(00Fh & 07Fh)	; BANK0
T1CON			EQU	(010h & 07Fh)	; BANK0
TMR2			EQU	(011h & 07Fh)	; BANK0
T2CON			EQU	(012h & 07Fh)	; BANK0
CCPR1L			EQU	(015h & 07Fh)	; BANK0
CCPR1H			EQU	(016h & 07Fh)	; BANK0
CCP1CON			EQU	(017h & 07Fh)	; BANK0
PWM1CON			EQU	(018h & 07Fh)	; BANK0
ECCPAS			EQU	(019h & 07Fh)	; BANK0
ADRES			EQU	(01Eh & 07Fh)	; BANK0
ADCON0			EQU	(01Fh & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(081h & 07Fh)	; BANK1
TRISA			EQU	(085h & 07Fh)	; BANK1
TRISB			EQU	(086h & 07Fh)	; BANK1
PIE1			EQU	(08Ch & 07Fh)	; BANK1
PCON			EQU	(08Eh & 07Fh)	; BANK1
PR2				EQU	(092h & 07Fh)	; BANK1
ADCON1			EQU	(09Fh & 07Fh)	; BANK1

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
RP0				EQU	5	; STATUS
RP1				EQU	6	; STATUS
IRP				EQU	7	; STATUS
; =====================================
RA0				EQU	0	; PORTA
RA1				EQU	1	; PORTA
RA2				EQU	2	; PORTA
RA3				EQU	3	; PORTA
RA4				EQU	4	; PORTA
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
RBIF			EQU	0	; INTCON
INTF			EQU	1	; INTCON
T0IF			EQU	2	; INTCON
RBIE			EQU	3	; INTCON
INTE			EQU	4	; INTCON
T0IE			EQU	5	; INTCON
PEIE			EQU	6	; INTCON
GIE				EQU	7	; INTCON
; =====================================
TMR1IF			EQU	0	; PIR1
TMR2IF			EQU	1	; PIR1
CCP1IF			EQU	2	; PIR1
ADIF			EQU	6	; PIR1
; =====================================
TMR1ON			EQU	0	; T1CON
TMR1CS			EQU	1	; T1CON
T1SYNC			EQU	2	; T1CON
T1OSCEN			EQU	3	; T1CON
T1CKPS0			EQU	4	; T1CON
T1CKPS1			EQU	5	; T1CON
; =====================================
T2CKPS0			EQU	0	; T2CON
T2CKPS1			EQU	1	; T2CON
TMR2ON			EQU	2	; T2CON
TOUTPS0			EQU	3	; T2CON
TOUTPS1			EQU	4	; T2CON
TOUTPS2			EQU	5	; T2CON
TOUTPS3			EQU	6	; T2CON
; =====================================
CCP1M0			EQU	0	; CCP1CON
CCP1M1			EQU	1	; CCP1CON
CCP1M2			EQU	2	; CCP1CON
CCP1M3			EQU	3	; CCP1CON
DC1B0			EQU	4	; CCP1CON
DC1B1			EQU	5	; CCP1CON
P1M0			EQU	6	; CCP1CON
P1M1			EQU	7	; CCP1CON
; =====================================
PDC0			EQU	0	; PWM1CON
PDC1			EQU	1	; PWM1CON
PDC2			EQU	2	; PWM1CON
PDC3			EQU	3	; PWM1CON
PDC4			EQU	4	; PWM1CON
PDC5			EQU	5	; PWM1CON
PDC6			EQU	6	; PWM1CON
PRSEN			EQU	7	; PWM1CON
; =====================================
PSSBD0			EQU	0	; ECCPAS
PSSBD1			EQU	1	; ECCPAS
PSSAC0			EQU	2	; ECCPAS
PSSAC1			EQU	3	; ECCPAS
ECCPAS0			EQU	4	; ECCPAS
ECCPAS2			EQU	6	; ECCPAS
ECCPASE			EQU	7	; ECCPAS
; =====================================
ADON			EQU	0	; ADCON0
GODONE			EQU	2	; ADCON0
CHS0			EQU	3	; ADCON0
CHS1			EQU	4	; ADCON0
CHS2			EQU	5	; ADCON0
ADCS0			EQU	6	; ADCON0
ADCS1			EQU	7	; ADCON0
; =====================================
PS0				EQU	0	; OPTION_REG
PS1				EQU	1	; OPTION_REG
PS2				EQU	2	; OPTION_REG
PSA				EQU	3	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
INTEDG			EQU	6	; OPTION_REG
RBPU			EQU	7	; OPTION_REG
; =====================================
TRISA0			EQU	0	; TRISA
TRISA1			EQU	1	; TRISA
TRISA2			EQU	2	; TRISA
TRISA3			EQU	3	; TRISA
TRISA4			EQU	4	; TRISA
; =====================================
TRISB0			EQU	0	; TRISB
TRISB1			EQU	1	; TRISB
TRISB2			EQU	2	; TRISB
TRISB3			EQU	3	; TRISB
TRISB4			EQU	4	; TRISB
TRISB5			EQU	5	; TRISB
TRISB6			EQU	6	; TRISB
TRISB7			EQU	7	; TRISB
; =====================================
TMR1IE			EQU	0	; PIE1
TMR2IE			EQU	1	; PIE1
CCP1IE			EQU	2	; PIE1
ADIE			EQU	6	; PIE1
; =====================================
BOR				EQU	0	; PCON
POR				EQU	1	; PCON
; =====================================
PCFG0			EQU	0	; ADCON1
PCFG1			EQU	1	; ADCON1
PCFG2			EQU	2	; ADCON1

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	02007h
PROTECT			EQU	01FFFh
UNPROTECT		EQU	03FFFh
BORV25			EQU	03F7Fh
BORV40			EQU	03FFFh
BORON			EQU	03FFFh
BORDIS			EQU	03FBFh
PWRTEN			EQU	03FF7h
PWRTDIS			EQU	03FFFh
WDTEN			EQU	03FFFh
WDTDIS			EQU	03FFBh
RC				EQU	03FFFh
HS				EQU	03FFEh
XT				EQU	03FFDh
LP				EQU	03FFCh
