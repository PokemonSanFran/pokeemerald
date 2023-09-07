#include "global.h"
#include "palette.h"
#include "field_control_avatar.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "fldeff_misc.h"
#include "item.h"
#include "field_control_avatar.h"
#include "map_name_popup.h"
#include "field_player_avatar.h"
#include "constants/items.h"
#include "fldeff.h"
#include "overworld.h"
#include "region_map.h"
#include "item_use.h"
#include "field_player_avatar.h"
#include "item.h"
#include "constants/items.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "party_menu.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "event_data.h"
#include "qol_field_moves.h"
#include "constants/songs.h"
#include "sound.h"
#include "script.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "field_weather.h"
#include "constants/field_effects.h"
#include "metatile_behavior.h"
#include "fieldmap.h"

static u8 CreateFieldMoveNoMonTask(void);
static void Task_DoFieldMoveNoMon_Init(u8);

static u32 CanStartCuttingTree(s16, s16, u8);
static void FieldCallback_CutTreeWithTool(void);

static void FieldCallback_UseFlyTool(void);
static void Task_UseFlyTool(void);
static void FieldCallback_FlyToolIntoMap(void);

static void Task_StartSurfingInit(u8);
static void Task_WaitStartSurfing(u8);

static bool8 SetUpFieldMove_QoLFlash(void);
static void FieldCallback_UseQoLFlash(void);
static void SetUpFieldMove_FlashMon(void);
static void FieldCallback_FlashMon(void);

static bool8 CanStartSmashingRock(s16, s16, u8);

static void Task_UseWaterfallWithoutMon(u8);
static u32 CanStartClimbingWaterfall(u8);
static bool8 WaterfallWithoutMonFieldEffect_Init(struct Task *, struct ObjectEvent *);
static bool8 WaterfallWithoutMonFieldEffect_RideUp(struct Task *, struct ObjectEvent *);
static bool8 WaterfallWithoutMonFieldEffect_ContinueRideOrEnd(struct Task *, struct ObjectEvent *);
static bool8 IsPlayerFacingWaterfall(void);

static void Task_UseDiveWithoutMon(u8);
static bool8 DiveWithoutMonFieldEffect_Init(struct Task *task);
static bool8 DiveWithoutMonFieldEffect_TryWarp(struct Task *task);

static bool32 PartyCanLearnMoveLevelUp(u16, u16);

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]

static u8 CreateFieldMoveNoMonTask(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    return CreateTask(Task_DoFieldMoveNoMon_Init, 8);
}

static void Task_DoFieldMoveNoMon_Init(u8 taskId)
{
    u8 objEventId;

    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    objEventId = gPlayerAvatar.objectEventId;

        gFieldEffectArguments[1] = GetPlayerFacingDirection();
        if (gFieldEffectArguments[1] == DIR_SOUTH)
            gFieldEffectArguments[2] = 0;
        if (gFieldEffectArguments[1] == DIR_NORTH)
            gFieldEffectArguments[2] = 1;
        if (gFieldEffectArguments[1] == DIR_WEST)
            gFieldEffectArguments[2] = 2;
        if (gFieldEffectArguments[1] == DIR_EAST)
            gFieldEffectArguments[2] = 3;
        ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByCurrentState());
        StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], gFieldEffectArguments[2]);

    gTasks[taskId].func = Task_DoFieldMove_RunFunc;
}

// Cut
bool8 SetUpFieldMove_CutTool(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE) == TRUE)
    {
        // Standing in front of cuttable tree.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_CutTreeWithTool;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_CutTreeWithTool(void)
{
    ScriptContext_SetupScript(EventScript_UseCutTool);
}


static u32 CanStartCuttingTree(s16 x, s16 y, u8 direction)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM01);
    bool32 bagHasItem = CheckBagHasItem(ITEM_CUT_TOOL,1);

    if (
            CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE)
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && (monHasMove || bagHasItem)
            && FlagGet(FLAG_BADGE01_GET)
       )

    {
        return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }

    return FIELD_MOVE_FAIL;
}

// Fly
void ReturnToFieldFromFlyToolMapSelect(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = Task_UseFlyTool;
}

static void FieldCallback_UseFlyTool(void)
{
    LockPlayerFieldControls();
    FreezeObjectEvents();
    gFieldCallback = NULL;
}

static void Task_UseFlyTool(void)
{
    Overworld_ResetStateAfterFly();
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    gFieldCallback = FieldCallback_FlyToolIntoMap;
}

static void FieldCallback_FlyToolIntoMap(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    if (gPaletteFade.active)
            return;

    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
    gFieldCallback = NULL;
}

u32 CanStartSurfing(s16 x, s16 y)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM02);
    bool32 bagHasItem = CheckBagHasItem(ITEM_SURF_TOOL,1);

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING)){
        if (
            IsPlayerFacingSurfableFishableWater()
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && (monHasMove || bagHasItem)
            && FlagGet(FLAG_BADGE05_GET)
           )
            return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }
    return FIELD_MOVE_FAIL;
}

void CreateStartSurfingTask(void)
{
    u8 taskId;

    ScriptContext_Enable();
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicTo(MUS_SURF);
    gPlayerAvatar.flags ^= PLAYER_AVATAR_FLAG_ON_FOOT;
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_SURFING;
    gPlayerAvatar.preventStep = TRUE;
    taskId = CreateTask(Task_StartSurfingInit,0);
    gTasks[taskId].data[0] = GetPlayerFacingDirection();
    Task_StartSurfingInit(taskId);
}

static void Task_StartSurfingInit(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventIsMovementOverridden(playerObjEvent))
    {
        if (!ObjectEventClearHeldMovementIfFinished(playerObjEvent))
            return;
    }
    SetPlayerAvatarStateMask(8);
    ObjectEventSetGraphicsId(playerObjEvent, GetPlayerAvatarGraphicsIdByStateId(3));
    ObjectEventClearHeldMovementIfFinished(playerObjEvent);
    ObjectEventSetHeldMovement(playerObjEvent, GetJumpSpecialMovementAction((u8)gTasks[taskId].data[0]));
    gTasks[taskId].func = Task_WaitStartSurfing;
}

static void Task_WaitStartSurfing(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        ObjectEventSetHeldMovement(playerObjEvent, GetFaceDirectionMovementAction(playerObjEvent->facingDirection));
        PlayerAvatarTransition_Surfing(playerObjEvent);
        gPlayerAvatar.preventStep = FALSE;
        ScriptContext_Stop();
        DestroyTask(taskId);
    }
}

// Strength

u32 CanPushBoulder(void)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM04);
    bool32 bagHasItem = CheckBagHasItem(ITEM_STRENGTH_TOOL,1);

    if (
        CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER)
        && (monHasMove || bagHasItem)
        && FlagGet(FLAG_BADGE04_GET)
       )
    {
        return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }
    return FIELD_MOVE_FAIL;
}


// Flash

bool8 SetUpFieldMove_QoLFlash(void)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_UseQoLFlash;
}

void FieldCallback_UseQoLFlash(void)
{
    u8 taskId = CreateFieldMoveNoMonTask();
    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlashTool >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlashTool;
}

void FldEff_UseFlashTool(void)
{
    HideMapNamePopUpWindow();
    PlaySE(SE_M_REFLECT);
    FlagSet(FLAG_SYS_USE_FLASH);
    ScriptContext_SetupScript(EventScript_UseFlashTool);
}

void SetUpFieldMove_FlashMon(void)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_FlashMon;
}

void FieldCallback_FlashMon(void)
{
    u32 taskId = 0;
    PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    gFieldEffectArguments[0] = gSpecialVar_Result;
    taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlash >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlash;
}

u32 CanUseFlashOnMap(void)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    bool32 bagHasItem = CheckBagHasItem(ITEM_FLASH_TOOL,1);
    if(
        gMapHeader.cave == TRUE
        && (monHasMove || bagHasItem)
        && FlagGet(FLAG_BADGE02_GET)
        && !FlagGet(FLAG_SYS_USE_FLASH)
        && (GetFlashLevel() == (gMaxFlashLevel - 1))
      )
    {
        return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }
    return FIELD_MOVE_FAIL;
}

void CheckAndDoQoLFlash(void)
{
    u32 fieldMoveStatus = CanUseFlashOnMap();

    if ((fieldMoveStatus != FIELD_MOVE_FAIL))
    {
        LockPlayerFieldControls();
        gFieldEffectArguments[0] = gSpecialVar_Result;

        if (fieldMoveStatus == FIELD_MOVE_POKEMON)
            SetUpFieldMove_FlashMon();

        else if (fieldMoveStatus == FIELD_MOVE_TOOL)
            SetUpFieldMove_QoLFlash();
    }
}

// Rock Smash

static bool8 CanStartSmashingRock(s16 x, s16 y, u8 direction)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM06);
    bool32 bagHasItem = CheckBagHasItem(ITEM_ROCKSMASH_TOOL,1);

    if (
            CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_BREAKABLE_ROCK)
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && (monHasMove || bagHasItem)
            && FlagGet(FLAG_BADGE03_GET)
       )

    {
        return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }

    return FIELD_MOVE_FAIL;
}

// Waterfall

static u32 CanStartClimbingWaterfall(u8 direction)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM07);
    bool32 bagHasItem = CheckBagHasItem(ITEM_WATERFALL_TOOL,1);

    if (
        IsPlayerFacingWaterfall()
        && IsPlayerSurfingNorth()
        && (direction == DIR_SOUTH)
        && (monHasMove || bagHasItem)
        && FlagGet(FLAG_BADGE03_GET)
       )

    {
        return monHasMove ? FIELD_MOVE_POKEMON : FIELD_MOVE_TOOL;
    }

    return FIELD_MOVE_FAIL;
}

bool32 CanStartWaterfallTool(void)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM07);
    bool32 bagHasItem = CheckBagHasItem(ITEM_WATERFALL_TOOL,1);

    if (
        IsPlayerFacingWaterfall()
        && IsPlayerSurfingNorth()
        && (monHasMove || bagHasItem)
        && FlagGet(FLAG_BADGE03_GET)
       )

    {
        return TRUE;
    }

    return FALSE;
}

static bool8 (*const sWaterfallWithoutMonFieldEffectFuncs[])(struct Task *, struct ObjectEvent *) =
{
    WaterfallWithoutMonFieldEffect_Init,
    WaterfallWithoutMonFieldEffect_RideUp,
    WaterfallWithoutMonFieldEffect_ContinueRideOrEnd,
};

void CreateClimbWaterfallTask(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseWaterfallWithoutMon, 0xFF);
    Task_UseWaterfallWithoutMon(taskId);
}

static void Task_UseWaterfallWithoutMon(u8 taskId)
{
    while (sWaterfallWithoutMonFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]));
}

static bool8 WaterfallWithoutMonFieldEffect_Init(struct Task *task, struct ObjectEvent *objectEvent)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tState++;
    return FALSE;
}

static bool8 WaterfallWithoutMonFieldEffect_RideUp(struct Task *task, struct ObjectEvent *objectEvent)
{
    ObjectEventSetHeldMovement(objectEvent, GetWalkSlowMovementAction(DIR_NORTH));
    task->tState++;
    return FALSE;
}

static bool8 WaterfallWithoutMonFieldEffect_ContinueRideOrEnd(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (!ObjectEventClearHeldMovementIfFinished(objectEvent))
        return FALSE;

    if (MetatileBehavior_IsWaterfall(objectEvent->currentMetatileBehavior))
    {
        // Still ascending waterfall, back to WaterfallFieldEffect_RideUp
        task->tState = 1;
        return TRUE;
    }

    UnlockPlayerFieldControls();
    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(FindTaskIdByFunc(Task_UseWaterfallWithoutMon));
    FieldEffectActiveListRemove(FLDEFF_USE_WATERFALL);
    return FALSE;
}

bool8 IsPlayerFacingWaterfall(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    MoveCoords(playerObjEvent->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerObjEvent, x, y, playerObjEvent->facingDirection) == COLLISION_NONE
     && MetatileBehavior_IsWaterfall(MapGridGetMetatileBehaviorAt(x, y)))
        return TRUE;
    else
        return FALSE;
}


#undef tState
#undef tMonId

// Dive

static bool8 (*const sDiveWithoutMonFieldEffectFuncs[])(struct Task *) =
{
    DiveWithoutMonFieldEffect_Init,
    DiveWithoutMonFieldEffect_TryWarp,
};

bool8 FldEff_UseDiveWithoutMon(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseDiveWithoutMon, 0xff);
    Task_UseDiveWithoutMon(taskId);
    return FALSE;
}

static void Task_UseDiveWithoutMon(u8 taskId)
{
    while (sDiveWithoutMonFieldEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 DiveWithoutMonFieldEffect_Init(struct Task *task)
{
    gPlayerAvatar.preventStep = TRUE;
    task->data[0]++;
    return FALSE;
}

static bool8 DiveWithoutMonFieldEffect_TryWarp(struct Task *task)
{
    struct MapPosition mapPosition;
    PlayerGetDestCoords(&mapPosition.x, &mapPosition.y);

    TryDoDiveWarp(&mapPosition, gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior);
    DestroyTask(FindTaskIdByFunc(Task_UseDiveWithoutMon));
    //FieldEffectActiveListRemove(FLDEFF_USE_DIVE);
    return FALSE;
}

// Teleport

bool8 FldEff_UseTeleportNoMon(void)
{
    u8 taskId = CreateFieldMoveNoMonTask();
    gTasks[taskId].data[8] = (u32)StartTeleportFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartTeleportFieldEffect;
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

// Sweet Scent

bool8 FldEff_SweetScentNoMon(void)
{
    u8 taskId;

    SetWeatherScreenFadeOut();
    taskId = CreateFieldMoveNoMonTask();
    gTasks[taskId].data[8] = (u32)StartSweetScentFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSweetScentFieldEffect;
    return FALSE;
}




void ClearQoLFieldMovesFlags(void)
{
    FlagClear(FLAG_SYS_USE_CUT);
    FlagClear(FLAG_SYS_USE_SURF);
    FlagClear(FLAG_SYS_USE_ROCK_SMASH);
    FlagClear(FLAG_SYS_USE_WATERFALL);
}

static bool32 PartyCanLearnMoveLevelUp(u16 species, u16 moveId)
{
    u32 i = 0;
    for (i = 0; gLevelUpLearnsets[species][i] != LEVEL_UP_END; i++)
    {
        if ((gLevelUpLearnsets[species][i] & LEVEL_UP_MOVE_ID) == moveId)
            return TRUE;
    }
    return FALSE;
}

bool32 PartyHasMonLearnsKnowsFieldMove(u16 itemId)
{
    struct Pokemon *mon;
    u32 species = 0, i = 0;
    u16 moveId = ItemIdToBattleMoveId(itemId);
    gSpecialVar_Result = PARTY_SIZE;
    gSpecialVar_0x8004 = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon,MON_DATA_SPECIES,NULL);

        if (species == SPECIES_NONE)
            break;

        if (PartyCanLearnMoveLevelUp(species, moveId)
            || (CanMonLearnTMTutor(mon, itemId,0) == ALREADY_KNOWS_MOVE)
            || (CanMonLearnTMTutor(mon, itemId,0) == CAN_LEARN_MOVE)
           )
        {
            gSpecialVar_Result = i;
            gSpecialVar_0x8004 = species;
            return TRUE;
        }
    }
    return FALSE;
}

