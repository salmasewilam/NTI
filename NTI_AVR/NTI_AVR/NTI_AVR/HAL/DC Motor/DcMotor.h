/*
 * DcMotor.h
 *
 * Created: 11/08/23 12:41:31 PM
 *  Author: USER
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"

typedef enum {
	M1,
	M2,
	M3,
	MOTOR_NUMBERS
}MOTOR_t;
typedef enum {
	CLOCKWISE,
	COUNTER_CLOCK_WISE
}MOTOR_DIRECTION_t;

void DC_Motor_Init(MOTOR_t m);
void DC_Motor_ON(MOTOR_t m,MOTOR_DIRECTION_t d,u8 duty);
void DC_Motor_OFF(MOTOR_t m);


#endif /* DCMOTOR_H_ */