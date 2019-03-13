#ifndef __BSP_DMA_H__

#define __BSP_DMA_H__

#include <stm32f10x.h>

#define USART1_DR 0x40013804
#define ADC1_DR   0x4001244C

void DMA_Configuration(void);

#endif
