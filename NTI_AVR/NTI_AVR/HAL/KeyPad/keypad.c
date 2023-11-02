/*
 * keypad.c
 *
 * Created: 10/21/23 2:20:27 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\DIO\Dio_Private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad_config.h"

#define F_CPU 8000000
#include <util/delay.h>


u8 input[COLS]={FIRST_INPUT,SECOND_INPUT,THIRD_INPUT,FORTH_INPUT};
u8 output[ROWS]={FIRST_OUTPUT,SECOND_OUTPUT,THIRD_OUTPUT,FORTH_OUTPUT};
	
u8 keys[4][4]={{'7','8','9','/'},
                {'4','5','6','*'},
				{'1','2','3','-'},
				{'C','0','=','+'}
				};
u8 keys2[4][4]={{'A','B','C','D'},
{'E','F','G','H'},
{'I','J','K','L'},
{'M','N','O','S'}
};
void keypad_init (void)
{
	//set output pins rows
	DIO_voidSetPinDirection(PORT_OUT,FIRST_OUTPUT,OUTPUT);
	DIO_voidSetPinDirection(PORT_OUT,SECOND_OUTPUT,OUTPUT);
	DIO_voidSetPinDirection(PORT_OUT,THIRD_OUTPUT,OUTPUT);
	DIO_voidSetPinDirection(PORT_OUT,FORTH_OUTPUT,OUTPUT);
	//set input pins cols
	DIO_voidSetPinDirection(PORT_IN,FIRST_INPUT,INPUT);
	DIO_voidSetPinDirection(PORT_IN,SECOND_INPUT,INPUT);
	DIO_voidSetPinDirection(PORT_IN,THIRD_INPUT,INPUT);
	DIO_voidSetPinDirection(PORT_IN,FORTH_INPUT,INPUT);
	//set output as high
	DIO_voidSetPinValue(PORT_OUT,FIRST_OUTPUT,HIGH);
	DIO_voidSetPinValue(PORT_OUT,SECOND_OUTPUT,HIGH);
	DIO_voidSetPinValue(PORT_OUT,SECOND_OUTPUT,HIGH);
	DIO_voidSetPinValue(PORT_OUT,SECOND_OUTPUT,HIGH);
	//set input as high for pullup 
	//DIO_voidSetPinValue(ptrD,3,HIGH);
	//DIO_voidSetPinValue(ptrD,5,HIGH);
	//DIO_voidSetPinValue(ptrD,6,HIGH);
	//DIO_voidSetPinValue(ptrD,7,HIGH);
	
}

u8 keypad_getkey(void)
{
	int r,c;
	u8 key='T';
	for (r=0;r<ROWS;r++)
	{
		DIO_voidSetPinValue(PORT_OUT,output[r],LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_GetPinValue(PORT_IN,input[c])==LOW)
			{
				key=keys[r][c];
				while(DIO_GetPinValue(PORT_IN,input[c])==LOW);
				return key;
			}
			
		}
		DIO_voidSetPinValue(PORT_OUT,output[r],HIGH);
	}
	return key;
}

u8 keypad_getkey_char(void)
{
	int r,c;
	u8 key='T';
	for (r=0;r<ROWS;r++)
	{
		DIO_voidSetPinValue(PORT_OUT,output[r],LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_GetPinValue(PORT_IN,input[c])==LOW)
			{
				key=keys2[r][c];
				while(DIO_GetPinValue(PORT_IN,input[c])==LOW);
				return key;
			}
			
		}
		DIO_voidSetPinValue(PORT_OUT,output[r],HIGH);
	}
	return key;
}