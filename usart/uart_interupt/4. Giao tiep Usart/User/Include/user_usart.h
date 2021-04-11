
#ifndef __USER_USART_H
#define __USER_USART_H

#include "main.h"

void USART1_Configuration(void);
void USART_OUT(USART_TypeDef* USARTx, char *Data,...);
void USART_SendChar(USART_TypeDef* USARTx, u8 data);
void USART_SendString(USART_TypeDef* USARTx, char*str);
char *itoa(int value, char *string, int radix);
/**************************************************************/
#endif
