#define SERVO_NOINT 	1
#define SERVO_INT 		0

#define SERVO_KICK_NO_KICK 0
#define SERVO_KICK_SET_KICK 1


void Servo_Set(float *values);
void Servo_Init();
void Servo_Move(float *state_from_values, float *state_to_values, uint16_t total_steps, uint8_t delay, uint8_t no_int);
void Servo_Play_Pattern(float *values, uint16_t poses, uint16_t total_steps, uint8_t delay, uint8_t no_int);
void Servo_Play_Trick_Pattern(float *start_values, float *trick_values, uint16_t poses, uint16_t total_steps, uint8_t delay, uint8_t no_int);
void Servo_Set_Kick(uint8_t direction, uint8_t strength, uint8_t kick);
void Servo_Drive(uint16_t direction, uint16_t speed);
