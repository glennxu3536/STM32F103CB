#include "bsp_systick.h"

void SysTick_Configuration(void)
{
	while(SysTick_Config(72));  //1us����һ��SysTick�쳣
	SysTick->CTRL &= ~(1<<1);  //��ʱ�ر��ж�
}

void Delay(unsigned long time)
{
    uint32_t temp;
    SysTick->LOAD=9000*time;
    SysTick->CTRL=0X01;
    SysTick->VAL=0;
    do
        temp=SysTick->CTRL;
    while((temp&0x01)&&(!(temp&(1<<16))));
    SysTick->CTRL=0;
    SysTick->VAL=0;
}

void Delay_us(unsigned long time)
{
	SysTick->CTRL |= (1<<1);
	while(time); //n--һ�ε�ʱ��ǡ����1us
	SysTick->CTRL &= ~(1<<1);
}
