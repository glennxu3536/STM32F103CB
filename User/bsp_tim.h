#ifndef __BSP_TIM_H__

#define __BSP_TIM_H__

#include <stm32f10x.h>

#define TIM2_START (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE))
#define TIM2_STOP  (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE))

void TIM2_Configuration(void);
void TIM2_NVIC_Configuration(void);

#endif
