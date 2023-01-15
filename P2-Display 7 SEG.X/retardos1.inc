PSECT udata_acs
 
contador1: DS 1	    ;reserva 1 byte en acces ram
contador2: DS 1	    ;reserva 1 byte en acces ram
contador3: DS 1	    
;250ms
    
PSECT code
Delay_250ms:				    ;2tcy
     MOVLW 250				    ;1tcy
     MOVWF contador2,0			    ;1tcy
	 Loop_1ms7:			     
	     MOVLW   249		    ;k Tcy
	     MOVWF   contador1,0	    ;k tcy
	     INT_LOOP7:			    
		 Nop			    ;249k TCY
		 DECFSZ  contador1,1,0	    ;251k TCY 
		 Goto    INT_LOOP7	    ;496k TCY
     DECFSZ  contador2,1,0		    ;(k-1)+3tcy
     GOTO    Loop_1ms7			    ;(k-1)*2tcy
     RETURN			            ;2 TCY
;500ms
Delay_500ms:
    MOVLW 2
    MOVWF contador3,0
    Loop_250ms:				    ;2tcy
	MOVLW 250				    ;1tcy
	MOVWF contador2,0			    ;1tcy
	    Loop_1ms8:			     
		 MOVLW   249		    ;k Tcy
		 MOVWF   contador1,0	    ;k tcy
		INT_LOOP8:			    
		     Nop			    ;249k TCY
		     DECFSZ  contador1,1,0	    ;251k TCY 
		     Goto    INT_LOOP8	    ;496k TCY
	DECFSZ  contador2,1,0		    ;(k-1)+3tcy
	GOTO    Loop_1ms8			    ;(k-1)*2tcy
    DECFSZ  contador3,1,0
    GOTO Loop_250ms
    RETURN			            ;2 TCY
 ;1s
 Delay_1s:
    MOVLW 4
    MOVWF contador3,0
    Loop_250ms1:				    ;2tcy
	MOVLW 250				    ;1tcy
	MOVWF contador2,0			    ;1tcy
	    Loop_1ms9:			     
		 MOVLW   249		    ;k Tcy
		 MOVWF   contador1,0	    ;k tcy
		INT_LOOP9:			    
		     Nop			    ;249k TCY
		     DECFSZ  contador1,1,0	    ;251k TCY 
		     Goto    INT_LOOP9	    ;496k TCY
	DECFSZ  contador2,1,0		    ;(k-1)+3tcy
	GOTO    Loop_1ms9			    ;(k-1)*2tcy
    DECFSZ  contador3,1,0
    GOTO Loop_250ms1
    RETURN			            ;2 TCY


