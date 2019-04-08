#include "includes.h"

OS_SEM SEM1;
OS_TCB	LED_TCB1, LED_TCB2, LED_TCB3, LED_TCB4;		     //����������ƿ�
CPU_STK	LED_Stk1[128], LED_Stk2[128], LED_Stk3[128], LED_Stk4[128];	   //���������ջ

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  OS_ERR err;	

  /* �弶��ʼ�� */	
	BSP_Init();
	
	//printf("booting...\n");
	
  /* ��ʼ��"uC/OS-III"�ں� */  
	OSInit(&err);		                                        
  
	OSSemCreate((OS_SEM   *)&SEM1,
							(CPU_CHAR *)"SEM1",
							(OS_SEM_CTR)1,
							(OS_ERR   *)&err);
	
	/*��������*/
	OSTaskCreate((OS_TCB     *)&LED_TCB1,                   // ������ƿ�ָ��          
               (CPU_CHAR   *)"LED1",		                  // ��������
               (OS_TASK_PTR )Task_LED1, 	               	// �������ָ��
               (void       *)&LED_TCB2,			              // ���ݸ�����Ĳ���parg
               (OS_PRIO     )6,			                      // �������ȼ�
               (CPU_STK    *)&LED_Stk1[0],	              // �����ջ����ַ
               (CPU_STK_SIZE)12,			                    // ��ջʣ�ྯ����
               (CPU_STK_SIZE)128,			                    // ��ջ��С
               (OS_MSG_QTY  )0,			                      // �ɽ��յ������Ϣ������
               (OS_TICK     )1000,			                  // ʱ��Ƭ��תʱ��
               (void       *)0,			                      // ������ƿ���չ��Ϣ
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // ����ѡ��
               (OS_ERR     *)&err);		                    // ����ֵ
	  
	OSTaskCreate((OS_TCB     *)&LED_TCB2,                   // ������ƿ�ָ��          
               (CPU_CHAR   *)"LED2",		                  // ��������
               (OS_TASK_PTR )Task_LED2, 	                // �������ָ��
               (void       *)0,			                      // ���ݸ�����Ĳ���parg
               (OS_PRIO     )6,			                      // �������ȼ�
               (CPU_STK    *)&LED_Stk2[0],	              // �����ջ����ַ
               (CPU_STK_SIZE)12,			                    // ��ջʣ�ྯ����
               (CPU_STK_SIZE)128,			                    // ��ջ��С
               (OS_MSG_QTY  )0,			                      // �ɽ��յ������Ϣ������
               (OS_TICK     )1000,			                  // ʱ��Ƭ��תʱ��
               (void       *)0,			                      // ������ƿ���չ��Ϣ
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // ����ѡ��
               (OS_ERR     *)&err);		                    // ����ֵ
	  
	OSTaskCreate((OS_TCB     *)&LED_TCB3,                   // ������ƿ�ָ��          
               (CPU_CHAR   *)"LED3",		                  // ��������
               (OS_TASK_PTR )Task_LED3, 	                // �������ָ��
               (void       *)0,			                      // ���ݸ�����Ĳ���parg
               (OS_PRIO     )6,			                      // �������ȼ�
               (CPU_STK    *)&LED_Stk3[0],	              // �����ջ����ַ
               (CPU_STK_SIZE)12,			                    // ��ջʣ�ྯ����
               (CPU_STK_SIZE)128,			                    // ��ջ��С
               (OS_MSG_QTY  )0,			                      // �ɽ��յ������Ϣ������
               (OS_TICK     )1000,			                  // ʱ��Ƭ��תʱ��
               (void       *)0,			                      // ������ƿ���չ��Ϣ
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	      // ����ѡ��
               (OS_ERR     *)&err);		                    // ����ֵ
	  	  

  /* ����������ϵͳ������Ȩ����uC/OS-III */
  OSStart(&err);                                       
}

/*********************************************END OF FILE**********************/

