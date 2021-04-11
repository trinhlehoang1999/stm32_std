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
int check_auto=0;
int check_home;
char buffer[16];
int8_t letter;
float nhietDo = 30.5;
u16 angle=0,t=0;
u8 check=0;
u8 _cnt=0;
float _step_angle_1,_step_angle_2,_step_angle_3,_step_angle_4,_step_angle_5;
//////////////////
u8 getchar_usart1=0;
u8 ktra=0,cnt=0,y;
uint8_t buff_game[6];
uint8_t RX,RY,LX,LY;
int status_1=0,status_2=0,status_3=0,status_4=0;
 extern PS2_stat ps2;
 ////////////////////////////

#define SYSCLK (72000000)
#define PRESCALER (72)

GPIO_InitTypeDef port;
TIM_TimeBaseInitTypeDef timer;
TIM_OCInitTypeDef timerPWM;

#define LED1 PDout(2)// PD2
#define LED0 PAout(8)// PA8
int TIM_Pulse,x_1,x_2,x_3,x_4,x_5;
int x1,x2,x3,x4;
int goc1,goc2,goc3,goc4;
int m1_angle=0;
int goc1=0;
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

void angle_servo_1(int step_angle1)//210
{
	angle=500;
	_step_angle_1=(float)(angle + 9.05*step_angle1);
	if(_step_angle_1>=2400) _step_angle_1=2400;
	else _step_angle_1=_step_angle_1;
		TIM4->CCR1 = (float)_step_angle_1;
}

void angle_servo_2(float step_angle2)//210
{
	angle=500;
	_step_angle_2=(float)(angle + 9.05*step_angle2);
	if(_step_angle_2>=2400) _step_angle_2=2400;
	else _step_angle_2=_step_angle_2;
	TIM4->CCR2 = (float)_step_angle_2;
}

void angle_servo_3(float step_angle3)//210
{
	angle=500;
	_step_angle_3=(float)(angle + 9.05*step_angle3);
	if(_step_angle_3>=2400) _step_angle_3=2400;
	else _step_angle_3=_step_angle_3;
	TIM4->CCR3 = (float)_step_angle_3;
}

void angle_servo_4(float step_angle4)//210
{
	angle=500;
	_step_angle_4=(float)(angle + 9.05*step_angle4);
	if(_step_angle_4>=2400) _step_angle_4=2400;
	else _step_angle_4=_step_angle_4;
	TIM4->CCR4 = (float)_step_angle_4;
}



void servo_init(void) {

	
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

	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4, &timerPWM);
	TIM_OC2Init(TIM4, &timerPWM);
	TIM_OC3Init(TIM4, &timerPWM);
	TIM_OC4Init(TIM4, &timerPWM);
  TIM_Cmd(TIM4, ENABLE);
}




void home ()
	{
		x_1=goc1=115;
		x_2=goc2=30;
		x_3=goc3=20;
		x_4=goc4=155;

	}

void giatoc1(int goc1, int t)
{

if (x_1!=goc1)
	{
		x1=0;
//		delay_ms(50);
		if(x_1<goc1) 
			{
				x_1++;
				delay_ms(t);
			}
		else if (x_1>goc1)
			{
				x_1--;
				delay_ms(t);
			}
		else 
			{	
				
				x_1=goc1;
			}

	}
		else 
	{
		x1=1;
	}
}

void giatoc2(int goc2, int t)
{
if (x_2!=goc2)
	{
		x2=0;
//		delay_ms(50);
		if(x_2<goc2) 
			{
				x_2++;
				delay_ms(t);
			}
		else if (x_2>goc2)
			{
				x_2--;
				delay_ms(t);
			}
		else 
			{	
				
				x_2=goc2;
			}
			
	}
	else x2 = 1;
}
void giatoc3(int goc3, int t)
{
if (x_3!=goc3)
	{
		x3=0;
//		delay_ms(50);
		if(x_3<goc3) 
			{
				x_3++;
				delay_ms(t);
			}
		else if (x_3>goc3)
			{
				x_3--;
				delay_ms(t);
			}
		else 
			{	
				
				x_3=goc3;
			}
			
	}
	else x3 = 1;
}
void giatoc4(int goc4, int t)
{
if (x_4!=goc4)
	{
		x4=0;
//		delay_ms(50);
		if(x_4<goc4) 
			{
				x_4++;
				delay_ms(t);
			}
		else if (x_4>goc4)
			{
				x_4--;
				delay_ms(t);
			}
		else 
			{	
				
				x_4=goc4;
			}
			
	}
	else x4 = 1;
}
void angle_1(int goc_1,int t)
	{
	giatoc1(goc_1,t);
	angle_servo_1(x_1);
	}
	
	void angle_2(int goc_2,int t)
	{
	giatoc2(goc_2,t);
	angle_servo_2(x_2);
	}
		void angle_3(int goc_3,int t)
	{
	giatoc3(goc_3,t);
	angle_servo_3(x_3);
	}
		void angle_4(int goc_4,int t)
	{
	giatoc4(goc_4,t);
	angle_servo_4(x_4);
	}
	
	
	void _auto()
		{
		if (kytu == '1' || status_1==1)
			{
			goc1=112;
			goc2=91; 	
			goc3=61;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ; 
			}	
		else if (kytu == '2'|| status_1==2)
			{
			goc1=98;
			goc2=95;
			goc3=59;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '3' || status_1==3)
			{
			goc1=74;
			goc2=87;
			goc3=55;
			goc4=167;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '4' || status_1==4)
			{
			goc1=123;
			goc2=86;
			goc3=35;
			goc4=160;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '5' || status_1==5)
			{
			goc1=99;
			goc2=84;
			goc3=29;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '6' || status_1==6)
			{
			goc1=70;
			goc2=89;
			goc3=40;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '7' || status_1==7)
			{
			goc1=138;
			goc2=72;
			goc3=14;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '8' || status_1==8)
			{
			goc1=104;
			goc2=74;
			goc3=12;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		else if (kytu == '9' || status_1==9)
			{
			goc1=54;
			goc2=75;
			goc3=21;
			goc4=155;
			_cnt=1;
			check_auto=0;
			status_1 = 0 ;
			}
		if (_cnt == 1 && x1==1 && x2 ==1 &&x3 ==1 && x4 == 1 && check == 1)
			{
				_cnt=2;
				check_auto=1;

			}
			
		}
		
	void _manual()
		{
			if(LX==255)
{

	x_1++;
	delay_ms(75);
	
	if (x_1>=210) x_1=210;
}
	else if(LX==0)
	{
	x_1--;
		delay_ms(75);
		
		if (x_1<=0) x_1=0;
	}

	if(LY==0)
{

x_2++;
	delay_ms(75);
	
	if (x_2>=210) x_2=210;
}
	else if(LY==255)
	{
	x_2--;
		delay_ms(75);
		
		if (x_2<=0) x_2=0;
	}
	
		if(RY==0)
{

	x_3++;
	delay_ms(75);
	
	if (x_3>=210) x_3=210;
}
	else if(RY==255)
	{
	x_3--;
		delay_ms(75);
		
		if (x_3<=0) x_3=0;
	}
	
	if(RX==255)
{

x_4++;
delay_ms(75);
	
	if (x_4>=210) x_4=210;
}
	else if(RX==0)
	{
		x_4--;
		delay_ms(75);
		
		if (x_4<=0) x_4=0;
	}

		}
		void reset_mcu()
			{
			if (ps2.R1 == 1)
				{
				NVIC_SystemReset();
				}
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

	delay_init();
	servo_init();

	USARTx_Init(USART1,Pins_PA9PA10, 19200);
	USARTx_Init(USART2,Pins_PA2PA3, 9600);

	check = 0;
  home();
	delay_ms(1500);
	status_1=status_2=0;
	check_home=1;
	check_auto=0;
	printf("nhap so o:\r\n");

    while(1)
    {
	reset_mcu();
	kytu=USART_Getc(USART2);
	//_manual();

if (ps2.Start == 1 ||check ==1)
	{
	check =1;

	}
if (ps2.Select == 1 || check == 0)
	{
	check =0;

	}
if (check == 0)
	{
		_cnt=0;
	_manual();
		if(check_home==1)
		{
	angle_1(goc1,1);
	angle_2(goc2,1);
	angle_3(goc3,1);
	angle_4(goc4,1);
	if(x1==1 && x2 == 1 && x3 == 1 && x4 == 1 && check_home == 1 )
		{
	check_home=0;
		}
		}
		else
		{
	angle_1(x_1,1);
	angle_2(x_2,1);
	angle_3(x_3,1);
	angle_4(x_4,1);
	}
}
else
	{
	_auto();
	angle_1(goc1,80);
	angle_2(goc2,80);
	angle_3(goc3,30);
	angle_4(goc4,30);
	}
	if (_cnt == 2 && x1==1 && x2 ==1 &&x3 ==1 && x4 == 1 )
		{
			delay_ms(1000);
			check_auto=2;
			goc1=115;
			goc2=30;
			goc3=20;
			goc4=155;

		}


	
		}
}




