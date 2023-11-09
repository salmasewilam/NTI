/*
 * LoginSystem.c
 *
 * Created: 11/02/23 7:41:22 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Login System\LoginSystem.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Login System\LoginSystem_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Data_password\password.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#define F_CPU 16000000
#include <util/delay.h>
extern const data_t data_base[2];
extern s8 index;
u8 system_flag=0;
void loginsystem_init (void)
{
	Timer1_Init(Timer1_Normal_Mode,Timer1_Scaler_8,Timer1_Disconnected,Timer1_Disconnected);
	UltraSonic_init();
	H_LCD_void_Init();
	keypad_init();
	DIO_voidSetPinDirection(RELAY_PORT,RELAY_PIN,OUTPUT);
	DIO_voidSetPinDirection(LED_PORT,LED_PIN,OUTPUT);
	
}
static void success_state(void)
{
	u8 key;
	system_flag=1;
	H_LCD_void_clear();
	H_LCD_void_sendString("Welcome ");
	H_LCD_void_sendString(data_base[index].name);
	DIO_voidSetPinValue(RELAY_PORT,RELAY_PIN,HIGH);
	_delay_ms(300);
	H_LCD_void_clear();
	H_LCD_void_sendString("1-LED ON 2-LED OFF");
	while (key !='1' && key !='2')
	{
		key=keypad_getkey();
	}
	switch(key)
	{
		case '1': DIO_voidSetPinValue(LED_PORT,LED_PIN,HIGH); break;
		case '2': DIO_voidSetPinValue(LED_PORT,LED_PIN,LOW); break;
		
	}
	_delay_ms(500);
}
static void wrong_pass(void)
{
	H_LCD_void_clear();
	H_LCD_void_sendString("Wrong pass,please     try again");
	_delay_ms(200);
}

void loginsystem_app(void)
{
	DIO_voidSetPinValue(RELAY_PORT,RELAY_PIN,LOW);
	DIO_voidSetPinValue(LED_PORT,LED_PIN,LOW);
	
	state_t state;
	u16 distance;
	u8 key,trial_num=0;
	u32 id,pass;
	distance=ultrasonic_getdistance();

	if (distance>16)
	{
		H_LCD_void_gotoXY(0,0);
		H_LCD_void_sendString("NO ONE DETECTED                    ");
		return;
	}
	H_LCD_void_gotoXY(0,0);
	H_LCD_void_sendString("To Login Press 0                         ");
	while (key !='0')
	{
		key =keypad_getkey();
		distance=ultrasonic_getdistance();
		_delay_ms(20);
		if (distance>16)
		{
			return;
		}
	}
	id=get_id();
	pass=get_pass();
	state=confirm_id_pass(id,pass); 
	if (state == SUCCESS)
	{
		 success_state();
	}
	else if (state == USER_NOT_FOUND)
	{
		H_LCD_void_clear();
		H_LCD_void_sendString("User Not found");
		_delay_ms(500);
		return;
	}
	else if (state == WRONG_PASS)
	{
		trial_num ++;
		while (trial_num<3)
		{
			wrong_pass();
			pass=get_pass();
			state=confirm_id_pass(id,pass);
			if (state ==SUCCESS)
			{
				success_state();
				break;
			}
			trial_num ++;
		}
	}
	if (system_flag != 1)
	{
		H_LCD_void_clear();
		H_LCD_void_sendString("SYSTEM IS LOCKED    FOR 2MIN");
		_delay_ms(2000);
	}
	system_flag=0;
}