/*
 * EXTINT.h
 *
 * Created: 10/22/23 2:20:49 PM
 *  Author: USER
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

#include "stdtypes.h"

#define INT0 6
#define INT1 7 
#define INT2 5

#define GICR (*(volatile u8 *)0x5B)
#define MCUCR (*(volatile u8 *)0x55)
#define MCUCSR (*(volatile u8 *)0x54)

typedef enum {The_low_level,Any_logical_change,The_falling_edge,The_rising_edge}TRIGGER;

void EXT_voidEnable(u8 intid,TRIGGER trig);
void EXT_voidDisable(u8 intid);
void EXTINT_setcallback(void (*p)(void),u8 intid);

#endif /* EXTINT_H_ */