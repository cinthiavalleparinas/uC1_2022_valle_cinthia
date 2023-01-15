;nombre: P2 display 7 seg 
;fecha: 15/01/22, 
;descripcion: programa que permita mostrar los valores alfanuméricos(0-9 y A-F) en un display de 7 segmentos ánodo común, conectados al puerto D. 
;autor: Valle Pariñas Cinthia Paola 
PROCESSOR 18F57Q84
    
#include "CONFBITS.inc" ;/onfig statements should precede project file includes./
#include "retardos1.inc"
#include <xc.inc>

PSECT resetVect,class=CODE, reloc=2
resetVect:
    goto Main
PSECT CODE
Main:
    CALL    Config_OSC
    CALL    Config_Port
    
Condition_button:
    BTFSC PORTA,3,1; salta si el bit 3 del registro PORTA es cero, a letras 
    GOTO Numeros
    Letras:
	Letra_A:
	  CLRF	PORTD,0 ; pone a todos los bits del registro PORTD en 0 
	  BSF	PORTD,3,0; pone solo el bit 3 en 1 para el A 
	  CALL	Delay_1s; para el retardo de 1s 
	  BTFSC	PORTA,3,0; salta si el bit 3 del registro PORTA es cero, a numeros 
	  GOTO Numeros
	Letra_B:
	  CLRF	PORTD,0
	  BSF	PORTD,0,0; pone solo el bit 0 del registro PORTD en 1para el b 
	  BSF	PORTD,1,0; pone solo el bit 1 en 1 para el b 
	  CALL	Delay_1s
	  BTFSC PORTA,3,0
	  GOTO Numeros
	Letra_C:
	  CLRF PORTD,0
	  BSF	PORTD,1,0
	  BSF	PORTD,2,0
	  BSF	PORTD,6,0
	  CALL Delay_1s
	  BTFSC	PORTA,3,0
	  GOTO Numeros
	Letra_D:
	  CLRF PORTD,0
	  BSF	PORTD,0,0
	  BSF	PORTD,5,0
	  CALL Delay_1s
	  BTFSC	 PORTA,3,0
	  GOTO Numeros
	Letra_E:
	  CLRF PORTD,0
	  BSF	PORTD,1,0
	  BSF	PORTD,2,0
	  CALL Delay_1s
	  BTFSC	PORTA,3,0
	  GOTO	Numeros
	Letra_F:
	  CLRF	PORTD,0
	  BSF	PORTD,1,0
	  BSF	PORTD,2,0
	  BSF	PORTD,3,0
	  CALL Delay_1s
	  BTFSC PORTA,3,0
	  GOTO Numeros
	  GOTO Letras
	  
     Numeros:
	Numero_0:
	  CLRF PORTD,0
	  BSF	PORTD,6,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	Numero_1:
	  SETF	PORTD,0
	  BCF	PORTD,1,0
	  BCF	PORTD,2,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	Numero_2:
	  CLRF	PORTD,0
	  BSF	PORTD,2,0
	  BSF	PORTD,5,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	Numero_3:
	  CLRF	PORTD,0
	  BSF	PORTD,4,0
	  BSF	PORTD,5,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	Numero_4:
	  CLRF	PORTD,0
	  BSF	PORTD,0,0
	  BSF	PORTD,3,0
	  BSF	PORTD,4,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	Numero_5:
	  CLRF	PORTD,0
	  BSF	PORTD,1,0
	  BSF	PORTD,4,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	 Numero_6:
	  CLRF	PORTD,0
	  BSF	PORTD,1,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	 Numero_7:
	  SETF	PORTD,0
	  BCF	PORTD,0,0
	  BCF	PORTD,1,0
	  BCF	PORTD,2,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	 Numero_8:
	  CLRF	PORTD,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	 Numero_9:
	  CLRF	PORTD,0
	  BSF	PORTD,3,0
	  BSF	PORTD,4,0
	  CALL Delay_1s
	  BTFSS	PORTA,3,0
	  GOTO Letras
	  GOTO Numeros
Config_OSC:
    ;configuramos el oscilador a una frecuencia de 4Mhz  
    BANKSEL OSCCON1
    MOVLW 0x60	;seleccionamos el bloque del oscilador interno con un div:1
    MOVWF OSCCON1
    MOVLW 0X02	;seleccionamos a una frecuencia de 4Mhz
    MOVWF OSCFRQ
    RETURN
 
Config_Port:	;PORT-LAT-ANSEL-TRIS LED:RF3,  BUTTON:RA3
    ;Config Button
    BANKSEL LATA
    CLRF    LATA,1	;PORTA<7,0> = 0
    CLRF    ANSELA,1	;PORTA DIGITAL
    BSF	    TRISA,3,1	;RA3 COMO ENTRADA
    BSF	    WPUA,3,1	;ACTIVAMOS LA RESISTENCIA PULLUP DEL PIN RA3
    ;Config Port D
    BANKSEL PORTD
    SETF    PORTD,1	;PORTE<7,0> = 1
    CLRF    ANSELD,1	;PORTE DIGITAL
    CLRF    TRISD,1	;PORTE COMO SALIDA
    RETURN

END resetVect


