#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__
#include <stm32f10x.h>

void SysTick_Configuration(void);
void Delay(unsigned long time);
void Delay_us(unsigned long time);

#endif
