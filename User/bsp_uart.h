#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stm32f10x.h>
#include "bsp_systick.h"
#include <stdio.h>

void Uart1_NVIC_Configuration(void);
void Uart2_NVIC_Configuration(void);
void Uart1_Configuration(void);
void Uart2_Configuration(void);
//void USART2_IRQHandler(void);
int cal(void);
int fputc(int c, FILE *fp);

#endif
