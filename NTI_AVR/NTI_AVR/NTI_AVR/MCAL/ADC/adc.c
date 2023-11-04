/*
 * adc.c
 *
 * Created: 10/24/23 9:38:39 AM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\ADC\adc_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\ADC\Adc_private.h"

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

u16 ADC_getDigitalValueSynchBlocking (CHANNELS ch)
{
	u16 data;
	ADMUX=ADMUX & 0xE0;
	ADMUX=ADMUX |ch;
	//start conversion
	SET_BIT(ADCSRA,ADSC);	
while (READ_BIT(ADCSRA,ADSC)!=0);
	data=ADC;
	return data;
}
u8 ADC_getDigitalValueSynchNonBlocking (u16 * p)
{
	SET_BIT(ADCSRA,ADSC);
	
	if (READ_BIT(ADCSRA,ADSC)==0)
	{
		*p=ADC;
		return 0;
	}
	return -1;
}
void ADC_SetCallBack(void(*p)(void))
{
	if (p!=0)
	{
		EXT_INT_ptr=p;
		//enable();
	SET_BIT(ADCSRA,ADSC);
	SET_BIT(ADCSRA,ADSC);
	
	}

}
u16 ADC_getreading(void)
{
	return ADC;
}
void ADC_getDigitalValueAsynchCallBack(CHANNELS ch,void(*p)(void))
{
	//set channel
	ADMUX=ADMUX & 0xE0;
	ADMUX=ADMUX |ch;
	//set call back pointer
	if (p!= 0) EXT_INT_ptr=p;
	//enable interrupt
	SET_BIT(ADCSRA,ADIE);
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	
}

ISR(ADC_vect)
{

	if (EXT_INT_ptr!=0)
	{
		EXT_INT_ptr();
	}
}
