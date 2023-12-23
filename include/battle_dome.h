#ifndef GUARD_BATTLE_DOME_H
#define GUARD_BATTLE_DOME_H

extern u32 gPlayerPartyLostHP;

int GetDomeTrainerSelectedMons(u16 tournamentTrainerId);
int TrainerIdToDomeTournamentId(u16 trainerId);
void CopyDomeTrainerName(u8 *, u16);

#endif // GUARD_BATTLE_DOME_H
