#include <stm32f10x.h>
#include "led_key.h"
#include "bsp_systick.h"

void Key_Init(GPIO_TypeDef* GPIOx, uint16_t PIN)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	if     (GPIOx == GPIOA)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	else if(GPIOx == GPIOB)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	else
		return;
	GPIO_InitStructure.GPIO_Pin = PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void Led_Init(GPIO_TypeDef* GPIOx, uint16_t PIN)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	if     (GPIOx == GPIOA)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	else if(GPIOx == GPIOB)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	else
		return;
	GPIO_InitStructure.GPIO_Pin = PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

int KeyScan(GPIO_TypeDef* GPIOx, uint16_t PIN)
{
	if(!GPIO_ReadInputDataBit(GPIOx, PIN))
	{
		Delay(20);
		if(!GPIO_ReadInputDataBit(GPIOx, PIN))
		{
			while(!GPIO_ReadInputDataBit(GPIOx, PIN));
			return KEY_ON;
		}
		else
		{
			while(!GPIO_ReadInputDataBit(GPIOx, PIN));
			return KEY_OFF;
		}	 
	}
	return KEY_OFF;
}
