#include "main.h"
#include "interrupts.h"
#include "led.h"
#include "button.h"
#include "bluetooth.h"
#include "../app.h"
#include "../animation.h"

void Interrupts_SysTick(){
	LED_Breath();
	Bluetooth_SysTick();
	Animation_SysTick();
	App_SysTick();
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART1){
		//!TBD
	}
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART1){
		Bluetooth_Interrupt();
	}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == BUTTON_RESET_Pin){
		Button_Interrupt();
	}
}
