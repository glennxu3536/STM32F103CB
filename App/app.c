#include "app.h"
 
u8 shm[30];

/* 
 * 函数名：Task_LED
 * 描述  : LED流水灯	
 * 输入  ：无
 * 输出  : 无
 */

void Task_LED1(void *p_arg)
{
	OS_ERR err;
	u8 task1_str[] = "Hello,world!";
	
  while (1)
  {
		printf("Task1:\n");
		memcpy(shm, task1_str, sizeof(task1_str));
		OSTimeDly(50, OS_OPT_TIME_PERIODIC, &err);
		printf("%s\n", shm);
		OSTimeDly(1000, OS_OPT_TIME_PERIODIC, &err);
  }
}

void Task_LED2(void *p_arg)
{
	OS_ERR err;
	u8 task2_str[] = "Good morning!";
	
  while (1)
  {
		printf("Task2:\n");
		memcpy(shm, task2_str, sizeof(task2_str));
		OSTimeDly(50, OS_OPT_TIME_PERIODIC, &err);
		printf("%s\n", shm);
		OSTimeDly(1000, OS_OPT_TIME_PERIODIC, &err);
	}
}

void Task_LED3(void *p_arg)
{
	OS_ERR err;
  (void)p_arg;

  while (1)
  {
      GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_SET);
      //OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_RESET);
			//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
  }
}

void Task_LED4(void *p_arg)
{
	OS_ERR err;
  (void)p_arg;

  while (1)
  {
      GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
      //OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
			GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
			//OSTimeDlyHMSM(0, 0,0,250,OS_OPT_TIME_HMSM_STRICT,&err);
  }
}
