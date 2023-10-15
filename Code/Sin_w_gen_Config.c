/*************************************** Copyright ****************************** 
  * FileName   : Sin_w_gen_Config.c   
  * Version    : v1.0		
  * Author     : Lai-zs@qq.com			
  * Date       : 2022-12-22         
  * Description:    
  * Function List:  
   <description>:  
********************************************************************************/
 
/*include----------------------------------------------------------------------*/
#include "Sin_w_gen_Config.h"
#include "tim.h"

/*define-----------------------------------------------------------------------*/


/*variate----------------------------------------------------------------------*/
Sine_Wave_struct sin_W={0};

/*statement--------------------------------------------------------------------*/

uint32_t Get_Time_us(void);

/*Function prototype Begin*****************************************************/

void SIN_Init()
{
	set_wave_freq(&sin_W,5);			//����Ƶ��
	set_wave_VP(&sin_W,2500,500);	//���÷��ֵ ��ֵ ��ֵ
	
	init_wave_buff(&sin_W,400);		//���뻺����
	init_wave_buff_data(&sin_W);	//��ʼ������������
//	Printf_wave_buff_data(&sin_W);//��ӡ����������
	wave_Channel_Add(&sin_W,1,0);		//���һ��ͨ��
	wave_Channel_Add(&sin_W,2,Calculate_wave_phase(&sin_W,10));	//���һ��ͨ��
	wave_Channel_Add(&sin_W,3,Calculate_wave_phase(&sin_W,50));	//���һ��ͨ��
	wave_Channel_Add(&sin_W,4,Calculate_wave_phase(&sin_W,80));	//���һ��ͨ��
	Print_Channel(&sin_W);		//��ӡͨ����Ϣ
	
	
	HAL_TIM_Base_Start(&htim2);
	sin_W.Get_time_us = Get_Time_us; //����ʱ���ȡ����
}

/***********************************************************
*@fuction	:Get_Time_us
*@brief		:ʱ���ȡ����
*@param		:--
*@return	:void
*@author	:--
*@date		:2022-12-23
***********************************************************/
uint32_t Get_Time_us()	//���ؼ�����ʱ�� ��λus
{
	return __HAL_TIM_GET_COUNTER(&htim2);	
}

uint16_t Get_CH1_Val()
{
	return Get_wave_Value(&sin_W,1);
}

uint16_t Get_CH2_Val()
{
	return Get_wave_Value(&sin_W,2);
}

uint16_t Get_CH3_Val()
{
	return Get_wave_Value(&sin_W,3);
}

uint16_t Get_CH4_Val()
{
	return Get_wave_Value(&sin_W,4);
}





/*Function prototype End*******************************************************/


