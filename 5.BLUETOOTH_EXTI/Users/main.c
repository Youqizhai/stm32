#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "blueteeth.h"
#include "led.h"


extern UART_HandleTypeDef g_uart1_handle; 
extern uint8_t a[1];


int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
			led_init();
			blueteeth_init(115200);
	
	
	
    while(1)
    { 
      
    }
}


