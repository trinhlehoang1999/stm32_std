#include "LED.h"

void LED_init(void)
	{
 GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|    //cap xung cho 2 port B va E.
  RCC_APB2Periph_GPIOA, ENABLE);	    //chan dieu khien o 2 port B va E duoc cho phep
		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_4;			    //LED0-->PB.5 // goi chan can output
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //ngo ra là day keo
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 // voi toc do gpio là 50 mhz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			     //GPIOB.5// cai dat cau hinh len port B
		
  //GPIO_ResetBits(GPIOB,GPIO_Pin_5);					//PB.5 =0
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	            //LED1-->PE.5
//  GPIO_Init(GPIOC, &GPIO_InitStructure);	  	       
//  GPIO_ResetBits(GPIOC,GPIO_Pin_13); 				//PE.5 =0  
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	 //ngo ra là day keo

  GPIO_Init(GPIOB, &GPIO_InitStructure);	  	       
  //GPIO_ResetBits(GPIOC,GPIO_Pin_13); 	
		
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	            //LED1-->PE.5
  GPIO_Init(GPIOC, &GPIO_InitStructure);	  	       
  GPIO_ResetBits(GPIOC,GPIO_Pin_13); 	
	
}
	
void delay_s (unsigned long t) {while (t--);}



	


