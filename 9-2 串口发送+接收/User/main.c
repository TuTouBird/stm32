#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "OLED.h"

uint8_t RXData;

int main(void)
{
	OLED_Init();
	Serial_Init();
	
	OLED_ShowString(1,1,"RXData:");
	
	while(1)
	{
		if(Serial_GetRXFlag()==1)
		{
			RXData=Serial_GetRXData();
			Serial_SendByte(RXData);
			OLED_ShowHexNum(1,8,RXData,2);
		}
	}
}
