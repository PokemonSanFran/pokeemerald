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
#include "battle_transition.h"
#include "battle_pike.h"
#include "constants/weather.h"
#include "field_weather.h"
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
static bool32 BattleArcade_DoGive(u32 impact, u32 type);
static void GetContinueMenuType(void);
static u32 GenerateSetEvent(void);
static void ResetGiveItemVar(void);
static u32 GetImpactSide(u32 event);
static bool32 IsItemConsumable(u16);
static void RestoreNonConsumableHeldItems(void);
static u32 CalculateBattlePoints(u32);
static void GiveBattlePoints(u32 points);
static void CalculateGiveChallengeBattlePoints(void);
static u32 CountNumberTypeWin(u8);
static void BattleArcade_GiveEnemyItems(void);
static void CheckArcadeSymbol(void);
static void TakePlayerHeldItems(void);
static void TakeEnemyHeldItems(void);
static struct Pokemon *LoadSideParty(u32);
static void TakeHeldItems(struct Pokemon *party);
static void HandleGameBoardResult(void);
static void GetBrainStatus(void);
static void GetBrainIntroSpeech(void);
static void BattleArcade_PostBattleEventCleanup(void);
static void BufferImpactedName(u32 impact);
static void HandleGiveItemVar(u32 impact, u32 type);
static void ShowBattleArcadeTypeWinsWindow(void);
static void CloseBattleArcadeTypeWinsWindow(void);
static void ShowBattleArcadeTypeMonsWindow(void);
static void CloseBattleArcadeTypeMonsWindow(void);
static void InitBattleArcadeMons(void);
static void ArcadePrintTypesMastered(u8, u8, u8);
static u32 GetBestTypeWinAmount(u8);
static const u8 *GetBestTypeWinType(u8);
static void ArcadePrintBestStreak(u8, u8, u8);
static bool32 IsGiveItemVarSet(void);
static void PrintArcadeStreak(const u8*, u16, u8, u8);
static void SaveCurrentWinStreak(void);
u16 GetCurrentBattleArcadeWinStreak(u8 lvlMode, u8 battleMode);
static void BufferGiveString(u32);
static bool32 DoGameBoardResult(u32, u32);
static bool32 BattleArcade_DoLowerHP(u32);
static bool32 BattleArcade_DoPoison(u32);
static bool32 BattleArcade_DoParalyze(u32);
static bool32 BattleArcade_DoBurn(u32);
static bool32 BattleArcade_DoSleep(u32);
static bool32 BattleArcade_DoFreeze(u32);
static bool32 BattleArcade_DoStatusAilment(u32, u32);
static bool32 BattleArcade_DoGiveBerry(u32);
static bool32 BattleArcade_DoGiveItem(u32);
static bool32 BattleArcade_DoLevelUp(u32);
static bool32 BattleArcade_DoSun(void);
static bool32 BattleArcade_DoRain(void);
static bool32 BattleArcade_DoSand(void);
static bool32 BattleArcade_DoHail(void);
static bool32 BattleArcade_DoFog(void);
static bool32 BattleArcade_DoTrickRoom(void);
static bool32 BattleArcade_DoSwap(void);
static bool32 BattleArcade_DoSpeedUp(void);
static bool32 BattleArcade_DoSpeedDown(void);
static bool32 BattleArcade_DoRandom(void);
static bool32 BattleArcade_DoGiveBP(void);
static bool32 BattleArcade_DoNoBattle(void);
static bool32 BattleArcade_DoNoEvent(void);
static void FillFrontierTrainerParties(void);
static void ResetLevelsToOriginal(void);
void ResetRouletteSpeed(void);

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
    [ARCADE_FUNC_GIVE_BATTLE_POINTS]     = CalculateGiveChallengeBattlePoints,
    [ARCADE_FUNC_CHECK_SYMBOL]           = CheckArcadeSymbol,
    [ARCADE_FUNC_TAKE_PLAYER_ITEMS]      = TakePlayerHeldItems,
    [ARCADE_FUNC_TAKE_ENEMY_ITEMS]       = TakeEnemyHeldItems,
    [ARCADE_FUNC_HANDLE_GAME_RESULT]     = HandleGameBoardResult,
    [ARCADE_FUNC_CHECK_BRAIN_STATUS]     = GetBrainStatus,
    [ARCADE_FUNC_GET_BRAIN_INTRO]        = GetBrainIntroSpeech,
    [ARCADE_FUNC_EVENT_CLEAN_UP]         = BattleArcade_PostBattleEventCleanup,
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
    ResetGiveItemVar();
    ResetRouletteSpeed();
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

static void CalculateGiveChallengeBattlePoints(void)
{
    u32 points = CalculateBattlePoints(((gSaveBlock2Ptr->frontier.arcadeWinStreaks[VarGet(VAR_FRONTIER_BATTLE_MODE)][gSaveBlock2Ptr->frontier.lvlMode]) / FRONTIER_STAGES_PER_CHALLENGE));
    GiveBattlePoints(points);
}

static void GiveBattlePoints(u32 points)
{
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

static void TakeEnemyHeldItems(void)
{
    TakeHeldItems(LoadSideParty(ARCADE_IMPACT_OPPONENT));
}

static void TakePlayerHeldItems(void)
{
    TakeHeldItems(LoadSideParty(ARCADE_IMPACT_PLAYER));
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

u32 GetSetImpactSide(u32 event)
{
    u32 impact = GetImpactSide(event);
    BufferImpactedName(impact);
    VarSet(VAR_ARCADE_IMPACT_SIDE,impact);
    return impact;
}

static u32 GetImpactSide(u32 event)
{
    //return ARCADE_IMPACT_PLAYER; // Debug

    if (event >= ARCADE_EVENT_FIELD_START)
        return ARCADE_IMPACT_ALL;
    else
        return Random() % ARCADE_IMPACT_ALL;
}

static u32 GenerateSetEvent(void)
{
    u32 event;
    do
    {
        event = Random() % ARCADE_EVENT_COUNT;
    } while ((event == ARCADE_EVENT_TRICK_ROOM)||(event == ARCADE_EVENT_FOG));

    /*
    if (VarGet(VAR_ARCADE_EVENT) == ARCADE_EVENT_RAIN)
        event = ARCADE_EVENT_SLEEP;
    else
    */
        event = ARCADE_EVENT_SPEED_UP; //Debug

    VarSet(VAR_ARCADE_EVENT,event);
    return event;
}

static bool32 IsEventBattle(u32 event)
{
    return (event != ARCADE_EVENT_NO_BATTLE);
}

static bool32 DoesEventGiveItems(u32 event)
{
    if (!IsEventBattle(event))
        return FALSE;

    if ((event != ARCADE_EVENT_GIVE_BERRY) && (event != ARCADE_EVENT_GIVE_ITEM))
        return FALSE;

    return TRUE;
}

static bool32 ShouldEnemyGetItemBeforeBattle(u32 event)
{
    if (!IsGiveItemVarSet())
        return FALSE;

    if (DoesEventGiveItems(event))
        return FALSE;

    return TRUE;
}

static void HandleGameBoardResult(void)
{
    u32 event = GenerateSetEvent();
    u32 impact = GetSetImpactSide(event);

    FillFrontierTrainerParties();
    if (ShouldEnemyGetItemBeforeBattle(event))
        BattleArcade_GiveEnemyItems();

    gSpecialVar_Result = DoGameBoardResult(event, impact);
}

static bool32 DoGameBoardResult(u32 event, u32 impact)
{
    switch (event)
    {
        case ARCADE_EVENT_LOWER_HP: return BattleArcade_DoLowerHP(impact);
        case ARCADE_EVENT_POISON: return BattleArcade_DoPoison(impact);
        case ARCADE_EVENT_PARALYZE: return BattleArcade_DoParalyze(impact);
        case ARCADE_EVENT_BURN: return BattleArcade_DoBurn(impact);
        case ARCADE_EVENT_SLEEP: return BattleArcade_DoSleep(impact);
        case ARCADE_EVENT_FREEZE: return BattleArcade_DoFreeze(impact);
        case ARCADE_EVENT_GIVE_BERRY: return BattleArcade_DoGiveBerry(impact);
        case ARCADE_EVENT_GIVE_ITEM: return BattleArcade_DoGiveItem(impact);
        case ARCADE_EVENT_LEVEL_UP: return BattleArcade_DoLevelUp(impact);
        case ARCADE_EVENT_SUN: return BattleArcade_DoSun();
        case ARCADE_EVENT_RAIN: return BattleArcade_DoRain();
        case ARCADE_EVENT_SAND: return BattleArcade_DoSand();
        case ARCADE_EVENT_HAIL: return BattleArcade_DoHail();
        case ARCADE_EVENT_FOG: return BattleArcade_DoFog();
        case ARCADE_EVENT_TRICK_ROOM: return BattleArcade_DoTrickRoom();
        case ARCADE_EVENT_SWAP: return BattleArcade_DoSwap();
        case ARCADE_EVENT_SPEED_UP: return BattleArcade_DoSpeedUp();
        case ARCADE_EVENT_SPEED_DOWN: return BattleArcade_DoSpeedDown();
        case ARCADE_EVENT_RANDOM: return BattleArcade_DoRandom();
        case ARCADE_EVENT_GIVE_BP_SMALL: return BattleArcade_DoGiveBP();
        case ARCADE_EVENT_GIVE_BP_BIG: return BattleArcade_DoGiveBP();
        case ARCADE_EVENT_NO_BATTLE: return BattleArcade_DoNoBattle();
        default:
        case ARCADE_EVENT_NO_EVENT: return BattleArcade_DoNoEvent();
    }
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

static struct Pokemon *LoadSideParty(u32 impact)
{
    if (impact == ARCADE_IMPACT_PLAYER)
        return gPlayerParty;
    else
        return gEnemyParty;
}

static bool32 BattleArcade_DoLowerHP(u32 impact)
{
    u32 i, maxHP, reducedHP;
    struct Pokemon *party = LoadSideParty(impact);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (!GetMonData(&party[i], MON_DATA_SANITY_HAS_SPECIES))
            break;

        maxHP = GetMonData(&party[i], MON_DATA_MAX_HP);
        reducedHP = maxHP - (maxHP * 200 / 1000);
        SetMonData(&party[i], MON_DATA_HP, &reducedHP);
    }
    return TRUE;
}

static bool32 BattleArcade_DoPoison(u32 impact)
{
	return BattleArcade_DoStatusAilment(impact, STATUS1_POISON);
}
static bool32 BattleArcade_DoParalyze(u32 impact)
{
	return BattleArcade_DoStatusAilment(impact, STATUS1_PARALYSIS);
}
static bool32 BattleArcade_DoBurn(u32 impact)
{
	return BattleArcade_DoStatusAilment(impact, STATUS1_BURN);
}
static bool32 BattleArcade_DoSleep(u32 impact)
{
	return BattleArcade_DoStatusAilment(impact, STATUS1_SLEEP);
}
static bool32 BattleArcade_DoFreeze(u32 impact)
{
	return BattleArcade_DoStatusAilment(impact, STATUS1_FREEZE);
}

static bool32 IsStatusSleepOrFreeze(u32 status)
{
    return ((status == STATUS1_FREEZE) || (status == STATUS1_SLEEP));
}

static void InitalizePartyIndex(u32 *newIndex)
{
    u32 i;
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        newIndex[i] = i;
}

static void ShufflePartyIndex(u32 *newIndex)
{
    u32 i, temp;
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        SWAP(newIndex[i], newIndex[Random() % (i +1)], temp);
}

static bool32 BattleArcade_DoStatusAilment(u32 impact, u32 status)
{
    struct Pokemon *party = LoadSideParty(impact);
    struct Pokemon *mon;
    u32 i, impactedCount = 0, species;
    u32 newIndex[MAX_FRONTIER_PARTY_SIZE];

    InitalizePartyIndex(newIndex);

    if (IsStatusSleepOrFreeze(status))
        ShufflePartyIndex(newIndex);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        mon = &party[newIndex[i]];

        if (!GetMonData(mon,MON_DATA_SANITY_HAS_SPECIES))
            continue;

        if (DoesAbilityPreventStatus(mon, status))
            continue;

        if (DoesTypePreventStatus(GetMonData(mon,MON_DATA_SPECIES), status))
            continue;

        SetMonData(mon, MON_DATA_STATUS, &status);
        impactedCount++;

        if (!IsStatusSleepOrFreeze(status))
            continue;

        return TRUE;
    }
    return (impactedCount > 0);
}

static void BufferGiveString(u32 item)
{
    CopyItemName(item,gStringVar3);
}

static bool32 BattleArcade_DoGiveBerry(u32 impact)
{
    HandleGiveItemVar(impact, ARCADE_EVENT_GIVE_BERRY);
    return BattleArcade_DoGive(impact, ARCADE_EVENT_GIVE_BERRY);
}

static bool32 BattleArcade_DoGiveItem(u32 impact)
{
    HandleGiveItemVar(impact, ARCADE_EVENT_GIVE_ITEM);
    return BattleArcade_DoGive(impact, ARCADE_EVENT_GIVE_ITEM);
}

static u32 GetGroupIdFromWinStreak(void)
{
    u32 challengeNum = GetCurrentBattleArcadeWinStreak(FRONTIER_SAVEDATA.lvlMode, VarGet(VAR_FRONTIER_BATTLE_MODE)) / FRONTIER_STAGES_PER_CHALLENGE;

    if (challengeNum < 3)
        return ARCADE_BERRY_GROUP_1;
    else if (challengeNum > 6)
        return ARCADE_BERRY_GROUP_3;
    else
        return ARCADE_BERRY_GROUP_2;
}

static u32 GetCategorySize(u32 type)
{
    if (type == ARCADE_EVENT_GIVE_ITEM)
        return ARCADE_ITEM_GROUP_SIZE;
    else
        return ARCADE_BERRY_GROUP_SIZE;
}

static const u32 (*GetCategoryGroups(u32 type))[ARCADE_BERRY_GROUP_SIZE]
{
    static const u32 gameBerries[ARCADE_BERRY_GROUP_COUNT][ARCADE_BERRY_GROUP_SIZE] =
    {
        [ARCADE_BERRY_GROUP_1] =
        {
            ITEM_CHERI_BERRY,
            ITEM_CHESTO_BERRY,
            ITEM_PECHA_BERRY,
            ITEM_RAWST_BERRY,
            ITEM_ASPEAR_BERRY,
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
        },
        [ARCADE_BERRY_GROUP_2] =
        {
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
        },
        [ARCADE_BERRY_GROUP_3] =
        {
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
            ITEM_LIECHI_BERRY,
            ITEM_GANLON_BERRY,
            ITEM_SALAC_BERRY,
            ITEM_PETAYA_BERRY,
            ITEM_APICOT_BERRY,
            ITEM_LANSAT_BERRY,
            ITEM_STARF_BERRY,
        },
    };

    static const u32 gameItems[ARCADE_ITEM_GROUP_COUNT][ARCADE_ITEM_GROUP_SIZE] =
    {
        [ARCADE_ITEM_GROUP_1] =
        {
            ITEM_CHERI_BERRY,
            ITEM_CHESTO_BERRY,
            ITEM_PECHA_BERRY,
            ITEM_RAWST_BERRY,
            ITEM_ASPEAR_BERRY,
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
        },
        [ARCADE_ITEM_GROUP_2] =
        {
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
        },
        [ARCADE_ITEM_GROUP_3] =
        {
            ITEM_PERSIM_BERRY,
            ITEM_SITRUS_BERRY,
            ITEM_LUM_BERRY,
            ITEM_LIECHI_BERRY,
            ITEM_GANLON_BERRY,
            ITEM_SALAC_BERRY,
            ITEM_PETAYA_BERRY,
            ITEM_APICOT_BERRY,
            ITEM_LANSAT_BERRY,
            ITEM_STARF_BERRY,
        },
    };

    return (type == ARCADE_EVENT_GIVE_ITEM) ? gameItems : gameBerries;
}

static u32 BattleArcade_GenerateGive(u32 type)
{
    u32 heldItem = ITEM_NONE;
    u32 maxGroupSize = GetCategorySize(type);
    u32 groupId = GetGroupIdFromWinStreak();
    const u32 (*itemGroups)[ARCADE_BERRY_GROUP_SIZE] = GetCategoryGroups(type);

    do
    {
        heldItem = itemGroups[groupId][Random() % maxGroupSize];
    } while (heldItem == ITEM_NONE);

    return heldItem;
}

static bool32 IsGiveItemVarSet(void)
{
    return (VarGet(VAR_ARCADE_GIVE_HOLD_ITEM));
}

static bool32 IsImpactedSideOpponent(u32 impact)
{
    return (impact == ARCADE_IMPACT_OPPONENT);
}

static void HandleGiveItemVar(u32 impact, u32 type)
{
    if (!IsImpactedSideOpponent(impact))
        return;

    VarSet(VAR_ARCADE_GIVE_HOLD_ITEM,type);
}

static void ResetGiveItemVar(void)
{
    VarSet(VAR_ARCADE_GIVE_HOLD_ITEM,ARCADE_ENEMY_HOLD_NOTHING);
}

static void BattleArcade_GiveEnemyItems(void)
{
    BattleArcade_DoGive(ARCADE_IMPACT_OPPONENT, VarGet(VAR_ARCADE_GIVE_HOLD_ITEM));
}

static bool32 BattleArcade_DoGive(u32 impact, u32 type)
{
    u32 i;
    u32 item = BattleArcade_GenerateGive(type);
    struct Pokemon *party = LoadSideParty(impact);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;

        SetMonData(&party[i], MON_DATA_HELD_ITEM, &item);
    }

    BufferGiveString(item);
    return TRUE;
}

static u32 CalculateNewLevel(u32 origLevel)
{
    u32 newLevel = (origLevel + ARCADE_EVENT_LEVEL_INCREASE);
    return (newLevel >= MAX_LEVEL) ? MAX_LEVEL : newLevel;
}

static void SaveLevelDifferentToSaveblock(u32 index, u32 origLevel, u32 newLevel)
{
    FRONTIER_SAVEDATA.arcadeLvlDiff[index] = (newLevel - origLevel);
}

static u32 GetLevelDifferentFromSaveblock(u32 index)
{
    return FRONTIER_SAVEDATA.arcadeLvlDiff[index];
}

static u32 CalculateAndSaveNewLevel(u32 index, u32 origLevel)
{
    SaveLevelDifferentToSaveblock(index,origLevel,CalculateNewLevel(origLevel));
    return (origLevel + GetLevelDifferentFromSaveblock(index));
}

static bool32 BattleArcade_DoLevelUp(u32 impact)
{
    u32 i, newLevel, oldLevel;
    struct Pokemon *party = LoadSideParty(impact);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (!GetMonData(&party[i], MON_DATA_SANITY_HAS_SPECIES))
            break;

        newLevel = CalculateAndSaveNewLevel(i,(GetMonData(&party[i], MON_DATA_LEVEL)));
        SetMonData(&party[i], MON_DATA_LEVEL, &newLevel);
    }
    return TRUE;
    // ARCADE TODO this should not appear if at level 100
}

static void BattleArcade_DoWeather(u32 weather)
{
    SetSavedWeather(weather);
    DoCurrentWeather();
}

static bool32 BattleArcade_DoSun(void)
{
    BattleArcade_DoWeather(WEATHER_DROUGHT);
	return TRUE;
}
static bool32 BattleArcade_DoRain(void)
{
    BattleArcade_DoWeather(WEATHER_DOWNPOUR);
	return TRUE;
}
static bool32 BattleArcade_DoSand(void)
{
    BattleArcade_DoWeather(WEATHER_SANDSTORM);
	return TRUE;
}
static bool32 BattleArcade_DoHail(void)
{
    BattleArcade_DoWeather(WEATHER_SNOW);
    //ARCADE TODO snow needs to keep going _AND summon infinite hail
	return TRUE;
}
static bool32 BattleArcade_DoFog(void)
{
    BattleArcade_DoWeather(WEATHER_FOG_HORIZONTAL);
    //ARCADE TODO if Fog is not around at all in gen 3, disable this effect
	return TRUE;
}
static bool32 BattleArcade_DoTrickRoom(void)
{
	return TRUE;
}
static bool32 BattleArcade_DoSwap(void)
{
    u32 i;
    struct Pokemon tempParty[MAX_FRONTIER_PARTY_SIZE];

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;

        CopyMon(&tempParty[i],&gPlayerParty[i],sizeof(gPlayerParty[i]));
        CopyMon(&gPlayerParty[i],&gEnemyParty[i],sizeof(gEnemyParty[i]));
        CopyMon(&gEnemyParty[i],&tempParty[i],sizeof(tempParty[i]));
    }
    return TRUE;
}

/*
static bool32 BattleArcade_ChangeSpeed(u32 mode)
{
    u32 currentSpeed = VarGet(VAR_ARCADE_CURSOR_SPEED);

    if (mode == ARCADE_EVENT_SPEED_DOWN)
    {
        if (ARCADE_SPEED_DECREMENT > currentSpeed)
        {
            VarSet(VAR_ARCADE_CURSOR_SPEED,ARCADE_SPEED_MIN);
    DebugPrintf("speed: %d, now: %d",currentSpeed,VarGet(VAR_ARCADE_CURSOR_SPEED));
            return TRUE;
        }
    }
    else
    {
        if ((ARCADE_SPEED_INCREMENT + currentSpeed) > ARCADE_SPEED_MAX)
        {
            VarSet(VAR_ARCADE_CURSOR_SPEED,ARCADE_SPEED_MAX);
    DebugPrintf("speed: %d, now: %d",currentSpeed,VarGet(VAR_ARCADE_CURSOR_SPEED));
            return TRUE;
        }
    }

    if (mode == ARCADE_EVENT_SPEED_UP)
        VarSet(VAR_ARCADE_CURSOR_SPEED,currentSpeed + ARCADE_SPEED_INCREMENT);
    else
        VarSet(VAR_ARCADE_CURSOR_SPEED,currentSpeed + ARCADE_SPEED_DECREMENT);


    DebugPrintf("speed: %d, now: %d",currentSpeed,VarGet(VAR_ARCADE_CURSOR_SPEED));
    return TRUE;
}
*/

static bool32 BattleArcade_ChangeSpeed(u32 mode)
{
    u32 currentSpeed = VarGet(VAR_ARCADE_CURSOR_SPEED);
    DebugPrintf("speed at beginning: %d",currentSpeed);

    if ((mode == ARCADE_EVENT_SPEED_UP) && (currentSpeed == ARCADE_SPEED_LEVEL_7))
        return TRUE;

    if ((mode == ARCADE_EVENT_SPEED_DOWN) && (currentSpeed == ARCADE_SPEED_LEVEL_0))
        return TRUE;

    if (mode == ARCADE_EVENT_SPEED_UP)
        VarSet(VAR_ARCADE_CURSOR_SPEED,++currentSpeed);
    else
        VarSet(VAR_ARCADE_CURSOR_SPEED,--currentSpeed);

    DebugPrintf("speed at end: %d",currentSpeed);
    return TRUE;
}

static bool32 BattleArcade_DoSpeedUp(void)
{
    BattleArcade_ChangeSpeed(ARCADE_EVENT_SPEED_UP);
	return TRUE;
}
static bool32 BattleArcade_DoSpeedDown(void)
{
    BattleArcade_ChangeSpeed(ARCADE_EVENT_SPEED_DOWN);
	return TRUE;
}
static bool32 BattleArcade_DoRandom(void)
{
	return TRUE;
}
static bool32 BattleArcade_DoGiveBP(void)
{
	return TRUE;
}
static bool32 BattleArcade_DoNoBattle(void)
{
	return TRUE;
}
static bool32 BattleArcade_DoNoEvent(void)
{
	return TRUE;
}

#define VAR_BRAIN_STATUS VAR_TEMP_F

static void GetBrainStatus(void)
{
    VarSet(VAR_BRAIN_STATUS,0); //Debug
    // return true if the brain should be fought here
    return;
}

static bool32 IsOpponentImpacted(void)
{
    return (VarGet(VAR_ARCADE_IMPACT_SIDE) == ARCADE_IMPACT_OPPONENT);
}

static void GetBrainIntroSpeech(void)
{
    //return one string for silver fight and otherwise the gold string
    return;
}

void SetBattleTypeFlags(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
    switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
    {
        case FRONTIER_MODE_SINGLES:
            break;
        case FRONTIER_MODE_DOUBLES:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
            break;
        case FRONTIER_MODE_MULTIS:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
            break;
    }
}

void FillFrontierTrainerParties(void)
{
    switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
    {
        case FRONTIER_MODE_SINGLES:
            FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
            break;
        case FRONTIER_MODE_DOUBLES:
            FillFrontierTrainerParty(FRONTIER_DOUBLES_PARTY_SIZE);
            break;
        case FRONTIER_MODE_MULTIS:
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.trainerIds[17];
            FillPartnerParty(gPartnerTrainerId);
            break;
    }
}

void DoSpecialRouletteTrainerBattle(void)
{
    SetBattleTypeFlags();
    CreateTask(Task_StartBattleAfterTransition, 1);
    PlayMapChosenOrBattleBGM(0);
    BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
}

static bool32 IsEventLevelUp(void)
{
     return (VarGet(VAR_ARCADE_EVENT) == ARCADE_EVENT_LEVEL_UP);
}

static bool32 IsEventSwap(void)
{
     return (VarGet(VAR_ARCADE_EVENT) == ARCADE_EVENT_SWAP);
}

static void BattleArcade_ReturnPlayerPartyOriginalLevel(void)
{
    u32 i, newLevel;
    struct Pokemon *party = LoadSideParty(ARCADE_IMPACT_PLAYER);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (!GetMonData(&party[i], MON_DATA_SANITY_HAS_SPECIES))
            break;

        newLevel = (GetMonData(&party[i], MON_DATA_LEVEL) - FRONTIER_SAVEDATA.arcadeLvlDiff[i]);

        if (newLevel <= 0)
            newLevel = MIN_LEVEL;

        SetMonData(&party[i], MON_DATA_LEVEL, &newLevel);
        CalculateMonStats(&party[i]);
    }
}

static void ResetLevelsToOriginal(void)
{
    if (!IsEventLevelUp())
        return;

    BattleArcade_ReturnPlayerPartyOriginalLevel();
}

static void ReturnPartyToOwner(void)
{
    if (!IsEventSwap())
        return;
    BattleArcade_DoSwap();
}

static void ResetWeatherPostBattle(void)
{
    DoCurrentWeather();
    SetSavedWeatherFromCurrMapHeader();
}

void BattleArcade_PostBattleEventCleanup(void)
{
    ResetLevelsToOriginal();
    ReturnPartyToOwner();
    ResetWeatherPostBattle();
}

void ResetRouletteSpeed(void)
{
    VarSet(VAR_ARCADE_CURSOR_SPEED,ARCADE_SPEED_DEFAULT);
}

// graphical set up off board
// populate array with effects
// iterate again over each spot and pick a side

#endif
