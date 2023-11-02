/*
 * EEPROM_interface.h
 *
 * Created: 10/31/23 3:04:33 PM
 *  Author: USER
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"

#define EEPROM_ADDRESS_Write 0xA0
#define EEPROM_ADDRESS_Read 0xA1
void EEPROM_Init(void);
void eeprom_WriteByte(u8 data , u8 address);
void eeprom_ReadByte(u8 address , u8 *data);
#endif /* EEPROM_INTERFACE_H_ */