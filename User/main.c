#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"
#include "bsp_uart.h"
#include "hc_sr04.h"

int main()
{
	Uart1_Configuration();
	Uart1_NVIC_Configuration();
	
	TIM2_Configuration();
	hcsr04_Init();
	printf("Booting...\n");
	RCC_TIM2_START;
	
	while(1)
	{
		hcsr04_Trigger();
		Delay(1000);
	}
}
