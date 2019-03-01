#include "bsp_tim.h"
#include "led_key.h"
#include "bsp_systick.h"
#include "bsp_uart.h"
#include "bsp_at24c02.h"

unsigned char i;
	
int main(void)
{ 
	Uart1_Configuration();
	Uart1_NVIC_Configuration();
	Led_Init(GPIOA, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4, GPIO_Mode_Out_PP);
	IIC_Configuration();
	
	printf("Booting...\n");

	i = IIC_Read_Byte(0);
	for(int j = 0; j < i; j++)
	{
		LED_TOGGLE;
		Delay(200);
		LED_TOGGLE;
		Delay(200);
	}
	
		
}
