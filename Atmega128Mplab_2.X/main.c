/* 
 * File:    main.c
 * Author:  Sergio Santos
 *  <sergio.salazar.santos@gmail.com>
 * Date:
 *  30/09/2020
 */
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
#include "Librarias/ATMEGA128API/Atmega128API.h"
#include "Librarias/LCD/lcd.h"
#include "Librarias/FUNCTION/function.h"
#include "Librarias/KEYPAD/keypad.h"
/*
** constant and macro
*/
#define TRUE 1
#define FALSE 0
#define GI 7
/*
** variable
*/
uint8_t count;
/*
** procedure and function header
*/
void PORTINIT(void);
/*
 ** MAIN
 */
int main(int argc, char** argv) {
    /***Variables***/
    char* str=NULL;
    /***DEFINE IO***/
    uint8_t PPINB=PINB;//INIC value
    uint8_t LPINB;
    uint8_t PPINC=PINC;//INIC value
    uint8_t LPINC;
    /***FUNCTION***/
    PORTINIT();
	/***INICIALIZE OBJECTS***/
	LCD0 lcd0 = LCD0enable(&DDRA,&PINA,&PORTA);
    FUNC func = FUNCenable();
    TIMER_COUNTER0 tc_0 = TIMER_COUNTER0enable(0,1);
    KEYPAD keypad = KEYPADenable(&DDRE,&PINE,&PORTE);
    
    tc_0.start(1024);
    
	while(TRUE){
		lcd0.reboot();
        /*****Oneshot******/
        //UPDATE IO
        LPINB=PPINB;
        LPINC=PPINC;
        /***SETUP IO***/
        PPINB=PINB;
        PPINC=PINC;
        /******************/
		//TODO:: Please write your application code
		lcd0.gotoxy(0,4);
		lcd0.string_size("Boot up",7);
		lcd0.gotoxy(1,2);
		lcd0.string_size("Run",3);
        
        if(LPINB!=PPINB)
            str=func.ui16toa(func.hl(LPINB,PPINB));
        
        lcd0.gotoxy(2,0);
        lcd0.string_size(str,4);
        
        if(func.hl(LPINB,PPINB) & 1)
            PORTC+=1;
        
        if((func.hl(LPINB,PPINB) & 2))
            PORTC-=1;
        
        if((func.hl(LPINB,PPINB) & 4)){
            lcd0.write(0x1F,0);// cursor or display shift
            lcd0.BF();
        }
        
        
        lcd0.gotoxy(3,0);
        lcd0.string_size(keypad.get().string,20);
        
        
        if(keypad.get().character=='C'){
			keypad.flush();
		}
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
ISR(TIMER0_OVF_vect) // TIMER0_COMP_vect
{
    if(!count)
        PORTC=0;
    count+=1;
}

/*************************************************************************
*************************************************************************/

