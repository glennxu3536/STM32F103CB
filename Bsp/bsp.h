#ifndef  __BSP_H__
#define  __BSP_H__

#include "stm32f10x.h"
#include "os_cfg_app.h"
#include "led_key.h"
#include "bsp_uart.h"

void BSP_Init(void);
void SysTick_init(void);


#endif /* __BSP_H__ */



