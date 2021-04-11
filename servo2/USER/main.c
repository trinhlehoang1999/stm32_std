#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "timer.h"
// #include "stm32f10x_gpio.h"
/************************************************
STM32VN
************************************************/

u16 angle=0;
u16 _angle=0;
#define SYSCLK (72000000-1)
#define PRESCALER (72-1)
 long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


GPIO_InitTypeDef port;
TIM_TimeBaseInitTypeDef timer;
TIM_OCInitTypeDef timerPWM;

#define LED0 PDout(2)// PD2
#define LED1 PAout(8)// PA8
int TIM_Pulse,x=0;
void angle_servo(u16 angle)
{
//_angle=map(angle,0,270,500,2500);
	if(5<=angle<=250) _angle=angle;
	else 
	{
				angle=5; 
	}
		_angle=(float)angle*10;
	TIM4->CCR1 =_angle;//500-9000
}
void servo_init(void) {

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	GPIO_StructInit(&port);
	port.GPIO_Mode = GPIO_Mode_AF_PP;
	port.GPIO_Pin = GPIO_Pin_6;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &port);

	TIM_TimeBaseStructInit(&timer);
	timer.TIM_Prescaler = PRESCALER;
	timer.TIM_Period = SYSCLK / PRESCALER / (50);
	timer.TIM_ClockDivision = 0;
	timer.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &timer);

	TIM_OCStructInit(&timerPWM);
//	timerPWM.TIM_Pulse = 1000;
	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4, &timerPWM);

    TIM_Cmd(TIM4, ENABLE);
}

int main(void)
{
	
	
	//Init buttons
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_StructInit(&port);
	port.GPIO_Mode = GPIO_Mode_IPU;
	port.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_1;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &port);
  //LED_Init();
	delay_init();
	servo_init();
//	TIM_Pulse = timerPWM.TIM_Pulse;
//		TIM4->CCR1 = 2;
			x=angle=_angle=0;
    while(1)
    {
//			LED0=1; LED1=1;
//			delay_ms(100);
//			LED0=0; LED1=0;
//			delay_ms(100);
//    	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1) == 0) {
//				LED0=1;
//				TIM_Pulse=+100;
//				delay_ms(10);
//    		TIM4->CCR1 = TIM_Pulse;
//        if(TIM_Pulse>=19999) TIM_Pulse=19999;
//    	} else LED0=0;
//    	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0) {
//				LED1=1;
//				TIM_Pulse=-100;
//				delay_ms(100);
//    		TIM4->CCR1 = TIM_Pulse;
//				if(TIM_Pulse<=2) TIM_Pulse=2;
//    	} else LED1=0;
		LED0=0;
			LED1=0;
			x=angle;
	angle_servo(x);
			
		//	TIM4->CCR1 =angle;//500-9000
   	    // delay
   	  //delay_ms(100);
			
    }
}



