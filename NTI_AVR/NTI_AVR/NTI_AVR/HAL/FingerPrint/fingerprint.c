/*
 * fingerprint.c
 *
 * Created: 11/04/23 10:20:00 AM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\FingerPrint\fingerprint.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\UART\uart_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\DIO\Dio.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\HAL\LCD\lcd.h"
#define F_CPU 16000000
#include <util/delay.h>

static u8 return_ack(void)
{
	u8 ack,data[12];
	for (int i=0;i<12;i++)
	{
		Uart_RecieveData(&data[i]);
	}
	/*for (int i=0;i<12;i++)
	{
		LCD_writeHex(data[i]);
		H_LCD_void_sendData('-');
	}	*/
	ack=data[9];
	return ack;
}
void fingerprint_init(void)
{
	DIO_voidSetPinDirection(ptrD,1,1);
	DIO_voidSetPinDirection(ptrD,0,0);
	Uart_Init();
}
FINGERP_ERROR_t FingerPS_handShake(void)
 {
	 u8 ack;
	 FINGERP_ERROR_t status;
	 Uart_SendData(0xEF);
	 Uart_SendData(0x01);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0x01);
	 Uart_SendData(0x00);
	 Uart_SendData(0x03);
	 Uart_SendData(0x40);
	 Uart_SendData(0x00);
	 Uart_SendData(0x44);
	 ack=return_ack();
	 status =ack;
	 return status;
 }
 
FINGERP_ERROR_t FingerPS_genImg(void) //GenImg
 {
	 u8 ack;
	 FINGERP_ERROR_t status;
	 Uart_SendData(0xEF);
	 Uart_SendData(0x01);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0x01);
	 Uart_SendData(0x00);
	 Uart_SendData(0x03);
	 Uart_SendData(0x01);
	 Uart_SendData(0x00);
	 Uart_SendData(0x05);
	 ack=return_ack();
	 status=ack;
	 return status;
 }
FINGERP_ERROR_t FingerPS_convertImg2CharFile(u8 bufferID)//Img2Tz
{
	 u8 ack;
	 u16 sum=0;
	 FINGERP_ERROR_t status;
	 Uart_SendData(0xEF);
	 Uart_SendData(0x01);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0x01);
	 Uart_SendData(0x00);
	 Uart_SendData(0x04);
	 Uart_SendData(0x02);
	 Uart_SendData(bufferID); //01 charBuffer1 02 charBUffer2
	 sum=0x01+0x04+0x02+bufferID;
	 Uart_SendData((u8)sum>>8);
	 Uart_SendData((u8)sum);
	 ack=return_ack();
	 status=ack;
	 return status; 
}
FINGERP_ERROR_t FingerPS_genTemplate(void)//RegModel
{
	 u8 ack;
	 FINGERP_ERROR_t status;
	 Uart_SendData(0xEF);
	 Uart_SendData(0x01);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0xFF);
	 Uart_SendData(0x01);
	 Uart_SendData(0x00);
	 Uart_SendData(0x03);
	 Uart_SendData(0x05);
	 Uart_SendData(0x00);
	 Uart_SendData(0x09);
	  ack=return_ack();
	  status=ack;
	  return status; 
}
FINGERP_ERROR_t FingerPS_strTemplate(u8 bufferID,u16 pageID)//store
{
	u8 ack;
	u16 sum;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x06);
	Uart_SendData(0x06);
	Uart_SendData(bufferID);
	Uart_SendData((u8)pageID>>8);
	Uart_SendData((u8)pageID);
	sum=0x01+0x06+0x06+bufferID+pageID;
	Uart_SendData((u8)sum>>8);
	Uart_SendData((u8)sum);
	ack=return_ack();
	status=ack;
	return status;
}
FINGERP_ERROR_t FingerPS_searchFinger(u8 bufferID,u16 startpage,u16 pageNum,u16 *pageID)//search
{
	u8 ack,id2;
	u16 sum=0,id=0;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x08);
	Uart_SendData(0x04);
	Uart_SendData(bufferID);
	Uart_SendData((u8)(startpage>>8));
	Uart_SendData((u8)startpage);
	Uart_SendData((u8)(pageNum>>8));
	Uart_SendData((u8)pageNum);
	sum=0x01+0x08+0x04+bufferID+startpage+pageNum;
	Uart_SendData((u8)(sum>>8));
	Uart_SendData((u8)sum);
	Uart_RecieveData(&id2);
	id=id2<<8;
	Uart_RecieveData(&id2);
	id+=id2;
	*pageID=id;
    ack=return_ack();
	status=ack;
	return status;	
}
FINGERP_ERROR_t FingerPS_emptyLibrary(void) //Empty
{
	u8 ack;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x03);
	Uart_SendData(0x0D);
	Uart_SendData(0x00);
	Uart_SendData(0x11);
	 ack=return_ack();
	status=ack;
	return status;
}
FINGERP_ERROR_t FingerPS_deleteFinger(u16 pageID) //DeletChar
{
	u8 ack;
	u16 sum;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x07);
	Uart_SendData(0x0C);
	Uart_SendData((u8)pageID>>8);
	Uart_SendData(pageID);
	Uart_SendData(0x00);
	Uart_SendData(0x01); // to delete one template
	sum=0x01+0x07+0x0C+pageID+0x01;
	Uart_SendData((u8)sum>>8);
	Uart_SendData(sum);
	 ack=return_ack();
	status=ack;
	return status;
}
FINGERP_ERROR_t FingerPS_LoadCharFile(u8 bufferID,u16 pageID)//LoadChar
{
	u8 ack;
	u16 sum;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x06);
	Uart_SendData(0x07);
	Uart_SendData(bufferID);
	Uart_SendData((u8)pageID>>8);
	Uart_SendData(pageID);
	sum=0x01+0x06+0x07+bufferID+pageID;
	Uart_SendData((u8)sum>>8);
	Uart_SendData(sum);
	 ack=return_ack();
	status=ack;
	return status;
}
FINGERP_ERROR_t FingerPS_match(void)//Match
{
	u8 ack;
	FINGERP_ERROR_t status;
	Uart_SendData(0xEF);
	Uart_SendData(0x01);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0xFF);
	Uart_SendData(0x01);
	Uart_SendData(0x00);
	Uart_SendData(0x03);
	Uart_SendData(0x03);
	Uart_SendData(0x00);
	Uart_SendData(0x07);
	 ack=return_ack();
	status=ack;
	return status;
}

