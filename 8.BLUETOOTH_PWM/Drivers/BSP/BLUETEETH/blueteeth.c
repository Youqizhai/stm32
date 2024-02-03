#include "blueteeth.h"


UART_HandleTypeDef g_uart1_handle; 


uint8_t a[1];

void blueteeth_init(uint32_t baudrate)
{
		g_uart1_handle.Instance = USART1;                                   
g_uart1_handle.Init.BaudRate = baudrate;                                 
g_uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;                    
g_uart1_handle.Init.StopBits = UART_STOPBITS_1;                      
g_uart1_handle.Init.Parity = UART_PARITY_NONE;                       
g_uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;                     
g_uart1_handle.Init.Mode = UART_MODE_TX_RX;                               
HAL_UART_Init(&g_uart1_handle);

}


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_init_struct;

    if (huart->Instance == USART1)                         
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();                           
        __HAL_RCC_USART1_CLK_ENABLE();                               

        gpio_init_struct.Pin = GPIO_PIN_9;               
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;               
        gpio_init_struct.Pull = GPIO_PULLUP;                 
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;       
        HAL_GPIO_Init(GPIOA, &gpio_init_struct);
                
        gpio_init_struct.Pin = GPIO_PIN_10;             
        gpio_init_struct.Mode = GPIO_MODE_AF_INPUT;    
        HAL_GPIO_Init(GPIOA, &gpio_init_struct); 
        

    }
}


