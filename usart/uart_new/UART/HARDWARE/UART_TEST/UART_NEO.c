#include "uart_neo.h"

#include "sys.h"
int x=0,y=0,z=0;
 char buffer;


void gpio_config(void){
	
	GPIO_InitTypeDef			GPIO_SETUP;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	 GPIO_SETUP.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_4;		
 GPIO_SETUP.GPIO_Mode = GPIO_Mode_Out_PP; 	 
 GPIO_SETUP.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOA, &GPIO_SETUP);

}

void usart_config(void){
	    USART_InitTypeDef			UART_SETUP;
		GPIO_InitTypeDef			GPIO_SETUP;
NVIC_InitTypeDef			NVIC_SETUP;
	/*Cap clock cho USART và port su dung*/
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO|RCC_APB2Periph_USART1 , ENABLE);
	
		
	
			GPIO_SETUP.GPIO_Pin = GPIO_Pin_9;
			GPIO_SETUP.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_SETUP.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOA, &GPIO_SETUP);
		
			GPIO_SETUP.GPIO_Pin = GPIO_Pin_10;
			GPIO_SETUP.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_SETUP.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOA, &GPIO_SETUP);	
	
			/*Cau hinh USART*/
			UART_SETUP.USART_BaudRate = 19200;
			UART_SETUP.USART_WordLength = USART_WordLength_8b;
			UART_SETUP.USART_StopBits = USART_StopBits_1;
			UART_SETUP.USART_Parity = USART_Parity_No;
			UART_SETUP.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
			UART_SETUP.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
			USART_Init(USART1, &UART_SETUP);
			 USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
			
			/* Cau hinh vector ngat va muc uu tien */
			NVIC_SETUP.NVIC_IRQChannel = USART1_IRQn;
			NVIC_SETUP.NVIC_IRQChannelSubPriority = 1;
			NVIC_SETUP.NVIC_IRQChannelPreemptionPriority = 2;	
			NVIC_SETUP.NVIC_IRQChannelCmd = ENABLE;
			NVIC_Init(&NVIC_SETUP);
			 // NVIC_EnableIRQ(USART1_IRQn);
			/* xoa co ngat nhan cho lan dau su dung*/
			USART_ClearFlag(USART1, USART_IT_RXNE);
			
			/* Cau hinh cho phep ngat nhan*/
		 


			/* Cho phep UART hoat dong */
			USART_Cmd(USART1, ENABLE);
 //NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_IRQHandler(void)
	{
	
		
		if(USART_GetITStatus ( USART1,USART_IT_RXNE)!=RESET)
		{

			buffer=USART_ReceiveData  ( USART1 );

			USART_SendData  ( USART1,buffer); 

		while (USART_GetITStatus   ( USART1,USART_IT_RXNE)==RESET)
		{
break;
			
		}
if(buffer=='1')
{
	x++;
	delay_ms(100);
	if(x==1)
	{
GPIO_SetBits(GPIOA,GPIO_Pin_5); //do
	}
	if(x>=2|x==0)
	{
 GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		x=0;
}
	}

if(buffer=='2')
{
	y++;
		delay_ms(100);
	if(y==1)
	{
GPIO_SetBits(GPIOA,GPIO_Pin_6);  // vang
	}
	if(y>=2|y==0)
	{
 GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		y=0;
}
	}
	
if(buffer=='3')
{
	z++;
		delay_ms(100);
	if(z==1)
	{
GPIO_SetBits(GPIOA,GPIO_Pin_4);// xanh
	}
	if(z>=2|z==0)
	{
 GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		z=0;
}

}}}
		








