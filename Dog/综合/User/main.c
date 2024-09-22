#include "stm32f10x.h"             
#include "Dog.h"
#include "DogFace.h"
#include "Serial.h"

uint8_t command;

int main(void)
{
	Dog_Init();
	Serial_Init();
	while(1)
	{	
	}
}

void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		command=USART_ReceiveData(USART1);
		if(command==1)
		{
			Dog_up();			
		}
		else if(command==2)
		{
			Dog_down();			
		}
		else if(command==3)
		{
			DogFace_kun();
		}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
