/*
 * IIC_Interface.h
 *
 * Created: 10/31/23 12:00:07 PM
 *  Author: USER
 */ 


#ifndef IIC_INTERFACE_H_
#define IIC_INTERFACE_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"

#define	STATUS_REGISTER_MASK	0xF8
#define TWBR_OF_SCL(scl,pre)  ((((16000000)/(scl))-16)/((2)*(pre)))
typedef enum{SCL_100,SCL_400}SCL_t;
typedef enum {I2C_prescaler_1=0,I2C_prescaler_4,I2C_prescaler_16,I2C_prescaler_64}i2c_prescaler_t;
	
void I2C_init (i2c_prescaler_t prescaler,SCL_t scl);
void I2C_sendByte(u8 copy_u8data);
void I2C_sendStart(void);
void I2C_sendStop(void);
void I2C_recieveByte_ACK(u8* ptr);
void I2C__NoACK(u8* ptr);
void I2C_getStatus(u8* status );

#endif /* IIC_INTERFACE_H_ */