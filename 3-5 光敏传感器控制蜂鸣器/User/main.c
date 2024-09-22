#include "stm32f10x.h"                 
#include "Buzzer.h"
#include "LightSensor.h"
#include "OLED.h"

int main(void)
{
	Buzzer_Init();
	LightSensor_Init();
	OLED_Init();
	
	while(1)
	{
		if(LightSensor_Get() == 0)   //亮输出低电平
		{
			Buzzer_ON();
			OLED_ShowNum(1,1,0,1);
		}
		if(LightSensor_Get() == 1)	 //暗输出高电平
		{
			Buzzer_OFF();
			OLED_ShowNum(1,1,1,1);
		}
	}
}
