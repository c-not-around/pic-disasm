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
RCSTA			EQU	(018h & 07Fh)	; BANK0
TXREG			EQU	(019h & 07Fh)	; BANK0
RCREG			EQU	(01Ah & 07Fh)	; BANK0
CMCON			EQU	(01Fh & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(081h & 07Fh)	; BANK1
TRISA			EQU	(085h & 07Fh)	; BANK1
TRISB			EQU	(086h & 07Fh)	; BANK1
PIE1			EQU	(08Ch & 07Fh)	; BANK1
PCON			EQU	(08Eh & 07Fh)	; BANK1
PR2				EQU	(092h & 07Fh)	; BANK1
TXSTA			EQU	(098h & 07Fh)	; BANK1
SPBRG			EQU	(099h & 07Fh)	; BANK1
EEDATA			EQU	(09Ah & 07Fh)	; BANK1
EEADR			EQU	(09Bh & 07Fh)	; BANK1
EECON1			EQU	(09Ch & 07Fh)	; BANK1
EECON2			EQU	(09Dh & 07Fh)	; BANK1
VRCON			EQU	(09Fh & 07Fh)	; BANK1

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
RA5				EQU	5	; PORTA
RA6				EQU	6	; PORTA
RA7				EQU	7	; PORTA
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
TXIF			EQU	4	; PIR1
RCIF			EQU	5	; PIR1
CMIF			EQU	6	; PIR1
EEIF			EQU	7	; PIR1
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
CCP1Y			EQU	4	; CCP1CON
CCP1X			EQU	5	; CCP1CON
; =====================================
RX9D			EQU	0	; RCSTA
OERR			EQU	1	; RCSTA
FERR			EQU	2	; RCSTA
ADEN			EQU	3	; RCSTA
CREN			EQU	4	; RCSTA
SREN			EQU	5	; RCSTA
RX9				EQU	6	; RCSTA
SPEN			EQU	7	; RCSTA
; =====================================
CM0				EQU	0	; CMCON
CM1				EQU	1	; CMCON
CM2				EQU	2	; CMCON
CIS				EQU	3	; CMCON
C1INV			EQU	4	; CMCON
C2INV			EQU	5	; CMCON
C1OUT			EQU	6	; CMCON
C2OUT			EQU	7	; CMCON
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
TRISA5			EQU	5	; TRISA
TRISA6			EQU	6	; TRISA
TRISA7			EQU	7	; TRISA
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
TXIE			EQU	4	; PIE1
RCIE			EQU	5	; PIE1
CMIE			EQU	6	; PIE1
EEIE			EQU	7	; PIE1
; =====================================
BOR				EQU	0	; PCON
POR				EQU	1	; PCON
OSCF			EQU	3	; PCON
; =====================================
TX9D			EQU	0	; TXSTA
TRMT			EQU	1	; TXSTA
BRGH			EQU	2	; TXSTA
SYNC			EQU	4	; TXSTA
TXEN			EQU	5	; TXSTA
TX9				EQU	6	; TXSTA
CSRC			EQU	7	; TXSTA
; =====================================
RD				EQU	0	; EECON1
WR				EQU	1	; EECON1
WREN			EQU	2	; EECON1
WRERR			EQU	3	; EECON1
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
CONFIG_ADDR		EQU	02007h
; =====================================
CONFIG_ADDR		EQU	02007h
PROTECT			EQU	01FFFh
UNPROTECT		EQU	03FFFh
CPD				EQU	03EFFh
UNPROTECT		EQU	03FFFh
LVPEN			EQU	03FFFh
LVPDIS			EQU	03F7Fh
BOREN			EQU	03FFFh
BORDIS			EQU	03FBFh
MCLREN			EQU	03FFFh
MCLRDIS			EQU	03FDFh
PWRTEN			EQU	03FF7h
PWRTDIS			EQU	03FFFh
WDTEN			EQU	03FFFh
WDTDIS			EQU	03FFBh
RCCLK			EQU	03FFFh
RCIO			EQU	03FFEh
INTCLK			EQU	03FFDh
INTIO			EQU	03FFCh
EC				EQU	03FEFh
HS				EQU	03FEEh
XT				EQU	03FEDh
LP				EQU	03FECh
