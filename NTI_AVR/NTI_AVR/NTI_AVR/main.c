/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 8000000
#include <util/delay.h>

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\7SEG\sevensegment.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\KeyPad\keypad.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\EXT_INT\EXTINT.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\ADC\adc.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\UART\uart_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\SPI\SPI_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\UltraSonic\ultrasonic.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\EEPROM\EEPROM_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\RTC\RTC.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\FingerPrint\fingerprint.h"
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
	 //I2C_init(I2C_prescaler_4,SCL_100);
	// EEPROM_Init();
	//coolingsystem_init();
 fingerprint_init();

//	RTC_Init();
    
 // DIO_voidSetPinDirection(ptrB,7,1);	
	//Uart_RX_SetCallBack(ReciveDataNoBlock_callback);

//Uart_RX_InterruptEnable();

	//enable();
	//Timer0_EnableInt(Timer0_Compare_Match);
	//Timer1_ICU_InterruptEnable();
	//Timer1_OVF_InterruptEnable();
	//sei();

	FINGERP_ERROR_t e=	FingerPS_handShake();
	if (e==0) H_LCD_void_sendData('S');
	else H_LCD_void_sendData('F');

while (1) {


		}
		
}
