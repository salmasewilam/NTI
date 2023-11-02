/*
 * ExtInt_private.h
 *
 * Created: 10/30/23 8:42:16 PM
 *  Author: USER
 */ 


#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

#define GICR (*(volatile u8 *)0x5B)
#define MCUCR (*(volatile u8 *)0x55)
#define MCUCSR (*(volatile u8 *)0x54)


#endif /* EXTINT_PRIVATE_H_ */