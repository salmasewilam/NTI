/*
 * EXTINT.h
 *
 * Created: 10/22/23 2:20:49 PM
 *  Author: USER
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"

#define INT0 6
#define INT1 7 
#define INT2 5


typedef enum {The_low_level,Any_logical_change,The_falling_edge,The_rising_edge}TRIGGER;

void EXT_voidEnable(u8 intid,TRIGGER trig);
void EXT_voidDisable(u8 intid);
void EXTINT_setcallback(void (*p)(void),u8 intid);

#endif /* EXTINT_H_ */