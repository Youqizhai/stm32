#include "tim.h"


TIM_HandleTypeDef g_timx_handle;  

void tim_init(uint16_t psc, uint16_t arr)
{
	
			g_timx_handle.Instance = TIM1;                   
			g_timx_handle.Init.Prescaler = psc;                          
			g_timx_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        
			g_timx_handle.Init.Period = arr;                            
			HAL_TIM_Base_Init(&g_timx_handle);
			HAL_TIM_Base_Start_IT(&g_timx_handle);    
}


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
        __HAL_RCC_TIM1_CLK_ENABLE();                  
        HAL_NVIC_SetPriority(TIM1_UP_IRQn, 1, 3); 
        HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);          
    }
}

void TIM1_UP_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_timx_handle); 
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    }
}


