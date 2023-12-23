#include "global.h"
#include "battle_tower.h"
#include "event_data.h"
#include "battle_setup.h"
#include "text.h"
#include "main.h"
#include "international_string_util.h"
#include "battle.h"
#include "frontier_util.h"
#include "strings.h"
#include "string_util.h"
#include "item.h"
#include "tv.h"
#include "overworld.h"
#include "battle_arcade.h"
#include "battle_records.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/battle_arcade.h"
#include "constants/field_specials.h"
#include "constants/hold_effects.h"
#include "constants/trainers.h"
#include "constants/opponents.h"
#include "battle_dome.h"
#include "random.h"
#ifdef BATTLE_ARCADE

#define FRONTIER_SAVEDATA gSaveBlock2Ptr->frontier
#define ARCADE_SAVE_WINS FRONTIER_SAVEDATA.arcadeWinStreaks
#define ARCADE_SAVE_STREAKS FRONTIER_SAVEDATA.arcadeRecordWinStreaks

static EWRAM_DATA u8 sBattleArcade_TypeWinsWindowId = 0;

static void (* const sBattleArcadeFuncs[])(void);

static void InitArcadeChallenge(void);
static void GetArcadeData(void);
static void SetArcadeData(void);
static void SetArcadeBattleWon(void);
static void SaveCurrentStreak(void);
static void SaveCurrentParty(u32, u8);
static void SaveArcadeChallenge(void);
static void GetOpponentIntroSpeech(void);
static void GetContinueMenuType(void);
static u32 GenerateSetEvent(void);
static u32 GetImpactSide(u32 event);
static bool32 IsItemConsumable(u16);
static void RestoreNonConsumableHeldItems(void);
static u32 CalculateBattlePoints(u32);
static void GiveBattlePoints(void);
static u32 CountNumberTypeWin(u8);
static void CheckArcadeSymbol(void);
static void TakePlayerHeldItems(void);
static void TakeEnemyHeldItems(void);
static void TakeHeldItems(struct Pokemon *party);
static void HandleGameBoardResult(void);
static void GetBrainStatus(void);
static void GetBrainIntroSpeech(void);
static void BufferImpactedName(u32 impact);
static u8 ConvertMenuInputToType(u8);
static void ConvertMenuInputToTypeAndSetVar(void);
static void ShowBattleArcadeTypeWinsWindow(void);
static void CloseBattleArcadeTypeWinsWindow(void);
static void ShowBattleArcadeTypeMonsWindow(void);
static void CloseBattleArcadeTypeMonsWindow(void);
static void InitBattleArcadeMons(void);
static void ArcadePrintTypesMastered(u8, u8, u8);
static u32 GetBestTypeWinAmount(u8);
static const u8 *GetBestTypeWinType(u8);
static void ArcadePrintBestStreak(u8, u8, u8);
static void PrintArcadeStreak(const u8*, u16, u8, u8);
static void SaveCurrentWinStreak(void);
u16 GetCurrentBattleArcadeWinStreak(u8 lvlMode, u8 battleMode);
static void BufferGiveString(u32);
static bool32 DoGameBoardResult(u32, u32);

static const struct WindowTemplate sBattleArcade_TypeWinsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 20,
};

static void (* const sBattleArcadeFuncs[])(void) =
{
    [ARCADE_FUNC_INIT]                   = InitArcadeChallenge,
    [ARCADE_FUNC_GET_DATA]               = GetArcadeData,
    [ARCADE_FUNC_SET_DATA]               = SetArcadeData,
    [ARCADE_FUNC_SET_BATTLE_WON]         = SetArcadeBattleWon,
    [ARCADE_FUNC_SAVE]                   = SaveArcadeChallenge,
    [ARCADE_FUNC_GET_OPPONENT_INTRO]     = GetOpponentIntroSpeech,
    [ARCADE_FUNC_GIVE_BATTLE_POINTS]     = GiveBattlePoints,
    [ARCADE_FUNC_CHECK_SYMBOL]           = CheckArcadeSymbol,
    [ARCADE_FUNC_TAKE_PLAYER_ITEMS]      = TakePlayerHeldItems,
    [ARCADE_FUNC_TAKE_ENEMY_ITEMS]       = TakeEnemyHeldItems,
    [ARCADE_FUNC_HANDLE_GAME_RESULT]     = HandleGameBoardResult,
    [ARCADE_FUNC_CHECK_BRAIN_STATUS]     = GetBrainStatus,
    [ARCADE_FUNC_GET_BRAIN_INTRO]        = GetBrainIntroSpeech,
};

static const u32 sWinStreakFlags[][2] =
{
    {STREAK_ARCADE_SINGLES_50,     STREAK_ARCADE_SINGLES_OPEN},
    {STREAK_ARCADE_DOUBLES_50,     STREAK_ARCADE_DOUBLES_OPEN},
    {STREAK_ARCADE_MULTIS_50,      STREAK_ARCADE_MULTIS_OPEN},
};

static const u32 sWinStreakMasks[][2] =
{
    {~(STREAK_ARCADE_SINGLES_50),     ~(STREAK_ARCADE_SINGLES_OPEN)},
    {~(STREAK_ARCADE_DOUBLES_50),     ~(STREAK_ARCADE_DOUBLES_OPEN)},
    {~(STREAK_ARCADE_MULTIS_50),      ~(STREAK_ARCADE_MULTIS_OPEN)},
};

void CallBattleArcadeFunc(void)
{
    sBattleArcadeFuncs[gSpecialVar_0x8004]();
}

static void InitArcadeChallenge(void)
{
    u32 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    FRONTIER_SAVEDATA.challengeStatus = CHALLENGE_STATUS_SAVING;
    FRONTIER_SAVEDATA.curChallengeBattleNum = 0;
    FRONTIER_SAVEDATA.challengePaused = FALSE;
    FRONTIER_SAVEDATA.disableRecordBattle = FALSE;
    ResetFrontierTrainerIds();
    if (!(FRONTIER_SAVEDATA.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
        FRONTIER_SAVEDATA.arcadeWinStreaks[battleMode][lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void GetArcadeData(void)
{
    u32 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case ARCADE_DATA_WIN_STREAK:
        gSpecialVar_Result = GetCurrentBattleArcadeWinStreak(lvlMode, battleMode);
        break;
    case ARCADE_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((FRONTIER_SAVEDATA.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case ARCADE_DATA_LVL_MODE:
        FRONTIER_SAVEDATA.arcadeLvlMode = FRONTIER_SAVEDATA.lvlMode;
        break;
    }
}

static void SetArcadeData(void)
{
    u32 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
        case 0:
            break;
        case ARCADE_DATA_WIN_STREAK:
            FRONTIER_SAVEDATA.curChallengeBattleNum = gSpecialVar_0x8006;
            break;
        case ARCADE_DATA_WIN_STREAK_ACTIVE:
            if (gSpecialVar_0x8006)
                FRONTIER_SAVEDATA.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
            else
                FRONTIER_SAVEDATA.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
            break;
    }
}

static void SetArcadeBattleWon(void)
{
    FRONTIER_SAVEDATA.curChallengeBattleNum++;
    SaveCurrentWinStreak();
    gSpecialVar_Result = FRONTIER_SAVEDATA.curChallengeBattleNum;
}

static void SaveCurrentWinStreak(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 winStreak = GetCurrentBattleArcadeWinStreak(lvlMode, battleMode);

    if (FRONTIER_SAVEDATA.arcadeWinStreaks[battleMode][lvlMode] < winStreak)
        FRONTIER_SAVEDATA.arcadeWinStreaks[battleMode][lvlMode] = winStreak;
}

u16 GetCurrentBattleArcadeWinStreak(u8 lvlMode, u8 battleMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.arcadeWinStreaks[battleMode][lvlMode];

    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void SaveCurrentStreak(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 oldStreak = ARCADE_SAVE_STREAKS[battleMode][lvlMode];
    u32 currentStreak = ARCADE_SAVE_WINS[battleMode][lvlMode];

    if (oldStreak >= currentStreak)
        return;

    ARCADE_SAVE_STREAKS[battleMode][lvlMode] = currentStreak;
}

static void SaveArcadeChallenge(void)
{
    u16 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 challengeNum = (signed)(FRONTIER_SAVEDATA.arcadeWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE);

    if (gSpecialVar_0x8005 == 0 && (challengeNum > 1 || FRONTIER_SAVEDATA.curChallengeBattleNum != 0))

    FRONTIER_SAVEDATA.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    FRONTIER_SAVEDATA.challengePaused = TRUE;
    SaveGameFrontier();
}

static void GetOpponentIntroSpeech(void)
{
    FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static const u8 sArcadeBattlePointAwards[][FRONTIER_MODE_COUNT] =
{
    {2,2,2},
    {2,2,2},
    {2,2,2},
    {2,2,2},
    {4,4,4},
    {4,4,4},
    {4,5,5},
    {6,6,6},
};

static u32 CalculateBattlePoints(u32 challengeNum)
{
    u32 maxChallengeNum = ARRAY_COUNT(sArcadeBattlePointAwards);
    u32 points;

    if (challengeNum != 0)
        challengeNum--;

    if (challengeNum >= maxChallengeNum)
        challengeNum = (maxChallengeNum - 1);

    points = sArcadeBattlePointAwards[challengeNum][VarGet(VAR_FRONTIER_BATTLE_MODE)];

    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        points = 20;

    return points;
}

static void GiveBattlePoints(void)
{
    u32 points = CalculateBattlePoints(((gSaveBlock2Ptr->frontier.arcadeWinStreaks[VarGet(VAR_FRONTIER_BATTLE_MODE)][gSaveBlock2Ptr->frontier.lvlMode]) / FRONTIER_STAGES_PER_CHALLENGE));

    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar2, points, STR_CONV_MODE_LEFT_ALIGN,CountDigits(points));

    FRONTIER_SAVEDATA.cardBattlePoints += ((points > USHRT_MAX) ? USHRT_MAX: points);
    FRONTIER_SAVEDATA.battlePoints += ((points > MAX_BATTLE_FRONTIER_POINTS) ? MAX_BATTLE_FRONTIER_POINTS : points);
}

static void CheckArcadeSymbol(void)
{
    u32 numWins = 0;
    u8 numDigits = CountDigits(numWins);
    u32 hasSilver = FlagGet(FLAG_SYS_ARENA_SILVER);
    u32 hasGold = FlagGet(FLAG_SYS_ARENA_GOLD);
    bool32 shouldGetGold = (numWins == (NUMBER_OF_MON_TYPES - 1));
    bool32 shouldGetSilver = (numWins == ((NUMBER_OF_MON_TYPES - 1) /2));

    ConvertIntToDecimalStringN(gStringVar1, numWins, STR_CONV_MODE_LEFT_ALIGN, numDigits);

    if (shouldGetGold && !hasGold)
        gSpecialVar_Result = ARCADE_SYMBOL_GOLD;
    else if (shouldGetSilver && !hasSilver)
        gSpecialVar_Result = ARCADE_SYMBOL_SILVER;
    else
        gSpecialVar_Result = ARCADE_SYMBOL_NONE;
}

u32 Arcade_SetChallengeNumToMax(u8 challengeNum)
{
    return (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_ARCADE) ? UCHAR_MAX : challengeNum;
}

static u8 ConvertMenuInputToType(u8 selection)
{
    return (selection > TYPE_STEEL) ? ++selection : selection;
}


static void TakeEnemyHeldItems(void)
{
    struct Pokemon *party = gEnemyParty;
    TakeHeldItems(party);
}

static void TakePlayerHeldItems(void)
{
    struct Pokemon *party = gPlayerParty;
    TakeHeldItems(party);
}

static void TakeHeldItems(struct Pokemon *party)
{
    u32 i;
    u16 item = ITEM_NONE;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;

        SetMonData(&party[i], MON_DATA_HELD_ITEM, &item);
    }
}

#define VAR_IMPACT_SIDE VAR_TEMP_2

u32 GetSetImpactSide(u32 event)
{
    u32 impact = GetImpactSide(event);
    BufferImpactedName(impact);
    VarSet(VAR_IMPACT_SIDE,impact);
    return impact;
}


static u32 GetImpactSide(u32 event)
{
    if (event >= ARCADE_SUN)
        return ARCADE_IMPACT_ALL;
    else
        return Random() % ARCADE_IMPACT_ALL;
}

static u32 GenerateSetEvent(void)
{
    u32 event = Random() % ARCADE_EVENT_COUNT;
    gSpecialVar_0x8005 = event;
}

static void HandleGameBoardResult(void)
{
    u32 event = GenerateSetEvent();
    u32 impact = GetSetImpactSide(event);

    gSpecialVar_Result = DoGameBoardResult(event, impact);
}

static void BufferGameBerryName(void)
{
    CopyItemName(ITEM_APICOT_BERRY, gStringVar3);
}

static void BufferGameItemName(void)
{
    CopyItemName(ITEM_LEFTOVERS, gStringVar3);
}

static void BufferGiveString(u32 event)
{
    if (event == ARCADE_GIVE_BERRY)
        BufferGameBerryName();
    else
        BufferGameItemName();
}

static bool32 DoGameBoardResult(u32 event, u32 impact)
{
    BufferGiveString(event);
    return TRUE;
}

static u32 GetImpactedTrainerId(u32 impact)
{
    return (impact == ARCADE_IMPACT_PLAYER) ? TRAINER_PLAYER : gTrainerBattleOpponent_A;
}

static void BufferImpactedName(u32 impact)
{
    CopyDomeTrainerName(gStringVar1, GetImpactedTrainerId(impact));
}

#define VAR_BRAIN_STATUS VAR_TEMP_F

static void GetBrainStatus(void)
{
    VarSet(VAR_BRAIN_STATUS,0); //Debug
    // return true if the brain should be fought here
    return;
}

static void GetBrainIntroSpeech(void)
{
    //return one string for silver fight and otherwise the gold string
    return;
}

// graphical set up off board
// populate array with effects
// iterate again over each spot and pick a side

#endif
