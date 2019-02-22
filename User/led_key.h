#ifndef _LED_KEY_H
#define _LED_KEY_H

#include <stm32f10x.h>
#define KEY_ON  0
#define KEY_OFF 1
#define LED_TOGGLE (GPIOA->ODR ^= GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4)

void Key_Init(GPIO_TypeDef* GPIOx, uint16_t PIN);
void Led_Init(GPIO_TypeDef* GPIOx, uint16_t PIN);
int KeyScan(GPIO_TypeDef* GPIOx, uint16_t PIN);

#endif
