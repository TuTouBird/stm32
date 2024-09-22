#include "stm32f10x.h"                  // Device header
#include "SERVO.h"
#include "Delay.h"

void Dog_Init(void)
{
	Servo_Init();
}

void Dog_up(void)
{
	
	Servo1_SetAngle(0);
	Servo2_SetAngle(90);
	Servo3_SetAngle(0);
	Servo4_SetAngle(90);
	
}

void Dog_down(void)
{
	
	Servo1_SetAngle(90);
	Servo2_SetAngle(0);
	Servo3_SetAngle(90);
	Servo4_SetAngle(0);
	
}

void Dog_hello(void)
{
	Servo1_SetAngle(90);
	Servo2_SetAngle(90);
	Servo3_SetAngle(90);
	Servo4_SetAngle(90);
	Delay_ms(500);
	//摆手
	Servo2_SetAngle(180);
	Delay_ms(200);
	Servo2_SetAngle(135);
	Delay_ms(200);
	Servo2_SetAngle(180);
	Delay_ms(200);
	Servo2_SetAngle(135);
	Delay_ms(200);
	Servo2_SetAngle(180);
	Delay_ms(200);
	Servo2_SetAngle(135);
	Delay_ms(200);
	Servo2_SetAngle(90);
}

void Dog_swing(void)
{
	uint8_t i;
	for(i=0;i<20;i++)
	{
		Servo1_SetAngle(30);
		Servo2_SetAngle(150);
		Servo3_SetAngle(30);
		Servo4_SetAngle(150);
		Delay_ms(200);
		Servo1_SetAngle(90);
		Servo2_SetAngle(90);
		Servo3_SetAngle(90);
		Servo4_SetAngle(90);
		Delay_ms(200);
	}
}
