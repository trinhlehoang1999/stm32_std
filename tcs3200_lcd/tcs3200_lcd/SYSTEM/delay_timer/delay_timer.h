#ifndef DELAY_TIMER_H
#define DELAY_TIMER_H
#include "stm32f10x.h"
extern void delaytimer_int(void);
extern void Delay1Ms(void);
extern void Delay_Ms(uint32_t u32DelayInMs);
extern void Delay_Us(uint32_t delay);


#endif


