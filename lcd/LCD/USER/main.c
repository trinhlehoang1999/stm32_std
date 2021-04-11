#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "stdio.h"
#include "lcd_txt.h"
#include "hd44780.h"


/************************************************
www.stm32vn.com
************************************************/
float nhietDo = 30.5;
char buffer[16];
int8_t letter = 0x00;

 
 int main(void)
 {	
	 LED_init();
	 delay_init();
   lcd_init();
  while(1)
	{
		sprintf(buffer, "Nhiet do: %0.2f", nhietDo);
		nhietDo = nhietDo + 0.1;
		lcd_puts(1, 0, (int8_t *) buffer);

	}
 }
