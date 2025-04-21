#ifndef GUARD_BATTLE_ARCADE_H
#define GUARD_BATTLE_ARCADE_H

void CallBattleArcadeFunc(void);
void ConvertFacilityFromArcadeToPike(u32*);
u32 GetArcadePrintCount();
void Arcade_ShowResultsWindow();

struct GameResult
{
    u8 impact:2;
    u8 event:5;
};

#define FRONTIER_SAVEDATA                       gSaveBlock2Ptr->frontier
#define ARCADE_SAVEDATA_CURRENT_STREAK          FRONTIER_SAVEDATA.arcadeWinStreaks
#define ARCADE_SAVEDATA_RECORD_STREAK           FRONTIER_SAVEDATA.arcadeRecordWinStreaks
#define ARCADE_SAVEDATA_CURSOR                  FRONTIER_SAVEDATA.gameCursor

#define VAR_ARCADE_BERRY                        VAR_UNUSED_0x40FA
#define VAR_ARCADE_ITEM                         VAR_UNUSED_0x409D
#define VAR_ARCADE_PERFORMANCE_POINTS           VAR_UNUSED_0x404E

#define IMPACT_PERFORMANCE_TABLE_SIZE           5
#define ARCADE_BRAIN_DEFEAT_POINTS              20

#endif //GUARD_BATTLE_ARCADE_H
