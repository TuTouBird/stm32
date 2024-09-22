#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	Serial_Init();
	
//	Serial_SendByte('A');
	
//	uint8_t MyArray[]={0x41,0x42,0x43,0x44,0x45};
//	Serial_SendArray(MyArray,5);
	
//	Serial_SendString("HelloWorld!\n");
	
//	Serial_SendNumber(12345,5);
	
//	printf("Num=%d\n",666);
	
//	char String[100];
//	sprintf(String,"Num=%d\n",666);
//	Serial_SendString(String);
	
//	Serial_Printf("Num=%d\n",666);
	
	Serial_Printf("你好，世界！");
	
	while(1)
	{
		
	}
}
