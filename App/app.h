#ifndef	_APP_H_
#define	_APP_H_

#include "bsp.h" 
#include "os.h"  		
#include "os_type.h"

/**************** 用户任务声明 *******************/
void Task_LED1(void *p_arg);
void Task_LED2(void *p_arg);
void Task_LED3(void *p_arg);
void Task_LED4(void *p_arg);

#endif	//_APP_H_
