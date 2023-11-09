/*
 * watchdog_private.h
 *
 * Created: 11/05/23 10:05:28 AM
 *  Author: USER
 */ 


#ifndef WATCHDOG_PRIVATE_H_
#define WATCHDOG_PRIVATE_H_

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"

#define WDTCR (*(volatile u8 *)0x41)

#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDP0 0
#define WDTOE 4



#endif /* WATCHDOG_PRIVATE_H_ */