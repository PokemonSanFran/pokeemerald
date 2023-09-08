u32 CanUseCut(s16, s16, u8);
bool8 SetUpFieldMove_UseCutTool(void);
u32 UseCut(u32);

void ReturnToFieldFromFlyToolMapSelect(void);

u32 CanUseSurf(s16, s16);
void CreateUseSurfTask(void);

u32 CanUseStrength(void);

void FldEff_UseFlashTool(void);
u32 CanUseFlash(void);
void CheckAndUseFlash(void);

bool32 CanUseWaterfallTool(void);
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
    FLY_SOURCE_FIELD,
    FLY_SOURCE_BAG
};
