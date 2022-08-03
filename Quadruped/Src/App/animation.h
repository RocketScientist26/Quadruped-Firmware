#include "anim_data.h"

#define ANIMATION_MAX_SUBSTEP ((float)SERVO_TOTAL_STEPS / 180.0f)

void Animation_SysTick();
void Animation_Stop();
void Animation_Set(anim_data_t *anim_data);
void Animation_Play_Frame();
void Animation_Play();
