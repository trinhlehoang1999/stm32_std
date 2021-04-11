
#include "main.h"
#include "var.h" 
int main(void)
{
char str[50],i;
SystemInit();
NVIC_Configuration();
GPIO_Configuration();
TIMER1_Configuration();
USART1_Configuration();
delay_init(72);
USART_SendString(USART1," wWw.HocARM.net - USART1 STM32 START\r\n");
sprintf(str,"\n\rDEMO USART\n\r");
USART_SendString(USART1,str);
while(1)
 {	
	unsigned char c; c=USART_ReceiveData(USART1);
	 
	if(c=='3'){ USART_SendString(USART1," wWw.HocARM.net - USART1 STM32 START\r\n");}
	if(c=='1'){ PORTB=0x00;}
	if(c=='2'){ PORTB=0xFF;}
 }
}


