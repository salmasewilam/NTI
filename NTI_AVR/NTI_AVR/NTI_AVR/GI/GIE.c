/*
 * GIE.c
 *
 * Created: 10/22/23 2:03:58 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE_Private.h"
void enable()
{
	SET_BIT(SREG,GI);
}
void disable()
{
	CLEAR_BIT(SREG,GI);
}
