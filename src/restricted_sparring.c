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
#include "restricted_sparring.h"
#include "battle_records.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/item.h"
#include "constants/moves.h"
#include "constants/restricted_sparring.h"
#include "constants/field_specials.h"
#ifdef RESTRICTED_SPARRING_MONS
#include "pokemon_icon.h"
#endif

#define SPARRING_SAVEDATA gSaveBlock2Ptr->frontier.restrictedSparring

static EWRAM_DATA u8 sRestrictedSparring_TypeWinsWindowId = 0;
static EWRAM_DATA u8 sRestrictedSparring_MarkWindowId = 0;
#ifdef RESTRICTED_SPARRING_MONS
static EWRAM_DATA u8 sRestrictedSparring_TypeMonsWindowId = 0;
static EWRAM_DATA u16 sScrollableMultichoice_MonIconId[FRONTIER_PARTY_SIZE];
#endif

static void (* const sRestrictedSparringFuncs[])(void);
static void InitSparringChallenge(void);
static void GetSparringData(void);
static void SetSparringData(void);
static void SetSparringBattleWon(void);
static void SaveSparringChallenge(void);
static void SaveCurrentStreak(void);
static void SaveCurrentParty(u32, u8);
static void GetOpponentIntroSpeech(void);
static void RestoreNonConsumableHeldItems(void);
static bool32 IsItemConsumable(u16);
static void ResetSketchedMoves(void);
static void GiveBattlePoints(void);
static bool32 IsFirstTypeWin(void);
static u8 ConvertMenuInputToType(u8);
static void ConvertMenuInputToTypeAndSetVar(void);
static void BufferSparringTypeNameToString(void);
static u32 GetNumberTypeWinFromSaveblock(void);
static void CheckSparringSymbol(void);
static void PrintSparringStreak(const u8*, u16, u8, u8);
static void CompareStreakToMax();
static void ShowRestrictedSparringTypeWinsWindow(void);
static void CloseRestrictedSparringTypeWinsWindow(void);
static void GetContinueMenuType(void);
//void ShowRestrictedSparringMarkWindow(void);
//void CloseRestrictedSparringMarkWindow(void);

static const struct WindowTemplate sRestrictedSparring_TypeWinsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 20,
};
#ifdef RESTRICTED_SPARRING_MONS
static void InitRestrictedSparringMons(void);
static void ShowRestrictedSparringTypeMonsWindow(void);
static void CloseRestrictedSparringTypeMonsWindow(void);
static const struct WindowTemplate sRestrictedSparring_TypeMonsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 10,
    .width = 12,
    .height = 3,
    .paletteNum = 15,
    .baseBlock = 41,
};
static const struct WindowTemplate sRestrictedSparring_MarkWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 1,
    .width = 12,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 41 + (12 * 12),
};
#endif

static void (* const sRestrictedSparringFuncs[])(void) =
{
    [SPARRING_FUNC_INIT]                   = InitSparringChallenge,
    [SPARRING_FUNC_GET_DATA]               = GetSparringData,
    [SPARRING_FUNC_SET_DATA]               = SetSparringData,
    [SPARRING_FUNC_SET_BATTLE_WON]         = SetSparringBattleWon,
    [SPARRING_FUNC_SAVE]                   = SaveSparringChallenge,
    [SPARRING_FUNC_GET_OPPONENT_INTRO]     = GetOpponentIntroSpeech,
    [SPARRING_FUNC_GET_CONTINUE_MENU_TYPE] = GetContinueMenuType,
    [SPARRING_FUNC_RESTORE_HELD_ITEMS]     = RestoreNonConsumableHeldItems,
    [SPARRING_FUNC_RESET_SKETCH_MOVES]     = ResetSketchedMoves,
    [SPARRING_FUNC_GIVE_BATTLE_POINTS]     = GiveBattlePoints,
    [SPARRING_FUNC_GET_TYPE_NAME]          = BufferSparringTypeNameToString,
    [SPARRING_FUNC_CHECK_SYMBOL]           = CheckSparringSymbol,
    [SPARRING_FUNC_CONVERT_TYPE]           = ConvertMenuInputToTypeAndSetVar,
    [SPARRING_FUNC_CHECK_MAX]              = CompareStreakToMax,
};

void CallRestrictedSparringFunc(void)
{
    sRestrictedSparringFuncs[gSpecialVar_0x8004]();
}

static void InitSparringChallenge(void)
{
    FlagClear(FLAG_SPARRING_FIRST_TYPE_WIN);
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    VarSet(VAR_RESTRICTEDSPARRING_HEAL_COUNT,SPARRING_MAX_NUM_RESTORE);

    gTrainerBattleOpponent_A = 0;
}

static void GetSparringData(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
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
    switch (gSpecialVar_0x8005)
    {
    case SPARRING_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    }
}

static void SetSparringBattleWon(void)
{
    u8 numWins = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    gSaveBlock2Ptr->frontier.curChallengeBattleNum = (numWins == MAX_SPARRING_STREAK) ? numWins : ++numWins;

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

    if (oldStreak < SPARRING_REWARD_BONUS_ROUND)
        if (currentStreak >= SPARRING_REWARD_BONUS_ROUND)
            FlagSet(FLAG_SPARRING_FIRST_TYPE_WIN);

#ifdef RESTRICTED_SPARRING_MONS
    SaveCurrentParty(typeMode,lvlMode);
}

static void SaveCurrentParty(u32 typeMode, u8 lvlMode)
{
    u32 i;
    u32 species;
    u32 personality;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] == 0)
            break;

        species = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_SPECIES, NULL);
        personality = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_PERSONALITY, NULL);

        SPARRING_SAVEDATA[lvlMode][typeMode].sparringMon[i].species = species;
        SPARRING_SAVEDATA[lvlMode][typeMode].sparringMon[i].personality = personality;
    }
#endif
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
    u32 i;
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
    u32 i, j, k;
    u16 monId;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;

        if (monId >= PARTY_SIZE)
            continue;

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

    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN,CountDigits(points));

    gSaveBlock2Ptr->frontier.cardBattlePoints += ((points > USHRT_MAX) ? USHRT_MAX: points);
    gSaveBlock2Ptr->frontier.battlePoints += ((points > MAX_BATTLE_FRONTIER_POINTS) ? MAX_BATTLE_FRONTIER_POINTS : points);
}

bool32 Sparring_CheckIfPartyMonMatchesType(struct Pokemon *mon)
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

static u32 CountNumberTypeWin(u8 lvlMode)
{
    u32 i, numWins = 0;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) >= SPARRING_MIN_STREAK)
            numWins++;

    return numWins;
}

static u32 GetNumberTypeWinFromSaveblock(void)
{
    return CountNumberTypeWin(gSaveBlock2Ptr->frontier.lvlMode);
}

static void CheckSparringSymbol(void)
{
    u32 numWins = GetNumberTypeWinFromSaveblock();
    u8 numDigits = CountDigits(numWins);
    u32 hasSilver = FlagGet(FLAG_SYS_ARENA_SILVER);
    u32 hasGold = FlagGet(FLAG_SYS_ARENA_GOLD);
    bool32 shouldGetGold = (numWins == (NUMBER_OF_MON_TYPES - 1));
    bool32 shouldGetSilver = (numWins == ((NUMBER_OF_MON_TYPES - 1) /2));

    ConvertIntToDecimalStringN(gStringVar1, numWins, STR_CONV_MODE_LEFT_ALIGN, numDigits);

    if (shouldGetGold && !hasGold)
        gSpecialVar_Result = SPARRING_GET_GOLD;
    else if (shouldGetSilver && !hasSilver)
        gSpecialVar_Result = SPARRING_GET_SILVER;
    else
        gSpecialVar_Result = SPARRING_GET_NONE;
}

u32 Sparring_SetChallengeNumToMax(u8 challengeNum)
{
    return (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_SPARRING) ? UCHAR_MAX : challengeNum;
}

static u8 ConvertMenuInputToType(u8 selection)
{
    return (selection > TYPE_STEEL) ? ++selection : selection;
}

static void ConvertMenuInputToTypeAndSetVar(void)
{
    VarSet(VAR_SPARRING_TYPE,ConvertMenuInputToType(gSpecialVar_Result));
}

void Sparring_ShowWinsWindow(void)
{
    //ShowRestrictedSparringMarkWindow();
    ShowRestrictedSparringTypeWinsWindow();
#ifdef RESTRICTED_SPARRING_MONS
    InitRestrictedSparringMons();
    ShowRestrictedSparringTypeMonsWindow();
#endif
}

void Sparring_CloseWindsWindow(void)
{
    //CloseRestrictedSparringMarkWindow();
    CloseRestrictedSparringTypeWinsWindow();
#ifdef RESTRICTED_SPARRING_MONS
    CloseRestrictedSparringTypeMonsWindow();
#endif
}

static void ShowRestrictedSparringTypeWinsWindow(void)
{
    sRestrictedSparring_TypeWinsWindowId = AddWindow(&sRestrictedSparring_TypeWinsWindowTemplate);
    SetStandardWindowBorderStyle(sRestrictedSparring_TypeWinsWindowId, FALSE);
    PutWindowTilemap(sRestrictedSparring_TypeWinsWindowId);
    CopyWindowToVram(sRestrictedSparring_TypeWinsWindowId, COPYWIN_GFX);
}

static void CloseRestrictedSparringTypeWinsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sRestrictedSparring_TypeWinsWindowId, TRUE);
    RemoveWindow(sRestrictedSparring_TypeWinsWindowId);
}

static void ShowRestrictedSparringTypeMonsWindow(void)
{
    sRestrictedSparring_TypeMonsWindowId = AddWindow(&sRestrictedSparring_TypeMonsWindowTemplate);
    SetStandardWindowBorderStyle(sRestrictedSparring_TypeMonsWindowId, FALSE);
    PutWindowTilemap(sRestrictedSparring_TypeMonsWindowId);
    CopyWindowToVram(sRestrictedSparring_TypeMonsWindowId, COPYWIN_GFX);
}

static void CloseRestrictedSparringTypeMonsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sRestrictedSparring_TypeMonsWindowId, TRUE);
    RemoveWindow(sRestrictedSparring_TypeMonsWindowId);
}

void FillRestrictedSparringWinWindow(u16 selection)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 typeMode = ConvertMenuInputToType(selection);
    u32 num = SPARRING_SAVEDATA[typeMode][lvlMode].winStreak;
    u32 width = GetWindowAttribute(sRestrictedSparring_TypeWinsWindowId, WINDOW_WIDTH) * 8;
    u32 height = GetWindowAttribute(sRestrictedSparring_TypeWinsWindowId, WINDOW_HEIGHT) * 8;

    FillWindowPixelBuffer(sRestrictedSparring_TypeWinsWindowId,PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, CountDigits(MAX_SPARRING_STREAK));
    StringExpandPlaceholders(gStringVar2,gText_WinStreak);

    if (typeMode == NUMBER_OF_MON_TYPES)
        StringCopy(gStringVar2,gText_Blank);

    AddTextPrinterParameterized2(sRestrictedSparring_TypeWinsWindowId, FONT_NORMAL, gStringVar2, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
}

void FillRestrictedSparringTypeMons(u16 typeMode)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 priority = 0;
    u32 species, personality, index;
    s32 x = (GetWindowAttribute(sRestrictedSparring_TypeMonsWindowId, WINDOW_TILEMAP_LEFT) * SPARRING_TILES) + SPARRING_TYPE_MON_X_OFFSET;
    u32 y = (GetWindowAttribute(sRestrictedSparring_TypeMonsWindowId, WINDOW_TILEMAP_TOP) * SPARRING_TILES) + SPARRING_TILES;

    for (index = 0; index < FRONTIER_PARTY_SIZE; index++)
    {
        species = SPARRING_SAVEDATA[lvlMode][typeMode].sparringMon[index].species;
        if (species == SPECIES_NONE)
            continue;

        x += SPARRING_TYPE_MON_ICON_SIZE;
        personality = SPARRING_SAVEDATA[lvlMode][typeMode].sparringMon[index].personality;

        LoadMonIconPalette(species);
        sScrollableMultichoice_MonIconId[index] = CreateMonIcon(species,SpriteCallbackDummy,x,y,priority,personality,FALSE);
        gSprites[sScrollableMultichoice_MonIconId[index]].oam.priority = priority;
    }
}

void Sparring_DestroyMonIconFreeResources(u16 menu)
{
    u32 i = 0;

    if (menu != SCROLL_MULTI_POKEMON_TYPE)
        return;

    FreeMonIconPalettes();
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        DestroySpriteAndFreeResources(&gSprites[sScrollableMultichoice_MonIconId[i]]);
}

static void InitRestrictedSparringMons(void)
{
    u32 i = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        sScrollableMultichoice_MonIconId[i] = 0;
}

static void SparringPrintTypesMastered(u8 lvlMode, u8 x, u8 y)
{
    PrintSparringStreak(gText_TypesMastered, CountNumberTypeWin(lvlMode), x, y);
}

static u32 GetBestTypeWinAmount(u8 lvlMode)
{
    u32 i;
    u32 biggestWins = SPARRING_SAVEDATA[0][lvlMode].winStreak;

    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) > biggestWins)
            biggestWins = (SPARRING_SAVEDATA[i][lvlMode].winStreak);

    return biggestWins;
}

static const u8 *GetBestTypeWinType(u8 lvlMode)
{
    u32 type = 0, i = 0;
    u32 biggestWins = SPARRING_SAVEDATA[0][lvlMode].winStreak;

    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
    {
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) > biggestWins)
        {
            biggestWins = (SPARRING_SAVEDATA[i][lvlMode].winStreak);
            type = i;
        }
    }
    return gTypeNames[type];
}

static void SparringPrintBestStreak(u8 lvlMode, u8 x, u8 y)
{
    StringCopy(gStringVar2,GetBestTypeWinType(lvlMode));
    PrintSparringStreak(gText_BestStreak,GetBestTypeWinAmount(lvlMode),x,y);
}

static void PrintSparringStreak(const u8 *str, u16 num, u8 x, u8 y)
{
    if (num > MAX_SPARRING_STREAK)
        num = MAX_SPARRING_STREAK;

    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, CountDigits(MAX_SPARRING_STREAK));
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x, y, TEXT_SKIP_DRAW, NULL);
}

void Sparring_ShowResultsWindow(void)
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

    StringExpandPlaceholders(gStringVar4, gText_RestrictedSparringResults);
    PrintAligned(gStringVar4, SPARRING_RECORD_HEADER_HEIGHT);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, SPARRING_RECORD_LEVEL_HEADER_X_POS, SPARRING_RECORD_50_LEVEL_Y_POS, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, SPARRING_RECORD_LEVEL_HEADER_X_POS, SPARRING_RECORD_OPEN_LEVEL_Y_POS, TEXT_SKIP_DRAW, NULL);

    PrintHyphens(10);

    SparringPrintBestStreak(FRONTIER_LVL_50,SPARRING_RECORD_DATA_X_POS,SPARRING_RECORD_50_LEVEL_Y_POS);
    SparringPrintTypesMastered(FRONTIER_LVL_50,SPARRING_RECORD_DATA_X_POS,SPARRING_RECORD_50_LEVEL_BEST_Y_POS);
    SparringPrintBestStreak(FRONTIER_LVL_OPEN, SPARRING_RECORD_DATA_X_POS, SPARRING_RECORD_OPEN_LEVEL_Y_POS);
    SparringPrintTypesMastered(FRONTIER_LVL_OPEN, SPARRING_RECORD_DATA_X_POS, SPARRING_RECORD_OPEN_LEVEL_BEST_Y_POS);

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

static void CompareStreakToMax(void)
{
    gSpecialVar_Result = FALSE;

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum != MAX_SPARRING_STREAK)
        return;

    ConvertIntToDecimalStringN(gStringVar1,MAX_SPARRING_STREAK,STR_CONV_MODE_LEFT_ALIGN,CountDigits(MAX_SPARRING_STREAK));
    gSpecialVar_Result = TRUE;
}

void Sparring_FillWindows(u16 selection)
{
    //FillRestrictedSparringMarkWindow(selection);
    FillRestrictedSparringWinWindow(selection);
#ifdef RESTRICTED_SPARRING_MONS
    FillRestrictedSparringTypeMons(selection);
    return;
#endif
}

/*
void ShowRestrictedSparringMarkWindow()
{
    sRestrictedSparring_MarkWindowId = AddWindow(&sRestrictedSparring_MarkWindowTemplate);
    PutWindowTilemap(sRestrictedSparring_MarkWindowId);
    CopyWindowToVram(sRestrictedSparring_MarkWindowId, COPYWIN_GFX);
}

void CloseRestrictedSparringMarkWindow(void)
{
    //ClearStdWindowAndFrameToTransparent(sRestrictedSparring_MarkWindowId, TRUE);
    RemoveWindow(sRestrictedSparring_MarkWindowId);
}


void FillRestrictedSparringMarkWindow(u16 selection)
{
    u8 i;
    u32 y = 0;

    for (i;i < MAX_SCROLL_MULTI_ON_SCREEN ; i ++)
    {
        AddTextPrinterParameterized3(sRestrictedSparring_MarkWindowId, FONT_NORMAL, 10, y, 0, TEXT_SKIP_DRAW,gText_SelectorArrow2);
        y += 8;

    }
}
*/
