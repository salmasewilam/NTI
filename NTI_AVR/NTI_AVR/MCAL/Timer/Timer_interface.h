/*
 * Timer_interface.h
 *
 * Created: 10/27/23 12:54:57 PM
 *  Author: USER
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"


typedef enum{Timer0_Stopped=0,
	Timer0_Scaler_1,
	Timer0_Scaler_8,
	Timer0_Scaler_64,
	Timer0_Scaler_256,
	Timer0_Scaler_1024,
	External_Clk_Falling,
	External_Clk_Rising}Timer0_prescaler;
	
typedef enum{Timer0_Normal_Mode,Timer0_PhaseCorrect_PWM_Mode,Timer0_CTC_Mode,Timer0_Fast_PWM_Mode}Timer0_modes;

typedef enum{Timer0_Disconnected,Timer0_Toggle_on_compare,Timer0_Clear_on_compare,Timer0_Set_on_compare}Timer0_OCR0_modes;
typedef enum{Timer0_Compare_Match,Timer0_OverFlow}Timer0_Interrupt_Source;

void Timer0_Init(Timer0_modes mode,Timer0_prescaler prescaler,Timer0_OCR0_modes ocrmode);
void Timer0_start(Timer0_prescaler prescaler);
void Timer0_stop(void);
void setFastPWM(u8 duty);
void setphaseCorrectPWM(u8 duty);
u32 Timer0_GetCounts(void);
void Timer0_setDelayTimeMilliSec(u32 time);
void Timer0_EnableInt(Timer0_Interrupt_Source source);
void Timer0_DisableInt(Timer0_Interrupt_Source source);
void Timer0_setCallBack(Timer0_Interrupt_Source source,void (*p)(void));

/************Timer1************/
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
#define TCNT1       (*(volatile unsigned short*)0x4C)

void Timer1_Init(Timer1_modes mode,Timer0_prescaler prescaler,OCR1_modes OCRA, OCR1_modes OCRB);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));

#endif /* TIMER_INTERFACE_H_ */