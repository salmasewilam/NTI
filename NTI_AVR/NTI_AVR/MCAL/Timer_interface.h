/*
 * Timer_interface.h
 *
 * Created: 10/27/23 12:54:57 PM
 *  Author: USER
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\stdtypes.h"

/*
typedef union {
	struct
	{
		unsigned char PIN0:1;
		unsigned char PIN1:1;
		unsigned char PIN2:1;
		unsigned char PIN3:1;
		unsigned char PIN4:1;
		unsigned char PIN5:1;
		unsigned char PIN6:1;
		unsigned char PIN7:1;
		
	};
	unsigned char reg;
	}registerpins_t;

typedef struct {
registerpins_t	TCCR0; //53
registerpins_t TCNT0;  //52
registerpins_t OCR0; //5C
registerpins_t TIMSK;// 59
	}registers_t;
*/
/* Timer 0 */
#define TCNT0   (*(volatile u8*)0x52)
#define TCCR0   (*(volatile u8*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TWCR    (*(volatile u8*)0x56)
#define SPMCR   (*(volatile u8*)0x57)
#define TIFR    (*(volatile u8*)0x58)
#define TIMSK   (*(volatile u8*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define OCR0    (*(volatile u8*)0x5C)

typedef enum{Timer0_Stopped=0,
	Timer0_Scaler_1,
	Timer0_Scaler_8,
	Timer0_Scaler_64,
	Timer0_Scaler_256,
	Timer0_Scaler_1024,
	External_Clk_Falling,
	External_Clk_Rising}Timer0_prescaler;
	
typedef enum{Normal_Mode,PhaseCorrect_PWM_Mode,CTC_Mode,Fast_PWM_Mode}Timer0_modes;

typedef enum{Disconnected,Toggle_on_compare,Clear_on_compare,Set_on_compare}OCR0_modes;
//typedef enum{Disconnected,Reserved,Clear_on_compare,Set_on_compare}OCR0_FASTPWM_modes;
//typedef enum{Disconnected,Reserved,Clear_on_compare,Set_on_compare}OCR0_PHASECORRECTPWM_modes;
typedef enum{Compare_Match,OverFlow}Interrupt_Source;

#define PWM_INVERTING 0
#define PWM_NON_INVERTING 1
#define PWM_Mode PWM_INVERTING

/*****************Timer1*******/

#define ICR1      (*(volatile unsigned short*)0x46)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1B     (*(volatile unsigned short*)0x48)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A     (*(volatile unsigned short*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)
#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1A        (*(volatile unsigned char*)0x4F)

#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)


/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

typedef enum{Timer1_Stopped=0,
	Timer1_Scaler_1,
	Timer1_Scaler_8,
	Timer1_Scaler_64,
	Timer1_Scaler_256,
	Timer1_Scaler_1024,
	Timer1_External_Clk_Falling,
    Timer1_External_Clk_Rising}Timer1_prescaler;

typedef enum{Timer1_Normal_Mode=0,
	Timer1_PhaseCorrect_PWM_8bit_Mode,
	Timer1_PhaseCorrect_PWM_9bit_Mode,
	Timer1_PhaseCorrect_PWM_10bit_Mode,	
	Timer1_CTC_OCRA1_Mode,
	Timer1_Fast_PWM_8bit_Mode,
	Timer1_Fast_PWM_9bit_Mode,
	Timer1_Fast_PWM_10bit_Mode,
	Timer1_Phase_Frequency_Correct_ICR1_MODE,
	Timer1_Phase_Frequency_Correct_OCR1A_MODE,
	Timer1_PWM_PhaseCorrect_ICR1,
	Timer1_PWM_PhaseCorrect_OCR1A,
	Timer1_CTC_ICR1_MODE,
	Timer1_RESERVED,
	Timer1_Fast_PWM_ICR1_MODE,
	Timer1_Fast_PWM_OCR1A_MODE
	}Timer1_modes;

typedef enum{Timer1_Disconnected,Timer1_Toggle_on_compare,Timer1_Clear_on_compare,Timer1_Set_on_compare}OCR1_modes;

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;

#endif /* TIMER_INTERFACE_H_ */