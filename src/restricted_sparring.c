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

static void (* const sRestrictedSparringFuncs[])(void);
static void RestoreNonConsumableHeldItems(void);
static bool32 IsItemConsumable(u16 item);
static void ResetSketchedMoves(void);
static void GiveBattlePoints(void);
static bool32 IsFirstTypeWin(void);
static void GetFirstTypeWin(void);

static void (* const sRestrictedSparringFuncs[])(void) =
{
    /*
       [SPARRING_FUNC_INIT]                = InitTowerChallenge,
       [SPARRING_FUNC_GET_DATA]            = GetTowerData,
       [SPARRING_FUNC_SET_DATA]            = SetTowerData,
       [SPARRING_FUNC_SET_OPPONENT]        = SetNextFacilityOpponent,
       [SPARRING_FUNC_SET_BATTLE_WON]      = SetTowerBattleWon,
       [SPARRING_FUNC_GIVE_RIBBONS]        = AwardBattleTowerRibbons,
       [SPARRING_FUNC_SAVE]                = SaveTowerChallenge,
       [SPARRING_FUNC_GET_OPPONENT_INTRO]  = GetOpponentIntroSpeech,
       [SPARRING_FUNC_NOP]                 = BattleTowerNop1,
       [SPARRING_FUNC_NOP2]                = BattleTowerNop2,
       [SPARRING_FUNC_LOAD_PARTNERS]       = LoadMultiPartnerCandidatesData,
       [SPARRING_FUNC_PARTNER_MSG]         = ShowPartnerCandidateMessage,
       [SPARRING_FUNC_LOAD_LINK_OPPONENTS] = LoadLinkMultiOpponentsData,
       [SPARRING_FUNC_TRY_CLOSE_LINK]      = TowerTryCloseLink,
       [SPARRING_FUNC_SET_PARTNER_GFX]     = SetMultiPartnerGfx,
       [SPARRING_FUNC_SET_INTERVIEW_DATA]  = SetTowerInterviewData,
       */
    [SPARRING_FUNC_GET_CONTINUE_MENU_TYPE] = GetContinueMenuType,
    [SPARRING_FUNC_RESTORE_HELD_ITEMS]     = RestoreNonConsumableHeldItems,
    [SPARRING_FUNC_RESET_SKETCH_MOVES]     = ResetSketchedMoves,
    [SPARRING_FUNC_GIVE_BATTLE_POINTS]    = GiveBattlePoints,
    [SPARRING_FUNC_GET_FIRST_TYPE_WIN] = GetFirstTypeWin,
};

void CallRestrictedSparringFunc(void)
{
    sRestrictedSparringFuncs[gSpecialVar_0x8004]();
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

static void GetFirstTypeWin(void)
{
    gSpecialVar_Result = !(IsFirstTypeWin());
}

static bool32 IsFirstTypeWin(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 type = TYPE_NORMAL;
    bool32 hasOneWinForType = ((gSaveBlock2Ptr->frontier.restrictedSparring[type][lvlMode].winStreak) == 1);
    u32 currentStreak = gSaveBlock2Ptr->frontier.curChallengeBattleNum++;

    return (hasOneWinForType && currentStreak > 4) ? TRUE : FALSE;
}

static u32 CalculateBattlePoints(u32 numWins)
{
    u32 points, i;
    bool32 isFirstTypeWin = !(IsFirstTypeWin());
    u32 challengeStatus = gSaveBlock2Ptr->frontier.challengeStatus;

    if (numWins == 0)
        return 0;
    if (numWins < SPARRING_REWARD_BONUS_ROUND)
        return (numWins * SPARRING_REWARD_BP);

    if (isFirstTypeWin)
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
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    u32 points = CalculateBattlePoints(GetCurrentBattleTowerWinStreak(lvlMode, battleMode));

    IncrementDailyBattlePoints(points);
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);

    gSaveBlock2Ptr->frontier.cardBattlePoints += ((points > 0xFFFF) ? 0xFFFF : points);
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
