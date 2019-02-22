#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"

int main()
{
	SysTick_Configuration();
	
	Led_Init(GPIOA, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	TIM2_START;
	
	while(1);
}
