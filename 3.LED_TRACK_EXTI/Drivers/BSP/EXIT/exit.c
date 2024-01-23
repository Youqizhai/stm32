#include "./BSP/EXIT/exit.h"
#include "./SYSTEM/delay/delay.h"
void exit_init(void)
{
	GPIO_InitTypeDef gpio_init_struct;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio_init_struct.Pin = GPIO_PIN_1;
	gpio_init_struct.Mode = GPIO_MODE_IT_RISING_FALLING;
	gpio_init_struct.Pull = GPIO_NOPULL;
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&gpio_init_struct);
	HAL_NVIC_SetPriority(EXTI1_IRQn,0,2);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTIO_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_1)
	{
			delay_ms(20);
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0) 
		{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
		}
		else
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1) 
		{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
		}
	}
		
}
