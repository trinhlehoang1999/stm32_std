#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"


/************************************************
www.stm32vn.com 
************************************************/


 
 int main(void)
 {	
	 LED_init();
	 delay_init();
 
  while(1)
	{
//	    LED0 =0;//GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	    GPIO_SetBits(GPIOC,GPIO_Pin_13);
		  LED12=1;
			LED13=1;
			LED14=1;
			LED15=1;
		delay_ms(30);
			LED12=0;
			LED13=0;
			LED14=0;
			LED15=0;
//			LED0 =1;
//		GPIO_SetBits(GPIOB,GPIO_Pin_5);
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delay_ms(30);
	}
 }
