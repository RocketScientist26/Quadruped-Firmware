#define BT_STAT_DEBOUNCE_SAMPLES 	10

#define BLUETOOTH_TX_TIMEOUT_MS 	100
#define BLUETOOTH_RX_TIMEOUT_MS 	100
#define BLUETOOTH_MAX_RX_SIZE 		256

uint8_t Bluetooth_Find_Rx_Length(uint8_t rx_symbol);
uint8_t Bluetooth_Connected_Debounce();
uint8_t Bluetooth_Connected();

void Bluetooth_SysTick();
void Bluetooth_Interrupt();

void Bluetooth_Transmit(uint8_t *data, uint16_t length);
uint8_t Bluetooth_Rx_Ready();
uint8_t *Bluetooth_Rx_Data();
void Bluetooth_Listen();
void Bluetooth_Init(uint8_t command_symbol, uint8_t *symbols, uint8_t *lengths, uint16_t commands);
