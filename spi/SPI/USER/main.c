#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "Led7Control.h"
/************************************************
www.stm32vn.com
************************************************/


///////////////////////////////////////////////////////////////////////

 
 int main(void)
 {	
	 //u8 c=0;
	 u16 delaytime=800;
	 char buffer[100];
	 //LED_init();
	 delay_init();
	 //pinMode(PB5,INPUT_PULLUP);
//	 pinMode(PB6,INPUT);
//	 
	 USARTx_Init(USART2, Pins_PA2PA3, 115200);
//	 do { answer = sendAT("AT","OK",1000);} while(answer==0);
//	
//	 init_SIM808();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
	 	Led7Control(PB15,PB13,PB12,8);
	/*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  LedControl_shutdown(0,false);
  /* Set the brightness to a medium values */
  LedControl_setIntensity(0,15);
  /* and clear the display */
  LedControl_clearDisplay(0);
	
//	delay_ms(delaytime);
//	LedControl_setChar(0,0,'a',false);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x05);
//  delay_ms(delaytime);
//  LedControl_setChar(0,0,'d',false);
//  delay_ms(delaytime);
//  LedControl_setRow(0,3,0x04);
//  delay_ms(delaytime);
//  LedControl_setRow(0,2,0x04);
//  delay_ms(delaytime);
//  LedControl_setRow(0,1,0x02);
//  delay_ms(delaytime);
//  LedControl_setRow(0,3,0x6d);
// delay_ms(delaytime);
//  LedControl_clearDisplay(0);
 
//	LedControl_setDigit(0,7,0,false);
//	 delay_ms(delaytime);
//		LedControl_setDigit(0,6,9,false);
//		 delay_ms(delaytime);
//			LedControl_setDigit(0,5,0,false);
//			 delay_ms(delaytime);
//				LedControl_setDigit(0,4,5,false);
//				 delay_ms(delaytime);
//					LedControl_setDigit(0,3,2,false);
//					 delay_ms(delaytime);
//						LedControl_setDigit(0,2,0,false);
//						 delay_ms(delaytime);
//							LedControl_setDigit(0,1,2,false);
//								//LedControl_setDigit(0,0,0,false);
//								  delay_ms(delaytime);
//	for( int i=0;i<13;i++) {
//    LedControl_setDigit(0,7,i,false);
//    LedControl_setDigit(0,6,i+1,false);
//    LedControl_setDigit(0,5,i+2,false);
//    LedControl_setDigit(0,4,i+3,false);
//    delay_ms(delaytime);
//  }
 LedControl_clearDisplay(0);
  LedControl_clearDisplay(0x0a);
	 LedControl_clearDisplay(0x0b);
	  LedControl_clearDisplay(0x09);
		 LedControl_clearDisplay(0x0f);
		 
		  LedControl_setDigit(0,7,0,false);
		 LedControl_setDigit(0,6,1,false);
		   delay_ms(delaytime);
				 LedControl_setDigit(0,5,2,false);
		 LedControl_setDigit(0,4,3,false);
		   delay_ms(delaytime);
		LedControl_setDigit(0,3,4,false);
				 LedControl_setDigit(0,2,5,false);
		LedControl_setDigit(0,1,6,false);
    LedControl_setRow(0,0,0x02);
  delay_ms(delaytime);
//  delay_ms(delaytime);
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	 
  while(1)
	{
//										  delay_ms(delaytime);

//			for( int i=0;i<13;i++) {
//    LedControl_setDigit(0,7,i,false);
//    LedControl_setDigit(0,6,i+1,false);
//    LedControl_setDigit(0,5,i+2,false);
//    LedControl_setDigit(0,4,i+3,false);
//    delay_ms(delaytime);
//  }
////  LedControl_clearDisplay(0);
//  delay_ms(delaytime);
//			LedControl_setDigit(0,7,0,false);

//		LedControl_setDigit(0,6,9,false);


//				LedControl_setDigit(0,4,5,false);
//	
//					LedControl_setDigit(0,3,2,false);
//		
//						LedControl_setDigit(0,2,0,false);
//					
//							LedControl_setDigit(0,1,2,false);
//								//LedControl_setDigit(0,0,0,false);
//								  delay_ms(delaytime);
//		
//		LedControl_setDigit(0,4,5,false);
//		 delay_ms(delaytime);
////	delay_ms(delaytime);
//	LedControl_setChar(0,5,'a',false);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x05);
//  delay_ms(delaytime);
//  LedControl_setChar(0,0,'d',false);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x1c);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x10);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x15);
//  delay_ms(delaytime);
//  LedControl_setRow(0,0,0x1D);
//  delay_ms(delaytime);
//  LedControl_clearDisplay(8);
//  delay_ms(delaytime);
//		c=USART_Getc(USART1);
//		if(c) USART_Putc(USART1,c);
		
		//if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);
		
//		if(ReadPin(PBin(5))==0) printf("abc\r\n");
//		delay_ms(10);
		
//	digitalWrite( PB5, HIGH );delay_ms(300);
//	digitalWrite( PB5, LOW );delay_ms(300);
	}
 }
