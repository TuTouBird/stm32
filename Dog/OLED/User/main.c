#include "stm32f10x.h"                 
#include "DogFace.h"
#include "Delay.h"

int main(void){

	DogFace_Init();
	
	while(1){
		DogFace_up();
		Delay_ms(2000);
		DogFace_down();
		Delay_ms(2000);
		DogFace_kun();
		Delay_ms(2000);
	}
} 
