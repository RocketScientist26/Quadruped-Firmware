#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "general.h"

void General_Copy_Float(float *from, float *to, uint16_t length){
	memcpy(to, from, length * 4);
}
void General_Array_To_Hex_String(uint8_t *arr, char *hexstr, uint16_t count){
	uint16_t i = 0;
	while(i != count){
		sprintf(&hexstr[i*2], "%02x", arr[i]);
		i++;
	}
}
void General_Hex_String_To_Array(uint8_t *in, uint8_t *out, uint16_t length){
	uint16_t i = 0;
	uint32_t tmp = 0;
	while(i != length){
		*(uint8_t *)&tmp = in[i];
		*(uint8_t *)(&tmp + 1) = in[i+1];
		*(uint8_t *)(&tmp + 2) = 0;
		out[(uint16_t)(i / 2)] = (uint8_t)strtol((char *)&tmp, NULL, 16);
		i += 2;
	}
}

