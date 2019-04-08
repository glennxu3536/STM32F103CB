#include <stm32f10x.h>
#include "led_key.h"

OS_ERR err;

void Key_Init(GPIO_TypeDef* GPIOx, uint16_t PIN, GPIOMode_TypeDef MODE)
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
	GPIO_InitStructure.GPIO_Mode = MODE;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void Led_Init(GPIO_TypeDef* GPIOx, uint16_t PIN, GPIOMode_TypeDef MODE)
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
	GPIO_InitStructure.GPIO_Mode = MODE;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

int KeyScan(GPIO_TypeDef* GPIOx, uint16_t PIN)
{
	if(!GPIO_ReadInputDataBit(GPIOx, PIN))
	{
		OSTimeDly(20, OS_OPT_TIME_DLY ,&err);
		if(!GPIO_ReadInputDataBit(GPIOx, PIN))
		{
			while(!GPIO_ReadInputDataBit(GPIOx, PIN));
			return KEY_ON;
		}
		else
		{
			while(!GPIO_ReadInputDataBit(GPIOx, PIN));//到底有没有用
			return KEY_OFF;
		}	 
	}
	return KEY_OFF;
}
