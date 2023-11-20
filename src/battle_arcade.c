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
#ifdef BATTLE_ARCADE

#define FRONTIER_SAVEDATA gSaveBlock2Ptr->frontier
#define ARCADE_SAVEDATA FRONTIER_SAVEDATA.battleArcade

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
static void ResetSketchedMoves(void);
static bool32 IsFirstTypeWin(void);
static u32 CalculateBattlePoints(u32);
static void GiveBattlePoints(void);
static void BufferArcadeTypeNameToString(void);
static u32 CountNumberTypeWin(u8);
static u32 GetNumberTypeWinFromSaveblock(void);
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
static void CompareStreakToMax(void);

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
    [ARCADE_FUNC_RESET_SKETCH_MOVES]     = ResetSketchedMoves,
    [ARCADE_FUNC_GIVE_BATTLE_POINTS]     = GiveBattlePoints,
    [ARCADE_FUNC_GET_TYPE_NAME]          = BufferArcadeTypeNameToString,
    [ARCADE_FUNC_CHECK_SYMBOL]           = CheckArcadeSymbol,
    [ARCADE_FUNC_CONVERT_TYPE]           = ConvertMenuInputToTypeAndSetVar,
    [ARCADE_FUNC_CHECK_MAX]              = CompareStreakToMax,
};

STATIC_ASSERT(VAR_ARCADE_HEAL_COUNT > 0, AssignAVarTo_VAR_ARCADE_HEAL_COUNT_ToUseBattleArcade);
STATIC_ASSERT(VAR_ARCADE_TYPE > 0, AssignAVarTo_VAR_ARCADE_TYPE_ToUseBattleArcade);
STATIC_ASSERT(FLAG_ARCADE_FIRST_TYPE_WIN > 0, AssignAFlagTo_FLAG_ARCADE_FIRST_TYPE_WIN_ToUseBattleArcade);

void CallBattleArcadeFunc(void)
{
    sBattleArcadeFuncs[gSpecialVar_0x8004]();
}

static void InitArcadeChallenge(void)
{
    FlagClear(FLAG_ARCADE_FIRST_TYPE_WIN);
    FRONTIER_SAVEDATA.challengeStatus = 0;
    FRONTIER_SAVEDATA.curChallengeBattleNum = 0;
    FRONTIER_SAVEDATA.challengePaused = FALSE;
    FRONTIER_SAVEDATA.disableRecordBattle = FALSE;
    VarSet(VAR_ARCADE_HEAL_COUNT,ARCADE_MAX_NUM_RESTORE);

    gTrainerBattleOpponent_A = 0;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetArcadeData(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 typeMode= VarGet(VAR_ARCADE_TYPE);

    switch (gSpecialVar_0x8005)
    {
    case ARCADE_DATA_WIN_STREAK:
        gSpecialVar_Result = (FRONTIER_SAVEDATA.curChallengeBattleNum);
        break;
    case ARCADE_DATA_LVL_MODE:
        gSpecialVar_Result = lvlMode;
        break;
    case ARCADE_DATA_TYPE_MODE:
        gSpecialVar_Result = typeMode;
    }
}

static void SetArcadeData(void)
{
    switch (gSpecialVar_0x8005)
    {
    case ARCADE_DATA_WIN_STREAK:
        FRONTIER_SAVEDATA.curChallengeBattleNum = gSpecialVar_0x8006;
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
    u32 typeMode = VarGet(VAR_ARCADE_TYPE);
    u32 oldStreak = ARCADE_SAVEDATA[typeMode][lvlMode].winStreak;
    u32 currentStreak = FRONTIER_SAVEDATA.curChallengeBattleNum;

    if (oldStreak >= currentStreak)
        return;

    ARCADE_SAVEDATA[typeMode][lvlMode].winStreak = currentStreak;

    if (oldStreak < ARCADE_MIN_STREAK)
        if (currentStreak >= ARCADE_MIN_STREAK)
            FlagSet(FLAG_ARCADE_FIRST_TYPE_WIN);

}

static void SaveArcadeChallenge(void)
{
    FRONTIER_SAVEDATA.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
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

static void ResetSketchedMoves(void)
{
    u32 i, j, k;
    u16 monId;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        monId = FRONTIER_SAVEDATA.selectedPartyMons[i] - 1;

        if (monId >= PARTY_SIZE)
            continue;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            for (k = 0; k < MAX_MON_MOVES; k++)
            {
                if (GetMonData(&gSaveBlock1Ptr->playerParty[FRONTIER_SAVEDATA.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + k, NULL)
                        == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL))
                    break;
            }
            if (k == MAX_MON_MOVES)
                SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, j);
                PokemonUseItemEffects(&gPlayerParty[i],ITEM_MAX_ETHER,i,MON_DATA_MOVE1 + k,FALSE);
        }
    }
}

static bool32 IsFirstTypeWin(void)
{
    return FlagGet(FLAG_ARCADE_FIRST_TYPE_WIN);
}

static u32 CalculateBattlePoints(u32 numWins)
{
    u32 points = 0, i;

    if (numWins == 0)
        return 0;

    if (numWins < ARCADE_BP_BONUS_MATCH)
        return (numWins * ARCADE_BP_BASE);

    if (IsFirstTypeWin())
        points +=  ARCADE_BP_TYPE_WIN_BONUS;

    for (i = 1; i <= numWins; i++)
    {
        if ((i % ARCADE_BP_STREAK_BONUS) == 0)
            points += ARCADE_BP_STREAK_BONUS;
        else
            points += ARCADE_BP_BASE;
    }

    return points;
}

static void GiveBattlePoints(void)
{
    u32 points = CalculateBattlePoints(FRONTIER_SAVEDATA.curChallengeBattleNum);

    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar2, points, STR_CONV_MODE_LEFT_ALIGN,CountDigits(points));

    FRONTIER_SAVEDATA.cardBattlePoints += ((points > USHRT_MAX) ? USHRT_MAX: points);
    FRONTIER_SAVEDATA.battlePoints += ((points > MAX_BATTLE_FRONTIER_POINTS) ? MAX_BATTLE_FRONTIER_POINTS : points);
}

bool32 Arcade_CheckIfPartyMonMatchesType(struct Pokemon *mon)
{
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 chosenType = VarGet(VAR_ARCADE_TYPE);

    if((gSpeciesInfo[species].types[0] != chosenType) && (gSpeciesInfo[species].types[1] != chosenType))
        return FALSE;

    return TRUE;
}

static void BufferArcadeTypeNameToString(void)
{
    StringCopy(gStringVar3, gTypeNames[VarGet(VAR_ARCADE_TYPE)]);
}

static u32 CountNumberTypeWin(u8 lvlMode)
{
    u32 i, numWins = 0;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
        if ((ARCADE_SAVEDATA[i][lvlMode].winStreak) >= ARCADE_BP_STREAK_BONUS)
            numWins++;

    return numWins;
}

static u32 GetNumberTypeWinFromSaveblock(void)
{
    return CountNumberTypeWin(FRONTIER_SAVEDATA.lvlMode);
}

static void CheckArcadeSymbol(void)
{
    u32 numWins = GetNumberTypeWinFromSaveblock();
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

void Arcade_ShowWinsWindow(void)
{
    ShowBattleArcadeTypeWinsWindow();
}

void Arcade_CloseWinsWindow(void)
{
    CloseBattleArcadeTypeWinsWindow();
}

static void ShowBattleArcadeTypeWinsWindow(void)
{
    sBattleArcade_TypeWinsWindowId = AddWindow(&sBattleArcade_TypeWinsWindowTemplate);
    SetStandardWindowBorderStyle(sBattleArcade_TypeWinsWindowId, FALSE);
    PutWindowTilemap(sBattleArcade_TypeWinsWindowId);
    CopyWindowToVram(sBattleArcade_TypeWinsWindowId, COPYWIN_GFX);
}

static void CloseBattleArcadeTypeWinsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sBattleArcade_TypeWinsWindowId, TRUE);
    RemoveWindow(sBattleArcade_TypeWinsWindowId);
}


void FillBattleArcadeWinWindow(u16 selection)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 typeMode = ConvertMenuInputToType(selection);
    u32 num = ARCADE_SAVEDATA[typeMode][lvlMode].winStreak;
    u32 width = GetWindowAttribute(sBattleArcade_TypeWinsWindowId, WINDOW_WIDTH) * ARCADE_TILES;
    u32 height = GetWindowAttribute(sBattleArcade_TypeWinsWindowId, WINDOW_HEIGHT) * ARCADE_TILES;

    FillWindowPixelBuffer(sBattleArcade_TypeWinsWindowId,PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, CountDigits(ARCADE_MAX_STREAK));
    StringExpandPlaceholders(gStringVar2,gText_WinStreak);

    if (typeMode == NUMBER_OF_MON_TYPES)
        StringCopy(gStringVar2,gText_Blank);

    AddTextPrinterParameterized2(sBattleArcade_TypeWinsWindowId, FONT_NORMAL, gStringVar2, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
}


static void ArcadePrintTypesMastered(u8 lvlMode, u8 x, u8 y)
{
    PrintArcadeStreak(gText_TypesMastered, CountNumberTypeWin(lvlMode), x, y);
}

static u32 GetBestTypeWinAmount(u8 lvlMode)
{
    u32 i;
    u32 biggestWins = ARCADE_SAVEDATA[0][lvlMode].winStreak;

    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
        if ((ARCADE_SAVEDATA[i][lvlMode].winStreak) > biggestWins)
            biggestWins = (ARCADE_SAVEDATA[i][lvlMode].winStreak);

    return biggestWins;
}

static const u8 *GetBestTypeWinType(u8 lvlMode)
{
    u32 type = 0, i = 0;
    u32 biggestWins = ARCADE_SAVEDATA[0][lvlMode].winStreak;

    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
    {
        if ((ARCADE_SAVEDATA[i][lvlMode].winStreak) > biggestWins)
        {
            biggestWins = (ARCADE_SAVEDATA[i][lvlMode].winStreak);
            type = i;
        }
    }
    return gTypeNames[type];
}

static void ArcadePrintBestStreak(u8 lvlMode, u8 x, u8 y)
{
    StringCopy(gStringVar2,GetBestTypeWinType(lvlMode));
    PrintArcadeStreak(gText_BestStreak,GetBestTypeWinAmount(lvlMode),x,y);
}

static void PrintArcadeStreak(const u8 *str, u16 num, u8 x, u8 y)
{
    if (num > ARCADE_MAX_STREAK)
        num = ARCADE_MAX_STREAK;

    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, CountDigits(ARCADE_MAX_STREAK));
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x, y, TEXT_SKIP_DRAW, NULL);
}

void Arcade_ShowResultsWindow(void)
{
    static const struct WindowTemplate sFrontierResultsWindowTemplate =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    };

    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);

    StringExpandPlaceholders(gStringVar4, gText_BattleArcadeResults);
    PrintAligned(gStringVar4, ARCADE_RECORD_HEADER_Y_POS);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, ARCADE_RECORD_LEVEL_HEADER_X_POS, ARCADE_RECORD_50_LEVEL_Y_POS, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, ARCADE_RECORD_LEVEL_HEADER_X_POS, ARCADE_RECORD_OPEN_LEVEL_Y_POS, TEXT_SKIP_DRAW, NULL);

    PrintHyphens(10);

    ArcadePrintBestStreak(FRONTIER_LVL_50,ARCADE_RECORD_DATA_X_POS,ARCADE_RECORD_50_LEVEL_Y_POS);
    ArcadePrintTypesMastered(FRONTIER_LVL_50,ARCADE_RECORD_DATA_X_POS,ARCADE_RECORD_50_LEVEL_BEST_Y_POS);
    ArcadePrintBestStreak(FRONTIER_LVL_OPEN, ARCADE_RECORD_DATA_X_POS, ARCADE_RECORD_OPEN_LEVEL_Y_POS);
    ArcadePrintTypesMastered(FRONTIER_LVL_OPEN, ARCADE_RECORD_DATA_X_POS, ARCADE_RECORD_OPEN_LEVEL_BEST_Y_POS);

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

static void CompareStreakToMax(void)
{
    gSpecialVar_Result = FALSE;

    if (FRONTIER_SAVEDATA.curChallengeBattleNum != ARCADE_MAX_STREAK)
        return;

    ConvertIntToDecimalStringN(gStringVar1,ARCADE_MAX_STREAK,STR_CONV_MODE_LEFT_ALIGN,CountDigits(ARCADE_MAX_STREAK));
    gSpecialVar_Result = TRUE;
}

void Arcade_FillWindows(u16 selection)
{
    FillBattleArcadeWinWindow(selection);
}
#endif
