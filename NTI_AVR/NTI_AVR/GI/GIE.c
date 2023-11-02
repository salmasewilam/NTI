/*
 * GIE.c
 *
 * Created: 10/22/23 2:03:58 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
void enable()
{
	SET_BIT(SREG,GI);
}
void disable()
{
	CLEAR_BIT(SREG,GI);
}
