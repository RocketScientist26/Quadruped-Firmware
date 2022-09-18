#include "main.h"
#include "parser.h"
#include "animation.h"
#include "settings.h"
#include "Device/servo.h"
#include "Device/bluetooth.h"
#include "Device/led.h"

/*
	Commands
	Robot detect:
		#?
			#R
	Move:
		#1-3
			#[COMMAND ID (FROM 1 TO 6)]-[SPEED VALUE (FROM 1 TO 3)]
	Kick:
		#L00-00
			#L[KICK DIRECTION (FROM 0 TO ANIM_DATA_KICK_DIRECTION_MAX)]-[KICK STRENGTH (FROM 0 TO ANIM_DATA_KICK_STRENGTH_MAX)]
	Driving:
		#K000-00
			#K[DRIVING DIRECTION (FROM 0 TO ANIM_DATA_DRIVE_DIRECTION_MAX)]-[DRIVING SPEED (FROM 0 TO ANIM_DATA_DRIVE_STRENGHT_MAX)]
	Special tricks:
		#D1
			#D[TRICK ID (FROM 1 to 3)]
	LED Enable/disable:
		#E0
			#E[LED SHOULD BE ENABLED OR DISABLED (1 OR 0)]
	Settings page opened:
		#F
			Robot goes into calibration pose.
			We should reply with settings string, example: #C-0-0-0-0-0-0-0-01234Quadruped 1\n
	Request to store settings in flash:
		#G
			We just store current settings to flash
	Settings page closed:
		#H
			Robot should return in normal stand pose
	Calibration value changed for servo:
		#I+91
			#I[CALIBRATION VALUE FROM -9 TO +9][SERVO NUMBER FROM 1 TO 8]
	Bluetooth name and password change requested:
		#JQuadruped 1234
			#J[NAME][PASSWORD]
*/

uint8_t parser_symbols[] = {'?', '1', '2', '3', '4', '5', '6', 'L', 'K', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
uint8_t parser_lengths[] = {2, 4, 4, 4, 4, 4, 4, 7, 8, 3, 3, 2, 2, 2, 5, 16};
uint8_t parser_handshake[] = "#R";

uint8_t Parser_Update(uint8_t *data){
	uint8_t ret = PARSER_CMD_NONE;
	if(Bluetooth_Rx_Ready()){
		switch(Bluetooth_Rx_Data()[1]){
			case '?':
				Bluetooth_Transmit((uint8_t *)&parser_handshake[0], 2);
			break;
			case '1':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_FORAWRD_1;
					break;
					case '2':
						ret = PARSER_CMD_FORAWRD_2;
					break;
					case '3':
						ret = PARSER_CMD_FORAWRD_3;
					break;
				}
			break;
			case '2':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_BACKWARD_1;
					break;
					case '2':
						ret = PARSER_CMD_BACKWARD_2;
					break;
					case '3':
						ret = PARSER_CMD_BACKWARD_3;
					break;
				}
			break;
			case '3':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_TURN_RIGHT_1;
					break;
					case '2':
						ret = PARSER_CMD_TURN_RIGHT_2;
					break;
					case '3':
						ret = PARSER_CMD_TURN_RIGHT_3;
					break;
				}
			break;
			case '4':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_TURN_LEFT_1;
					break;
					case '2':
						ret = PARSER_CMD_TURN_LEFT_2;
					break;
					case '3':
						ret = PARSER_CMD_TURN_LEFT_3;
					break;
				}
			break;
			case '5':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_SLIDE_LEFT_1;
					break;
					case '2':
						ret = PARSER_CMD_SLIDE_LEFT_2;
					break;
					case '3':
						ret = PARSER_CMD_SLIDE_LEFT_3;
					break;
				}
			break;
			case '6':
				switch(Bluetooth_Rx_Data()[3]){
					case '1':
						ret = PARSER_CMD_SLIDE_RIGHT_1;
					break;
					case '2':
						ret = PARSER_CMD_SLIDE_RIGHT_2;
					break;
					case '3':
						ret = PARSER_CMD_SLIDE_RIGHT_3;
					break;
				}
			break;
			case 'L':
				//Kick
				//Data [DIRECTION][STRENGTH]
				data[0] = ((Bluetooth_Rx_Data()[2] - 48) * 10) + (Bluetooth_Rx_Data()[3] - 48);
				data[1] = ((Bluetooth_Rx_Data()[5] - 48) * 10) + (Bluetooth_Rx_Data()[6] - 48);
				if((data[0] <= ANIM_DATA_KICK_DIRECTION_MAX) && (data[1] <= ANIM_DATA_KICK_STRENGTH_MAX)){
					ret = PARSER_CMD_KICK;
				}
			break;
			case 'K':
				//Drive
				//Data [DIRECTION][STRENGTH]
				data[0] = ((Bluetooth_Rx_Data()[2] - 48) * 100) + ((Bluetooth_Rx_Data()[3] - 48) * 10) + (Bluetooth_Rx_Data()[4] - 48);
				data[1] = ((Bluetooth_Rx_Data()[6] - 48) * 10) + (Bluetooth_Rx_Data()[7] - 48);
				if((data[0] <= ANIM_DATA_DRIVE_DIRECTION_MAX) && (data[1] <= ANIM_DATA_DRIVE_SPEED_MAX)){
					ret = PARSER_CMD_DRIVE;
				}
			break;
			case 'D':
				//Tricks
				switch(Bluetooth_Rx_Data()[2]){
					case '1':
						ret = PARSER_CMD_TRICK_1_SWIM;
					break;
					case '2':
						ret = PARSER_CMD_TRICK_2_WORKOUT;
					break;
					case '3':
						ret = PARSER_CMD_TRICK_3_HELLO;
					break;
				}
			break;
			case 'E':
				//LED Enable/disable from settings page
				LED_Enable(Bluetooth_Rx_Data()[2] - 48);
				Settings_Write_LED(Bluetooth_Rx_Data()[2] - 48);
			break;
			case 'F':
				//Settings page opened
				Animation_Stop();
				LED_Set_Mode(LED_CONSTANT);
				Servo_Set((float *)&anim_data_calib[0]);
				Bluetooth_Transmit(Settings_Data(), 34);
				ret = PARSER_CMD_SETT;
			break;
			case 'G':
				//Write settings to flash request
				Settings_Write();
			break;
			case 'H':
				//Settings page closed
				Servo_Set((float *)&anim_data_standby[0]);
			break;
			case 'I':
				//Servo calibration reqeuest
				if(Bluetooth_Rx_Data()[2] == '-'){
					Servo_Set_Calib((int8_t)(Bluetooth_Rx_Data()[3]-48) - (2 * (Bluetooth_Rx_Data()[3]-48)), Bluetooth_Rx_Data()[4]-48);
				}else{
					Servo_Set_Calib(Bluetooth_Rx_Data()[3]-48, Bluetooth_Rx_Data()[4]-48);
				}
				Settings_Set_Calib(Servo_Calib_Data());
				Servo_Set((float *)&anim_data_calib[0]);
			break;
			case 'J':
				//Bluetooth name/password change request
				Settings_Write_Bluetooth(&Bluetooth_Rx_Data()[12], &Bluetooth_Rx_Data()[2]);
				Servo_Set((float *)&anim_data_standby[0]);
			break;
		}
		Bluetooth_Listen();
	}else if(!Bluetooth_Connected_Debounce()){
		Animation_Stop();
		Servo_Set((float *)&anim_data_standby[0]);
	}
	return ret;
}
void Parser_Init(){
	Bluetooth_Init('#', parser_symbols, parser_lengths, sizeof(parser_lengths));
}
