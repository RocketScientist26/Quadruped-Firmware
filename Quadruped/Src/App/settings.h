uint8_t Settings_Verify();
void Settings_Write();
void Settings_Reset();
void Settings_Read(int8_t *calib, uint8_t *led);
uint8_t *Settings_Data();
void Settings_Set_Calib(int8_t *calib);
void Settings_Write_LED(uint8_t led);
void Settings_Write_Bluetooth(uint8_t *bt_password, uint8_t *bt_name);
void Settings_Init();