#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"


int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
     SystemClock_Config();                  /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
    
    while(1)
    { 
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);    /* PB5��1 */ 
        delay_ms(500);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);  /* PB5��0 */
        delay_ms(500); 
    }
}



