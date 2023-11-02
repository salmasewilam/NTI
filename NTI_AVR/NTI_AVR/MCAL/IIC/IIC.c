/*
 * IIC.c
 *
 * Created: 10/31/23 12:00:40 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\MCAL\IIC\IIC_Interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\utils.h"

void I2C_init (i2c_prescaler_t prescaler,SCL_t scl)
{
	TWSR&=0xFC;
	u8 TWPS=(u8)prescaler;
	TWSR|=TWPS;
	switch (scl)
	{
		case SCL_100: switch(TWPS)
		{
			case 0: TWBR=TWBR_OF_SCL(100,1);break;
			case 1: TWBR=TWBR_OF_SCL(100,4);break;
			case 2: TWBR=TWBR_OF_SCL(100,16);break;
			case 3: TWBR=TWBR_OF_SCL(100,64);break;
		}break;
		case SCL_400: switch(TWPS)
		{
			case 0: TWBR=TWBR_OF_SCL(400,1);break;
			case 1: TWBR=TWBR_OF_SCL(400,4);break;
			case 2: TWBR=TWBR_OF_SCL(400,16);break;
			case 3: TWBR=TWBR_OF_SCL(400,64);break;
		}break;
	}
}

void I2C_sendByte(u8 copy_u8data)
{
	TWDR = copy_u8data;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

void I2C_sendStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN);
	while(READ_BIT(TWCR, TWINT) == 0);

}

void I2C_sendStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWSTO);

}
void I2C_recieveByte_ACK(u8* ptr)
{
	TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWEA);

	while(READ_BIT(TWCR, TWINT) == 0);

	*ptr = TWDR;

}
void I2C__NoACK(u8* ptr)
{
	TWCR = (1<<TWINT)|(1<<TWEN);

	while(READ_BIT(TWCR, TWINT) == 0);

	*ptr = TWDR;
}

void I2C_getStatus(u8* status )
{
	*status =(TWSR& 0xF8);
}