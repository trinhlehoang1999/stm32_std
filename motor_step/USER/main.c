#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "timer.h"

#define IN1 GPIO_Pin_6
#define IN2 GPIO_Pin_7
#define IN3 GPIO_Pin_8
#define IN4 GPIO_Pin_9

uint16_t StepSequence[8] = {IN1, IN1|IN2, IN2, IN2|IN3, IN3, IN3|IN4, IN4, IN4|IN1};
uint8_t MotorStep = 0;
int32_t i=0;
void StepMotorInit(void) {
	GPIO_InitTypeDef  GPIO_InitStructure;

	// Enable PORTB Clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* Configure the pins */
	GPIO_InitStructure.GPIO_Pin = IN1 | IN2 | IN3 | IN4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}

void StepMotorNextStep(void) {
	MotorStep++;
	if (MotorStep > 7)
		MotorStep = 0;
i++; 
	GPIO_Write(GPIOB, StepSequence[MotorStep]);
	delay_ms(1);
}

void StepMotorPrevStep(void) {
	if (MotorStep > 0)
		MotorStep--;
	else
		MotorStep = 7;
i++;
	GPIO_Write(GPIOB, StepSequence[MotorStep]);
	delay_ms(10);
}

int main(void)
{
delay_init();
	StepMotorInit();

    while(1)
    {
//			GPIO_Write(GPIOB, StepSequence[0]);
//			delay_ms(1);
//						GPIO_Write(GPIOB, StepSequence[2]);
   	StepMotorNextStep();
    	/* delay */
    
    }
}
