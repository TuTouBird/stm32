#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_6;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
	{
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0);
		Delay_ms(100);
		KeyNum=1;
	}
	else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2) == 0)
	{
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2) == 0);
		Delay_ms(100);
		KeyNum=2;
	}
	else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4) == 0)
	{
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4) == 0);
		Delay_ms(100);
		KeyNum=3;
	}
	else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6) == 0)
	{
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6) == 0);
		Delay_ms(100);
		KeyNum=4;
	}
	else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10) == 0)
	{
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10) == 0);
		Delay_ms(100);
		KeyNum=5;
	}
	return KeyNum;
}
