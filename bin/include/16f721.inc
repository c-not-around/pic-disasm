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
PORTA			EQU	(0005h & 07Fh)	; BANK0
PORTB			EQU	(0006h & 07Fh)	; BANK0
PORTC			EQU	(0007h & 07Fh)	; BANK0
PCLATH			EQU	(000Ah & 07Fh)	; BANK0
INTCON			EQU	(000Bh & 07Fh)	; BANK0
PIR1			EQU	(000Ch & 07Fh)	; BANK0
TMR1L			EQU	(000Eh & 07Fh)	; BANK0
TMR1H			EQU	(000Fh & 07Fh)	; BANK0
T1CON			EQU	(0010h & 07Fh)	; BANK0
TMR2			EQU	(0011h & 07Fh)	; BANK0
T2CON			EQU	(0012h & 07Fh)	; BANK0
SSPBUF			EQU	(0013h & 07Fh)	; BANK0
SSPCON			EQU	(0014h & 07Fh)	; BANK0
CCPR1L			EQU	(0015h & 07Fh)	; BANK0
CCPR1H			EQU	(0016h & 07Fh)	; BANK0
CCP1CON			EQU	(0017h & 07Fh)	; BANK0
RCSTA			EQU	(0018h & 07Fh)	; BANK0
TXREG			EQU	(0019h & 07Fh)	; BANK0
RCREG			EQU	(001Ah & 07Fh)	; BANK0
ADRES			EQU	(001Eh & 07Fh)	; BANK0
ADCON0			EQU	(001Fh & 07Fh)	; BANK0
; =====================================
OPTION_REG		EQU	(0081h & 07Fh)	; BANK1
TRISA			EQU	(0085h & 07Fh)	; BANK1
TRISB			EQU	(0086h & 07Fh)	; BANK1
TRISC			EQU	(0087h & 07Fh)	; BANK1
PIE1			EQU	(008Ch & 07Fh)	; BANK1
PCON			EQU	(008Eh & 07Fh)	; BANK1
T1GCON			EQU	(008Fh & 07Fh)	; BANK1
OSCCON			EQU	(0090h & 07Fh)	; BANK1
OSCTUNE			EQU	(0091h & 07Fh)	; BANK1
PR2				EQU	(0092h & 07Fh)	; BANK1
SSPADD			EQU	(0093h & 07Fh)	; BANK1
SSPMSK			EQU	(0093h & 07Fh)	; BANK1
SSPSTAT			EQU	(0094h & 07Fh)	; BANK1
WPUA			EQU	(0095h & 07Fh)	; BANK1
IOCA			EQU	(0096h & 07Fh)	; BANK1
TXSTA			EQU	(0098h & 07Fh)	; BANK1
SPBRG			EQU	(0099h & 07Fh)	; BANK1
FVRCON			EQU	(009Dh & 07Fh)	; BANK1
ADCON1			EQU	(009Fh & 07Fh)	; BANK1
; =====================================
PMDATL			EQU	(010Ch & 07Fh)	; BANK2
PMADRL			EQU	(010Dh & 07Fh)	; BANK2
PMDATH			EQU	(010Eh & 07Fh)	; BANK2
PMADRH			EQU	(010Fh & 07Fh)	; BANK2
WPUB			EQU	(0115h & 07Fh)	; BANK2
IOCB			EQU	(0116h & 07Fh)	; BANK2
; =====================================
ANSELA			EQU	(0185h & 07Fh)	; BANK3
ANSELB			EQU	(0186h & 07Fh)	; BANK3
ANSELC			EQU	(0187h & 07Fh)	; BANK3
ICDIO			EQU	(0189h & 07Fh)	; BANK3
PMCON1			EQU	(018Ch & 07Fh)	; BANK3
PMCON2			EQU	(018Dh & 07Fh)	; BANK3
ICKBUG			EQU	(018Eh & 07Fh)	; BANK3
BIGBUG			EQU	(018Fh & 07Fh)	; BANK3

; =====================================
;		SFR's Bits Definitions
; =====================================
CARRY			EQU	0	; STATUS
DC				EQU	1	; STATUS
ZERO			EQU	2	; STATUS
nPD				EQU	3	; STATUS
nTO				EQU	4	; STATUS
IRP				EQU	7	; STATUS
; =====================================
RA0				EQU	0	; PORTA
RA1				EQU	1	; PORTA
RA2				EQU	2	; PORTA
RA3				EQU	3	; PORTA
RA4				EQU	4	; PORTA
RA5				EQU	5	; PORTA
; =====================================
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
RABIF			EQU	0	; INTCON
INTF			EQU	1	; INTCON
TMR0IF			EQU	2	; INTCON
RABIE			EQU	3	; INTCON
INTE			EQU	4	; INTCON
TMR0IE			EQU	5	; INTCON
PEIE			EQU	6	; INTCON
GIE				EQU	7	; INTCON
; =====================================
TXIF			EQU	4	; PIR1
RCIF			EQU	5	; PIR1
TMR1GIF			EQU	7	; PIR1
PSPIF			EQU	7	; PIR1
; =====================================
TMR1ON			EQU	0	; T1CON
T1SYNC			EQU	2	; T1CON
; =====================================
TMR2ON			EQU	2	; T2CON
; =====================================
CKP				EQU	4	; SSPCON
SSPEN			EQU	5	; SSPCON
SSPOV			EQU	6	; SSPCON
WCOL			EQU	7	; SSPCON
; =====================================
RX9D			EQU	0	; RCSTA
OERR			EQU	1	; RCSTA
FERR			EQU	2	; RCSTA
ADDEN			EQU	3	; RCSTA
CREN			EQU	4	; RCSTA
SREN			EQU	5	; RCSTA
RX9				EQU	6	; RCSTA
SPEN			EQU	7	; RCSTA
; =====================================
PSA				EQU	3	; OPTION_REG
T0SE			EQU	4	; OPTION_REG
T0CS			EQU	5	; OPTION_REG
INTEDG			EQU	6	; OPTION_REG
nRABPU			EQU	7	; OPTION_REG
; =====================================
TRISA0			EQU	0	; TRISA
TRISA1			EQU	1	; TRISA
TRISA2			EQU	2	; TRISA
TRISA4			EQU	4	; TRISA
TRISA5			EQU	5	; TRISA
; =====================================
TRISB4			EQU	4	; TRISB
TRISB5			EQU	5	; TRISB
TRISB6			EQU	6	; TRISB
TRISB7			EQU	7	; TRISB
; =====================================
TRISC0			EQU	0	; TRISC
TRISC1			EQU	1	; TRISC
TRISC2			EQU	2	; TRISC
TRISC3			EQU	3	; TRISC
TRISC4			EQU	4	; TRISC
TRISC5			EQU	5	; TRISC
TRISC6			EQU	6	; TRISC
TRISC7			EQU	7	; TRISC
; =====================================
TMR1IE			EQU	0	; PIE1
TMR2IE			EQU	1	; PIE1
CCP1IE			EQU	2	; PIE1
SSPIE			EQU	3	; PIE1
TXIE			EQU	4	; PIE1
RCIE			EQU	5	; PIE1
ADIE			EQU	6	; PIE1
TMR1GIE			EQU	7	; PIE1
; =====================================
nBOR			EQU	0	; PCON
nPOR			EQU	1	; PCON
; =====================================
T1GVAL			EQU	2	; T1GCON
T1GGO_DONE		EQU	3	; T1GCON
T1GSPM			EQU	4	; T1GCON
T1GTM			EQU	5	; T1GCON
T1GPOL			EQU	6	; T1GCON
TMR1GE			EQU	7	; T1GCON
; =====================================
ICSS			EQU	2	; OSCCON
ICSL			EQU	3	; OSCCON
; =====================================
MSK0			EQU	0	; SSPMSK
MSK1			EQU	1	; SSPMSK
MSK2			EQU	2	; SSPMSK
MSK3			EQU	3	; SSPMSK
MSK4			EQU	4	; SSPMSK
MSK5			EQU	5	; SSPMSK
MSK6			EQU	6	; SSPMSK
MSK7			EQU	7	; SSPMSK
; =====================================
WPUA0			EQU	0	; WPUA
WPUA1			EQU	1	; WPUA
WPUA2			EQU	2	; WPUA
WPUA3			EQU	3	; WPUA
WPUA4			EQU	4	; WPUA
WPUA5			EQU	5	; WPUA
; =====================================
IOCA0			EQU	0	; IOCA
IOCA1			EQU	1	; IOCA
IOCA2			EQU	2	; IOCA
IOCA3			EQU	3	; IOCA
IOCA4			EQU	4	; IOCA
IOCA5			EQU	5	; IOCA
; =====================================
TX9D			EQU	0	; TXSTA
TRMT			EQU	1	; TXSTA
BRGH			EQU	2	; TXSTA
SYNC			EQU	4	; TXSTA
TXEN			EQU	5	; TXSTA
TX9				EQU	6	; TXSTA
CSRC			EQU	7	; TXSTA
; =====================================
ADFVR0			EQU	0	; FVRCON
ADFVR1			EQU	1	; FVRCON
TSRNG			EQU	4	; FVRCON
TSEN			EQU	5	; FVRCON
FVREN			EQU	6	; FVRCON
FVRST			EQU	7	; FVRCON
; =====================================
ADCS0			EQU	4	; ADCON1
ADCS1			EQU	5	; ADCON1
ADCS2			EQU	6	; ADCON1
ADFM			EQU	7	; ADCON1
; =====================================
ANSA0			EQU	0	; ANSELA
ANSA1			EQU	1	; ANSELA
ANSA2			EQU	2	; ANSELA
ANSA4			EQU	4	; ANSELA
ANSA5			EQU	5	; ANSELA
; =====================================
ANSB4			EQU	4	; ANSELB
ANSB5			EQU	5	; ANSELB
; =====================================
ANSC0			EQU	0	; ANSELC
ANSC1			EQU	1	; ANSELC
ANSC2			EQU	2	; ANSELC
ANSC3			EQU	3	; ANSELC
ANSC6			EQU	6	; ANSELC
ANSC7			EQU	7	; ANSELC
; =====================================
RD				EQU	0	; PMCON1
WR				EQU	1	; PMCON1
WREN			EQU	2	; PMCON1
WRERR			EQU	3	; PMCON1
FREE			EQU	4	; PMCON1
LWLO			EQU	5	; PMCON1
CFGS			EQU	6	; PMCON1
EEPGD			EQU	7	; PMCON1

; =====================================
;		Configuration Definitions
; =====================================
; =====================================
CONFIG			EQU	02007h
FOSC_EC_OSC_CLKOUT	EQU	0FFFFh
FOSC_EC_OSC_NOCLKOUT	EQU	0FFFEh
FOSC_INTOSC_CLKOUT	EQU	0FFFDh
FOSC_INTOSC_NOCLKOUT	EQU	0FFFCh
WDTEN_ON		EQU	0FFFFh
WDTEN_OFF		EQU	0FFF7h
PWRTE_OFF		EQU	0FFFFh
PWRTE_ON		EQU	0FFEFh
MCLRE_OFF		EQU	0FFDFh
MCLRE_ON		EQU	0FFFFh
CP_OFF			EQU	0FFFFh
CP_ON			EQU	0FFBFh
BOREN_OFF		EQU	0FCFFh
BOREN_NSLEEP	EQU	0FEFFh
BOREN_ON		EQU	0FFFFh
PLLEN_ON		EQU	0FFFFh
PLLEN_OFF		EQU	0EFFFh
DEBUG_OFF		EQU	0FFFFh
DEBUG_ON		EQU	0DFFFh
; =====================================
CONFIG2			EQU	02009h
WRTEN_OFF		EQU	0FFFFh
WRTEN_BOOT		EQU	0FFFEh
WRTEN_HALF		EQU	0FFFDh
WRTEN_FULL		EQU	0FFFCh
VCAPEN_OFF		EQU	0FFFFh
