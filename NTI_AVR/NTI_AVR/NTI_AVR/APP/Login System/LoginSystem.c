/*
 * LoginSystem.c
 *
 * Created: 11/02/23 7:41:22 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Login System\LoginSystem.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Data_password\password.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
extern const data_t data_base[2];
extern u8 index;
void loginsystem_init (void)
{
	Timer1_Init(Timer1_Normal_Mode,Timer1_Scaler_8,Timer1_Disconnected,Timer1_Disconnected);
	UltraSonic_init();
	H_LCD_void_Init();
	keypad_init();
//	DIO_voidSetPinDirection(Relay_port,Relay_pin,OUTPUT);
}

void loginsystem_app(void)
{
	state_t state;
	u16 distance;
	u8 key;
	distance=ultrasonic_getdistance();
	if (distance>16)
	{
		return;
	}
	H_LCD_void_clear();
	H_LCD_void_sendString("To enter the system press 0");
	key=keypad_getkey();
	while (key =='T')
	{
	key=keypad_getkey();
	}
	state =confirm_id_pass();
	if (state == SUCCESS)
	{
		H_LCD_void_sendString("Welcome ");
		 H_LCD_void_sendString(data_base[index].name);
		 
	}
}