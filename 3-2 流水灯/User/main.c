#include "stm32f10x.h"                  
#include "Delay.h"

int main(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	unsigned int num1 = 0x0001;
	unsigned int num2 = 0x0080;
	unsigned char i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			GPIO_Write(GPIOA,~(num1<<i));
			Delay_ms(200);
		}
		for(i=0;i<8;i++)
		{
			GPIO_Write(GPIOA,~(num2>>i));
			Delay_ms(200);
		}
	}
}
