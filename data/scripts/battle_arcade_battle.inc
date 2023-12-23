BattleFrontier_RouletteRoom_EventScript_BeginChallenge::
# 8 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 9 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 10 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 11 "data/scripts/battle_arcade_battle.pory"
	arcade_takeplayerhelditems
# 12 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 13 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber::
# 18 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 19 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 20 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber::
# 25 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 26 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GameNoComeOn, MSGBOX_DEFAULT
# 27 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_PlayGameBoard::
# 32 "data/scripts/battle_arcade_battle.pory"
	additem ITEM_COIN_CASE, 1
# 33 "data/scripts/battle_arcade_battle.pory"
	addcoins 50
# 34 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 35 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 36 "data/scripts/battle_arcade_battle.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 37 "data/scripts/battle_arcade_battle.pory"
	playslotmachine VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_HandleGameResults::
# 42 "data/scripts/battle_arcade_battle.pory"
	arcade_takeenemyhelditems
# 43 "data/scripts/battle_arcade_battle.pory"
	arcade_handlegameresult
# 45 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent, MSGBOX_DEFAULT
# 46 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 47 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceImpactString
# 48 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
	return


BattleArcade_RouletteRoom_AnnounceImpactString::
# 53 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8005
# 55 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LOWER_HP, BattleArcade_RouletteRoom_AnnounceImpactString_2
# 57 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_RouletteRoom_AnnounceImpactString_3
# 59 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_RouletteRoom_AnnounceImpactString_4
# 61 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_RouletteRoom_AnnounceImpactString_5
# 63 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_RouletteRoom_AnnounceImpactString_6
# 65 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_RouletteRoom_AnnounceImpactString_7
# 67 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BERRY, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 68 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_ITEM, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 70 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LEVEL_UP, BattleArcade_RouletteRoom_AnnounceImpactString_9
# 72 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SUN, BattleArcade_RouletteRoom_AnnounceImpactString_10
# 74 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RAIN, BattleArcade_RouletteRoom_AnnounceImpactString_11
# 76 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SAND, BattleArcade_RouletteRoom_AnnounceImpactString_12
# 78 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_HAIL, BattleArcade_RouletteRoom_AnnounceImpactString_13
# 80 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FOG, BattleArcade_RouletteRoom_AnnounceImpactString_14
# 82 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_TRICK_ROOM, BattleArcade_RouletteRoom_AnnounceImpactString_15
# 84 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SWAP, BattleArcade_RouletteRoom_AnnounceImpactString_16
# 86 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_UP, BattleArcade_RouletteRoom_AnnounceImpactString_17
# 88 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_DOWN, BattleArcade_RouletteRoom_AnnounceImpactString_18
# 90 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RANDOM, BattleArcade_RouletteRoom_AnnounceImpactString_19
# 92 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_SMALL, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 93 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_BIG, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 95 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_BATTLE, BattleArcade_RouletteRoom_AnnounceImpactString_21
# 97 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_EVENT, BattleArcade_RouletteRoom_AnnounceImpactString_22
	return

BattleArcade_RouletteRoom_AnnounceImpactString_2:
# 56 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_3:
# 58 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_4:
# 60 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_5:
# 62 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_6:
# 64 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_7:
# 66 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_8:
# 69 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_9:
# 71 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_10:
# 73 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_11:
# 75 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_12:
# 77 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_13:
# 79 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_14:
# 81 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_15:
# 83 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_16:
# 85 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_17:
# 87 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_18:
# 89 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_19:
# 91 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_20:
# 94 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ReceivedBp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_21:
# 96 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_22:
# 98 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard::
# 104 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber
# 105 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 106 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 107 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartGameBoard
# 108 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 109 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_LoadOpponentText
# 110 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartBattle
# 111 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HandleBattleResult
	return


BattleArcade_RouletteRoom_EventScript_StartGameBoard::
# 116 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 117 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_PlayGameBoard
# 118 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_HandleGameResults
	return


BattleArcade_RouletteRoom_EventScript_LoadOpponentText::
# 123 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 124 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 125 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 126 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_StartBattle::
# 131 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 132 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost::
# 137 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 138 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon::
# 143 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 144 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_DefeatedOpponent::
# 149 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 150 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 151 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2
BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1:
# 155 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 156 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 157 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HealPlayer
	return

BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2:
# 153 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1


BattleArcade_RouletteRoom_EventScript_HealPlayer::
# 162 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GoodGoingWellHeal
# 163 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 164 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 165 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 166 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 167 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 168 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent::
# 173 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainstatus
# 174 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1:
# 179 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 180 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_ReadyForOpponent
# 181 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 182 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4:
# 186 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenu
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2:
# 176 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainUpNext
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5:
# 184 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4


BattleArcade_RouletteRoom_EventScript_ReadyMenu::
# 192 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 193 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 195 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenu_2
# 196 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenu_3
# 197 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenu_4
# 198 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_RouletteRoom_EventScript_ReadyMenu_5
# 199 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenu_6
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_2:
# 195 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_3:
# 196 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_4:
# 197 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_5:
# 198 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_6:
# 199 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord::
# 205 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 206 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 207 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2
# 208 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3
# 209 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4
# 210 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2:
# 207 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3:
# 208 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4:
# 209 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5:
# 210 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattle::
# 216 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 217 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 218 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 219 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1
	return

BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1:
# 221 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle::
# 227 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AskRecordBattle
# 228 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ReadyForOpponent::
# 233 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 234 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady
# 235 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_RouletteRoom_EventScript_AskPauseChallenge::
# 241 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak, MSGBOX_YESNO
# 242 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2
BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1:
# 246 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2:
# 244 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_PauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1


BattleArcade_RouletteRoom_EventScript_PauseChallenge::
# 251 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower
# 252 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 254 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 255 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 256 "data/scripts/battle_arcade_battle.pory"
	waitse
# 258 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 259 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_RouletteRoom_EventScript_AskRetireChallenge::
# 265 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire
# 266 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 267 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 268 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2
BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1:
# 272 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2:
# 270 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_RetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1


BattleArcade_RouletteRoom_EventScript_RetireChallenge::
# 277 "data/scripts/battle_arcade_battle.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 278 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return


BattleArcade_RouletteRoom_EventScript_ContinueChallenge::
# 283 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 284 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp::
# 289 "data/scripts/battle_arcade_battle.pory"
	arcade_set ARCADE_DATA_LVL_MODE
# 290 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobby::
# 295 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 296 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_RouletteRoom_EventScript_WarpToLobby_2
# 302 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 5, 6
BattleArcade_RouletteRoom_EventScript_WarpToLobby_1:
# 304 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_RouletteRoom_EventScript_WarpToLobby_2:
# 298 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 6, 6
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby_1


BattleArcade_RouletteRoom_EventScript_BrainUpNext::
# 310 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, 1
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainUpNext_2
BattleArcade_RouletteRoom_EventScript_BrainUpNext_1:
# 315 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition, MSGBOX_DEFAULT
# 316 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, 1
# 318 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainUpNext_2:
# 312 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForBrain
	goto BattleArcade_RouletteRoom_EventScript_BrainUpNext_1


BattleArcade_RouletteRoom_EventScript_AskReadyForBrain::
# 323 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 324 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskReadyForBrain_1
# 330 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForBrain_1:
# 326 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainReadyMenu
	return


BattleArcade_RouletteRoom_EventScript_BrainReadyMenu::
# 336 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 337 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 339 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_2
# 340 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_3
# 341 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_4
# 342 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_5
# 343 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_6
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_2:
# 339 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BattleBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_3:
# 340 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_4:
# 341 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_5:
# 342 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_6:
# 343 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord::
# 349 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 350 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 352 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_2
# 353 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_3
# 354 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_4
# 355 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_5
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_2:
# 352 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BattleBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_3:
# 353 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_4:
# 354 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_5:
# 355 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_LoadBrainText::
# 361 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_RouletteRoom_EventScript_LoadBrainText_Text_0
# 362 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainintro
# 363 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 364 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 365 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_BattleBrain::
# 370 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 371 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 372 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BrainIntro
# 373 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartGameBoard
# 374 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 375 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_LoadBrainText
# 376 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartBattle
# 377 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult
	return


BattleArcade_RouletteRoom_EventScript_HandleBattleResult::
# 383 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_HandleBattleResult_2
BattleArcade_RouletteRoom_EventScript_HandleBattleResult_1:
# 387 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return

BattleArcade_RouletteRoom_EventScript_HandleBattleResult_2:
# 385 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent
	goto BattleArcade_RouletteRoom_EventScript_HandleBattleResult_1


BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult::
# 392 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_2
BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_1:
# 396 "data/scripts/battle_arcade_battle.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	return

BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_2:
# 394 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_DefeatedBrain
	goto BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_1


BattleArcade_RouletteRoom_EventScript_DefeatedBrain::
# 401 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 402 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BrainCongratsText
# 403 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 404 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	return


BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge::
# 409 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 410 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1:
# 414 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_GiveBP
# 415 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_RestoreItems
# 416 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_Save
# 417 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon
	return

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2:
# 412 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1


BattleArcade_RouletteRoom_EventScript_Save::
# 422 "data/scripts/battle_arcade_battle.pory"
	msgbox gText_SavingDontTurnOff2
# 423 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 424 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 425 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 426 "data/scripts/battle_arcade_battle.pory"
	waitse
# 427 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_GiveBP::
# 432 "data/scripts/battle_arcade_battle.pory"
	arcade_givepoints
# 433 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh
	return


BattleArcade_RouletteRoom_EventScript_RestoreItems::
# 438 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems
	return


BattleArcade_RouletteRoom_EventScript_BrainCongratsText::
# 443 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 444 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 35
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainCongratsText_1
# 450 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TrulyItWasSoVery, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_EventScript_BrainCongratsText_1:
# 446 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_BrainIntro::
# 456 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
# 457 "data/scripts/battle_arcade_battle.pory"
	arcade_checksymbol
# 458 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_NoNeedToWorry, MSGBOX_DEFAULT
# 459 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_GOLD
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainIntro_1
# 465 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YouAreProving, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_EventScript_BrainIntro_1:
# 461 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_IKnowOneThing, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_LoadBrainText_Text_0:
# 361 "data/scripts/battle_arcade_battle.pory"
	.string "hello$"

BattleArcade_RouletteRoom_Text_WellDone::
# 469 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_RouletteRoom_Text_LetTheBattle::
# 474 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Next::
# 479 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Go::
# 484 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_RouletteRoom_Text_DoYouWantToContinue::
# 489 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_RouletteRoom_Text_DoYouWantToRestore::
# 494 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 499 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn::
# 504 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_RouletteRoom_Text_PleaseWaitAMoment::
# 508 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_RouletteRoom_Text_GoodGoingWellHeal::
# 512 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady::
# 516 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveTheLastBattle::
# 520 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_RouletteRoom_Text_BattleHasBeenSaved::
# 524 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_RouletteRoom_Text_ThereWasAnError::
# 528 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_RouletteRoom_Text_DeleteYourExistingBattleVideo::
# 532 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower::
# 536 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak::
# 540 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire::
# 544 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_RouletteRoom_Text_IsChoosingPleaseWait::
# 548 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_RouletteRoom_Text_ChoseToRetire::
# 552 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade::
# 556 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_RouletteRoom_Text_GameNoComeOn::
# 560 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_RouletteRoom_Text_WithoutFurtherAdo::
# 564 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent::
# 568 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp::
# 572 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothWithoutFullHp::
# 576 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp::
# 580 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothLeveledUp::
# 584 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommencePoisoned::
# 588 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothPoisoned::
# 592 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed::
# 596 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothParalyzed::
# 600 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBurned::
# 604 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothBurned::
# 608 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceAsleep::
# 612 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothAsleep::
# 616 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceFrozen::
# 620 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothFrozen::
# 624 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe::
# 628 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_BothPokemonWillBeLoanedThe::
# 632 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_HereYouGo::
# 636 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight::
# 640 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall::
# 644 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm::
# 648 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail::
# 652 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_RouletteRoom_Text_MatchConductedDenseFog::
# 656 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted::
# 660 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched::
# 664 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_RouletteRoom_Text_BoardspeedIncreased::
# 668 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_RouletteRoom_Text_BoardspeedDecreased::
# 672 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_RouletteRoom_Text_BoardmotionRandom::
# 676 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_RouletteRoom_Text_ReceivedBp::
# 680 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AndReceivedBp::
# 684 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AreYouReady::
# 688 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip::
# 692 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_RouletteRoom_Text_TooBadThereIsNo::
# 696 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_RouletteRoom_Text_OkLetTheBattleCommence::
# 700 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_RouletteRoom_Text_MatchPoisonedLuckyBreak::
# 704 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchBothPoisonedLuckyBreak::
# 708 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak::
# 712 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBothParalyzedLuckyBreak::
# 716 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak::
# 720 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_RouletteRoom_Text_MatchBothBurnedLuckyBreak::
# 724 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak::
# 728 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchBothAsleepLuckyBreak::
# 732 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak::
# 736 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_RouletteRoom_Text_MatchBothFrozenLuckyBreak::
# 740 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh::
# 744 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems::
# 748 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_RouletteRoom_Text_Continue::
# 752 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_RouletteRoom_Text_Record::
# 756 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_RouletteRoom_Text_Rest::
# 760 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_RouletteRoom_Text_Retire::
# 764 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition::
# 768 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_RouletteRoom_Text_NoNeedToWorry::
# 773 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\l"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that.$"

BattleArcade_RouletteRoom_Text_IKnowOneThing::
# 778 "data/scripts/battle_arcade_battle.pory"
	.string "I know one thing for certain. You have\n"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_RouletteRoom_Text_YouAreProving::
# 782 "data/scripts/battle_arcade_battle.pory"
	.string "You are proving yourself incredible. Are\n"
	.string "you incredible because you are so lucky\l"
	.string "you shrug off bad luck entirely? Or, are\l"
	.string "you so incredibly talented to not be\l"
	.string "swayed by luck, good or bad? I wish to\l"
	.string "see for myself what brought you to me\l"
	.string "today!$"

BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour::
# 786 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_RouletteRoom_Text_TrulyItWasSoVery::
# 790 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
