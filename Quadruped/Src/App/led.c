#include "main.h"
#include "led.h"

extern TIM_HandleTypeDef htim2;

uint8_t led_active = 1;

uint8_t led_current_breathing_light_level = 0;
uint8_t led_current_breathing_light_level_is_rising_or_falling = 0;
uint32_t led_how_much_ms_passed_since_last_direction_change = 0;
uint8_t led_current_breathing_speed = 2;
uint8_t led_current_level_in_breathing_sample = 0;

void Led_Init(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
}
void Led_On(){
	led_active = 1;
}
void Led_Off(){
	led_active = 0;
	TIM2 -> CCR2 = 0;
}
void Led_Breath(uint8_t is_moving, uint8_t no_settings){
	if((is_moving > 0)&&(no_settings == 1)){
		if(led_how_much_ms_passed_since_last_direction_change < 75999){
			led_how_much_ms_passed_since_last_direction_change++;
		}
	}else{
		uint8_t i = 2;//2 times faster cooldown from fast to normal breathing speed
		while(i != 0){
			if(led_how_much_ms_passed_since_last_direction_change > 0){
				led_how_much_ms_passed_since_last_direction_change--;
			}
			i--;
		}
	}

	//Setting breathing speed, 21 = normal, 2 = fastest
	//Total time for 19step = 76sec
	//One step increase in every 4s and decrease in every 2s if direction is falling
	led_current_breathing_speed = (uint8_t)(((uint32_t)19-(((uint32_t)led_how_much_ms_passed_since_last_direction_change+(uint32_t)1)/(uint32_t)4000))+(uint32_t)2);

	//Breath
	if(led_active == 1){
		led_current_level_in_breathing_sample++;
		if(led_current_level_in_breathing_sample > led_current_breathing_speed){
			led_current_level_in_breathing_sample = led_current_breathing_speed;
		}
		if(led_current_level_in_breathing_sample == led_current_breathing_speed){
			led_current_level_in_breathing_sample = 0;

			//Breathing from HERE
			TIM2 -> CCR2 = led_current_breathing_light_level;
			if(led_current_breathing_light_level_is_rising_or_falling == 0){
				if(led_current_breathing_light_level < 63){
					led_current_breathing_light_level++;
				}
				else{
					led_current_breathing_light_level_is_rising_or_falling = 1;
				}
			}
			else{
				if(led_current_breathing_light_level > 2){
					led_current_breathing_light_level--;
				}
				else{
					led_current_breathing_light_level_is_rising_or_falling = 0;
				}
			}
			//To HERE

		}
	}
}