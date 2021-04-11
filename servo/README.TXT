#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "string.h"
#include "timer.h"
#include "lcd_txt.h"
#include "ps2.h"
#include "stdbool.h"
#include "stm32f10x_gpio.h"
//#define hoang1
/************************************************
STM32VN
************************************************/
//#define LCD20xN //For lcd20x4
bool check_home;
char buffer[16];
int8_t letter;
float nhietDo = 30.5;
u16 angle=0;
int8_t check=0;
float _step_angle_1,_step_angle_2,_step_angle_3,_step_angle_4,_step_angle_5;
//////////////////
u8 getchar_usart1=0;
u8 ktra=0,cnt=0,y;
uint8_t buff_game[6];
uint8_t RX,RY,LX,LY;
bool status_1=0,status_2=0,status_3=0,status_4=0;
 extern PS2_stat ps2;
 ////////////////////////////

#define SYSCLK (72000000)
#define PRESCALER (72)
 long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


GPIO_InitTypeDef port;
TIM_TimeBaseInitTypeDef timer;
TIM_OCInitTypeDef timerPWM;

#define LED1 PDout(2)// PD2
#define LED0 PAout(8)// PA8
int TIM_Pulse,x_1,x_2,x_3,x_4,x_5;
int x1,x2,x3,x4;
int home1,home2,home3,home4;
char _buffer[]={0,0,0,0};
char kytu;
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

void angle_servo_2(float step_angle2)//210
{
	angle=500;
	_step_angle_2=(float)(angle + 9.05*step_angle2);
	if(_step_angle_2>=2401) _step_angle_2=2400;
	else _step_angle_2=_step_angle_2;
	TIM4->CCR2 = (float)_step_angle_2;
}

void angle_servo_3(float step_angle3)//210
{
	angle=500;
	_step_angle_3=(float)(angle + 9.05*step_angle3);
	if(_step_angle_3>=2401) _step_angle_3=2400;
	else _step_angle_3=_step_angle_3;
	TIM4->CCR3 = (float)_step_angle_3;
}

void angle_servo_4(float step_angle4)//210
{
	angle=500;
	_step_angle_4=(float)(angle + 9.05*step_angle4);
	if(_step_angle_4>=2401) _step_angle_4=2400;
	else _step_angle_4=_step_angle_4;
	TIM4->CCR4 = (float)_step_angle_4;
}

//void angle_servo_5(float step_angle5)//210
//{
//	angle=500;
//	_step_angle_5=(float)(angle + 9.05*step_angle5);
//	if(_step_angle_5>=2401) _step_angle_5=2400;
//	else _step_angle_5=_step_angle_5;
//	TIM3->CCR1 = (float)_step_angle_5;
//}


void servo_init(void) {

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
	TIM_OC2Init(TIM4, &timerPWM);
	TIM_OC3Init(TIM4, &timerPWM);
	TIM_OC4Init(TIM4, &timerPWM);
  TIM_Cmd(TIM4, ENABLE);
}


//void servo_kep_init()
//	{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);
//	GPIO_StructInit(&port);
//	port.GPIO_Mode = GPIO_Mode_AF_PP;
//	port.GPIO_Pin = GPIO_Pin_6;
//	port.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &port);

//	TIM_TimeBaseStructInit(&timer);
//	timer.TIM_Prescaler = PRESCALER-1;
//	timer.TIM_Period = (SYSCLK / PRESCALER / (50))-1;
//	timer.TIM_ClockDivision = 0;
//	timer.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM3, &timer);

//	TIM_OCStructInit(&timerPWM);
////	timerPWM.TIM_Pulse = 1000;
//	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
//	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
//	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OC1Init(TIM3, &timerPWM);
//  TIM_Cmd(TIM3, ENABLE);
//	}

void home (void)
	{
		x_1=home1=110;
		x_2=home2=15;
		x_3=home3=5;
		x_4=home4=170;
		
		angle_servo_1(home1);//105
		angle_servo_2(home2);//15
		angle_servo_3(home3);//5
		angle_servo_4(home4);//170
//		angle_servo_5(130);
	}
void number_1()
	{

	x_1=120;//120  //115
	x_2=75;//75		//5	
	x_3=50;//50		//
	x_4=200;//200
	
	}
	void number_2()
	{
	x_1=105;
	x_2=75;
	x_3=50;
	x_4=175;
	
	}
	void number_3()
	{
	x_1=90;
	x_2=75;
	x_3=60;
	x_4=185;
	
	}
	void number_4()
	{
	x_1=135;
	x_2=70;
	x_3=40;
	x_4=175;
	
	}
		void number_5()
	{
		if (home1<120)
			{
				home1++;
				delay_ms(50);
				x_1=home1;
			}
		else x_1=home1;
			
		if (home2<75)
			{
				home2++;
				delay_ms(50);
				x_2=home2;
			}
		else x_2=home2;
			
		if (home3<50)
			{
				home3++;
				delay_ms(50);
				x_3=home3;
			}
		else x_3=x3;
			
		if (home4<200)
			{
				home4++;
				delay_ms(50);
				x_4=home4;
			}
		else x_4=home4;
//	x_1=110;
//	x_2=70;
//	x_3=30;
//	x_4=175;
	
	}
		void number_6()
	{
	x_1=85;
	x_2=70;
	x_3=30;
	x_4=175;
	
	}
		void number_7()
	{
	x_1=150;
	x_2=55;
	x_3=20;
	x_4=150;
	
	}
		void number_8()
	{
	x_1=105;
	x_2=45;
	x_3=5;
	x_4=170;
	
	}
		void number_9()
	{
	x_1=70;
	x_2=55;
	x_3=10;
	x_4=170;
	
	}
			void X()
	{
	x_1=130;
		
	x_2=75;
		delay_ms(500);
	x_3=6;
		
	x_4=165;
		delay_ms(1000);
	x_1=105;
		
	x_2=80;
		delay_ms(500);
	x_3=26;
		
	x_4=160;
	
	}
	void _auto()
		{
				if(kytu=='1')
{	
		
		number_1(); 
		printf("so 1\r\n");
}	
				else if(kytu=='2')
{	
		number_2(); 
		printf("so 2\r\n");
}	
			else if(kytu=='3')
{	
		number_3(); 
		printf("so 3\r\n");
}	
				else if(kytu=='4')
{	
		number_4(); 
		printf("so 4\r\n");
}	
			else if(kytu=='5'||check==1)
{	
		number_5(); 
		check=1;
		printf("so 5\r\n");
	
}	
			else if(kytu=='6')
{	
		number_6(); 
		printf("so 6\r\n");
}	
			else if(kytu=='7')
{	
		number_7(); 
		printf("so 7\r\n");
}	
			else if(kytu=='8')
{	
		number_8(); 
		printf("so 8\r\n");
}	
			else if(kytu=='9')
{	
		number_9(); 
		printf("so 9\r\n");
}
	
		}
	void _manual()
		{
			if(LX==255)
{

x_1++;
	delay_ms(70);
	
	if (x_1>=210) x_1=210;
}
	else if(LX==0)
	{
	x_1--;
		delay_ms(70);
		
		if (x_1<=0) x_1=0;
	}


	if(LY==0)
{

x_2++;
	delay_ms(70);
	
	if (x_2>=210) x_2=210;
}
	else if(LY==255)
	{
	x_2--;
		delay_ms(70);
		
		if (x_2<=0) x_2=0;
	}
	
		if(RY==0)
{

x_3++;
	delay_ms(40);
	
	if (x_3>=210) x_3=210;
}
	else if(RY==255)
	{
	x_3--;
		delay_ms(40);
		
		if (x_3<=0) x_3=0;
	}
	
	if(RX==255)
{

x_4++;
delay_ms(45);
	
	if (x_4>=210) x_4=210;
}
	else if(RX==0)
	{
		x_4--;
		delay_ms(45);
		
		if (x_4<=0) x_4=0;
	}
	
//	if(ps2.R1==1)
//{

//x_5++;
//delay_ms(10);
//	
//	if (x_5>=200) x_5=200;
//}
//	else if(ps2.R2==1)
//	{
//		x_5--;
//		delay_ms(10);
//		
//		if (x_5<=100) x_5=100;
//	}
		}
int main(void)
{
	
	
	//Init buttons
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_StructInit(&port);
	port.GPIO_Mode = GPIO_Mode_IPU;
	port.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_1;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &port);
  //LED_Init();
	delay_init();
	servo_init();
//	servo_kep_init();
	USARTx_Init(USART1,Pins_PA9PA10, 19200);
	USARTx_Init(USART2,Pins_PA2PA3, 9600);
	
  //lcd_init();

	angle=_step_angle_1=_step_angle_2=_step_angle_3=_step_angle_4=_step_angle_5=0;


	check_home=1;
	home();
	delay_ms(3000);
	home();
	printf("nhap so o:\r\n");

    while(1)
    {
	kytu=USART_Getc(USART2);

	_auto();
	_manual();
	
angle_servo_1(x_1);
angle_servo_2(x_2);
angle_servo_3(x_3);
angle_servo_4(x_4);

    }
}

