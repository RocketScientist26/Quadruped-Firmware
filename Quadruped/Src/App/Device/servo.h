#define SERVO_COUNT 					8
#define SERVO_TOTAL_STEPS 				100

#define SERVO_CALIBRATION_STEP_PWM 		15
#define SERVO_MAX_PWM 					2600 - (SERVO_CALIBRATION_STEP_PWM * 9)
#define SERVO_MIN_PWM 					260 + (SERVO_CALIBRATION_STEP_PWM * 9)

#define SERVO_STEP_PWM 					((SERVO_MAX_PWM - SERVO_MIN_PWM) / (float)SERVO_TOTAL_STEPS)

int8_t *Servo_Calib_Data();
void Servo_Set_Calib(int8_t calib, uint8_t servo);
void Servo_Set(float *values);
void Servo_Init();