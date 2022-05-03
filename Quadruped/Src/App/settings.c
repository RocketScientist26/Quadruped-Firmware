#include "main.h"
#include "settings.h"
#include "flash.h"
#include "general.h"

extern UART_HandleTypeDef huart1;

uint8_t settings[35] = "#C+0+0+0+0+0+0+0+01234Quadruped 1\n";

static uint8_t settings_default[35] = "#C+0+0+0+0+0+0+0+01234Quadruped 1\n";
static uint8_t settings_bt_name_default[19] = "AT+NAMEQuadruped\r\n";
static uint8_t settings_bt_password_default[13] = "AT+PIN1234\r\n";
static uint8_t settings_bt_tmp[20];

void Settings_Bluetooth_Change(uint8_t *name, uint8_t *password){
	//Reset Bluetooth
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(500);//Wait for Bluetooth to start and reset it's name and password also
	while(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) != GPIO_PIN_RESET);//Wait for Bluetooth disconnect
	HAL_Delay(300);

	//Copy "AT+NAME"
	General_Copy(&settings_bt_name_default[0], &settings_bt_tmp[0],7);
	//Copy name
	uint8_t i = 0;
	while(i != 10){
		if(name[i] != ' '){
			settings_bt_tmp[i+7] = name[i];
			i++;
		}else{
			break;
		}
	}
	//Fill /r/n
	settings_bt_tmp[i] = '\r';
	settings_bt_tmp[i+1] = '\n';
	//Send
	HAL_UART_Transmit(&huart1, settings_bt_tmp, i+9, 2500);
	HAL_Delay(200);


	//Copy "AT+PIN"
	General_Copy(&settings_bt_password_default[0], &settings_bt_tmp[0],6);
	//Copy password
	i = 0;
	while(i != 4){
		if(password[i] != ' '){
			settings_bt_tmp[i+6] = password[i];
			i++;
		}else{
			break;
		}
	}
	//Fill /r/n
	settings_bt_tmp[i] = '\r';
	settings_bt_tmp[i+1] = '\n';
	//Send
	HAL_UART_Transmit(&huart1, settings_bt_tmp, i+8, 2500);
	HAL_Delay(200);


	//Reset Bluetooth
	HAL_Delay(800);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
}
void Settings_Reset(){
	Flash_Write(settings_default,35);
	General_Copy(&settings_default[0], &settings[0],35);

	//Reset Bluetooth name and password to defaults
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(500);//Wait for Bluetooth to start and reset it's name and password also
	while(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) != GPIO_PIN_RESET);//Wait for Bluetooth disconnect
	HAL_Delay(300);
	HAL_UART_Transmit(&huart1, settings_bt_name_default, 18, 2500);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart1, settings_bt_password_default, 12, 2500);

	//Reset Bluetooth
	HAL_Delay(800);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(400);
	HAL_GPIO_WritePin(BT_RESET_GPIO_Port, BT_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
}
void Settings_Read(int8_t *calib, uint8_t *led){
	//Read settings from flash
	Flash_Read(settings, 35);
	if(settings[0] != '#'){//Wrong data, reset
		Settings_Reset();
	}

	//Read LED status from string
	if(settings[32] == '1'){
		led = (uint8_t *)((uint8_t)1);
	}else{
		led = (uint8_t *)((uint8_t)0);
		TIM2 -> CCR2 = 0;
	}
	
	//Read calibration from string
	uint8_t i = 0;
	while(i != 8){
		i++;
		if(settings[(2*i)] == '-'){
			calib[i-1] = (settings[(2*i)+1]-48)-(2*(settings[(2*i)+1]-48));
		}else{
			calib[i-1] = settings[(2*i)+1]-48;
		}
	}
}
