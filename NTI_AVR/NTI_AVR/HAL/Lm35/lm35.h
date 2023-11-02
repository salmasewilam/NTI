/*
 * lm35.h
 *
 * Created: 11/02/23 6:34:48 PM
 *  Author: USER
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"

#define lm_pin 0
#define lm_port ptrA

void lm35_init(void);
u16 lm35_gettemp(void);

#endif /* LM35_H_ */