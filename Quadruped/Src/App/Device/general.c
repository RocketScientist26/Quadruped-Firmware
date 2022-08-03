#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

void General_Copy_Float(float *from, float *to, uint16_t length){
	memcpy(to, from, length * 4);
}
void General_Array_To_Hex_String(uint8_t *arr, uint8_t *hexstr, uint16_t count){
	uint16_t i = 0;
	while(i != count){
		sprintf((char *)&hexstr[i*2], "%02x", arr[i]);
		i++;
	}
}
void General_Hex_String_To_Array(uint8_t *hexstr, uint8_t *arr, uint16_t length){
	uint16_t i = 0;
	uint32_t tmp = 0;
	while(i != length){
		*(uint8_t *)&tmp = hexstr[i];
		*(uint8_t *)(&tmp + 1) = hexstr[i+1];
		*(uint8_t *)(&tmp + 2) = 0;
		arr[(uint16_t)(i / 2)] = (uint8_t)strtol((char *)&tmp, NULL, 16);
		i += 2;
	}
}

