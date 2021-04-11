#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "laban.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//USART_TypeDef* USARTx;
//USART_PinsPack_t pinspack;

uint8_t byte_low,byte_high;
int16_t data;

/************************************************
www.stm32vn.com
************************************************/
 
 int main(void)
 {	

	 delay_init();
	 USARTx_Init(USART2, Pins_PA2PA3, 115200);
	  init_laban(USART1,Pins_PA9PA10);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
//	     USART_Putc(USART1,sign[0]);
//		delay_ms(5);
	 
	 		GPIOC->CRH=0x00300000;
		GPIOC->BRR=GPIO_Pin_13;
			delay_ms(100);
			GPIOC->BSRR=GPIO_Pin_13;
			delay_ms(100);
  while(1)
	{
    value_yaw(USART1);
		printf("%d\r\n",data);
//		c=USART_Getc(USART1);
//    USART_Putc(USART1,sign[1]);
//		delay_ms(5);
//		byte_high=USART_Getc(USART1);
//				delay_ms(1);
//		byte_low=USART_Getc(USART1);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		USART_Putc(USART1,sign[2]);
//		delay_ms(5);
//		if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);
		
				 		GPIOC->CRH=0x00300000;
		GPIOC->BRR=GPIO_Pin_13;
			delay_ms(100);
			GPIOC->BSRR=GPIO_Pin_13;
			delay_ms(100);
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);
	}
 }
