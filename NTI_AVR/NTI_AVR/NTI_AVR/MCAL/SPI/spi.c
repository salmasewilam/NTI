/*
 * spi.c
 *
 * Created: 10/30/23 12:09:27 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\SPI\SPI_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\SPI\Spi_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"

void SPI_init (SPI_init_bits * init)
{
	SPI_init_bits init2;
	init2.clk=init->clk;
	init2.clk_parity=init->clk_parity;
	init2.clk_phase=init->clk_phase;
	init2.Master_slave=init->Master_slave;
	init2.data_order=init->data_order;
	init2.Spi_enable=init->Spi_enable;
	init2.interrupt_enable=init->interrupt_enable;
 u8 portval=init2.SPCR_port;
 
SPCR=portval;
 #if Speed==Single_Speed
 CLEAR_BIT(SPSR,SPI2X);
 #elif Speed ==Double_Speed
 SET_BIT(SPSR,SPI2X);
 #endif

}

void SPI_SendReceive(u8 data_send,u8 *data_recived)
{
	SPDR=data_send;
	while(!READ_BIT(SPSR,SPIF)); 
	*data_recived=SPDR;
}



