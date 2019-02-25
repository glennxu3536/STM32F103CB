#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"

int main()
{
	int i;
	TIM2_PWM_Configuration();
	RCC_TIM2_START;
	
	while(1)
	{
		for(i = 0; i < 20000; i++)
		{
			TIM_SetCompare2(TIM2, i);
			Delay_us(70);
		}
		
		for(i = 20000; i > 0; i--)
		{
			TIM_SetCompare2(TIM2, i);
			Delay_us(70);
		}
	}
}
