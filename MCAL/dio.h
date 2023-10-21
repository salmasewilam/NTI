#ifndef DIO_H_
#define DIO_H_


typedef union{
	
	struct
	{
		unsigned char PIN0:1;
		unsigned char PIN1:1;
		unsigned char PIN2:1;
		unsigned char PIN3:1;
		unsigned char PIN4:1;
		unsigned char PIN5:1;
		unsigned char PIN6:1;
		unsigned char PIN7:1;
		
	};
	unsigned char port;
}pins_t;

typedef struct{
	pins_t pin;
	pins_t DDR;
	pins_t port;
}ports_t;

typedef enum {INPUT,OUTPUT}Direction;
typedef enum {LOW,HIGH}Value;

#define ptrA (volatile ports_t *) 0x39
#define ptrB (volatile ports_t *) 0x36
#define ptrC (volatile ports_t *) 0x33
#define ptrD (volatile ports_t *) 0x30

void DIO_voidSetPinDirection(ports_t *ptr,unsigned char p,Direction dir );
void DIO_voidSetPinValue(ports_t *ptr,unsigned char p,Value val);
Value DIO_GetPinValue(ports_t *ptr,unsigned char p);
void DIO_SetPortDirection(ports_t *ptr ,Direction dir );
void DIO_voidSetPortValue(ports_t *ptr,Value val);
unsigned char DIO_GetPortValue(ports_t *ptr);


#endif /* DIO_H_ */
