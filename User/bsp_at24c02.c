#include "bsp_at24c02.h"

//PB6:SCL   PB7:SDA
void IIC_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_WriteBit(GPIOB, GPIO_Pin_6 | GPIO_Pin_7, Bit_RESET);
}

void IIC_START(void)
{
	SDA_OUT();   //让PB7：SDA配置为输出功能
	
	IIC_SDA_H;
	IIC_SCL_H;
	Delay_us(5);
	
	IIC_SDA_L;
	IIC_SCL_L;
}

void IIC_STOP(void)
{
	SDA_OUT();   //让PB7：SDA配置为输出功能
	
	IIC_SDA_L;
	IIC_SCL_H;
	Delay_us(5);
	
	IIC_SDA_H;
	IIC_SCL_L;
	
	Delay_us(10000);
}

//AT24C02应答STM32
unsigned int IIC_Wait_ACK(void)
{
	unsigned int n = 0;
	SDA_IN();
	IIC_SCL_H;
	
	while(Read_SDA)
	{
		n++;
		if(n > 500)
		{
			IIC_STOP();
			return 1;
		}
	}
	
	IIC_SCL_L;
	return 0;
}

void IIC_ACK(void)   //STM32应答AT24C02
{
	SDA_OUT();
	
	IIC_SCL_L;
	IIC_SDA_L;
	IIC_SCL_H;
	
	IIC_SCL_L;
}

void IIC_Send_Byte(unsigned char data)
{
	unsigned int i;
	SDA_OUT();
	
	for(i = 0; i < 8; i++)
	{
		if(data & 0x80)
			IIC_SDA_H;
		else
			IIC_SDA_L;
		
		IIC_SCL_L;
		IIC_SCL_H;
		
		IIC_SCL_L;
		data <<= 1;
	}
}

void IIC_Write_Byte(unsigned int Addr, unsigned int data)
{
	IIC_START();
	IIC_Send_Byte(0xA0);
	while(IIC_Wait_ACK());
	IIC_Send_Byte(Addr);
	while(IIC_Wait_ACK());
	IIC_Send_Byte(data);
	while(IIC_Wait_ACK());
	IIC_STOP();
}

unsigned char IIC_Receive_Byte(void)
{
	unsigned int i;
	unsigned char data;
	SDA_IN();
	
	for(i = 0; i < 8; i++)
	{
		IIC_SCL_L;
		IIC_SCL_H;
		
		data <<= 1;
		
		if(Read_SDA)
			data++;
		
		IIC_SCL_L;
	}
	
	IIC_ACK();
	
	return data;
}

unsigned char IIC_Read_Byte(unsigned int Addr)
{
	unsigned char data;
	
	IIC_START();
	IIC_Send_Byte(0xA0);
	while(IIC_Wait_ACK());
	IIC_Send_Byte(Addr);
	while(IIC_Wait_ACK());
	
	IIC_START();
	IIC_Send_Byte(0xA1);
	while(IIC_Wait_ACK());
	data = IIC_Receive_Byte();
	
	IIC_STOP();
	
	return data;
}

void AT24C02_WriteBuf(unsigned int Addr, unsigned char *buf, unsigned int size)
{
	while(size--)
	{
		IIC_Write_Byte(Addr, *buf);
		buf++;
		Addr++;
	}
}

void AT24C02_ReadBuf(unsigned int Addr, unsigned char *buf, unsigned int size)
{
	while(size--)
	{
		*buf = IIC_Read_Byte(Addr);
		buf++;
		Addr++;
	}
}
