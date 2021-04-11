#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "PS2.h"

#define SYSCLK (72000000)
#define PRESCALER (72)

#define DIR_PORT_1         GPIOA
#define DIR_PIN_1          GPIO_Pin_0
#define STEP_PORT_1        GPIOA
#define STEP_PIN_1         GPIO_Pin_1
#define ENABLE_PORT_1      GPIOA
#define ENABLE_PIN_1       GPIO_Pin_2

#define DIR_PORT_2         GPIOA
#define DIR_PIN_2          GPIO_Pin_3
#define STEP_PORT_2        GPIOA
#define STEP_PIN_2         GPIO_Pin_4
#define ENABLE_PORT_2      GPIOA
#define ENABLE_PIN_2       GPIO_Pin_5

#define HIGH            		Bit_SET
#define LOW              		Bit_RESET
	////////////////////
	u8 getchar_usart1=0;
	u8 ktra=0,cnt=0,y;
	uint8_t buff_game[6];
	uint8_t RX,RY,LX,LY;
 extern PS2_stat ps2;
	////////////////
	u16 angle=0;
	float _step_angle_1;
	u8 kytu=0;
	/////////////
	u8 limit_s1=0;
	u8 limit_s2=0;
	u8 home=0;
	u8 mode_check=0;
	u16 run_step1=0,run_step2=0,run_angle=0;
	u8 check = 0,dir_check1=0,dir_check2=0;
	u16 lowSpeed, highSpeed, change, rampUpStop,rampDownStart,d,i;
	u16 _lowSpeed, _highSpeed, _change, _rampUpStop,_rampDownStart,_d,_i;
 char c[100];
///////////////
	int16_t location_x=0,location_y=0;
///////////////
#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
  
 
 void USART1_IRQHandler()
	{
		ps2_read(buff_game[0],buff_game[1],buff_game[2],buff_game[3],buff_game[4],buff_game[5]);
		if(buff_game[0]==170&&buff_game[1]==170)
			{
			NVIC_SystemReset();
			}

	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET) // Cho ky tu
{
       USART_ClearITPendingBit(USART1,USART_IT_RXNE);
       getchar_usart1 = USART1->DR;
 
       if(ktra == 4 )
       {
             buff_game[cnt++] = getchar_usart1;
             if(cnt > 5)
             {
                  ktra = 0;
                  cnt = 0;

              }
}
 
if(getchar_usart1 == 0xAA) ktra++;
}
	
	}
	
	void angle_servo_1(float step_angle1)//210
{
	angle=500;
	_step_angle_1=(float)(angle + 9.05*step_angle1);
	if(_step_angle_1>=2401) _step_angle_1=2400;
	else _step_angle_1=_step_angle_1;
		TIM4->CCR1 = (float)_step_angle_1;
}
  void gpio_init(){
	 GPIO_InitTypeDef GPIO_InitStructure;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  /* Configure PD0 and PD2 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6| GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 }
 
 void servo_init(void) {
	GPIO_InitTypeDef port;
	TIM_TimeBaseInitTypeDef timer;
	TIM_OCInitTypeDef timerPWM;
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);
	GPIO_StructInit(&port);
	port.GPIO_Mode = GPIO_Mode_AF_PP;
	port.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &port);

	TIM_TimeBaseStructInit(&timer);
	timer.TIM_Prescaler = PRESCALER-1;
	timer.TIM_Period = (SYSCLK / PRESCALER / (50))-1;
	timer.TIM_ClockDivision = 0;
	timer.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &timer);

	TIM_OCStructInit(&timerPWM);
//	timerPWM.TIM_Pulse = 1000;
	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4, &timerPWM);
  TIM_Cmd(TIM4, ENABLE);
}
 void simpleAccel(u16 steps) {

   lowSpeed = 3000;
   highSpeed = 1000;
   change = 2;

   rampUpStop = (lowSpeed - highSpeed) / change;
  if ( rampUpStop > steps / 2 ){
		
    rampUpStop = steps / 2;
			}
   rampDownStart = steps - rampUpStop;
   d = lowSpeed;

  for ( i = 0; i < steps; i++) {
    GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,HIGH);
		//delay_us(d);
    GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,LOW);
    delay_us(d);

    if ( i < rampUpStop )
			{
      d -= change;
			}
		else if ( i > rampDownStart )
			{
	      d += change;
			}
		
	printf("%d  %d\r\n",d,i);
	//printf("%d\r\n",i);
  }
	
	
}
 
 void simpleAcce2(u16 steps) {

   _lowSpeed = 3000;
   _highSpeed = 1000;
   _change = 2;

   _rampUpStop = (_lowSpeed - _highSpeed) / _change;
  if ( _rampUpStop > steps / 2 ){
		
    _rampUpStop = steps / 2;
			}
   _rampDownStart = steps - _rampUpStop;
   _d = _lowSpeed;

  for ( _i = 0; _i < steps; _i++) {
		limit_s1=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
		limit_s2=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7);
    GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,HIGH);
    GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,LOW);
    delay_us(_d);

    if ( _i < _rampUpStop )
			{
      _d -= _change;
			}
		else if ( _i > _rampDownStart )
			{
			_d += _change;
			}
		
	printf("%d  %d\r\n",_d,_i);
	//printf("%d\r\n",i);
  }
	
	
}
 void manual ()
	 {

	 if (LX == 0 )
	 {
		 location_x--;
		GPIO_WriteBit(DIR_PORT_1,DIR_PIN_1,HIGH);
		 simpleAccel(2);
//		GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,HIGH);
//		delay_us(500);
//    GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,LOW);
//    delay_us(1000);
		 if (location_x < 1) location_x = 1;
	 }
	 else if (LX == 255)
	 {
		 location_x++;
		GPIO_WriteBit(DIR_PORT_1,DIR_PIN_1,LOW);
		simpleAccel(2);
//		GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,HIGH);
//		delay_us(500);
//    GPIO_WriteBit(STEP_PORT_1,STEP_PIN_1,LOW);
//    delay_us(1000);
		 //if (location_x < 1) location_x = 1;

	 }

	 	else if (LY == 0 )
	 {
		 location_y++;
		GPIO_WriteBit(DIR_PORT_2,DIR_PIN_2,LOW);
		simpleAcce2(2);
//		GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,HIGH);
//		delay_us(10000);
//  	GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,LOW);
//    delay_us(10000);
		//if (location_y < 1) location_y = 1;
	 }
	 else if (LY == 255)
	 {
		location_y--;
		GPIO_WriteBit(DIR_PORT_2,DIR_PIN_2,HIGH);
		simpleAcce2(2);
//		GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,HIGH);
//		delay_us(10000);
//  	GPIO_WriteBit(STEP_PORT_2,STEP_PIN_2,LOW);
//    delay_us(10000);
		 if (location_y < 1) location_y = 1;

	 }

	 }
	 
	 
 
 	void _auto()
		{
		if (kytu==1)
			{
				home=0;
			simpleAccel(15);
			simpleAcce2(70);
				home=1;
			}
				if (kytu==2)
			{
				home=0;
			simpleAccel(20);
			simpleAcce2(45);
				home=1;
			}
				if (kytu==3)
			{
				home=0;
			simpleAccel(1);
			simpleAcce2(1);
				home=1;
			}
				if (kytu==4)
			{
				home=0;
			simpleAccel(1);
			simpleAcce2(1);
				home=1;
			}

			if (home == 1)
				{
				//delay_ms(1000);
				kytu=0;
					
//				simpleAccel(1);
//				simpleAcce2(1);
					
				}

		}
	 int main(void)
 {	
	 gpio_init();
	 delay_init();
	 uart_init(19200);
		servo_init();
			run_angle=100;
	 location_x=location_y=0;
	 home=0;
   //simpleAccel(400);
	 //GPIO_WriteBit(DIR_PORT_1,DIR_PIN_1,LOW);
	 //simpleAccel( 400);
	//	GPIO_WriteBit(DIR_PORT,DIR_PIN,HIGH);
//		simpleAccel(100);
//		delay_ms(100);

  while(1)
	{
		limit_s1=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
		limit_s2=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7);
//		GPIO_WriteBit(DIR_PORT_1,DIR_PIN_1,(bool) dir_check1);
//		GPIO_WriteBit(DIR_PORT_2,DIR_PIN_2,(bool) dir_check2);
//				if (check == 1)
//			{
//				simpleAccel(run_step1);
//				simpleAcce2(run_step2);
//				//delay_ms(300);
//				check = 0;
//			}
		GPIO_WriteBit(ENABLE_PORT_1,ENABLE_PIN_1,LOW);
		GPIO_WriteBit(ENABLE_PORT_2,ENABLE_PIN_2,LOW);
		if(ps2.Start==1 || mode_check==0)
			{
			mode_check=0;
			manual();
			}
			if(ps2.Select==1 || mode_check==1)
			{
			mode_check=1;
			_auto();
			}
		//manual();
		//_auto();
		
			angle_servo_1(run_angle);
			if (limit_s1 == 0 && limit_s2 == 0)
				{
				location_x = location_y = 0;
				}
	}
	//simpleAcce2(x);
	//simpleAccel(x);
 }
 
 
