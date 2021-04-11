/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "sys.h"
#include "exti.h"
#include "usart.h"

/////////////////////////////////////////////////////////////////////////////////////

/* Private variables ---------------------------------------------------------*/
uint8_t serial_available_1 = 0;
/* Private variables ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint32_t count = 0;
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);


/* TIM2 init function */
void MX_TIM2_Init(void)
{

  TIM_SlaveConfigTypeDef sSlaveConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_Base_Init(&htim3);

  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_EXTERNAL1;
  sSlaveConfig.InputTrigger = TIM_TS_TI1FP1;
  sSlaveConfig.TriggerPolarity = TIM_TRIGGERPOLARITY_RISING;
  sSlaveConfig.TriggerFilter = 15;
  HAL_TIM_SlaveConfigSynchronization(&htim3, &sSlaveConfig);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

}
/* Private function prototypes -----------------------------------------------*/
TIM_HandleTypeDef  TIM;
uint16_t nPULSE=0;
uint16_t x=0;

void nPWM(uint16_t psc,uint16_t arr ,uint16_t PULSE_NUMBER){
	
	//pinMode(PA8,AF_PP);

	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; /* Peripheral clock enable */
//uint16_t Prescaler = (uint16_t) (SystemCoreClock / 1000000) - 1;
/* Set the Timer prescaler to get 1MHz as counter clock */
TIM1->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS); /* Select the up counter mode */
TIM1->CR1 |= TIM_COUNTERMODE_UP;
TIM1->CR1 &= ~TIM_CR1_CKD;
TIM1->CR1 |= 0;//TIM_CLOCKDIVISION_DIV1; /* Set the clock division to 1*/
TIM1->ARR = arr-1; /* Set the Autoreload value */
TIM1->CCR1 = (arr/2);//PULSE; /* Set the Pulse value */uint16_t PULSE
TIM1->PSC = psc-1; /* Set the Prescaler value */
/////////////////////////
TIM1->RCR = 1 - 1; /* =1PULSE Set the Repetition counter value *//////////////////////////////
/////////////////////////
TIM1->EGR = TIM_EGR_UG; /* Generate an update event to reload the Prescaler
and the repetition counter value immediately */
TIM1->SMCR = RESET; /* Configure the Internal Clock source */
TIM1->CR1 |= TIM_CR1_OPM; /* Select the OPM Mode */
TIM1->CCMR1 &= (uint16_t)~TIM_CCMR1_OC1M;
TIM1->CCMR1 &= (uint16_t)~TIM_CCMR1_CC1S;
TIM1->CCMR1 |= TIM_OCMODE_PWM2;
/* Select the Channel 1 Output Compare and the Mode */
TIM1->CCER &= (uint16_t)~TIM_CCER_CC1P;
/* Set the Output Compare Polarity to High */
TIM1->CCER |= TIM_OCPOLARITY_HIGH;//TIM_OCPolarity_High;
TIM1->CCER = TIM_CCER_CC1E; /* Enable the Compare output channel 1 */
TIM1->BDTR |= TIM_BDTR_MOE; /* Enable the TIM main Output */

TIM1->SR = 0;              // clear interrupt status after the update event
TIM1->DIER = TIM_DIER_UIE; // enable interrupt on update (overflow) event

   NVIC_SetPriority(TIM1_UP_IRQn, 0);
   NVIC_EnableIRQ(TIM1_UP_IRQn);

TIM1->CR1 |= TIM_CR1_CEN; /* Enable the TIM peripheral */


			nPULSE=PULSE_NUMBER-1;

		x=0;

///* set the Timer prescaler to get 1MHz as counter clock */
// Tim1Prescaler= (uint16_t) (SystemCoreClock / 1000000) - 1;
///* Initialize the PWM period to get 20 KHz as frequency from 1MHz */
// Period = 1000000 / 20000;

//	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; /* Peripheral clock enable */
///* configure the Timer prescaler */
// TIM1->PSC = psc-1;
///* configure the period */
// TIM1->ARR = arr-1;
///* configure the repetition counter */
// TIM1->RCR = ((uint32_t) PULSE_NUMBER) -1;
///* configure pulse width */
// TIM1->CCR1 = arr/ 2;
///* Select the Clock Divison to 1*/
//  /* Reset clock Division bit field */
//  TIM1->CR1 &= ~ TIM_CR1_CKD;
//  /* Select DIV1 as clock division*/
//  TIM1->CR1 |= TIM_CLOCKDIVISION_DIV1;
//	
//  /* Select the Up-counting for TIM1 counter */
//  /* Reset mode selection bit fields */
//  TIM1->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
//  /* select Up-counting mode */
//  TIM1->CR1 |= TIM_COUNTERMODE_UP;
//	
//  /* SET PWM1 mode */
//  /* Reset the Output Compare Mode Bits */
//  TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;
//  TIM1->CCMR1 &= ~TIM_CCMR1_CC1S;
//  /* Select the output compare mode 1*/
//  TIM1->CCMR1 |= TIM_OCMODE_PWM1;
//	
//  /* Select active High as output polarity level */
//  /* Reset the Output Polarity level */
//  TIM1->CCER &= ~TIM_CCER_CC1P;
//  /* Set the high Output Compare Polarity */
//  TIM1->CCER |= TIM_OCPOLARITY_HIGH;

//  /* Enable CC1 output on High level*/
//  TIM1->CCER |= TIM_CCER_CC1E;
//		
// /* Select active High as output Complementary polarity level */
// /* Reset the Output N State */
//  TIM1->CCER &= ~TIM_CCER_CC1NP;
// /* Set the Output N Polarity to high level */
//  TIM1->CCER |= TIM_OCNPOLARITY_HIGH;
//	
//  /* Enable CC1 output on High level*/
//  TIM1->CCER |= TIM_CCER_CC1NE;
//  
///******************* COM Control update configuration *********************/

//  /* Set the capture Compare Preload */
//  TIM1->CR2 |= TIM_CR2_CCPC;
//	
//  /* Set CCUS bit to select the COM control update to trigger input TRGI*/
//  TIM1->CR2 |= TIM_CR2_CCUS;

//  /* Enable the Commutation Interrupt sources */
//  TIM1->DIER |= TIM_IT_COM;
///******************************************************************/
//  
///********** Master mode configuration: Trigger Reset mode *********/

//  /* Configure TIM1's trigger output Update to trig TIM2 */
//  TIM1->CR2 &= ~ TIM_CR2_MMS;
//  TIM1->CR2 |= TIM_TRGO_RESET;
///******************************************************************/	
//        
///************ Slave mode configuration : Trigger mode ************/
//	
// /* Select the TIM_TS_ITR1 signal as Input trigger for the TIM */
//  TIM1->SMCR &= ~TIM_SMCR_TS;
//  TIM1->SMCR |= TIM_TS_ITR1;
//	
//  /* Select the Slave Mode */ 
//  TIM1->SMCR &= ~TIM_SMCR_SMS;
//  TIM1->SMCR |= TIM_SLAVEMODE_TRIGGER;
///******************************************************************/	

//  /* Set the UG bit to enable UEV */
//  TIM1->EGR |= TIM_EGR_UG;
//	
//  /* Enable the TIM1 Main Output */
//  TIM1->BDTR |= TIM_BDTR_MOE;
//	
//  /* Enable the TIM Counter */
//  TIM1->CR1 |= TIM_CR1_CEN;

}

void TIM1_UP_IRQHandler(void) {
    TIM1->SR = 0;
    //digitalWrite( PC13, LOW );
	(x++>=nPULSE)? (TIM1->CR1 &= ~TIM_CR1_CEN) :(TIM1->CR1 |= TIM_CR1_CEN);
	
}
void tim2(uint16_t psc,uint16_t arr ,uint16_t PULSE_NUMBER){
//	/* set the Timer prescaler to get 1MHz as counter clock */
// Tim2Prescaler= (uint16_t) ((SystemCoreClock ) / 1000000) - 1;
///* Initialize the PWM period to get 50 Hz as frequency from 1MHz */
// Period = 1000000 / 50;
/* configure the period */
 TIM2->ARR = arr-1;
/* configure the Timer prescaler */
	 TIM2->PSC = psc-1;
///* Select the Clock Divison to 1*/
///* Reset clock Division bit field */
// TIM2->CR1 &= ~ TIM_CR1_CKD;
///* Select DIV1 as clock division*/
// TIM2->CR1 |= TIM_CLOCKDIVISION_DIV1;
///* Select the Up-counting for TIM1 counter */
///* Reset mode selection bit fields */
// TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
///* select Up-counting mode */
// TIM2->CR1 |= TIM_COUNTERMODE_UP;
///****** Master mode configuration: Trigger update mode *******/
///* Trigger of TIM2 Update into TIM1 Slave */
// TIM1->CR2 &= ~ TIM_CR2_MMS;
// TIM2->CR2 |= TIM_TRGO_UPDATE;
///*************************************************************/
///* Enable the TIM Counter */
// TIM2->CR1 |= TIM_CR1_CEN;

 /* Select the Clock Divison to 1*/
  /* Reset clock Division bit field */
  TIM2->CR1 &= ~ TIM_CR1_CKD;
  /* Select DIV1 as clock division*/
  TIM2->CR1 |= TIM_CLOCKDIVISION_DIV1;
	
  /* Select the Up-counting for TIM1 counter */
  /* Reset mode selection bit fields*/
  TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
  /* select Up-counting mode */
  TIM2->CR1 |= TIM_COUNTERMODE_UP;

/********** Master mode configuration: trigger update ***********/	
	
  /* Trigger of TIM2 Update into TIM1 Slave */
  TIM2->CR2 &= ~TIM_CR2_MMS;
  TIM2->CR2 |= TIM_TRGO_UPDATE;
	
/****************************************************************/	
/********** Slave mode configuration: Trigger mode **************/
	
 /* Select the TIM_TS_ITR0 signal as Input trigger for the TIM */
  TIM2->SMCR &= ~TIM_SMCR_TS;
  TIM2->SMCR |= TIM_TS_ITR0;
	
  /* Slave Mode selection: Trigger reset Mode */
  TIM2->SMCR &= ~TIM_SMCR_SMS;
  TIM2->SMCR |= TIM_SLAVEMODE_RESET;
/****************************************************************/	
	
  /* Enable the TIM1 Counter */
  TIM2->CR1 |= TIM_CR1_CEN;
}
//void TIM3_IRQHandler(void)
//{
//if ( (TIM3->SR & TIM_IT_UPDATE) != RESET)
//  {
//    //TIM_ClearITPendingBit(LED_TIM, TIM_IT_Update);
//			
//    // Do ISR stuff here!

//  }
//}

//  void TIM3_IRQHandler(void) {
// 
//      HAL_TIM_IRQHandler(&TIM);
//    }
//	
// int x=0;
//    void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
// 
//      if(htim->Instance == TIM3){
//         // HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//         //digitalWrite( PC13, LOW );	
//				if(x++>=nPULSE) {x=0;TIM3->CR1 &= ~TIM_CR1_CEN;}
//      }
// 
//    }
//void MX_GPIO_Init(void);
//	

char buffer[100];
uint8_t rx_buff[100];
int i=0;



	 uint16_t adcx=0;
	 float  temp=0;

int main(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	HAL_Init();
	SystemClock_Config(); 
	//HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  //////////////////////////////////
	
	/* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
	
	 /*Configure GPIO pin : A8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//MX_GPIO_Init();
//	GPIO_Set(GPIOC,GPIO_PIN_12|GPIO_PIN_13,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_SPEED_FREQ_LOW);

//	GPIO_Set(GPIOD,GPIO_PIN_12|GPIO_PIN_13,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_SPEED_FREQ_LOW);

//	HAL_Delay(2000);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//	
//	EXTIx_Init(GPIOA,GPIO_PIN_0, Trigger_Rising);
	
//		pinMode(PC13,OUTPUT);
//		digitalWrite( PC13, HIGH );
		//delay(500);
//		MX_TIM2_Init();
//	HAL_TIM_Base_Start(&htim3);// Khoi dong timer 2 khong su dung ngat
//	USART_Init(USART1, Pins_PA9PA10, 115200);
//	USART_Puts(USART1, "STM32VN\n");
	
	
	
	//delay(500);
	
//	DMA_USARTx_Init(USART1);
//	HAL_UART_Receive_DMA(&uartdma,rx_buff,100);

	
	tim2(72,20000,0);
//	nPWM(1,2048,0);
	
  while (1)
  {
		tim2(72,20000,20);
		HAL_Delay(1000);
		//TIM2->CCR1 = 100;
 
//		digitalWrite( PC13, LOW );	
//		delay_us(500000);
//		digitalWrite( PC13, HIGH );
//		delay_us(500000);
		
//		char	c = USART_Getc(USART1);//USART1->DR;
//		if (c) {
//			/* If anything received, put it back to terminal */
//			USART_Putc(USART1, c);
//		}
//		
//		count = __HAL_TIM_GetCounter(&htim3); // Doc gia tri bien count cua Timer2
	//	printf("%d\r\n",count );
//		delay(50);
//		if (USART_Gets(USART1, buffer, sizeof(buffer))) 	printf("%s\r\n",buffer);//USART_Puts(USART1,buffer);

		
		
		//		
//		if (serial_available_1) {
//			
//        serial_available_1 = 0;   
//			
//				if (strstr((char*)rx_buff, "\n") != NULL) 
//					{
//						HAL_UART_DMAStop(&uartdma);
//					  USART_Puts(USART1, (char*) rx_buff); 
//					  for(i=0;i<100;i++)rx_buff[i]=0;
//					  HAL_UART_Receive_DMA(&uartdma,rx_buff,100);
//					}
//				
//		}
//		delay(1500);
		
		
  }
  

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct ;
  RCC_ClkInitTypeDef RCC_ClkInitStruct ;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    //Error_Handler();
  }
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    //Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
    //Error_Handler();
  }

	
}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
//void MX_GPIO_Init(void)
//{

//  GPIO_InitTypeDef GPIO_InitStruct;

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOC_CLK_ENABLE();

//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

//  /*Configure GPIO pins : PC13 */
//  GPIO_InitStruct.Pin = GPIO_PIN_13;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if (huart==&uartdma) serial_available_1 = 1;
    //if (huart==&huart2) serial_available_2 = 1;
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
 

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
