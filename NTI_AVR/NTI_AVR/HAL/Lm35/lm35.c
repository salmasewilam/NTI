/*
 * lm35.c
 *
 * Created: 11/02/23 6:35:02 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\Lm35\lm35.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\ADC\adc.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"

void lm35_init(void)
{
	DIO_voidSetPinDirection(lm_port,lm_pin,INPUT);
	ADC_Init();
}

u16 lm35_gettemp(void)
{
	u16 adc_read=ADC_getDigitalValueSynchBlocking(lm_pin);
	u16 voltvalue=((u32)adc_read*5000)/1024; //volt in mv
	u16 temp=voltvalue/10;
	return temp;
}