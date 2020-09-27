/************************************************************************
Title: ATMEGA 128
Author: Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File: main.c 2020/09/26 14:00:00
Software: Atmel Studio 7 (Version: 7.0.1931)
Hardware: Atmega128 by ETT ET-BASE
	-PORTA: lcd display 2x16 or 4x20
	-16Mhz
LICENSE:
	Copyright (C) 2014
	This program is free software; you can redistribute it and/or modify
	it.
COMMENT:
	stable
************************************************************************/
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
/***preamble inic***/
#define F_CPU 16000000UL
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
int main(int argc, char** argv) {
    PORTINIT();
	/***INICIALIZE OBJECTS***/
	LCD0 lcd0 = LCD0enable(&DDRA,&PINA,&PORTA);
	while(TRUE){
		lcd0.reboot();
		//TODO:: Please write your application code
		lcd0.gotoxy(0,4);
		lcd0.string_size("Ola Sergio",10);
		lcd0.gotoxy(1,2);
		lcd0.string_size("Bom trabalho",12);
	}
    return (EXIT_SUCCESS);
}
/*
** procedure and function definition
*/
void PORTINIT()
{
	DDRG|=0B00000100;
	PORTG|=0B00000011;
	SREG|=(1<<GI);
}
/*
** interrupt
*/
/*************************************************************************
*************************************************************************/
