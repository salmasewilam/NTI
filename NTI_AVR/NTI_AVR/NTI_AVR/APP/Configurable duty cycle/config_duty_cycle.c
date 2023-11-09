/*
 * config_duty_cycle.c
 *
 * Created: 11/08/23 8:32:47 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\DC Motor\DcMotor.h"

void config_duty_init (void)
{
	H_LCD_void_Init();
	keypad_init();
	DC_Motor_Init(M1);
	
}
void config_duty_app(void)
{
	H_LCD_void_clear();
	H_LCD_void_sendString("please enter the");
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendString("Duty Cycle  ");
	u8 duty=0,key;
	key=keypad_getkey();
	while (key!= '=')
	{
		if (key >=48 && key <58)
		{
			H_LCD_void_sendData(key);
			duty=duty*10+(key-48);
		}
		key=keypad_getkey();
	}
	H_LCD_void_clear();
	H_LCD_void_sendString("Duty = ");
	H_LCD_void_sendIntNum((u32)duty);
	DC_Motor_ON(M1,CLOCKWISE,duty);
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendString("To change duty");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("PRESS 0");
	while (keypad_getkey()!='0');
	return;
}