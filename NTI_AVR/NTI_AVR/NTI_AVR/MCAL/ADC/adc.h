/*
 * adc.h
 *
 * Created: 10/24/23 9:38:23 AM
 *  Author: USER
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"




typedef enum {ADC_CH_0=0,ADC_CH_1,ADC_CH_2,ADC_CH_3,ADC_CH_4,ADC_CH_5,ADC_CH_6,ADC_CH_7}CHANNELS;
typedef enum {FREE_RUNNING=0,Analog_Comparator,External_Interrupt}TRIG;
	
void ADC_Init(void) ;
u16 ADC_getDigitalValueSynchBlocking (CHANNELS ch);
u8 ADC_getDigitalValueSynchNonBlocking (u16 * p);
void ADC_SetCallBack(void(*p)(void));
u16 ADC_getreading(void);

#endif /* ADC_H_ */