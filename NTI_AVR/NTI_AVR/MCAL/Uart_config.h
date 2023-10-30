/*
 * Uart_config.h
 *
 * Created: 10/29/23 9:08:36 PM
 *  Author: USER
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define ASYN 0
#define SYN  1
#define MODE ASYN

#define DISABLE_PARITY 0
#define EVEN_PARITY 2
#define ODD_PARITY  3
#define PARITY DISABLE_PARITY

#define STOP_1BIT 0
#define STOP_2BIT 1
#define STOP_BITS STOP_1BIT

#define CHARSIZE_5BIT 0
#define CHARSIZE_6BIT 1
#define CHARSIZE_7BIT 2
#define CHARSIZE_8BIT 3
#define CHARSIZE_9BIT 7
#define CHAR_SIZE CHARSIZE_8BIT

//#define  BAUD_9600 


#endif /* UART_CONFIG_H_ */