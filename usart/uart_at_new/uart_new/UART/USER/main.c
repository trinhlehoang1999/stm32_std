#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/************************************************
www.stm32vn.com
************************************************/
int answer;

int sendAT(char* ATcmd, char* rec_answer, unsigned int timeout) {
  int x=0, answer=0; u8 c=0;
  char response[100];
  //unsigned long previous;
  memset(response, '\0', 100);      // Initialize the string  // xoa  ky tu 
  delay_ms(100);
  while( USART_Getc(USART1) > 0) ;
  printf("%s\r\n",ATcmd);
  x = 0;
  //previous = millis();
  do {
		delay_ms(1);
		c= USART_Getc(USART1);//
    if(c){    
      response[x] = c;
      x++;
      if (strstr(response, rec_answer) != NULL)    // kiem tra bien rec_answer co lap lai hay khong
      {
        answer = 1; //ok
      }
    }
  }
  while((answer == 0) && ( --timeout>0 ));    
  return answer;
}


void init_SIM808(void) {
  do { answer = sendAT("AT+CREG?","+CREG: 0,1",1000);} while(answer==0);     // Connecting to the network
// config GSM
  do { answer = sendAT("ATE0","OK",1000);} while(answer==0);
  do { answer = sendAT("AT+CMGF=1", "OK",1000);} while(answer==0);          // Set SMS into text mode
  do { answer = sendAT("AT+CNMI=2,2,2,0,0", "OK",1000);} while(answer==0);  // Hien thi truc tiep noi dung tin nhan
  do { answer = sendAT("AT+CLIP=1", "OK",1000);} while(answer==0);          //Hien thi thon g tin nguoi goi den 
 
  }
 
 int main(void)
 {	
	 //u8 c=0;
	 char buffer[100];
	 //LED_init();
	 delay_init();
	 pinMode(PB5,OUTPUT);
	 pinMode(PB6,INPUT);
	 
	 USARTx_Init(USART1, Pins_PA9PA10, 115200);
	 do { answer = sendAT("AT","OK",1000);} while(answer==0);
	
	 init_SIM808();
  while(1)
	{
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);
		
		if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);
		
		
		
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);
	}
 }
