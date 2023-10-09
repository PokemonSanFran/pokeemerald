#include "global.h"
#include "battle_tower.h"
#include "apprentice.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "text.h"
#include "main.h"
#include "international_string_util.h"
#include "battle.h"
#include "frontier_util.h"
#include "strings.h"
#include "recorded_battle.h"
#include "easy_chat.h"
#include "gym_leader_rematch.h"
#include "battle_transition.h"
#include "trainer_see.h"
#include "new_game.h"
#include "string_util.h"
#include "data.h"
#include "link.h"
#include "field_message_box.h"
#include "tv.h"
#include "battle_factory.h"
#include "constants/apprentice.h"
#include "constants/battle_dome.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_mons.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tower.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/item.h"
#include "item.h"
#include "constants/trainers.h"
#include "constants/event_objects.h"
#include "constants/moves.h"
#include "constants/restricted_sparring.h"
#include "tv.h"
#include "restricted_sparring.h"

#define SPARRING_SAVEDATA gSaveBlock2Ptr->frontier.restrictedSparring

static void (* const sRestrictedSparringFuncs[])(void);
static void InitSparringChallenge(void);
static void GetSparringData(void);
static void SetSparringData(void);
static void SetSparringBattleWon(void);
static void SaveSparringChallenge(void);
static void SaveCurrentStreak(void);
static u32 GetCurrentSparringWinStreak(u8, u32);
static void GetOpponentIntroSpeech(void);
static void RestoreNonConsumableHeldItems(void);
static bool32 IsItemConsumable(u16 item);
static void ResetSketchedMoves(void);
static void GiveBattlePoints(void);
static bool32 IsFirstTypeWin(void);
static void BufferSparringTypeNameToString(void);
static u32 CountNumberWinStreaks(void);
static void CheckSparringSymbol(void);

static void (* const sRestrictedSparringFuncs[])(void) =
{
    [SPARRING_FUNC_INIT]                = InitSparringChallenge,
    [SPARRING_FUNC_GET_DATA]            = GetSparringData,
    [SPARRING_FUNC_SET_DATA]            = SetSparringData,
    [SPARRING_FUNC_SET_BATTLE_WON]      = SetSparringBattleWon,
    [SPARRING_FUNC_SAVE]                = SaveSparringChallenge,
    [SPARRING_FUNC_GET_OPPONENT_INTRO]  = GetOpponentIntroSpeech,
    [SPARRING_FUNC_GET_CONTINUE_MENU_TYPE] = GetContinueMenuType,
    [SPARRING_FUNC_RESTORE_HELD_ITEMS]     = RestoreNonConsumableHeldItems,
    [SPARRING_FUNC_RESET_SKETCH_MOVES]     = ResetSketchedMoves,
    [SPARRING_FUNC_GIVE_BATTLE_POINTS]    = GiveBattlePoints,
    [SPARRING_FUNC_GET_TYPE_NAME] = BufferSparringTypeNameToString,
    [SPARRING_FUNC_CHECK_SYMBOL] = CheckSparringSymbol,
};

void CallRestrictedSparringFunc(void)
{
    sRestrictedSparringFuncs[gSpecialVar_0x8004]();
}

static void InitSparringChallenge(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 typeMode= VarGet(VAR_SPARRING_TYPE);

    FlagClear(FLAG_SPARRING_FIRST_TYPE_WIN);
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void GetSparringData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 typeMode= VarGet(VAR_SPARRING_TYPE);

    switch (gSpecialVar_0x8005)
    {
    case SPARRING_DATA_WIN_STREAK:
        gSpecialVar_Result = (gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        break;
    case SPARRING_DATA_LVL_MODE:
        gSpecialVar_Result = lvlMode;
        break;
    case SPARRING_DATA_TYPE_MODE:
        gSpecialVar_Result = typeMode;
    }
}

static void SetSparringData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 typeMode = VarGet(VAR_SPARRING_TYPE);

    switch (gSpecialVar_0x8005)
    {
    case SPARRING_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    }
}

static void SetSparringBattleWon(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum++;
    SaveCurrentStreak();
}

static void SaveCurrentStreak(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 typeMode = VarGet(VAR_SPARRING_TYPE);
    u32 oldStreak = SPARRING_SAVEDATA[typeMode][lvlMode].winStreak;
    u32 currentStreak = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    if (oldStreak >= currentStreak)
        return;

    SPARRING_SAVEDATA[typeMode][lvlMode].winStreak = currentStreak;

    if (oldStreak == (SPARRING_REWARD_BONUS_ROUND - 1))
        FlagSet(FLAG_SPARRING_FIRST_TYPE_WIN);
}

static u32 GetCurrentSparringWinStreak(u8 lvlMode, u32 typeMode)
{
    u32 winStreak = SPARRING_SAVEDATA[typeMode][lvlMode].winStreak = winStreak;

    if (winStreak > MAX_SPARRING_STREAK)
        return MAX_SPARRING_STREAK;
    else
        return winStreak;
}

static void SaveSparringChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void GetOpponentIntroSpeech(void)
{
    FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

u32 CalculateMenuType(void)
{
    bool32 hasHeal = (!(VarGet(VAR_RESTRICTEDSPARRING_HEAL_COUNT) == 0));
    bool32 canRecord = (gSaveBlock2Ptr->frontier.disableRecordBattle == FALSE);

    if (canRecord && hasHeal)
        return RECORDYES_HEALYES;
    if (canRecord && !hasHeal)
        return RECORDYES_HEALNO;
    if (!canRecord && hasHeal)
        return RECORDNO_HEALYES;
    if (!canRecord && !hasHeal)
        return RECORDNO_HEALNO;
}

void GetContinueMenuType(void)
{
    gSpecialVar_Result = CalculateMenuType();
}

static bool32 IsItemConsumable(u16 item)
{
    return (gItems[item].pocket == POCKET_BERRIES);
}

static void RestoreNonConsumableHeldItems(void)
{
    u8 i;
    u16 item;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] == 0)
            break;

        item = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_HELD_ITEM, NULL);

        if (!IsItemConsumable(item))
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
    }
}

static void ResetSketchedMoves(void)
{
    u8 i, j, k;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                for (k = 0; k < MAX_MON_MOVES; k++)
                {
                    if (GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + k, NULL)
                        == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL))
                        break;
                }
                if (k == MAX_MON_MOVES)
                    SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, j);
            }
        }
    }
}

static bool32 IsFirstTypeWin(void)
{
    return FlagGet(FLAG_SPARRING_FIRST_TYPE_WIN);
}

static u32 CalculateBattlePoints(u32 numWins)
{
    u32 points = 0, i;

    if (numWins == 0)
        return 0;
    if (numWins < SPARRING_REWARD_BONUS_ROUND)
        return (numWins * SPARRING_REWARD_BP);

    if (IsFirstTypeWin())
        points +=  SPARRING_REWARD_FIRST_BONUS;

    for (i = 1; i <= numWins; i++)
    {
        if ((i % SPARRING_MIN_STREAK) == 0)
            points += SPARRING_REWARD_BP_BONUS;
        else
            points += SPARRING_REWARD_BP;
    }
    return points;
}

static void GiveBattlePoints(void)
{
    u32 points = CalculateBattlePoints(gSaveBlock2Ptr->frontier.curChallengeBattleNum);
    DebugPrintf("you getting %d points",points);

    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);

    gSaveBlock2Ptr->frontier.cardBattlePoints += ((points > USHRT_MAX) ? USHRT_MAX: points);
    gSaveBlock2Ptr->frontier.battlePoints += ((points > MAX_BATTLE_FRONTIER_POINTS) ? MAX_BATTLE_FRONTIER_POINTS : points);

}

bool32 CheckIfPartyMonMatchesType(struct Pokemon *mon)
{
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 chosenType = VarGet(VAR_SPARRING_TYPE);

    if((gSpeciesInfo[species].types[0] != chosenType) && (gSpeciesInfo[species].types[1] != chosenType))
        return FALSE;

    return TRUE;
}

static void BufferSparringTypeNameToString(void)
{
    StringCopy(gStringVar3, gTypeNames[VarGet(VAR_SPARRING_TYPE)]);
}

static u32 CountNumberWinStreaks(void)
{
    u32 i, numWins = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) > (SPARRING_MIN_STREAK - 1))
            numWins++;

        DebugPrintf("for type %d, you have %d wins.",i,SPARRING_SAVEDATA[i][lvlMode].winStreak);

    }
    DebugPrintf("you have %d wins",numWins);
    return numWins;
}

static void CheckSparringSymbol(void)
{
    u32 numWins = CountNumberWinStreaks();
    u8 numDigits = CountDigits(numWins);
    u32 hasSilver = FlagGet(FLAG_SYS_ARENA_SILVER);
    u32 hasGold = FlagGet(FLAG_SYS_ARENA_GOLD);
    bool32 shouldGetGold = (numWins == (NUMBER_OF_MON_TYPES - 1));
    bool32 shouldGetSilver = (numWins == (NUMBER_OF_MON_TYPES /2));

    if (shouldGetGold && !hasGold)
    {
        ConvertIntToDecimalStringN(gStringVar1, numWins, STR_CONV_MODE_LEFT_ALIGN, numDigits);
        gSpecialVar_Result = SPARRING_GET_GOLD;
        return;
    }
    else if (shouldGetSilver && !hasSilver)
    {
        ConvertIntToDecimalStringN(gStringVar1, numWins, STR_CONV_MODE_LEFT_ALIGN, numDigits);
        gSpecialVar_Result = SPARRING_GET_SILVER;
        return;
    }

    gSpecialVar_Result = SPARRING_GET_NONE;
}

u32 MaxChallengeNumInRestrictingSparring(u8 challengeNum)
{
    /*
    if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_SPARRING)
        return UCHAR_MAX;
    else
        return challengeNum;
        */
    return (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_SPARRING) ? UCHAR_MAX : challengeNum;
}
