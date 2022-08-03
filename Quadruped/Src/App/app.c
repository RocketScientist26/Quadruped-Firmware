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
/*	//Handle settings reset with button
	if(Button_Pressed()){
		if(!Button_Debounce_Read()){
			Settings_Reset();
			app.cmd = PARSER_CMD_NONE;
			app.cmd_time_ms = 0;
		}
	}
*/
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
			break;

			//Start driving
			case PARSER_CMD_DRIVE:
			break;

			//Start tricks
			case PARSER_CMD_TRICK_1_SWIM:
			break;
			case PARSER_CMD_TRICK_2_WORKOUT:
			break;
			case PARSER_CMD_TRICK_3_HELLO:
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

	//!TBD Kick and Drive mode directions and value update
	//!TBD Animation - Play START once, play loop/play loop with updated variables

	//Set return to standby pose and kick animations if command timed out
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
			break;
			case PARSER_CMD_TRICK_1_SWIM:
				//Return from Swim
			break;
			case PARSER_CMD_TRICK_2_WORKOUT:
				//Return from Workout
			break;
			case PARSER_CMD_TRICK_3_HELLO:
				//Return from Hello
			break;
		}
	}

	//Play animation if any
	Animation_Play();
}
