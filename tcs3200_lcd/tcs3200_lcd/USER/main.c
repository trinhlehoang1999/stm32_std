#include "stm32f10x.h"
#include "sys.h"
#include "LED.h"
#include "delay.h"
#include "delay_timer.h"
#include "i2c.h"
#include "i2c_lcd.h"
#include "stdio.h"
#include "tcs3200.h"
#include "stdlib.h"

/************************************************
www.stm32vn.com 
************************************************/
char a=0xf7;
 float nhietDo = 30.5;
char buffer1[5];
char buffer2[5];
char buffer3[5];
uint16_t value_cnt=0;
uint16_t ic1_tcs3200;
uint16_t ic2_tcs3200;
int R,G,B;
 
uint8_t value_red=0;
uint8_t value_green=0;
uint8_t value_blue=0;
uint16_t value_tcs3200(uint16_t min,uint16_t max);

 void get_color(void);

//#define led_c13 PCout(13)


 void get_color(void)
	 {
	 	Set_Filter (Red);
		 if(R==1) {
		value_red= value_tcs3200(243,960);
//		I2C_LCD_WriteCmd(0x80);
//		sprintf(buffer1, "R:%3d",value_red);
//	  I2C_LCD_Puts(buffer1);
//    delay_ms(1);
	
			 }
		Set_Filter (Green);
			  if(G==1) {
		value_green= value_tcs3200(430,955);// so max cang lon thi goc cang lon
//		I2C_LCD_WriteCmd(0x85);
//		sprintf(buffer2, "G:%3d",value_green);
//	  I2C_LCD_Puts(buffer2);
		
//    delay_ms(1);
		 }
				
		Set_Filter(Blue);
		   if(B==1) {
		value_blue= value_tcs3200(205,695);
//		I2C_LCD_WriteCmd(0x8B);
//		sprintf(buffer3, "B:%3d",value_blue);
//	  I2C_LCD_Puts(buffer3);
	
//	  delay_ms(1);
		 }
	 }
 
int main(void)
 {	
//		GPIO_InitTypeDef GPIO_led;
//	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
//	 	GPIO_led.GPIO_Pin = GPIO_Pin_13;			
//	  GPIO_led.GPIO_Mode = GPIO_Mode_Out_PP; 
//	  GPIO_led.GPIO_Speed = GPIO_Speed_50MHz;	
//    GPIO_Init(GPIOC, &GPIO_led);
	 LED_init();
	delay_init();
	delaytimer_int();/// khoi tao delay timer

	
	delay_init();
	delaytimer_int();/// khoi tao delay timer
	 
	My_I2C_Init(); //  khoi tao i2c

	I2C_LCD_Init(); // khoi tao i2c lcd
	 
	I2C_LCD_Clear();   // xoa man hinh
	 
	I2C_LCD_BackLight(1); // chon mode light on

	 
//	 	I2C_LCD_WriteCmd(0x80);
//		I2C_LCD_Puts("RED");
//		I2C_LCD_WriteCmd(0x85);
//		I2C_LCD_Puts("GREEN");
//		I2C_LCD_WriteCmd(0x8C);
//		I2C_LCD_Puts("BLUE");

//	 I2C_LCD_WriteCmd(0x80);
//	 I2C_LCD_Puts("   tech3 SPKT   ");
	 
  tcs3200_capture();
	
	// Set_Filter (Red);
		// Set_Filter (Green);
//			 Set_Filter (Blue);
	 Set_Scaling (Scl2);
 
  while(1)
	{
     
		get_color();

			if (value_red<20&&value_green<20&&value_blue<20){
			 I2C_LCD_WriteCmd(0x80);
			 I2C_LCD_Puts("   tech3 SPKT   ");
			 I2C_LCD_WriteCmd(0xc2);
	     I2C_LCD_Puts("WAITING SCAN    ");
				delay_ms(4000);
		}  
		 if (((value_blue>=140)&&(value_green<=34))&&(value_red<value_blue&&value_green<value_red))  {
			 I2C_LCD_WriteCmd(0xc1);
			 I2C_LCD_Puts(" BLUE detected  ");
				delay_ms(4000);
			}
		 if ((184<value_red<203)&&(30<=value_green<=60)&&(value_red>value_blue&&value_blue>value_green)){
			 I2C_LCD_WriteCmd(0xc1);
			 I2C_LCD_Puts(" GREEN detected");
			 delay_ms(4000);
		}  
//			if (((10<value_red<34)&&(160<value_blue<175))&&(value_green<value_red&&value_blue>value_green)){
//			 I2C_LCD_WriteCmd(0xc1);
//			 I2C_LCD_Puts(" ORANGE detected");
//				delay_ms(4000);
//		} 
			 if ((value_green>=222)&&(value_blue>=200)&&(value_blue>value_red&&value_red<value_green))  {
			 I2C_LCD_WriteCmd(0xc1);
			 I2C_LCD_Puts(" PINK detected   ");
				 delay_ms(4000);
		} 
			 if ((value_red<=16)&&(70<=value_green<=100)&&(value_blue>value_red&&value_blue>value_green)){
			 I2C_LCD_WriteCmd(0xc1);
			 I2C_LCD_Puts(" YELLOW detected  ");
			delay_ms(4000);
		}  
		if ((value_red>=234)&&(value_blue>=230)&&(value_green<value_red&&value_blue>value_green)){
			 I2C_LCD_WriteCmd(0xc1);
			 I2C_LCD_Puts(" WHITE detected  ");
			delay_ms(4000);
		} 

//    ic2_tcs3200=TIM2->CCR2;
		//value_red= value_tcs3200(220,740);  //RED=220,2020,GREEN=210,2015,BLUE=220,740
		

		

//		


//    led_c13=1;
//		delay_ms(100);
//		led_c13=0;
//		delay_ms(100);
	}
	
 }
 
//void TIM2_IRQHandler(void)
//	{
//		if(TIM_GetITStatus(TIM2,TIM_IT_CC1))
//			{
//				TIM_ClearITPendingBit(TIM2,TIM_IT_CC1);
//				ic1_tcs3200=TIM_GetCapture1(TIM2);
//			  ic2_tcs3200=TIM2->CCR2;
//				

//			}

//	}
 
 
 
