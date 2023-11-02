/*
 * coolingsystem.c
 *
 * Created: 11/02/23 6:01:14 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\APP\CoolingSystem\coolingsystem.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\Lm35\lm35.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"

#define F_CPU 8000000
#include <util/delay.h>

void coolingsystem_init(void)
{
	lm35_init();
	Timer0_Init(Timer0_Fast_PWM_Mode,Timer0_Scaler_8,Timer0_Set_on_compare);
	H_LCD_void_Init();
	DIO_voidSetPinDirection(ptrB,3,OUTPUT);
}

void coolingsystem_app(void)
{
	H_LCD_void_clear();
	u16 temp;
	temp=lm35_gettemp();
	H_LCD_void_sendIntNum((u32)temp);
	if (temp<25)
	{
		setFastPWM(0);
	}
	else if (temp<35)
	{
		setFastPWM(50);
		
	}
	else if (temp>35)
	{
		setFastPWM(80);
		
	}
	_delay_ms(100);
}