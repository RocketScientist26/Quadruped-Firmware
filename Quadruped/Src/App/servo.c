#include "main.h"
#include "servo.h"
#include "movements.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

extern uint8_t app_action;

uint16_t servo_min_pwm = 260; //Absolute zero point for servo
uint16_t servo_max_pwm = 2600; //Absolute max point for servo
uint16_t servo_calibration_step_pwm = 15; //From -9 to +9 PWM value for every step
float servo_movement_step_pwm; //Single percent PWM value for movement
int8_t servo_calibration_values[8] = {
	0,0,0,0,0,0,0,0
};

//Base
void Servo_Set(float *values){
	TIM3 -> CCR1 = servo_min_pwm + (servo_calibration_values[0]*servo_calibration_step_pwm) + (values[0]*servo_movement_step_pwm);
	TIM3 -> CCR2 = servo_min_pwm + (servo_calibration_values[1]*servo_calibration_step_pwm) + ((100-values[1])*servo_movement_step_pwm);
	TIM3 -> CCR3 = servo_min_pwm + (servo_calibration_values[2]*servo_calibration_step_pwm) + (values[2]*servo_movement_step_pwm);
	TIM3 -> CCR4 = servo_min_pwm + (servo_calibration_values[3]*servo_calibration_step_pwm) + ((100-values[3])*servo_movement_step_pwm);

	TIM4 -> CCR1 = servo_min_pwm + (servo_calibration_values[4]*servo_calibration_step_pwm) + (values[4]*servo_movement_step_pwm);
	TIM4 -> CCR2 = servo_min_pwm + (servo_calibration_values[5]*servo_calibration_step_pwm) + ((100-values[5])*servo_movement_step_pwm);
	TIM4 -> CCR3 = servo_min_pwm + (servo_calibration_values[6]*servo_calibration_step_pwm) + (values[6]*servo_movement_step_pwm);
	TIM4 -> CCR4 = servo_min_pwm + (servo_calibration_values[7]*servo_calibration_step_pwm) + ((100-values[7])*servo_movement_step_pwm);
}
void Servo_Init(){
	servo_max_pwm -= servo_calibration_step_pwm * 9;
	servo_min_pwm += servo_calibration_step_pwm * 9;
	servo_movement_step_pwm = (servo_max_pwm - servo_min_pwm)/100.0f;

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
}

//Animation
float servo_current_values[8] = {//Store here current calculated angles, same as standby pose at start
	MOV_SRV_ST_V, MOV_SRV_ST_H, MOV_SRV_ST_H, MOV_SRV_ST_V, MOV_SRV_ST_V, MOV_SRV_ST_H, MOV_SRV_ST_H, MOV_SRV_ST_V
};
void Servo_Move(float *state_from_values, float *state_to_values, uint16_t total_steps, uint8_t delay, uint8_t no_int){
	uint16_t current_step = 0;
	uint8_t i = 0;
	while(current_step < total_steps){
		i = 0;
		current_step++;
		while(i != 8){
			servo_current_values[i] = ((float)(((float)state_to_values[i] - (float)state_from_values[i])/total_steps)*current_step)+state_from_values[i];
			i++;
		}
		Servo_Set(&servo_current_values[0]);
		HAL_Delay(delay);
		if((app_action == 0)&&(no_int == 0)){
			current_step = total_steps;
		}
	}
}
void Servo_Play_Pattern(float *values, uint16_t poses, uint16_t total_steps, uint8_t delay, uint8_t no_int){
	uint16_t i = 0;
	while(i != poses){
		if((i+1) == poses){
			//If this is last movement for current function call, move from last to first pose (and not from last to unavailable next pose)
			Servo_Move(&values[i*8], &values[0], total_steps, delay, no_int);
		}
		else{
			Servo_Move(&values[i*8], &values[(i+1)*8], total_steps, delay, no_int);
		}
		i++;
		if(app_action == 0){
			i = poses;
		}
	}
}
void Servo_Play_Trick_Pattern(float *start_values, float *trick_values, uint16_t poses, uint16_t total_steps, uint8_t delay, uint8_t no_int){
	Servo_Move(start_values, trick_values, total_steps, delay, no_int);
	if(app_action != 0){
		uint16_t i = 0;
		while(i != poses){
			Servo_Move(&trick_values[i*8], &trick_values[(i+1)*8], total_steps, delay, no_int);
			i++;
			if(app_action == 0){
				i = poses;
			}
		}
	}
}

extern float movements_kick_pose[8];
void Servo_Set_Kick(uint8_t direction, uint8_t strength, uint8_t kick){
	//^<50-75 | _20-95 / Kick ^>50-15
	if(kick == SERVO_KICK_NO_KICK){
		movements_kick_pose[4] = (((75.0f - 50.0f)/80.0f)*(float)strength) + 50.0f;
		movements_kick_pose[5] = (((95.0f - 20.0f)/90.0f)*(float)direction) + 20.0f;
		Servo_Set(movements_kick_pose);
	}else{
		if(strength >= 78){
			movements_kick_pose[4] = 15;
		}else{
			movements_kick_pose[4] = (((50.0f - 15.0f)/80.0f)*(float)strength) + 50.0f;
		}
		Servo_Set(movements_kick_pose);
		HAL_Delay(500);//TBD
		movements_kick_pose[4] = 60;
		movements_kick_pose[5] = 50;
		Servo_Set(movements_kick_pose);
	}
}
extern float movements_drive_pattern[32];
float servo_drive_calculated_values[32] = {
	MOV_DRIVE_V_DW, MOV_DRIVE_H_BW, MOV_DRIVE_H_BW, MOV_DRIVE_V_DW, MOV_DRIVE_V_DW, MOV_DRIVE_H_FW, MOV_DRIVE_H_FW, MOV_DRIVE_V_DW,
	MOV_DRIVE_V_UP, MOV_DRIVE_H_FW, MOV_DRIVE_H_FW, MOV_DRIVE_V_DW, MOV_DRIVE_V_UP, MOV_DRIVE_H_BW, MOV_DRIVE_H_BW, MOV_DRIVE_V_DW,
	MOV_DRIVE_V_DW, MOV_DRIVE_H_FW, MOV_DRIVE_H_FW, MOV_DRIVE_V_DW, MOV_DRIVE_V_DW, MOV_DRIVE_H_BW, MOV_DRIVE_H_BW, MOV_DRIVE_V_DW,
	MOV_DRIVE_V_DW, MOV_DRIVE_H_BW, MOV_DRIVE_H_BW, MOV_DRIVE_V_UP, MOV_DRIVE_V_DW, MOV_DRIVE_H_FW, MOV_DRIVE_H_FW, MOV_DRIVE_V_UP
};
void Servo_Drive(uint16_t direction, uint16_t speed){
	/*
		Direction 0-180, speed 0-80. Servos 1,2,5,6
	*/
	//Scale speed
	float scale = ((MOV_DRIVE_H_BW - MOV_DRIVE_H_FW)/160.0f) * (80-speed);//2*80 by this value should be decreased every servo, pointing to center
	servo_drive_calculated_values[1] = movements_drive_pattern[1] - scale;
	servo_drive_calculated_values[2] = movements_drive_pattern[2] - scale;
	servo_drive_calculated_values[5] = movements_drive_pattern[5] + scale;
	servo_drive_calculated_values[6] = movements_drive_pattern[6] + scale;

	servo_drive_calculated_values[9] = movements_drive_pattern[9] + scale;
	servo_drive_calculated_values[10] = movements_drive_pattern[10] + scale;
	servo_drive_calculated_values[13] = movements_drive_pattern[13] - scale;
	servo_drive_calculated_values[14] = movements_drive_pattern[14] - scale;

	servo_drive_calculated_values[17] = movements_drive_pattern[17] + scale;
	servo_drive_calculated_values[18] = movements_drive_pattern[18] + scale;
	servo_drive_calculated_values[21] = movements_drive_pattern[21] - scale;
	servo_drive_calculated_values[22] = movements_drive_pattern[22] - scale;

	servo_drive_calculated_values[25] = movements_drive_pattern[25] - scale;
	servo_drive_calculated_values[26] = movements_drive_pattern[26] - scale;
	servo_drive_calculated_values[29] = movements_drive_pattern[29] + scale;
	servo_drive_calculated_values[30] = movements_drive_pattern[30] + scale;

	//Proportionally decrease apporiate side
	float directional_scale = 0;
	float directional_scale_max = ((MOV_DRIVE_H_BW - scale) - (MOV_DRIVE_H_FW + scale))/3.0f;
	if(direction < 90){
		directional_scale = (directional_scale_max/90.0f) * (90.0f - direction);
		servo_drive_calculated_values[1] -= directional_scale;
		servo_drive_calculated_values[2] -= directional_scale;

		servo_drive_calculated_values[9] += directional_scale;
		servo_drive_calculated_values[10] += directional_scale;

		servo_drive_calculated_values[17] += directional_scale;
		servo_drive_calculated_values[18] += directional_scale;

		servo_drive_calculated_values[25] -= directional_scale;
		servo_drive_calculated_values[26] -= directional_scale;

	}else if(direction > 90){
		directional_scale = (directional_scale_max/90.0f) * (direction - 90.0f);
		servo_drive_calculated_values[5] += directional_scale;
		servo_drive_calculated_values[6] += directional_scale;

		servo_drive_calculated_values[13] -= directional_scale;
		servo_drive_calculated_values[14] -= directional_scale;

		servo_drive_calculated_values[21] -= directional_scale;
		servo_drive_calculated_values[22] -= directional_scale;

		servo_drive_calculated_values[29] += directional_scale;
		servo_drive_calculated_values[30] += directional_scale;
	}
	
	Servo_Play_Pattern(servo_drive_calculated_values, 4, MOV_DRIVE_SAMPLES, MOV_DRIVE_DELAY, SERVO_INT);
}

