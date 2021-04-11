#include "stm32f10x.h"
//#include "LED.h"
#include "usart.h"
#include "delay.h"
#include <string.h>
//#define USE_USART1
char c;
char buffer[2]="h";

/************************************************
www.stm32vn.com
************************************************/




char a[100] = "abc\n"; // Gán giá tr? cho chu?i a là "abc"
char b[] = "Arduino.VN - Cong dong Arduino Viet Nam\n";
void setup() {

printf("%s\r\n",a);
  strcpy(a, "arduino.vn"); // Gán chu?i a có giá tr? là "arduino.vn
printf("%s\r\n",a);
  strcpy(a, b); // Gán chu?i a có giá tr? là chu?i 
  printf("%s\r\n",a);
}

 int main(void)
 {	

	 //LED_init();

//	 pinMode(PB5,OUTPUT);
//	 pinMode(PB6,INPUT);
//	 gpio_config();
//	 usart_config();
	  delay_init();
	
   USARTx_Init(USART1,Pins_PA9PA10, 115200);
		
  setup();
  while(1)
	{
//		c='HOANG';
//		delay_ms(1000);
//		if(c) USART_Puts(USART1,c);
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);

//		if (USART_Gets(USART1,buffer,sizeof(buffer))) 
//{
//		//printf("%s\r\n",buffer);
//		delay_ms(1000);
//		USART_Puts(USART1,buffer);
//	}	
		
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);

		 

 			

//GPIO_SetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
//delay_ms(200);
//GPIO_ResetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
//delay_ms(200);

	
	
}}
		




	
