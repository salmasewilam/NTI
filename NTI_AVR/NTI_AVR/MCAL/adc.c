/*
 * adc.c
 *
 * Created: 10/24/23 9:38:39 AM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\adc_config.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"

void (*EXT_INT_ptr)(void)=(void *)0;

void ADC_Init(void) 
{
	//set prescaler
	ADCSRA&=0xF8;
	ADCSRA|= PRESCALER;
	//set vref
	ADMUX&=0x3F;
	ADMUX|=(VREF<<6);
	//set ADjust
	#if ADJUST == R_ADJUST
	CLEAR_BIT(ADMUX,ADLAR);
	#elif ADJUST == L_ADJUST
	SET_BIT(ADMUX,ADLAR);
	#endif
	//Auto trigger enable
	//SET_BIT(ADCSRA,ADATE);
	//enable
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_getDigitalValueSynchBlocking (void)
{
	u16 data;
	//ADMUX=ADMUX & 0xE0;
	//ADMUX=ADMUX |ch;
	SET_BIT(ADCSRA,ADSC);
	
while (READ_BIT(ADCSRA,ADSC)!=0);
	data=ADC;
	return data;
}
u16 ADC_getDigitalValueSynchNonBlocking (void)
{
	u16 data;
	SET_BIT(ADCSRA,ADSC);
	
	if (READ_BIT(ADCSRA,ADSC)==0)
	{
		data=ADC;
		return data;
	}
	return 0;
}
void ADC_getDigitalValueAsynchCallBack(void(*p)(void))
{
	if (p!=0)
	{
		EXT_INT_ptr=p;
		//enable();
	SET_BIT(ADCSRA,ADSC);
	
	}

}
ISR(ADC_vect)
{
	if (EXT_INT_ptr!=0)
	{
		EXT_INT_ptr();
	}
	return;
}
