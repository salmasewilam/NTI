/*
 * Password.c
 *
 * Created: 10/26/23 8:43:36 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\APP\password.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\keypad.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd.h"


data_t data_base[2]={{"AHMED ALI",1234,5060},{"SARA OMAR",5678,1020}};
u8 index=-1;
u32 get_id(void)
{
	u32 id=0;
	u8 key;
	int i=0;
	H_LCD_void_sendString("enter id: ");
	for (;i<4;)
	{
		key=keypad_getkey();
		if (key !='T')
		{
			H_LCD_void_sendData(key);
			id=(id*10)+(key-48);
			i++;
		}
	}
	return id;
}
u32 get_pass(void)
{
	
	u32 pass=0;
	u8 key;
	int i=0;
		H_LCD_void_clear();
		H_LCD_void_sendString("enter pass: ");
	for (;i<4;)
	{
		key=keypad_getkey();
		if (key !='T')
		{
			H_LCD_void_sendData('*');
			pass=(pass*10)+(key-48);
			i++;
		}
	}
	return pass;
}
state_t confirm_id_pass(void)
{
	u32 id=get_id();
	for (u8 i=0;i<DATA_SIZE;i++)
	{
		if (id ==data_base[i].id)
		{
			index=i;
			break;
		}
	}
	if (index==-1) return USER_NOT_FOUND;
	u32 pass=get_pass();
	if (pass == data_base[index].pass)
	{
		return SUCCESS;
	}
	return WRONG_PASS;
}

void app(void)
{
	state_t state;
	state=confirm_id_pass();
	H_LCD_void_clear();
	switch(state)
	{
		case USER_NOT_FOUND: H_LCD_void_sendString("wrong ID"); break;
		case WRONG_PASS: H_LCD_void_sendString("wrong password"); break;
		case SUCCESS: H_LCD_void_sendString("Welcome");
		              H_LCD_void_sendString(data_base[index].name);
					   break;
	}
}