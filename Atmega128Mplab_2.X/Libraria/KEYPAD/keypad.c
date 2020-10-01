/*************************************************************************
KEYPAD API START
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
Date: 29092020
Comment:
   Stable
*************************************************************************/
/***preamble inic***/
/*
** Library
*/
#include <avr/io.h>
#include <inttypes.h>
/***/
#include "keypad.h"
/***preamble inic***/
/*
** constant and macro
*/
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif
#define KEYPADLINES 4
#define KEYPADCOLUMNS 4
/*
** variable
*/
volatile uint8_t *keypad_DDR;
volatile uint8_t *keypad_PIN;
volatile uint8_t *keypad_PORT;
struct keydata{
	uint8_t line_1;
	uint8_t line_2;
	uint8_t line_3;
	uint8_t line_4;
}keypad_datai,keypad_dataf;
char keypadvalue[KEYPADLINES][KEYPADCOLUMNS]=
{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0',35,'D'}
};
volatile uint8_t KEYPADSTRINGINDEX;
struct keypadata data;
/*
** procedure and function header
*/
/***getkey***/
char KEYPAD_getkey(void);
/***string***/
struct keypadata KEYPAD_get(void);
/***flush***/
void KEYPAD_flush(void);
/***lh***/
uint8_t KEYPADlh(uint8_t xi, uint8_t xf);
/***hl***/
uint8_t KEYPADhl(uint8_t xi, uint8_t xf);
/*
** procedure and function
*/
KEYPAD KEYPADenable(volatile uint8_t *ddr, volatile uint8_t *pin, volatile uint8_t *port)
{
	//LOCAL VARIABLES
	uint8_t tSREG;
	tSREG=SREG;
	data.character=' ';
	SREG&=~(1<<GLOBAL_INTERRUPT_ENABLE);
	//ALLOCAÇÂO MEMORIA PARA Estrutura
	KEYPAD keypad;
	//import parametros
	keypad_DDR=ddr;
	keypad_PIN=pin;
	keypad_PORT=port;
	//inic variables
	*keypad_DDR=(1<<KEYPADLINE_1) | (1<<KEYPADLINE_2) | (1<<KEYPADLINE_3) | (1<<KEYPADLINE_4);
	*keypad_PORT=(1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4);
	keypad_datai.line_1=keypad_dataf.line_1=(1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4);
	keypad_datai.line_2=keypad_dataf.line_2=(1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4);
	keypad_datai.line_3=keypad_dataf.line_3=(1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4);
	keypad_datai.line_4=keypad_dataf.line_4=(1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4);
	KEYPADSTRINGINDEX=0;
	//Direccionar apontadores para PROTOTIPOS
	keypad.getkey=KEYPAD_getkey;
	keypad.get=KEYPAD_get;
	keypad.flush=KEYPAD_flush;
	SREG=tSREG;
	//
	*keypad_PORT|=(1<<KEYPADLINE_1) | (1<<KEYPADLINE_2) | (1<<KEYPADLINE_3) | (1<<KEYPADLINE_4);
	//Going to use pull down method.
	return keypad;
}
char KEYPAD_getkey(void)
{
	uint8_t HL;
	char c='\0';
	uint8_t keypad_option;
	for(keypad_option=0;keypad_option<KEYPADLINES;keypad_option++){
		switch (keypad_option)
		{
			case 0: //line 1 index 0
				*keypad_DDR|=(1<<KEYPADLINE_1);
				*keypad_PORT&=~(1<<KEYPADLINE_1);
				keypad_dataf.line_1=*keypad_PIN & ((1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4));
				HL=KEYPADhl(keypad_datai.line_1,keypad_dataf.line_1);
				keypad_datai.line_1=keypad_dataf.line_1;
				if(HL){
					//decode index line one column what ?
					if(HL == (1<<KEYPADDATA_1))
						c=keypadvalue[0][0];
					if(HL == (1<<KEYPADDATA_2))
						c=keypadvalue[0][1];
					if(HL == (1<<KEYPADDATA_3))
						c=keypadvalue[0][2];
					if(HL == (1<<KEYPADDATA_4))
						c=keypadvalue[0][3];
				}
				*keypad_DDR&=~(1<<KEYPADLINE_1);
				*keypad_PORT|=(1<<KEYPADLINE_1);
				break;
			case 1: //line 2 index 1
				*keypad_DDR|=(1<<KEYPADLINE_2);
				*keypad_PORT&=~(1<<KEYPADLINE_2);
				keypad_dataf.line_2=*keypad_PIN & ((1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4));
				HL=KEYPADhl(keypad_datai.line_2,keypad_dataf.line_2);
				keypad_datai.line_2=keypad_dataf.line_2;
				if(HL){
					//decode index line two column what ?
					if(HL == (1<<KEYPADDATA_1))
						c=keypadvalue[1][0];
					if(HL == (1<<KEYPADDATA_2))
						c=keypadvalue[1][1];
					if(HL == (1<<KEYPADDATA_3))
						c=keypadvalue[1][2];
					if(HL == (1<<KEYPADDATA_4))
						c=keypadvalue[1][3];
				}
				*keypad_DDR&=~(1<<KEYPADLINE_2);
				*keypad_PORT|=(1<<KEYPADLINE_2);
				break;
			case 2: //line 3 index 2
				*keypad_DDR|=(1<<KEYPADLINE_3);
				*keypad_PORT&=~(1<<KEYPADLINE_3);
				keypad_dataf.line_3=*keypad_PIN & ((1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4));
				HL=KEYPADhl(keypad_datai.line_3,keypad_dataf.line_3);
				keypad_datai.line_3=keypad_dataf.line_3;
				if(HL){
					//decode index line three column what ?
					if(HL == (1<<KEYPADDATA_1))
						c=keypadvalue[2][0];
					if(HL == (1<<KEYPADDATA_2))
						c=keypadvalue[2][1];
					if(HL == (1<<KEYPADDATA_3))
						c=keypadvalue[2][2];
					if(HL == (1<<KEYPADDATA_4))
						c=keypadvalue[2][3];
				}
				*keypad_DDR&=~(1<<KEYPADLINE_3);
				*keypad_PORT|=(1<<KEYPADLINE_3);
				break;
			case 3: //line 4 index 3
				*keypad_DDR|=(1<<KEYPADLINE_4);
				*keypad_PORT&=~(1<<KEYPADLINE_4);
				keypad_dataf.line_4=*keypad_PIN & ((1<<KEYPADDATA_1) | (1<<KEYPADDATA_2) | (1<<KEYPADDATA_3) | (1<<KEYPADDATA_4));
				HL=KEYPADhl(keypad_datai.line_4,keypad_dataf.line_4);
				keypad_datai.line_4=keypad_dataf.line_4;
				if(HL){
					//decode index line four column what ?
					if(HL == (1<<KEYPADDATA_1))
						c=keypadvalue[3][0];
					if(HL == (1<<KEYPADDATA_2))
						c=keypadvalue[3][1];
					if(HL == (1<<KEYPADDATA_3))
						c=keypadvalue[3][2];
					if(HL == (1<<KEYPADDATA_4))
						c=keypadvalue[3][3];
				}
				*keypad_DDR&=~(1<<KEYPADLINE_4);
				*keypad_PORT|=(1<<KEYPADLINE_4);
				break;
			default:
				break;
		}//endswitch
	}//endfor
	return c;
}
/***get***/
struct keypadata KEYPAD_get(void)
{
	char c;
	c=KEYPAD_getkey();
	if(c){
		data.character=c;
		if(KEYPADSTRINGINDEX<(KEYPADSTRINGSIZE)){
			data.string[KEYPADSTRINGINDEX]=c;
			KEYPADSTRINGINDEX++;
		}
	}
	return data;
}
/***flush***/
void KEYPAD_flush(void)
{
	uint8_t i;
	data.character=' ';
	KEYPADSTRINGINDEX=0;
	for(i=0;i<KEYPADSTRINGSIZE+1;i++)
        data.string[i]='\0';
}
/***lh***/
uint8_t KEYPADlh(uint8_t xi, uint8_t xf)
{
	uint8_t i;
	//printf("KEYPADlh\n");
	i=xf^xi;
	i&=xf;
	return i;
}
/***hl***/
uint8_t KEYPADhl(uint8_t xi, uint8_t xf)
{
	uint8_t i;
	//printf("KEYPADhl\n");
	i=xf^xi;
	i&=xi;
	return i;
}
/*
** interrupt
*/
/************************************************************************
The matrix buttons should have a diode em series so each button would only let current flow in one direction not allowing
feedbacks. Little defect of keypads !
A byte has 8bit 256 possible combinations, being zero [0] the first data address and two hundred and fifty five [255] the last, 
making the 256 possible addresses for data storage. In a string of length 256 in this case the address 255 or the 256 character 
is always the "\0" character has an indicator of end of string.
should try doing circular buffer just for fun, or maybe nor, who knows.
************************************************************************/
/*************************************************************************
KEYPAD API END
*************************************************************************/
