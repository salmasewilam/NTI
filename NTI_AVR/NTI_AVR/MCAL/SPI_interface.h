/*
 * SPI_interface.h
 *
 * Created: 10/30/23 12:11:14 PM
 *  Author: USER
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* SPI Control Register */
//#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

typedef enum{MSB,LSB}spi_data_order_t;
typedef enum{POLLING,INTERRUPT}spi_mode_t;
typedef enum{DISABLED,ENABLED}spi_enable_t;
typedef enum{SLAVE,MASTER}spi_master_slave_t;
typedef enum{LOW_IDLE,HIGH_IDLE}spi_clkparity_t;
typedef enum{SAMPLE,SETUP}spi_clkphase_t;
typedef enum{F_4=0,F_16,F_64,F_128,F2_2=0,F2_8,F2_32,F2_64}spi_clock_t;
	
typedef struct {
	spi_clock_t clk:2;
	spi_clkphase_t clk_phase:1;
	spi_clkparity_t clk_parity:1;
	spi_master_slave_t Master_slave:1;
	spi_data_order_t data_order:1;
	spi_enable_t Spi_enable:1;
	spi_mode_t interrupt_enable:1;
	}SPI_init_bits;
	
#define SPCR ((volatile SPI_init_bits *) 0x2D)

#endif /* SPI_INTERFACE_H_ */