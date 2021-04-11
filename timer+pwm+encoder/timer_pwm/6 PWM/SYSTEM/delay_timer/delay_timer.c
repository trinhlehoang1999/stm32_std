#include <stm32f10x.h>
#include "delay_timer.h"


void delaytimer_int()
	{
			TIM_TimeBaseInitTypeDef timerInit;
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		timerInit.TIM_CounterMode = TIM_CounterMode_Up;
	timerInit.TIM_Period = 0xFFFF;
	timerInit.TIM_Prescaler = 72 - 1;
	
	TIM_TimeBaseInit(TIM3, &timerInit);
	
	TIM_Cmd(TIM3, ENABLE);
	
	}

void Delay1Ms(void)
{
	
	TIM_SetCounter(TIM3, 0);
	while (TIM_GetCounter(TIM3) < 1000) {
	}
}

void Delay_Us(uint32_t delay)
{
	
	TIM_SetCounter(TIM3, 0);
	while (TIM_GetCounter(TIM3) < delay) {
	}
}

void Delay_Ms(uint32_t u32DelayInMs)
{
	
	while (u32DelayInMs) {
		Delay1Ms();
		--u32DelayInMs;
	}
}









