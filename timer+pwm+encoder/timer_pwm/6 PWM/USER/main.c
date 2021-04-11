#include "led.h"
#include "delay.h"
#include "delay_timer.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "timer.h"
 #include "stm32f10x_gpio.h"
/************************************************
STM32VN
************************************************/
#define led_c13 PCout(13)
#define led_a8 PAout(8)
#define dir_b0 PBout(0)
#define max_hz 500000
#define _max_hz 1000000
		int status=0;
		int x=0,y=0,z=0,n=0,dir=0;

u32 counter=0,t_delay=0,vong=1,time=0;
	u32 counter_current=0;
 int main(void)
 {		

	
    	 	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 
	//uart_init(115200);	 
 	LED_Init();	
	 	delay_init();	
	 delaytimer_int();
//PWM: 72M/2=36M	>>psc = 0-65535 >> 0,28,42,84,
//TIMx 16bit   >> arr = 0-65535 =(84M/psc)/F_pwm
//F_pwm: tan so PWM : hz, kHz,...
	
//Luu y: cac he so arr-psc trong cung mot TIM phai co gia tri giong nhau,
//neu set khac nhau no se sung dung he so lenh cuoi cung
// TIM khac nhau thi he so arr-psc giong hay khac deu duoc
	// VD: TIM4
	
	//PWM_Init(TIM4, PWM_Channel_1, PWM_PinsPack_2,500-1,84-1);		//0.0005s = 84M/84=1M, 1M/2Khz=500>> %PWM=(500/100)*led0pwmval
 //	PWM_Init(TIM2, PWM_Channel_2, PWM_PinsPack_1,100-1,35);	  //0.02s =  (72M/72)/50Hz=20000 >> %PWM=(60000/100)*led0pwmval
	 // TIM3_Int_Init(20000-1,3600-1);
//	PWM_Init(TIM4, PWM_Channel_2, PWM_PinsPack_2,20000-1,83);		//0.02s = 84M/84=1M, 1M/50hz=20000 >> %PWM=(20000/100)*led0pwmval
//	PWM_Init(TIM4, PWM_Channel_3, PWM_PinsPack_2,20000-1,83);	 	// tuy theo he so chia ta duoc cac gia tri phu hop 50Hz 
//	PWM_Init(TIM4, PWM_Channel_4, PWM_PinsPack_2,20000-1,83); 
//	PWM_Init(TIM10, PWM_Channel_1, PWM_PinsPack_1,42000-1,0);	  //0.0005s = ( 84M/2kHz=42000) >> %PWM=(42000/100)*led0pwmval
//	

//	TIM3->CCR1 =200*12.5;delay_ms(5000);//
//	TIM3->CCR1 =200*2.5;delay_ms(5000);
//	TIM3->CCR1 =200*12.5;delay_ms(5000);
//	TIM3->CCR1 =200*2.5;delay_ms(000);
dir=0;
		
	while(1) //0-100£¬100-0 <=> 0-20000£¬20000-0 
	{
		led_a8=1;
		delay_ms(300);
				led_a8=0;
		delay_ms(300);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
  //GPIOC->CRH=0x00300000b;

		if(status==1)
			{
			counter= 1024*8*vong;
						if(dir==1)
					{
						dir_b0=1;
				  }
						else if(dir==0)
							{
							 dir_b0=0;
							}
				for (n=0; n<counter;n++)
		{
			
			counter_current=n;
			
			if(counter_current<0.2*counter)
			{x=1;
			t_delay=t_delay+13;
		  } 

			else
				{
					if(counter_current<=0.8*counter)
						{
							y=1;
				t_delay=max_hz;
				}
						else 
							{
						z=1;
								t_delay=t_delay-10;
							}
}
					
//			if(counter_current>=counter)
//			{
//			t_delay=0;
//				counter_current=0;
//			}
			time=_max_hz*2/t_delay;
			led_c13=1;
//	Delay_Us(1);
		delay_us(time);
			led_c13=0;
			delay_us(time);
//			Delay_Us(1);
				status=0;

		}
	time=0;
		t_delay=0;
		counter=0;
		counter_current=0;
		     }
					
												}
		
		

		
	} 
 

