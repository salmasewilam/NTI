/*
 * GIE.c
 *
 * Created: 10/22/23 2:03:58 PM
 *  Author: USER
 */ 
#include "GIE.h"
#include "utils.h"
void enable()
{
	SET_BIT(SREG,GI);
}
void disable()
{
	CLEAR_BIT(SREG,GI);
}
