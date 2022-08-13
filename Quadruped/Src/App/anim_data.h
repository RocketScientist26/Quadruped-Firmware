#define ANIM_DATA_LOOP 1
#define ANIM_DATA_ONCE 0

#define ANIM_DATA_KICK_DELAY_MS 300
#define ANIM_DATA_KICK_DIRECTION_MAX 90
#define ANIM_DATA_KICK_STRENGTH_MAX 80
#define ANIM_DATA_KICK_DIRECTION_SERVO_MIN (float)25
#define ANIM_DATA_KICK_DIRECTION_SERVO_MAX (float)80
#define ANIM_DATA_KICK_STRENGTH_SERVO_MIN (float)20
#define ANIM_DATA_KICK_STRENGTH_SERVO_MAX (float)94

#define ANIM_DATA_DRIVE_DIRECTION_MAX 180
#define ANIM_DATA_DRIVE_SPEED_MAX 80
#define ANIM_DATA_DRIVE_SUBSTEP_MAX 0.5f
#define ANIM_DATA_DRIVE_SUBSTEP_MIN 0.2f

///General patterns
#define ANIM_DATA_VT 40
//Standby pose
#define ANIM_DATA_ST_V 75
#define ANIM_DATA_ST_H 40
//Calibration pose
#define ANIM_DATA_CA_V 40
#define ANIM_DATA_CA_H 75

///Buttons animation patterns
//Forward/Backward
#define ANIM_DATA_FW_BW_1_V_UP 50
#define ANIM_DATA_FW_BW_1_V_DW 75
#define ANIM_DATA_FW_BW_1_H_FW 33
#define ANIM_DATA_FW_BW_1_H_BW 50

#define ANIM_DATA_FW_BW_2_V_UP 50
#define ANIM_DATA_FW_BW_2_V_DW 80
#define ANIM_DATA_FW_BW_2_H_FW 25
#define ANIM_DATA_FW_BW_2_H_BW 55

#define ANIM_DATA_FW_BW_3_V_UP 45
#define ANIM_DATA_FW_BW_3_V_DW 80
#define ANIM_DATA_FW_BW_3_H_FW 18
#define ANIM_DATA_FW_BW_3_H_BW 55

//Turn Left, Turn Right
#define ANIM_DATA_TR_TL_1_V_UP 55
#define ANIM_DATA_TR_TL_1_V_DW 75
#define ANIM_DATA_TR_TL_1_H_FW 45
#define ANIM_DATA_TR_TL_1_H_BW 35

#define ANIM_DATA_TR_TL_2_V_UP 50
#define ANIM_DATA_TR_TL_2_V_DW 80
#define ANIM_DATA_TR_TL_2_H_FW 55
#define ANIM_DATA_TR_TL_2_H_BW 38

#define ANIM_DATA_TR_TL_3_V_UP 45
#define ANIM_DATA_TR_TL_3_V_DW 80
#define ANIM_DATA_TR_TL_3_H_FW 60
#define ANIM_DATA_TR_TL_3_H_BW 38

//Slide Left, Slide Right
#define ANIM_DATA_SR_SL_1_V_UP 55
#define ANIM_DATA_SR_SL_1_V_DW 75
#define ANIM_DATA_SR_SL_1_H_FW 55
#define ANIM_DATA_SR_SL_1_H_BW 65

#define ANIM_DATA_SR_SL_2_V_UP 50
#define ANIM_DATA_SR_SL_2_V_DW 80
#define ANIM_DATA_SR_SL_2_H_FW 50
#define ANIM_DATA_SR_SL_2_H_BW 70

#define ANIM_DATA_SR_SL_3_V_UP 45
#define ANIM_DATA_SR_SL_3_V_DW 80
#define ANIM_DATA_SR_SL_3_H_FW 35
#define ANIM_DATA_SR_SL_3_H_BW 80

typedef struct{
	uint32_t poses;
	uint8_t loop;
	uint32_t frame_delay;
	float max_substep;
	float data[];
}anim_data_t;

extern const float anim_data_calib[];
extern const float anim_data_standby[];
extern volatile anim_data_t anim_data_kick;
extern const anim_data_t anim_data_forward_1;
extern const anim_data_t anim_data_forward_2;
extern const anim_data_t anim_data_forward_3;
extern const anim_data_t anim_data_backward_1;
extern const anim_data_t anim_data_backward_2;
extern const anim_data_t anim_data_backward_3;
extern const anim_data_t anim_data_turn_left_1;
extern const anim_data_t anim_data_turn_left_2;
extern const anim_data_t anim_data_turn_left_3;
extern const anim_data_t anim_data_turn_right_1;
extern const anim_data_t anim_data_turn_right_2;
extern const anim_data_t anim_data_turn_right_3;
extern const anim_data_t anim_data_slide_left_1;
extern const anim_data_t anim_data_slide_left_2;
extern const anim_data_t anim_data_slide_left_3;
extern const anim_data_t anim_data_slide_right_1;
extern const anim_data_t anim_data_slide_right_2;
extern const anim_data_t anim_data_slide_right_3;
extern const anim_data_t anim_data_swim_s;
extern const anim_data_t anim_data_swim_l;
extern volatile anim_data_t anim_data_swim_e;
extern const anim_data_t anim_data_workout_s;
extern const anim_data_t anim_data_workout_l;
extern volatile anim_data_t anim_data_workout_e;
extern const anim_data_t anim_data_hello_s;
extern const anim_data_t anim_data_hello_l;
extern volatile anim_data_t anim_data_hello_e;
extern volatile anim_data_t anim_data_drive;
