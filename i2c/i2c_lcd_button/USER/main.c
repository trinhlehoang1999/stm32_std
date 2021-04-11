#include "stm32f10x.h"
#include "sys.h"
#include "LED.h"
#include "delay.h"
#include "delay_timer.h"
#include "i2c.h"
#include "i2c_lcd.h"
#include "stdio.h"


/************************************************
www.stm32vn.com 
************************************************/
char a=0xf7;
 float nhietDo = 30.5;
char buffer[2];
 int main(void)
 {	
	
	 LED_init();
	 delay_init();
	delaytimer_int();/// khoi tao delay timer

	My_I2C_Init(); //  khoi tao i2c
	
	I2C_LCD_Init(); // khoi tao i2c lcd
	 
	 I2C_LCD_Clear();   // xoa man hinh
	I2C_LCD_BackLight(1); // chon mode light on
	 
	 	I2C_LCD_WriteCmd(0x81);
	I2C_LCD_Puts(&a);
	 	I2C_LCD_WriteCmd(0xc0);
	 I2C_LCD_Puts("value:");
 
  while(1)
	{
			 	I2C_LCD_WriteCmd(0xc7);
sprintf(buffer, "%0.1f", nhietDo);
				nhietDo = nhietDo + 0.1;
	I2C_LCD_Puts(buffer);
		Delay_Ms(200);

	}
	
 }
