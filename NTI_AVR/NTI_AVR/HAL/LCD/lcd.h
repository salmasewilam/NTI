/*
 * lcd.h
 *
 * Created: 10/23/23 10:55:34 AM
 *  Author: USER
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\stdtypes.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\HAL\LCD\lcd_config.h"

void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data );
void H_LCD_void_sendCommand(u8 copy_u8command);
void H_LCD_void_sendString(const s8 * pstr);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);
static void H_LCD_void_latchByte(u8 copy_u8Byte);
void H_LCD_void_clear(void);


#endif /* LCD_H_ */