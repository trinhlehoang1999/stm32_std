#include "stm32f10x.h"
#include "sys.h"
#include "tcs3200.h"
#include "delay.h"
#include "LED.h"

 long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void tcs3200_gpio()
{
GPIO_InitTypeDef GPIO_tcs3200;

	
 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	   
	GPIO_tcs3200.GPIO_Pin = pin_S0|pin_S1|pin_S2|pin_S3;			   
  GPIO_tcs3200.GPIO_Mode = GPIO_Mode_Out_PP; 	 
  GPIO_tcs3200.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(port, &GPIO_tcs3200);		
  GPIO_tcs3200.GPIO_Pin = pin_OUT;
	GPIO_tcs3200.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(port, &GPIO_tcs3200);
}

void tcs3200_capture()
{

	TIM_TimeBaseInitTypeDef TIM_tcs3200;
	TIM_ICInitTypeDef TIM_capture;
//  NVIC_InitTypeDef NVIC_capture;
	RCC_ClocksTypeDef RCC_ClocksStatus;
	uint16_t prescaler;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	tcs3200_gpio();
  RCC_GetClocksFreq(&RCC_ClocksStatus);
  prescaler = RCC_ClocksStatus.SYSCLK_Frequency / 1000000 - 1;
	

	TIM_DeInit(TIM2);
	TIM_tcs3200.TIM_Prescaler = prescaler;
	TIM_tcs3200.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_tcs3200.TIM_Period = 0xFFFF;
	TIM_tcs3200.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2, &TIM_tcs3200);
	
	TIM_capture.TIM_Channel = TIM_Channel_1;
	TIM_capture.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_capture.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_capture.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_capture.TIM_ICFilter = 5;
	TIM_PWMIConfig(TIM2, &TIM_capture);
//	TIM_Cmd(TIM2,DISABLE);
//	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_SelectInputTrigger(TIM2, TIM_TS_TI1FP1);
	TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable);
	TIM_SelectSlaveMode(TIM2,TIM_SlaveMode_Reset);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	
	
//	NVIC_capture.NVIC_IRQChannel = TIM2_IRQn;
//	NVIC_capture.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_capture.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_capture.NVIC_IRQChannelSubPriority = 0;
//	
//	NVIC_Init(&NVIC_capture);
	
}

void Set_Filter (uint8_t mode1) //Mode es de tipo enum Filtro
{
	switch (mode1){
		case(Red):
			R=1;
		  B=0;
		  G=0;
			GPIO_ResetBits(port, pin_S2 | pin_S3 );
//		delay_ms(10);
			break;
		case(Blue):
			R=0;
		  B=1;
		  G=0;
			GPIO_ResetBits(port, pin_S2);
			GPIO_SetBits(port, pin_S3);
//		delay_ms(10);
			break;
		case(Clear):
			GPIO_ResetBits(port, pin_S3);
			GPIO_SetBits(port, pin_S2);
//		delay_ms(10);
			break;
		case(Green):
			R=0;
		  B=0;
		  G=1;
			GPIO_SetBits(port, pin_S2 | pin_S3);
//		delay_ms(10);
			break;
	}
}

void Set_Scaling (uint8_t mode2) 
{
	switch (mode2){
		case(Scl0):
			GPIO_ResetBits(port, pin_S0 | pin_S1);
			break;
		case(Scl2):
			GPIO_ResetBits(port, pin_S0);
			GPIO_SetBits(port, pin_S1);
			break;
		case(Scl20):
			GPIO_ResetBits(port, pin_S1);
			GPIO_SetBits(port, pin_S0);
			break;
		case(Scl100):
			GPIO_SetBits(port, pin_S0 | pin_S1);
			break;
	}
}

uint16_t value_tcs3200(uint16_t min,uint16_t max)
{

	TIM2->CNT = 0;
	TIM_Cmd(TIM2, ENABLE);

	while(!TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){

	 } 
delay_us(10000);
		TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_Cmd(TIM2, DISABLE);
	return map(ic2_tcs3200=TIM2->CCR2,min,max,255,0);
}







