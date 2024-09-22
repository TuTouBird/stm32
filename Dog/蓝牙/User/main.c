#include "stm32f10x.h"
#include "Serial.h"
#include "gpio.h"

int main(void)
{
	gpio_init();
	Serial_Init();
	
	while(1)
	{
	}
}

void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		if(USART_ReceiveData(USART1)==1)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
