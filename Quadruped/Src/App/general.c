#include <stdio.h>
#include <stdlib.h>
#include "main.h"

static char general_tmp[3];

void General_Copy(uint8_t *from, uint8_t *to, uint16_t length){
	uint16_t i = 0;
	while(i != length){
		to[i] = from[i];
		i++;
	}
}
void General_Copy_Float(float *from, float *to, uint16_t length){
	uint16_t i = 0;
	while(i != length){
		to[i] = from[i];
		i++;
	}
}
void General_Array_To_Hex_String(uint8_t *arr, char *hexstr, uint16_t count){
	uint16_t i = 0;
	while(i != count){
		sprintf(&hexstr[i*2],"%02x",arr[i]);
		i++;
	}
}
void General_Hex_String_To_Array(uint8_t *in, uint8_t *out, uint16_t length){
	uint16_t i = 0;
	while(i != length){
		general_tmp[0] = in[i];
		general_tmp[1] = in[i+1];
		general_tmp[2] = 0;
		out[(uint16_t)(i/2)] = (uint8_t)strtol(general_tmp, NULL, 16);
		i+=2;
	}
}

