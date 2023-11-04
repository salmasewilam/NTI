/*
 * ultrasonic.c
 *
 * Created: 11/01/23 4:29:19 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\UltraSonic_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"


#define F_CPU 8000000
#include <util/delay.h>

volatile u16 t1, t2;
volatile u8 ultrasonic_flag=0;

void UltraSonic_init(void)
{
	DIO_voidSetPinDirection(TRIG_PORT,TRIG,OUTPUT);
	DIO_voidSetPinDirection(ECHO,ECHO_PORT,INPUT);
	Timer1_ICU_SetCallBack(f1);
	Timer1_ICU_InterruptEnable();

}
u16 ultrasonic_getdistance(void)
{
	TCNT1=0;
	ultrasonic_flag=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_voidSetPinValue(TRIG_PORT,TRIG,HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(TRIG_PORT,TRIG,LOW);
	while(ultrasonic_flag<2);
	u16 t=t2-t1;
	u16 distance=t/58;
	return distance;
}
static void f1(void)
{
	if (ultrasonic_flag==0)
	{
		t1=ICU_TakeReading();
	Timer1_InputCaptureEdge(FALLING);	
		ultrasonic_flag=1;
	
	}
	else if (ultrasonic_flag==1)
	{
		t2=ICU_TakeReading();
		ultrasonic_flag=2;
	}
}