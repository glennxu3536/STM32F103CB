#include "hc_sr04.h"
#include "led_key.h"
#include "bsp_systick.h"
#include "bsp_tim.h"
#include "bsp_uart.h"

u16 sr04_flag = 1;
u16 sr04_cnt = 0;

void hcsr04_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void hcsr04_Trigger()
{
	GPIOB->ODR ^= GPIO_Pin_13;
	Delay_us(11);
	GPIOB->ODR ^= GPIO_Pin_13;
	while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15));
	TIM_SetCounter(TIM2, 0);
	while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15));
	printf("%.1fcm\n", 0.017 * TIM_GetCounter(TIM2));
}
