/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 8000000
#include <util/delay.h>

#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Dio.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\sevensegment.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\keypad.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\EXTINT.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\adc.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\APP\password.h"


u16 data;
u8 flag=0;
void f1(void)
{
	DIO_voidSetPinDirection(ptrC,2,1);
	DIO_voidSetPinValue(ptrC,2,1);
}
void f2(void)
{
	DIO_voidSetPinDirection(ptrC,0,1);
	DIO_voidSetPinValue(ptrC,0,1);
}
void f3(void)
{
	data=ADC;
	flag=1;
	SET_BIT(ADCSRA,ADSC);
	
}
int main(void)
{
	H_LCD_void_Init();
	sevseg_init();
	keypad_init();
	ADC_Init();
	//DIO_voidSetPinDirection(ptrA,0,0);
	
	//EXT_voidEnable(INT0,The_rising_edge);
	//EXT_voidEnable(INT1,The_rising_edge);
//	EXT_voidEnable(INT2,The_rising_edge);
	
//	EXTINT_setcallback(f2,INT0);
	//EXTINT_setcallback(f1,INT1);
	//EXTINT_setcallback(f3,INT2);
	//enable();
   u8 key;
	u8 smiley[8] = {
		0b00000,
		0b10001,
		0b00000,
		0b00000,
		0b10001,
		0b01110,
		0b00000,
		0b00000,
	};
	u8 s[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b10101,
		0b10101,
		0b11111,
		0b00000,
		0b00000
	};
	u8 l[8] = {
		0b00000,
		0b00000,
		0b00100,
		0b00100,
		0b00100,
		0b11111,
		0b00000,
		0b00000
	};
	u8 m[8] = {
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b11100,
		 0b10111,
		 0b11100,
		 0b00000
	};
	u8 a[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00011,
		0b10010,
		0b11110
	};
//	H_LCD_void_creatCustomChar(smiley, 0);
	//H_LCD_void_creatCustomChar(s, 1);
	//H_LCD_void_creatCustomChar(l, 2);
//	H_LCD_void_creatCustomChar(m, 3);
	//H_LCD_void_creatCustomChar(a, 4);

	//H_LCD_void_gotoXY(0,6);


	    while (1) {
				H_LCD_void_clear();
				app();
				_delay_ms(3000);
		
		}
	}
