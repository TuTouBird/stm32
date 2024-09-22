#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoder.h"

int16_t num;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	
	OLED_ShowString(1, 1, "Num:");

	while(1)
	{
		num += Get_Encoder();
		OLED_ShowSignedNum(1,5,num,5);
	}
}
