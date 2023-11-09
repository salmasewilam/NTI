/*
 * Dc_Motor.c
 *
 * Created: 11/08/23 12:41:17 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\DC Motor\DcMotor.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\DC Motor\DC Motor_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
void DC_Motor_Init(MOTOR_t m)
{
	switch (m)
	{
		case M1: DIO_voidSetPinDirection(ptrB,3,OUTPUT);
		DIO_voidSetPinDirection(IN1_PORT,IN1,OUTPUT);
		DIO_voidSetPinDirection(IN2_PORT,IN2,OUTPUT);
		Timer0_Init(Timer0_Fast_PWM_Mode,Timer0_Scaler_8,Timer0_Set_on_compare);
		break;
		case M2: DIO_voidSetPinDirection(ptrD,4,OUTPUT);
		DIO_voidSetPinDirection(ptrD,2,OUTPUT);
		Timer1_Init(Timer1_Fast_PWM_8bit_Mode,Timer1_Scaler_8,Timer1_Clear_on_compare,Timer1_Disconnected);
		break;
		case M3: DIO_voidSetPinDirection(ptrD,5,OUTPUT);
		DIO_voidSetPinDirection(ptrD,3,OUTPUT);
		Timer1_Init(Timer1_Fast_PWM_8bit_Mode,Timer1_Scaler_8,Timer1_Disconnected,Timer1_Clear_on_compare);
		break;
	}
}
void DC_Motor_ON(MOTOR_t m,MOTOR_DIRECTION_t d,u8 duty)
{
	switch (m)
	{
		case M1: setFastPWM(duty);
		switch(d)
		{
			case CLOCKWISE: DIO_voidSetPinValue(IN1_PORT,IN1,HIGH);
			DIO_voidSetPinValue(IN2_PORT,IN2,LOW);
			break;
			case COUNTER_CLOCK_WISE: DIO_voidSetPinValue(IN1_PORT,IN1,LOW);
			DIO_voidSetPinValue(IN2_PORT,IN2,HIGH);
			break;
		}
		break;
		case M2: 
		break;
		case M3:
		break;
	}
}
void DC_Motor_OFF(MOTOR_t m)
{
	switch (m)
	{
		case M1: setFastPWM(0);
		break;
		case M2:
		break;
		case M3:
		break;
	}
}