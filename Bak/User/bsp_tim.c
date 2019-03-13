#include "bsp_tim.h"
#include "led_key.h"

int TIM3CH1_Polarity = 1;
int TIM3CH1_Capture = 0; 
int TIM3CH1_Complete = 0;
int TIM3CH1_Overload = 0;

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

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	RCC_TIM2_STOP;//先关闭TIM2待用
}

void TIM3_INPUTCAPTURE_Confuguration()
{
	RCC_TIM3_START;
	Led_Init(GPIOA, GPIO_Pin_6, GPIO_Mode_IN_FLOATING);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
	TIM_TimeBaseStructure.TIM_Prescaler = 71;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICFilter = 0x0;
	TIM_ICInit(TIM3, &TIM_ICInitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ClearFlag(TIM3, TIM_IT_CC1 | TIM_IT_Update);
	TIM_ITConfig(TIM3, TIM_IT_CC1 | TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	RCC_TIM3_STOP;
}

void TIM3_IRQHandler()
{
	if(TIM3CH1_Complete == 0)
	{
		if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
			if(TIM3CH1_Polarity == 0)
				TIM3CH1_Overload++;
		if(TIM_GetITStatus(TIM3, TIM_IT_CC1) == SET)
		{
			if(TIM3CH1_Polarity == 1)
			{
				TIM_SetCounter(TIM3, 0);
				TIM3CH1_Capture= 0;
				TIM_OC1PolarityConfig(TIM3, TIM_OCPolarity_Low);
			}
			else
			{
				TIM3CH1_Capture = TIM_GetCounter(TIM3);
				TIM3CH1_Complete = 1;
				TIM_OC1PolarityConfig(TIM3, TIM_OCPolarity_High);
			}
			TIM3CH1_Polarity ^= 1;
		}
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC1 | TIM_IT_Update);
}
