#include "stm32f10x.h"
/********************/
#include "i2c_lcd.h" //   
#include "stdio.h"//            // de su dung lcd i2c phai add 4 thu vien nay
#include "i2c.h"//
#include "delay_timer.h"//
/********************/  
  char * x=0;
float nhietDo = 30.5;
char buffer[16];
int8_t letter = 0x5C;

int main(void)
{
	GPIO_InitTypeDef gpioInit;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = GPIO_Pin_13;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpioInit);

	delaytimer_int();/// khoi tao delay timer

	My_I2C_Init(); //  khoi tao i2c
	
	I2C_LCD_Init(); // khoi tao i2c lcd
	
	I2C_LCD_Clear();
	I2C_LCD_BackLight(1);
	I2C_LCD_WriteCmd(0x83);
	I2C_LCD_Puts("lehoang1714");
		I2C_LCD_WriteCmd(0xc0);
	I2C_LCD_Puts("x");
//	I2C_LCD_WriteCmd(0xc3);
//	I2C_LCD_Puts("LIKE -DOG");
	
	while (1) {
			I2C_LCD_WriteCmd(0xc2);
		sprintf(buffer, "%0.2f", nhietDo);
		nhietDo = nhietDo + 0.1;
		x++;
		


		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		Delay_Ms(500);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		Delay_Ms(500);
	}
}
