#include "app.h"

void delay(u32 time)
{
	while(time--);
}

/* 
 * 函数名：Task_LED
 * 描述  : LED流水灯	
 * 输入  ：无
 * 输出  : 无
 */
void Task_LED1(void *p_arg)
{
	int i = 0;
	OS_ERR err;

  while (1)
  {
		if(i > 10)
			OSSchedRoundRobinYield(&err);
    GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
    delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET);
		delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
		i++;
  }
}

void Task_LED2(void *p_arg)
{
	OS_ERR err;
  (void)p_arg;

  while (1)
  {
      GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_SET);
      delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_RESET);
			delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
  }
}

void Task_LED3(void *p_arg)
{
	OS_ERR err;
  (void)p_arg;

  while (1)
  {
      GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_SET);
      delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_RESET);
			delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
  }
}

void Task_LED4(void *p_arg)
{
	OS_ERR err;
  (void)p_arg;

  while (1)
  {
      GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
      delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
			GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
			delay(0xFFFFF);//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
  }
}
