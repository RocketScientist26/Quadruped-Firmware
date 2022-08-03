#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "settings.h"
#include "anim_data.h"
#include "Device/bluetooth.h"
#include "Device/flash.h"
#include "Device/led.h"
#include "Device/servo.h"

static uint8_t settings_act[35];
static const uint8_t settings_def[35] = "#C+0+0+0+0+0+0+0+01234Quadruped 1\n";

uint8_t Settings_Verify(){
	if(
		(settings_act[0] != '#')||
		(settings_act[1] != 'C')||
		((settings_act[2] != '+') && (settings_act[2] != '-')) ||
		((settings_act[4] != '+') && (settings_act[4] != '-')) ||
		((settings_act[6] != '+') && (settings_act[6] != '-')) ||
		((settings_act[8] != '+') && (settings_act[8] != '-')) ||
		((settings_act[10] != '+') && (settings_act[10] != '-')) ||
		((settings_act[12] != '+') && (settings_act[12] != '-')) ||
		((settings_act[14] != '+') && (settings_act[14] != '-')) ||
		((settings_act[16] != '+') && (settings_act[16] != '-')) ||
		((settings_act[3] - 48) > 9) ||
		((settings_act[5] - 48) > 9) ||
		((settings_act[7] - 48) > 9) ||
		((settings_act[9] - 48) > 9) ||
		((settings_act[11] - 48) > 9) ||
		((settings_act[13] - 48) > 9) ||
		((settings_act[15] - 48) > 9) ||
		((settings_act[17] - 48) > 9) ||
		((settings_act[32] - 48) > 1) ||
		(settings_act[33] != '\n') ||
		(settings_act[34] != 0)
	){
		//Wrong data
		return 0;
	}
	return 1;
}
void Settings_Write(){
	//Verify
	if(!Settings_Verify()){
		memcpy(&settings_act[0], &settings_def[0], 35);
	}

	//Write
	Flash_Write((uint8_t *)&settings_act[0], 35);
}
void Settings_Reset(){
	memcpy(&settings_act[0], &settings_def[0], 35);
	Flash_Write((uint8_t *)&settings_def[0], 35);
	Settings_Write_Bluetooth(&settings_act[18], &settings_act[22]);
}
void Settings_Read(int8_t *calib, uint8_t *led){
	Flash_Read(settings_act, 35);
	//Verify
	if(!Settings_Verify()){
		memcpy(&settings_act[0], &settings_def[0], 35);
	}

	//Calibration
	uint8_t i = 0;
	while(i != 8){
		i++;
		if(settings_act[(2 * i)] == '-'){
			calib[i - 1] = (settings_act[(2 * i) + 1] - 48) - (2 * (settings_act[(2 * i) + 1] - 48));
		}else{
			calib[i - 1] = settings_act[(2 * i) + 1] - 48;
		}
	}
	//LED
	*led = settings_act[32] - 48;
}
uint8_t *Settings_Data(){
	return (uint8_t *)&settings_act[0];
}
void Settings_Set_Calib(int8_t *calib){
	//Calibration
	uint8_t i = 0;
	while(i != 8){
		if(calib[i] >= 0){
			settings_act[2 + (i * 2)] = '+';
			settings_act[3 + (i * 2)] = (uint8_t)calib[i] + (uint8_t)48;
		}else{
			settings_act[2 + (i * 2)] = '-';
			settings_act[3 + (i * 2)] = (uint8_t)((int8_t)calib[i] - (2 * (int8_t)calib[i])) + (uint8_t)48;
		}
		i++;
	}
	
	//Verify
	if(!Settings_Verify()){
		memcpy(&settings_act[0], &settings_def[0], 35);
	}
}
void Settings_Write_LED(uint8_t led){
	settings_act[32] = led + 48;
	Settings_Write();
}
void Settings_Write_Bluetooth(uint8_t *bt_password, uint8_t *bt_name){
	if(!Settings_Verify()){
		memcpy(&settings_act[0], &settings_def[0], 35);
	}

	//Password
	memcpy(&settings_act[18], bt_password, 4);
	//Name
	memcpy(&settings_act[22], bt_name, 10);

	//Write
	Flash_Write((uint8_t *)&settings_act[0], 35);

	//Reset Bluetooth
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(500);

	//Wait for Bluetooth disconnect
	while(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) != GPIO_PIN_RESET);
	HAL_Delay(300);

	//Set Bluetooth password
	uint8_t *tmp = malloc(18);
	memcpy(&tmp[0], (uint8_t *)"AT+PIN", 6);
	memcpy(&tmp[6], (uint8_t *)&bt_password[0], 4);
	memcpy(&tmp[10], (uint8_t *)"\r\n", 2);
	Bluetooth_Transmit((uint8_t *)tmp, 12);
	HAL_Delay(50);

	//Set Bluetooth name
	memcpy(&tmp[0], (uint8_t *)"AT+NAME", 7);
	//Detect spaces at the end of the name
	uint8_t i = 10;
	while(i != 0){
		i--;
		if(bt_name[i] != ' '){
			break;
		}
	}
	memcpy(&tmp[7], (uint8_t *)&bt_name[0], i + 1);
	memcpy(&tmp[i + 8], (uint8_t *)"\r\n", 2);
	Bluetooth_Transmit((uint8_t *)tmp, 12);
	Bluetooth_Transmit((uint8_t *)tmp, 18);
	HAL_Delay(800);

	//Reset Bluetooth
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
}
void Settings_Init(){
	uint8_t led = 0;
	Settings_Read(Servo_Calib_Data(), &led);

	//Enable LED
	LED_Enable(led);
	LED_Init();

	//Enable servos
	Servo_Init();
	Servo_Set((float *)&anim_data_standby[0]);
}
