/*
 * small_OS.c
 *
 * Created: 11/08/23 9:28:34 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Small OS\SmallOS_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Small OS\small_os.h"


static void task1_fun(void)
{
	DIO_Toggle_pin(RED_LED_PORT,RED_LED_PIN);
}
static void task2_fun(void)
{
	if (DIO_GetPinValue(PB_PORT,PB_PIN)==LOW)
	{
		DIO_Toggle_pin(BLUE_LED_PORT,BLUE_LED_PIN);
	}
}
static void task3_fun(void)
{
		DIO_Toggle_pin(GREEN_LED_PORT,GREEN_LED_PIN);
}
static task_t tasks[3]={{60,task1_fun},{30,task2_fun},{180,task3_fun}};
static void sechulder(void)
{
	static volatile  u32 c=0;
	//Timer0_setTCNT_value(250);
	c++;
	for (int i=0;i<3;i++)
	{
		if (c%tasks[i].periodicity==0)
		{
			tasks[i].pfun();
		}
	}
	if (c== 180) c=0;
}

void small_os_init(void)
{
	DIO_voidSetPinDirection(RED_LED_PORT,RED_LED_PIN,OUTPUT);
	DIO_voidSetPinDirection(BLUE_LED_PORT,BLUE_LED_PIN,OUTPUT);
	DIO_voidSetPinDirection(GREEN_LED_PORT,GREEN_LED_PIN,OUTPUT);
	DIO_voidSetPinDirection(PB_PORT,PB_PIN,INPUT);
	DIO_voidSetPinValue(PB_PORT,PB_PORT,OUTPUT); //enable pullup
	Timer0_Init(Timer0_Normal_Mode,Timer0_Scaler_1024,Timer0_Disconnected);
	Timer0_setCallBack(Timer0_OverFlow,sechulder);
	Timer0_EnableInt(Timer0_OverFlow);
	enable();
}