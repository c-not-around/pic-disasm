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
GPIO			EQU	(005h & 07Fh)	; BANK0
PCLATH			EQU	(00Ah & 07Fh)	; BANK0
INTCON			EQU	(00Bh & 07Fh)	; BANK0
PIR1			EQU	(00Ch & 07Fh)	; BANK0
TMR1L			EQU	(00Eh & 07Fh)	; BANK0
TMR1H			EQU	(00Fh & 07Fh)	; BANK0
T1CON			EQU	(010h & 07Fh)	; BANK0
CMCON			EQU	(019h & 07Fh)	; BANK0
ADRESH			EQU	(01Eh & 07Fh)	; BANK0
ADCON0			EQU	(01Fh & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(081h & 07Fh)	; BANK1
TRISIO			EQU	(085h & 07Fh)	; BANK1
PIE1			EQU	(08Ch & 07Fh)	; BANK1
PCON			EQU	(08Eh & 07Fh)	; BANK1
OSCCAL			EQU	(090h & 07Fh)	; BANK1
WPU				EQU	(095h & 07Fh)	; BANK1
IOCB			EQU	(096h & 07Fh)	; BANK1
IOC				EQU	(096h & 07Fh)	; BANK1
VRCON			EQU	(099h & 07Fh)	; BANK1
EEDATA			EQU	(09Ah & 07Fh)	; BANK1
EEADR			EQU	(09Bh & 07Fh)	; BANK1
EECON1			EQU	(09Ch & 07Fh)	; BANK1
EECON2			EQU	(09Dh & 07Fh)	; BANK1
ADRESL			EQU	(09Eh & 07Fh)	; BANK1
ANSEL			EQU	(09Fh & 07Fh)	; BANK1

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
PD				EQU	3	; STATUS
TO				EQU	4	; STATUS
RP0				EQU	5	; STATUS
; =====================================
GPIO0			EQU	0	; GPIO
GPIO1			EQU	1	; GPIO
GPIO2			EQU	2	; GPIO
GPIO3			EQU	3	; GPIO
GPIO4			EQU	4	; GPIO
GPIO5			EQU	5	; GPIO
; =====================================
GPIF			EQU	0	; INTCON
INTF			EQU	1	; INTCON
T0IF			EQU	2	; INTCON
GPIE			EQU	3	; INTCON
INTE			EQU	4	; INTCON
T0IE			EQU	5	; INTCON
PEIE			EQU	6	; INTCON
GIE				EQU	7	; INTCON
; =====================================
TMR1IF			EQU	0	; PIR1
CMIF			EQU	3	; PIR1
ADIF			EQU	6	; PIR1
EEIF			EQU	7	; PIR1
; =====================================
TMR1ON			EQU	0	; T1CON
TMR1CS			EQU	1	; T1CON
T1SYNC			EQU	2	; T1CON
T1OSCEN			EQU	3	; T1CON
T1CKPS0			EQU	4	; T1CON
T1CKPS1			EQU	5	; T1CON
TMR1GE			EQU	6	; T1CON
; =====================================
CM0				EQU	0	; CMCON
CM1				EQU	1	; CMCON
CM2				EQU	2	; CMCON
CIS				EQU	3	; CMCON
CINV			EQU	4	; CMCON
COUT			EQU	6	; CMCON
; =====================================
ADON			EQU	0	; ADCON0
GODONE			EQU	1	; ADCON0
CHS0			EQU	2	; ADCON0
CHS1			EQU	3	; ADCON0
VCFG			EQU	6	; ADCON0
ADFM			EQU	7	; ADCON0
; =====================================
PS0				EQU	0	; OPTION_REG
PS1				EQU	1	; OPTION_REG
PS2				EQU	2	; OPTION_REG
PSA				EQU	3	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
INTEDG			EQU	6	; OPTION_REG
GPPU			EQU	7	; OPTION_REG
; =====================================
TRIS0			EQU	0	; TRISIO
TRIS1			EQU	1	; TRISIO
TRIS2			EQU	2	; TRISIO
TRIS3			EQU	3	; TRISIO
TRIS4			EQU	4	; TRISIO
TRIS5			EQU	5	; TRISIO
; =====================================
TMR1IE			EQU	0	; PIE1
CMIE			EQU	3	; PIE1
ADIE			EQU	6	; PIE1
EEIE			EQU	7	; PIE1
; =====================================
BOD				EQU	0	; PCON
POR				EQU	1	; PCON
; =====================================
CAL0			EQU	2	; OSCCAL
CAL1			EQU	3	; OSCCAL
CAL2			EQU	4	; OSCCAL
CAL3			EQU	5	; OSCCAL
CAL4			EQU	6	; OSCCAL
CAL5			EQU	7	; OSCCAL
; =====================================
WPU0			EQU	0	; WPU
WPU1			EQU	1	; WPU
WPU2			EQU	2	; WPU
WPU4			EQU	4	; WPU
WPU5			EQU	5	; WPU
; =====================================
IOCB0			EQU	0	; IOCB
IOCB1			EQU	1	; IOCB
IOCB2			EQU	2	; IOCB
IOCB3			EQU	3	; IOCB
IOCB4			EQU	4	; IOCB
IOCB5			EQU	5	; IOCB
IOC0			EQU	0	; IOCB
IOC1			EQU	1	; IOCB
IOC2			EQU	2	; IOCB
IOC3			EQU	3	; IOCB
IOC4			EQU	4	; IOCB
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
ANS0			EQU	0	; ANSEL
ANS1			EQU	1	; ANSEL
ANS2			EQU	2	; ANSEL
ANS3			EQU	3	; ANSEL
ADCS0			EQU	4	; ANSEL
ADCS1			EQU	5	; ANSEL
ADCS2			EQU	6	; ANSEL

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG_ADDR		EQU	02007h
CPD				EQU	03EFFh
UNPROTECT		EQU	03FFFh
PROTECT			EQU	03F7Fh
UNPROTECT		EQU	03FFFh
BOREN			EQU	03FFFh
BORDIS			EQU	03FBFh
MCLREN			EQU	03FFFh
MCLRDIS			EQU	03FDFh
PWRTDIS			EQU	03FFFh
PWRTEN			EQU	03FEFh
WDTEN			EQU	03FFFh
WDTDIS			EQU	03FF7h
RCCLK			EQU	03FFFh
RCIO			EQU	03FFEh
INTCLK			EQU	03FFDh
INTIO			EQU	03FFCh
EC				EQU	03FFBh
HS				EQU	03FFAh
XT				EQU	03FF9h
LP				EQU	03FF8h
