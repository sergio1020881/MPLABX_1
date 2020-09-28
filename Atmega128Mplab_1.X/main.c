/************************************************************************
Title:
    ATMEGA 128
Author:
    Sergio Santos
    <sergio.salazar.santos@gmail.com>
File:
    main.c 2020/09/26 14:00:00
Software:
    MPLAB X IDE v5.40
Hardware: Atmega128 by ETT ET-BASE
	-PORTA: lcd display 2x16 or 4x20
License:
    GNU Public License
Comment:
	28092020
************************************************************************/
/***preamble inic***/
#define F_CPU 16000000UL
/*
** library
*/
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "librarias/Atmega128API.h"
#include "librarias/lcd.h"
#include "librarias/function.h"
/*
** constant and macro
*/
#define TRUE 1
#define FALSE 0
#define GI 7
/*
** variable
*/
/*
** procedure and function header
*/
void PORTINIT();
/*
 ** MAIN
 */
int main(int argc, char** argv) {
    PORTINIT();
	/***INICIALIZE OBJECTS***/
	LCD0 lcd0 = LCD0enable(&DDRA,&PINA,&PORTA);
    FUNC func = FUNCenable();
    
    
	while(TRUE){
		lcd0.reboot();
		//TODO:: Please write your application code
		lcd0.gotoxy(0,4);
		lcd0.string_size("Boot up",7);
		lcd0.gotoxy(1,2);
		lcd0.string_size("Run",3);
        PORTC=PINB;
        
        
        
        
	}
    return (EXIT_SUCCESS);
}
/*
** procedure and function definition
*/
void PORTINIT()
{
	DDRB=0B00000000;
	PORTB=0B11111111;
    DDRC=0B11111111;
    PORTC=0B00000000;
	SREG|=(1<<GI);
}
/*
** interrupt
*/


/*************************************************************************
*************************************************************************/
