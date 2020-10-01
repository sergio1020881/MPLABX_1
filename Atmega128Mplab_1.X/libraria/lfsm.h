/************************************************************************
Title:    LFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: lfsm.h,v 0.1 2018/08/18 13:00:00 Sergio Exp $
Software: GCC
Hardware:
	Atmel MCU (Atmega324A)
License:  GNU General Public License
Usage:
	Micro controller Atmel, the library is mcu independent, but in this case using Atmega324A.
LICENSE:
    Copyright (C) 2018
    This program is free software; you can redistribute it and/or modify
    it under the consent of the code developer, in case of commercial use
    need license.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	very stable
************************************************************************/
#ifndef _LFSM_H_
	#define _LFSM_H_
/******/
#include "eeprom.h"
/*
** constant and macro
*/
/*
** variable
*/
struct lfsmdata{
	uint8_t page;
	uint8_t feedback;
	uint8_t inhl;
	uint8_t inlh;
	uint8_t mask;
	uint8_t outhl;
	uint8_t outlh;
};
/******/
struct lfsm{
	//Local Variables
	EEPROM* eeprom;
	uint8_t sizeeeprom;
	uint8_t sizeblock;
	uint8_t page;
	uint8_t input;
	uint8_t output;
	uint8_t status;
	//Function Pointers
	uint8_t (*read)(struct lfsm *r, uint8_t input);
	uint8_t (*learn)(struct lfsm *r, const uint8_t input, const uint8_t next, const uint8_t mask, const uint8_t page);
	uint8_t (*quant)(struct lfsm *r);
	uint8_t (*remove)(struct lfsm *r, uint8_t input);
	uint8_t (*deleteall)(struct lfsm *r);
	uint8_t (*getoutput)(struct lfsm *r);
	uint8_t (*getstatus)(struct lfsm *r);
	void (*setoutput)(struct lfsm *r,uint8_t output);
	uint8_t (*getpage)(struct lfsm *r);
	void (*setpage)(struct lfsm *r,uint8_t page);
};
typedef struct lfsm LFSM;
/*
** procedure and function header
*/
LFSM LFSMenable(EEPROM* eeprom, const uint8_t sizeeeprom);
#endif
/***EOF***/
