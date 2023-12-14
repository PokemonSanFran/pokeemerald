BattleFrontier_RouletteRoom_EventScript_BeginChallenge::
# 6 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 7 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 8 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 10 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 11 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber::
# 16 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 17 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 18 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber::
# 23 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 24 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GameNoComeOn, MSGBOX_DEFAULT
# 25 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_PlayGameBoard::
# 30 "data/scripts/battle_arcade_battle.pory"
	additem ITEM_COIN_CASE, 1
# 31 "data/scripts/battle_arcade_battle.pory"
	addcoins 50
# 32 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 33 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 34 "data/scripts/battle_arcade_battle.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 35 "data/scripts/battle_arcade_battle.pory"
	playslotmachine VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_HandleGameResults::
# 41 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent, MSGBOX_DEFAULT
# 42 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 45 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceResults
# 46 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
	return


BattleArcade_RouletteRoom_BufferImpactedName::
# 51 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, ARCADE_IMPACT_OPPONENT
	goto_if_eq BattleArcade_RouletteRoom_BufferImpactedName_1
# 58 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_1, gText_Player
	return

BattleArcade_RouletteRoom_BufferImpactedName_1:
# 54 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, 1
	return


BattleArcade_RouletteRoom_AnnounceImpactString::
# 65 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 67 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_LOWER_HP, BattleArcade_RouletteRoom_AnnounceImpactString_2
# 69 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_POISON, BattleArcade_RouletteRoom_AnnounceImpactString_3
# 71 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_PARALYZE, BattleArcade_RouletteRoom_AnnounceImpactString_4
# 73 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_BURN, BattleArcade_RouletteRoom_AnnounceImpactString_5
# 75 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SLEEP, BattleArcade_RouletteRoom_AnnounceImpactString_6
# 77 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_FREEZE, BattleArcade_RouletteRoom_AnnounceImpactString_7
# 79 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BERRY, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 80 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_ITEM, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 82 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_LEVEL_UP, BattleArcade_RouletteRoom_AnnounceImpactString_9
# 84 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SUN, BattleArcade_RouletteRoom_AnnounceImpactString_10
# 86 "data/scripts/battle_arcade_battle.pory"
	case ARACDE_RAIN, BattleArcade_RouletteRoom_AnnounceImpactString_11
# 88 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SAND, BattleArcade_RouletteRoom_AnnounceImpactString_12
# 90 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_HAIL, BattleArcade_RouletteRoom_AnnounceImpactString_13
# 92 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_FOG, BattleArcade_RouletteRoom_AnnounceImpactString_14
# 94 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_TRICK_ROOM, BattleArcade_RouletteRoom_AnnounceImpactString_15
# 96 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SWAP, BattleArcade_RouletteRoom_AnnounceImpactString_16
# 98 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SPEED_UP, BattleArcade_RouletteRoom_AnnounceImpactString_17
# 100 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SPEED_DOWN, BattleArcade_RouletteRoom_AnnounceImpactString_18
# 102 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_RANDOM, BattleArcade_RouletteRoom_AnnounceImpactString_19
# 104 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BP_SMALL, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 105 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BP_BIG, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 107 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_NO_BATTLE, BattleArcade_RouletteRoom_AnnounceImpactString_21
# 109 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_NO_EVENT, BattleArcade_RouletteRoom_AnnounceImpactString_22
	return

BattleArcade_RouletteRoom_AnnounceImpactString_2:
# 68 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_3:
# 70 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_4:
# 72 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_5:
# 74 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_6:
# 76 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_7:
# 78 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_8:
# 81 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_9:
# 83 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_10:
# 85 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_11:
# 87 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_12:
# 89 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_13:
# 91 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_14:
# 93 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_15:
# 95 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_16:
# 97 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_17:
# 99 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_18:
# 101 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_19:
# 103 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_20:
# 106 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ReceivedBp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_21:
# 108 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_22:
# 110 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_AnnounceResults::
# 116 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_BufferImpactedName
# 117 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceImpactString
	return


BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard::
# 122 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber
# 123 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 124 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 125 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 126 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_PlayGameBoard
# 127 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_HandleGameResults
# 128 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_StartBattle
	return


BattleArcade_RouletteRoom_EventScript_StartBattle::
# 133 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 134 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 135 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 136 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 137 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 138 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 139 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 140 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_StartBattle_2
BattleArcade_RouletteRoom_EventScript_StartBattle_1:
# 144 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return

BattleArcade_RouletteRoom_EventScript_StartBattle_2:
# 142 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent
	goto BattleArcade_RouletteRoom_EventScript_StartBattle_1


BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost::
# 149 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 150 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon::
# 155 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 156 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_DefeatedOpponent::
# 161 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 163 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2
BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1:
# 167 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 168 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 169 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HealPlayer
	return

BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2:
# 165 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1


BattleArcade_RouletteRoom_EventScript_HealPlayer::
# 174 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GoodGoingWellHeal
# 175 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 176 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 177 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 178 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 179 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 180 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent::
# 185 "data/scripts/battle_arcade_battle.pory"
	frontier_getbrainstatus
# 186 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 187 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1:
# 192 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 193 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_ReadyForOpponent
# 194 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 195 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4:
# 199 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenu
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5:
# 197 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4


BattleArcade_RouletteRoom_EventScript_ReadyMenu::
# 205 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 206 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 208 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenu_2
# 209 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenu_3
# 210 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenu_4
# 211 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_RouletteRoom_EventScript_ReadyMenu_5
# 212 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenu_6
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_2:
# 208 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_3:
# 209 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattle
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_4:
# 210 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_5:
# 211 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_6:
# 212 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord::
# 218 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 219 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 220 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2
# 221 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3
# 222 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4
# 223 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2:
# 220 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3:
# 221 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4:
# 222 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5:
# 223 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattle::
# 229 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 230 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 231 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 232 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRecordBattle_2
BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1:
# 236 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskRecordBattle_2:
# 234 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1


BattleArcade_RouletteRoom_EventScript_ReadyForOpponent::
# 241 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 242 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady
# 243 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_RouletteRoom_EventScript_AskPauseChallenge::
# 249 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak, MSGBOX_YESNO
# 250 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2
BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1:
# 254 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2:
# 252 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_PauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1


BattleArcade_RouletteRoom_EventScript_PauseChallenge::
# 259 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower
# 260 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 262 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 263 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 264 "data/scripts/battle_arcade_battle.pory"
	waitse
# 266 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 267 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_RouletteRoom_EventScript_AskRetireChallenge::
# 273 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire
# 274 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 275 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 276 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2
BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1:
# 280 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2:
# 278 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_RetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1


BattleArcade_RouletteRoom_EventScript_RetireChallenge::
# 285 "data/scripts/battle_arcade_battle.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 286 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return


BattleArcade_RouletteRoom_EventScript_ContinueChallenge::
# 291 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 292 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp::
# 297 "data/scripts/battle_arcade_battle.pory"
	arcade_set ARCADE_DATA_LVL_MODE
# 298 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobby::
# 303 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 304 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_RouletteRoom_EventScript_WarpToLobby_2
# 310 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 5, 6
BattleArcade_RouletteRoom_EventScript_WarpToLobby_1:
# 312 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_RouletteRoom_EventScript_WarpToLobby_2:
# 306 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 6, 6
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby_1


BattleArcade_RouletteRoom_Text_WellDone::
# 317 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_RouletteRoom_Text_LetTheBattle::
# 322 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Next::
# 327 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Go::
# 332 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_RouletteRoom_Text_DoYouWantToContinue::
# 337 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_RouletteRoom_Text_DoYouWantToRestore::
# 342 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 347 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn::
# 352 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_RouletteRoom_Text_PleaseWaitAMoment::
# 356 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_RouletteRoom_Text_GoodGoingWellHeal::
# 360 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady::
# 364 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveTheLastBattle::
# 368 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_RouletteRoom_Text_BattleHasBeenSaved::
# 372 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_RouletteRoom_Text_ThereWasAnError::
# 376 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_RouletteRoom_Text_DeleteYourExistingBattleVideo::
# 380 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower::
# 384 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak::
# 388 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire::
# 392 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_RouletteRoom_Text_IsChoosingPleaseWait::
# 396 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_RouletteRoom_Text_ChoseToRetire::
# 400 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade::
# 404 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_RouletteRoom_Text_GameNoComeOn::
# 408 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_RouletteRoom_Text_WithoutFurtherAdo::
# 412 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent::
# 416 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp::
# 420 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothWithoutFullHp::
# 424 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp::
# 428 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothLeveledUp::
# 432 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommencePoisoned::
# 436 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothPoisoned::
# 440 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed::
# 444 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothParalyzed::
# 448 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBurned::
# 452 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothBurned::
# 456 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceAsleep::
# 460 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothAsleep::
# 464 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceFrozen::
# 468 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothFrozen::
# 472 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe::
# 476 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_BothPokemonWillBeLoanedThe::
# 480 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_HereYouGo::
# 484 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight::
# 488 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall::
# 492 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm::
# 496 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail::
# 500 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_RouletteRoom_Text_MatchConductedDenseFog::
# 504 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted::
# 508 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched::
# 512 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_RouletteRoom_Text_BoardspeedIncreased::
# 516 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_RouletteRoom_Text_BoardspeedDecreased::
# 520 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_RouletteRoom_Text_BoardmotionRandom::
# 524 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_RouletteRoom_Text_ReceivedBp::
# 528 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AndReceivedBp::
# 532 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AreYouReady::
# 536 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip::
# 540 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_RouletteRoom_Text_TooBadThereIsNo::
# 544 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_RouletteRoom_Text_OkLetTheBattleCommence::
# 548 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_RouletteRoom_Text_MatchPoisonedLuckyBreak::
# 552 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchBothPoisonedLuckyBreak::
# 556 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak::
# 560 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBothParalyzedLuckyBreak::
# 564 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak::
# 568 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_RouletteRoom_Text_MatchBothBurnedLuckyBreak::
# 572 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak::
# 576 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchBothAsleepLuckyBreak::
# 580 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak::
# 584 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_RouletteRoom_Text_MatchBothFrozenLuckyBreak::
# 588 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh::
# 592 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems::
# 596 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_RouletteRoom_Text_Continue::
# 600 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_RouletteRoom_Text_Record::
# 604 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_RouletteRoom_Text_Rest::
# 608 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_RouletteRoom_Text_Retire::
# 612 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition::
# 616 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_RouletteRoom_Text_IKnowOneThingFor::
# 620 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\l"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that. I\l"
	.string "know one thing for certain. You have\l"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_RouletteRoom_Text_YouAreProvingYourselfIncredible::
# 624 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\l"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that. You\l"
	.string "are proving yourself incredible. Are you\l"
	.string "incredible because you are so lucky you\l"
	.string "shrug off bad luck entirely? Or, are you\l"
	.string "so incredibly talented to not be swayed\l"
	.string "by luck, good or bad? I wish to see for\l"
	.string "myself what brought you to me today!$"

BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour::
# 628 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_RouletteRoom_Text_TrulyItWasSoVery::
# 632 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
