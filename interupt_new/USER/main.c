#include "stm32f10x.h"
#include "LED.h"
#include "exti.h"
#include "delay.h"
//#include "KEY.h"

//#define B12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)

/************************************************
www.stm32vn.com
************************************************/
u8 key;


int t;
int button=0;
//#define B1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
 int main(void)
 {	
	 LED_init();


	// EXTIx_Init(GPIOA, GPIO_Pin_5, Trigger_Rising);
	 EXTIx_Init(GPIOB, GPIO_Pin_12, Trigger_Rising);
	 delay_init();
	
  while(1)
	{
	//	button=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);
//	    LED0 =0;//GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//	    GPIO_SetBits(GPIOE,GPIO_Pin_5);
//		delay_ms(300);
//			LED0 =1;GPIO_SetBits(GPIOB,GPIO_Pin_5);
//			GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//		delay_ms(300);

//t=1;
	GPIO_SetBits(GPIOA,GPIO_Pin_4);	delay_ms(150);	
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);	delay_ms(150);	
	GPIO_SetBits(GPIOA,GPIO_Pin_6);		delay_ms(150);
			GPIO_ResetBits(GPIOA,GPIO_Pin_6);		delay_ms(150);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	//delay_ms(100);
	}
 }
 



 
 
 
 

