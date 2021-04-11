#include "stm32f10x.h"
#include "sys.h"
#include "LED.h"
#include "delay.h"


/************************************************
www.stm32vn.com 
************************************************/
  int a=0;
 
 int main(void)
 {	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	
	 LED_init();
	 delay_init();

  while(1)
	{
		GPIOA->CRH=0x00000003;
		GPIOA->BRR=GPIO_Pin_8;
		delay_ms(100);
		GPIOA->BSRR=GPIO_Pin_8;
		delay_ms(100);
//	   led_c13 =0;
//	  delay_ms(1500);

//		led_c13=1;
//		  delay_ms(1500);

		/////////////////////
//		GPIO_ResetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_4);
//delay_ms(1000);
//		
//	GPIO_SetBits(GPIOA,GPIO_Pin_4);
//	delay_ms(1000);
////			GPIO_ResetBits(GPIOA,GPIO_Pin_4);
////delay_ms(1000);
//		
//			GPIO_SetBits(GPIOA,GPIO_Pin_6);
//	delay_ms(1000);
////			GPIO_ResetBits(GPIOA,GPIO_Pin_6);
////			delay_ms(1000);
//		
//			GPIO_SetBits(GPIOA,GPIO_Pin_5);
//	delay_ms(1000);
////			GPIO_ResetBits(GPIOA,GPIO_Pin_5);
////delay_ms(1000);
a= GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);
if(a==0)  
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);		GPIO_SetBits(GPIOA,GPIO_Pin_6);			GPIO_SetBits(GPIOA,GPIO_Pin_5);
	
	}
	else GPIO_ResetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_4);

	}
	
 }
