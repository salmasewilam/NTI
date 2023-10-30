/*
 * Dio.c
 *
 * Created: 10/21/23 10:25:48 AM
 *  Author: USER
 */ 

#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Dio.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\stdtypes.h"
void DIO_voidSetPinDirection(ports_t *ptr,unsigned char p,Direction dir )
{
	switch(p)
	{
		case 0: ptr->DDR.PIN0=dir; break;
		case 1: ptr->DDR.PIN1=dir; break;
		case 2: ptr->DDR.PIN2=dir; break;
		case 3: ptr->DDR.PIN3=dir; break;
		case 4: ptr->DDR.PIN4=dir; break;
		case 5: ptr->DDR.PIN5=dir; break;
		case 6: ptr->DDR.PIN6=dir; break;
		case 7: ptr->DDR.PIN7=dir; break;
	}
}

void DIO_voidSetPinValue(ports_t *ptr,unsigned char p,Value val)
{
	switch(p)
	{
		case 0: ptr->port.PIN0=val; break;
		case 1: ptr->port.PIN1=val; break;
		case 2: ptr->port.PIN2=val; break;
		case 3: ptr->port.PIN3=val; break;
		case 4: ptr->port.PIN4=val; break;
		case 5: ptr->port.PIN5=val; break;
		case 6: ptr->port.PIN6=val; break;
		case 7: ptr->port.PIN7=val; break;
	}
}
Value DIO_GetPinValue(ports_t *ptr,unsigned char p)
{
	Value val;
	switch(p)
	{
		case 0: val=ptr->pin.PIN0; break;
		case 1: val=ptr->pin.PIN1; break;
		case 2: val=ptr->pin.PIN2; break;
		case 3: val=ptr->pin.PIN3; break;
		case 4: val=ptr->pin.PIN4; break;
		case 5: val=ptr->pin.PIN5; break;
		case 6: val=ptr->pin.PIN6; break;
		case 7: val=ptr->pin.PIN7; break;
	}
	return val;
	
}
void DIO_SetPortDirection(ports_t *ptr ,Direction dir )
{
	ptr->DDR.port=dir;
}
void DIO_voidSetPortValue(ports_t *ptr,Value val)
{
	ptr->port.port=val;
}
unsigned char DIO_GetPortValue(ports_t *ptr)
{
	unsigned char val;
	val=ptr->pin.port;
	return val;
}

void DIO_Toggle_pin(ports_t *ptr,unsigned char p)
{
	u8 val=DIO_GetPinValue(ptr,p);
	if (val==1)
	DIO_voidSetPinValue(ptr,p,0);
	else
	DIO_voidSetPinValue(ptr,p,1);
}