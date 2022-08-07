#include "anim_data.h"

void Animation_SysTick();
void Animation_Stop();
void Animation_Save_Current_Pose(float *to);
void Animation_Set_Kick(uint8_t direction, uint8_t strength);
void Animation_Kick();
void Animation_Set_Drive(uint8_t direction, uint8_t speed);
uint8_t Animation_Is_Playing();
void Animation_Set(anim_data_t *anim_data);
void Animation_Play_Frame();
void Animation_Play();
