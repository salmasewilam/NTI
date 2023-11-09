/*
 * coolingsystem.c
 *
 * Created: 11/02/23 6:01:14 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\CoolingSystem\coolingsystem.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\Lm35\lm35.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\DC Motor\DcMotor.h"

void coolingsystem_init(void)
{
	lm35_init();
	DC_Motor_Init(M1);
	H_LCD_void_Init();
	H_LCD_void_sendString("Current Temp= ");
}

void coolingsystem_app(void)
{
	//H_LCD_void_clear();
	H_LCD_void_gotoXY(0,14);
	u16 temp;
	temp=lm35_gettemp();
	H_LCD_void_sendIntNum((u32)temp);
	H_LCD_void_sendString("  ");
	if (temp<25)
	{
		DC_Motor_OFF(M1);
	}
	else if (temp<35)
	{
		DC_Motor_ON(M1,CLOCKWISE,50);
		
	}
	else if (temp>35)
	{
		DC_Motor_ON(M1,CLOCKWISE,80);
		
	}
}