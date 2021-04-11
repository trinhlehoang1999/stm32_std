#include "stm32f10x.h"
#include "LED.h"
#include "exti.h"
#include "delay.h"


/************************************************
www.stm32vn.com
************************************************/
u8 key;
#define B12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
 u8 t;
int B=0;  

  void cauhinh_led(void)
	 {
	 GPIO_InitTypeDef  GPIO_InitStructure; 		
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	    //PB,PE		
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;			    //LED0-->PB.5 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOA, &GPIO_InitStructure);	
	 }
 void gpio_exti(void)
	 {
	 GPIO_InitTypeDef  gpio_exticonfig;		
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);	    //PB,PE		
	
  gpio_exticonfig.GPIO_Pin = GPIO_Pin_12;			    //LED0-->PB.5 
  gpio_exticonfig.GPIO_Mode = GPIO_Mode_IPU; 	 
  gpio_exticonfig.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &gpio_exticonfig);	
		 
		 GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);
	 
	 }
 
	 void exti_config(void)
		 {
		 EXTI_InitTypeDef    exticonfig;	
		 exticonfig.EXTI_Line=EXTI_Line12;
			 exticonfig.EXTI_Mode=EXTI_Mode_Interrupt;
			 exticonfig.EXTI_Trigger=EXTI_Trigger_Rising;
			 exticonfig.EXTI_LineCmd=ENABLE;
			 EXTI_Init(&exticonfig);
		 }
 
 void nvic_exti(void)
 {
 NVIC_InitTypeDef   nvic_int;
	#ifdef VECT_TAB_RAM
NVIC_SetVectorTable(NVIC_VectTab_RAM,0x0);
#else
	 NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0);
#endif

	  nvic_int.NVIC_IRQChannel = EXTI15_10_IRQn;			//KEY0
  	nvic_int.NVIC_IRQChannelPreemptionPriority = 0x02;	
  	nvic_int.NVIC_IRQChannelSubPriority = 0x00;					
  	nvic_int.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&nvic_int);  	  //NVIC
	 
 }
 

  void EXTI15_10_IRQHandler(void)
{

	 
if(EXTI_GetITStatus(EXTI_IMR_MR12)==SET)
{
	while(B12==1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_4);	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_6);	
		t=0;
			EXTI_ClearITPendingBit(EXTI_IMR_MR12);
}}


}
 

 
 int main(void)
 {	
	 cauhinh_led();
	 gpio_exti();
	 exti_config();
	  nvic_exti();
	// LED_init();
	 //EXTIx_Init(GPIOA, GPIO_Pin_5, Trigger_Rising);
//	 EXTIx_Init(GPIOB, GPIO_Pin_12, Trigger_Falling);
	 delay_init();



while(1)
	{
//	    LED0 =0;//GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	 // GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6);
//		delay_ms(300);
//			LED0 =1;GPIO_SetBits(GPIOB,GPIO_Pin_5);
//			GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//		delay_ms(300);
		//B=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);
		t=1;

		GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_4);
	}
 }



 
 
 
 
 
