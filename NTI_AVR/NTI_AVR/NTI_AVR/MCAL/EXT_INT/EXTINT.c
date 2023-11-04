/*
 * EXTINT.c
 *
 * Created: 10/22/23 2:38:47 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\EXT_INT\EXTINT.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\EXT_INT\ExtInt_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"

void (* p_NTI[3])(void)={0,0,0};
	
void EXT_voidEnable(u8 intid,TRIGGER trig)
{
	if (intid>7 || intid<5)
	{
		return;
	}
	SET_BIT(GICR,intid);
	
	switch(intid)
	{
		case INT0: MCUCR&=0b11111100;
		           MCUCR|=trig;
				   break;
        case INT1:MCUCR&=0b11110011;
                  MCUCR|=(trig<<2);
                   break;
 		case INT2: if (trig ==The_falling_edge) CLEAR_BIT(MCUCSR,6);
		          else SET_BIT(MCUCSR,6); break;
 		break;
		 
	}
	
}
void EXT_voidDisable(u8 intid)
{
	CLEAR_BIT(GICR,intid);
}
void EXTINT_setcallback(void (*p)(void),u8 intid)
{
	switch(intid)
	{
		case INT0: p_NTI[0]=p; break;
		case INT1: p_NTI[1]=p; break;
		case INT2: p_NTI[2]=p; break;
	}
	
}

ISR(INT0_vect)
{
	if (p_NTI[0]!=0)
	{
		p_NTI[0]();
	}
	return;
}

ISR(INT1_vect)
{
	if (p_NTI[1]!=0)
	{
		p_NTI[1]();
	}
	return;
}

ISR(INT2_vect)
{
	if (p_NTI[2]!=0) 
	{
		p_NTI[2]();
	}
	return;
}