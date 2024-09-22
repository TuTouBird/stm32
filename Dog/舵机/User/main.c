#include "stm32f10x.h"                  // Device header
#include "Dog.h"
#include "Servo.h"

int main(void)
{
	Dog_Init();
	Dog_down();
	
	while(1)
	{
		
	}
}
