#include <math.h>
#include "main.h"
#include "animation.h"
#include "Device/servo.h"

struct animation{
	float c_data[SERVO_COUNT];
	uint32_t c_pose_n;
	uint32_t c_steps;
	uint32_t c_step_n;
	uint32_t c_frame_delay;

	float *data;
	uint32_t poses;
	uint8_t loop_en;
	uint32_t frame_delay;
}animation;

void Animation_SysTick(){
	if(animation.poses){
		animation.c_frame_delay++;
	}
}
void Animation_Stop(){
	animation.poses = 0;
	animation.loop_en = 0;
	animation.c_pose_n = 0;
	animation.c_step_n = 0;
	animation.c_frame_delay = 0;
}
void Animation_Set(anim_data_t *anim_data){
	animation.c_pose_n = 0;
	animation.c_step_n = 0;

	animation.data = &anim_data->data[0];
	animation.poses = anim_data->poses;
	animation.loop_en = anim_data->loop;
	animation.frame_delay = anim_data->delay;
}
void Animation_Play_Frame(){
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
				if(fabs(to[i] - from[i]) > i){
					max = fabs(to[i] - from[i]);
				}
				i++;
			}
			animation.c_steps = max / ANIMATION_MAX_SUBSTEP;
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
