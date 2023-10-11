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
#include "battle_records.h"

#define SPARRING_SAVEDATA gSaveBlock2Ptr->frontier.restrictedSparring
static EWRAM_DATA u8 sRestrictedSparring_TypeWinsWindowId = 0;
static EWRAM_DATA u8 sScrollableMultichoice_ItemSpriteId = 0;

static void (* const sRestrictedSparringFuncs[])(void);
static void InitSparringChallenge(void);
static void GetSparringData(void);
static void SetSparringData(void);
static void SetSparringBattleWon(void);
static void SaveSparringChallenge(void);
static void SaveCurrentStreak(void);
static void GetOpponentIntroSpeech(void);
static void RestoreNonConsumableHeldItems(void);
static bool32 IsItemConsumable(u16 item);
static void ResetSketchedMoves(void);
static void GiveBattlePoints(void);
static bool32 IsFirstTypeWin(void);
static void BufferSparringTypeNameToString(void);
static u32 CountNumberTypeWinFromSaveblock(void);
static void CheckSparringSymbol(void);
static void ShowRestrictedSparringTypeMons(u16 item);
static void SparringPrintStreak(const u8 *str, u16 num, u8 x, u8 y);

#define TAG_ITEM_ICON 5500

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

static u32 CountNumberTypeWin(u8 lvlMode)
{
    u32 i, numWins = 0;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) > (SPARRING_MIN_STREAK - 1))
            numWins++;
    }
    return numWins;
}

static u32 CountNumberTypeWinFromSaveblock(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    return CountNumberTypeWin(lvlMode);
}

static void CheckSparringSymbol(void)
{
    u32 numWins = CountNumberTypeWinFromSaveblock();
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

void ShowRestrictedSparringTypeWinsWindow(void)
{
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

    sRestrictedSparring_TypeWinsWindowId = AddWindow(&sRestrictedSparring_TypeWinsWindowTemplate);
    SetStandardWindowBorderStyle(sRestrictedSparring_TypeWinsWindowId, FALSE);
    CopyWindowToVram(sRestrictedSparring_TypeWinsWindowId, COPYWIN_GFX);
}

void CloseRestrictedSparringTypeWinsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sRestrictedSparring_TypeWinsWindowId, TRUE);
    RemoveWindow(sRestrictedSparring_TypeWinsWindowId);
}
void FillRestrictedSparringWinWindowAndPokemonIcon(u16 selection)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 num = SPARRING_SAVEDATA[selection][lvlMode].winStreak;
    u32 width = GetWindowAttribute(sRestrictedSparring_TypeWinsWindowId, WINDOW_WIDTH);
    u32 height = GetWindowAttribute(sRestrictedSparring_TypeWinsWindowId, WINDOW_HEIGHT);

    FillWindowPixelRect(sRestrictedSparring_TypeWinsWindowId, PIXEL_FILL(1), 0, 0, width, height);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_LEFT_ALIGN, CountDigits(num));
    StringExpandPlaceholders(gStringVar2,gText_WinStreak);
    AddTextPrinterParameterized2(1, FONT_NORMAL, gStringVar2, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    //ShowRestrictedSparringTypeMons(selection);
}

static void ShowRestrictedSparringTypeMons(u16 item)
{
    FreeSpriteTilesByTag(TAG_ITEM_ICON);
    FreeSpritePaletteByTag(TAG_ITEM_ICON);
    //sScrollableMultichoice_ItemSpriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, item);

    if (sScrollableMultichoice_ItemSpriteId != MAX_SPRITES)
    {
        gSprites[sScrollableMultichoice_ItemSpriteId].oam.priority = 0;
        gSprites[sScrollableMultichoice_ItemSpriteId].x = 36;
        gSprites[sScrollableMultichoice_ItemSpriteId].y = 92;
    }
}

static const struct WindowTemplate sFrontierResultsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 18,
    .paletteNum = 15,
    .baseBlock = 1
};

static void SparringPrintTypesMastered(u8 lvlMode, u8 x, u8 y)
{
    u16 numWins = CountNumberTypeWin(lvlMode);
    SparringPrintStreak(gText_TypesMastered, numWins, x, y);
}

static u32 GetBestTypeWinAmount(u8 lvlMode)
{
    u32 i, biggestWins = SPARRING_SAVEDATA[0][lvlMode].winStreak;

    for (i = TYPE_FIGHTING; i < NUMBER_OF_MON_TYPES; i++)
        if ((SPARRING_SAVEDATA[i][lvlMode].winStreak) > biggestWins)
            biggestWins = (SPARRING_SAVEDATA[i][lvlMode].winStreak);

    return biggestWins;
}

static const u8 *GetBestTypeWinType(u8 lvlMode)
{
    u32 type = 0;
    u32 i, biggestWins = SPARRING_SAVEDATA[0][lvlMode].winStreak;

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
    SparringPrintStreak(gText_BestStreak,GetBestTypeWinAmount(lvlMode),x,y);
}

static void SparringPrintStreak(const u8 *str, u16 num, u8 x, u8 y)
{
    if (num > MAX_SPARRING_STREAK)
        num = MAX_SPARRING_STREAK;

    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x, y, TEXT_SKIP_DRAW, NULL);
}

void ShowSparringResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));

    StringExpandPlaceholders(gStringVar4, gText_RestrictedSparringResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);

    PrintHyphens(10);

    SparringPrintBestStreak(FRONTIER_LVL_50,80,49);
    SparringPrintTypesMastered(FRONTIER_LVL_50,80,65);
    SparringPrintBestStreak(FRONTIER_LVL_OPEN, 80,  97);
    SparringPrintTypesMastered(FRONTIER_LVL_OPEN, 80,  113);

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}
