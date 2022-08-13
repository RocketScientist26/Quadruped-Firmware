#include "main.h"
#include "app.h"
#include "Device/button.h"
#include "Device/servo.h"
#include "Device/led.h"
#include "settings.h"
#include "parser.h"
#include "animation.h"

static struct app{
	uint8_t cmd;
	uint32_t cmd_time_ms;
	uint8_t data[APP_DATA_BUFF_SIZE];
}app;

void App_SysTick(){
	if(app.cmd && (app.cmd_time_ms < APP_CMD_TIMEOUT_MS)){
		app.cmd_time_ms++;
	}
}

void App_Init(){
	Settings_Init();
	Parser_Init();
}
void App_Loop(){
	//Handle settings reset with button
	if(Button_Pressed()){
		if(!Button_Debounce_Read()){
			Settings_Reset();
			app.cmd = PARSER_CMD_NONE;
			app.cmd_time_ms = 0;
		}
	}

	//Handle animation commands
	uint8_t cmd = Parser_Update((uint8_t *)&app.data[0]);
	//Reset command timeout timer
	if(app.cmd && cmd){
		app.cmd_time_ms = 0;
	}
	//If we got a new command
	if(cmd && (app.cmd != cmd)){
		app.cmd = cmd;
		switch(cmd){
			//Start moving, ignoring any current pose
			case PARSER_CMD_FORAWRD_1:
				Animation_Set((anim_data_t *)&anim_data_forward_1);
			break;
			case PARSER_CMD_FORAWRD_2:
				Animation_Set((anim_data_t *)&anim_data_forward_2);
			break;
			case PARSER_CMD_FORAWRD_3:
				Animation_Set((anim_data_t *)&anim_data_forward_3);
			break;
			case PARSER_CMD_BACKWARD_1:
				Animation_Set((anim_data_t *)&anim_data_backward_1);
			break;
			case PARSER_CMD_BACKWARD_2:
				Animation_Set((anim_data_t *)&anim_data_backward_2);
			break;
			case PARSER_CMD_BACKWARD_3:
				Animation_Set((anim_data_t *)&anim_data_backward_3);
			break;
			case PARSER_CMD_TURN_LEFT_1:
				Animation_Set((anim_data_t *)&anim_data_turn_left_1);
			break;
			case PARSER_CMD_TURN_LEFT_2:
				Animation_Set((anim_data_t *)&anim_data_turn_left_2);
			break;
			case PARSER_CMD_TURN_LEFT_3:
				Animation_Set((anim_data_t *)&anim_data_turn_left_3);
			break;
			case PARSER_CMD_TURN_RIGHT_1:
				Animation_Set((anim_data_t *)&anim_data_turn_right_1);
			break;
			case PARSER_CMD_TURN_RIGHT_2:
				Animation_Set((anim_data_t *)&anim_data_turn_right_2);
			break;
			case PARSER_CMD_TURN_RIGHT_3:
				Animation_Set((anim_data_t *)&anim_data_turn_right_3);
			break;
			case PARSER_CMD_SLIDE_LEFT_1:
				Animation_Set((anim_data_t *)&anim_data_slide_left_1);
			break;
			case PARSER_CMD_SLIDE_LEFT_2:
				Animation_Set((anim_data_t *)&anim_data_slide_left_2);
			break;
			case PARSER_CMD_SLIDE_LEFT_3:
				Animation_Set((anim_data_t *)&anim_data_slide_left_3);
			break;
			case PARSER_CMD_SLIDE_RIGHT_1:
				Animation_Set((anim_data_t *)&anim_data_slide_right_1);
			break;
			case PARSER_CMD_SLIDE_RIGHT_2:
				Animation_Set((anim_data_t *)&anim_data_slide_right_2);
			break;
			case PARSER_CMD_SLIDE_RIGHT_3:
				Animation_Set((anim_data_t *)&anim_data_slide_right_3);
			break;

			//Go into Kick pose
			case PARSER_CMD_KICK:
				Animation_Set_Kick(*(uint8_t *)&app.data[0], *(uint8_t *)&app.data[1]);
				Animation_Set((anim_data_t *)&anim_data_kick);
			break;

			//Start driving
			case PARSER_CMD_DRIVE:
				Animation_Set_Drive(*(uint8_t *)&app.data[0], *(uint8_t *)&app.data[1]);
				Animation_Set((anim_data_t *)&anim_data_drive);
			break;

			//Start tricks
			case PARSER_CMD_TRICK_1_SWIM:
				Animation_Set((anim_data_t *)&anim_data_swim_s);
			break;
			case PARSER_CMD_TRICK_2_WORKOUT:
				Animation_Set((anim_data_t *)&anim_data_workout_s);
			break;
			case PARSER_CMD_TRICK_3_HELLO:
				Animation_Set((anim_data_t *)&anim_data_hello_s);
			break;

			//Prevent any return to standby pose or kick animations on timeout
			case PARSER_CMD_SETT:
				app.cmd = PARSER_CMD_NONE;
			break;
		}

		if(app.cmd && (app.cmd != PARSER_CMD_KICK)){
			LED_Set_Mode(LED_ACCELERATE);
		}
	}
	//We got same command but we need to update values
	else if(cmd){
		switch(app.cmd){
			case PARSER_CMD_DRIVE:
				Animation_Set_Drive(*(uint8_t *)&app.data[0], *(uint8_t *)&app.data[1]);
			break;
			case PARSER_CMD_KICK:
				if(!Animation_Is_Playing()){
					Animation_Set_Kick(*(uint8_t *)&app.data[0], *(uint8_t *)&app.data[1]);
					Servo_Set((float *)&anim_data_kick.data[SERVO_COUNT]);
				}
			break;
			case PARSER_CMD_TRICK_1_SWIM:
				if(!Animation_Is_Playing()){
					Animation_Set((anim_data_t *)&anim_data_swim_l);
				}
			break;
			case PARSER_CMD_TRICK_2_WORKOUT:
				if(!Animation_Is_Playing()){
					Animation_Set((anim_data_t *)&anim_data_workout_l);
				}
			break;
			case PARSER_CMD_TRICK_3_HELLO:
				if(!Animation_Is_Playing()){
					Animation_Set((anim_data_t *)&anim_data_hello_l);
				}
			break;
		}
	}

	//Return to standby pose and kick animations if command timed out
	if(app.cmd_time_ms == APP_CMD_TIMEOUT_MS){
		switch(app.cmd){
			case PARSER_CMD_FORAWRD_1: case PARSER_CMD_FORAWRD_2: case PARSER_CMD_FORAWRD_3:
			case PARSER_CMD_BACKWARD_1: case PARSER_CMD_BACKWARD_2: case PARSER_CMD_BACKWARD_3:
			case PARSER_CMD_TURN_LEFT_1: case PARSER_CMD_TURN_LEFT_2: case PARSER_CMD_TURN_LEFT_3:
			case PARSER_CMD_TURN_RIGHT_1: case PARSER_CMD_TURN_RIGHT_2: case PARSER_CMD_TURN_RIGHT_3:
			case PARSER_CMD_SLIDE_LEFT_1: case PARSER_CMD_SLIDE_LEFT_2: case PARSER_CMD_SLIDE_LEFT_3:
			case PARSER_CMD_SLIDE_RIGHT_1: case PARSER_CMD_SLIDE_RIGHT_2: case PARSER_CMD_SLIDE_RIGHT_3:
			case PARSER_CMD_DRIVE:
				//Return to standby pose
				LED_Set_Mode(LED_COOL_DOWN);
				app.cmd = PARSER_CMD_NONE;
				app.cmd_time_ms = 0;
				Animation_Stop();
				Servo_Set((float *)&anim_data_standby[0]);
			break;
			case PARSER_CMD_KICK:
				//Kick
				app.cmd = PARSER_CMD_NONE;
				app.cmd_time_ms = 0;
				Animation_Stop();
				Animation_Kick();
			break;
			case PARSER_CMD_TRICK_1_SWIM:
				//Return from Swim
				Animation_Save_Current_Pose((float *)&anim_data_swim_e.data[0]);
				Animation_Set((anim_data_t *)&anim_data_swim_e);
				while(Animation_Is_Playing()){
					Animation_Play();
				}
				LED_Set_Mode(LED_COOL_DOWN);
				app.cmd = PARSER_CMD_NONE;
				app.cmd_time_ms = 0;
			break;
			case PARSER_CMD_TRICK_2_WORKOUT:
				//Return from Workout
				Animation_Save_Current_Pose((float *)&anim_data_workout_e.data[0]);
				Animation_Set((anim_data_t *)&anim_data_workout_e);
				while(Animation_Is_Playing()){
					Animation_Play();
				}
				LED_Set_Mode(LED_COOL_DOWN);
				app.cmd = PARSER_CMD_NONE;
				app.cmd_time_ms = 0;
			break;
			case PARSER_CMD_TRICK_3_HELLO:
				//Return from Hello
				Animation_Save_Current_Pose((float *)&anim_data_hello_e.data[0]);
				Animation_Set((anim_data_t *)&anim_data_hello_e);
				while(Animation_Is_Playing()){
					Animation_Play();
				}
				LED_Set_Mode(LED_COOL_DOWN);
				app.cmd = PARSER_CMD_NONE;
				app.cmd_time_ms = 0;
			break;
		}
	}

	//Play animation if any
	Animation_Play();
}
