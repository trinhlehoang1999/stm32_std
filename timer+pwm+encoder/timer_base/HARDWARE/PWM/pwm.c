#include "pwm.h"
#include "led.h"




/*
 * PWM pins 
 *
 * 	TIMER	|CHANNEL 1				|CHANNEL 2				|CHANNEL 3				|CHANNEL 4
 * 				|PP1	PP2		PP3		|PP1	PP2		PP3		|PP1	PP2		PP3		|PP1	PP2		PP3
 *
 * 	TIM 2	|PA0	PA5		PA15	|PA1	PB3		-			|PA2	PB10	-			|PA3	PB11	-
 * 	TIM 3	|PA6	PB4		PC6		|PA7	PB5		PC7		|PB0	PC8		-			|PB1	PC9		-
 * 	TIM 4	|PB6	PD12	-			|PB7	PD13	-			|PB8	PD14	-			|PB9	PD15	-
 * 	TIM 5	|PA0	PH10	-			|PA1	PH11	-			|PA2	PH12	-			|PA3	PI0		-
 * 	TIM 8	|PC6	PI5		-			|PC7	PI6		-			|PC8	PI7		-			|PC9	PI2		-
 * 	TIM 9	|PA2	PE5		-			|PA3	PE6		-			|-		-		-				|-		-		-
 * 	TIM 10|PB8	PF6		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 11|PB9	PF7		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 12|PB14	PH6		-			|PB15	PH9		-			|-		-		-				|-		-		-
 * 	TIM 13|PA6	PF8		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 14|PA7	PF9		-			|-		-		-				|-		-		-				|-		-		-
 *
*/
//////////////////////////////////////////////////////////////////////////////////	 
			


void PWM_INT_InitTIM1Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;					/* Set pin */
					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;					/* Set pin */
					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;					/* Set pin */
					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM2Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_3:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM3Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_3:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_3:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}

void PWM_INT_InitTIM4Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;					/* Set pin */
					GPIO_Init(GPIOD, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
												/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;					/* Set pin */
					GPIO_Init(GPIOD, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
												/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;					/* Set pin */
					GPIO_Init(GPIOD, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
					/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;					/* Set pin */
					GPIO_Init(GPIOD, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}

void PWM_INT_InitTIM5Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOH, ENABLE);	/* Enable clock */
//					//GPIO_PinAFConfig(GPIOH, GPIO_PinSource10, GPIO_AF_TIM5);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;					/* Set pin */
//					GPIO_Init(GPIOH, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM5);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOH, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOH, GPIO_PinSource11, GPIO_AF_TIM5);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;					/* Set pin */
//					GPIO_Init(GPIOH, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM5);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOH, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOH, GPIO_PinSource12, GPIO_AF_TIM5);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;					/* Set pin */
//					GPIO_Init(GPIOH, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM5);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOI, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOI, GPIO_PinSource0, GPIO_AF_TIM5);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					/* Set pin */
//					GPIO_Init(GPIOI, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM8Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOI, GPIO_PinSource5, GPIO_AF_TIM8);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;					/* Set pin */
//					GPIO_Init(GPIOI, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB2Periph_GPIOI, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOI, GPIO_PinSource6, GPIO_AF_TIM8);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
//					GPIO_Init(GPIOI, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_3:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOI, GPIO_PinSource7, GPIO_AF_TIM8);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
//					GPIO_Init(GPIOI, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_4:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM8);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOC, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOI, GPIO_PinSource2, GPIO_AF_TIM8);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;					/* Set pin */
//					GPIO_Init(GPIOI, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM9Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM9);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;					/* Set pin */
//					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM9);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOE, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM10Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOF, GPIO_PinSource6, GPIO_AF_TIM10);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOF, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}

void PWM_INT_InitTIM11Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOF, GPIO_PinSource7, GPIO_AF_TIM11);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOF, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}

void PWM_INT_InitTIM12Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOH, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOH, GPIO_PinSource6, GPIO_AF_TIM12);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
//					GPIO_Init(GPIOH, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		case PWM_Channel_2:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;					/* Set pin */
					GPIO_Init(GPIOB, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
//					RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);	/* Enable clock */
//					GPIO_PinAFConfig(GPIOH, GPIO_PinSource9, GPIO_AF_TIM12);	/* Alternate function */
//					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
//					GPIO_Init(GPIOH, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}

void PWM_INT_InitTIM13Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM13);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_TIM13);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;					/* Set pin */
					GPIO_Init(GPIOF, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}

void PWM_INT_InitTIM14Pins(PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Common settings */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	switch (Channel) {
		case PWM_Channel_1:
			switch (PinsPack) {
				case PWM_PinsPack_1:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM14);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;					/* Set pin */
					GPIO_Init(GPIOA, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				case PWM_PinsPack_2:
					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	/* Enable clock */
					//GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_TIM14);	/* Alternate function */
					GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;					/* Set pin */
					GPIO_Init(GPIOF, &GPIO_InitStruct);						/* Initialize pin */
													/* Result OK */
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	
	
}


void PWM_InitChannel(TIM_TypeDef* TIMx, PWM_Channel_t Channel, PWM_PinsPack_t PinsPack) {
	if (TIMx == TIM1) {
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		 PWM_INT_InitTIM1Pins(Channel, PinsPack);
	} else if (TIMx == TIM2) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		 PWM_INT_InitTIM2Pins(Channel, PinsPack);
	} else if (TIMx == TIM3) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		 PWM_INT_InitTIM3Pins(Channel, PinsPack);
	} else if (TIMx == TIM4) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
		 PWM_INT_InitTIM4Pins(Channel, PinsPack);
	} else if (TIMx == TIM5) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
		 PWM_INT_InitTIM5Pins(Channel, PinsPack);
	}  else if (TIMx == TIM6) {
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	} else if (TIMx == TIM7) {
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	} else if (TIMx == TIM8) {
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
		 PWM_INT_InitTIM8Pins(Channel, PinsPack);
	} else if (TIMx == TIM9) {
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
		 PWM_INT_InitTIM9Pins(Channel, PinsPack);
	} else if (TIMx == TIM10) {
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
		 PWM_INT_InitTIM10Pins(Channel, PinsPack);
	} else if (TIMx == TIM11) {
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
		 PWM_INT_InitTIM11Pins(Channel, PinsPack);
	} else if (TIMx == TIM12) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
		 PWM_INT_InitTIM12Pins(Channel, PinsPack);
	} else if (TIMx == TIM13) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
		 PWM_INT_InitTIM13Pins(Channel, PinsPack);
	} else if (TIMx == TIM14) {
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
		 PWM_INT_InitTIM14Pins(Channel, PinsPack);
	}

}

void  TIM_OC(TIM_TypeDef* TIMx,PWM_Channel_t Channel)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* Common settings */
	//TIM_OCInitStructure.TIM_Pulse = Pulse;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	switch (Channel) {
		case PWM_Channel_1:
			TIM_OC1Init(TIMx, &TIM_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case PWM_Channel_2:
			TIM_OC2Init(TIMx, &TIM_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case PWM_Channel_3:
			TIM_OC3Init(TIMx, &TIM_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case PWM_Channel_4:
			TIM_OC4Init(TIMx, &TIM_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		default:
			break;
	}
}
////////////////////////////////////////////////////////////////////////////////// 	 
//Luu y: cac he so arr-psc trong cung mot TIM phai co gia tri giong nhau,
//neu set khac nhau no se sung dung he so lenh cuoi cung
// TIM khac nhau thi he so arr-psc giong hay khac deu duoc
void PWM_Init(TIM_TypeDef* TIMx,PWM_Channel_t Channel, PWM_PinsPack_t PinsPack,u32 arr,u32 psc)
{		 					 
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	PWM_InitChannel( TIMx,  Channel,  PinsPack);
	
//	/* Enable clock for Timer */	
//	TIMER_PROPERTIES_EnableClock(TIMx);
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  ///////////////////////
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_Period=arr;   ////////////////////////
	TIM_TimeBaseStructure.TIM_ClockDivision=0;	
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseStructure);
	
	TIM_OC(TIMx,Channel);
 
  TIM_ARRPreloadConfig(TIMx,ENABLE);
	
	TIM_Cmd(TIMx, ENABLE);  
 
										  
}  
//void PWM_Set(TIM_TypeDef* TIMx,PWM_Channel_t Channel,u32 pwm)
//{
//		switch (Channel) {
//		case PWM_Channel_1:
//			TIM_SetCompare1(TIMx,pwm);
//			break;
//		case PWM_Channel_2:
//			TIM_SetCompare2(TIMx,pwm);
//			break;
//		case PWM_Channel_3:
//			TIM_SetCompare3(TIMx,pwm);
//			break;
//		case PWM_Channel_4:
//			TIM_SetCompare4(TIMx,pwm);
//			break;
//		default:
//			break;
//		}
//}
