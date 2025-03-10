#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;   //USART1_TX
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;   //波特率
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;   //不使用流控
	USART_InitStructure.USART_Mode=USART_Mode_Tx;   //发送模式
	USART_InitStructure.USART_Parity=USART_Parity_No;   //无校验
	USART_InitStructure.USART_StopBits=USART_StopBits_1;   //1位停止位
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;   //8位字长
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}

void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);   //等待TXE置1
}

void Serial_SendArray(uint8_t* Array,uint16_t Length)
{
	uint16_t i;
	for(i=0;i<Length;i++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char* String)
{
	uint8_t i;
	for(i=0;String[i]!='\0';i++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t x,uint32_t y)
{
	uint32_t Result=1;
	while(y--)
	{
		Result*=x;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number,uint8_t Length)
{
	uint8_t i;
	for(i=0;i<Length;i++)
	{
		Serial_SendByte(Number/Serial_Pow(10,Length-i-1)%10+'0');
	}
}

int fputc(int ch,FILE* f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char* format,...)//可变参数
{
	char String[100];
	va_list arg;
	va_start(arg,format);
	vsprintf(String,format,arg);
	va_end(arg);
	Serial_SendString(String);
}
