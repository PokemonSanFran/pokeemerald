#ifndef GUARD_VS_SEEKER_H
#define GUARD_VS_SEEKER_H

#include "global.h"

void Task_VsSeeker_0(u8 taskId);
bool8 UpdateVsSeekerStepCounter(void);
void MapResetTrainerRematches(u16 mapGroup, u16 mapNum);
void ClearRematchMovementByTrainerId(void);
u16 VsSeekerConvertLocalIdToTableId(u16 localId);

#endif //GUARD_VS_SEEKER_H
