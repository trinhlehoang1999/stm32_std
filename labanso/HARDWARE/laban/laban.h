#ifndef _laban_H
#define _laban_H 			   
#include "sys.h"
#include "usart.h"
#include "misc.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stdlib.h"

//extern USART_TypeDef* USARTx;
//extern USART_PinsPack_t pinspack;

//////////////////////////////////////////////////////////////////////////////////	 
extern uint8_t byte_low,byte_high;
extern int16_t data;

extern void reset_laban(void);
extern void calib_laban(void);
extern void init_laban(USART_TypeDef* USARTx, USART_PinsPack_t pinspack);

extern void value_yaw(USART_TypeDef* USARTx);
extern void value_roll(USART_TypeDef* USARTx);
extern void value_pitch(	USART_TypeDef* USARTx);
//extern void value_pitch(void);
//extern USART_TypeDef* USARTx;
//extern USART_PinsPack_t pinspack;

////////////////////////////////////////////////////////////////////////////////// 
	 

#endif


