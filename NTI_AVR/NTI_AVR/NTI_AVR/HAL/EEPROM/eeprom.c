/*
 * eeprom.c
 *
 * Created: 10/31/23 3:04:11 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\EEPROM\EEPROM_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
void EEPROM_Init(void)
{
	I2C_init(I2C_prescaler_16,SCL_100);
}

void eeprom_WriteByte(u8 data , u8 address)
{
	//step 1 : send Start
	I2C_sendStart();
	//step 2 : check status if not Start Success return false
	u8 status;
	I2C_getStatus(&status);
	if (status !=MT_START_COND_ACK) return;
	//step 3 : send address 1010 + E A9 A8 + W
	I2C_sendByte(EEPROM_ADDRESS_Write);
	//step 4 : check status TWI_MT_SLA_W_ACK
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_ACK) return;
	//step 5 : send rest of Byte address as data A7 .....A0
	I2C_sendByte(address);
	//step 6 : check status TWI_MT_DATA_ACK
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	//step 7 : send Byte to be written
	I2C_sendByte(data);
	//step 8 : check status TWI_MT_DATA_ACK
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	//step 9 : send stop
	I2C_sendStop();
}
void eeprom_ReadByte(u8 address , u8 *data)
{
	//step 1 : send Start
	I2C_sendStart();
	//step 2 : check status if not Start Success return false
	u8 status;
	I2C_getStatus(&status);
	if (status !=MT_START_COND_ACK) return;
	//step 3 : send address 1010 + E A9 A8 + W
	I2C_sendByte(EEPROM_ADDRESS_Write);
	//step 4 : check status TWI_MT_SLA_W_ACK
	I2C_getStatus(&status);
	if (status !=MT_SLA_W_ACK) return;
	//step 5 : send rest of Byte address as data A7 .....A0
	I2C_sendByte(address);
	//step 6 : check status TWI_MT_DATA_ACK
	I2C_getStatus(&status);
	if (status !=MT_DATA_TRANSMITED_ACK) return;
	//step 7 : send Repeated Start
	I2C_sendStart();	
	//step 8 : check status
	I2C_getStatus(&status);	
	if (status !=MT_REPEATED_START_ACK) return;
	//step 9 : send address 1010 + 000 + R
	I2C_sendByte(EEPROM_ADDRESS_Read);
	//step 10 : check status TWI_MR_SLA_R_ACK
	I2C_getStatus(&status);
	if (status !=MR_SLA_R_ACK) return;
	//step 11 : read data
	I2C_recieveByte_ACK(data);
	//step 12 : check status TWI_MR_DATA_ACK
	I2C_getStatus(&status);
	if (status !=MR_DATA_RECIEVED_ACK) return;
	//step 13 : send Stop
	I2C_sendStop();
}
