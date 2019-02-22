#include "hc_sr04.h"
#include "led_key.h"
#include "bsp_systick.h"

u16 cnt = 0;

void hcsr04_Init()
{
	Led_Init(GPIOB, GPIO_Pin_13);
	Key_Init(GPIOB, GPIO_Pin_15);
}

void hcsr04_Trigger()
{
	GPIOB->ODR ^= GPIO_Pin_13;
	Delay_us(12);
	GPIOB->ODR ^= GPIO_Pin_13;
	while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15));
	hcsr04_Echo();
}

void hcsr04_Echo()
{
	
}

void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
		cnt++;
}
