/*
 * sevensegment.c
 *
 * Created: 10/21/23 11:27:37 AM
 *  Author: USER
 */ 
#include "Dio.h"
#include "sevensegment.h"

#define F_CPU 8000000
#include <util/delay.h>
	
void sevseg_init(void)
{
	//set com as output for the four 7seg
	DIO_voidSetPinDirection(ptrA,2,1);
	DIO_voidSetPinDirection(ptrA,3,1);
	DIO_voidSetPinDirection(ptrB,5,1);
	DIO_voidSetPinDirection(ptrB,6,1);
	
    //enable only one 7seg
	DIO_voidSetPinValue(ptrA,2,1);
	DIO_voidSetPinValue(ptrA,3,0);
	DIO_voidSetPinValue(ptrB,5,1);
	DIO_voidSetPinValue(ptrB,6,1);
	
	//set decoder pins as output
	DIO_voidSetPinDirection(ptrB,0,1);
	DIO_voidSetPinDirection(ptrB,1,1);
	DIO_voidSetPinDirection(ptrB,2,1);
	DIO_voidSetPinDirection(ptrB,4,1);
	

}
void sevseg_num(u8 num)
{
	
	/*
	     NOT TESTED
	    u8 seg[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x11};
		u8 value=DIO_GetPortValue(ptrB);
		value&=~seg[num];
		value|=seg[num];
		DIO_voidSetPortValue(ptrB,value);*/
	switch(num){
		case 0: DIO_voidSetPinValue(ptrB,0,0);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 1: DIO_voidSetPinValue(ptrB,0,1);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 2: DIO_voidSetPinValue(ptrB,0,0);
		DIO_voidSetPinValue(ptrB,1,1);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 3: DIO_voidSetPinValue(ptrB,0,1);
		DIO_voidSetPinValue(ptrB,1,1);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 4: DIO_voidSetPinValue(ptrB,0,0);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,1);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 5: DIO_voidSetPinValue(ptrB,0,1);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,1);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 6: DIO_voidSetPinValue(ptrB,0,0);
		DIO_voidSetPinValue(ptrB,1,1);
		DIO_voidSetPinValue(ptrB,2,1);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 7: DIO_voidSetPinValue(ptrB,0,1);
		DIO_voidSetPinValue(ptrB,1,1);
		DIO_voidSetPinValue(ptrB,2,1);
		DIO_voidSetPinValue(ptrB,4,0);
		break;
		case 8: DIO_voidSetPinValue(ptrB,0,0);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,1);
		break;
		case 9: DIO_voidSetPinValue(ptrB,0,1);
		DIO_voidSetPinValue(ptrB,1,0);
		DIO_voidSetPinValue(ptrB,2,0);
		DIO_voidSetPinValue(ptrB,4,1);
		break;
	}
	
}

void sevseg_4num(u16 num){
	u8 rem;
	
		rem=num%10;
		num=num/10;
		sevseg_num(rem);
		_delay_ms(1);
		DIO_voidSetPinValue(ptrA,3,1);
		DIO_voidSetPinValue(ptrA,2,0);
		rem=num%10;
		num=num/10;
		sevseg_num(rem);
		_delay_ms(1);
		DIO_voidSetPinValue(ptrA,2,1);
		DIO_voidSetPinValue(ptrB,5,0);//5
		
		rem=num%10;
		num=num/10;
		sevseg_num(rem);
		_delay_ms(1);
		DIO_voidSetPinValue(ptrB,5,1);
		DIO_voidSetPinValue(ptrB,6,0);
		rem=num%10;
		num=num/10;
		sevseg_num(rem);
		_delay_ms(1);
		DIO_voidSetPinValue(ptrB,6,1);
		DIO_voidSetPinValue(ptrA,3,0);
	
}