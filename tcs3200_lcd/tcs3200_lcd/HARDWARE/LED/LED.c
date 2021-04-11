#include "LED.h"

void LED_init(void)
	{
 GPIO_InitTypeDef GPIO_led;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
			GPIO_led.GPIO_Pin = GPIO_Pin_13;			
	GPIO_led.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_led.GPIO_Speed = GPIO_Speed_50MHz;	
  GPIO_Init(GPIOC, &GPIO_led);
}
	
void delay_s (unsigned long t) {while (t--);}



	


