#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"
#include "oled.h"
#include "hc_sr04.h"

int main()
{
	OLED_Init();
	printf("Booting...\n");
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	TIM2_START;
	hcsr04_Init();
	RCC_TIM2_START;
	Delay(500);
	while(1)
	{
		OLED_ClearFor();
		hcsr04_Trigger();
		Delay(500);
	}
}
