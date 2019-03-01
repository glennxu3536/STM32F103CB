#ifndef __BSP_AT24C02_H__
#define __BSP_AT24C02_H__

#include <stm32f10x.h>
#include "bsp_systick.h"

#define SDA_OUT()		{GPIOB->CRL &= 0x0FFFFFFF; GPIOB->CRL |= 0x30000000;}
#define SDA_IN()		{GPIOB->CRL &= 0x0FFFFFFF; GPIOB->CRL |= 0x40000000;}

#define IIC_SDA_H		GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_SET)
#define IIC_SDA_L		GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_RESET)
#define IIC_SCL_H		GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_SET)
#define IIC_SCL_L		GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_RESET)

#define Read_SDA		GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)

void IIC_Configuration(void);
unsigned char IIC_Read_Byte(unsigned int Addr);
void IIC_Write_Byte(unsigned int Addr, unsigned int data);
void AT24C02_WriteBuf(unsigned int Addr, unsigned char *buf, unsigned int size);
void AT24C02_ReadBuf(unsigned int Addr, unsigned char *buf, unsigned int size);

#endif
