#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "tim.h"
#include "led.h"
int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
		 led_init();
    tim_init(7199,4999);
    while(1)
    { 
        delay_ms(500);
    }
}



