/*
 * uart_interface.h
 *
 * Created: 10/29/23 3:27:14 PM
 *  Author: USER
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\stdtypes.h"

//functions prototypes
void getframe(void);
void Uart_Init(void);
void Uart_SendData(u8 data);
void Uart_RecieveData(u8* pdata);
void Uart_SendString(u8* str);
u8 ReciveString_NOBLOCK(u8* str2);
void Uart_RX_InterruptEnable(void);
void Uart_RX_InterruptDisable(void);
//void Uart_RX_SetCallBack(void (*LocalFPtr)(u8* str));

void Uart_RX_SetCallBack(void (*LocalFPtr)(void));

#endif /* UART_INTERFACE_H_ */