#ifndef __BSP_TIM_H__

#define __BSP_TIM_H__

#include <stm32f10x.h>

#define RCC_TIM2_START (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE))
#define RCC_TIM2_STOP  (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE))
#define RCC_TIM3_START (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE))
#define RCC_TIM3_STOP  (RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, DISABLE))
#define TIM2_START     (TIM_Cmd(TIM2, ENABLE))
#define TIM2_STOP      (TIM_Cmd(TIM2, DISABLE))

void TIM2_Configuration(void);//counter
void TIM2_NVIC_Configuration(void);
void TIM2_PWM_Configuration(void);//Output compare
void TIM3_INPUTCAPTURE_Confuguration(void);

#endif
