////////////#include "stm32f10x.h"
//#include "LED.h"
#include "usart.h"
#include "delay.h"
#include <string.h>
#include "PS2.h"
//#include "uart_neo.h"
//#define USE_USART1
char c;
uint8_t go;
//void ps2_read(uint8_t Data1,uint8_t Data2);
u8 getchar_usart1=0;
u8 ktra=0,cnt=0,y;
uint8_t buff_game[6];
uint8_t RX,RY,LX,LY;
 extern PS2_stat ps2;

/************************************************
www.stm32vn.com
************************************************/




//char a[100] = "abc\n"; // Gán giá tr? cho chu?i a là "abc"
//char b[] = "Arduino.VN - Cong dong Arduino Viet Nam\n";
//void setup() {

//printf("%s\r\n",a);
//  strcpy(a, "arduino.vn"); // Gán chu?i a có giá tr? là "arduino.vn
//printf("%s\r\n",a);
//  strcpy(a, b); // Gán chu?i a có giá tr? là chu?i 
//  printf("%s\r\n",a);
//}
void USART1_IRQHandler()
	{
		ps2_read(buff_game[0],buff_game[1],buff_game[2],buff_game[3],buff_game[4],buff_game[5]);
		if(buff_game[0]==170&&buff_game[1]==170)
			{
			NVIC_SystemReset();
			}

	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET) // Cho ky tu
{
       USART_ClearITPendingBit(USART1,USART_IT_RXNE);
       getchar_usart1 = USART1->DR;
 
       if(ktra == 4 )
       {
             buff_game[cnt++] = getchar_usart1;
             if(cnt > 5)
             {
                  ktra = 0;
                  cnt = 0;

              }
}
 
if(getchar_usart1 == 0xAA) ktra++;
}
	
	}
 int main(void)
 {	
	
	 //LED_init();

//	 pinMode(PB5,OUTPUT);
//	 pinMode(PB6,INPUT);
//	 gpio_config();
//	 usart_config();
	  delay_init();

   USARTx_Init(USART1,Pins_PA9PA10, 19200);

		   USARTx_Init(USART2,Pins_PA2PA3, 115200);
//  setup();
  while(1)
	{
			
//		c='HOANG';
//		delay_ms(1000);
//		if(c) USART_Puts(USART1,c);
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);
		if(ps2.L==1)		    printf("PS2_Left =%d\n",ps2.L);
    if(ps2.D==1)     		printf("PS2_Down=%d\n",ps2.D);
		if(ps2.R==1)        printf("PS2_Right=%d\n",ps2.R);
		if(ps2.U==1)        printf("PS2_Up=%d\n",ps2.U);

		if(ps2.square==1)   printf("PS2_Square=%d\n",ps2.square);
		if(ps2.X==1)	printf("PS2_Cross=%d\n",ps2.X);
		if(ps2.O==1)    printf("PS2_Circle=%d\n",ps2.O);
		if(ps2.trigle==1)	printf("PS2_Trigle=%d\n",ps2.trigle);

		if(ps2.R1==1)	printf("PS2_R1=%d\n",ps2.R1);
		if(ps2.R2==1)	printf("PS2_R2=%d\n",ps2.R2);
		if(ps2.R3==1)	printf("PS2_R3=%d\n",ps2.R3);
		if(ps2.L1==1)	  printf("PS2_L1=%d\n",ps2.L1);
		if(ps2.L2==1)		printf("PS2_L2=%d\n",ps2.L2);
		if(ps2.L3==1)	  printf("PS2_L3=%d\n",ps2.L3);
		
		if(ps2.Select==1)		printf("PS2_Select=%d\n",ps2.Select);
		if(ps2.Start==1)		printf("PS2_Start=%d\n",ps2.Start);
		
		printf("----------------\n");
		
		printf("PS2_RX=%d\n",RX);
		printf("PS2_RY=%d\n",RY);
		printf("PS2_LX=%d\n",LX);
		printf("PS2_LY=%d\n",LY);	
		
		printf("----------------\n");
		delay_ms(400);
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
		




	
