#include "tim.h"

TIM_HandleTypeDef g_timx_pwm_handle;  


void tim_init(uint16_t arr,uint16_t psc)
{
		__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_TIM1_CLK_ENABLE();
	TIM_OC_InitTypeDef tim_oc_pwm;
	g_timx_pwm_handle.Instance = TIM1;
	g_timx_pwm_handle.Init.Prescaler = psc;
	g_timx_pwm_handle.Init.Period = arr;
	g_timx_pwm_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&g_timx_pwm_handle); 
	
	tim_oc_pwm.OCMode = TIM_OCMODE_PWM2;
	tim_oc_pwm.Pulse = (1/20)*arr;
	tim_oc_pwm.OCPolarity = TIM_OCPOLARITY_HIGH;
	HAL_TIM_PWM_ConfigChannel(&g_timx_pwm_handle,&tim_oc_pwm,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&g_timx_pwm_handle,TIM_CHANNEL_1);
}
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{	
		GPIO_InitTypeDef gpio_init_struct;
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_TIM1_CLK_ENABLE();
	gpio_init_struct.Pin = GPIO_PIN_13;
	gpio_init_struct.Mode = GPIO_MODE_AF_PP;
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOC,&gpio_init_struct);
	}

}


