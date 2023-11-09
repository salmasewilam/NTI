/*
 * NTI_AVR.c
 *
 * Created: 10/21/23 10:23:30 AM
 * Author : USER
 */ 

#define F_CPU 16000000
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
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\WatchDog\watchdog.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\DC Motor\DcMotor.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\APP\Login System\LoginSystem.h"
void f1(u8 *str)
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
  //SPI_init_bits init={F_4,SAMPLE,LOW_IDLE,MASTER,MSB,ENABLED,POLLING};
    // Uart_Init();
	 // SPI_init(&init);
	// I2C_init(I2C_prescaler_16,SCL_100);
	 //EEPROM_Init();
	//coolingsystem_init();
 //DIO_voidSetPinDirection(ptrD,0,1);
// DIO_voidSetPinDirection(ptrD,1,0);

// fingerprint_init();

 //H_LCD_void_sendData('F');

    
 // DIO_voidSetPinDirection(ptrB,7,1);	
	//Uart_RX_SetCallBack(ReciveDataNoBlock_callback);

//Uart_RX_InterruptEnable();

	//enable();
	//Timer0_EnableInt(Timer0_Compare_Match);
	//Timer1_ICU_InterruptEnable();
	//Timer1_OVF_InterruptEnable();
	//sei();
	/*FINGERP_ERROR_t status;
	
status=FingerPS_emptyLibrary();
LCD_writeHex(status);
H_LCD_void_sendData('-');


status =FingerPS_handShake();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_genImg();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_convertImg2CharFile(0x01);
LCD_writeHex(status);
H_LCD_void_sendData('-');
_delay_ms(500);
status =FingerPS_genImg();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_convertImg2CharFile(0x02);
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_genTemplate();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_strTemplate(0x01,0x0002);
LCD_writeHex(status);
H_LCD_void_sendData('-');
_delay_ms(500);

u8 id=9;
status =FingerPS_genImg();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_convertImg2CharFile(0x01);
LCD_writeHex(status);
H_LCD_void_sendData('-');
_delay_ms(500);
status =FingerPS_genImg();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_convertImg2CharFile(0x02);
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_genTemplate();
LCD_writeHex(status);
H_LCD_void_sendData('-');
status =FingerPS_searchFinger(0x01,0x00,0x05,&id);
LCD_writeHex(status);
H_LCD_void_sendData('-');
H_LCD_void_sendString("ID");
LCD_writeHex(id);
*/


while (1) {




		}
		
}
