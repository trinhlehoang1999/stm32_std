#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "adc.h"

/************************************************
www.stm32vn.com
************************************************/

extern u16 ADC_ConvertedValue[2];

 
 int main(void)
 {	
	 u8 c=0;
	 u16 adcx[2];
	 float  temp=0;
	 
	 	 u16 adcx1=0;
	 float  temp1=0;
	 char buffer[100];
	 //LED_init();
	 delay_init();
	 pinMode(PB5,OUTPUT);
	 pinMode(PB6,INPUT);
	 
	 USARTx_Init(USART1, Pins_PA9PA10, 115200);
	 Adc_Init(ADC1,ADC_Channel_0);
   Adc_Init(ADC1,ADC_Channel_1);
  while(1)
	{
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);
//		
//		if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);
//		
//		
	
		
		temp=(float)ADC_ConvertedValue[0]*(3.3/4096);
//		adcx=temp;
		temp1=ADC_ConvertedValue[1];
		
//		   	adcx1=Get_Adc_Average(ADC1,ADC_Channel_1,10);
//				temp1=(float)adcx1*(3.3/4096);
//		adcx1=temp1;
		//xuat LCD-UART
		printf("temp0:%f\n",temp);
		printf("temp1:%f\n",temp1);
		delay_ms(250);
		
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);
	}
 }
