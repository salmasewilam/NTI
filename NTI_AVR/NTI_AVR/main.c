/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 8000000
#include <util/delay.h>

#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Dio.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\sevensegment.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\keypad.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\EXTINT.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\adc.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\APP\password.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Timer_interface.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\uart_interface.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\SPI_interface.h"
extern u32 c;

u16 data;
u8 flag=0;
void f1(u8 *str)
{
	static int i=0;
	str[i]=UDR;
	i++;
}
void f2(void)
{
	DIO_voidSetPinDirection(ptrC,0,1);
	DIO_voidSetPinValue(ptrC,0,1);
}
void f3(void)
{
	data=ADC;
	flag=1;
	SET_BIT(ADCSRA,ADSC);
	
}

int main(void)
{
	H_LCD_void_Init();
	sevseg_init();
	keypad_init();
//	ADC_Init();
//	Timer0_Init(Fast_PWM_Mode,Timer0_Scaler_1024,Set_on_compare);
//	Timer1_Init(Timer1_Normal_Mode,Timer1_Scaler_1024,Timer1_Disconnected,Timer1_Disconnected);
SPI_init_bits init={F_4,SAMPLE,LOW_IDLE,MASTER,MSB,ENABLED,POLLING};
     Uart_Init();
	 SPI_init(&init);

	DIO_voidSetPinDirection(ptrA,6,1);
	DIO_voidSetPinDirection(ptrD,0,0);

	u8 smiley[8] = {
		0b00000,
		0b10001,
		0b00000,
		0b00000,
		0b10001,
		0b01110,
		0b00000,
		0b00000,
	};
	u8 s[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b10101,
		0b10101,
		0b11111,
		0b00000,
		0b00000
	};
	u8 l[8] = {
		0b00000,
		0b00000,
		0b00100,
		0b00100,
		0b00100,
		0b11111,
		0b00000,
		0b00000
	};
	u8 m[8] = {
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b11100,
		 0b10111,
		 0b11100,
		 0b00000
	};
	u8 a[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00011,
		0b10010,
		0b11110
	};
	
	//Uart_RX_SetCallBack(ReciveDataNoBlock_callback);

//Uart_RX_InterruptEnable();

	//enable();
	//sei();
		  u8 data2;
	u8 data[10];
		
while (1) {
	data2=ReciveString_10char(data);
	if (data2==1)
	
	{
		//H_LCD_void_sendString(data);
	}

		}
		
}
