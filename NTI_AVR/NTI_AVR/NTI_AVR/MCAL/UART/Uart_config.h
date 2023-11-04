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

#define	BAUD_4800 207
#define	BAUD_9600 103
#define	BAUD_14400 68
#define	BAUD_19200 51
#define	BAUD_28800 34
#define	BAUD_38400 25
#define	BAUD_57600 16
#define	BAUD_76800 12
#define	BAUD_115200 8
#define	BAUD_230400 3
#define	BAUD_250000 3
#define	BAUD_500000 1
#define	BAUD_1000000 0

#define BAUD_RATE BAUD_57600


#endif /* UART_CONFIG_H_ */