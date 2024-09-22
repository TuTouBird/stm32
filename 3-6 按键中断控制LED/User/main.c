#include "stm32f10x.h"                 
#include "LED.h"
#include "NVIC.h"
#include "Key.h"

int main(void){
	
	LED_Init();
	Key_Init();
	NVIC_Config();
	
	while(1){
		
	}
} 
