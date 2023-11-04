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
	if (status !=TWI_MT_START) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_sendByte(SECONDS_REG);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=TWI_MR_SLA_R_ACK) return;
	I2C_sendByte(RTC_ADDRESS_READ);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_recieveByte_ACK(&data);
	t.seconds=BCD_to_Decimal(data);
	I2C_recieveByte_ACK(&data);
	t.Minutes=BCD_to_Decimal(data);
	I2C_RECIEVENoACK(&data);
	t.Hours=BCD_to_Decimal(data);
	I2C_sendStop();
	return t;
}
void RTC_settime (time_t* t)
{
	I2C_sendStart();
	u8 status,data;
	I2C_getStatus(&status);
	if (status !=TWI_MT_START) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_sendByte(SECONDS_REG);
	I2C_getStatus(&status);
	if (status !=TWI_MT_DATA_ACK) return;
	data=decimal_BCD(t->seconds);
	data|=0;
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=TWI_MT_DATA_ACK) return;
	data=decimal_BCD(t->Minutes);
	data|=0;
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=TWI_MT_DATA_ACK) return;
	data=decimal_BCD(t->Hours);
	if (t->am_pm==NONE)
	{
		data|=0;
	}
	else if (t->am_pm==PM)
	{
	data|=(1<<6);
	data|=(t->am_pm)<<5;
	}
	else if (t->am_pm==AM)
	{
		data|=(1<<6);
		data&=0x1F;
	}
	I2C_sendByte(data);
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_NOT_ACK) return;
	I2C_sendStop();
}
void RTC_setdate (date_t* t)
{
		I2C_sendStart();
		u8 status,data;
		I2C_getStatus(&status);
		if (status !=TWI_MT_START) return;
		//step 3 : send address
		I2C_sendByte(RTC_ADDRESS_WRITE);
		//step 4 : check status TWI_MT_SLA_W_ACK
		I2C_getStatus(&status);
		if (status !=TWI_MT_SLA_W_ACK) return;
		//step 5 : send rest of Byte address as data A7 .....A0
		I2C_sendByte(DAY_REG);
		//step 6 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=TWI_MT_DATA_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->day);
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=TWI_MT_DATA_ACK) return;
		//step 6 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=TWI_MT_DATA_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->date);
		data|=0;
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=TWI_MT_DATA_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->month);
		data|=0;
		I2C_sendByte(data);
		I2C_getStatus(&status);
		if (status !=TWI_MT_DATA_ACK) return;
		//step 7 : send Byte to be written
		data=decimal_BCD(t->year);
		I2C_sendByte(data);
		//step 8 : check status TWI_MT_DATA_ACK
		I2C_getStatus(&status);
		if (status !=MT_SLA_W_NOT_ACK) return;
		//step 9 : send stop
		I2C_sendStop();
}
date_t RTC_getdate(void)
{
	u8 data,status;
	date_t d;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=TWI_MT_START) return;
	I2C_sendByte(RTC_ADDRESS_WRITE);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_sendByte(DAY_REG);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_sendStart();
	I2C_getStatus(&status);
	if (status !=TWI_MR_SLA_R_ACK) return;
	I2C_sendByte(RTC_ADDRESS_READ);
	I2C_getStatus(&status);
	if (status !=TWI_MT_SLA_W_ACK) return;
	I2C_recieveByte_ACK(&data);
	d.day=BCD_to_Decimal(data);
	I2C_recieveByte_ACK(&data);
	d.date=BCD_to_Decimal(data);
	I2C_recieveByte_ACK(&data);
	d.month=BCD_to_Decimal(data);
	I2C_RECIEVENoACK(&data);
	d.year=BCD_to_Decimal(data);
	I2C_sendStop();
	return d;
}