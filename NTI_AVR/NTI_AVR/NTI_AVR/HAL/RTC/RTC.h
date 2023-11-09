/*
 * RTC.h
 *
 * Created: 11/03/23 12:35:28 PM
 *  Author: USER
 */ 


#ifndef RTC_H_
#define RTC_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"

typedef enum {AM=0,PM,NONE}AM_PM_t;
typedef struct{
	u8 day;
	u8 date;
	u8 month;
	u8 year;
	}date_t;

typedef struct{
	u8 seconds;
	u8 Minutes;
	u8 Hours;
	AM_PM_t am_pm;
}time_t;
void RTC_settime (time_t* t);
void RTC_setdate (date_t* t);
time_t RTC_getTime(void);
date_t RTC_getdate(void);

#endif /* RTC_H_ */