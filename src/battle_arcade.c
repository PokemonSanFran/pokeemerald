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
#include "constants/moves.h"
#include "constants/battle_arcade.h"
#include "constants/field_specials.h"
#include "constants/hold_effects.h"
#include "constants/trainers.h"
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
static bool32 IsItemConsumable(u16);
static void RestoreNonConsumableHeldItems(void);
static u32 CalculateBattlePoints(u32);
static void GiveBattlePoints(void);
static u32 CountNumberTypeWin(u8);
static void CheckArcadeSymbol(void);
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
    [ARCADE_FUNC_GET_CONTINUE_MENU_TYPE] = GetContinueMenuType,
    [ARCADE_FUNC_RESTORE_HELD_ITEMS]     = RestoreNonConsumableHeldItems,
    [ARCADE_FUNC_GIVE_BATTLE_POINTS]     = GiveBattlePoints,
    [ARCADE_FUNC_CHECK_SYMBOL]           = CheckArcadeSymbol,
    [ARCADE_FUNC_CONVERT_TYPE]           = ConvertMenuInputToTypeAndSetVar,
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
    FRONTIER_SAVEDATA.challengeStatus = 0;
    FRONTIER_SAVEDATA.curChallengeBattleNum = 0;
    FRONTIER_SAVEDATA.challengePaused = FALSE;
    FRONTIER_SAVEDATA.disableRecordBattle = FALSE;

    gTrainerBattleOpponent_A = 0;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetArcadeData(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case ARCADE_DATA_WIN_STREAK:
        gSpecialVar_Result = (FRONTIER_SAVEDATA.curChallengeBattleNum);
        break;
    case ARCADE_DATA_LVL_MODE:
        gSpecialVar_Result = lvlMode;
        break;
    }
}

static void SetArcadeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
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
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
            break;
    }
}

static void SetArcadeBattleWon(void)
{
    u8 numWins = FRONTIER_SAVEDATA.curChallengeBattleNum;

    FRONTIER_SAVEDATA.curChallengeBattleNum = (numWins == ARCADE_MAX_STREAK) ? numWins : ++numWins;

    SaveCurrentStreak();
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
    FRONTIER_SAVEDATA.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    FRONTIER_SAVEDATA.challengePaused = TRUE;
    SaveGameFrontier();
}

static void GetOpponentIntroSpeech(void)
{
    FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

u32 CalculateMenuType(void)
{
    bool32 hasHeal = (!(VarGet(VAR_ARCADE_HEAL_COUNT) == 0));
    bool32 canRecord = (FRONTIER_SAVEDATA.disableRecordBattle == FALSE);

    if (canRecord && hasHeal)
        return ARCADE_RECORDYES_HEALYES;
    if (canRecord && !hasHeal)
        return ARCADE_RECORDYES_HEALNO;
    if (!canRecord && hasHeal)
        return ARCADE_RECORDNO_HEALYES;
    if (!canRecord && !hasHeal)
        return ARCADE_RECORDNO_HEALNO;
}

static void GetContinueMenuType(void)
{
    gSpecialVar_Result = CalculateMenuType();
}

static bool32 IsItemConsumable(u16 item)
{
    u32 holdEffect = gItems[item].holdEffect;

    return (
            (holdEffect > HOLD_EFFECT_NONE
             && holdEffect < HOLD_EFFECT_EVASION_UP)
            || (holdEffect == HOLD_EFFECT_RESTORE_STATS)
            || (holdEffect == HOLD_EFFECT_CURE_ATTRACT)
           );
}

static void RestoreNonConsumableHeldItems(void)
{
    u32 i;
    u16 item;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (FRONTIER_SAVEDATA.selectedPartyMons[i] == 0)
            break;

        item = GetMonData(&gSaveBlock1Ptr->playerParty[FRONTIER_SAVEDATA.selectedPartyMons[i] - 1], MON_DATA_HELD_ITEM, NULL);

        if (!IsItemConsumable(item))
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
    }
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

static void ConvertMenuInputToTypeAndSetVar(void)
{
    VarSet(VAR_ARCADE_TYPE,ConvertMenuInputToType(gSpecialVar_Result));
}

#endif
