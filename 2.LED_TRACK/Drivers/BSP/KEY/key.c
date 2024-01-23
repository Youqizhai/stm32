#include "./BSP/KEY/key.h"
void key_init(void)
{
	GPIO_InitTypeDef gpio_init_struct;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio_init_struct.Pin = GPIO_PIN_1;
	gpio_init_struct.Mode = GPIO_MODE_INPUT;
	gpio_init_struct.Pull = GPIO_PULLUP;
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&gpio_init_struct);
}

