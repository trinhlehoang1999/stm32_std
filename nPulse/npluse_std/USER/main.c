#include "stm32f10x.h"
#include "LED.h"
#include "exti.h"
#include "delay.h"
#include "usart.h"	

/************************************************
www.stm32vn.com
************************************************/

#define LED0 PCout(13) 
//#define B12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
uint16_t nPULSE=0;
uint16_t x=0;

//void TIM3_Int_Init(u16 arr1,u16 psc1)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

//	TIM_TimeBaseStructure.TIM_Period = arr1; 
//	TIM_TimeBaseStructure.TIM_Prescaler =psc1;   
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
// 
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); 
//	
//	TIM_Cmd(TIM3, ENABLE);  

//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//	NVIC_Init(&NVIC_InitStructure);  

//						 
//}

void nPWM(uint16_t psc,uint16_t arr ,uint32_t PULSE_NUMBER){
	
	//pinMode(PA8,AF_PP);

	
RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; /* Peripheral clock enable */
//uint16_t Prescaler = (uint16_t) (SystemCoreClock / 1000000) - 1;
/* Set the Timer prescaler to get 1MHz as counter clock */
TIM1->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS); /* Select the up counter mode */
TIM1->CR1 |= TIM_CounterMode_Up;
TIM1->CR1 &= ~TIM_CR1_CKD;
TIM1->CR1 |= 0;//TIM_CLOCKDIVISION_DIV1; /* Set the clock division to 1*/
TIM1->ARR = arr-1; /* Set the Autoreload value */
TIM1->CCR1 = ((arr-1)/2);//PULSE; /* Set the Pulse value */uint16_t PULSE
TIM1->PSC = psc-1; /* Set the Prescaler value */
/////////////////////////
TIM1->RCR = 1 - 1; /* =1PULSE Set the Repetition counter value *//////////////////////////////
/////////////////////////
TIM1->EGR = TIM_EGR_UG; /* Generate an update event to reload the Prescaler
and the repetition counter value immediately */
TIM1->SMCR = RESET; /* Configure the Internal Clock source */
TIM1->CR1 |= TIM_CR1_OPM; /* Select the OPM Mode */
TIM1->CCMR1 &= (uint16_t)~TIM_CCMR1_OC1M;
TIM1->CCMR1 &= (uint16_t)~TIM_CCMR1_CC1S;
TIM1->CCMR1 |= TIM_OCMode_PWM2;
/* Select the Channel 1 Output Compare and the Mode */
TIM1->CCER &= (uint16_t)~TIM_CCER_CC1P;
/* Set the Output Compare Polarity to High */
TIM1->CCER |= TIM_OCPolarity_High;//TIM_OCPolarity_High;
TIM1->CCER = TIM_CCER_CC1E; /* Enable the Compare output channel 1 */
TIM1->BDTR |= TIM_BDTR_MOE; /* Enable the TIM main Output */

TIM1->SR = 0;              // clear interrupt status after the update event
TIM1->DIER = TIM_DIER_UIE; // enable interrupt on update (overflow) event

   NVIC_SetPriority(TIM1_UP_IRQn , 0);
   NVIC_EnableIRQ(TIM1_UP_IRQn );

TIM1->CR1 |= TIM_CR1_CEN; /* Enable the TIM peripheral */


			nPULSE=PULSE_NUMBER-1;

		x=0;
		}

void TIM1_UP_IRQHandler(void) {
    TIM1->SR = 0;
    //digitalWrite( PC13, LOW );
	(x++>=nPULSE)? (TIM1->CR1 &= ~TIM_CR1_CEN) :(TIM1->CR1 |= TIM_CR1_CEN);
	
}

void tim2(uint16_t psc,uint16_t arr ,uint16_t PULSE_NUMBER){
//	/* set the Timer prescaler to get 1MHz as counter clock */
// Tim2Prescaler= (uint16_t) ((SystemCoreClock ) / 1000000) - 1;
///* Initialize the PWM period to get 50 Hz as frequency from 1MHz */
// Period = 1000000 / 50;

	RCC->APB1ENR |= 	RCC_APB1ENR_TIM2EN ;
/* configure the period */
 TIM2->ARR = arr-1;
/* configure the Timer prescaler */
	 TIM2->PSC = psc-1;
///* Select the Clock Divison to 1*/
///* Reset clock Division bit field */
// TIM2->CR1 &= ~ TIM_CR1_CKD;
///* Select DIV1 as clock division*/
// TIM2->CR1 |= TIM_CLOCKDIVISION_DIV1;
///* Select the Up-counting for TIM1 counter */
///* Reset mode selection bit fields */
// TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
///* select Up-counting mode */
// TIM2->CR1 |= TIM_COUNTERMODE_UP;
///****** Master mode configuration: Trigger update mode *******/
///* Trigger of TIM2 Update into TIM1 Slave */
// TIM1->CR2 &= ~ TIM_CR2_MMS;
// TIM2->CR2 |= TIM_TRGO_UPDATE;
///*************************************************************/
///* Enable the TIM Counter */
// TIM2->CR1 |= TIM_CR1_CEN;

 /* Select the Clock Divison to 1*/
  /* Reset clock Division bit field */
  TIM2->CR1 &= ~ TIM_CR1_CKD;
  /* Select DIV1 as clock division*/
  TIM2->CR1 |= TIM_CKD_DIV1;
	
  /* Select the Up-counting for TIM1 counter */
  /* Reset mode selection bit fields*/
  TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
  /* select Up-counting mode */
  TIM2->CR1 |= TIM_CounterMode_Up;

/********** Master mode configuration: trigger update ***********/	
	
  /* Trigger of TIM2 Update into TIM1 Slave */
  TIM2->CR2 &= ~TIM_CR2_MMS;
  TIM2->CR2 |= TIM_TRGOSource_Update;
	
/****************************************************************/	
/********** Slave mode configuration: Trigger mode **************/
	
 /* Select the TIM_TS_ITR0 signal as Input trigger for the TIM */
  TIM2->SMCR &= ~TIM_SMCR_TS;
  TIM2->SMCR |= TIM_TS_ITR0;
	
  /* Slave Mode selection: Trigger reset Mode */
  TIM2->SMCR &= ~TIM_SMCR_SMS;
  TIM2->SMCR |= TIM_SlaveMode_Reset;
/****************************************************************/	
	
  /* Enable the TIM1 Counter */
  TIM2->CR1 |= TIM_CR1_CEN;
}

 
void gpio_init()
	{
		GPIO_InitTypeDef GPIO_InitStruct;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStruct);
	}
void init_pwm()
	{
		GPIO_InitTypeDef GPIO_InitStruct;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
	}
 int main(void)
 {	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	 delay_init();
	 init_pwm();
	 gpio_init();
//	 USARTx_Init(USART1, Pins_PA9PA10, 115200);
//	 USART_Puts(USART1, "STM32VN\n");
   nPWM(1,72,10);
 //tim2(1,2048,2000);
while(1)
	{

	}
 }



 
 
 
 
 
