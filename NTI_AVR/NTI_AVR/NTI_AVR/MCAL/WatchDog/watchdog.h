/*
 * watchdog.h
 *
 * Created: 11/05/23 10:05:11 AM
 *  Author: USER
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_
typedef enum {Oscillator_Cycles_16=0,
	Oscillator_Cycles_32,
	Oscillator_Cycles_64,
	Oscillator_Cycles_128,
	Oscillator_Cycles_256,
	Oscillator_Cycles_512,
	Oscillator_Cycles_1024,
Oscillator_Cycles_2048}watchdog_sleeptime_t;

void WDT_Enable(void);
void WDT_Disable(void);
void WDT_sleep(watchdog_sleeptime_t sleepTime);
void WDT_refresh(void);

#endif /* WATCHDOG_H_ */