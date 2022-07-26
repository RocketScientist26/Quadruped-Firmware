#include <string.h>
#include "main.h"
#include "bluetooth.h"
#include "app.h"
#include "flash.h"
#include "led.h"
#include "servo.h"

extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart1;

extern uint8_t app_action;
extern uint8_t app_action_name_and_password_changed;
extern uint8_t app_return_to_stay;
extern uint8_t app_button_mode_motion_speed;
extern uint8_t app_kick_direction;
extern uint8_t app_kick_strength;
extern uint16_t app_driving_direction;
extern uint16_t app_driving_speed;
extern float movements_calibration_pose[8];
extern int8_t servo_calibration_values[8];
extern uint8_t settings[35];

uint8_t bluetooth_rx_data[512];
uint8_t bluetooth_encrypted_request_code[256];
uint8_t bluetooth_encrypted_response_code[512];

void Bluetooth_UART_Listen(){
	HAL_UART_Receive_IT(&huart1, &bluetooth_rx_data[0], 1);
}
void Bluetooth_UART_Timer_Stop(){
	HAL_TIM_Base_Stop_IT(&htim1);
	TIM1 -> CNT = 0;
}
void Bluetooth_UART_Timer_Start(){
	HAL_TIM_Base_Start_IT(&htim1);
}
void Bluetooth_UART_Timer_Reset(){
	Bluetooth_UART_Timer_Stop();
	Bluetooth_UART_Timer_Start();
}
uint8_t Bluetooth_Is_Connected(){
	if(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) == GPIO_PIN_SET){
		return 1;
	}
	return 0;
}
void Bluetooth_Receive(uint16_t count){
	HAL_UART_Receive(&huart1, &bluetooth_rx_data[0], count, (count*6)+300);
}
void Bluetooth_Transmit(uint8_t *data, uint16_t count){
	HAL_UART_Transmit(&huart1, &data[0], count, (count*9)+300);
}

void Bluetooth_Read_Message(){
	if(Bluetooth_Is_Connected() == 1){
		if(bluetooth_rx_data[0] == '#'){//Command
			Bluetooth_Receive(1);
			//Movement Commands Forward, Backward, Turn Left, Turn Right, Slide Left, Slide Right
			//Example: #1-3, #[COMMAND ID HERE FROM 1 TO 6]-[SPEED VALUE HERE FROM 1 TO 3]
			if((bluetooth_rx_data[0] >= (1+48))&&(bluetooth_rx_data[0] <= (6+48))){
				app_action = bluetooth_rx_data[0] - 48;
				Bluetooth_Receive(2);
				app_button_mode_motion_speed = bluetooth_rx_data[1]-48;
				if((app_button_mode_motion_speed>3)||(app_button_mode_motion_speed<1)){
					app_button_mode_motion_speed = 1;
				}
				Bluetooth_UART_Timer_Reset();
			}
			//Kick
			else if(bluetooth_rx_data[0] == 'L'){
				Bluetooth_Receive(5);//#L00-00
				app_action = 7;
				app_kick_strength = ((bluetooth_rx_data[0]-48)*10)+(bluetooth_rx_data[1]-48);
				app_kick_direction = ((bluetooth_rx_data[3]-48)*10)+(bluetooth_rx_data[4]-48);
				Bluetooth_UART_Timer_Reset();
			}
			//Driving
			else if(bluetooth_rx_data[0] == 'K'){
				Bluetooth_Receive(6);//#K020-80
				app_driving_direction = ((bluetooth_rx_data[0]-48)*100)+((bluetooth_rx_data[1]-48)*10)+(bluetooth_rx_data[2]-48);
				app_driving_speed = ((bluetooth_rx_data[4]-48)*10)+(bluetooth_rx_data[5]-48);
				app_action = 8;
				Bluetooth_UART_Timer_Reset();
			}
			//Special Tricks
			else if(bluetooth_rx_data[0] == 'D'){
				//#D1 #D2 #D3
				Bluetooth_Receive(1);
				if((bluetooth_rx_data[0] >= (1 + 48))&&(bluetooth_rx_data[0] <= (3 + 48))){
					app_action = 8 + (bluetooth_rx_data[0] - 48);
				}
				Bluetooth_UART_Timer_Reset();
			}
			//LED
			else if(bluetooth_rx_data[0] == 'E'){
				//#E0 #E1
				Bluetooth_Receive(1);
				if(bluetooth_rx_data[0] == '1'){
					Led_On();
					settings[32] = '1';
				}
				else{
					Led_Off();
					settings[32] = '0';
				}
				Flash_Write(&settings[0],35);
			}
			//Settings
			else if(bluetooth_rx_data[0] == 'S'){
				//nastroikebis dgomi da dabruneba parametrebis
				Bluetooth_Receive(1);
				Bluetooth_UART_Timer_Stop();
				if((bluetooth_rx_data[0] == 'O')||(bluetooth_rx_data[0] == 'W')){
					//Assemble calibration values into string //#C-0-0-0-0-0-0-0-01234Quadruped 1\n
					uint8_t i = 0;
					while(i != 8){
						i++;
						if(servo_calibration_values[i-1] < 0){
							settings[(2*i)] = '-';
							settings[(2*i)+1] = (servo_calibration_values[i-1] - (2*servo_calibration_values[i-1]))+48;
						}
						else{
							settings[(2*i)] = '+';
							settings[(2*i)+1] = servo_calibration_values[i-1]+48;
						}
					}
					if(bluetooth_rx_data[0] == 'O'){
						Bluetooth_Transmit(&settings[0], 34);
						app_return_to_stay = APP_STAY_NO_RETURN;
						app_action = 12;
					}
					else if(bluetooth_rx_data[0] == 'W'){//Write configuration to flash request #SW
						Flash_Write(&settings[0],35);
					}
				}
				else if(bluetooth_rx_data[0] == 'C'){//Settings page closed #SC
					app_return_to_stay = APP_STAY_FROM_BTNS_DRIVE_SETTINGS;
					Bluetooth_UART_Timer_Start();
				}
				else if(bluetooth_rx_data[0] == 'D'){//Adjust joint position and calibration value #SD+91
					Bluetooth_Receive(3);
					int8_t v = bluetooth_rx_data[1]-48;
					uint8_t n = bluetooth_rx_data[2]-48-1;
					if(bluetooth_rx_data[0] == '-'){
						v = v-(2*v);
					}
					servo_calibration_values[n] = v;
					Servo_Set(&movements_calibration_pose[0]);
				}
				else if(bluetooth_rx_data[0] == 'S'){//Set new Bluetooth name and password #SSNNNNNNNNNNPPPP
					Bluetooth_Receive(14);
					memcpy(&settings[18], &bluetooth_rx_data[10], 4);	//#C-0-0-0-0-0-0-0-01234Quadruped 1\n
					memcpy(&settings[22], &bluetooth_rx_data[0], 10);
					Flash_Write(&settings[0],35);
					//Wait for disconnecting, than change name/password and reset Bluetooth
					app_action_name_and_password_changed = 1;
					app_return_to_stay = APP_STAY_FROM_BTNS_DRIVE_SETTINGS;
					Bluetooth_UART_Timer_Start();
				}
			}
		}
	}
	Bluetooth_UART_Listen();
}
