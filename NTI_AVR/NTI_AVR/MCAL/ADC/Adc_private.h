/*
 * Adc_private.h
 *
 * Created: 10/30/23 8:29:06 PM
 *  Author: USER
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

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


#endif /* ADC_PRIVATE_H_ */