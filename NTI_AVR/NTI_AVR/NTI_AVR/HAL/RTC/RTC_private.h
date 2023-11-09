/*
 * RTC_private.h
 *
 * Created: 11/03/23 12:47:48 PM
 *  Author: USER
 */ 


#ifndef RTC_PRIVATE_H_
#define RTC_PRIVATE_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"


#define RTC_ADDRESS_WRITE 0xD0
#define RTC_ADDRESS_READ 0xD1

#define SECONDS_REG ((volatile u8*)0x00)
#define MINUTES_REG ((volatile u8*)0x01)
#define HOURS_REG ((volatile u8*)0x02)
#define DAY_REG ((volatile u8*)0x03)
#define DATE_REG ((volatile u8*)0X04)
#define MONTH_REG ((volatile u8*)0x05)
#define YEAR_REG ((volatile u8*)0x06)
#define CONTROL_REG ((volatile u8*)0X07)
#define RAM_REG ((volatile u8*)0X08)

static u8 BCD_to_Decimal(u8 bcd) ;
static u8 decimal_BCD(u8 decimal);
#endif /* RTC_PRIVATE_H_ */