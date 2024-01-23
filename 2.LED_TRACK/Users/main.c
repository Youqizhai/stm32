#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "led.h"
#include "./BSP/KEY/key.h"

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
    led_init();
		key_init();
    while(1)
    { 
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0)
				{
					delay_ms(10);
					if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0)
					{
							HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
					}
					else
						
							HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
						
				}
    }
}



