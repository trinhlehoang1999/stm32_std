#include "hd44780.h"
#include "delay.h"

//***************************************************************************
//Definitions
//***************************************************************************

//Constants
#define CMD_FCLR								0x01
#define CMD_CLR									0x02
#define CMD_SHIFT_CFG						0x04
#define CMD_DISPLAY_CURSOR			0x08
#define CMD_SCREEN_CURSOR_SHIFT	0x10
#define CMD_BUS_FONT						0x20
#define CMD_CGRAM_ADDR					0x40
#define CMD_DDRAM_ADDR					0x80

#define SHIFT_CFG_ID						0x02
#define SHIFT_CFG_S							0x01
#define DISPLAY_CURSOR_D				0x04
#define DISPLAY_CURSOR_C				0x02
#define DISPLAY_CURSOR_B				0x01
#define SCREEN_CURSOR_SHIFT_SC	0x08
#define SCREEN_CURSOR_SHIFT_RL	0x04
#define	CMD_BUS_FONT_DL					0x10
#define	CMD_BUS_FONT_N					0x80
#define	CMD_BUS_FONT_F					0x40

//Macroses
#define LCD_RS_H()	GPIO_SetBits(LCD_RS_GPIO_Port, LCD_RS_Pin); delay_us(1)
#define LCD_RS_L()	GPIO_ResetBits(LCD_RS_GPIO_Port, LCD_RS_Pin); delay_us(1)
#define LCD_E_H()		GPIO_SetBits(LCD_E_GPIO_Port, LCD_E_Pin); delay_us(1)
#define LCD_E_L()		GPIO_ResetBits(LCD_E_GPIO_Port, LCD_E_Pin); delay_us(1)
#define LCD_RW_H()	GPIO_SetBits(LCD_RW_GPIO_Port, LCD_RW_Pin); delay_us(1)
#define LCD_RW_L()	GPIO_ResetBits(LCD_RW_GPIO_Port, LCD_RW_Pin); delay_us(1)
void gpio_init_LCD()
	{
		
	GPIO_InitTypeDef  GPIO_InitStructure;
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA, ENABLE);	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;   //LCD control pins
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;//LCD data pins D4->D7
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//LCD data pins D0->D
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
//Variables
LcdPinsTypedef LcdPins[8];

//Functions
void LCD_write_IR(uint8_t);
void LCD_write_DR(uint8_t);
void LCD_write(enum enumIrDr, uint8_t);
void LCD_write_8bit(uint8_t);
void LCD_write_4bit(uint8_t);

//***************************************************************************
//Functions realizations
//***************************************************************************

//LCD initialization func
void LCD_Init(void)
{
	gpio_init_LCD();
	LCD_E_L();
	LCD_RS_L();
	LCD_RW_L();
	delay_ms(100);
	LcdPins[4].GPIOx = LCD_D4_GPIO_Port;
	LcdPins[4].PinMask = LCD_D4_Pin;
	LcdPins[5].GPIOx = LCD_D5_GPIO_Port;
	LcdPins[5].PinMask = LCD_D5_Pin;
	LcdPins[6].GPIOx = LCD_D6_GPIO_Port;
	LcdPins[6].PinMask = LCD_D6_Pin;
	LcdPins[7].GPIOx = LCD_D7_GPIO_Port;
	LcdPins[7].PinMask = LCD_D7_Pin;
	
	#ifdef LCD_DATA_4_BIT_MODE
		LCD_write_4bit(0x30);
		delay_ms(10);
		LCD_write_4bit(0x30);
		delay_us(200);
		LCD_write_4bit(0x30);
		LCD_write_4bit(0x20);
		LCD_write(IR, 0x28);
	#else
		LcdPins[0].GPIOx = LCD_D0_GPIO_Port;
		LcdPins[0].PinMask = LCD_D0_Pin;
		LcdPins[1].GPIOx = LCD_D1_GPIO_Port;
		LcdPins[1].PinMask = LCD_D1_Pin;
		LcdPins[2].GPIOx = LCD_D2_GPIO_Port;
		LcdPins[2].PinMask = LCD_D2_Pin;
		LcdPins[3].GPIOx = LCD_D3_GPIO_Port;
		LcdPins[3].PinMask = LCD_D3_Pin;
		LCD_write(IR, 0x30);
		delay_ms(10);
		LCD_write(IR, 0x30);
		Delay_us_ms(USEC, 200);
		LCD_write(IR, 0x30);
		LCD_write(IR, 0x38);
	#endif

	LCD_write(IR, 0x0D);
	LCD_write(IR, 0x01);
	LCD_write(DR, 'H');
	LCD_write(DR, 'e');
	LCD_write(DR, 'l');
	LCD_write(DR, 'l');
	LCD_write(DR, 'o');
	LCD_write(DR, '!');
}

//LCD write function
//dir - write direction (IR - instruction register IR, DR - data register DR)
//data - writing data
void LCD_write(enum enumIrDr dir, uint8_t data){
	switch(dir){
		case IR: LCD_RS_L();
			break;
		case DR: LCD_RS_H();
			break;
		default:
			break;
	}
	#ifdef LCD_DATA_4_BIT_MODE
		LCD_write_4bit(data);
		LCD_write_4bit(data << 4);
	#else
		LCD_write_8bit(data);
	#endif
}

//LCD write function for 8-bit databus mode
void LCD_write_8bit(uint8_t byte){
	int count;
	delay_us(1);
	
	for ( count = 8; count > 0; --count){
		int index = count - 1;

		if ((byte & 0x80) != 0){
			GPIO_SetBits(LcdPins[index].GPIOx, LcdPins[index].PinMask);
		}
		else{
			GPIO_ResetBits(LcdPins[index].GPIOx, LcdPins[index].PinMask);
		}

		byte <<= 1;
	}
	
	LCD_E_H();
	delay_us(1);
	LCD_E_L();
	delay_us(1);
}

//LCD write function for 4-bit databus mode
void LCD_write_4bit(uint8_t byte){
	int count;
	LCD_RW_L();
	
	for (count = 8; count > 4; --count){
		int index = count - 1;
		if ((byte & 0x80) != 0){
			GPIO_SetBits(LcdPins[index].GPIOx, LcdPins[index].PinMask);
		}
		else{
			GPIO_ResetBits(LcdPins[index].GPIOx, LcdPins[index].PinMask);
		}

		byte <<= 1;
	}
	
	LCD_E_H();
	LCD_E_L();
}
