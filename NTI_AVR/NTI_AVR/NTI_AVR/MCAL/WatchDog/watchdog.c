/*
 * watchdog.c
 *
 * Created: 11/05/23 10:04:53 AM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\WatchDog\watchdog.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\WatchDog\watchdog_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
u8 watchdog_flag=0;
void WDT_Enable(void)
{
	SET_BIT(WDTCR,WDE);
}
void WDT_Disable(void)
{
	WDTCR=(1<<WDTOE)|(1<<WDE);
	WDTCR=0;
}
void WDT_sleep(watchdog_sleeptime_t sleepTime)
{
	WDTCR&=0xF8;
	WDTCR|= sleepTime;
}
void WDT_refresh(void)
{
	__asm("WDR");
}