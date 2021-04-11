#ifndef __DC_MOTOR_H
#define __DC_MOTOR_H	 
#include "sys.h"
#include "pwm.h"		
#include "led.h"

////////////////////////////////////////////////////////////////////////////////// 
void motor_stop(void);
void motor_run(uint8_t x);
void PWM_Init(TIM_TypeDef* TIMx,PWM_Channel_t Channel, PWM_PinsPack_t PinsPack,u32 arr,u32 psc);


		 				    
#endif





