bool8 SetUpFieldMove_CutTool(void);

void ReturnToFieldFromFlyToolMapSelect(void);

u32 CanStartSurfing(s16, s16);
void CreateStartSurfingTask(void);

u32 CanPushBoulder(void);

void FldEff_UseFlashTool(void);
u32 CanUseFlashOnMap(void);
void CheckAndDoQoLFlash(void);

bool32 CanStartWaterfallTool(void);
void CreateClimbWaterfallTask(void);

bool8 FldEff_UseDiveWithoutMon(void);

bool8 FldEff_UseTeleportNoMon(void);

bool8 FldEff_SweetScentNoMon(void);

void ClearQoLFieldMovesFlags(void);
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
