#include "main.h"
#include "app.h"
#include "flash.h"
#include "general.h"
#include "led.h"
#include "bluetooth.h"
#include "servo.h"
#include "settings.h"
#include "movements.h"

//Remotely controlled flags
uint8_t app_action = 0;
uint8_t app_action_name_and_password_changed = 0;
uint8_t app_return_to_stay = 0;
uint8_t app_button_mode_motion_speed = 0;
uint8_t app_kick_direction = 0;//0-90
uint8_t app_kick_strength = 0;//0-80
uint16_t app_driving_direction = 0;
uint16_t app_driving_speed = 0;
//Settings
extern uint8_t settings[35];
extern int8_t servo_calibration_values[8];
extern uint8_t led_active;
//Local variables
uint8_t app_action_button_reset = 0;
uint8_t app_movement_start = 1;
//Movement arrays
extern float servo_current_values[8];
extern float movements_standby_pose[8];
extern float movements_calibration_pose[8];
extern float movements_buttons_mode_patterns[576];
extern float movements_special_tricks_swim[104];
extern float movements_kick_pose[8];

//Reset button
uint8_t App_RESET_Button_Read(){
	uint8_t i = 0;
	while(i != 10){
		if(HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin) == GPIO_PIN_SET){
			return 0;
		}
		i++;
	}
	return 1;
}

//Action cancel
void App_Action_Cancel(){
	app_action = 0;
	app_movement_start = 1;
	app_return_to_stay = APP_STAY_FROM_BTNS_DRIVE_SETTINGS;
}

//Interrupts
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim -> Instance == TIM1){
		App_Action_Cancel();
	}
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	Bluetooth_Read_Message();
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == BUTTON_RESET_Pin){
		if(HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin) == GPIO_PIN_RESET){
			app_action_button_reset = 1;
		}
	}
	if(GPIO_Pin == BT_STAT_Pin){
		if(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) == GPIO_PIN_RESET){
			//Bluetoot disconnected
		}
	}
}
void App_SysTick_Call(){
	if(app_action != 12){//If not in settings page
		Led_Breath(app_action, LED_NOT_IN_SETTINGS);
	}else{
		Led_Breath(app_action, LED_IN_SETTINGS);
	}
}

//Loops
void App_Loop_Settings(){
	//Bluetooth name and password change
	if(app_action_name_and_password_changed == 1){
		Settings_Bluetooth_Change(&settings[22], &settings[18]);//Change name and password
		app_action_name_and_password_changed = 0;
		App_Action_Cancel();
		Bluetooth_UART_Listen();
	}
	//Settings reset by button press
	if(app_action_button_reset == 1){
		if(App_RESET_Button_Read() == 1){
			Led_Off();
			Settings_Reset();
			Settings_Read(&servo_calibration_values[0], &led_active);
			Led_On();
			App_Action_Cancel();
			Bluetooth_UART_Listen();
		}
		app_action_button_reset = 0;
	}
}
void App_Loop_Buttons_Mode_Actions(){
	if((app_action >= 1)&&(app_action <= 6)){
		if(app_movement_start == 1){
			app_movement_start = 0;
			if(app_button_mode_motion_speed == 1){
				Servo_Move(movements_standby_pose, &movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], MOV_BTNS_MODE_SAMPLES_SP1, MOV_BTNS_MODE_DELAY_SP1, SERVO_NOINT);
			}else if(app_button_mode_motion_speed == 2){
				Servo_Move(movements_standby_pose, &movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], MOV_BTNS_MODE_SAMPLES_SP2, MOV_BTNS_MODE_DELAY_SP2, SERVO_NOINT);
			}else if(app_button_mode_motion_speed == 3){
				Servo_Move(movements_standby_pose, &movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], MOV_BTNS_MODE_SAMPLES_SP3, MOV_BTNS_MODE_DELAY_SP3, SERVO_NOINT);
			}
		}
		else{
			if(app_button_mode_motion_speed == 1){
				Servo_Play_Pattern(&movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], 4, MOV_BTNS_MODE_SAMPLES_SP1, MOV_BTNS_MODE_DELAY_SP1, SERVO_INT);
			}else if(app_button_mode_motion_speed == 2){
				Servo_Play_Pattern(&movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], 4, MOV_BTNS_MODE_SAMPLES_SP2, MOV_BTNS_MODE_DELAY_SP2, SERVO_INT);
			}else if(app_button_mode_motion_speed == 3){
				Servo_Play_Pattern(&movements_buttons_mode_patterns[((app_action-1)*96)+(((app_button_mode_motion_speed-1)*32))], 4, MOV_BTNS_MODE_SAMPLES_SP3, MOV_BTNS_MODE_DELAY_SP3, SERVO_INT);
			}
		}
	}
}
void App_Loop_Kick(){
	if(app_action == 7){
		if(app_movement_start == 1){
			app_movement_start = 0;
			Servo_Move(movements_standby_pose, movements_kick_pose, MOV_KICK_ENTER_EXIT_SAMPLES, MOV_KICK_ENTER_EXIT_DELAY, SERVO_INT);
			if(app_action == 7){
				app_return_to_stay = APP_STAY_FROM_KICK;
			}
		}
		Servo_Set_Kick(app_kick_direction, app_kick_strength, SERVO_KICK_NO_KICK);
	}
}
void App_Loop_Drive(){
	if(app_action == 8){//Drive
		Servo_Drive(app_driving_direction, app_driving_speed);
	}
}
void App_Loop_Special_Tricks(){
	if(app_action == 9){//Swimming
		if(app_movement_start == 1){
			app_movement_start = 0;
			Servo_Play_Trick_Pattern(movements_standby_pose, movements_special_tricks_swim, 9, MOV_SPC_TRICKS_SWIM_ENTER_EXIT_SAMPLES, MOV_SPC_TRICKS_SWIM_ENTER_EXIT_DELAY, SERVO_INT);
			HAL_Delay(70);
			Servo_Move(&movements_special_tricks_swim[32], &movements_special_tricks_swim[40], MOV_SPC_TRICKS_SWIM_ENTER_EXIT_SAMPLES, MOV_SPC_TRICKS_SWIM_ENTER_EXIT_DELAY, SERVO_INT);
			if(app_action == 9){
				app_return_to_stay = APP_STAY_FROM_SWIM;
			}
		}
		else{
			Servo_Play_Pattern(&movements_special_tricks_swim[40], 8, MOV_SPC_TRICKS_SWIM_PLAY_SAMPLES, MOV_SPC_TRICKS_SWIM_PLAY_DELAY, SERVO_INT);
		}
	}
}
void App_Loop_Settings_Mode_Enter(){
	if(app_action == 12){
		if(app_movement_start == 1){
			app_movement_start = 0;
			General_Copy_Float(movements_calibration_pose, servo_current_values, 8);
			Servo_Move(movements_standby_pose, movements_calibration_pose, MOV_SETTINGS_AND_RETURN_SAMPLES, MOV_SETTINGS_AND_RETURN_DELAY, SERVO_NOINT);
		}
	}
}
void App_Loop_Return_To_Stay(){
	if((app_action == 0)&&(app_return_to_stay != APP_STAY_NO_RETURN)){
		if(app_return_to_stay == APP_STAY_FROM_BTNS_DRIVE_SETTINGS){ 
			Servo_Move(servo_current_values, movements_standby_pose, MOV_SETTINGS_AND_RETURN_SAMPLES, MOV_SETTINGS_AND_RETURN_DELAY, SERVO_NOINT);
		}else if(app_return_to_stay == APP_STAY_FROM_SWIM){
			
		}else if(app_return_to_stay == APP_STAY_FROM_WORKOUT){
			
		}else if(app_return_to_stay == APP_STAY_FROM_HELLO){
			
		}else if(app_return_to_stay == APP_STAY_FROM_KICK){
			Servo_Set_Kick(app_kick_direction, app_kick_strength, SERVO_KICK_SET_KICK);
			Servo_Move(movements_kick_pose, movements_standby_pose, MOV_KICK_ENTER_EXIT_SAMPLES, MOV_KICK_ENTER_EXIT_DELAY, SERVO_NOINT);
		}
		app_return_to_stay = APP_STAY_NO_RETURN;
	}
}

//App
void App_Init(){
	Settings_Read(servo_calibration_values, &led_active);
	Servo_Init();
	Servo_Set(movements_standby_pose);
	Led_Init();
	Bluetooth_UART_Listen();
}
void App_Loop(){
	App_Loop_Settings();//Check if settings need to be updated in Flash

	App_Loop_Buttons_Mode_Actions();//Check if any movement requested
	App_Loop_Kick();
	App_Loop_Drive();
	App_Loop_Special_Tricks();//Swimming, Workout, Hello
	App_Loop_Settings_Mode_Enter();

	App_Loop_Return_To_Stay();//Check if movement finished and we need to return no standby pose
}
