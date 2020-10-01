/*************************************************************************
Title: eeprom wrapper
Author: Sergio Santos
 * <sergio.salazar.santos@gmail.com>
File: $Id: eeprom.c,v 0.2 01/10/2020 Exp $
Software: AVR-GCC 4.1, AVR Libc 1.4.6 or higher
Hardware: ATmega
License: GNU General Public License
Comment:
   Very Stable
*************************************************************************/
/*
** library
*/
#include "eeprom.h"
/*
** constant and macro
*/
/*
** variable
*/
/*
** procedure and function header
*/
/*
** procedure and function
*/
EEPROM EEPROMenable(void){
	EEPROM eeprom;
	eeprom.read_byte=eeprom_read_byte;
	eeprom.write_byte=eeprom_write_byte;
	eeprom.update_byte=eeprom_update_byte;
	eeprom.read_word=eeprom_read_word;
	eeprom.write_word=eeprom_write_word;
	eeprom.update_word=eeprom_update_word;
	//eeprom.read_dword=eeprom_read_dword;
	eeprom.write_dword=eeprom_write_dword;
	eeprom.write_dword=eeprom_write_dword;
	//eeprom.read_float=eeprom_read_float;
	eeprom.write_float=eeprom_write_float;
	eeprom.update_float=eeprom_update_float;
	eeprom.read_block=eeprom_read_block;
	eeprom.write_block=eeprom_write_block;
	eeprom.update_block=eeprom_update_block;
	return eeprom;
}
/*
** interrupt
*/
/***EOF***/
