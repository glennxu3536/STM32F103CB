#include "bsp_tim.h"
#include "led_key.h"

void TIM2_Configuration()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_TIM2_START;
	
	TIM_TimeBaseStructure.TIM_Period = 0x5BEB;
	TIM_TimeBaseStructure.TIM_Prescaler = 71;
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	//TIM_ClearFlag(TIM2, TIM_IT_Update);
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	
	RCC_TIM2_STOP;//先关闭TIM2待用
}

void TIM2_NVIC_Configuration()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}

void TIM2_PWM_Configuration()
{
	RCC_TIM2_START;
	Led_Init(GPIOA, GPIO_Pin_1, GPIO_Mode_AF_PP);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	TIM_TimeBaseStructure.TIM_Period = 19999;
	TIM_TimeBaseStructure.TIM_Prescaler = 71;
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	//TIM_ClearFlag(TIM2, TIM_IT_Update);
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	RCC_TIM2_STOP;//先关闭TIM2待用
}
