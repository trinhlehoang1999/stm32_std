#include "laban.h"
#include "sys.h"
#include "usart.h"
char sign[5]={'a','c','y','r','p'};

void value_yaw(USART_TypeDef* USARTx)
		{
	
			if(USARTx==USART1)
				{

		USART_Putc(USART1,sign[2]);
		delay_ms(1);
		byte_high=USART_Getc(USART1);
		delay_ms(1);
		byte_low=USART_Getc(USART1);
		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
		delay_ms(1);
					}
//	else if(USARTx==USART2)
//				{
//		USART_Putc(USART2,sign[2]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART2);
//		delay_ms(1);
//		byte_low=USART_Getc(USART2);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 	
//					else if(USARTx==USART3)
//				{
//		USART_Putc(USART3,sign[2]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART3);
//		delay_ms(1);
//		byte_low=USART_Getc(USART3);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 	
//				else if(USARTx==USART4)
//				{
//		USART_Putc(USART2,sign[2]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART2);
//		delay_ms(1);
//		byte_low=USART_Getc(USART2);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 				else if(USARTx==USART5)
//				{
//		USART_Putc(USART2,sign[2]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART2);
//		delay_ms(1);
//		byte_low=USART_Getc(USART2);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		}
				}
		
		
void value_roll(USART_TypeDef* USARTx)
		{

			if(USARTx==USART1)
				{
		USART_Putc(USART1,sign[3]);
		delay_ms(1);
		byte_high=USART_Getc(USART1);
		delay_ms(1);
		byte_low=USART_Getc(USART1);
		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
		delay_ms(1);
		}
				else if(USARTx==USART2)
				{
		USART_Putc(USART2,sign[3]);
		delay_ms(1);
		byte_high=USART_Getc(USART2);
		delay_ms(1);
		byte_low=USART_Getc(USART2);
		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
		delay_ms(1);
		} 	}
				//else if(USARTx==USART3)
//				{
//		USART_Putc(USART3,sign[3]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART3);
//		delay_ms(1);
//		byte_low=USART_Getc(USART3);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 	
////				else if(USARTx==USART4)
////				{
////		USART_Putc(USART2,sign[3]);
////		delay_ms(1);
////		byte_high=USART_Getc(USART4);
////		delay_ms(1);
////		byte_low=USART_Getc(USART4);
////		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
////		delay_ms(1);
////		} 				else if(USARTx==USART5)
////				{
////		USART_Putc(USART5,sign[3]);
////		delay_ms(1);
////		byte_high=USART_Getc(USART5);
////		delay_ms(1);
////		byte_low=USART_Getc(USART5);
////		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
////		delay_ms(1);
////		}
//				
//		}
		
void value_pitch(	USART_TypeDef* USARTx)
		{
		 if(USARTx==USART1)
				{
		USART_Putc(USART1,sign[4]);
		delay_ms(1);
		byte_high=USART_Getc(USART1);
		delay_ms(1);
		byte_low=USART_Getc(USART1);
		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
		delay_ms(1);
		}
//				else if(USARTx==USART2)
//				{
//		USART_Putc(USART2,sign[4]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART2);
//		delay_ms(1);
//		byte_low=USART_Getc(USART2);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 	else if(USARTx==USART3)
//				{
//		USART_Putc(USART3,sign[4]);
//		delay_ms(1);
//		byte_high=USART_Getc(USART3);
//		delay_ms(1);
//		byte_low=USART_Getc(USART3);
//		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
//		delay_ms(1);
//		} 	
////				else if(USARTx==USART4)
////				{
////		USART_Putc(USART4,sign[4]);
////		delay_ms(1);
////		byte_high=USART_Getc(USART4);
////		delay_ms(1);
////		byte_low=USART_Getc(USART4);
////		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
////		delay_ms(1);
////		} 				else if(USARTx==USART5)
////				{
////		USART_Putc(USART5,sign[4]);
////		delay_ms(1);
////		byte_high=USART_Getc(USART5);
////		delay_ms(1);
////		byte_low=USART_Getc(USART5);
////		data=(int16_t)((byte_high<<8|byte_low)+1800)/10;
////		delay_ms(1);
////		}
			}
//			

void init_laban( USART_TypeDef* USARTx, USART_PinsPack_t pinspack)
	{
	
	USARTx_Init(USARTx,pinspack,115200);
	reset_laban();
	}
void reset_laban()
	{ 
	    USART_Putc(USART1,sign[0]);
  		delay_ms(5);
	}

void calib_laban()
	{
		  USART_Putc(USART1,sign[1]);
  		delay_ms(5);
	}


