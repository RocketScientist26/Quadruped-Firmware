#include "main.h"
#include "button.h"

static uint8_t button_pressed = 0;

void Button_Interrupt(){
	button_pressed = 1;
}
uint8_t Button_Debounce_Read(){
	uint8_t level;
	uint8_t d = 0;
	uint8_t i = 0;
	while(d != 1){
		i = 0;
		level = HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin);
		while(i != BUTTON_DEBOUNCE_SAMPLES){
			i++;
			if(HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin) != level){
				break;
			}
			if(i == BUTTON_DEBOUNCE_SAMPLES){
				d = 1;
			}
		}
	}
	return level;
}
uint8_t Button_Pressed(){
	uint8_t ret = button_pressed;
	button_pressed = 0;
	return ret;
}