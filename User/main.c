#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"
#include "bsp_uart.h"

extern int TIM3CH1_Complete;
extern int TIM3CH1_Capture;
extern int TIM3CH1_Overload;

int main()
{

	TIM2_PWM_Configuration();
	TIM3_INPUTCAPTURE_Confuguration();
	Uart1_Configuration();
	Uart1_NVIC_Configuration();
	
	printf("booting...\n");
	RCC_TIM2_START;
	RCC_TIM3_START;
	
	TIM_SetCompare2(TIM2, 20000);
	
	while(1)
	{
		if(TIM3CH1_Complete == 1)
		{
			printf("%dus\n", TIM3CH1_Overload * 65536 + TIM3CH1_Capture);
			TIM3CH1_Complete = 0;
			TIM3CH1_Overload = 0;
		}
	}
}
