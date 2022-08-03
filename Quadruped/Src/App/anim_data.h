#define ANIM_DATA_LOOP 1
#define ANIM_DATA_ONCE 0

#define ANIM_DATA_KICK_DIRECTION_MAX 180
#define ANIM_DATA_KICK_STRENGHT_MAX 100
#define ANIM_DATA_DRIVE_DIRECTION_MAX 180
#define ANIM_DATA_DRIVE_STRENGHT_MAX 100

///General patterns
//Standby pose
#define ANIM_DATA_ST_V 60
#define ANIM_DATA_ST_H 35
//Calibration pose
#define ANIM_DATA_CA_V 15
#define ANIM_DATA_CA_H 75

///Buttons animation patterns
//Forward/Backward
#define ANIM_DATA_FW_BW_1_V_UP 22
#define ANIM_DATA_FW_BW_1_V_DW 60
#define ANIM_DATA_FW_BW_1_H_FW 23
#define ANIM_DATA_FW_BW_1_H_BW 40

#define ANIM_DATA_FW_BW_2_V_UP 25
#define ANIM_DATA_FW_BW_2_V_DW 60
#define ANIM_DATA_FW_BW_2_H_FW 18
#define ANIM_DATA_FW_BW_2_H_BW 45

#define ANIM_DATA_FW_BW_3_V_UP 28
#define ANIM_DATA_FW_BW_3_V_DW 60
#define ANIM_DATA_FW_BW_3_H_FW 3
#define ANIM_DATA_FW_BW_3_H_BW 60

//Turn Left, Turn Right
#define ANIM_DATA_TR_TL_1_V_UP 40
#define ANIM_DATA_TR_TL_1_V_DW 60
#define ANIM_DATA_TR_TL_1_H_FW 45
#define ANIM_DATA_TR_TL_1_H_BW 35

#define ANIM_DATA_TR_TL_2_V_UP 35
#define ANIM_DATA_TR_TL_2_V_DW 60
#define ANIM_DATA_TR_TL_2_H_FW 45
#define ANIM_DATA_TR_TL_2_H_BW 25

#define ANIM_DATA_TR_TL_3_V_UP 35
#define ANIM_DATA_TR_TL_3_V_DW 60
#define ANIM_DATA_TR_TL_3_H_FW 47
#define ANIM_DATA_TR_TL_3_H_BW 18

//Slide Left, Slide Right
#define ANIM_DATA_SR_SL_1_V_UP 28
#define ANIM_DATA_SR_SL_1_V_DW 60
#define ANIM_DATA_SR_SL_1_H_FW 55
#define ANIM_DATA_SR_SL_1_H_BW 65

#define ANIM_DATA_SR_SL_2_V_UP 25
#define ANIM_DATA_SR_SL_2_V_DW 60
#define ANIM_DATA_SR_SL_2_H_FW 50
#define ANIM_DATA_SR_SL_2_H_BW 70

#define ANIM_DATA_SR_SL_3_V_UP 22
#define ANIM_DATA_SR_SL_3_V_DW 60
#define ANIM_DATA_SR_SL_3_H_FW 40
#define ANIM_DATA_SR_SL_3_H_BW 80

typedef struct{
	uint32_t poses;
	uint8_t loop;
	uint32_t delay;
	float data[];
}anim_data_t;

extern const float anim_data_calib[];
extern const float anim_data_standby[];
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
extern const anim_data_t anim_data_swim;
extern const anim_data_t anim_data_workout;
extern const anim_data_t anim_data_hello;
extern const float anim_data_kick[];
