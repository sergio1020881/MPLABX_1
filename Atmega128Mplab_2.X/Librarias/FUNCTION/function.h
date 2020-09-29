/************************************************************************
Title:    FUNCTION
Author:   
    Sergio Santos
    <sergio.salazar.santos@gmail.com>
File:
    $Id: function.h,v 0.1 29/09/2020 Exp $
License:
    GNU General Public License 
Comment:
	Very Stable
************************************************************************/
#ifndef _FUNCTION_H_
	#define _FUNCTION_H_
/*
** Library
*/
#include <inttypes.h>
/*
** constant and macro
*/
/*
** variable
*/
struct function{
	/***PROTOTYPES VTABLE***/
	unsigned int (*power)(uint8_t base, uint8_t n);
	int (*stringlength)(const char string[]);
	void (*reverse)(char s[]);
	unsigned int (*mayia)(unsigned int xi, unsigned int xf, uint8_t nbits);
	uint8_t (*pinmatch)(uint8_t match, uint8_t pin, uint8_t HL);
	uint8_t (*hh)(uint8_t xi, uint8_t xf);
	uint8_t (*ll)(uint8_t xi, uint8_t xf);
	uint8_t (*lh)(uint8_t xi, uint8_t xf);
	uint8_t (*hl)(uint8_t xi, uint8_t xf);
	uint8_t (*diff)(uint8_t xi, uint8_t xf);
	uint8_t (*hmerge)(uint8_t X, uint8_t Y);
	uint8_t (*lmerge)(uint8_t X, uint8_t Y);
	void (*swap)(long *px, long *py);
	void (*copy)(char to[], char from[]);
	void (*squeeze)(char s[], int c);
	void (*shellsort)(int v[], int n);
	char* (*i16toa)(int16_t n);
	char* (*ui16toa)(uint16_t n);
	char* (*i32toa)(int32_t n);
	int (*trim)(char s[]);
	int (*pmax)(int a1, int a2);
	int (*gcd)(int u, int v);
	int (*strToInt)(const char string[]);
	uint8_t (*filter)(uint8_t mask, uint8_t data);
	unsigned int (*ticks)(unsigned int num);
	int (*twocomptoint8bit)(int twoscomp);
	int (*twocomptoint10bit)(int twoscomp);
	int (*twocomptointnbit)(int twoscomp, uint8_t nbits);
	char (*dec2bcd)(char num);
	char (*bcd2dec)(char num);
	char* (*resizestr)(char *string, int size);
	long (*trimmer)(long x, long in_min, long in_max, long out_min, long out_max);
	unsigned char (*bcd2bin)(unsigned char val);
	unsigned char (*bin2bcd)(unsigned val);
	long (*gcd1)(long a, long b);
	uint8_t (*pincheck)(uint8_t port, uint8_t pin);
	char* (*print_binary)(uint8_t number);
	/***pc use***
	char* (*fltos)(FILE* stream);
	char* (*ftos)(FILE* stream);
	int (*strtotok)(char* line,char* token[],const char* parser);
	char* (*putstr)(char* str);
	int (*getnum)(char* x);
	unsigned int (*getnumv2)(char* x);
	int (*readint)(int nmin, int nmax);
	*/
};
typedef struct function FUNC;
/*
** procedure and function header
*/
FUNC FUNCenable(void);
#endif
/***EOF***/
