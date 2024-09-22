#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Timer.h"
#include "Key.h"
#include "Buzzer.h"
#include "Delay.h"

uint8_t KeyNum,flag,TimeSelect,Alarm_Select,Buzzer_flag;
int8_t Time[]={23,59,55,7,0,0};
char* week[] = {"Mon.","Tue.","Wed.","Thu.","Fri.","Sat.","Sun."};

void TimeShow(void)
{
	OLED_ShowString(1,1,"  :  :  ");
	OLED_ShowNum(1,1,Time[0],2);//时
	OLED_ShowNum(1,4,Time[1],2);//分
	OLED_ShowNum(1,7,Time[2],2);//秒
	OLED_ShowString(1,10,week[Time[3]-1]);//星期
	OLED_ShowNum(2,7,Time[4],2);//闹钟时
	OLED_ShowString(2,9,":");
	OLED_ShowNum(2,10,Time[5],2);//闹钟分
}

void flashing(uint8_t num)
{
	if(num==0)
	{
		OLED_ShowString(1,1,"  ");
		Delay_ms(200);
		OLED_ShowNum(1,1,Time[0],2);
	}
	if(num==1)
	{
		OLED_ShowString(1,4,"  ");
		Delay_ms(200);
		OLED_ShowNum(1,4,Time[1],2);
	}
	if(num==2)
	{
		OLED_ShowString(1,7,"  ");
		Delay_ms(200);
		OLED_ShowNum(1,7,Time[2],2);
	}
	if(num==3)
	{
		OLED_ShowString(1,10,"    ");
		Delay_ms(200);
		OLED_ShowString(1,10,week[Time[3]-1]);
	}
	if(num==4)
	{
		OLED_ShowString(2,7,"  ");
		Delay_ms(200);
		OLED_ShowNum(2,7,Time[4],2);
	}
	if(num==5)
	{
		OLED_ShowString(2,10,"  ");
		Delay_ms(200);
		OLED_ShowNum(2,10,Time[5],2);
	}
}

int main(void)
{
	OLED_Init();
	Buzzer_Init();
	Timer_Init();
	Key_Init();
	TimeShow();
	OLED_ShowString(2,1,"Alarm:");
	OLED_ShowString(3,1,"Talk is cheap,");
	OLED_ShowString(4,1,"show me the code");
	
	while(1)
	{
		if(Buzzer_flag==1) {Buzzer_ON();Buzzer_flag=0;}
		KeyNum = Key_GetNum();
		if(flag == 0) {TIM_Cmd(TIM2,ENABLE);flag=1;}
		else if(KeyNum == 1 && flag == 1) 
		{
			TIM_Cmd(TIM2,DISABLE);
			flag=0;
			TimeSelect=0;
			flashing(TimeSelect);
			while(1)
			{
				KeyNum = Key_GetNum();
				if(KeyNum == 1) break;
				if(KeyNum==2)
				{
					TimeSelect++;
					TimeSelect%=5;
					flashing(TimeSelect);
				}
				if(KeyNum==3)
				{
					Time[TimeSelect]++;
					if(TimeSelect==0)
					{
						if(Time[0]==24)
							Time[0]=0;
						OLED_ShowNum(1,1,Time[0],2);
					}
					else if(TimeSelect==1)
					{
						if(Time[1]==60)
							Time[1]=0;
						OLED_ShowNum(1,4,Time[1],2);
					}
					else if(TimeSelect==2)
					{
						if(Time[2]==60)
							Time[2]=0;
						OLED_ShowNum(1,7,Time[2],2);
					}
					else if(TimeSelect==3)
					{
						if(Time[3]==8)
							Time[3]=1;
						OLED_ShowString(1,10,week[Time[3]-1]);
					}
				}
				if(KeyNum==4)
				{
					Time[TimeSelect]--;
					if(TimeSelect==0)
					{
						if(Time[0]<0)
							Time[0]=23;
						OLED_ShowNum(1,1,Time[0],2);
					}
					else if(TimeSelect==1)
					{
						if(Time[1]<0)
							Time[1]=59;
						OLED_ShowNum(1,4,Time[1],2);
					}
					else if(TimeSelect==2)
					{
						if(Time[2]<0)
							Time[2]=59;
						OLED_ShowNum(1,7,Time[2],2);
					}
					else if(TimeSelect==3)
					{
						if(Time[3]==0)
							Time[3]=7;
						OLED_ShowString(1,10,week[Time[3]-1]);
					}
				}
			}
		}
		if(KeyNum==5)
		{
			Alarm_Select=0;
			flashing(Alarm_Select+4);
			while(1)
			{
				KeyNum = Key_GetNum();
				if(KeyNum == 5) {OLED_ShowString(2,13,"OK");Delay_ms(1000);OLED_ShowString(2,13,"  ");break;}
				if(KeyNum==2)
				{
					Alarm_Select++;
					TimeSelect%=2;
					flashing(Alarm_Select+4);
				}
				if(KeyNum==3)
				{
					Time[Alarm_Select+4]++;
					if(Alarm_Select==0)
					{
						if(Time[Alarm_Select+4]==24)
							Time[Alarm_Select+4]=0;
						OLED_ShowNum(2,7,Time[Alarm_Select+4],2);
					}
					else if(Alarm_Select==1)
					{
						if(Time[Alarm_Select+4]==60)
							Time[Alarm_Select+4]=0;
						OLED_ShowNum(2,10,Time[Alarm_Select+4],2);
					}
				}
				if(KeyNum==4)
				{
					Time[Alarm_Select+4]--;
					if(Alarm_Select==0)
					{
						if(Time[Alarm_Select+4]<0)
							Time[Alarm_Select+4]=23;
						OLED_ShowNum(2,7,Time[Alarm_Select+4],2);
					}
					else if(Alarm_Select==1)
					{
						if(Time[Alarm_Select+4]<0)
							Time[Alarm_Select+4]=59;
						OLED_ShowNum(2,10,Time[Alarm_Select+4],2);
					}
				}
			}
		}			
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
	{
		Time[2]++;
		OLED_ShowNum(1,7,Time[2]%60,2);
		if(Time[2]==60)
		{
			Time[2]=0;
			Time[1]++;
			OLED_ShowNum(1,4,Time[1]%60,2);
			if((Time[0]%24)==Time[4]&&(Time[1]%60)==Time[5]) Buzzer_flag=1;
			if(Time[1]==60)
			{
				Time[1]=0;
				Time[0]++;
				OLED_ShowNum(1,1,Time[0]%24,2);
				if((Time[0]%24)==Time[4]&&(Time[1]%60)==Time[5]) Buzzer_flag=1;
				if(Time[0]==24)
				{
					Time[0]=0;
					Time[3]++;
					if(Time[3]==8) Time[3]=1;
					OLED_ShowString(1,10,week[Time[3]-1]);
					if((Time[0]%24)==Time[4]&&(Time[1]%60)==Time[5]) Buzzer_flag=1;
				}
			}
		}
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
