#define LED_MIN_BRIGHTNESS 			2
#define LED_MAX_SPEED 				2
#define LED_NORMAL_SPEED 			21
#define LED_SPEED_UP_INTERVAL_MS 	4000
#define LED_COOL_DOWN_INTERVAL_MS 	2000

enum{
	LED_CONSTANT,
	LED_ACCELERATE,
	LED_COOL_DOWN
};

void LED_Breath();
void LED_Set_Mode(uint8_t mode);
void LED_Enable(uint8_t enable);
void LED_Init();
