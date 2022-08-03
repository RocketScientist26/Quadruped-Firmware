#include "main.h"
#include "anim_data.h"

//Standby
const float anim_data_standby[] = {
	ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V
};
//Calibration
const float anim_data_calib[] = {
	ANIM_DATA_CA_V, ANIM_DATA_CA_H, ANIM_DATA_CA_H, ANIM_DATA_CA_V, ANIM_DATA_CA_V, ANIM_DATA_CA_H, ANIM_DATA_CA_H, ANIM_DATA_CA_V
};

//Forward (Third array also applies to Drive Mode)
const anim_data_t anim_data_forward_1 = {
	.data = {
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};

const anim_data_t anim_data_forward_2 = {
	.data = {
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_forward_3 = {
	.data = {
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
//Backward
const anim_data_t anim_data_backward_1 = {
	.data = {
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_UP,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_backward_2 = {
	.data = {
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_UP,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_backward_3 = {
	.data = {
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_UP,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
//Turn Left
const anim_data_t anim_data_turn_left_1 = {
	.data = {
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_turn_left_2 = {
	.data = {
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_turn_left_3 = {
	.data = {
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
//Turn Right
const anim_data_t anim_data_turn_right_1 = {
	.data = {
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_UP,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_turn_right_2 = {
	.data = {
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_UP,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_turn_right_3 = {
	.data = {
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_UP,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
//Slide Left
const anim_data_t anim_data_slide_left_1 = {
	.data = {
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_UP,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_slide_left_2 = {
	.data = {
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_UP,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_slide_left_3 = {
	.data = {
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_UP,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
//Slide Right
const anim_data_t anim_data_slide_right_1 = {
	.data = {
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_slide_right_2 = {
	.data = {
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};
const anim_data_t anim_data_slide_right_3 = {
	.data = {
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_UP,
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.delay = 3
};

//Swim
const anim_data_t anim_data_swim = {
	.data = {
	90, 73, 70, 90, 90, 87, 150, 60,
	90, 80, 70, 60, 90, 80, 150, 60,
	90, 0, 70, 60, 60, 80, 150, 60,
	90, 0, 70, 60, 90, 80, 150, 60,
	20, 0, 0, 150, 0, 150, 150, 130,

	0, 0, 20, 135, 15, 90, 150, 135,
	15, 0, 40, 150, 15, 110, 150, 150,
	0, 0, 60, 150, 15, 130, 150, 135,
	15, 0, 80, 150, 15, 150, 150, 150,
	0, 0, 60, 150, 0, 130, 150, 135,
	15, 0, 40, 135, 0, 110, 150, 150,
	0, 0, 20, 135, 0, 90, 150, 135,
	15, 0, 0, 135, 0, 70, 150, 150
	}
};
//Workout
const anim_data_t anim_data_workout = {
	.data = {
	90, 73, 70, 90, 90, 87, 150, 60,
	90, 80, 70, 60, 90, 80, 150, 60,
	90, 0, 70, 60, 60, 80, 150, 60,
	90, 0, 70, 60, 90, 80, 150, 60,
	20, 0, 40, 60, 90, 110, 150, 130,

	20, 0, 40, 60, 90, 110, 150, 130,//Down
	20, 0, 40, 120, 30, 110, 150, 130//Up
	}
};
//Hello
const anim_data_t anim_data_hello = {
	.data = {
	90, 73, 70, 90, 90, 87, 150, 60,
	90, 80, 70, 60, 90, 80, 150, 60,
	90, 0, 70, 60, 60, 80, 150, 60,
	90, 0, 70, 60, 90, 80, 150, 60,
	20, 0, 0, 150, 0, 150, 150, 130,

	0, 0, 20, 135, 15, 90, 150, 135,
	15, 0, 40, 150, 15, 110, 150, 150,
	0, 0, 60, 150, 15, 130, 150, 135,
	15, 0, 80, 150, 15, 150, 150, 150,
	0, 0, 60, 150, 0, 130, 150, 135,
	15, 0, 40, 135, 0, 110, 150, 150,
	0, 0, 20, 135, 0, 90, 150, 135,
	15, 0, 0, 135, 0, 70, 150, 150
	}
};

//Kick
const float anim_data_kick[] = {
	40, 50, 40, 60, 60, 50, 30, 60
};
