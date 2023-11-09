/*
 * Timer.c
 *
 * Created: 10/27/23 12:54:41 PM
 *  Author: USER
 */ 
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_interface.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\MCAL\Timer\Timer_private.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\utils.h"
#include "C:\Users\USER\Desktop\nti repo\NTI\NTI_AVR\NTI_AVR\NTI_AVR\GI\GIE.h"


void (* OVF_ptr)(void)=0;
void (* CM_ptr)(void)=0;


/******************Timer0*********/
void Timer0_Init(Timer0_modes mode,Timer0_prescaler prescaler,Timer0_OCR0_modes ocrmode)
{
	switch(mode)
	{
		case Timer0_Normal_Mode:CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case Timer0_PhaseCorrect_PWM_Mode:SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case Timer0_CTC_Mode:CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case Timer0_Fast_PWM_Mode:SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	switch(ocrmode)
	{
		case Timer0_Normal_Mode: CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Timer0_Toggle_on_compare: SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case Timer0_Clear_on_compare: CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case Timer0_Set_on_compare: SET_BIT(TCCR0,COM00);
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
void Timer0_start(Timer0_prescaler prescaler)
{
	TCCR0&=0xF8;
	TCCR0|=prescaler;
}
void Timer0_stop(void)
{
	TCCR0&=0xF8;
}
void setFastPWM(u8 duty)
{
	
	#if TIMER0_PWM_Mode == TIMER0_PWM_INVERTING
	OCR0 =255-((duty*255)/100);
	#elif TIMER0_PWM_Mode == TIMER0_PWM_NON_INVERTING
	OCR0 =(duty*255)/100;
	#endif
	
}
void setphaseCorrectPWM(u8 duty)
{
	#if TIMER0_PWM_Mode == TIMER0_PWM_INVERTING
	OCR0 =(510-((duty*510)/100))/2;
	#elif TIMER0_PWM_Mode == TIMER0_PWM_NON_INVERTING
	OCR0 =((duty*510)/100)/2;
	#endif

}
static volatile OVF_Num=0;
static volatile u8 ov_flag=0;
void Timer0_setTCNT_value (u8 val)
{
	TCNT0=val;
}
u32 Timer0_GetCounts(void)
{
	u32 counts=OVF_Num*256+TCNT0;
	OVF_Num=0;
	return counts;
}

static void Timer0_delay(void)
{
	static c=0;
	c++;
	if (c==OVF_Num)
	{
		ov_flag=1;
		c=0;
	}
}
void Timer0_setDelayTimeMilliSec(u32 time)
{
	Timer0_start(Timer0_Scaler_1024);
	u32 tick=1024/16;
	u32 allcounts=(u32)(time *1000)/tick;
	
	 OVF_Num=allcounts/256;
	u32 OVF_Rem=allcounts%256;
	if (OVF_Rem !=0)
	{
		OVF_Num++;
		TCNT0=256-OVF_Rem;	
	}
	Timer0_setCallBack(Timer0_OverFlow,Timer0_delay);
	while(ov_flag==0);
	ov_flag=0;
}
	
void Timer0_EnableInt(Timer0_Interrupt_Source source)
{
	switch(source)
	{
		case Timer0_Compare_Match: SET_BIT(TIMSK,OCIE0); break;
		case Timer0_OverFlow: SET_BIT(TIMSK,TOIE0); break;
		
	}
}
void Timer0_DisableInt(Timer0_Interrupt_Source source)
{
	switch(source)
	{
		case Timer0_Compare_Match: CLEAR_BIT(TIMSK,OCIE0); break;
		case Timer0_OverFlow: CLEAR_BIT(TIMSK,TOIE0); break;
	
	}
}

void Timer0_setCallBack(Timer0_Interrupt_Source source,void (*p)(void))
{
	switch(source)
	{
		case Timer0_Compare_Match: 
		if (p!=0)
		{CM_ptr=p;} 
			break;
		case Timer0_OverFlow:
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

/******************Timer1*******************************************/
static void (*Timer1_OVF_Fptr) (void)=0;
static void (*Timer1_OCA_Fptr) (void)=0;
static void (*Timer1_OCB_Fptr) (void)=0;
static void (*Timer1_ICU_Fptr) (void)=0;

void Timer1_Init(Timer1_modes mode,Timer0_prescaler prescaler,OCR1_modes OCRA, OCR1_modes OCRB)
{
	//timer mode
	TCCR1A&=0XFC;
	u8 mode2= (u8)mode &0x03;
	TCCR1A|=mode2;
	TCCR1B &=0xE7;
	mode2 = (u8)mode <<1;
	mode2&=0x18;
	TCCR1B|=mode2;

	//prescaler
	TCCR1B&=0xF8;
	TCCR1B|=prescaler;
	//ocr mode
	TCCR1A&=0x0F;
	TCCR1A|=((u8)OCRB<<4); //OCRB
	TCCR1A|=((u8)OCRA<<6);
	TCNT1 = 0 ;
	OCR1A = 0 ;
	OCR1B = 0 ;

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
static volatile t1,t2,t3,ovf1=0,ovf2=0,icuflag=0,icu_ovf=0;
void OVF_duty_callback(void)
{
	icu_ovf++;
}
void duty_callback(void)
{
	if (icuflag==0)
	{
		t1=(u16)ICR1;
		icuflag++;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if (icuflag==1)
	{
		t2=ICR1;
		ovf1=icu_ovf;
		icuflag++;
		icu_ovf=0;
		Timer1_InputCaptureEdge(RISING);
		
	}
	else if (icuflag ==2)
	{
		t3=ICR1;
		ovf2=icu_ovf;	
		icuflag++;
		icu_ovf=0;
	}
}

u8 duty_calculate(void)
{
		icuflag=0;
	Timer1_ICU_SetCallBack(duty_callback);
	Timer1_OVF_SetCallBack(OVF_duty_callback);
	while(icuflag !=3);
	u32 ton =t2 -t1 +ovf1 *65536;
	u32 t_off=t3-t2+ovf2*65536;
	u32 t_total=ton+t_off;
	u8 duty =((u32)ton *100) /(u32)t_total;

	return duty;
	
}
u8 duty_calculate_Blocking(void)
{
		TIFR = (1<<ICF1); 
		Timer1_InputCaptureEdge(RISING);
		while ((TIFR&(1<<ICF1)) == 0);
		volatile  a=ICR1;
		TIFR = (1<<ICF1);
		Timer1_InputCaptureEdge(FALLING);
		while ((TIFR&(1<<ICF1)) == 0);
		
		volatile u16 b = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);
		Timer1_InputCaptureEdge(RISING);
		while ((TIFR&(1<<ICF1)) == 0);
		volatile u16 c = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);
		volatile u16 ton=b-a;
		volatile u16 toff =c-b;
		 u8 duty=(ton*100)/(ton+toff);
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
