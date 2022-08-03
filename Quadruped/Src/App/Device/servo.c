#include "main.h"
#include "servo.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

int8_t servo_calib[SERVO_COUNT];

int8_t *Servo_Calib_Data(){
	return (int8_t *)&servo_calib[0];
}
void Servo_Set_Calib(int8_t calib, uint8_t servo){
	if(servo && (servo <= SERVO_COUNT)){
		servo_calib[servo - 1] = calib;
	}
}
void Servo_Set(float *values){
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, SERVO_MIN_PWM + (servo_calib[0] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * values[0]));
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, SERVO_MIN_PWM + (servo_calib[1] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * (100-values[1])));
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, SERVO_MIN_PWM + (servo_calib[2] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * values[2]));
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, SERVO_MIN_PWM + (servo_calib[3] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * (100-values[3])));
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, SERVO_MIN_PWM + (servo_calib[4] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * values[4]));
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, SERVO_MIN_PWM + (servo_calib[5] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * (100-values[5])));
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, SERVO_MIN_PWM + (servo_calib[6] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * values[6]));
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, SERVO_MIN_PWM + (servo_calib[7] * SERVO_CALIBRATION_STEP_PWM) + (SERVO_STEP_PWM * (100-values[7])));
}
void Servo_Init(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
}