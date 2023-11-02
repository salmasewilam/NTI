/*
 * eeprom.c
 *
 * Created: 10/31/23 3:04:11 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\EEPROM\EEPROM_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"
/*
void EEPROM_Init()
{
	I2C_init(I2C_prescaler_16,SCL_100);
}
void eeprom_WriteByte(u8 data , u8 address)
{
	//step 1 : send Start
	//step 2 : check status if not Start Success return false
	//step 3 : send address 1010 + E A9 A8 + W
	//step 4 : check status TWI_MT_SLA_W_ACK
	//step 5 : send rest of Byte address as data A7 .....A0
	//step 6 : check status TWI_MT_DATA_ACK
	//step 7 : send Byte to be written
	//step 8 : check status TWI_MT_DATA_ACK
	//step 9 : send stop
}
void eeprom_WriteByte(u8 address , u8 *data)
{
	
}
*/