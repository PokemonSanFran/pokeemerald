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
#include "item_menu.h"

// TODO reset gitignore
/*
 TODO add  the following back to the git cache
        deleted:    data/layouts/layouts.json
        deleted:    data/maps/.gitignore
        deleted:    data/maps/map_groups.json
        deleted:    include/constants/layouts.h
        deleted:    include/constants/map_groups.h
        deleted:    src/data/wild_encounters.json
        deleted:    src/new_game.c
        */

// uncomment execute truck sequence

static u8 CreateUseToolTask(void);
static void Task_UseTool_Init(u8);
static void LockPlayerAndLoadMon(void);

static void FieldCallback_UseCutTool(void);

static void FieldCallback_UseFlyTool(void);
static void Task_UseFlyTool(void);

static void Task_UseSurfInit(u8);
static void Task_WaitUseSurf(u8);

static void UseFlash(u32 fieldMoveStatus);

static bool8 UseRockSmash(s16, s16, u8);

static void Task_UseWaterfallTool(u8);
static u32 CanUseWaterfall(u8);
static bool8 WaterfallToolFieldEffect_Init(struct Task *, struct ObjectEvent *);
static bool8 WaterfallToolFieldEffect_RideUp(struct Task *, struct ObjectEvent *);
static bool8 WaterfallToolFieldEffect_ContinueRideOrEnd(struct Task *, struct ObjectEvent *);
static bool8 IsPlayerFacingWaterfall(void);

static void Task_UseDiveTool(u8);
static bool8 DiveToolFieldEffect_Init(struct Task *task);
static bool8 DiveToolFieldEffect_TryWarp(struct Task *task);

static bool32 PartyCanLearnMoveLevelUp(u16, u16);

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]

static u8 CreateUseToolTask(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    return CreateTask(Task_UseTool_Init, 8);
}

static void Task_UseTool_Init(u8 taskId)
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

static void LockPlayerAndLoadMon(void)
{
    LockPlayerFieldControls();
    gFieldEffectArguments[0] = gSpecialVar_Result;
}

// Cut
u32 CanUseCut(s16 x, s16 y)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM01);
    bool32 bagHasItem = CheckBagHasItem(ITEM_CUT_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE01_GET);

    if (
            CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE)
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

bool8 SetUpFieldMove_UseCutTool(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE) == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_UseCutTool;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_UseCutTool(void)
{
    ScriptContext_SetupScript(EventScript_UseCutTool);
}

u32 UseCut(u32 fieldMoveStatus)
{
    LockPlayerAndLoadMon();

    if (FlagGet(FLAG_SYS_USE_CUT))
        ScriptContext_SetupScript(EventScript_CutTreeDown);
    else if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseCut);
    else if(fieldMoveStatus == FIELD_MOVE_TOOL)
        ScriptContext_SetupScript(EventScript_UseCutTool);

    FlagSet(FLAG_SYS_USE_CUT);
    return COLLISION_START_CUT;
}

// Fly
void ReturnToFieldFromFlyToolMapSelect(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = Task_UseFlyTool;
}

static void Task_UseFlyTool(void)
{
    Overworld_ResetStateAfterFly();
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    gFieldCallback = FieldCallback_UseFlyTool;
}

static void FieldCallback_UseFlyTool(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    if (gPaletteFade.active)
            return;

    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
    gFieldCallback = NULL;
}

bool32 IsFlyToolUsed(void)
{
    return (VarGet(VAR_FLY_TOOL_SOURCE));
}

bool32 ReturnToFieldOrBagFromFlyTool(void)
{
    if (VarGet(VAR_FLY_TOOL_SOURCE) == FLY_SOURCE_BAG)
        GoToBagMenu(ITEMMENULOCATION_LAST,KEYITEMS_POCKET,CB2_ReturnToFieldWithOpenMenu);
    else if (VarGet(VAR_FLY_TOOL_SOURCE) == FLY_SOURCE_FIELD)
        SetMainCallback2(CB2_ReturnToField);
}

void ResetFlyTool(void)
{
    VarSet(VAR_FLY_TOOL_SOURCE,0);
}

// Surf
u32 CanUseSurf(s16 x, s16 y, u8 collision)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM03);
    bool32 bagHasItem = CheckBagHasItem(ITEM_SURF_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE05_GET);
    bool32 collisionHasMismatch = (collision == COLLISION_ELEVATION_MISMATCH);

    if (
            IsPlayerFacingSurfableFishableWater()
            && collisionHasMismatch
            && (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

u32 CanUseSurfFromInteractedWater()
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    return CanUseSurf(x,y,COLLISION_ELEVATION_MISMATCH);
}

u32 UseSurf(u32 fieldMoveStatus)
{
    LockPlayerAndLoadMon();

    if (FlagGet(FLAG_SYS_USE_SURF))
        CreateUseSurfTask();
    else if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseSurfMove);
    else if(fieldMoveStatus == FIELD_MOVE_TOOL)
        ScriptContext_SetupScript(EventScript_UseSurfTool);

    FlagSet(FLAG_SYS_USE_SURF);
    return COLLISION_START_SURFING;
}

void CreateUseSurfTask(void)
{
    u8 taskId;

    ScriptContext_Enable();
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicTo(MUS_SURF);
    gPlayerAvatar.flags ^= PLAYER_AVATAR_FLAG_ON_FOOT;
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_SURFING;
    gPlayerAvatar.preventStep = TRUE;
    taskId = CreateTask(Task_UseSurfInit,0);
    gTasks[taskId].data[0] = GetPlayerFacingDirection();
    Task_UseSurfInit(taskId);
}

static void Task_UseSurfInit(u8 taskId)
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
    gTasks[taskId].func = Task_WaitUseSurf;
}

static void Task_WaitUseSurf(u8 taskId)
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

u32 CanUseStrength(u8 collision)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM04);
    bool32 bagHasItem = CheckBagHasItem(ITEM_STRENGTH_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE04_GET);
    bool32 playerUsedStrength = FlagGet(FLAG_SYS_USE_STRENGTH);
    bool32 collisionEvent = (collision == COLLISION_OBJECT_EVENT);

    if (
        CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER)
        && !playerUsedStrength
        && collisionEvent
        && ((monHasMove && playerHasBadge) || bagHasItem)
       )
    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }
    return FIELD_MOVE_FAIL;
}

u32 UseStrength(u32 fieldMoveStatus)
{
    LockPlayerAndLoadMon();

    if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseStrength);
    else
        ScriptContext_SetupScript(EventScript_UseStrengthTool);

    return COLLISION_PUSHED_BOULDER;
}

// Flash

void SetUpFieldMove_UseFlash(u32 fieldMoveStatus)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;

    if (fieldMoveStatus == FIELD_MOVE_POKEMON)
        gPostMenuFieldCallback = FieldCallback_UseFlashMove;
    else if (fieldMoveStatus == FIELD_MOVE_TOOL)
        gPostMenuFieldCallback = FieldCallback_UseFlashTool;
}

void FieldCallback_UseFlashTool(void)
{
    u8 taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlashTool >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlashTool;
}

void FieldCallback_UseFlashMove(void)
{
    u8 taskId = CreateFieldMoveTask();
    PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    gFieldEffectArguments[0] = gSpecialVar_Result;

    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlash >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlash;
}

void FldEff_UseFlashTool(void)
{
    HideMapNamePopUpWindow();
    PlaySE(SE_M_REFLECT);
    FlagSet(FLAG_SYS_USE_FLASH);
    ScriptContext_SetupScript(EventScript_UseFlashTool);
}

u32 CanUseFlash(void)
{
    bool32 playerIsInCave = (gMapHeader.cave == TRUE);
    bool32 mapIsNotLit = (GetFlashLevel() == (gMaxFlashLevel - 1));
    bool32 playerHasUsedFlash = FlagGet(FLAG_SYS_USE_FLASH);
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE02_GET);
    bool32 bagHasItem = CheckBagHasItem(ITEM_FLASH_TOOL,1);

    if(
            playerIsInCave
            && mapIsNotLit
            && !playerHasUsedFlash
            && ((monHasMove && playerHasBadge) || bagHasItem)
      )
    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }
    return FIELD_MOVE_FAIL;
}

static void UseFlash(u32 fieldMoveStatus)
{
    LockPlayerAndLoadMon();
    SetUpFieldMove_UseFlash(fieldMoveStatus);
}

void TryUseFlash(void)
{
    u32 fieldMoveStatus = CanUseFlash();
    if (fieldMoveStatus)
        UseFlash(fieldMoveStatus);
}

// Rock Smash

static bool8 UseRockSmash(s16 x, s16 y, u8 direction)
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

static u32 CanUseWaterfall(u8 direction)
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

bool32 CanUseWaterfallTool(void)
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

static bool8 (*const sWaterfallToolFieldEffectFuncs[])(struct Task *, struct ObjectEvent *) =
{
    WaterfallToolFieldEffect_Init,
    WaterfallToolFieldEffect_RideUp,
    WaterfallToolFieldEffect_ContinueRideOrEnd,
};

void CreateUseWaterfallTask(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseWaterfallTool, 0xFF);
    Task_UseWaterfallTool(taskId);
}

static void Task_UseWaterfallTool(u8 taskId)
{
    while (sWaterfallToolFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]));
}

static bool8 WaterfallToolFieldEffect_Init(struct Task *task, struct ObjectEvent *objectEvent)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tState++;
    return FALSE;
}

static bool8 WaterfallToolFieldEffect_RideUp(struct Task *task, struct ObjectEvent *objectEvent)
{
    ObjectEventSetHeldMovement(objectEvent, GetWalkSlowMovementAction(DIR_NORTH));
    task->tState++;
    return FALSE;
}

static bool8 WaterfallToolFieldEffect_ContinueRideOrEnd(struct Task *task, struct ObjectEvent *objectEvent)
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
    DestroyTask(FindTaskIdByFunc(Task_UseWaterfallTool));
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

static bool8 (*const sDiveToolFieldEffectFuncs[])(struct Task *) =
{
    DiveToolFieldEffect_Init,
    DiveToolFieldEffect_TryWarp,
};

bool8 FldEff_UseDiveTool(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseDiveTool, 0xff);
    Task_UseDiveTool(taskId);
    return FALSE;
}

static void Task_UseDiveTool(u8 taskId)
{
    while (sDiveToolFieldEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 DiveToolFieldEffect_Init(struct Task *task)
{
    gPlayerAvatar.preventStep = TRUE;
    task->data[0]++;
    return FALSE;
}

static bool8 DiveToolFieldEffect_TryWarp(struct Task *task)
{
    struct MapPosition mapPosition;
    PlayerGetDestCoords(&mapPosition.x, &mapPosition.y);

    TryDoDiveWarp(&mapPosition, gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior);
    DestroyTask(FindTaskIdByFunc(Task_UseDiveTool));
    //FieldEffectActiveListRemove(FLDEFF_USE_DIVE);
    return FALSE;
}

// Teleport

bool8 FldEff_UseTeleportTool(void)
{
    u8 taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (u32)StartTeleportFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartTeleportFieldEffect;
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

// Sweet Scent

bool8 FldEff_SweetScentTool(void)
{
    u8 taskId;

    SetWeatherScreenFadeOut();
    taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (u32)StartSweetScentFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSweetScentFieldEffect;
    return FALSE;
}




void ClearFieldMoveFlags(void)
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

