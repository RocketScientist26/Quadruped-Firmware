#include "main.h"
#include "bluetooth.h"

extern UART_HandleTypeDef huart1;

struct bluetooth_rx{
	uint8_t ready;
	uint8_t cnt;
	uint8_t receiving;
	uint32_t receiving_ms;
	uint8_t data[BLUETOOTH_MAX_RX_SIZE];
	uint8_t command_symbol;
	uint16_t commands;
	uint8_t *symbols;
	uint8_t *lengths;
}bluetooth_rx;

uint8_t Bluetooth_Find_Rx_Length(uint8_t rx_symbol){
	//Find command length by symbol
	uint8_t i = 0;
	while(i != bluetooth_rx.commands){
		if(bluetooth_rx.symbols[i] == rx_symbol){
			return i;
		}
		i++;
	}
	return i;
}
uint8_t Bluetooth_Connected_Debounce(){
	uint8_t level;
	uint8_t d = 0;
	uint8_t i = 0;
	while(d != 1){
		i = 0;
		level = HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin);
		while(i != BT_STAT_DEBOUNCE_SAMPLES){
			i++;
			if(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) != level){
				break;
			}
			if(i == BT_STAT_DEBOUNCE_SAMPLES){
				d = 1;
			}
		}
	}
	return level;
}
uint8_t Bluetooth_Connected(){
	if(HAL_GPIO_ReadPin(BT_STAT_GPIO_Port, BT_STAT_Pin) == GPIO_PIN_SET){
		return 1;
	}
	return 0;
}
void Bluetooth_SysTick(){
	if(bluetooth_rx.receiving){
		if(bluetooth_rx.receiving_ms < BLUETOOTH_RX_TIMEOUT_MS){
			bluetooth_rx.receiving_ms++;
		}else{
			Bluetooth_Listen();
		}
	}
}
void Bluetooth_Interrupt(){
	uint8_t tmp;
	switch(bluetooth_rx.cnt){
		case 0:
			if(bluetooth_rx.data[0] == bluetooth_rx.command_symbol){
				bluetooth_rx.cnt = 1;
				bluetooth_rx.receiving_ms = 0;
				bluetooth_rx.receiving = 1;
				HAL_UART_Receive_IT(&huart1, &bluetooth_rx.data[1], 1);
			}else{
				Bluetooth_Listen();
			}
		break;
		case 1:
			tmp = Bluetooth_Find_Rx_Length(bluetooth_rx.data[1]);
			if(tmp != bluetooth_rx.commands){
				bluetooth_rx.cnt = 2;
				if(bluetooth_rx.lengths[tmp] - bluetooth_rx.cnt){
					HAL_UART_Receive_DMA(&huart1, &bluetooth_rx.data[2], bluetooth_rx.lengths[tmp] - bluetooth_rx.cnt);
				}else{
					bluetooth_rx.receiving = 0;
					bluetooth_rx.ready = 1;
				}
			}else{
				Bluetooth_Listen();
			}
		break;
		case 2:
			bluetooth_rx.cnt = bluetooth_rx.lengths[Bluetooth_Find_Rx_Length(bluetooth_rx.data[1])];
			bluetooth_rx.receiving = 0;
			bluetooth_rx.ready = 1;
		break;
	}
}

void Bluetooth_Listen(){
	bluetooth_rx.ready = 0;
	bluetooth_rx.cnt = 0;
	bluetooth_rx.receiving = 0;
	bluetooth_rx.receiving_ms = 0;
	HAL_UART_Abort(&huart1);
	HAL_UART_Receive_IT(&huart1, &bluetooth_rx.data[0], 1);
}
void Bluetooth_Transmit(uint8_t *data, uint16_t length){
	if(Bluetooth_Connected()){
		HAL_UART_Transmit(&huart1, &data[0], length, BLUETOOTH_TX_TIMEOUT_MS);
	}
}
uint8_t *Bluetooth_Rx_Data(){
	return (uint8_t *)&bluetooth_rx.data[0];
}
uint8_t Bluetooth_Rx_Ready(){
	if(bluetooth_rx.ready){
		bluetooth_rx.ready = 0;
		return 1;
	}
	return 0;
}
void Bluetooth_Init(uint8_t command_symbol, uint8_t *symbols, uint8_t *lengths, uint16_t commands){
	bluetooth_rx.command_symbol = command_symbol;
	bluetooth_rx.commands = commands;
	bluetooth_rx.symbols = symbols;
	bluetooth_rx.lengths = lengths;
	Bluetooth_Listen();
}
