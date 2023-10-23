/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 8000000
#include <util/delay.h>

#include "Dio.h"
#include "sevensegment.h"
#include "keypad.h"
#include "EXTINT.h"
#include "GIE.h"
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
	DIO_voidSetPinDirection(ptrC,1,1);
	DIO_voidSetPinValue(ptrC,1,1);
}
int main(void)
{
	sevseg_init();
	//keypad_init();
	DIO_voidSetPinDirection(ptrD,2,0);
	DIO_voidSetPinDirection(ptrD,3,0);
	DIO_voidSetPinDirection(ptrD,4,0);
	
	EXT_voidEnable(INT0,The_rising_edge);
	EXT_voidEnable(INT1,The_rising_edge);
//	EXT_voidEnable(INT2,The_rising_edge);
	
	EXTINT_setcallback(f2,INT0);
	EXTINT_setcallback(f1,INT1);
	//EXTINT_setcallback(f3,INT2);
	enable();
	/*
	DIO_voidSetPinDirection(ptrC,2,1);
	DIO_voidSetPinDirection(ptrC,0,1);
	DIO_voidSetPinDirection(ptrC,1,1);
*/
	u8 key;

    while (1) 
    {
		/*
		key=keypad_getkey();
		if (key =='0')
		{
			DIO_voidSetPinValue(ptrC,0,1);
			_delay_ms(2000);
			
		}
		*/
    }
}

