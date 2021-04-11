#ifndef tcs3200_H
#define tcs3200_H

#include "stm32f10x.h"
#include "sys.h"

#define pin_S0 GPIO_Pin_4
#define pin_S1 GPIO_Pin_5
#define pin_S2 GPIO_Pin_6
#define pin_S3 GPIO_Pin_7
#define pin_OUT GPIO_Pin_0
#define port GPIOA


 extern long map(long x, long in_min, long in_max, long out_min, long out_max);
enum Colors{Red, Blue, Clear, Green};
enum Scaling{Scl0, Scl2, Scl20, Scl100};
extern uint16_t ic1_tcs3200;
extern uint16_t ic2_tcs3200;



extern void tcs3200_gpio(void);
extern void tcs3200_capture(void);
extern void Set_Filter (uint8_t mode1);
extern void Set_Scaling (uint8_t mode2);
extern void TIM2_IRQHandler(void);
extern uint16_t value_tcs3200(uint16_t min,uint16_t max);
extern int R,G,B;

#endif 






