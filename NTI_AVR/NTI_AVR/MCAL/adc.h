/*
 * adc.h
 *
 * Created: 10/24/23 9:38:23 AM
 *  Author: USER
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\stdtypes.h"

#define ADMUX (*(volatile u8*) 0x27)
#define ADCSRA (*(volatile u8*) 0x26)
#define ADCL (*(volatile u8*) 0x24)
#define ADCH (*(volatile u8*) 0x25)
#define ADC (*(volatile u16*)0x24)
#define SFIOR (*(volatile u8*) 0x50)

#define ADLAR 5
#define ADEN  7

#define ADSC  6
#define ADATE  5
#define ADIF  4
#define ADIE  3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0

#define ADC_SCALER_2 1
#define ADC_SCALER_4 2
#define ADC_SCALER_8 3
#define ADC_SCALER_16 4
#define ADC_SCALER_32 5
#define ADC_SCALER_64 6
#define ADC_SCALER_128 7

#define VREF_AREF 0
#define VREF_AVCC 1
#define VREF_256 3

#define R_ADJUST 0
#define L_ADJUST 1

typedef enum {ADC0=0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7}CHANNELS;
typedef enum {FREE_RUNNING=0,Analog_Comparator,External_Interrupt}TRIG;
void ADC_Init(void) ;
u8 ADC_getDigitalValueSynchNonBlocking (u16 * p);

#endif /* ADC_H_ */