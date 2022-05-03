void Bluetooth_UART_Listen();
void Bluetooth_UART_Timer_Stop();
void Bluetooth_UART_Timer_Start();
void Bluetooth_UART_Timer_Reset();
uint8_t Bluetooth_Is_Connected();
void Bluetooth_Receive(uint16_t count);
void Bluetooth_Transmit(uint8_t *data, uint16_t count);
void Bluetooth_Read_Message();