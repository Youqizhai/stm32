#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "blueteeth.h"
#include "tim.h"

extern TIM_HandleTypeDef g_timx_pwm_handle;  
extern UART_HandleTypeDef g_uart1_handle; 
extern uint8_t a[1];


int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
			blueteeth_init(115200);
	
	
	
    while(1)
    { 
       HAL_UART_Receive(&g_uart1_handle,a,1,HAL_MAX_DELAY);
			switch(*a)
			{
				case '1':
					__HAL_TIM_SetCompare(&g_timx_pwm_handle,TIM_CHANNEL_1,5);
						break;
				case '2':
						__HAL_TIM_SetCompare(&g_timx_pwm_handle,TIM_CHANNEL_1,15);
						break;
			}
    }
}



