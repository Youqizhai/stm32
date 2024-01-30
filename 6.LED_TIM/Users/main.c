#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "tim.h"
#include "led.h"
int main(void)
{
    HAL_Init();                              /* 初始化HAL库 */
     SystemClock_Config();                  /* 设置时钟, 72Mhz */
    delay_init(72);                          /* 延时初始化 */
		 led_init();
    tim_init(7199,4999);
    while(1)
    { 
        delay_ms(500);
    }
}



