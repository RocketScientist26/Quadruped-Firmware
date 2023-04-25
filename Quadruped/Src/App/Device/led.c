#include "main.h"
#include "led.h"

extern TIM_HandleTypeDef htim2;

struct led{
	uint8_t mode;
	uint8_t enabled;
	uint8_t brightness;
	uint8_t brightness_rising_or_falling;
	uint8_t current_transition_sample;
	uint32_t passed_time_ms;
}led;

void LED_Breath(){
	if(led.enabled){
		//Total time for acceleration: (LED_MAX_SPEED - LED_NORMAL_SPEED) * LED_SPEED_UP_INTERVAL_MS, twice faster cool down
		//Calculate time passed since changing mode and LED "breathing" interval
		uint8_t delay = 0;
		switch(led.mode){
			case LED_ACCELERATE:
				if(led.passed_time_ms > 0){
					led.passed_time_ms--;
				}
				delay = (led.passed_time_ms / LED_SPEED_UP_INTERVAL_MS) + LED_MAX_SPEED;
			break;
			case LED_COOL_DOWN:
				if(led.passed_time_ms < (LED_NORMAL_SPEED - LED_MAX_SPEED) * LED_COOL_DOWN_INTERVAL_MS){
					led.passed_time_ms++;
				}
				delay = (led.passed_time_ms / LED_COOL_DOWN_INTERVAL_MS) + LED_MAX_SPEED;
			break;
			case LED_CONSTANT:
				led.passed_time_ms = LED_SPEED_UP_INTERVAL_MS * LED_NORMAL_SPEED;
				delay = LED_NORMAL_SPEED;
			break;
		}

		//Breath
		led.current_transition_sample++;
		if(led.current_transition_sample >= delay){
			led.current_transition_sample = 0;

			if(led.brightness_rising_or_falling){
				//If rising brightness
				if(led.brightness < htim2.Init.Period){
					led.brightness++;
				}else{
					led.brightness_rising_or_falling = 0;
				}
			}else{
				//If reducing brightness
				if(led.brightness > LED_MIN_BRIGHTNESS){
					led.brightness--;
				}else{
					led.brightness_rising_or_falling = 1;
				}
			}

			//Set brightness
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, led.brightness);
		}
	}
}
void LED_Set_Mode(uint8_t mode){
	led.mode = mode;
}
uint8_t LED_Is_Enabled(){
	return led.enabled;
}
void LED_Enable(uint8_t enable){
	if(!enable){
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	}
	led.enabled = enable;
}
void LED_Init(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
}
