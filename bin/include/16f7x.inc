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
PCLATH			EQU	(00Ah & 07Fh)	; BANK0
INTCON			EQU	(00Bh & 07Fh)	; BANK0
PIR1			EQU	(00Ch & 07Fh)	; BANK0
PIR2			EQU	(00Dh & 07Fh)	; BANK0
TMR1L			EQU	(00Eh & 07Fh)	; BANK0
TMR1H			EQU	(00Fh & 07Fh)	; BANK0
T1CON			EQU	(010h & 07Fh)	; BANK0
TMR2			EQU	(011h & 07Fh)	; BANK0
T2CON			EQU	(012h & 07Fh)	; BANK0
SSPBUF			EQU	(013h & 07Fh)	; BANK0
SSPCON			EQU	(014h & 07Fh)	; BANK0
CCPR1L			EQU	(015h & 07Fh)	; BANK0
CCPR1H			EQU	(016h & 07Fh)	; BANK0
CCP1CON			EQU	(017h & 07Fh)	; BANK0
RCSTA			EQU	(018h & 07Fh)	; BANK0
TXREG			EQU	(019h & 07Fh)	; BANK0
RCREG			EQU	(01Ah & 07Fh)	; BANK0
CCPR2L			EQU	(01Bh & 07Fh)	; BANK0
CCPR2H			EQU	(01Ch & 07Fh)	; BANK0
CCP2CON			EQU	(01Dh & 07Fh)	; BANK0
ADRES			EQU	(01Eh & 07Fh)	; BANK0
ADCON0			EQU	(01Fh & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(081h & 07Fh)	; BANK1
TRISA			EQU	(085h & 07Fh)	; BANK1
TRISB			EQU	(086h & 07Fh)	; BANK1
TRISC			EQU	(087h & 07Fh)	; BANK1
TRISD			EQU	(088h & 07Fh)	; BANK1
TRISE			EQU	(089h & 07Fh)	; BANK1
PIE1			EQU	(08Ch & 07Fh)	; BANK1
PIE2			EQU	(08Dh & 07Fh)	; BANK1
PCON			EQU	(08Eh & 07Fh)	; BANK1
PR2				EQU	(092h & 07Fh)	; BANK1
SSPADD			EQU	(093h & 07Fh)	; BANK1
SSPSTAT			EQU	(094h & 07Fh)	; BANK1
TXSTA			EQU	(098h & 07Fh)	; BANK1
SPBRG			EQU	(099h & 07Fh)	; BANK1
ADCON1			EQU	(09Fh & 07Fh)	; BANK1
; =====================================
PMDATL			EQU	(010Ch & 07Fh)	; BANK2
PMADRL			EQU	(010Dh & 07Fh)	; BANK2
PMDATA			EQU	(010Ch & 07Fh)	; BANK2
PMADR			EQU	(010Dh & 07Fh)	; BANK2
PMDATH			EQU	(010Eh & 07Fh)	; BANK2
PMADRH			EQU	(010Fh & 07Fh)	; BANK2
; =====================================
PMCON1			EQU	(018Ch & 07Fh)	; BANK3

; =====================================
;		SFR's Bits Definitions
; =====================================
IRP				EQU	7	; STATUS
RP1				EQU	6	; STATUS
RP0				EQU	5	; STATUS
TO				EQU	4	; STATUS
PD				EQU	3	; STATUS
ZERO			EQU	2	; STATUS
DC				EQU	1	; STATUS
CARRY			EQU	0	; STATUS
; =====================================
RA5				EQU	5	; PORTA
RA4				EQU	4	; PORTA
RA3				EQU	3	; PORTA
RA2				EQU	2	; PORTA
RA1				EQU	1	; PORTA
RA0				EQU	0	; PORTA
; =====================================
RB7				EQU	7	; PORTB
RB6				EQU	6	; PORTB
RB5				EQU	5	; PORTB
RB4				EQU	4	; PORTB
RB3				EQU	3	; PORTB
RB2				EQU	2	; PORTB
RB1				EQU	1	; PORTB
RB0				EQU	0	; PORTB
; =====================================
RC7				EQU	7	; PORTC
RC6				EQU	6	; PORTC
RC5				EQU	5	; PORTC
RC4				EQU	4	; PORTC
RC3				EQU	3	; PORTC
RC2				EQU	2	; PORTC
RC1				EQU	1	; PORTC
RC0				EQU	0	; PORTC
; =====================================
RD7				EQU	7	; PORTD
RD6				EQU	6	; PORTD
RD5				EQU	5	; PORTD
RD4				EQU	4	; PORTD
RD3				EQU	3	; PORTD
RD2				EQU	2	; PORTD
RD1				EQU	1	; PORTD
RD0				EQU	0	; PORTD
; =====================================
RE2				EQU	2	; PORTE
RE1				EQU	1	; PORTE
RE0				EQU	0	; PORTE
; =====================================
GIE				EQU	7	; INTCON
PEIE			EQU	6	; INTCON
T0IE			EQU	5	; INTCON
INTE			EQU	4	; INTCON
RBIE			EQU	3	; INTCON
T0IF			EQU	2	; INTCON
INTF			EQU	1	; INTCON
RBIF			EQU	0	; INTCON
TMR0IE			EQU	5	; INTCON
TMR0IF			EQU	2	; INTCON
; =====================================
PSPIF			EQU	7	; PIR1
ADIF			EQU	6	; PIR1
RCIF			EQU	5	; PIR1
TXIF			EQU	4	; PIR1
SSPIF			EQU	3	; PIR1
CCP1IF			EQU	2	; PIR1
TMR2IF			EQU	1	; PIR1
TMR1IF			EQU	0	; PIR1
; =====================================
CCP2IF			EQU	0	; PIR2
; =====================================
T1CKPS1			EQU	5	; T1CON
T1CKPS0			EQU	4	; T1CON
T1OSCEN			EQU	3	; T1CON
T1SYNC			EQU	2	; T1CON
TMR1CS			EQU	1	; T1CON
TMR1ON			EQU	0	; T1CON
; =====================================
TOUTPS3			EQU	6	; T2CON
TOUTPS2			EQU	5	; T2CON
TOUTPS1			EQU	4	; T2CON
TOUTPS0			EQU	3	; T2CON
TMR2ON			EQU	2	; T2CON
T2CKPS1			EQU	1	; T2CON
T2CKPS0			EQU	0	; T2CON
; =====================================
WCOL			EQU	7	; SSPCON
SSPOV			EQU	6	; SSPCON
SSPEN			EQU	5	; SSPCON
CKP				EQU	4	; SSPCON
SSPM3			EQU	3	; SSPCON
SSPM2			EQU	2	; SSPCON
SSPM1			EQU	1	; SSPCON
SSPM0			EQU	0	; SSPCON
; =====================================
CCP1X			EQU	5	; CCP1CON
CCP1Y			EQU	4	; CCP1CON
CCP1M3			EQU	3	; CCP1CON
CCP1M2			EQU	2	; CCP1CON
CCP1M1			EQU	1	; CCP1CON
CCP1M0			EQU	0	; CCP1CON
; =====================================
SPEN			EQU	7	; RCSTA
RX9				EQU	6	; RCSTA
SREN			EQU	5	; RCSTA
CREN			EQU	4	; RCSTA
FERR			EQU	2	; RCSTA
OERR			EQU	1	; RCSTA
RX9D			EQU	0	; RCSTA
; =====================================
CCP2X			EQU	5	; CCP2CON
CCP2Y			EQU	4	; CCP2CON
CCP2M3			EQU	3	; CCP2CON
CCP2M2			EQU	2	; CCP2CON
CCP2M1			EQU	1	; CCP2CON
CCP2M0			EQU	0	; CCP2CON
; =====================================
ADCS1			EQU	7	; ADCON0
ADCS0			EQU	6	; ADCON0
CHS2			EQU	5	; ADCON0
CHS1			EQU	4	; ADCON0
CHS0			EQU	3	; ADCON0
ADGO			EQU	2	; ADCON0
GODONE			EQU	2	; ADCON0
ADON			EQU	0	; ADCON0
; =====================================
RBPU			EQU	7	; OPTION_REG
INTEDG			EQU	6	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
PSA				EQU	3	; OPTION_REG
PS2				EQU	2	; OPTION_REG
PS1				EQU	1	; OPTION_REG
PS0				EQU	0	; OPTION_REG
; =====================================
TRISA5			EQU	5	; TRISA
TRISA4			EQU	4	; TRISA
TRISA3			EQU	3	; TRISA
TRISA2			EQU	2	; TRISA
TRISA1			EQU	1	; TRISA
TRISA0			EQU	0	; TRISA
; =====================================
TRISB7			EQU	7	; TRISB
TRISB6			EQU	6	; TRISB
TRISB5			EQU	5	; TRISB
TRISB4			EQU	4	; TRISB
TRISB3			EQU	3	; TRISB
TRISB2			EQU	2	; TRISB
TRISB1			EQU	1	; TRISB
TRISB0			EQU	0	; TRISB
; =====================================
TRISC7			EQU	7	; TRISC
TRISC6			EQU	6	; TRISC
TRISC5			EQU	5	; TRISC
TRISC4			EQU	4	; TRISC
TRISC3			EQU	3	; TRISC
TRISC2			EQU	2	; TRISC
TRISC1			EQU	1	; TRISC
TRISC0			EQU	0	; TRISC
; =====================================
TRISD7			EQU	7	; TRISD
TRISD6			EQU	6	; TRISD
TRISD5			EQU	5	; TRISD
TRISD4			EQU	4	; TRISD
TRISD3			EQU	3	; TRISD
TRISD2			EQU	2	; TRISD
TRISD1			EQU	1	; TRISD
TRISD0			EQU	0	; TRISD
; =====================================
IBF				EQU	7	; TRISE
OBF				EQU	6	; TRISE
IBOV			EQU	5	; TRISE
PSPMODE			EQU	4	; TRISE
TRISE2			EQU	2	; TRISE
TRISE1			EQU	1	; TRISE
TRISE0			EQU	0	; TRISE
; =====================================
PSPIE			EQU	7	; PIE1
ADIE			EQU	6	; PIE1
RCIE			EQU	5	; PIE1
TXIE			EQU	4	; PIE1
SSPIE			EQU	3	; PIE1
CCP1IE			EQU	2	; PIE1
TMR2IE			EQU	1	; PIE1
TMR1IE			EQU	0	; PIE1
; =====================================
CCP2IE			EQU	0	; PIE2
; =====================================
POR				EQU	1	; PCON
BOR				EQU	0	; PCON
; =====================================
SMP				EQU	7	; SSPSTAT
CKE				EQU	6	; SSPSTAT
DA				EQU	5	; SSPSTAT
STOP			EQU	4	; SSPSTAT
START			EQU	3	; SSPSTAT
RW				EQU	2	; SSPSTAT
UA				EQU	1	; SSPSTAT
BF				EQU	0	; SSPSTAT
; =====================================
CSRC			EQU	7	; TXSTA
TX9				EQU	6	; TXSTA
TXEN			EQU	5	; TXSTA
SYNC			EQU	4	; TXSTA
BRGH			EQU	2	; TXSTA
TRMT			EQU	1	; TXSTA
TX9D			EQU	0	; TXSTA
; =====================================
PCFG2			EQU	2	; ADCON1
PCFG1			EQU	1	; ADCON1
PCFG0			EQU	0	; ADCON1
; =====================================
RD				EQU	0	; PMCON1

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	02007h
RC				EQU	03FFFh
HS				EQU	03FFEh
XT				EQU	03FFDh
LP				EQU	03FFCh
WDTEN			EQU	03FFFh
WDTDIS			EQU	03FFBh
PWRTEN			EQU	03FF7h
PWRTDIS			EQU	03FFFh
BOREN			EQU	03FFFh
BORDIS			EQU	03FBFh
UNPROTECT		EQU	03FFFh
PROTECT			EQU	03FEFh
