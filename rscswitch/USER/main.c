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
	
	 LED_init();
	 delay_init();
	
 
  while(1)
	{
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
