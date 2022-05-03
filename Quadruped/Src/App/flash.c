#include "main.h"
#include "flash.h"

static FLASH_EraseInitTypeDef EraseInitStruct;

void Flash_Read(uint8_t *data, uint16_t length){
	uint16_t fpages = length/4;
	uint16_t lbytes = length-(fpages*4);

	uint32_t tmp = 0;
	uint16_t i = 0;
	while(i!=(fpages*4)){
		tmp = *(__IO uint32_t *)(0x0800C000+i);
		data[i] = (uint8_t)((uint32_t)tmp>>24);
		data[i+1] = (uint8_t)((uint32_t)tmp>>16);
		data[i+2] = (uint8_t)((uint32_t)tmp>>8);
		data[i+3] = (uint8_t)tmp;
		i += 4;
	}
	if(lbytes != 0){
		tmp = *(__IO uint32_t *)(0x0800C000+i);
		if(lbytes == 3){
			data[i] = (uint8_t)((uint32_t)tmp>>24);
			data[i+1] = (uint8_t)((uint32_t)tmp>>16);
			data[i+2] = (uint8_t)((uint32_t)tmp>>8);
		}
		else if(lbytes == 2){
			data[i] = (uint8_t)((uint32_t)tmp>>24);
			data[i+1] = (uint8_t)((uint32_t)tmp>>16);
		}
		else if(lbytes == 1){
			data[i] = (uint8_t)((uint32_t)tmp>>24);
		}
	}
}
uint32_t Flash_Write(uint8_t *data, uint16_t length){
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = 0x0800C000;
	EraseInitStruct.NbPages = 1;
	uint32_t ErrorCode = 0;
	HAL_FLASH_Unlock();
	HAL_FLASHEx_Erase(&EraseInitStruct, &ErrorCode);

	//4is jeradis mere gadayris
	uint16_t fpages = length/4;
	uint16_t lbytes = length-(fpages*4);
	uint16_t i = 0;
	while(i != (fpages*4)){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, 0x0800C000+i, ((uint32_t)data[i]<<24)|((uint32_t)data[i+1]<<16)|((uint32_t)data[i+2]<<8)|(uint32_t)data[i+3]);
		i+=4;
	}
	if(lbytes != 0){
		uint32_t wdata = 0;
		if(lbytes == 3){
			wdata = ((uint32_t)data[i]<<24)|((uint32_t)data[i+1]<<16)|((uint32_t)data[i+2]<<8);
		}
		else if(lbytes == 2){
			wdata = ((uint32_t)data[i]<<24)|((uint32_t)data[i+1]<<16);
		}
		else if(lbytes == 1){
			wdata = ((uint32_t)data[i]<<24);
		}
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, 0x0800C000+i, wdata);
	}

	HAL_FLASH_Lock();
	return ErrorCode;
}

