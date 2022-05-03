#define LED_NOT_IN_SETTINGS 	1
#define LED_IN_SETTINGS 		0

void Led_Init();
void Led_On();
void Led_Off();
void Led_Breath(uint8_t is_moving, uint8_t no_settings);