#include "global.h"
#include "battle.h"
#include "battle_arcade.h"
#include "battle_dome.h"
#include "battle_pike.h"
#include "battle_records.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_transition.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/battle_arcade.h"
#include "constants/battle_frontier.h"
#include "constants/field_specials.h"
#include "constants/frontier_util.h"
#include "constants/hold_effects.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "constants/weather.h"

// Arcade Challenge Functions
void CallBattleArcadeFunc(void);
static void InitArcadeChallenge(void);
static void ResetCursorPositionOnSaveblock(void);
static void ResetCursorSpeed(void);
static void TakePlayerHeldItems(void);
static void GenerateItemsToBeGiven(void);
static u32 GenerateItemOrBerry(u32);
static void GetArcadeData(void);
static u16 GetCurrentArcadeWinStreak(void);
static void SetArcadeData(void);
static void SetArcadeBattleWon(void);
static void IncrementCurrentArcadeWinStreak(void);
static void SaveCurrentArcadeWinStreak(void);
static void SaveArcadeChallenge(void);
static void GiveBattlePointsForChallenge(void);
static u32 CalculateBattlePoints(u32);
static void GiveBattlePoints(u32);
static void BufferEarnedArcadePrint(void);
static u32 GetEarnedArcadePrint(void);
static bool32 ShouldGetGoldPrint(u32);
static bool32 ShouldGetSilverPrint(u32);
static bool32 ShouldGetPrint(u32, u32, u32);
static void TakeEnemyHeldItems(void);
static void GetArcadeBrainStatus(void);
static void CleanUpAfterArcadeBattle(void);
static void StartArcadeGameFromOverworld(void);
static void FillArcadeTrainerParty(void);
void ConvertFacilityFromArcadeToPike(u32*);
u32 GetArcadePrintCount(void);
static void SetArcadeBrainObjectEvent(void);
static void BufferPrintFromCurrentArcadeWinStreak(void);
static u32 GetPrintFromCurrentArcadeWinStreak(void);
static void ShowArcadeRecordsFromOverworld(void);
void DoArcadeTrainerBattle(void);
static void SetArcadeBattleFlags(void);

// Arcade Game Board Front End
static bool32 BattleArcade_AllocTilemapBuffers(void);
static void CalculateTilePosition(u32, u32*, u32*);
static u32 CreateCountdownPanel(u32, u32);
static u8 CreateEventSprite(u32, u32, u32);
static void CreateGameBoardCursor(void);
static void DestroyCountdownPanels(void);
static void DestroyEventSprites(void);
static void GameBoard_FadeAndBail(void);
static void GameBoard_FreeResources(void);
static void GameBoard_Init(MainCallback);
static bool8 GameBoard_InitBgs(void);
static void GameBoard_InitWindows(void);
static bool8 GameBoard_LoadGraphics(void);
static void GameBoard_MainCB(void);
static void GameBoard_SetupCB(void);
static void GameBoard_VBlankCB(void);
static u32 GetCursorPosition(void);
static u32 GetCursorSpeed(void);
static void SetCursorSpeed(u32);
static const u32* GetEventGfx(u32);
static u32 GetGameBoardMode(void);
static const u8 *GetHelpBarText(void);
static u32 GetHorizontalPositionFromSide(u32);
static void Task_GameBoardMainInput(u8);
static void Task_GameBoardWaitFadeAndBail(u8);
static void Task_GameBoardWaitFadeAndExitGracefully(u8);
static void Task_GameBoardWaitFadeIn(u8);
static void Task_GameBoard_CleanUp(u8);
static void Task_GameBoard_Countdown(u8);
static void Task_GameBoard_Game(u8);
static const u16 GetTileTag(u32);
static void IncrementCursorPosition(void);
static void SpriteCB_Cursor(struct Sprite*);
static void SpriteCB_GameBoardCursorPosition(struct Sprite*);
static void LoadTileSpriteSheets(void);
static void SetCursorPosition(u32);
static void SetScheduleShowBgs(u32);
static bool32 ShouldCursorMove(u32);
static void StartCountdown(void);
static void StartGame(void);
static void Task_OpenGameBoard(u8);

// Arcade Game Board Back End Init
static u32 ConvertBattlesToImpactIndex(void);
static u32 GenerateEvent(u32);
static void GenerateGameBoard(void);
static u32 GenerateImpact(void);
static u32 GenerateRandomBetweenBounds(u32);
static const u32 (*GetCategoryGroups(u32))[ARCADE_BERRY_GROUP_SIZE];
static u32 GetCategorySize(u32);
static u32 GetChallengeNum(void);
static u32 GetChallengeNumIndex(void);
static u32 GetGroupIdFromWinStreak(void);
static s32 GetPanelLowerBound(u32);
static s32 GetPanelUpperBound(u32);
static void InitRecordsWindow(void);
static bool32 IsEventBanned(u32);
static bool32 IsEventValidDuringBattleOrStreak(u32, u32);
static bool32 IsEventValidDuringCurrentBattle(u32);
static bool32 IsEventValidDuringCurrentStreak(u32);
static void HandleAndShowBgs(void);
static void HandleFinishMode();
static void PopulateCountdownSprites(void);
static void PopulateEventSprites(void);
static void PrintEnemyParty(void);
static void PrintHelpBar(void);
static void PrintPartyIcons(u32);
static void PrintPlayerParty(void);
static void InitCursorPositionFromSaveblock(void);
static u32 ReturnCursorWait(u32);
static void SaveCursorPositionToSaveblock(void);
static void SelectGameBoardSpace(u32*, u32*);

// Arcade Game Board Back End Resolve
static void ResetCursorRandomFlag(void);
static u32 CalculateAndSaveNewLevel(u32);
static bool32 DoGameBoardResult(u32, u32);
static void FloodGameBoard(u32, u32);
static bool32 BattleArcade_ChangeSpeed(u32);
static bool32 BattleArcade_DoBurn(u32);
static bool32 BattleArcade_DoFog(void);
static bool32 BattleArcade_DoFreeze(u32);
static bool32 BattleArcade_DoGive(u32, u32);
static bool32 BattleArcade_DoGiveBPBig(void);
static bool32 BattleArcade_DoGiveBPSmall(void);
static bool32 BattleArcade_DoGiveBerry(u32);
static bool32 BattleArcade_DoGiveItem(u32);
static bool32 BattleArcade_DoHail(void);
static bool32 BattleArcade_DoLevelUp(u32);
static bool32 BattleArcade_DoLowerHP(u32);
static bool32 BattleArcade_DoNoBattle(void);
static bool32 BattleArcade_DoNoEvent(void);
static bool32 BattleArcade_DoParalyze(u32);
static bool32 BattleArcade_DoPoison(u32);
static bool32 BattleArcade_DoRain(void);
static bool32 BattleArcade_DoSand(void);
static bool32 BattleArcade_DoSleep(u32);
static bool32 BattleArcade_DoSpeedDown(void);
static bool32 BattleArcade_DoSpeedUp(void);
static bool32 BattleArcade_DoStatusAilment(u32, u32);
static bool32 BattleArcade_DoSun(void);
static bool32 BattleArcade_DoSwap(void);
static bool32 BattleArcade_DoTrickRoom(void);
static void BattleArcade_DoWeather(u32);
static void HandleGameBoardResult(u32, u32);
static bool32 HasMove(struct Pokemon*, u16);
static bool32 HaveMonsBeenSwapped(void);
static void ResetSketchedMoves(void);
static void ResetWeatherPostBattle(void);
static bool32 IsStatusSleepOrFreeze(u32);
static void InitalizePartyIndex(u32*);
static struct Pokemon *LoadSideParty(u32);
static void ResetLevelsToOriginal(void);
static void ReturnPartyToOwner(void);
static void ShufflePartyIndex(u32*);
static void StoreEventToVar(u32);
static void StoreImpactedSideToVar(u32);
static void BufferImpactedName(u8*, u32);
static void BufferGiveString(u32);
static u32 GetImpactedTrainerId(u32);

// Arcade Records Window
static const u8 *BattleArcade_GenerateRecordName(void);
static const u8 *BattleArcade_GetLevelText(u32);
static const u8 *BattleArcade_GetRecordHeaderName(u32, u32);
static const u8 *BattleArcade_GetRecordName(void);
static void CB2_ShowRecords(void);
static u32 CalculateRecordRowYPosition(u32);
static void DisplayRecordsText(void);
static void GenerateRecordText(void);
static void PrintRecord(u32, u32, u32, u32, u8*, u32, u32, u32, u32);
static void PrintRecordHeader(u32, u32, u32, u32, u8*, u32, u32, u32, u32);
static void PrintRecordHeaderLevelRecord(u32, u32, u32, u32, u8*, u32, u32, u32, u32);
static void PrintRecordLevelMode(u32, u32, u32, u32, u8*, u32, u32, u32, u32);
static void HandleHeader(u32, u32, u32, u32, u8*, u32, u32);
static void HandleRecord(u32, u32, u32, u32, u8*, u32, u32);
static void Task_RecordsFadeIn(u8);
static void Task_RecordsFadeOut(u8);
static void Task_RecordsWaitForKeyPress(u8);
static u32 GetRecordValue(u32, u32);
static void InitRecordsBg(void);
static void MainCB2(void);
static void VBlankCB(void);

#ifdef BATTLE_ARCADE

static void (* const sBattleArcadeFuncs[])(void) =
{
	[ARCADE_FUNC_INIT]                   = InitArcadeChallenge,
	[ARCADE_FUNC_GET_DATA]               = GetArcadeData,
	[ARCADE_FUNC_SET_DATA]               = SetArcadeData,
	[ARCADE_FUNC_SET_BATTLE_WON]         = SetArcadeBattleWon,
	[ARCADE_FUNC_SAVE]                   = SaveArcadeChallenge,
	[ARCADE_FUNC_GIVE_BATTLE_POINTS]     = GiveBattlePointsForChallenge,
	[ARCADE_FUNC_CHECK_SYMBOL]           = BufferEarnedArcadePrint,
	[ARCADE_FUNC_TAKE_ENEMY_ITEMS]       = TakeEnemyHeldItems,
	[ARCADE_FUNC_CHECK_BRAIN_STATUS]     = GetArcadeBrainStatus,
	[ARCADE_FUNC_EVENT_CLEAN_UP]         = CleanUpAfterArcadeBattle,
	[ARCADE_FUNC_PLAY_GAME_BOARD]        = StartArcadeGameFromOverworld,
	[ARCADE_FUNC_GENERATE_OPPONENT]      = FillArcadeTrainerParty,
	[ARCADE_FUNC_SET_BRAIN_OBJECT]       = SetArcadeBrainObjectEvent,
	[ARCADE_FUNC_GET_PRINT_FROM_STREAK]  = BufferPrintFromCurrentArcadeWinStreak,
	[ARCADE_FUNC_RECORDS]                = ShowArcadeRecordsFromOverworld
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

	ResetCursorPositionOnSaveblock();
    ResetCursorSpeed();
    ResetFrontierTrainerIds();
	TakePlayerHeldItems();
	GenerateItemsToBeGiven();
    FlagSet(FLAG_HIDE_BATTLE_TOWER_OPPONENT);

    if (!(FRONTIER_SAVEDATA.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
        ARCADE_CURRENT_STREAK_WINS[battleMode][lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void ResetCursorPositionOnSaveblock(void)
{
    FRONTIER_SAVEDATA.arcadeCursorPosition = 0;
}

static void ResetCursorSpeed(void)
{
	ARCADE_CURSOR.speed = ARCADE_SPEED_DEFAULT;
}

static void TakePlayerHeldItems(void)
{
    BattleArcade_DoGive(ARCADE_IMPACT_PLAYER, ITEM_NONE);
}

static void GenerateItemsToBeGiven(void)
{
    VarSet(VAR_ARCADE_BERRY,GenerateItemOrBerry(ARCADE_EVENT_GIVE_BERRY));
    VarSet(VAR_ARCADE_ITEM,GenerateItemOrBerry(ARCADE_EVENT_GIVE_ITEM));
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
        gSpecialVar_Result = GetCurrentArcadeWinStreak();
        break;
    case ARCADE_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = (!(FRONTIER_SAVEDATA.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]));
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

static void IncrementCurrentArcadeWinStreak(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = (VarGet(VAR_FRONTIER_BATTLE_MODE));
	u32 currentWinStreak = ARCADE_CURRENT_STREAK_WINS[battleMode][lvlMode];

	if (currentWinStreak < MAX_STREAK)
		ARCADE_CURRENT_STREAK_WINS[battleMode][lvlMode]++;
}

static void SetArcadeBattleWon(void)
{
	u32 i;

	//for (i = 0; i < 4; i++)
	//{
		IncrementCurrentArcadeWinStreak();
		SaveCurrentArcadeWinStreak();
	//}
		gSpecialVar_Result = ++FRONTIER_SAVEDATA.curChallengeBattleNum;
}

u16 GetCurrentArcadeWinStreak(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u32 battleMode = (VarGet(VAR_FRONTIER_BATTLE_MODE));
    u32 winStreak = ARCADE_CURRENT_STREAK_WINS[battleMode][lvlMode];

    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}


static void SaveCurrentArcadeWinStreak(void)
{
    u8 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 oldStreak = ARCADE_RECORDED_WINS[battleMode][lvlMode];
    u32 currentStreak = GetCurrentArcadeWinStreak();

    if (oldStreak >= currentStreak)
        return;

	ARCADE_RECORDED_WINS[battleMode][lvlMode] = currentStreak;
}

static void SaveArcadeChallenge(void)
{
    u16 lvlMode = FRONTIER_SAVEDATA.lvlMode;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
	s32 challengeNum = (signed)(ARCADE_CURRENT_STREAK_WINS[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE);

    FRONTIER_SAVEDATA.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_FACILITY_CHALLENGE_STATUS, 0);
    FRONTIER_SAVEDATA.challengePaused = TRUE;
    SaveGameFrontier();
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
    if (challengeNum != 0)
        challengeNum--;

    if (challengeNum >= maxChallengeNum)
        challengeNum = (maxChallengeNum - 1);

	return (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN) ? ARCADE_BRAIN_DEFEAT_POINTS : sArcadeBattlePointAwards[challengeNum][VarGet(VAR_FRONTIER_BATTLE_MODE)];
}

static void GiveBattlePointsForChallenge(void)
{
	u32 points = CalculateBattlePoints(((ARCADE_CURRENT_STREAK_WINS[VarGet(VAR_FRONTIER_BATTLE_MODE)][FRONTIER_SAVEDATA.lvlMode]) / FRONTIER_STAGES_PER_CHALLENGE));
    GiveBattlePoints(points);
}

static void GiveBattlePoints(u32 points)
{
    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar3, points, STR_CONV_MODE_LEFT_ALIGN,CountDigits(points));

    FRONTIER_SAVEDATA.cardBattlePoints += ((points > USHRT_MAX) ? USHRT_MAX: points);
    FRONTIER_SAVEDATA.battlePoints += ((points > MAX_BATTLE_FRONTIER_POINTS) ? MAX_BATTLE_FRONTIER_POINTS : points);
}

static void BufferPrintFromCurrentArcadeWinStreak(void)
{
	gSpecialVar_Result = GetPrintFromCurrentArcadeWinStreak();
}

static u32 GetPrintFromCurrentArcadeWinStreak(void)
{
	switch(GetCurrentArcadeWinStreak())
	{
		case (ARCADE_SILVER_BATTLE_NUMBER - 1):
			return ARCADE_SYMBOL_SILVER;
		case (ARCADE_GOLD_BATTLE_NUMBER - 1):
			return ARCADE_SYMBOL_GOLD;
		default:
			return ARCADE_SYMBOL_NONE;
	}
}

static void BufferEarnedArcadePrint(void)
{
    gSpecialVar_Result = GetEarnedArcadePrint();
}

static u32 GetEarnedArcadePrint(void)
{
    u32 numWins = (GetCurrentArcadeWinStreak());

    if (ShouldGetGoldPrint(numWins))
        return ARCADE_SYMBOL_GOLD;
    else if (ShouldGetSilverPrint(numWins))
        return ARCADE_SYMBOL_SILVER;
    else
        return ARCADE_SYMBOL_NONE;
}

static bool32 ShouldGetGoldPrint(u32 numWins)
{
    return ShouldGetPrint(FLAG_ARCADE_GOLD_PRINT,numWins,ARCADE_GOLD_BATTLE_NUMBER);
}

static bool32 ShouldGetSilverPrint(u32 numWins)
{
    return ShouldGetPrint(FLAG_ARCADE_SILVER_PRINT,numWins,ARCADE_SILVER_BATTLE_NUMBER);
}

static bool32 ShouldGetPrint(u32 print, u32 numWins, u32 battleNum)
{
    if (FlagGet(print))
        return FALSE;

    if (numWins != battleNum)
        return FALSE;

    return TRUE;
}

static void TakeEnemyHeldItems(void)
{
    BattleArcade_DoGive(ARCADE_IMPACT_OPPONENT, ITEM_NONE);
}

static u32 ConvertBattlesToImpactIndex(void)
{
	u16 numBattle = GetCurrentArcadeWinStreak();

	return numBattle <= 4 ? ARCADE_BATTLE_NUM_0_4 :
		numBattle <= 10 ? ARCADE_BATTLE_NUM_5_10 :
		numBattle <= 15 ? ARCADE_BATTLE_NUM_11_15 :
		numBattle <= 20 ? ARCADE_BATTLE_NUM_16_20 :
		ARCADE_BATTLE_NUM_21_PLUS;
}

static const u32 ImpactTable[][ARCADE_IMPACT_COUNT] =
{
    //red、black、white、yellow    //Battles
    { 10, 75, 10,  5 },        //0-4
    { 25, 40, 30,  5 },        //5-10
    { 30, 30, 35,  5 },        //11-15
    { 35, 20, 30, 15 },        //16-20
    { 15, 15, 40, 30 },        //21-
};

static u32 GenerateImpact(void)
{
    u32 impactLine = 0, i = 0;

    for (i = 0; i < ARCADE_IMPACT_COUNT;i++)
    {
        impactLine += ImpactTable[ConvertBattlesToImpactIndex()][i];
        if ((Random () % 100) < impactLine)
			return i;
    }
    return ARCADE_IMPACT_COUNT;
}

static const u32 PanelStreakTable[][ARCADE_STREAK_NUM_COUNT] =
{
    //Streak 1  2  3  4  5  6  7  //Event panels
    //-------------------------------------------------------
    {0, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_LOWER_HP
    {1, 0, 1, 0, 0, 0, 1},      // ARCADE_EVENT_POISON
    {1, 0, 1, 0, 0, 0, 1},      // ARCADE_EVENT_PARALYZE
    {1, 0, 1, 0, 0, 0, 1},      // ARCADE_EVENT_BURN
    {0, 0, 0, 0, 1, 1, 1},      // ARCADE_EVENT_SLEEP
    {0, 0, 0, 0, 1, 1, 1},      // ARCADE_EVENT_FREEZE
    {1, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_GIVE_BERRY
    {0, 0, 0, 1, 1, 1, 1},      // ARCADE_EVENT_GIVE_ITEM
    {0, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_LEVEL_UP
    {0, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_SUN
    {0, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_RAIN
    {0, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_SAND
    {0, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_HAIL
    {0, 0, 0, 1, 0, 1, 1},      // ARCADE_EVENT_FOG
    {0, 0, 0, 1, 0, 1, 1},      // ARCADE_EVENT_TRICK_ROOM
    {1, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_SWAP
    {1, 1, 1, 0, 0, 0, 1},      // ARCADE_EVENT_SPEED_UP
    {1, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_SPEED_DOWN
    {0, 0, 0, 0, 1, 1, 1},      // ARCADE_EVENT_RANDOM
    {0, 0, 0, 1, 1, 1, 1},      // ARCADE_EVENT_GIVE_BP_SMALL
    {0, 0, 0, 0, 1, 1, 1},      // ARCADE_EVENT_NO_BATTLE
    {0, 0, 0, 0, 0, 0, 1},      // ARCADE_EVENT_GIVE_BP_BIG
    {1, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_NO_EVENT
};

static const u32 SpecialPanelTable[][ARCADE_EVENT_SPECIAL_COUNT] =
{
    //Battle 1  2  3  4  5  6  7  //Event panels
    //-------------------------------------------------------
    {1, 1, 1, 1, 1, 1, 0},      // ARCADE_EVENT_SWAP
    {1, 1, 1, 1, 1, 1, 0},      // ARCADE_EVENT_SPEED_UP
    {1, 1, 1, 1, 1, 1, 0},      // ARCADE_EVENT_SPEED_DOWN
    {1, 1, 1, 1, 1, 1, 0},      // ARCADE_EVENT_RANDOM
    {1, 0, 1, 0, 1, 0, 0},      // ARCADE_EVENT_GIVE_BP_SMALL
    {0, 1, 0, 1, 0, 1, 0},      // ARCADE_EVENT_NO_BATTLE
    {0, 1, 0, 1, 0, 1, 0},      // ARCADE_EVENT_GIVE_BP_BIG
    {1, 1, 1, 1, 1, 1, 1},      // ARCADE_EVENT_NO_EVENT
};

static s32 GetPanelUpperBound(u32 impact)
{
    //Not Inclusive
    switch (impact)
    {
        case ARCADE_IMPACT_PLAYER:
        case ARCADE_IMPACT_OPPONENT:
			return ARCADE_EVENT_WEATHER_START;
        case ARCADE_IMPACT_ALL:
			return ARCADE_EVENT_SPECIAL_START;
        default:
        case ARCADE_IMPACT_SPECIAL:
			return ARCADE_EVENT_COUNT;
    }
}

static s32 GetPanelLowerBound(u32 impact)
{
    //Inclusive
    switch (impact)
    {
        case ARCADE_IMPACT_PLAYER:
        case ARCADE_IMPACT_OPPONENT:
			return ARCADE_EVENT_INDIVIDUAL_START;
        case ARCADE_IMPACT_ALL:
			return ARCADE_EVENT_WEATHER_START;
        default:
        case ARCADE_IMPACT_SPECIAL:
			return ARCADE_EVENT_SPECIAL_START;
    }
}

static bool32 IsEventValidDuringCurrentStreak(u32 event)
{
    if (event < ARCADE_EVENT_SPECIAL_START)
        return TRUE;

    if (!PanelStreakTable[event][GetChallengeNumIndex()])
        return FALSE;

    return TRUE;
}

static bool32 IsEventValidDuringCurrentBattle(u32 event)
{
    if (!SpecialPanelTable[event - ARCADE_EVENT_SPECIAL_START][FRONTIER_SAVEDATA.curChallengeBattleNum])
        return FALSE;

    return TRUE;
}

static bool32 IsEventValidDuringBattleOrStreak(u32 event, u32 impact)
{
    if (IsEventBanned(event))
        return FALSE;
    if (!IsEventValidDuringCurrentStreak(event))
	{
		DebugPrintf("IsEventValidDuringCurrentStreak FAIL");
        return FALSE;
	}
    if (!IsEventValidDuringCurrentBattle(event))
	{
		DebugPrintf("IsEventValidDuringCurrentBattle FAIL");
        return FALSE;
}
    return TRUE;
}

static u32 GenerateRandomBetweenBounds(u32 impact)
{
    u32 upper = GetPanelUpperBound(impact);
    u32 lower = GetPanelLowerBound(impact);

    return (lower + Random() % (upper - lower + 1));
}

static u32 GenerateEvent(u32 impact)
{
    u32 event = GenerateRandomBetweenBounds(impact);
	DebugPrintf("GenerateRandomBetweenBounds %d",event);

    do
    {
        event = GenerateRandomBetweenBounds(impact);
    } while (!IsEventValidDuringBattleOrStreak(event,impact));

	DebugPrintf("GenerateRandomBetweenBounds %d",event);

    //DebugPrintf("event original roll is %d",event);
    //return ARCADE_EVENT_GIVE_ITEM; // Debug
    return event;
}

static bool32 HaveMonsBeenSwapped(void)
{
	struct Pokemon *frontierMon;
	struct Pokemon *playerMon;
	u32 playerMonPersonality, frontierMonPersonality, i, monId;

	for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
	{
		monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
		if (monId >= PARTY_SIZE)
			continue;

		frontierMon = &gSaveBlock1Ptr->playerParty[monId];
		playerMon = &gPlayerParty[i];

		playerMonPersonality = GetMonData(playerMon, MON_DATA_PERSONALITY,NULL);
		frontierMonPersonality = GetMonData(frontierMon, MON_DATA_PERSONALITY,NULL);

		if (playerMonPersonality == frontierMonPersonality)
			continue;

		return TRUE;
	}
	return FALSE;
}

static bool32 IsEventBanned(u32 event)
{
#ifndef ARCADE_GEN4_EFFECTS_UNBANNED
    if ((event == ARCADE_EVENT_TRICK_ROOM) || (event == ARCADE_EVENT_FOG))
        return TRUE;
#endif
    return FALSE;
}

struct GameResult
{
    u8 impact:2;
    u8 event:5;
};

static EWRAM_DATA struct GameResult sGameBoard[ARCADE_GAME_BOARD_SPACES] = {0};

static void GenerateGameBoard(void)
{
    u32 i, impact;

    for (i = 0; i < ARCADE_GAME_BOARD_SPACES; i++)
    {
        sGameBoard[i].impact = GenerateImpact();
        sGameBoard[i].event = GenerateEvent(sGameBoard[i].impact);
		DebugPrintf("event generated");

        DebugPrintf("spot %d has impact %d and event %d",i,sGameBoard[i].impact,sGameBoard[i].event);
    }
}

static void FloodGameBoard(u32 impact, u32 event)
{
    u32 i;
    for (i = 0; i < ARCADE_GAME_BOARD_SPACES; i++)
    {
        sGameBoard[i].impact = impact;
        sGameBoard[i].event = event;
    }
}

static void SelectGameBoardSpace(u32 *impact, u32 *event)
{
    u32 space = GetCursorPosition();
    u32 spaceImpact = sGameBoard[space].impact;
    u32 spaceEvent = sGameBoard[space].event;

    if (spaceEvent == ARCADE_EVENT_RANDOM)
    {
        do
        {
            spaceImpact = GenerateImpact();
            spaceEvent = GenerateEvent(spaceImpact);
        } while (spaceEvent == ARCADE_EVENT_RANDOM);
    }

	*impact = spaceImpact;
	*event = spaceEvent;
	*event = ARCADE_EVENT_GIVE_BP_BIG;
    //DebugPrintf("-----------------------");
    //DebugPrintf("Chosen panel %d has impact %d and event %d",space,sGameBoard[space].impact,sGameBoard[space].event);
}

static void HandleGameBoardResult(u32 impact, u32 event)
{
    //DebugPrintf("event from saveblock %d",GAME_BOARD_EVENT);
    //DebugPrintf("impact from saveblock %d",GAME_BOARD_IMPACT);
    LOCAL_VAR_GAME_BOARD_SUCCESS = DoGameBoardResult(event, impact);
    BufferImpactedName(gStringVar1,impact);

	FloodGameBoard(impact,event);
	StoreEventToVar(event);
	StoreImpactedSideToVar(impact);
}

static void StoreEventToVar(u32 event)
{
    LOCAL_VAR_GAME_BOARD_EVENT = event;
}

static void StoreImpactedSideToVar(u32 impact)
{
    LOCAL_VAR_GAME_BOARD_IMPACT = impact;
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
#ifdef ARCADE_GEN4_EFFECTS_UNBANNED
        case ARCADE_EVENT_FOG: return BattleArcade_DoFog();
        case ARCADE_EVENT_TRICK_ROOM: return BattleArcade_DoTrickRoom();
#endif
        case ARCADE_EVENT_SWAP: return BattleArcade_DoSwap();
        case ARCADE_EVENT_SPEED_UP: return BattleArcade_DoSpeedUp();
        case ARCADE_EVENT_SPEED_DOWN: return BattleArcade_DoSpeedDown();
        case ARCADE_EVENT_GIVE_BP_SMALL: return BattleArcade_DoGiveBPSmall();
        case ARCADE_EVENT_GIVE_BP_BIG: return BattleArcade_DoGiveBPBig();
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

static void BufferImpactedName(u8 *dest, u32 impact)
{
	if (impact == ARCADE_IMPACT_PLAYER)
		StringCopy_PlayerName(dest, gSaveBlock2Ptr->playerName);
	else
		GetFrontierTrainerName(dest, GetImpactedTrainerId(impact));
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
    u32 item = VarGet(VAR_ARCADE_BERRY);
    return BattleArcade_DoGive(impact, item);
}

static bool32 BattleArcade_DoGiveItem(u32 impact)
{
    u32 item = VarGet(VAR_ARCADE_ITEM);
    return BattleArcade_DoGive(impact, item);
}

static u32 GetChallengeNum(void)
{
    return (GetCurrentArcadeWinStreak() / FRONTIER_STAGES_PER_CHALLENGE);
}

static u32 GetChallengeNumIndex(void)
{
    u32 challengeNum = GetChallengeNum();

    if (challengeNum > ARCADE_STREAK_NUM_6)
        return ARCADE_STREAK_NUM_6;
    else
        return challengeNum;
}

static u32 GetGroupIdFromWinStreak(void)
{
    u32 challengeNum = GetChallengeNum();

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
            ///////////////////////////////////
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
            ///////////////////////////////////
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
            ITEM_KINGS_ROCK,
            ITEM_QUICK_CLAW,
            ITEM_BRIGHT_POWDER,
            ///////////////////////////////////
            ITEM_FOCUS_BAND,
            ITEM_LEFTOVERS,
        },
        [ARCADE_ITEM_GROUP_2] =
        {
            ITEM_WHITE_HERB,
            ITEM_SHELL_BELL,
            ///////////////////////////////////
            ITEM_SCOPE_LENS,
        },
        [ARCADE_ITEM_GROUP_3] =
        {
            ITEM_FOCUS_BAND,
            ITEM_LEFTOVERS,
            ///////////////////////////////////
            ITEM_SCOPE_LENS,
            ///////////////////////////////////
            ITEM_CHOICE_BAND
        },
    };

    return (type == ARCADE_EVENT_GIVE_ITEM) ? gameItems : gameBerries;
}

static u32 GenerateItemOrBerry(u32 type)
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

static bool32 BattleArcade_DoGive(u32 impact, u32 item)
{
    u32 i;
    struct Pokemon *party = LoadSideParty(impact);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;

        SetMonData(&party[i], MON_DATA_HELD_ITEM, &item);
        //DebugPrintf("slot %d has item %d",i,GetMonData(&party[i],MON_DATA_HELD_ITEM,NULL));
    }
    //DebugPrintf("-----------");

    BufferGiveString(item);
    return TRUE;
}

static u32 CalculateAndSaveNewLevel(u32 origLevel)
{
    u32 newLevel = (origLevel + ARCADE_EVENT_LEVEL_INCREASE);
    return (newLevel >= MAX_LEVEL) ? MAX_LEVEL : newLevel;
}

static bool32 BattleArcade_DoLevelUp(u32 impact)
{
    u32 i, newLevel, oldLevel;
    struct Pokemon *party = LoadSideParty(impact);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (!GetMonData(&party[i], MON_DATA_SANITY_HAS_SPECIES))
            break;

        newLevel = CalculateAndSaveNewLevel(GetMonData(&party[i], MON_DATA_LEVEL));
        SetMonData(&party[i], MON_DATA_LEVEL, &newLevel);
    }
    return TRUE;
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
	return TRUE;
}
static bool32 BattleArcade_DoFog(void)
{
    BattleArcade_DoWeather(WEATHER_FOG_HORIZONTAL);
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

	/*
	 //Debug
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;

        CopyMon(&tempParty[i],&gPlayerParty[i],sizeof(gPlayerParty[i]));
        CopyMon(&gPlayerParty[i],&gEnemyParty[i],sizeof(gEnemyParty[i]));
        CopyMon(&gEnemyParty[i],&tempParty[i],sizeof(tempParty[i]));
    }
	*/
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

static bool32 BattleArcade_ChangeSpeed(u32 mode)
{
    u32 currentSpeed = GetCursorSpeed();
    u32 boundarySpeed = (mode == ARCADE_EVENT_SPEED_UP) ? ARCADE_SPEED_LEVEL_7 : ARCADE_SPEED_LEVEL_0;

    if (currentSpeed == boundarySpeed)
        return TRUE;

    if (mode == ARCADE_EVENT_SPEED_UP)
		currentSpeed++;
    else
		currentSpeed--;

	SetCursorSpeed(currentSpeed);
    return TRUE;
}

static u32 GetCursorSpeed(void)
{
    return ARCADE_CURSOR.speed;
}

static void SetCursorSpeed(u32 speed)
{
	ARCADE_CURSOR.speed = speed;
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
static bool32 BattleArcade_DoGiveBPSmall(void)
{
    GiveBattlePoints(ARCADE_BP_SMALL);
	return TRUE;
}
static bool32 BattleArcade_DoGiveBPBig(void)
{
    GiveBattlePoints(ARCADE_BP_BIG);
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


static void GetArcadeBrainStatus(void)
{
	if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_LINK_MULTIS)
	{
		gSpecialVar_Result = FRONTIER_BRAIN_NOT_READY;
		return;
	}

	BufferPrintFromCurrentArcadeWinStreak();
}

void SetArcadeBattleFlags(void)
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

void FillArcadeTrainerParty(void)
{
    switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
    {
        case FRONTIER_MODE_SINGLES:
        case FRONTIER_MODE_DOUBLES:
            FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
            break;
        case FRONTIER_MODE_LINK_MULTIS:
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.trainerIds[17];
            FillPartnerParty(gPartnerTrainerId);
            break;
    }
}

void DoArcadeTrainerBattle(void)
{
    gBattleScripting.specialTrainerBattleType = SPECIAL_BATTLE_TOWER;

    SetArcadeBattleFlags();
    CreateTask(Task_StartBattleAfterTransition, 1);
    PlayMapChosenOrBattleBGM(0);
    BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
}

static void ResetLevelsToOriginal(void)
{
	struct Pokemon *frontierMon;
	struct Pokemon *playerMon;
	u32 playerMonLevel, frontierMonLevel, i, monId;

	for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
	{
		monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;

		if (monId >= PARTY_SIZE)
			continue;

		frontierMon = &gSaveBlock1Ptr->playerParty[monId];
		playerMon = &gPlayerParty[i];

		playerMonLevel = GetMonData(playerMon, MON_DATA_LEVEL,NULL);
		frontierMonLevel = GetMonData(frontierMon, MON_DATA_LEVEL,NULL);

		if (playerMonLevel == frontierMonLevel)
			continue;

		SetMonData(playerMon, MON_DATA_LEVEL, &frontierMonLevel);
	}
}

static void ReturnPartyToOwner(void)
{
    if (!HaveMonsBeenSwapped())
        return;

    BattleArcade_DoSwap();
}

static void ResetWeatherPostBattle(void)
{
    BattleArcade_DoWeather((gMapHeader.weather));
}

u32 GetArcadePrintCount(void)
{
	return (GetPrintFromCurrentArcadeWinStreak() - 1);
}

void ConvertFacilityFromArcadeToPike(u32* facility)
{
	if (*facility == FRONTIER_FACILITY_ARCADE)
		*facility = FRONTIER_FACILITY_PIKE;
}

void CleanUpAfterArcadeBattle(void)
{
    ResetWeatherPostBattle();
    ReturnPartyToOwner();
    ResetLevelsToOriginal();
	ResetSketchedMoves();
    HealPlayerParty();
}

static void ResetCursorRandomFlag(void)
{
    FlagClear(FLAG_ARCADE_RANDOM_CURSOR);
}

static void SetArcadeBrainObjectEvent(void)
{
    SetFrontierBrainObjEventGfx(FRONTIER_FACILITY_PIKE);
}

bool32 HasMove(struct Pokemon *pokemon, u16 move)
{
	u8 i;

	for (i = 0; i < MAX_MON_MOVES; i++)
		if (GetMonData(pokemon, MON_DATA_MOVE1 + i, NULL) == move)
			return TRUE;

	return FALSE;
}

static void ResetSketchedMoves(void)
{
	u8 i, j;
	struct Pokemon *frontierMon;
	struct Pokemon *playerMon;

	for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
	{
		u32 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;

		if (monId >= PARTY_SIZE)
			continue;

		frontierMon = &gSaveBlock1Ptr->playerParty[monId];
		playerMon = &gPlayerParty[i];

		for (j = 0; j < MAX_MON_MOVES; j++)
		{
			if (HasMove(frontierMon, GetMonData(playerMon, MON_DATA_MOVE1+j, NULL)))
				continue;

			SetMonMoveSlot(playerMon, MOVE_SKETCH, j);
			break;
		}
	}
}

EWRAM_DATA static u8 *sRecordsTilemapPtr = NULL;

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u32 sRecordsTilemap[] = INCBIN_U32("graphics/battle_frontier/arcade_records/arcade_records.bin.lz");
static const u32 sRecordsTiles[] = INCBIN_U32("graphics/battle_frontier/arcade_records/arcade_records.4bpp.lz");

static const u16 sRecordsPalettes[] = INCBIN_U16("graphics/battle_frontier/arcade_records/arcade_records.gbapal");

void CB2_ShowRecords(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadPalette(sRecordsPalettes, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    sRecordsTilemapPtr = Alloc(0x1000);
    InitRecordsBg();
    InitRecordsWindow();
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, &sRecordsTiles, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(sRecordsTilemap, sRecordsTilemapPtr);
    CopyBgTilemapBufferToVram(1);
    DisplayRecordsText();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(MainCB2);
    CreateTask(Task_RecordsFadeIn, 0);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_RecordsFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_RecordsWaitForKeyPress;
}

static void Task_RecordsWaitForKeyPress(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_RecordsFadeOut;
    }
}

static void Task_RecordsFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sRecordsTilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldFadeFromBlack);
    }
}

static const u8 *BattleArcade_GetRecordName(void)
{
	switch(gSpecialVar_0x8006)
	{
		case FRONTIER_MODE_SINGLES:
			return gText_Single2;
		case FRONTIER_MODE_DOUBLES:
			return gText_Double;
		default:
		case FRONTIER_MODE_MULTIS:
			return gText_Multi;
	}
}

static const u8 *BattleArcade_GenerateRecordName(void)
{
	StringCopy(gStringVar3,BattleArcade_GetRecordName());
    StringAppend(gStringVar3,gText_Space);
    StringAppend(gStringVar3,gText_Record);
    return gStringVar3;
}

static void HandleHeader(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 lvlMode)
{
	AddTextPrinterParameterized4(windowId, fontID, 0,ARCADE_RECORD_HEADER_Y_POSITION, letterSpacing, lineSpacing, color, speed, gText_BattleArcade);
	AddTextPrinterParameterized4(windowId, fontID, 122, ARCADE_RECORD_HEADER_Y_POSITION, letterSpacing, lineSpacing, color, speed, BattleArcade_GenerateRecordName());
}

static void HandleRecord(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 mode)
{
	u8 streakStatus;
	u32 streak, recordStreak, lvlMode, streakIndex;
	u32 loopIterations = 0;

	for (lvlMode = 0; lvlMode < FRONTIER_LVL_MODE_COUNT ; lvlMode++)
		for (streakIndex = 0; streakIndex < ARCADE_RECORD_STREAK_INDEX_COUNT; streakIndex++)
			PrintRecordHeaderLevelRecord(windowId, fontID, letterSpacing, lineSpacing, color, speed, streakIndex, lvlMode, loopIterations++);
}

static u32 CalculateRecordRowYPosition(u32 loopIterations)
{
	return (ARCADE_RECORD_ROWS_DEFAULT_Y_POSITION +
			(loopIterations * ARCADE_RECORD_ROWS_MARGIN));
}

static void PrintRecordHeaderLevelRecord(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 streakIndex, u32 lvlMode, u32 loopIterations)
{
	u32 y = CalculateRecordRowYPosition(loopIterations);

	PrintRecordHeader(windowId, fontID, letterSpacing, lineSpacing, color, speed,streakIndex,lvlMode,y);
	PrintRecordLevelMode(windowId, fontID, letterSpacing, lineSpacing, color, speed,streakIndex,lvlMode,y);
	PrintRecord(windowId, fontID, letterSpacing, lineSpacing, color, speed,streakIndex,lvlMode,y);
}

static const u8 *BattleArcade_GetRecordHeaderName(u32 level, u32 streakIndex)
{
	bool32 isStreakActive = ((FRONTIER_SAVEDATA.winStreakActiveFlags & sWinStreakFlags[gSpecialVar_0x8006][level]));

	if (streakIndex == 0 && isStreakActive)
		return gText_Current;
	else if (streakIndex == 0)
		return gText_Prev;
	else
		return gText_Record;
}

static void PrintRecordHeader(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 streakIndex, u32 level, u32 y)
{
	AddTextPrinterParameterized4(windowId, fontID, 0,y, letterSpacing, lineSpacing, color, speed, BattleArcade_GetRecordHeaderName(level, streakIndex));
}

static const u8 *BattleArcade_GetLevelText(u32 level)
{
	if (level == FRONTIER_LVL_50)
		return gText_Lv502;
	else
		return gText_OpenLv;
}

static void PrintRecordLevelMode(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 streakStatus, u32 level, u32 y)
{
	AddTextPrinterParameterized4(windowId, fontID, 45,y, letterSpacing, lineSpacing, color, speed, BattleArcade_GetLevelText(level));
}

static u32 GetRecordValue(u32 level, u32 streakIndex)
{
	u32 mode = gSpecialVar_0x8006;

	if (streakIndex == 0)
		return ARCADE_CURRENT_STREAK_WINS[mode][level];
	else
		return ARCADE_RECORDED_WINS[mode][level];
}

static void PrintRecord(u32 windowId, u32 fontID, u32 letterSpacing, u32 lineSpacing, u8 *color, u32 speed, u32 streakIndex, u32 level, u32 y)
{
	u32 record = GetRecordValue(level, streakIndex);

	ConvertIntToDecimalStringN(gStringVar1,record,STR_CONV_MODE_LEFT_ALIGN,CountDigits(record));
	StringExpandPlaceholders(gStringVar4,gText_GamesWinStreak);
	AddTextPrinterParameterized4(windowId, fontID, 95,y, letterSpacing, lineSpacing, color, speed, gStringVar4);
}

static void GenerateRecordText(void)
{
	u32 windowId = 0;
	u32 fontID = FONT_NORMAL;
	u32 letterSpacing = GetFontAttribute(fontID,FONTATTR_LETTER_SPACING);
	u32 lineSpacing = GetFontAttribute(fontID,FONTATTR_LINE_SPACING);
	u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
	u32 speed = TEXT_SKIP_DRAW;

	HandleHeader(windowId, fontID, letterSpacing, lineSpacing, color, speed,FRONTIER_LVL_OPEN);
	HandleRecord(windowId, fontID, letterSpacing, lineSpacing, color, speed,FRONTIER_LVL_50);
}

static void DisplayRecordsText(void)
{
	GenerateRecordText();
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static const struct BgTemplate sRecordsBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static void InitRecordsBg(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sRecordsBgTemplates, ARRAY_COUNT(sRecordsBgTemplates));
    SetBgTilemapBuffer(1, sRecordsTilemapPtr);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static const struct WindowTemplate sRecordsWinTemplates[2] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 1,
        .width = 26,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

static void InitRecordsWindow(void)
{
    InitWindows(sRecordsWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
}

void ShowArcadeRecordsFromOverworld(void)
{
	u8 taskId;
	//Task_OpenGameBoard(taskId);
    SetMainCallback2(CB2_ShowRecords);
    LockPlayerFieldControls();
}

#include "gba/types.h"
#include "gba/defines.h"
#include "text_window.h"
#include "characters.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "sprite.h"
#include "constants/songs.h"
#include "sound.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"

struct GameBoardState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 gameMode;
    u8 monIconSpriteId[2][MAX_FRONTIER_PARTY_SIZE];
	u16 timer;
	u8 cursorPosition;
	u8 eventIconSpriteId[ARCADE_GAME_BOARD_SPACES];
	u8 countdownPanelSpriteId[ARCADE_GAME_BOARD_SPACES];
};

enum WindowIds
{
	WIN_BOARD_HELP_BAR,
	WIN_BOARD_COUNT,
};

enum BackgroundIds
{
	BG_BOARD_HELP_BAR,
	BG_BOARD_EVENTS,
	BG_BOARD_BACKGROUND,
	BG_BOARD_BACKBOARD,
	BG_BOARD_COUNT,
};

static EWRAM_DATA struct GameBoardState *sGameBoardState = NULL;
static EWRAM_DATA u8 *sBgTilemapBuffer[BG_BOARD_COUNT] = {NULL, NULL, NULL, NULL};

static const u8 sHelpBar_Start[] =  _("{A_BUTTON}    Start Game Board");
static const u8 sHelpBar_Stop[] =  _("{A_BUTTON}    Stop Game Board");

static const struct BgTemplate sGameBoardBgTemplates[] =
{
    {
        .bg = BG_BOARD_HELP_BAR,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = BG_BOARD_EVENTS,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = BG_BOARD_BACKGROUND,
        .charBaseIndex = 6,
        .mapBaseIndex = 29,
        .priority = 4
    },
    {
        .bg = BG_BOARD_BACKBOARD,
        .charBaseIndex = 9,
        .mapBaseIndex = 28,
        .priority = 3
    },
};

static const struct WindowTemplate sGameBoardWinTemplates[] =
{
	[WIN_BOARD_HELP_BAR] =
	{
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 18,
		.width = 30,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 1,
	},
	DUMMY_WIN_TEMPLATE
};

enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
};

static const u8 sGameBoardWindowFontColors[][3] =
{
	[FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
	[FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
};

static const u32 sBackboardTilemap[] = INCBIN_U32("graphics/battle_frontier/arcade_game/backboard.bin.lz");
static const u32 sBackboardTiles[] = INCBIN_U32("graphics/battle_frontier/arcade_game/backboard.4bpp.lz");

static const u32 sLogobackgroundTilemap[] = INCBIN_U32("graphics/battle_frontier/arcade_game/logobackground.bin.lz");
static const u32 sLogobackgroundTiles[] = INCBIN_U32("graphics/battle_frontier/arcade_game/logobackground.4bpp.lz");


static const u32 sCountdownTile1[] = INCBIN_U32("graphics/battle_frontier/arcade_game/countdown_1.4bpp");
static const u32 sCountdownTile2[] = INCBIN_U32("graphics/battle_frontier/arcade_game/countdown_2.4bpp");
static const u32 sCountdownTile3[] = INCBIN_U32("graphics/battle_frontier/arcade_game/countdown_3.4bpp");

static const u32 sEventBurn[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_burn.4bpp.lz");
static const u32 sEventFog[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_fog.4bpp.lz");
static const u32 sEventFreeze[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_freeze.4bpp.lz");
static const u32 sEventGiveBerry[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_give_berry.4bpp.lz");
static const u32 sEventGiveBpBig[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_give_bp_big.4bpp.lz");
static const u32 sEventGiveBpSmall[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_give_bp_small.4bpp.lz");
static const u32 sEventGiveItem[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_give_item.4bpp.lz");
static const u32 sEventHail[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_hail.4bpp.lz");
static const u32 sEventLevelUp[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_level_up.4bpp.lz");
static const u32 sEventLowerHp[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_lower_hp.4bpp.lz");
static const u32 sEventNoBattle[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_no_battle.4bpp.lz");
static const u32 sEventParalyze[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_paralyze.4bpp.lz");
static const u32 sEventPoison[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_poison.4bpp.lz");
static const u32 sEventRain[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_rain.4bpp.lz");
static const u32 sEventRandom[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_random.4bpp.lz");
static const u32 sEventSand[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_sand.4bpp.lz");
static const u32 sEventSleep[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_sleep.4bpp.lz");
static const u32 sEventSpeedDown[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_speed_down.4bpp.lz");
static const u32 sEventSpeedUp[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_speed_up.4bpp.lz");
static const u32 sEventSun[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_sun.4bpp.lz");
static const u32 sEventSwap[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_swap.4bpp.lz");
static const u32 sEventTrickRoom[] = INCBIN_U32("graphics/battle_frontier/arcade_game/event_trick_room.4bpp.lz");
static const u32 sEventNoEvent[] = INCBIN_U32("graphics/battle_frontier/arcade_game/no_event.4bpp.lz");

static const u32 sCursorYellow[] = INCBIN_U32("graphics/battle_frontier/arcade_game/cursor_yellow.4bpp.lz");
static const u32 sCursorOrange[] = INCBIN_U32("graphics/battle_frontier/arcade_game/cursor_orange.4bpp.lz");

static const u8 sText_HelpBarStart[] =_("{A_BUTTON} Start Game");
static const u8 sText_HelpBarFinish[] =_("{A_BUTTON} Select Event");

#define DEFAULT_ANIM  0

static const union AnimCmd sCountdownPanelAnim[] =
{
    ANIMCMD_FRAME(0, ARCADE_BOARD_COUNTDOWN_TIMER),
    ANIMCMD_FRAME(1, ARCADE_BOARD_COUNTDOWN_TIMER),
    ANIMCMD_FRAME(2, ARCADE_BOARD_COUNTDOWN_TIMER+10),
    ANIMCMD_END
};

static const union AnimCmd *const sCountdownAnims[] =
{
    [DEFAULT_ANIM] = sCountdownPanelAnim
};

static const struct SpriteFrameImage sCountdownPanelPicTable[] =
{
    obj_frame_tiles(sCountdownTile3),
    obj_frame_tiles(sCountdownTile2),
    obj_frame_tiles(sCountdownTile1),
};

static const struct OamData CountdownPanelOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct SpriteTemplate sCountdownPanelSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = 0,
    .oam = &CountdownPanelOam,
    .anims = sCountdownAnims,
    .images = sCountdownPanelPicTable,
    .callback = SpriteCallbackDummy,
};

static const u8 *GetHelpBarText(void)
{
	switch (GetGameBoardMode())
	{
		case ARCADE_BOARD_MODE_WAIT:
			return sText_HelpBarStart;
		case ARCADE_BOARD_MODE_GAME_START:
			return sText_HelpBarFinish;
		default:
			return gText_Blank;
	}
}

static void PrintHelpBar(void)
{
    u32 windowId = WIN_BOARD_HELP_BAR;
    u32 fontId = FONT_NARROW;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(windowId, fontId, BAR_LEFT_PADDING, BAR_TOP_PADDING, GetFontAttribute(fontId, FONTATTR_LETTER_SPACING), GetFontAttribute(fontId, FONTATTR_LINE_SPACING), sGameBoardWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, GetHelpBarText());

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void StartArcadeGameFromOverworld(void)
{
    CreateTask(Task_OpenGameBoard, 0);
}

void Task_OpenGameBoard(u8 taskId)
{
	if (gPaletteFade.active)
		return;

	CleanupOverworldWindowsAndTilemaps();
	GameBoard_Init(CB2_ReturnToFieldContinueScript);
	DestroyTask(taskId);
}

void GameBoard_Init(MainCallback callback)
{
    sGameBoardState = AllocZeroed(sizeof(struct GameBoardState));

    if (sGameBoardState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sGameBoardState->loadState = 0;
    sGameBoardState->savedCallback = callback;

    SetMainCallback2(GameBoard_SetupCB);
}

static void GameBoard_SetupCB(void)
{
    u8 taskId;

    switch (gMain.state)
	{
		case 0:
			DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
			SetVBlankHBlankCallbacksToNull();
			ClearScheduledBgCopiesToVram();
			gMain.state++;
			break;
		case 1:
			ScanlineEffect_Stop();
			FreeAllSpritePalettes();
			ResetPaletteFade();
			ResetSpriteData();
			ResetTasks();
			gMain.state++;
			break;
		case 2:
			if (GameBoard_InitBgs())
			{
				sGameBoardState->loadState = 0;
				gMain.state++;
			}
			else
			{
				GameBoard_FadeAndBail();
				return;
			}
			break;
		case 3:
			if (GameBoard_LoadGraphics() == TRUE)
			{
				gMain.state++;
			}
			break;
		case 4:
			GameBoard_InitWindows();
			gMain.state++;
			break;
		case 5:
			GenerateGameBoard();
			FreeMonIconPalettes();
			LoadMonIconPalettes();
			PrintEnemyParty();
			PrintPlayerParty();
			PrintHelpBar();
			taskId = CreateTask(Task_GameBoardWaitFadeIn, 0);
			gMain.state++;
			break;
		case 6:
			BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
			gMain.state++;
			break;
		case 7:
			SetVBlankCallback(GameBoard_VBlankCB);
			SetMainCallback2(GameBoard_MainCB);
			break;
	}
}

static void GameBoard_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void GameBoard_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_GameBoardWaitFadeIn(u8 taskId)
{
    if (gPaletteFade.active)
		return;

	gTasks[taskId].func = Task_GameBoardMainInput;
}

static u32 GetGameBoardMode(void)
{
	return sGameBoardState->gameMode;
}

static void Task_GameBoardMainInput(u8 taskId)
{
    if (!JOY_NEW(A_BUTTON))
		return;

	PlaySE(SE_SELECT);
	switch (GetGameBoardMode())
	{
		case ARCADE_BOARD_MODE_WAIT:
			StartCountdown();
			break;
		case ARCADE_BOARD_MODE_GAME_START:
			HandleFinishMode();
			break;
		default:
			return;
	}
}

static void StartCountdown(void)
{
	HideBg(BG_BOARD_BACKGROUND);
	sGameBoardState->gameMode++;
	sGameBoardState->timer = ARCADE_BOARD_COUNTDOWN_TIMER;
	PopulateCountdownSprites();
	PrintHelpBar();
	CreateTask(Task_GameBoard_Countdown, 0);
}

static void StartGame(void)
{
	sGameBoardState->timer = ARCADE_BOARD_GAME_TIMER;
	InitCursorPositionFromSaveblock();
	CreateGameBoardCursor();
	DestroyCountdownPanels();
	CreateTask(Task_GameBoard_Game, 0);
}

static void PopulateCountdownSprites(void)
{
	u32 space, rowIndex, columnIndex, x, y, spriteId;

    for (space = 0; space < (ARCADE_GAME_BOARD_ROWS * ARCADE_GAME_BOARD_SPACES_PER_ROWS); space++)
	{
		CalculateTilePosition(space,&x,&y);
		sGameBoardState->countdownPanelSpriteId[space] = CreateCountdownPanel(x+12,y+12);
    }
}

static void PopulateEventSprites(void)
{
	u32 space, rowIndex, columnIndex, x, y;

	LoadTileSpriteSheets();

    for (space = 0; space < (ARCADE_GAME_BOARD_ROWS * ARCADE_GAME_BOARD_SPACES_PER_ROWS); space++)
	{
		CalculateTilePosition(space,&x,&y);
		sGameBoardState->eventIconSpriteId[space] = CreateEventSprite(x, y, space);
    }
}

static const u16 GetTileTag(u32 space)
{
	return (sGameBoard[space].event) + ARCADE_GFXTAG_EVENT;
}

static const u32* GetEventGfx(u32 event)
{
	//DebugPrintf("event is %d",event);
	switch (event)
	{
		case ARCADE_EVENT_LOWER_HP: return sEventLowerHp;
		case ARCADE_EVENT_POISON: return sEventPoison;
		case ARCADE_EVENT_PARALYZE: return sEventParalyze;
		case ARCADE_EVENT_BURN: return sEventBurn;
		case ARCADE_EVENT_SLEEP: return sEventSleep;
		case ARCADE_EVENT_FREEZE: return sEventFreeze;
		case ARCADE_EVENT_GIVE_BERRY: return sEventGiveBerry;
		case ARCADE_EVENT_GIVE_ITEM: return sEventGiveItem;
		case ARCADE_EVENT_LEVEL_UP: return sEventLevelUp;
		case ARCADE_EVENT_SUN: return sEventSun;
		case ARCADE_EVENT_RAIN: return sEventRain;
		case ARCADE_EVENT_SAND: return sEventSand;
		case ARCADE_EVENT_HAIL: return sEventHail;
		case ARCADE_EVENT_FOG: return sEventFog;
		case ARCADE_EVENT_TRICK_ROOM: return sEventTrickRoom;
		case ARCADE_EVENT_SWAP: return sEventSwap;
		case ARCADE_EVENT_SPEED_UP: return sEventSpeedUp;
		case ARCADE_EVENT_SPEED_DOWN: return sEventSpeedDown;
		case ARCADE_EVENT_RANDOM: return sEventRandom;
		case ARCADE_EVENT_GIVE_BP_SMALL: return sEventGiveBpSmall;
		case ARCADE_EVENT_NO_BATTLE: return sEventNoBattle;
		case ARCADE_EVENT_GIVE_BP_BIG: return sEventGiveBpBig;
		default:
		case ARCADE_EVENT_NO_EVENT: return sEventNoEvent;
	}
}

static void LoadTileSpriteSheets(void)
{
	u32 i;
	//DebugPrintf("LoadTileSpriteSheets");
	for (i = 0; i < ARCADE_GAME_BOARD_SPACES; i++)
	{
		u16 TileTag = GetTileTag(i);
		const u32 *gfx = GetEventGfx(sGameBoard[i].event);
		struct CompressedSpriteSheet sSpriteSheet_EventSpace = {gfx, 0x0200, TileTag};
		LoadCompressedSpriteSheet(&sSpriteSheet_EventSpace);
		//DebugPrintf("LoadCompressedSpriteSheet tileTag%d",TileTag);
	}
}

static u8 CreateEventSprite(u32 x, u32 y, u32 space)
{
    u32 spriteId;
	u16 TileTag = GetTileTag(space);

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;
    TempSpriteTemplate.tileTag = TileTag;
    TempSpriteTemplate.callback = SpriteCallbackDummy;
	//DebugPrintf("CreateEventSprite %d",TileTag);

    //LoadSpritePalette(&sGlassInterfaceSpritePalette[0]);
    spriteId = CreateSprite(&TempSpriteTemplate,x,y, 0);

    gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x32);
    gSprites[spriteId].oam.size = SPRITE_SIZE(32x32);
    gSprites[spriteId].oam.priority = 0;

	//DebugPrintf("gsprites %d tileNum %d tileTag %d",spriteId,gSprites[spriteId].oam.tileNum,TileTag);

	return spriteId;
}

static void DestroyEventSprites(void)
{
    u32 space;

    for (space = 0; space < ARCADE_GAME_BOARD_SPACES; space++)
    {
        DestroySpriteAndFreeResources(&gSprites[sGameBoardState->eventIconSpriteId[space]]);
        sGameBoardState->eventIconSpriteId[space] = 0;
    }
}
static void DestroyCountdownPanels(void)
{
    u32 space;

    for (space = 0; space < ARCADE_GAME_BOARD_SPACES; space++)
    {
        DestroySpriteAndFreeResources(&gSprites[sGameBoardState->countdownPanelSpriteId[space]]);
        sGameBoardState->countdownPanelSpriteId[space] = 0;
    }
}

static void CalculateTilePosition(u32 space, u32* x, u32* y)
{
	u32 rowIndex = space / ARCADE_GAME_BOARD_SPACES_PER_ROWS;
    u32 columnIndex = space % ARCADE_GAME_BOARD_SPACES_PER_ROWS;
    *x = 50 + columnIndex * 40;
    *y = 10 + rowIndex * 35;
}

static void SpriteCB_Cursor(struct Sprite *sprite)
{
	u32 x, y;
	CalculateTilePosition(GetCursorPosition(),&x,&y);

	sprite->x2 = x - 50;
    sprite->y2 = y - 10;
	sprite->subpriority = 0;
}

static u32 CreateCountdownPanel(u32 x, u32 y)
{
	return CreateSprite(&sCountdownPanelSpriteTemplate, x, y, 0);
}

static void CreateGameBoardCursor(void)
{
	u16 TileTag = ARCADE_GFXTAG_CURSOR;
	u32 spriteId;
	u32 x, y;

	struct CompressedSpriteSheet sSpriteSheet_Cursor = {sCursorYellow, 0x0800, TileTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

	LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);

    TempSpriteTemplate.tileTag = TileTag;
    TempSpriteTemplate.callback = SpriteCB_Cursor;

    spriteId = CreateSprite(&TempSpriteTemplate,45,7, 0);

    gSprites[spriteId].oam.shape = SPRITE_SHAPE(64x64);
    gSprites[spriteId].oam.size = SPRITE_SIZE(64x64);
    gSprites[spriteId].oam.priority = 1;
}

static void Task_GameBoard_Countdown(u8 taskId)
{
	sGameBoardState->timer--;
	//DebugPrintf("timer %d",sGameBoardState->timer);

	switch(sGameBoardState->timer)
	{
		case (ARCADE_FRAMES_PER_SECOND * 2):
		case (ARCADE_FRAMES_PER_SECOND):
			sGameBoardState->gameMode++;
			break;
		case 0:
			sGameBoardState->gameMode++;
			PopulateEventSprites();
			PrintHelpBar();
			StartGame();
			DestroyTask(taskId);
			break;
		default:
			break;
	}
}

static const u32 cursorWaitTable[ARCADE_SPEED_COUNT] =
{
	20,  // ARCADE_SPEED_LEVEL_0
	16,  // ARCADE_SPEED_LEVEL_1
	8,   // ARCADE_SPEED_LEVEL_2
	3,   // ARCADE_SPEED_LEVEL_3
	4,   // ARCADE_SPEED_LEVEL_4 (default)
	2,   // ARCADE_SPEED_LEVEL_5
	1,   // ARCADE_SPEED_LEVEL_6
	0    // ARCADE_SPEED_LEVEL_7
};

u32 ReturnCursorWait(u32 speed)
{
	//return 20; // Debug
    return cursorWaitTable[speed];
}

static bool32 ShouldCursorMove(u32 timer)
{
	u32 cursorWaitValue = ReturnCursorWait(GetCursorSpeed());

	if (cursorWaitValue == 0)
		return TRUE;

	return (timer % cursorWaitValue == 0);
}

static u32 GetCursorPosition(void)
{
	return sGameBoardState->cursorPosition;
}

static void SetCursorPosition(u32 value)
{
	sGameBoardState->cursorPosition = value;
}

static void InitCursorPositionFromSaveblock(void)
{
	sGameBoardState->cursorPosition = FRONTIER_SAVEDATA.arcadeCursorPosition;
}

static void SaveCursorPositionToSaveblock(void)
{
	FRONTIER_SAVEDATA.arcadeCursorPosition = GetCursorPosition();
}

static void IncrementCursorPosition(void)
{
	u32 position;

	if (FlagGet(FLAG_ARCADE_RANDOM_CURSOR))
		position = Random() % ARCADE_GAME_BOARD_SPACES;
	else
		position = GetCursorPosition();

	if ((position+1) >= ARCADE_GAME_BOARD_SPACES)
		SetCursorPosition(0);
	else
		SetCursorPosition(++position);

	//DebugPrintf("mode %d",sGameBoardState->gameMode);
	//DebugPrintf("position %d",sGameBoardState->cursorPosition);
}

static void SpriteCB_GameBoardCursorPosition(struct Sprite *sprite)
{
	u32 position = sGameBoardState->cursorPosition;
}

static void HandleFinishMode()
{
	u32 impact = 0, event = 0;
	sGameBoardState->gameMode++;
	DestroyTask(FindTaskIdByFunc(Task_GameBoard_Game));
	PrintHelpBar();
	SelectGameBoardSpace(&impact,&event);
	HandleGameBoardResult(impact,event);
	SaveCursorPositionToSaveblock();
	ResetCursorRandomFlag();
	DestroyEventSprites();
	PopulateEventSprites();
	sGameBoardState->timer = ARCADE_BOARD_COUNTDOWN_TIMER;
	CreateTask(Task_GameBoard_CleanUp,0);
}

static void Task_GameBoard_Game(u8 taskId)
{
	u32 timer = sGameBoardState->timer;
	//DebugPrintf("timer %d",sGameBoardState->timer);

	if (GetGameBoardMode() > ARCADE_BOARD_MODE_GAME_START)
		HandleFinishMode();
	else if (timer == 0)
		sGameBoardState->gameMode++;
	else if (ShouldCursorMove(timer))
		IncrementCursorPosition();

	sGameBoardState->timer--;
}

static void Task_GameBoard_CleanUp(u8 taskId)
{
	sGameBoardState->timer--;
	//DebugPrintf("timer %d",sGameBoardState->timer);

	if (sGameBoardState->timer != 0)
		return;

	BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);

	gTasks[taskId].func = Task_GameBoardWaitFadeAndExitGracefully;
}

static void Task_GameBoardWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sGameBoardState->savedCallback);
        GameBoard_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_GameBoardWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sGameBoardState->savedCallback);
        GameBoard_FreeResources();
        DestroyTask(taskId);
    }
}

static bool32 BattleArcade_AllocTilemapBuffers(void)
{
	u32 backgroundId;

	for (backgroundId = 0; backgroundId < BG_BOARD_COUNT; backgroundId++)
	{
		sBgTilemapBuffer[backgroundId] = AllocZeroed(TILEMAP_BUFFER_SIZE);

		if (sBgTilemapBuffer[backgroundId] == NULL)
			return FALSE;
	}
	return TRUE;
}

static bool8 GameBoard_InitBgs(void)
{
    ResetAllBgsCoordinates();

	if (!BattleArcade_AllocTilemapBuffers())
		return FALSE;
	HandleAndShowBgs();

    return TRUE;
}

static void GameBoard_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_GameBoardWaitFadeAndBail, 0);

    SetVBlankCallback(GameBoard_VBlankCB);
    SetMainCallback2(GameBoard_MainCB);
}

static bool8 GameBoard_LoadGraphics(void)
{
    switch (sGameBoardState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();

        DecompressAndCopyTileDataToVram(BG_BOARD_BACKBOARD, sBackboardTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOARD_BACKGROUND, sLogobackgroundTiles, 0, 0, 0);
        sGameBoardState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {

            LZDecompressWram(sBackboardTilemap, sBgTilemapBuffer[BG_BOARD_BACKBOARD]);
            LZDecompressWram(sLogobackgroundTilemap, sBgTilemapBuffer[BG_BOARD_BACKGROUND]);
            sGameBoardState->loadState++;
        }
        break;
    case 2:
        //LoadPalette(sGameBoardPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        sGameBoardState->loadState++;
    default:
        sGameBoardState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void GameBoard_InitWindows(void)
{
	u32 windowId;
    InitWindows(sGameBoardWinTemplates);

    DeactivateAllTextPrinters();

    ScheduleBgCopyTilemapToVram(0);

	for (windowId = 0; windowId < WIN_BOARD_COUNT; windowId++)
	{
		FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
		PutWindowTilemap(windowId);
		CopyWindowToVram(windowId, COPYWIN_FULL);
	}
}

static void GameBoard_FreeResources(void)
{
	u32 backgroundId;

	if (sGameBoardState != NULL)
	{
		Free(sGameBoardState);
	}

	for (backgroundId = 0; backgroundId < BG_BOARD_COUNT; backgroundId++)
	{
		if (sBgTilemapBuffer[backgroundId] != NULL)
			Free(sBgTilemapBuffer[backgroundId]);
	}

	FreeAllWindowBuffers();
	ResetSpriteData();
}

static void HandleAndShowBgs(void)
{
	u32 backgroundId;

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sGameBoardBgTemplates, NELEMS(sGameBoardBgTemplates));

	for (backgroundId = 0; backgroundId < BG_BOARD_COUNT; backgroundId++)
		SetScheduleShowBgs(backgroundId);
}

static void SetScheduleShowBgs(u32 backgroundId)
{
	SetBgTilemapBuffer(backgroundId, sBgTilemapBuffer[backgroundId]);
	ScheduleBgCopyTilemapToVram(backgroundId);
	ShowBg(backgroundId);
}

static u32 GetHorizontalPositionFromSide(u32 side)
{
	return (side == ARCADE_IMPACT_OPPONENT) ? 225 : 15;
}

static void PrintPartyIcons(u32 side)
{
	u32 x = GetHorizontalPositionFromSide(side);
	u32 y = 27;
	u32 i;
	struct Pokemon *party = LoadSideParty(side);

	for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
	{
		if (!GetMonData(&party[i], MON_DATA_SANITY_HAS_SPECIES))
			break;

		sGameBoardState->monIconSpriteId[side][i] = CreateMonIcon(GetMonData(&party[i], MON_DATA_SPECIES),SpriteCallbackDummy, x, y, 4, GetMonData(&party[i],MON_DATA_PERSONALITY),FALSE);
		//DebugPrintf("gSprites mon %d",sGameBoardState->monIconSpriteId[side][i]);
		//DebugPrintf("mon gsprites %d tileNum %d",sGameBoardState->monIconSpriteId[side][i],gSprites[sGameBoardState->monIconSpriteId[side[i]].oam.tileNum]);
		gSprites[sGameBoardState->monIconSpriteId[side][i]].oam.priority = 0;
		y += 37;
	}
}

static void PrintEnemyParty(void)
{
	PrintPartyIcons(ARCADE_IMPACT_OPPONENT);
}

static void PrintPlayerParty(void)
{
	PrintPartyIcons(ARCADE_IMPACT_PLAYER);
}

// Arcade Board
// get palettes working
// cursor changes color with every animation
// entire screen is glowing white as its happening
// clean up and refactor battle
// clean up and refactor maps battle
// re-organize battle arcade c into chunks (battles, game board front end, game board back end, records)
// refactor battle arcade c
// get Kura's opinion
// figure out why the cursor feels too fast at default
// add branch tags
// write documentation

#endif
