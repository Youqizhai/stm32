#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "blueteeth.h"
#include "led.h"


extern UART_HandleTypeDef g_uart1_handle; 
extern uint8_t a[1];


int main(void)
{
    HAL_Init();                              /* 初始化HAL库 */
     SystemClock_Config();                  /* 设置时钟, 72Mhz */
    delay_init(72);                          /* 延时初始化 */
			led_init();
			blueteeth_init(115200);
	
	
	
    while(1)
    { 
      
    }
}



