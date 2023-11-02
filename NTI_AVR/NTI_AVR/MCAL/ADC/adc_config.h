/*
 * adc_config.h
 *
 * Created: 10/24/23 9:51:07 AM
 *  Author: USER
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\ADC\adc.h"


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

#define PRESCALER ADC_SCALER_8
#define VREF  VREF_AREF
#define ADJUST R_ADJUST




#endif /* ADC_CONFIG_H_ */