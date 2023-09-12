u32 CanUseCut(s16, s16);
u32 UseCut(u32);

void ReturnToFieldFromFlyToolMapSelect(void);
bool32 IsFlyToolUsed(void);
bool32 ReturnToFieldOrBagFromFlyTool(void);
void ResetFlyTool(void);

u32 CanUseSurf(s16, s16, u8);
u32 CanUseSurfFromInteractedWater(void);
u32 UseSurf(u32);
void RemoveRelevantSurfFieldEffect(void);
void Task_SurfToolFieldEffect(u8 taskId);

u32 CanUseStrength(u8);
u32 UseStrength(u32);

void FldEff_UseFlashTool(void);
u32 CanUseFlash(void);
void TryUseFlash(void);

u32 CanUseRockSmash(s16 x, s16 y);
u32 UseRockSmash(u32 fieldMoveStatus);

u32 CanUseWaterfall(u8);
bool32 CanUseWaterfallTool(void);
u32 UseWaterfall(struct PlayerAvatar, u32);
void CreateUseWaterfallTask(void);

bool8 FldEff_UseDiveTool(void);

bool8 FldEff_UseTeleportTool(void);

bool8 FldEff_SweetScentTool(void);

void ClearFieldMoveFlags(void);
bool32 PartyHasMonLearnsKnowsFieldMove(u16);

enum FieldMoveActionSource
{
    FIELD_MOVE_FAIL,
    FIELD_MOVE_POKEMON,
    FIELD_MOVE_TOOL
};

enum FlyToolSource
{
    FLY_SOURCE_MOVE,
    FLY_SOURCE_FIELD,
    FLY_SOURCE_BAG
};
