#include "stm32f10x.h"                  // Device header

void NVIC_Config(void)
{
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	  NVIC_InitTypeDef NVIC_InitStructure;
	
	  //PA0

      NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;

      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;

      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

      NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

      NVIC_Init(&NVIC_InitStructure);
	  
	  //PA3

      NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;

      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;

      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

      NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

      NVIC_Init(&NVIC_InitStructure);
	  
	  //PA6

      NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;

      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;

      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

      NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

      NVIC_Init(&NVIC_InitStructure);
}
