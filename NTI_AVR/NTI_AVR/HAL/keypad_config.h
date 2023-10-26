/*
 * keypad_config.h
 *
 * Created: 10/22/23 8:18:37 PM
 *  Author: USER
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define ROWS 4
#define COLS 4

#define PORT_OUT ptrB
#define PORT_IN ptrD

#define FIRST_OUTPUT 4 //nti 5 == mini 4
#define SECOND_OUTPUT 5 //nti 4 == mini 5
#define THIRD_OUTPUT 6//nti 3 == mini 6
#define FORTH_OUTPUT 7 //nti 2 == mini 7

#define FIRST_INPUT 2 //nti 7 == mini 2
#define SECOND_INPUT 3 //nti 6 == mini 3
#define THIRD_INPUT 4 //nti 5 == mini 4
#define FORTH_INPUT 5 ////nti 3 == mini 5


#endif /* KEYPAD_CONFIG_H_ */