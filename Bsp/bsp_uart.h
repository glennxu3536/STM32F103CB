#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stm32f10x.h>
#include <stdio.h>

void Uart1_NVIC_Configuration(void);
void Uart1_Configuration(void);
int fputc(int c, FILE *fp);

#endif
