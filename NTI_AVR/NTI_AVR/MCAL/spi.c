/*
 * spi.c
 *
 * Created: 10/30/23 12:09:27 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\SPI_interface.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\stdtypes.h"

void SPI_init (SPI_init_bits* init)
{
	SPCR->clk=init->clk;
	SPCR->clk_parity=init->clk_parity;
	SPCR->clk_phase=init->clk_phase;
	SPCR->Master_slave=init->Master_slave;
	SPCR->data_order=init->data_order;
	SPCR->Spi_enable=init->Spi_enable;
	SPCR->interrupt_enable=init->interrupt_enable;
	
}

void SPI_SendReceive(u8 data_send,u8 *data_recived)
{
	SPDR=data_send;
	while(!READ_BIT(SPSR,SPIF)); 
	*data_recived=SPDR;
}