#include "stm32f10x.h"                  // Device header
#include "OLED.h"

void DogFace_Init(void)
{
	OLED_Init();
}

void DogFace_down(void)
{
	OLED_ShowImage(0,0,128,64,face1);
	OLED_Update();
}

void DogFace_up(void)
{
	OLED_ShowImage(0,0,128,64,face2);
	OLED_Update();
}

void DogFace_kun(void)
{
	OLED_ShowImage(0,0,128,64,kun);
	OLED_Update();
}
