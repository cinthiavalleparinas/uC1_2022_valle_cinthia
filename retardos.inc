;--------------------------------------------------------------
; @file:		retardos.inc
; @brief:		Esta librería contiene códigos de ciertos retardos para una implementación.
;			Nota: Tener en cuenta que La frecuencia del oscilador usado en esta librería es de 4 MHZ,
;			      por lo tanto, un TCY=1us
; @date:		09/01/2023
; @author:		Valle Pariñas Cinthia Paola 
; @Version and program:	MPLAB X IDE v6.00
;------------------------------------------------------------------
    
PSECT udata_acs
Contador1: DS 1		    ;reserva 1 byte acces ram
Contador2: DS 1    
    
PSECT code
 
; 10us --> (6+4k)
Delay_10us:		    ;2 Tcy
    MOVLW 1		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
Ext_Loop10us:
    NOP			    ;k*Tcy
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop10us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy
;  
;25 us --> (3k+7)
Delay_25us:		    ;2 Tcy
    MOVLW 6		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
    NOP			    ;1 Tcy
Ext_Loop25us: 
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop25us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy
; 
;50 us --> (6k+4)
Delay_50us:		    ;2 Tcy
    MOVLW 11		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
Ext_Loop50us:
    NOP			    ;k*Tcy
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop10us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy  
; 
;100 us --> (3k+7)
Delay_100us:		    ;2 Tcy
    MOVLW 31		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
    NOP			    ;1 Tcy
Ext_Loop100us: 
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop25us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy   
; 
;200 us --> (4k+8)
Delay_200us:		    ;2 Tcy
    MOVLW 48		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
    NOP			    ;1 Tcy
    NOP			    ;1 Tcy
Ext_Loop200us: 
    NOP			    ;k*Tcy
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop25us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy  
; 
;250 us --> (3k+7)
Delay_250us:		    ;2 Tcy
    MOVLW 81		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
    NOP			    ;1 Tcy
Ext_Loop250us: 
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop25us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy     
; 
;500 us --> (4k+8)
Delay_500us:		    ;2 Tcy
    MOVLW 123		    ;1 Tcy
    MOVWF Contador1,1,0	    ;1 Tcy
    NOP			    ;1 Tcy
    NOP			    ;1 Tcy
Ext_Loop500us: 
    NOP			    ;k*Tcy
    DECFSZ Contador1,1,0    ;(k-1)+3Tcy
    GOTO Ext_Loop25us	    ;(k-1)*2Tcy
    RETURN		    ; 2 Tcy  
;       
Delay_1ms:		    ;2 Tcy
    MOVLW   1		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy

Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_5ms:		    ;2 Tcy
    MOVLW   5		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy
   
Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_10ms:		    ;2 Tcy
    MOVLW   10		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy
 
Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_25ms:		    ;2 Tcy
    MOVLW   25		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy
   ;
Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_50ms:		    ;2 Tcy
    MOVLW   50		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy

Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_100ms:		    ;2 Tcy
    MOVLW   100		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy

Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_200ms:		    ;2 Tcy
    MOVLW   200		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy

Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy
; 
Delay_250ms:		    ;2 Tcy
    MOVLW   250		    ;1 Tcy -- k2
    MOVWF   Contador2,0	    ;1Tcy

Ext_Loop:
    MOVLW   249		    ;1 Tcy --k1
    MOVWF   Contador1,0	    ;1 Tcy
Int_Loop:
    NOP			    ;k1*Tcy
    DECFSZ Contador1,1,0    ;(k1-1)+3Tcy
    GOTO Int_Loop	    ;(k1-1)*2Tcy
    DECFSZ  Contador2,1,0
    GOTO  Ext_Loop
    RETURN		   ;2Tcy