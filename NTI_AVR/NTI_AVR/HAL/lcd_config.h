/*
 * lcd_config.h
 *
 * Created: 10/23/23 10:46:24 AM
 *  Author: USER
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RS 3 //nti 3== mini 1
#define EN 2 //nti 2 ==mini 2
#define D4 0 //nti0 ==mini 3
#define D5 1 //nti1 ==mini 4
#define D6 2 //nti2 == mini5
#define D7 4 //nti4 == mini6

#define RS_PORT ptrA
#define EN_PORT ptrA

#define PINS_PORT ptrB //nti B == mini A

#define D4_PORT ptrB //nti B =mini A
#define D5_PORT ptrA
#define D6_PORT ptrA
#define D7_PORT ptrA

#define _4_BIT_MODE 0
#define _8_BIT_MODE 1

#define LCD_MODE _4_BIT_MODE



#endif /* LCD_CONFIG_H_ */