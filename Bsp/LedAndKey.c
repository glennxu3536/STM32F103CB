#include <stm32f10x.h>
#include	"LedAndKey.h"

GPIO_InitTypeDef GPIO_InitStructure;

void wait(unsigned long n)
{
	while(n--);
}

//LED1~LED4£ºPA1~PA4  GPIO Configuration
void Led_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//Key:PA0 GPIO Configuration
void Key_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_0);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int Key_Scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		wait(10000);
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) //Ïû¶¶
		{
			while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
			return KEY_ON;
		}
		else 
			return KEY_OFF;
	}
	else
		return KEY_OFF;

}
