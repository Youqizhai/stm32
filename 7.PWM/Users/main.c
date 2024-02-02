#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "led.h"
#include "tim.h"


extern TIM_HandleTypeDef g_timx_pwm_handle;  


int main(void)
{
		uint8_t val =2;
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
    led_init();
		tim_init(200-1,7200-1); 
	
	
	
    while(1)
    { 
			
			if(val == 3)
			{
				val =2;
			}
        __HAL_TIM_SetCompare(&g_timx_pwm_handle,TIM_CHANNEL_1,5*val);
			val++;
    }
}



