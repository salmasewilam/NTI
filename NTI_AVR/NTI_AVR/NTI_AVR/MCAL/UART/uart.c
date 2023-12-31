/*
 * uart.c
 *
 * Created: 10/29/23 3:27:30 PM
 *  Author: USER
 */ 

#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\UART\uart_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\UART\Uart_config.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\UART\Uart_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
static void (*Uart_RX_Fptr) (void)=0;
static void (*Uart_TX_Fptr) (void)=0;

void Uart_Init(void)
{
	//set baud rate to 9600 for 8Mhz ==51 , 16Mhz== 103
	UBRRH=0;
	UBRRL=16;
	/*#if (BAUD_RATE==BAUD_4800)
	UBRRL=(u8)BAUD_4800;
	#elif (BAUD_RATE==BAUD_9600)
	UBRRL=(u8)BAUD_9600;
	#elif (BAUD_RATE==BAUD_14400)
	UBRRL=(u8)BAUD_14400;
	#elif (BAUD_RATE==BAUD_19200)
	UBRRL=(u8)BAUD_19200;
	#elif (BAUD_RATE==BAUD_28800)
	UBRRL=(u8)BAUD_28800;
	#elif (BAUD_RATE==BAUD_38400)
	UBRRL=(u8)BAUD_38400;
	#elif (BAUD_RATE==BAUD_57600)
	UBRRL=(u8)BAUD_57600;
	#elif (BAUD_RATE==BAUD_76800)
	UBRRL=(u8)BAUD_76800;
	#elif (BAUD_RATE==BAUD_115200)
	UBRRL=(u8)BAUD_115200;
	#elif (BAUD_RATE==BAUD_230400)
	UBRRL=(u8)BAUD_230400;
	#elif (BAUD_RATE==BAUD_250000)
	UBRRL=(u8)BAUD_250000;
	#elif (BAUD_RATE==BAUD_500000)
	UBRRL=(u8)BAUD_500000;
	#elif (BAUD_RATE==BAUD_1000000)
	UBRRL=(u8)BAUD_1000000;*/
	//enable reciever and transmitter
	UCSRB=(1<<RXEN)|(1<<TXEN);
	//set frame
	u8 data=0b10000110;
	#if MODE==SYN
	SET_BIT(data,UMSEL);
	#endif
	#if PARITY==EVEN_PARITY
	SET_BIT(data,UPM1);
	#elif PARITY==ODD_PARITY
	SET_BIT(data,UPM1);
	SET_BIT(data,UPM0);
	#endif
	#if STOP_BITS==STOP_2BIT
	SET_BIT(data,USBS);
	#endif
	UCSRC = data;
	//	
}

void Uart_SendData(u8 data)
{
	while (!READ_BIT(UCSRA,UDRE));
	//LCD_writeHex(data);
	UDR=data;
}

void Uart_RecieveData(u8* pdata)
{
	while (!READ_BIT(UCSRA,RXC));
	*pdata=UDR;
	//LCD_writeHex(*pdata);
	
}

void Uart_SendString(u8* str)
{
	for (int i=0;str[i];i++)
	{
		Uart_SendData(str[i]);
	}
}

void Uart_RX_InterruptEnable(void)
{
	//UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	SET_BIT(UCSRB,RXCIE);
	
}
void Uart_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
	
}
void Uart_TX_InterruptEnable(void)
{
		SET_BIT(UCSRB,TXCIE);
	
}
void Uart_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
	
}
volatile u8 uart_str[100],uart_flag=0;
/*
void getframe(void)
{
	u8 data[12];
	static u8 ind=0;
	data[ind]=UDR;
	LCD_writeHex(data[ind]);
	H_LCD_void_sendData('-');
	ind++;
	if (ind==12) ind=0;

}*/
static void ReciveDataNoBlock_callback(void)
{
    static volatile int i=0;
	uart_str[i]=UDR;
	if (uart_str[i]=='#') 
	{
		uart_str[i]='\0';
		uart_flag=1;
		i=0;
	}
	else
	i++;
}
u8 ReciveString_NOBLOCK(u8* str2)
{
	Uart_RX_SetCallBack(ReciveDataNoBlock_callback);
	
	int j;
	
	if (uart_flag==1)
	{
		for(j=0;uart_str[j];j++)
		{
			str2[j]=uart_str[j];
		}
		str2[j]='\0';
		uart_flag=0;
		return 1;
	}
		return 0;
		
}

void Uart_RX_SetCallBack(void (*LocalFPtr)(void))
{
	if (LocalFPtr!=0)
	{
		Uart_RX_Fptr=LocalFPtr;
	}
}
void Uart_TX_SetCallBack(void (*LocalFPtr)(void))
{
	if (LocalFPtr!=0)
	{
		Uart_TX_Fptr=LocalFPtr;
	}
}
ISR(UART_RX_vect)
{
	
	if (Uart_RX_Fptr!=0)
	{
		Uart_RX_Fptr();
	}
}
ISR (UART_TX_vect)
{
	if (Uart_TX_Fptr!=0)
	{
		Uart_TX_Fptr();
	}
	
}

