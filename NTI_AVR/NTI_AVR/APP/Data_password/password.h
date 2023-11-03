/*
 * password.h
 *
 * Created: 10/26/23 8:43:55 PM
 *  Author: USER
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"

typedef struct  
{
	u8 name[20];
	u32 id;
	u32 pass;
}data_t;

typedef enum {USER_NOT_FOUND,WRONG_PASS,SUCCESS}state_t;
#define DATA_SIZE  2

u32 get_id(void);
u32 get_pass(void);
state_t confirm_id_pass(void);
void app(void);
#endif /* PASSWORD_H_ */