#include "stm32f10x.h"
#include "usart.h"
uint32_t dem=0;

void TIM3_Init(u16 arr1,u16 psc1)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = arr1; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc1;   
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); 
	
	TIM_Cmd(TIM3, ENABLE);  

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  

						 
}

void delay(uint32_t u32DelayInMs)
{
	
	
	while (u32DelayInMs) {
		TIM_SetCounter(TIM4, 0);
		while (TIM_GetCounter(TIM4) < 1000) {
		}
		--u32DelayInMs;
		printf("gia tri:%d\n",u32DelayInMs);
	}
}

int main(void)
{
	GPIO_InitTypeDef gpioInit;
	TIM_TimeBaseInitTypeDef tim4Init;
//	TIM_OCInitTypeDef pwmInit;

	/* clock PB */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* PB9 out */
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = GPIO_Pin_9;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpioInit);
	
	/* timer 4 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	tim4Init.TIM_Prescaler = 72-1;
	tim4Init.TIM_CounterMode = TIM_CounterMode_Up;
	tim4Init.TIM_Period = 0xffff;
	tim4Init.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4, &tim4Init);
	TIM_Cmd(TIM4, ENABLE);
	uart_init(115200);
//	pwmInit.TIM_OCMode = TIM_OCMode_PWM1;
//	pwmInit.TIM_OCPolarity = TIM_OCPolarity_High;
//	pwmInit.TIM_OutputState = TIM_OutputState_Enable;
//	pwmInit.TIM_Pulse = 6;
//	
//	TIM_OC4Init(TIM4, &pwmInit);
	
	while (1) {
		delay(100);
	dem=TIM_GetCounter(TIM4);
		printf("gia tri dem :%d\n",dem);
	//printf("gia tri dem :%d\n,",u32DelayInMs);
//		GPIO_SetBits(GPIOB, GPIO_Pin_9);
//		delay(100);
//		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
//	delay(200);

	}
}
