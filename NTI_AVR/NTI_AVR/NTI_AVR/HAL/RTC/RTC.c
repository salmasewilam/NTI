/*
 * RTC.c
 *
 * Created: 11/03/23 12:35:14 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\RTC\RTC.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\RTC\RTC_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"

void RTC_Init(void)
{
	I2C_init(I2C_prescaler_1,SCL_100);
	
}
static u8 decimal_BCD(u8 decimal)
{
	unsigned int bcd = 0;
	unsigned int shift = 0;

	while (decimal > 0) {
		unsigned int digit = decimal % 10;
		bcd += (digit << shift);
		shift += 4;
		decimal /= 10;
	}
	return bcd;
}
static u8 BCD_to_Decimal(u8 bcd) {
	// Extract the tens and ones digits from the BCD byte
	u8 tens = (bcd >> 4) & 0x0F;
	u8 ones = bcd & 0x0F;

	// Convert to decimal and return the result
	u8 decimal = (tens * 10) + ones;
	return decimal;
}
time_t RTC_getTime(void)
{
	u8 data,status;
	time_t t;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=MT_START_COND_ACK) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_ACK) return;
	I2C_sendByte(SECONDS_REG);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=MT_REPEATED_START_ACK) return;
	I2C_sendByte(RTC_ADDRESS_READ);
	I2C_getStatus(&status);
	if (status !=MR_SLA_R_ACK) return;
	I2C_recieveByte_ACK(&data);
	t.seconds=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	I2C_recieveByte_ACK(&data);
	t.Minutes=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	I2C_RECIEVENoACK(&data);
	I2C_getStatus(&status);
	if (status != MR_DATA_RECIEVED_NOT_ACK) return;
	if (READ_BIT(data,6)==0)
	{
		t.Hours=BCD_to_Decimal(data);
		t.am_pm=NONE;
	}
	else
	{
		if (READ_BIT(data,5)==0)
		{ t.am_pm=AM;
		}
		else 
		{t.am_pm=PM;}
		data&=0x1F;
		t.Hours=BCD_to_Decimal(data);
	}
	I2C_sendStop();
	return t;
}
void RTC_settime (time_t* t)
{
	I2C_sendStart();
	u8 status,data;
	I2C_getStatus(&status);
	if (status !=MT_START_COND_ACK) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_ACK) return;
	I2C_sendByte(SECONDS_REG);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	data=decimal_BCD(t->seconds);
	data|=0;
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	data=decimal_BCD(t->Minutes);
	data|=0;
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	data=decimal_BCD(t->Hours);
	if (t->am_pm==NONE)
	{
		data&=0x3F;
	}
	else if (t->am_pm==PM)
	{
	data|=(1<<6)|(1<<5);
		
	}
	else if (t->am_pm==AM)
	{
		data|=(1<<6);
		data&=0x5F;
	}
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	I2C_sendStop();
}

void RTC_setdate (date_t* t)
{
		I2C_sendStart();
		u8 status,data;
		I2C_getStatus(&status);
		if (status !=MT_START_COND_ACK) return;
		I2C_sendByte(RTC_ADDRESS_WRITE);
		I2C_getStatus(&status);
		if (status !=MT_SLA_W_ACK) return;
		//step 5 : send rest of Byte address as data A7 .....A0
		I2C_sendByte(DAY_REG);
		//step 6 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
	
		//step 7 : send Byte to be written
		data=decimal_BCD(t->day);
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
		//step 6 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->date);
		data|=0;
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->month);
		data|=0;
		I2C_sendByte(data);
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->year);
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_DATA_TRANSMITED_ACK) return;
		//step 9 : send stop
		I2C_sendStop();
}
date_t RTC_getdate(void)
{
	u8 data,status;
	date_t d;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=MT_START_COND_ACK) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_ACK) return;
	I2C_sendByte(DAY_REG);
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=MT_REPEATED_START_ACK) return;
	I2C_sendByte(RTC_ADDRESS_READ);
	I2C_getStatus(&status);
	if (status !=MR_SLA_R_ACK) return;
	I2C_recieveByte_ACK(&data);
	d.day=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	I2C_recieveByte_ACK(&data);
	d.date=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	I2C_recieveByte_ACK(&data);
	d.month=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	I2C_RECIEVENoACK(&data);
	d.year=BCD_to_Decimal(data);
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_NOT_ACK) return;
	I2C_sendStop();
	return d;
}

void RTC_print_date_time (void)
{
	time_t t2;
	t2=RTC_getTime();
	H_LCD_void_sendString("Time:");
	H_LCD_void_sendIntNum((u32)t2.Hours);
	H_LCD_void_sendData('-');
	H_LCD_void_sendIntNum((u32)t2.Minutes);
	H_LCD_void_sendData('-');
	H_LCD_void_sendIntNum((u32)t2.seconds);
	if (t2.am_pm==AM) H_LCD_void_sendString(" AM");
	else if (t2.am_pm==PM) H_LCD_void_sendString(" PM");
	else H_LCD_void_sendString(" 24 format");
	date_t d2;
	d2=RTC_getdate();
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendString("Date:");
	H_LCD_void_sendIntNum((u32)d2.date);
	H_LCD_void_sendData('-');
	H_LCD_void_sendIntNum((u32)d2.month);
	H_LCD_void_sendData('-');
	H_LCD_void_sendIntNum((u32)d2.year);
}