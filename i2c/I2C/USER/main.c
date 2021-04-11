#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


#include "dht11.h"

#include "myiic.h" 
#include "ds1307.h"

/************************************************
www.stm32vn.com
************************************************/
int answer;

int sendAT(char* ATcmd, char* rec_answer, unsigned int timeout) {
  int x=0, answer=0; u8 c=0;
  char response[100];
  //unsigned long previous;
  memset(response, '\0', 100);      // Initialize the string
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
      if (strstr(response, rec_answer) != NULL)    
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

u8 scans_IIC( u8 add)	{
	
	IIC_Start();	
	IIC_Send_Byte(add|0);
	if(IIC_Wait_Ack()) {IIC_Stop(); return 1;}
	
	return 0;
}

u8 gio,phut,giay,thu,ngay,thang,nam;

 int main(void)
 {	
	 //u8 c=0;
	 u8 add=0, err=0;
	 u8 temp=0,humi=0;
	 char buffer[100];
	 //LED_init();
	 delay_init();
	 pinMode(PB5,OUTPUT);
	 pinMode(PB6,INPUT);
	 
	 USARTx_Init(USART2, Pins_PA2PA3, 115200);
	 printf("abc\r\n");
	 DS1307_Init();
	 delay_ms(100);
	 RTC_SetDateTime(5,03,0,4,29,4,20);
	 
	 //DHT11_Init();
//	 USARTx_Init(USART1, Pins_PA9PA10, 115200);
//	 do { answer = sendAT("AT","OK",1000);} while(answer==0);
//	
//	 init_SIM808();
  while(1)
	{
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);
		
		RTC_GetDateTime(&gio,&phut,&giay,&thu,&ngay,&thang,&nam);
		printf("gio:%d--phut:%d--giay:%d \n\t %d/%d/%d \r\n",gio,phut,giay,ngay,thang,2000+nam);
		delay_ms(500);
		
//		for(add=1;add<255;add++){
//			err=scans_IIC(add);
//			if(err==0){printf("ADD= 0x%X\r\n",add);}
//		}		
//			delay_ms(1500);delay_ms(1300);delay_ms(1500);
		//if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);
		
//		DHT11_Read_Data(&temp,&humi);
//		printf("%d--%d\r\n",temp,humi);
//		delay_ms(300);
		
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);
	}
 }
