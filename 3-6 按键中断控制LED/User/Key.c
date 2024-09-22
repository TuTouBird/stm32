#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource6);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line6;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

}

void EXTI0_IRQHandler(void)
{
     if(EXTI_GetITStatus(EXTI_Line0) == SET) 
     {
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){}
		Delay_ms(100);
		GPIO_WriteBit(GPIOB, GPIO_Pin_0,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_0)));
        EXTI_ClearITPendingBit(EXTI_Line0); 
     }
}

void EXTI3_IRQHandler(void)
{
     if(EXTI_GetITStatus(EXTI_Line3) == SET) 
     {
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0){}
		Delay_ms(100);
		GPIO_WriteBit(GPIOB, GPIO_Pin_1,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_1)));
        EXTI_ClearITPendingBit(EXTI_Line3); 
     }
}

void EXTI9_5_IRQHandler(void)
{
     if(EXTI_GetITStatus(EXTI_Line6) == SET) 
     {
		Delay_ms(100);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0){}
		Delay_ms(100);
		GPIO_WriteBit(GPIOB, GPIO_Pin_10,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_10)));		
        EXTI_ClearITPendingBit(EXTI_Line6); 
     }
}

