#include "includes.h"

OS_SEM SEM1;
OS_TCB	LED_TCB1, LED_TCB2, LED_TCB3, LED_TCB4;		     //定义任务控制块
CPU_STK	LED_Stk1[128], LED_Stk2[128], LED_Stk3[128], LED_Stk4[128];	   //定义任务堆栈

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
  OS_ERR err;	

  /* 板级初始化 */	
	BSP_Init();
	
	//printf("booting...\n");
	
  /* 初始化"uC/OS-III"内核 */  
	OSInit(&err);		                                        
  
	OSSemCreate((OS_SEM   *)&SEM1,
							(CPU_CHAR *)"SEM1",
							(OS_SEM_CTR)1,
							(OS_ERR   *)&err);
	
	/*创建任务*/
	OSTaskCreate((OS_TCB     *)&LED_TCB1,                   // 任务控制块指针          
               (CPU_CHAR   *)"LED1",		                  // 任务名称
               (OS_TASK_PTR )Task_LED1, 	               	// 任务代码指针
               (void       *)&LED_TCB2,			              // 传递给任务的参数parg
               (OS_PRIO     )6,			                      // 任务优先级
               (CPU_STK    *)&LED_Stk1[0],	              // 任务堆栈基地址
               (CPU_STK_SIZE)12,			                    // 堆栈剩余警戒线
               (CPU_STK_SIZE)128,			                    // 堆栈大小
               (OS_MSG_QTY  )0,			                      // 可接收的最大消息队列数
               (OS_TICK     )1000,			                  // 时间片轮转时间
               (void       *)0,			                      // 任务控制块扩展信息
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // 任务选项
               (OS_ERR     *)&err);		                    // 返回值
	  
	OSTaskCreate((OS_TCB     *)&LED_TCB2,                   // 任务控制块指针          
               (CPU_CHAR   *)"LED2",		                  // 任务名称
               (OS_TASK_PTR )Task_LED2, 	                // 任务代码指针
               (void       *)0,			                      // 传递给任务的参数parg
               (OS_PRIO     )6,			                      // 任务优先级
               (CPU_STK    *)&LED_Stk2[0],	              // 任务堆栈基地址
               (CPU_STK_SIZE)12,			                    // 堆栈剩余警戒线
               (CPU_STK_SIZE)128,			                    // 堆栈大小
               (OS_MSG_QTY  )0,			                      // 可接收的最大消息队列数
               (OS_TICK     )1000,			                  // 时间片轮转时间
               (void       *)0,			                      // 任务控制块扩展信息
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // 任务选项
               (OS_ERR     *)&err);		                    // 返回值
	  
	OSTaskCreate((OS_TCB     *)&LED_TCB3,                   // 任务控制块指针          
               (CPU_CHAR   *)"LED3",		                  // 任务名称
               (OS_TASK_PTR )Task_LED3, 	                // 任务代码指针
               (void       *)0,			                      // 传递给任务的参数parg
               (OS_PRIO     )6,			                      // 任务优先级
               (CPU_STK    *)&LED_Stk3[0],	              // 任务堆栈基地址
               (CPU_STK_SIZE)12,			                    // 堆栈剩余警戒线
               (CPU_STK_SIZE)128,			                    // 堆栈大小
               (OS_MSG_QTY  )0,			                      // 可接收的最大消息队列数
               (OS_TICK     )1000,			                  // 时间片轮转时间
               (void       *)0,			                      // 任务控制块扩展信息
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // 任务选项
               (OS_ERR     *)&err);		                    // 返回值
	  	  

  /* 启动多任务系统，控制权交给uC/OS-III */
  OSStart(&err);                                       
}

/*********************************************END OF FILE**********************/

