/*
 * lcd.c
 *
 * Created: 10/23/23 10:55:10 AM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd_config.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Dio.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#define F_CPU 8000000
#include <util/delay.h>

#if LCD_MODE==_4_BIT_MODE

u8 LCD_pins[4]={D7,D6,D5,D4};
	
void H_LCD_void_Init(void)
{
	DIO_voidSetPinDirection(RS_PORT,RS,OUTPUT);
	DIO_voidSetPinDirection(EN_PORT,EN,OUTPUT);
	DIO_voidSetPinDirection(PINS_PORT,D4,OUTPUT);
	DIO_voidSetPinDirection(PINS_PORT,D5,OUTPUT);
	DIO_voidSetPinDirection(PINS_PORT,D6,OUTPUT);
	DIO_voidSetPinDirection(PINS_PORT,D7,OUTPUT);
	
	_delay_ms(50);
   DIO_voidSetPinValue(RS_PORT,RS,LOW);
	H_LCD_void_sendCommand(0x02);
	H_LCD_void_sendCommand(0x02);
	H_LCD_void_sendCommand(0x08);
	_delay_ms(1);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x0C);//display on off 0E
	_delay_ms(1);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x01);
	_delay_ms(3);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x06);
	
	
}
void H_LCD_void_sendData(u8 copy_u8data )
{
	DIO_voidSetPinValue(RS_PORT,RS,HIGH);
	H_LCD_void_latchByte(copy_u8data);
	_delay_ms(1);
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	DIO_voidSetPinValue(RS_PORT,RS,LOW);
	H_LCD_void_latchByte(copy_u8command);
	_delay_ms(1);
}

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
	int p=7;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<4;j++)
		{
			DIO_voidSetPinValue(PINS_PORT,LCD_pins[j],READ_BIT(copy_u8Byte,p));
			p--;
		}
		DIO_voidSetPinValue(EN_PORT,EN,HIGH);
		_delay_ms(5);
		DIO_voidSetPinValue(EN_PORT,EN,LOW);
		_delay_ms(5);
	}
}
#elif LCD_MODE == _8_BIT_MODE
u8 LCD_pins[8]={D7,D6,D5,D4,D3,D2,D1,D0};

void H_LCD_void_Init(void)
{
	DIO_voidSetPinDirection(RS_PORT,RS,OUTPUT);
	DIO_voidSetPinDirection(EN_PORT,EN,OUTPUT);
	for (int i=0;i<8;i++)
	{
		DIO_voidSetPinDirection(PINS_PORT,LCD_pins[i],OUTPUT);
	}
	_delay_ms(50);
	DIO_voidSetPinValue(RS_PORT,RS,LOW);
	H_LCD_void_sendCommand(0x38);
	_delay_ms(1);
	H_LCD_void_sendCommand(0x0C);//display on off 0E
	_delay_ms(1);
	H_LCD_void_sendCommand(0x01);
	_delay_ms(3);
	H_LCD_void_sendCommand(0x06);

}
void H_LCD_void_sendData(u8 copy_u8data )
{
	DIO_voidSetPinValue(RS_PORT,RS,HIGH);
	H_LCD_void_latchByte(copy_u8data);
	_delay_ms(1);
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	DIO_voidSetPinValue(RS_PORT,RS,LOW);
	H_LCD_void_latchByte(copy_u8command);
	_delay_ms(1);
}

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
	    DIO_voidSetPortValue(PINS_PORT,copy_u8Byte);
		DIO_voidSetPinValue(EN_PORT,EN,HIGH);
		_delay_ms(5);
		DIO_voidSetPinValue(EN_PORT,EN,LOW);
		_delay_ms(5);
	}
}
#endif
void H_LCD_void_sendString(const s8 * pstr)
{
	for (int i=0;pstr[i];i++)
	{
		H_LCD_void_sendData(pstr[i]);
	}
}
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
	u8 arr[20]={0};
	int i;
	if (copy_s32Num==0)
	{
		H_LCD_void_sendData('0');
		return;
	}
	else if (copy_s32Num<0)
	{
		H_LCD_void_sendData('-');
		copy_s32Num=copy_s32Num*-1;
	}
	for (i=0;copy_s32Num>0;)
	{
		arr[i]=copy_s32Num%10;
		copy_s32Num=copy_s32Num/10;
		i++;
	}
	
	for(;i>0;)
	{
		i--;
		H_LCD_void_sendData(arr[i]+'0');
	}
}

void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	    // Select CGRAM location
	    copy_u8charCode &= 0x07;
	    H_LCD_void_sendCommand(0x40 | (copy_u8charCode << 3));

	    // Load the custom character pattern into CGRAM
	    for (u8 i = 0; i < 8; i++) {
		    H_LCD_void_sendData(ArrPattern[i]);
	    }
}
void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{
	H_LCD_void_sendData(copy_u8charCode);
}

void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	if (copy_u8Row==0)
	{
		H_LCD_void_sendCommand(0x80|copy_u8Col);
	}
	else if (copy_u8Row ==1)
	{
		H_LCD_void_sendCommand(0x80+0x40+copy_u8Col);
	}
}

void H_LCD_void_clear(void)
{
	H_LCD_void_sendCommand(0x01);
	_delay_ms(1);
}