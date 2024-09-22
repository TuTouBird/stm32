#include "stm32f10x.h"                  

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //ADCCLK = 72MHZ / 6 = 12MHZ
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode=DISABLE; //连续转换，失能，每转换一次规则组序列后停止
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right; //数据右对齐
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//软件触发，不使用外部触发
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent; //独立模式，单独使用ADC1
	ADC_InitStructure.ADC_NbrOfChannel=1; //通道数，为1，仅在扫描模式下，才需要指定大于1的数，在非扫描模式下，只能是1
	ADC_InitStructure.ADC_ScanConvMode=DISABLE; //扫描模式，失能，只转换规则组的序列1这一个位置
	ADC_Init(ADC1,&ADC_InitStructure);
	
	ADC_Cmd(ADC1,ENABLE);
	
	/*ADC校准*/
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) == SET);
}

uint16_t AD_GetValue(uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADC1,ADC_Channel,1,ADC_SampleTime_55Cycles5);//在每次转换前，根据函数形参灵活更改规则组的通道1
	ADC_SoftwareStartConvCmd(ADC1,ENABLE); //软件触发AD转换一次
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);//等待EOC标志位，即等待AD转换结束
	return ADC_GetConversionValue(ADC1);
}
