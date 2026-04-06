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
PORTC			EQU	(007h & 07Fh)	; BANK0
GPIO			EQU	(005h & 07Fh)	; BANK0
PCLATH			EQU	(00Ah & 07Fh)	; BANK0
INTCON			EQU	(00Bh & 07Fh)	; BANK0
PIR1			EQU	(00Ch & 07Fh)	; BANK0
TMR1L			EQU	(00Eh & 07Fh)	; BANK0
TMR1H			EQU	(00Fh & 07Fh)	; BANK0
T1CON			EQU	(010h & 07Fh)	; BANK0
WDTCON			EQU	(018h & 07Fh)	; BANK0
CMCON0			EQU	(019h & 07Fh)	; BANK0
CMCON1			EQU	(01Ah & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(081h & 07Fh)	; BANK1
TRISA			EQU	(085h & 07Fh)	; BANK1
TRISC			EQU	(087h & 07Fh)	; BANK1
TRISIO			EQU	(085h & 07Fh)	; BANK1
PIE1			EQU	(08Ch & 07Fh)	; BANK1
PCON			EQU	(08Eh & 07Fh)	; BANK1
OSCCON			EQU	(08Fh & 07Fh)	; BANK1
OSCTUNE			EQU	(090h & 07Fh)	; BANK1
LVDCON			EQU	(094h & 07Fh)	; BANK1
WPUDA			EQU	(095h & 07Fh)	; BANK1
IOCA			EQU	(096h & 07Fh)	; BANK1
WDA				EQU	(097h & 07Fh)	; BANK1
VRCON			EQU	(099h & 07Fh)	; BANK1
EEDAT			EQU	(09Ah & 07Fh)	; BANK1
EEDATA			EQU	(09Ah & 07Fh)	; BANK1
EEADR			EQU	(09Bh & 07Fh)	; BANK1
EEADRL			EQU	(09Bh & 07Fh)	; BANK1
EECON1			EQU	(09Ch & 07Fh)	; BANK1
EECON2			EQU	(09Dh & 07Fh)	; BANK1
; =====================================
CRCON			EQU	(0110h & 07Fh)	; BANK2
CRDAT0			EQU	(0111h & 07Fh)	; BANK2
CRDAT1			EQU	(0112h & 07Fh)	; BANK2
CRDAT2			EQU	(0113h & 07Fh)	; BANK2
CRDAT3			EQU	(0114h & 07Fh)	; BANK2

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
; =====================================
RC0				EQU	0	; PORTC
RC1				EQU	1	; PORTC
RC2				EQU	2	; PORTC
RC3				EQU	3	; PORTC
RC4				EQU	4	; PORTC
RC5				EQU	5	; PORTC
; =====================================
GP0				EQU	0	; GPIO
GP1				EQU	1	; GPIO
GP2				EQU	2	; GPIO
GP3				EQU	3	; GPIO
GP4				EQU	4	; GPIO
GP5				EQU	5	; GPIO
; =====================================
RAIF			EQU	0	; INTCON
INTF			EQU	1	; INTCON
T0IF			EQU	2	; INTCON
RAIE			EQU	3	; INTCON
INTE			EQU	4	; INTCON
T0IE			EQU	5	; INTCON
PEIE			EQU	6	; INTCON
GIE				EQU	7	; INTCON
; =====================================
TMR1IF			EQU	0	; PIR1
OSFIF			EQU	2	; PIR1
C1IF			EQU	3	; PIR1
C2IF			EQU	4	; PIR1
CRIF			EQU	5	; PIR1
LVDIF			EQU	6	; PIR1
EEIF			EQU	7	; PIR1
; =====================================
TMR1ON			EQU	0	; T1CON
TMR1CS			EQU	1	; T1CON
T1SYNC			EQU	2	; T1CON
T1OSCEN			EQU	3	; T1CON
T1CKPS0			EQU	4	; T1CON
T1CKPS1			EQU	5	; T1CON
TMR1GE			EQU	6	; T1CON
T1GINV			EQU	7	; T1CON
; =====================================
SWDTEN			EQU	0	; WDTCON
WDTPS0			EQU	1	; WDTCON
WDTPS1			EQU	2	; WDTCON
WDTPS2			EQU	3	; WDTCON
WDTPS3			EQU	4	; WDTCON
; =====================================
CM0				EQU	0	; CMCON0
CM1				EQU	1	; CMCON0
CM2				EQU	2	; CMCON0
CIS				EQU	3	; CMCON0
C1INV			EQU	4	; CMCON0
C2INV			EQU	5	; CMCON0
C1OUT			EQU	6	; CMCON0
C2OUT			EQU	7	; CMCON0
; =====================================
C2SYNC			EQU	0	; CMCON1
T1GSS			EQU	1	; CMCON1
; =====================================
PS0				EQU	0	; OPTION_REG
PS1				EQU	1	; OPTION_REG
PS2				EQU	2	; OPTION_REG
PSA				EQU	3	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
INTEDG			EQU	6	; OPTION_REG
RAPU			EQU	7	; OPTION_REG
; =====================================
TRISA0			EQU	0	; TRISA
TRISA1			EQU	1	; TRISA
TRISA2			EQU	2	; TRISA
TRISA3			EQU	3	; TRISA
TRISA4			EQU	4	; TRISA
TRISA5			EQU	5	; TRISA
; =====================================
TRISC0			EQU	0	; TRISC
TRISC1			EQU	1	; TRISC
TRISC2			EQU	2	; TRISC
TRISC3			EQU	3	; TRISC
TRISC4			EQU	4	; TRISC
TRISC5			EQU	5	; TRISC
; =====================================
TRISIO0			EQU	0	; TRISIO
TRISIO1			EQU	1	; TRISIO
TRISIO2			EQU	2	; TRISIO
TRISIO3			EQU	3	; TRISIO
TRISIO4			EQU	4	; TRISIO
TRISIO5			EQU	5	; TRISIO
; =====================================
TMR1IE			EQU	0	; PIE1
OSFIE			EQU	2	; PIE1
C1IE			EQU	3	; PIE1
C2IE			EQU	4	; PIE1
CRIE			EQU	5	; PIE1
LVDIE			EQU	6	; PIE1
EEIE			EQU	7	; PIE1
; =====================================
BOD				EQU	0	; PCON
POR				EQU	1	; PCON
WUR				EQU	3	; PCON
SBODEN			EQU	4	; PCON
ULPWUE			EQU	5	; PCON
; =====================================
SCS				EQU	0	; OSCCON
LTS				EQU	1	; OSCCON
HTS				EQU	2	; OSCCON
OSTS			EQU	3	; OSCCON
IRCF0			EQU	4	; OSCCON
IRCF1			EQU	5	; OSCCON
IRCF2			EQU	6	; OSCCON
; =====================================
TUN0			EQU	0	; OSCTUNE
TUN1			EQU	1	; OSCTUNE
TUN2			EQU	2	; OSCTUNE
TUN3			EQU	3	; OSCTUNE
TUN4			EQU	4	; OSCTUNE
; =====================================
LVDL0			EQU	0	; LVDCON
LVDL1			EQU	1	; LVDCON
LVDL2			EQU	2	; LVDCON
LVDEN			EQU	4	; LVDCON
IRVST			EQU	5	; LVDCON
; =====================================
WPUDA0			EQU	0	; WPUDA
WPUDA1			EQU	1	; WPUDA
WPUDA2			EQU	2	; WPUDA
WPUDA4			EQU	4	; WPUDA
WPUDA5			EQU	5	; WPUDA
; =====================================
IOCA0			EQU	0	; IOCA
IOCA1			EQU	1	; IOCA
IOCA2			EQU	2	; IOCA
IOCA3			EQU	3	; IOCA
IOCA4			EQU	4	; IOCA
IOCA5			EQU	5	; IOCA
; =====================================
WDA0			EQU	0	; WDA
WDA1			EQU	1	; WDA
WDA2			EQU	2	; WDA
WDA4			EQU	4	; WDA
WDA5			EQU	5	; WDA
; =====================================
VR0				EQU	0	; VRCON
VR1				EQU	1	; VRCON
VR2				EQU	2	; VRCON
VR3				EQU	3	; VRCON
VRR				EQU	5	; VRCON
VREN			EQU	7	; VRCON
; =====================================
RD				EQU	0	; EECON1
WR				EQU	1	; EECON1
WREN			EQU	2	; EECON1
WRERR			EQU	3	; EECON1
; =====================================
CRREG0			EQU	0	; CRCON
CRREG1			EQU	1	; CRCON
ENCDEC			EQU	6	; CRCON
GODONE			EQU	7	; CRCON

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	02007h
EXTCLK			EQU	03FFFh
EXTIO			EQU	03FFEh
INTCLK			EQU	03FFDh
INTIO			EQU	03FFCh
EC				EQU	03FFBh
HS				EQU	03FFAh
XT				EQU	03FF9h
LP				EQU	03FF8h
WDTEN			EQU	03FFFh
WDTDIS			EQU	03FF7h
PWRTDIS			EQU	03FFFh
PWRTEN			EQU	03FEFh
MCLREN			EQU	03FFFh
MCLRDIS			EQU	03FDFh
UNPROTECT		EQU	03FFFh
CP				EQU	03FBFh
UNPROTECT		EQU	03FFFh
CPD				EQU	03F7Fh
BORDIS			EQU	03CFFh
SBOREN			EQU	03DFFh
BORXSLP			EQU	03EFFh
BOREN			EQU	03FFFh
IESOEN			EQU	03FFFh
IESODIS			EQU	03BFFh
FCMEN			EQU	03FFFh
FCMDIS			EQU	037FFh
WAKECNT			EQU	03FFFh
WAKERST			EQU	02FFFh
