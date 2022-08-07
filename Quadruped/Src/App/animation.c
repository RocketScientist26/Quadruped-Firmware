#include <math.h>
#include <string.h>
#include "main.h"
#include "animation.h"
#include "Device/servo.h"

struct animation{
	uint8_t c_kick_strength;

	uint8_t c_drive_dir;
	uint8_t c_drive_speed;

	float c_data[SERVO_COUNT];
	uint32_t c_pose_n;
	uint32_t c_steps;
	uint32_t c_step_n;
	uint32_t c_frame_delay;

	float *data;
	uint32_t poses;
	uint8_t loop_en;
	float max_substep;
	float frame_delay;
}animation;

void Animation_SysTick(){
	if(Animation_Is_Playing()){
		animation.c_frame_delay++;
	}
}
void Animation_Save_Current_Pose(float *to){
	memcpy(&to[0], &animation.c_data[0], SERVO_COUNT * sizeof(float));
}
void Animation_Set_Kick(uint8_t direction, uint8_t strength){
	animation.c_kick_strength = strength;
	///Precalculate pose
	//Strength
	anim_data_kick.data[SERVO_COUNT + 4] = ANIM_DATA_KICK_STRENGTH_SERVO_MIN + (((ANIM_DATA_KICK_STRENGTH_SERVO_MAX - ANIM_DATA_KICK_STRENGTH_SERVO_MIN) / ANIM_DATA_KICK_STRENGTH_MAX) * animation.c_kick_strength);
	//Direction
	anim_data_kick.data[SERVO_COUNT + 5] = (((ANIM_DATA_KICK_DIRECTION_SERVO_MAX - ANIM_DATA_KICK_DIRECTION_SERVO_MIN) / (float)ANIM_DATA_KICK_DIRECTION_MAX) * direction) + ANIM_DATA_KICK_DIRECTION_SERVO_MIN;
}
void Animation_Kick(){
	//Precalculate kick
	anim_data_kick.data[SERVO_COUNT + 4] = ANIM_DATA_KICK_STRENGTH_SERVO_MIN + (((ANIM_DATA_KICK_STRENGTH_SERVO_MAX - ANIM_DATA_KICK_STRENGTH_SERVO_MIN) / ANIM_DATA_KICK_STRENGTH_MAX) * (ANIM_DATA_KICK_STRENGTH_MAX - animation.c_kick_strength));
	//Kick
	Servo_Set((float *)&anim_data_kick.data[SERVO_COUNT]);
	HAL_Delay(ANIM_DATA_KICK_DELAY_MS);
	//Return to standby pose
	Servo_Set((float *)&anim_data_standby[0]);
}

void Animation_Set_Drive(uint8_t direction, uint8_t speed){
	animation.c_drive_dir = direction;
	animation.c_drive_speed = speed;
}

uint8_t Animation_Is_Playing(){
	if(animation.poses){
		return 1;
	}
	return 0;
}
void Animation_Set(anim_data_t *anim_data){
	animation.c_pose_n = 0;
	animation.c_step_n = 0;

	animation.data = &anim_data->data[0];
	animation.poses = anim_data->poses;
	animation.loop_en = anim_data->loop;
	animation.max_substep = anim_data->max_substep;
	animation.frame_delay = anim_data->frame_delay;
}
void Animation_Stop(){
	animation.poses = 0;
	animation.loop_en = 0;
	animation.c_pose_n = 0;
	animation.c_step_n = 0;
	animation.c_frame_delay = 0;
}
void Animation_Play_Frame(){
	//Precalculations before first step of pose transition
	if(!animation.c_step_n){
		///Drive
		/*
			Direction 0-180, speed 0-80. Servos 1,2,5,6
		*/
		//Scale speed
		//2*80 by this value should be decreased every servo, pointing to center
		float scale = (((float)ANIM_DATA_FW_BW_3_H_BW - (float)ANIM_DATA_FW_BW_3_H_FW) / (2 * (float)ANIM_DATA_DRIVE_SPEED_MAX)) * ((float)ANIM_DATA_DRIVE_SPEED_MAX - animation.c_drive_speed);
		anim_data_drive.data[1] = anim_data_forward_3.data[1] - scale;
		anim_data_drive.data[2] = anim_data_forward_3.data[2] - scale;
		anim_data_drive.data[5] = anim_data_forward_3.data[5] + scale;
		anim_data_drive.data[6] = anim_data_forward_3.data[6] + scale;

		anim_data_drive.data[9] = anim_data_forward_3.data[9] + scale;
		anim_data_drive.data[10] = anim_data_forward_3.data[10] + scale;
		anim_data_drive.data[13] = anim_data_forward_3.data[13] - scale;
		anim_data_drive.data[14] = anim_data_forward_3.data[14] - scale;

		anim_data_drive.data[17] = anim_data_forward_3.data[17] + scale;
		anim_data_drive.data[18] = anim_data_forward_3.data[18] + scale;
		anim_data_drive.data[21] = anim_data_forward_3.data[21] - scale;
		anim_data_drive.data[22] = anim_data_forward_3.data[22] - scale;

		anim_data_drive.data[25] = anim_data_forward_3.data[25] - scale;
		anim_data_drive.data[26] = anim_data_forward_3.data[26] - scale;
		anim_data_drive.data[29] = anim_data_forward_3.data[29] + scale;
		anim_data_drive.data[30] = anim_data_forward_3.data[30] + scale;

		//Proportionally decrease apporiate side
		float directional_scale = 0;
		float directional_scale_max = ((ANIM_DATA_FW_BW_3_H_BW - scale) - (ANIM_DATA_FW_BW_3_H_FW + scale))/3.0f;
		if(animation.c_drive_dir < (ANIM_DATA_DRIVE_DIRECTION_MAX / 2)){
			directional_scale = (directional_scale_max/90.0f) * (90.0f - animation.c_drive_dir);
			anim_data_drive.data[1] -= directional_scale;
			anim_data_drive.data[2] -= directional_scale;

			anim_data_drive.data[9] += directional_scale;
			anim_data_drive.data[10] += directional_scale;

			anim_data_drive.data[17] += directional_scale;
			anim_data_drive.data[18] += directional_scale;

			anim_data_drive.data[25] -= directional_scale;
			anim_data_drive.data[26] -= directional_scale;

		}else if(animation.c_drive_dir > (ANIM_DATA_DRIVE_DIRECTION_MAX / 2)){
			directional_scale = (directional_scale_max/90.0f) * (animation.c_drive_dir - 90.0f);
			anim_data_drive.data[5] += directional_scale;
			anim_data_drive.data[6] += directional_scale;

			anim_data_drive.data[13] -= directional_scale;
			anim_data_drive.data[14] -= directional_scale;

			anim_data_drive.data[21] -= directional_scale;
			anim_data_drive.data[22] -= directional_scale;

			anim_data_drive.data[29] += directional_scale;
			anim_data_drive.data[30] += directional_scale;
		}
	}

	if((animation.loop_en && (animation.c_pose_n < animation.poses)) || (!animation.loop_en && (animation.c_pose_n < (animation.poses - 1)))){
		float *from = (float *)&animation.data[SERVO_COUNT * animation.c_pose_n];
		float *to;
		if(animation.c_pose_n == (animation.poses - 1)){
			to = (float *)&animation.data[0];
		}else{
			to = (float *)&animation.data[SERVO_COUNT * (animation.c_pose_n + 1)];
		}

		if(!animation.c_step_n){
			//At first step of pose transition
			float max = 0;
			uint8_t i = 0;
			while(i != SERVO_COUNT){
				if(fabs(to[i] - from[i]) > max){
					max = fabs(to[i] - from[i]);
				}
				i++;
			}
			animation.c_steps = max / animation.max_substep;
		}

		if(animation.c_step_n != animation.c_steps){
			uint8_t i = 0;
			while(i != SERVO_COUNT){
				if(to[i] > from[i]){
					animation.c_data[i] = from[i] + (((to[i] - from[i]) / animation.c_steps) * animation.c_step_n);
				}else{
					animation.c_data[i] = from[i] - (((from[i] - to[i]) / animation.c_steps) * animation.c_step_n);
				}
				i++;
			}
			Servo_Set((float *)&animation.c_data[0]);
			animation.c_step_n++;
		}else{
			animation.c_step_n = 0;
			animation.c_pose_n++;
		}
	}else if(animation.loop_en){
		animation.c_pose_n = 0;
		animation.c_step_n = 0;
	}else{
		Animation_Stop();
	}
}
void Animation_Play(){
	if(animation.poses && (animation.c_frame_delay >= animation.frame_delay)){
		Animation_Play_Frame();
		animation.c_frame_delay = 0;
	}
}
