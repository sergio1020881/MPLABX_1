/*** 
File: main.c
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
Hardware: Atmega
	-PORTA : LCD Display 4X20
	-PORTB : Buttons
	-PORTC : Relay Board
	-PORTE : Keypad 4X4
Date:
	30/09/2020
Comment:
	LFSM
***/
/***FCPU***/
#define F_CPU 16000000UL
/*
** library
*/
//#include <stdio.h>
//#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "Librarias/EEPROM/eeprom.h"
#include "Librarias/ATMEGA128API/Atmega128API.h"
#include "Librarias/LCD/lcd.h"
#include "Librarias/FUNCTION/function.h"
#include "Librarias/KEYPAD/keypad.h"
#include "Librarias/LFSM/lfsm.h"
/*
 ** Constant and Macro
 */
#define True 1
/*
 ** Global Variable
 */
char* string=NULL;
/*
 ** Function Definition
 */
void PORTINIT(void);
/***MAIN***/
int main(void)
{
	PORTINIT();
	uint8_t option=0; //Menu Jumper
	uint8_t input_tmp=0;
	struct keypadata keypadinput;
	uint8_t output=0;
	uint8_t mask=0;
	uint8_t page=0;
	uint8_t n;
	KEYPAD keypad = KEYPADenable(&DDRE,&PINE,&PORTE);
	LCD0 lcd = LCD0enable(&DDRA,&PINA,&PORTA);
	EEPROM eeprom = EEPROMenable();
	LFSM lfsm = LFSMenable(&eeprom,571);
	FUNC func = FUNCenable();
	/**************************************/
	lfsm.setoutput(&lfsm,0);
	/*** Replace with your application code ***/
	while (True)
	{
		/******/
		keypadinput=keypad.get();
		n=PINB;
		/******/
		if(keypadinput.character){
			lcd.gotoxy(0,12);
			lcd.putch(keypadinput.character);
		}
		lcd.gotoxy(0,16);
		string=func.ui16toa(n);
		lcd.string_size(string,4);
		/******/
		switch(option){
			case 0:
				lcd.gotoxy(0,0);
				lcd.string_size("Running ",8);
				string=func.ui16toa(lfsm.getpage(&lfsm));
				lcd.string_size(string,3);
				if(keypadinput.character == 'A'){//Clear screen and empty buffer
					lcd.clear();
					keypad.flush();
					continue;
				}
				if(keypadinput.character == 'B'){//Learn
					lcd.clear();
					keypad.flush();
					option=1;
				}
				if(keypadinput.character == 'C'){//Delete or remove
					lcd.clear();
					keypad.flush();
					option=6;
				}
				lfsm.read(&lfsm,n);
				break;
			case 1:
				// Menu
				lcd.gotoxy(0,0);
				lcd.string_size("Enter: ",12);
				lcd.gotoxy(1,0);
				lcd.string_size("In   Out  Mask Page",20);
				option=2;
				break;
			case 2:
				lcd.gotoxy(0,7);
				lcd.string_size(keypadinput.string,4);
				if(keypadinput.character == 'D'){
					input_tmp=func.strToInt(keypadinput.string);
					lcd.gotoxy(2,0);
					string=func.ui16toa(input_tmp);
					lcd.string(string);
					keypad.flush();
					option=3;
				}
				if(keypadinput.character == 'C'){
					keypad.flush();
					option=2;
				}
				break;
			case 3:
				lcd.gotoxy(0,7);
				lcd.string_size(keypadinput.string,4);
				if(keypadinput.character == 'D'){
					output=func.strToInt(keypadinput.string);
					lcd.gotoxy(2,5);
					string=func.ui16toa(output);
					lcd.string(string);
					keypad.flush();
					option=4;
				}
				if(keypadinput.character == 'C'){
					keypad.flush();
					option=3;
				}
				break;
			case 4:
				lcd.gotoxy(0,7);
				lcd.string_size(keypadinput.string,4);
				if(keypadinput.character == 'D'){
					mask=func.strToInt(keypadinput.string);
					lcd.gotoxy(2,10);
					string=func.ui16toa(mask);
					lcd.string(string);
					keypad.flush();
					option=5;
				}
				if(keypadinput.character == 'C'){
					keypad.flush();
					option=4;
				}
				break;
			case 5:
				lcd.gotoxy(0,7);
				lcd.string_size(keypadinput.string,4);
				if(keypadinput.character == 'D'){
					page=func.strToInt(keypadinput.string);
					lcd.gotoxy(2,15);
					string=func.ui16toa(page);
					lcd.string(string);
					switch(lfsm.learn(&lfsm,input_tmp,output,mask,page)){
						case 0:
							lcd.gotoxy(3,12);
							lcd.string_size("disabled",7);
							break;
						case 1:
							lcd.gotoxy(3,12);
							lcd.string_size("exists",7);
							break;
						case 2:
							lcd.gotoxy(3,12);
							lcd.string_size("upload",7);
							break;
						case 3:
							lcd.gotoxy(3,12);
							lcd.string_size("upload",7);
							break;
						case 4:
							lcd.gotoxy(3,12);
							lcd.string_size("full",7);
							break;
						default:
							break;
					}//End switch
				/******/
				//lfsm.read(&lfsm,input_tmp);
				keypad.flush();
				option=0;
				}//End if
				if(keypadinput.character == 'C'){
					keypad.flush();
					option=5;
				}
				break;
			case 6:
				lcd.gotoxy(1,0);
				lcd.string_size("Delete - 1",10);
				lcd.gotoxy(2,0);
				lcd.string_size("Remove - 2 No - 3",17);
				option=7;
				break;
			case 7:
				if(keypadinput.character == '1'){//Clear eeprom
					lcd.gotoxy(1,0);
					lcd.hspace(10);
					lcd.gotoxy(2,0);
					lcd.hspace(17);
					lfsm.deleteall(&lfsm);
					lfsm.setpage(&lfsm,0);
					//lfsm.setoutput(&lfsm,0X00);
					keypad.flush();
					lcd.gotoxy(3,12);
					lcd.string_size("deleted",7);
					option=0;
				}else if(keypadinput.character == '2'){//Remove one entry
					lcd.gotoxy(1,0);
					lcd.hspace(10);
					lcd.gotoxy(2,0);
					lcd.hspace(17);
					keypad.flush();
					option=8;
				}else if(keypadinput.character == '3'){//Exit
					lcd.gotoxy(1,0);
					lcd.hspace(10);
					lcd.gotoxy(2,0);
					lcd.hspace(17);
					keypad.flush();
					option=0;
				}
				break;
			case 8:
				lcd.gotoxy(0,0);
				lcd.string_size("Enter: ",12);
				lcd.gotoxy(1,0);
				lcd.string_size("Input",20);
				option=9;
				break;
			case 9:
				lcd.gotoxy(0,7);
				lcd.string_size(keypadinput.string,4);
				if(keypadinput.character == 'D'){
					input_tmp=func.strToInt(keypadinput.string);
					lcd.gotoxy(2,0);
					string=func.ui16toa(input_tmp);
					lcd.string(string);
					switch(lfsm.remove(&lfsm,input_tmp)){
						case 0:
							lcd.gotoxy(3,12);
							lcd.string_size("No entry",7);
							break;
						case 1:
							lcd.gotoxy(3,12);
							lcd.string_size("New Entry",7);
							break;
						case 2:
							lcd.gotoxy(3,12);
							lcd.string_size("global logic",7);
							break;
						case 3:
							lcd.gotoxy(3,12);
							lcd.string_size("local logic",7);
							break;
						case 4:
							lcd.gotoxy(3,12);
							lcd.string_size("local logic",7);
							break;
						case 41:
							lcd.gotoxy(3,12);
							lcd.string_size("local above",7);
							break;
						case 42:
							lcd.gotoxy(3,12);
							lcd.string_size("local bellow",7);
							break;
						default:
							break;
					}//End switch
					/******/
					//lfsm.read(&lfsm,input_tmp);
					
					keypad.flush();
					option=0;
				}//End if
				if(keypadinput.character == 'C'){
					keypad.flush();
					option=8;
				}
				break;
			default:
				break;
		}//End switch
		/***DISPLAY***/
		lcd.gotoxy(3,0);
		lcd.string_size("Output ",7);
		string=func.ui16toa(lfsm.getoutput(&lfsm));
		lcd.string_size(string,4);
		//lcd.hspace(2);
		//string=func.ui16toa(lfsm.getstatus(&lfsm));
		//lcd.string_size(string,4);
		PORTC=lfsm.getoutput(&lfsm);
		
	}//End while
}//End main
/***Procedure and Function***/
void PORTINIT(void){
	DDRC=0XFF;
	PORTC=0XFF;
	DDRB=0X00;
	PORTB=0XFF;
}
/***Interrupt***/
/***Comment
The more one programs the more precise our logical thinking becomes
absent from error.
***/
/***EOF***/
