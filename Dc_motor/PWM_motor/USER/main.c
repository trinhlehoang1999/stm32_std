#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "stdbool.h"


/************************************************
STM32VN
************************************************/
uint8_t x=0,check,z=0,check_flag=0,check_counter=0;
uint32_t y=0;
u32 arr,counter=1,limit=0;
	
#define LED2 PCout(12)// PC12	
#define LED0 PAout(8)// PA8
#define LED1 PDout(2)// PD2	
	
 int main(void)
 {		
// 	u16 led0pwmval=0;
//	u8 dir=1;	
	delay_init();	    	 	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 
	//uart_init(115200);	 

	 
//PWM: 72M/2=36M	>>psc = 0-65535 >> 0,28,42,84,
//TIMx 16bit   >> arr = 0-65535 =(84M/psc)/F_pwm
//F_pwm: tan so PWM : hz, kHz,...
	
//Luu y: cac he so arr-psc trong cung mot TIM phai co gia tri giong nhau,
//neu set khac nhau no se sung dung he so lenh cuoi cung
// TIM khac nhau thi he so arr-psc giong hay khac deu duoc
	// VD: TIM4
	 	LED_Init();
	//PWM_Init(TIM4, PWM_Channel_1, PWM_PinsPack_2,500-1,84-1);		//0.0005s = 84M/84=1M, 1M/2Khz=500>> %PWM=(500/100)*led0pwmval
 	PWM_Init(TIM2, PWM_Channel_1, PWM_PinsPack_1,2,1);	  //0.02s =  (72M/72)/50Hz=20000 >> %PWM=(60000/100)*led0pwmval
	 	//PWM_Init(TIM2, PWM_Channel_2, PWM_PinsPack_1,99,35);
//	PWM_Init(TIM4, PWM_Channel_2, PWM_PinsPack_2,20000-1,83);		//0.02s = 84M/84=1M, 1M/50hz=20000 >> %PWM=(20000/100)*led0pwmval
// 	PWM_Init(TIM4, PWM_Channel_3, PWM_PinsPack_2,20000-1,83);	 	// tuy theo he so chia ta duoc cac gia tri phu hop 50Hz 
//	PWM_Init(TIM4, PWM_Channel_4, PWM_PinsPack_2,20000-1,83); 
//	PWM_Init(TIM10, PWM_Channel_1, PWM_PinsPack_1,42000-1,0);	  //0.0005s = ( 84M/2kHz=42000) >> %PWM=(42000/100)*led0pwmval
//	
  //PWM_Init(TIM2, PWM_Channel_1, PWM_PinsPack_1,arr,35);
//	TIM3->CCR1 =200*12.5;delay_ms(5000);//
//	TIM3->CCR1 =200*2.5;delay_ms(5000);
//	TIM3->CCR1 =200*12.5;delay_ms(5000);
//	TIM3->CCR1 =200*2.5;delay_ms(000);
	x=0;
	y=0;
	check=0;
	TIM_Cmd(TIM2,ENABLE);
	while(1) //0-100��100-0 <=> 0-20000��20000-0 
	{

 
		
TIM2->CCR1=1;
		LED0=1;
		delay_us(1);
				LED0=0;
		delay_us(1);

//		
 
//x++;
//		delay_ms(100);
//		if (x>=99){
//		x=0;
//		}
//		TIM2->CCR1=50;
//		delay_ms(100);
//		TIM2->CCR1=75;
//		delay_ms(100);
//		TIM2->CCR1=99;
//		delay_ms(100);
		

// 		delay_ms(10);	 
//		if(dir)led0pwmval++;//dir==1 ,0-100
//		else led0pwmval--;	//dir==0 ,100-0
// 		if(led0pwmval>100)dir=0; // >100%
//		if(led0pwmval==0)dir=1;	
// 
//		//TIM_SetCompare2(TIM4,200*led0pwmval);					//su dung ham
//		//PWM_Set(TIM4, PWM_Channel_2,200*led0pwmval); 	//su dung ham
//		TIM4->CCR1 =200*led0pwmval;//20000/100=200 		// su dung lenh
		
//		TIM4->CCR1 =200*led0pwmval;// su dung lenh
//		TIM4->CCR2 =200*led0pwmval;//20000/100=200
//		TIM4->CCR3 =200*led0pwmval;// su dung lenh
//		TIM4->CCR4 =200*led0pwmval;//20000/100=200
//		TIM10->CCR1 =420*led0pwmval;//42000/100=420
		
		
	} 
 }

