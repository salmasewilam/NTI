/*
 * Timer.c
 *
 * Created: 10/27/23 12:54:41 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\Timer_interface.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\MCAL\GIE.h"
#include "C:\Users\USER\Documents\NTI_AVR\NTI_AVR\HAL\lcd.h"

void (* OVF_ptr)(void)=0;
void (* CM_ptr)(void)=0;

#define F_CPU 8000000
#include <util/delay.h>

/******************Timer0*********/
void Timer0_Init(Timer0_modes mode,Timer0_prescaler prescaler,OCR0_modes mode2)
{
	switch(mode)
	{
		case Normal_Mode:CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case PhaseCorrect_PWM_Mode:SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case CTC_Mode:CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case Fast_PWM_Mode:SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	switch(mode2)
	{
		case Normal_Mode: CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Toggle_on_compare: SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Clear_on_compare: CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case Set_on_compare: SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
	TCCR0&=0xF8;
	TCCR0|=prescaler;
}
/*
void TIMER0_OC0Mode(OCR0_modes mode)
{
	switch(mode)
	{
		case Normal_Mode: CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Toggle_on_compare: SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Clear_on_compare: CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case Set_on_compare: SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}
*/
void Timer_start(Timer0_prescaler prescaler)
{
	TCCR0&=0xF8;
	TCCR0|=prescaler;
}
void Timer_stop(void)
{
	TCCR0&=0xF8;
}
void setFastPWM(u8 duty)
{
	
	#if PWM_Mode == PWM_INVERTING
	OCR0 =255-((duty*255)/100);
	#elif PWM_Mode == PWM_NON_INVERTING
	OCR0 =(duty*255)/100;
	#endif
	
}
void setphaseCorrectPWM(u8 duty)
{
	#if PWM_Mode == PWM_INVERTING
	OCR0 =(510-((duty*510)/100))/2;
	#elif PWM_Mode == PWM_NON_INVERTING
	OCR0 =((duty*510)/100)/2;
	#endif

}
u32 Timer_GetCounts(void)
{
	//u32 counts=No_OVF*256+TCNT0;
	//No_OVF=0;
	//return counts;
}
u32 OVF_Num;
u8 ov_flag=0;
void Timer0_delay(void)
{
	static c=0;
	c++;
	if (c==OVF_Num)
	{
		ov_flag=1;
		c=0;
	}
}
Timer_setDelayTimeMilliSec(u32 time)
{
	Timer_start(Timer0_Scaler_1024);
	u32 tick=1024/16;
	u32 allcounts=(u32)(time *1000)/tick;
	
	 OVF_Num=allcounts/256;
	u32 OVF_Rem=allcounts%256;
	if (OVF_Rem !=0)
	{
		OVF_Num++;
		TCNT0=256-OVF_Rem;	
	}
	setCallBack(OverFlow,Timer0_delay);
	while(ov_flag==0);
	ov_flag=0;
}
	
void EnableInt(Interrupt_Source source)
{
	switch(source)
	{
		case Compare_Match: SET_BIT(TIMSK,OCIE0); break;
		case OverFlow: SET_BIT(TIMSK,TOIE0); break;
		
	}
}
void DisableInt(Interrupt_Source source)
{
	switch(source)
	{
		case Compare_Match: CLEAR_BIT(TIMSK,OCIE0); break;
		case OverFlow: CLEAR_BIT(TIMSK,TOIE0); break;
	
	}
}

void setCallBack(Interrupt_Source source,void (*p)(void))
{
	switch(source)
	{
		case Compare_Match: 
		if (p!=0)
		{CM_ptr=p;} 
			break;
		case OverFlow:
		if (p!=0){ OVF_ptr=p;} 
			break;
		
	}
}

ISR(TIMER0_OVF_vect)
{
	
	if (OVF_ptr!= 0)
	{
		OVF_ptr();
	}
	return;

}
ISR(TIMER0_OC_vect)
{
	if (CM_ptr!= 0)
	{
		CM_ptr();
	}
	return;
}

/******************Timer1*********/
static void (*Timer1_OVF_Fptr) (void)=0;
static void (*Timer1_OCA_Fptr) (void)=0;
static void (*Timer1_OCB_Fptr) (void)=0;
static void (*Timer1_ICU_Fptr) (void)=0;

void Timer1_Init(Timer1_modes mode,Timer0_prescaler prescaler,OCR1_modes OCRA, OCR1_modes OCRB)
{
	//timer mode
	TCCR1A&=0XFC;
	TCCR1A|=(mode &0x03);
	TCCR1B &=0xE7;
	u8 mode2 = (u8)mode <<1;
	mode2&=0x18;
	TCCR1B|=mode2;

	//prescaler
	TCCR0&=0xF8;
	TCCR0|=prescaler;
	//ocr mode
	TCCR1A&=0x0F;
	TCCR1A|=((u8)OCRB<<4); //OCRB
	TCCR1A|=((u8)OCRA<<6);
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);
}
u16 ICU_TakeReading(void)
{
	return ICR1;
}
u16 t1,t2,t3,ovf1,ovf2,icuflag=0,icu_ovf=0;
void OVF_duty_callback(void)
{
	icu_ovf++;
}
void duty_callback(void)
{
	if (icuflag==0)
	{
		t1=ICR1;
		icuflag++;
		icu_ovf=0;
		//H_LCD_void_clear();
		H_LCD_void_sendIntNum(t1);
	//	_delay_ms(1000);
	}
	else if (icuflag==1)
	{
		t2=ICR1;
		icuflag++;
		icu_ovf=0;
		
		Timer1_InputCaptureEdge(FALLING);
	}
	else if (icuflag ==2)
	{
		t3=ICR1;
		icuflag++;
		icu_ovf=0;
		Timer1_InputCaptureEdge(RISING);
	}
}

u8 duty_calculate(void)
{
	Timer1_ICU_SetCallBack(duty_callback);
	Timer1_OVF_SetCallBack(OVF_duty_callback);
	if(icuflag !=4)
	{
		return 0;
	}
	
	u16 ton =t2 -t1 +ovf1 *65536;
	u16 t_total=ton+(t3-t2+ovf2*65536);
	/*H_LCD_void_clear();
	H_LCD_void_sendData('O');
	H_LCD_void_sendIntNum(ton);
	_delay_ms(1000);
	H_LCD_void_sendData('T');
	H_LCD_void_sendIntNum(t_total);
	_delay_ms(1000);*/
	u8 duty =(u32)ton *100 /(u32)t_total;
	return duty;
	
}

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}

void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}

void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}

void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=0)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=0)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=0)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=0)
	{
		Timer1_ICU_Fptr();
	}
}
