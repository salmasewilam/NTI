/*
 * IIC_Interface.h
 *
 * Created: 10/31/23 12:00:07 PM
 *  Author: USER
 */ 


#ifndef IIC_INTERFACE_H_
#define IIC_INTERFACE_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\stdtypes.h"

#define	STATUS_REGISTER_MASK	0xF8
/*

#define TWI_MT_START 0X08
#define TWI_MT_SLA_W_ACK 0x18
#define TWI_MT_DATA_ACK  0x28
#define TWI_MR_SLA_R_ACK 0x40
#define TWI_MR_DATA_ACK  0x50*/

//Status codes for master transmit
#define MT_START_COND_ACK  0X08
#define MT_REPEATED_START_ACK 0x10
#define MT_SLA_W_ACK  0x18
#define MT_SLA_W_NOT_ACK 0x20
#define MT_DATA_TRANSMITED_ACK 0x28
#define MT_DATA_TRANSMITED_NOT_ACK 0x30
#define MT_ARBITERATION_LOST 0x38

//status codes for master recieve

#define MR_START_COND_ACK  0X08
#define MR_REPEATED_START_ACK 0x10
#define MR_ARB_LOST_OR_NOT_ACK  0x38
#define MR_SLA_R_ACK 0x40
#define MR_DATA_RECIEVED_ACK 0x50
#define MR_DATA_RECIEVED_NOT_ACK 0x58


#define TWBR_OF_SCL(scl,pre)  ((((16000000)/(scl))-16)/((2)*(pre)))
typedef enum{SCL_100,SCL_400}SCL_t;
typedef enum {I2C_prescaler_1=0,I2C_prescaler_4,I2C_prescaler_16,I2C_prescaler_64}i2c_prescaler_t;
	
void I2C_init (i2c_prescaler_t prescaler,SCL_t scl);
void I2C_sendByte(u8 copy_u8data);
void I2C_sendStart(void);
void I2C_sendStop(void);
void I2C_recieveByte_ACK(u8* ptr);
void I2C_RECIEVENoACK(u8* ptr);
void I2C_getStatus(u8* status );

#endif /* IIC_INTERFACE_H_ */