/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 8000000
#include <util/delay.h>

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\7SEG\sevensegment.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\EXT_INT\EXTINT.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\ADC\adc.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\UART\uart_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\SPI\SPI_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"

void f1(u8 *str)
{


}
void f2(void)
{
	DIO_voidSetPinDirection(ptrC,0,1);
	DIO_voidSetPinValue(ptrC,0,1);
}
void f3(void)
{

}

int main(void)
{
	H_LCD_void_Init();
	sevseg_init();
	keypad_init();
	ADC_Init();
	//Timer1_Init(Timer1_Normal_Mode,Timer1_Scaler_8,Timer1_Disconnected,Timer1_Disconnected);
	
	//UltraSonic_init();
	//Timer0_Init(Timer0_Fast_PWM_Mode,Timer0_Scaler_64,Timer0_Set_on_compare);
	//Timer1_Init(Timer1_Normal_Mode,Timer1_Scaler_8,Timer1_Disconnected,Timer1_Disconnected);
  SPI_init_bits init={F_4,SAMPLE,LOW_IDLE,MASTER,MSB,ENABLED,POLLING};
     //Uart_Init();
	 // SPI_init(&init);
	 I2C_init(I2C_prescaler_4,SCL_100);

   // DIO_voidSetPinDirection(ptrB,5,1);
  //DIO_voidSetPinDirection(ptrB,6,0);
 // DIO_voidSetPinDirection(ptrB,7,1);

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
	//Timer0_EnableInt(Timer0_Compare_Match);
	//Timer1_ICU_InterruptEnable();
	//Timer1_OVF_InterruptEnable();
	//sei();
		  u8 data2, data=0;
		  u16 d;
	I2C_sendStart();
	
while (1) {
	I2C_sendByte(0x41);
	I2C_recieveByte_ACK(&data2);
	H_LCD_void_sendData(data2);
	data++;
	if (data==5)
	I2C_sendStop();

		}
		
}
