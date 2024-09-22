#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "PWM.h"

uint8_t i;

int main(void)
{
	OLED_Init();
	PWM_Init();
	
	while(1)
	{
		for(i=0;i<=100;i++)
		{
			PWM_SetCompare1(i);   //CCR
			OLED_ShowNum(1,1,i,3);
			Delay_ms(10);
		}
		for(i=0;i<=100;i++)
		{
			PWM_SetCompare1(100-i);
			OLED_ShowNum(1,1,i,3);
			Delay_ms(10);
		}
	}
}
