#define BUTTON_DEBOUNCE_SAMPLES 10

void Button_Interrupt();
uint8_t Button_Debounce_Read();
uint8_t Button_Pressed();