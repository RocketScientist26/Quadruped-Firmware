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
//Kick
volatile anim_data_t anim_data_kick = {
	.data = {
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V,
		55, 50, 45, ANIM_DATA_ST_V, ANIM_DATA_VT, ANIM_DATA_VT, 35, ANIM_DATA_ST_V
	},
	.poses = 2,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.8,
	.frame_delay = 1
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
	.max_substep = 0.3,
	.frame_delay = 2
};
const anim_data_t anim_data_forward_2 = {
	.data = {
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.35,
	.frame_delay = 2
};
const anim_data_t anim_data_forward_3 = {
	.data = {
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.5,
	.frame_delay = 2
};
//Backward
const anim_data_t anim_data_backward_1 = {
	.data = {
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_UP,
		ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW,
		ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_H_BW, ANIM_DATA_FW_BW_1_V_DW, ANIM_DATA_FW_BW_1_V_UP, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_H_FW, ANIM_DATA_FW_BW_1_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.3,
	.frame_delay = 2
};
const anim_data_t anim_data_backward_2 = {
	.data = {
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_UP,
		ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW,
		ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_H_BW, ANIM_DATA_FW_BW_2_V_DW, ANIM_DATA_FW_BW_2_V_UP, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_H_FW, ANIM_DATA_FW_BW_2_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.35,
	.frame_delay = 2
};
const anim_data_t anim_data_backward_3 = {
	.data = {
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_UP,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_H_BW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_H_FW, ANIM_DATA_FW_BW_3_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.5,
	.frame_delay = 2
};
//Turn Left
const anim_data_t anim_data_turn_left_1 = {
	.data = {
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.25,
	.frame_delay = 2
};
const anim_data_t anim_data_turn_left_2 = {
	.data = {
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.35,
	.frame_delay = 2
};
const anim_data_t anim_data_turn_left_3 = {
	.data = {
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.5,
	.frame_delay = 2
};
//Turn Right
const anim_data_t anim_data_turn_right_1 = {
	.data = {
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_UP,
		ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_H_BW, ANIM_DATA_TR_TL_1_V_DW,
		ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW, ANIM_DATA_TR_TL_1_V_UP, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_H_FW, ANIM_DATA_TR_TL_1_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.25,
	.frame_delay = 2
};
const anim_data_t anim_data_turn_right_2 = {
	.data = {
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_UP,
		ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_H_BW, ANIM_DATA_TR_TL_2_V_DW,
		ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW, ANIM_DATA_TR_TL_2_V_UP, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_H_FW, ANIM_DATA_TR_TL_2_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.35,
	.frame_delay = 2
};
const anim_data_t anim_data_turn_right_3 = {
	.data = {
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_UP,
		ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_H_BW, ANIM_DATA_TR_TL_3_V_DW,
		ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW, ANIM_DATA_TR_TL_3_V_UP, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_H_FW, ANIM_DATA_TR_TL_3_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.5,
	.frame_delay = 2
};
//Slide Left
const anim_data_t anim_data_slide_left_1 = {
	.data = {
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_UP,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.3,
	.frame_delay = 2
};
const anim_data_t anim_data_slide_left_2 = {
	.data = {
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_UP,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.4,
	.frame_delay = 2
};
const anim_data_t anim_data_slide_left_3 = {
	.data = {
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_UP,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.45,
	.frame_delay = 2
};
//Slide Right
const anim_data_t anim_data_slide_right_1 = {
	.data = {
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_DW,
		ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_V_UP, ANIM_DATA_SR_SL_1_V_DW, ANIM_DATA_SR_SL_1_H_FW, ANIM_DATA_SR_SL_1_H_BW, ANIM_DATA_SR_SL_1_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.3,
	.frame_delay = 2
};
const anim_data_t anim_data_slide_right_2 = {
	.data = {
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_DW,
		ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_V_UP, ANIM_DATA_SR_SL_2_V_DW, ANIM_DATA_SR_SL_2_H_FW, ANIM_DATA_SR_SL_2_H_BW, ANIM_DATA_SR_SL_2_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.4,
	.frame_delay = 2
};
const anim_data_t anim_data_slide_right_3 = {
	.data = {
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_DW,
		ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_V_UP, ANIM_DATA_SR_SL_3_V_DW, ANIM_DATA_SR_SL_3_H_FW, ANIM_DATA_SR_SL_3_H_BW, ANIM_DATA_SR_SL_3_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.45,
	.frame_delay = 2
};

//Swim
const anim_data_t anim_data_swim_s = {
	.data = {
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, 60, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, 60, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		60, ANIM_DATA_CA_H, 30, ANIM_DATA_ST_V, ANIM_DATA_ST_V, 30, ANIM_DATA_CA_H, 60,
		ANIM_DATA_CA_V, ANIM_DATA_CA_H, 30, ANIM_DATA_CA_V, ANIM_DATA_CA_V, 30, ANIM_DATA_CA_H, ANIM_DATA_CA_V,
		25, ANIM_DATA_CA_H, 15, 45, 25, 45, ANIM_DATA_CA_H, 45
	},
	.poses = 8,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.25,
	.frame_delay = 2
};
const anim_data_t anim_data_swim_l = {
	.data = {
		25, ANIM_DATA_CA_H, 15, 45, 25, 45, ANIM_DATA_CA_H, 45,
		45, ANIM_DATA_CA_H, 15, 45, 25, 45, ANIM_DATA_CA_H, 25,
		25, ANIM_DATA_CA_H, 45, 25, 45, 15, ANIM_DATA_CA_H, 45,
		45, ANIM_DATA_CA_H, 45, 25, 45, 15, ANIM_DATA_CA_H, 25,
		25, ANIM_DATA_CA_H, 45, 25, 45, 15, ANIM_DATA_CA_H, 45,
		45, ANIM_DATA_CA_H, 15, 45, 25, 45, ANIM_DATA_CA_H, 25,
		25, ANIM_DATA_CA_H, 15, 45, 25, 45, ANIM_DATA_CA_H, 45
	},
	.poses = 7,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.3,
	.frame_delay = 2
};
volatile anim_data_t anim_data_swim_e = {
	.data = {
		ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT,
		ANIM_DATA_CA_V, ANIM_DATA_CA_H, 30, ANIM_DATA_CA_V, ANIM_DATA_CA_V, 30, ANIM_DATA_CA_H, ANIM_DATA_CA_V,
		60, ANIM_DATA_CA_H, 30, ANIM_DATA_ST_V, ANIM_DATA_ST_V, 30, ANIM_DATA_CA_H, 60,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, 60, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, 60, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V
	},
	.poses = 8,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.3,
	.frame_delay = 2
};
//Workout
const anim_data_t anim_data_workout_s = {
	.data = {
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, 60, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, 60, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		60, ANIM_DATA_CA_H, 30, ANIM_DATA_ST_V, ANIM_DATA_ST_V, 30, ANIM_DATA_CA_H, 60
	},
	.poses = 6,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.25,
	.frame_delay = 2
};
const anim_data_t anim_data_workout_l = {
	.data = {
		60, ANIM_DATA_CA_H, 30, ANIM_DATA_ST_V, ANIM_DATA_ST_V, 30, ANIM_DATA_CA_H, 60,
		60, ANIM_DATA_CA_H, 30, 60, 60, 30, ANIM_DATA_CA_H, 60
	},
	.poses = 2,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.1,
	.frame_delay = 2
};
volatile anim_data_t anim_data_workout_e = {
	.data = {
		ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT,
		60, ANIM_DATA_CA_H, 30, ANIM_DATA_ST_V, ANIM_DATA_ST_V, 30, ANIM_DATA_CA_H, 60,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_CA_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, 60, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, 60, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_CA_H, ANIM_DATA_ST_V,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V
	},
	.poses = 7,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.3,
	.frame_delay = 2
};
//Hello
const anim_data_t anim_data_hello_s = {
	.data = {
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V,
		55, 50, 45, ANIM_DATA_ST_V, 10, 70, 35, ANIM_DATA_ST_V
	},
	.poses = 2,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.35,
	.frame_delay = 2
};
const anim_data_t anim_data_hello_l = {
	.data = {
		55, 50, 45, ANIM_DATA_ST_V, 10, 70, 35, ANIM_DATA_ST_V,
		55, 50, 45, ANIM_DATA_ST_V, 10, 50, 35, ANIM_DATA_ST_V
	},
	.poses = 2,
	.loop = ANIM_DATA_LOOP,
	.max_substep = 0.1,
	.frame_delay = 2
};
volatile anim_data_t anim_data_hello_e = {
	.data = {
		ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_VT,
		ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V, ANIM_DATA_ST_V, ANIM_DATA_ST_H, ANIM_DATA_ST_H, ANIM_DATA_ST_V,
	},
	.poses = 2,
	.loop = ANIM_DATA_ONCE,
	.max_substep = 0.3,
	.frame_delay = 2
};

//Drive
volatile anim_data_t anim_data_drive = {
	.data = {
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_DW,
		ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_UP, ANIM_DATA_FW_BW_3_V_DW, ANIM_DATA_VT, ANIM_DATA_VT, ANIM_DATA_FW_BW_3_V_UP
	},
	.poses = 4,
	.loop = ANIM_DATA_LOOP,
	.max_substep = ANIM_DATA_DRIVE_SUBSTEP_MAX,
	.frame_delay = 2
};