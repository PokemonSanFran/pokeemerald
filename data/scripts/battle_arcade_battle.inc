BattleFrontier_RouletteRoom_EventScript_BeginChallenge::
# 8 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 9 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 10 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 11 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 12 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber::
# 17 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 18 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 19 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber::
# 24 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 25 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GameNoComeOn, MSGBOX_DEFAULT
# 26 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_PlayGameBoard::
# 31 "data/scripts/battle_arcade_battle.pory"
	additem ITEM_COIN_CASE, 1
# 32 "data/scripts/battle_arcade_battle.pory"
	addcoins 50
# 33 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 34 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 35 "data/scripts/battle_arcade_battle.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 36 "data/scripts/battle_arcade_battle.pory"
	playslotmachine VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_HandleGameResults::
# 41 "data/scripts/battle_arcade_battle.pory"
	arcade_takeplayerhelditems
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
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_RouletteRoom_AnnounceImpactString_1
# 59 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceImpactString_Failure
	return

BattleArcade_RouletteRoom_AnnounceImpactString_1:
# 55 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceImpactString_Success
	return


BattleArcade_RouletteRoom_AnnounceImpactString_Success::
# 65 "data/scripts/battle_arcade_battle.pory"
	switch VAR_UNUSED_0x4083
# 67 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LOWER_HP, BattleArcade_RouletteRoom_AnnounceImpactString_Success_2
# 69 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_RouletteRoom_AnnounceImpactString_Success_3
# 71 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_RouletteRoom_AnnounceImpactString_Success_4
# 73 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_RouletteRoom_AnnounceImpactString_Success_5
# 75 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_RouletteRoom_AnnounceImpactString_Success_6
# 77 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_RouletteRoom_AnnounceImpactString_Success_7
# 79 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BERRY, BattleArcade_RouletteRoom_AnnounceImpactString_Success_8
# 80 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_ITEM, BattleArcade_RouletteRoom_AnnounceImpactString_Success_8
# 82 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LEVEL_UP, BattleArcade_RouletteRoom_AnnounceImpactString_Success_9
# 84 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SUN, BattleArcade_RouletteRoom_AnnounceImpactString_Success_10
# 86 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RAIN, BattleArcade_RouletteRoom_AnnounceImpactString_Success_11
# 88 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SAND, BattleArcade_RouletteRoom_AnnounceImpactString_Success_12
# 90 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_HAIL, BattleArcade_RouletteRoom_AnnounceImpactString_Success_13
# 92 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FOG, BattleArcade_RouletteRoom_AnnounceImpactString_Success_14
# 94 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_TRICK_ROOM, BattleArcade_RouletteRoom_AnnounceImpactString_Success_15
# 96 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SWAP, BattleArcade_RouletteRoom_AnnounceImpactString_Success_16
# 98 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_UP, BattleArcade_RouletteRoom_AnnounceImpactString_Success_17
# 100 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_DOWN, BattleArcade_RouletteRoom_AnnounceImpactString_Success_18
# 102 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RANDOM, BattleArcade_RouletteRoom_AnnounceImpactString_Success_19
# 104 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_SMALL, BattleArcade_RouletteRoom_AnnounceImpactString_Success_20
# 105 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_BIG, BattleArcade_RouletteRoom_AnnounceImpactString_Success_20
# 107 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_BATTLE, BattleArcade_RouletteRoom_AnnounceImpactString_Success_21
# 110 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_EVENT, BattleArcade_RouletteRoom_AnnounceImpactString_Success_22
BattleArcade_RouletteRoom_AnnounceImpactString_Success_22:
# 111 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_2:
# 68 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_3:
# 70 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_4:
# 72 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_5:
# 74 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_6:
# 76 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_7:
# 78 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_8:
# 81 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_9:
# 83 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_10:
# 85 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_11:
# 87 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_12:
# 89 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_13:
# 91 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_14:
# 93 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_15:
# 95 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_16:
# 97 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_17:
# 99 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_18:
# 101 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_19:
# 103 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_20:
# 106 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ReceivedBp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Success_21:
# 108 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_AnnounceImpactString_Failure::
# 117 "data/scripts/battle_arcade_battle.pory"
	switch VAR_UNUSED_0x4083
# 119 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_RouletteRoom_AnnounceImpactString_Failure_2
# 121 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_RouletteRoom_AnnounceImpactString_Failure_3
# 123 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_RouletteRoom_AnnounceImpactString_Failure_4
# 125 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_RouletteRoom_AnnounceImpactString_Failure_5
# 128 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_RouletteRoom_AnnounceImpactString_Failure_6
BattleArcade_RouletteRoom_AnnounceImpactString_Failure_6:
# 129 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Failure_2:
# 120 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Failure_3:
# 122 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Failure_4:
# 124 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_Failure_5:
# 126 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard::
# 135 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber
# 136 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 137 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 138 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartGameBoard
# 139 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 140 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_LoadOpponentText
# 141 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartBattle
# 142 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HandleBattleResult
	return


BattleArcade_RouletteRoom_EventScript_StartGameBoard::
# 147 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 148 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_PlayGameBoard
# 149 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_HandleGameResults
	return


BattleArcade_RouletteRoom_EventScript_LoadOpponentText::
# 154 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 155 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 156 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 157 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_StartBattle::
# 162 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 163 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_DoRouletteBattle
	return


BattleArcade_RouletteRoom_EventScript_DoRouletteBattle::
# 168 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 170 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, 0
# 171 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 172 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
# 173 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_0x8005, 0
# 175 "data/scripts/battle_arcade_battle.pory"
	special DoSpecialRouletteTrainerBattle
# 176 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 178 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 179 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8004, FRONTIER_MODE_LINK_MULTIS
	goto_if_ne BattleArcade_RouletteRoom_EventScript_DoRouletteBattle_2
BattleArcade_RouletteRoom_EventScript_DoRouletteBattle_1:
# 184 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleArcade_RouletteRoom_EventScript_DoRouletteBattle_2:
# 181 "data/scripts/battle_arcade_battle.pory"
	frontier_resetsketch
	goto BattleArcade_RouletteRoom_EventScript_DoRouletteBattle_1


BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost::
# 190 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 191 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon::
# 196 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 197 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp
	return


BattleArcade_RouletteRoom_EventScript_DefeatedOpponent::
# 202 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 203 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 204 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2
BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1:
# 208 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 209 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 210 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HealPlayer
	return

BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_2:
# 206 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent_1


BattleArcade_RouletteRoom_EventScript_HealPlayer::
# 215 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GoodGoingWellHeal
# 216 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 217 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 218 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 219 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 220 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 221 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent::
# 226 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainstatus
# 227 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1:
# 232 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 233 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_ReadyForOpponent
# 234 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 235 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4:
# 239 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenu
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2:
# 229 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainUpNext
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5:
# 237 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4


BattleArcade_RouletteRoom_EventScript_ReadyMenu::
# 245 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 246 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 248 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenu_2
# 249 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenu_3
# 250 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenu_4
# 251 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_RouletteRoom_EventScript_ReadyMenu_5
# 252 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenu_6
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_2:
# 248 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_3:
# 249 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_4:
# 250 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_5:
# 251 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenu_6:
# 252 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord::
# 258 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 259 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 260 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2
# 261 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3
# 262 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4
# 263 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_2:
# 260 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_3:
# 261 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_4:
# 262 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_ReadyMenuNoRecord_5:
# 263 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattle::
# 269 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 270 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 271 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 272 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1
	return

BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1:
# 274 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle::
# 280 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AskRecordBattle
# 281 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ReadyForOpponent::
# 286 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BufferNextBattleNumber
# 287 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady
# 288 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_RouletteRoom_EventScript_AskPauseChallenge::
# 294 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak, MSGBOX_YESNO
# 295 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2
BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1:
# 299 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2:
# 297 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_PauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_1


BattleArcade_RouletteRoom_EventScript_PauseChallenge::
# 304 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower
# 305 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 307 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 308 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 309 "data/scripts/battle_arcade_battle.pory"
	waitse
# 311 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 312 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_RouletteRoom_EventScript_AskRetireChallenge::
# 318 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire
# 319 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 320 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 321 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2
BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1:
# 325 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2:
# 323 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_RetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_1


BattleArcade_RouletteRoom_EventScript_RetireChallenge::
# 330 "data/scripts/battle_arcade_battle.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 331 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return


BattleArcade_RouletteRoom_EventScript_ContinueChallenge::
# 336 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 337 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_SetLevelModeAndWarp::
# 342 "data/scripts/battle_arcade_battle.pory"
	arcade_set ARCADE_DATA_LVL_MODE
# 343 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby
	return


BattleArcade_RouletteRoom_EventScript_WarpToLobby::
# 348 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 349 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_RouletteRoom_EventScript_WarpToLobby_2
# 355 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 5, 6
BattleArcade_RouletteRoom_EventScript_WarpToLobby_1:
# 357 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_RouletteRoom_EventScript_WarpToLobby_2:
# 351 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 6, 6
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobby_1


BattleArcade_RouletteRoom_EventScript_BrainUpNext::
# 363 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, 1
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainUpNext_2
BattleArcade_RouletteRoom_EventScript_BrainUpNext_1:
# 368 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition, MSGBOX_DEFAULT
# 369 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, 1
# 371 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainUpNext_2:
# 365 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForBrain
	goto BattleArcade_RouletteRoom_EventScript_BrainUpNext_1


BattleArcade_RouletteRoom_EventScript_AskReadyForBrain::
# 376 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 377 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskReadyForBrain_1
# 383 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForBrain_1:
# 379 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BrainReadyMenu
	return


BattleArcade_RouletteRoom_EventScript_BrainReadyMenu::
# 389 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 390 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 392 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_2
# 393 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_3
# 394 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_4
# 395 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_5
# 396 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_6
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_2:
# 392 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BattleBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_3:
# 393 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_4:
# 394 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_5:
# 395 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenu_6:
# 396 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord::
# 402 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 403 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 405 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_2
# 406 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_3
# 407 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_4
# 408 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_5
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_2:
# 405 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_BattleBrain
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_3:
# 406 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_4:
# 407 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	return

BattleArcade_RouletteRoom_EventScript_BrainReadyMenuNoRecord_5:
# 408 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_LoadBrainText::
# 414 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_RouletteRoom_EventScript_LoadBrainText_Text_0
# 415 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainintro
# 416 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 417 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 418 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_BattleBrain::
# 423 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 424 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 425 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BrainIntro
# 426 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartGameBoard
# 427 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 428 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_LoadBrainText
# 429 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_StartBattle
# 430 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult
	return


BattleArcade_RouletteRoom_EventScript_HandleBattleResult::
# 436 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_HandleBattleResult_2
BattleArcade_RouletteRoom_EventScript_HandleBattleResult_1:
# 440 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyLost
	return

BattleArcade_RouletteRoom_EventScript_HandleBattleResult_2:
# 438 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent
	goto BattleArcade_RouletteRoom_EventScript_HandleBattleResult_1


BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult::
# 445 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_2
BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_1:
# 449 "data/scripts/battle_arcade_battle.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	return

BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_2:
# 447 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_DefeatedBrain
	goto BattleArcade_RouletteRoom_EventScript_HandleBrainBattleResult_1


BattleArcade_RouletteRoom_EventScript_DefeatedBrain::
# 454 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 455 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_BrainCongratsText
# 456 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 457 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	return


BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge::
# 462 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 463 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1:
# 467 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_GiveBP
# 468 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_RestoreItems
# 469 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_Save
# 470 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_WarpToLobbyWon
	return

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2:
# 465 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1


BattleArcade_RouletteRoom_EventScript_Save::
# 475 "data/scripts/battle_arcade_battle.pory"
	msgbox gText_SavingDontTurnOff2
# 476 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 477 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 478 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 479 "data/scripts/battle_arcade_battle.pory"
	waitse
# 480 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_GiveBP::
# 485 "data/scripts/battle_arcade_battle.pory"
	arcade_givepoints
# 486 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh
	return


BattleArcade_RouletteRoom_EventScript_RestoreItems::
# 491 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems
	return


BattleArcade_RouletteRoom_EventScript_BrainCongratsText::
# 496 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 497 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 35
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainCongratsText_1
# 503 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TrulyItWasSoVery, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_EventScript_BrainCongratsText_1:
# 499 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_BrainIntro::
# 509 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
# 510 "data/scripts/battle_arcade_battle.pory"
	arcade_checksymbol
# 511 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_NoNeedToWorry, MSGBOX_DEFAULT
# 512 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_GOLD
	goto_if_eq BattleArcade_RouletteRoom_EventScript_BrainIntro_1
# 518 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YouAreProving, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_EventScript_BrainIntro_1:
# 514 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_IKnowOneThing, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_EventScript_LoadBrainText_Text_0:
# 414 "data/scripts/battle_arcade_battle.pory"
	.string "hello$"

BattleArcade_RouletteRoom_Text_WellDone::
# 522 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_RouletteRoom_Text_LetTheBattle::
# 527 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Next::
# 532 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Go::
# 537 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_RouletteRoom_Text_DoYouWantToContinue::
# 542 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_RouletteRoom_Text_DoYouWantToRestore::
# 547 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 552 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn::
# 557 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_RouletteRoom_Text_PleaseWaitAMoment::
# 561 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_RouletteRoom_Text_GoodGoingWellHeal::
# 565 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady::
# 569 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveTheLastBattle::
# 573 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_RouletteRoom_Text_BattleHasBeenSaved::
# 577 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_RouletteRoom_Text_ThereWasAnError::
# 581 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_RouletteRoom_Text_DeleteYourExistingBattleVideo::
# 585 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower::
# 589 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak::
# 593 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire::
# 597 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_RouletteRoom_Text_IsChoosingPleaseWait::
# 601 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_RouletteRoom_Text_ChoseToRetire::
# 605 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade::
# 609 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_RouletteRoom_Text_GameNoComeOn::
# 613 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_RouletteRoom_Text_WithoutFurtherAdo::
# 617 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent::
# 621 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp::
# 625 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothWithoutFullHp::
# 629 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp::
# 633 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothLeveledUp::
# 637 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommencePoisoned::
# 641 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothPoisoned::
# 645 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed::
# 649 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothParalyzed::
# 653 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBurned::
# 657 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothBurned::
# 661 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceAsleep::
# 665 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothAsleep::
# 669 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceFrozen::
# 673 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothFrozen::
# 677 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe::
# 681 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_BothPokemonWillBeLoanedThe::
# 685 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_HereYouGo::
# 689 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight::
# 693 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall::
# 697 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm::
# 701 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail::
# 705 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_RouletteRoom_Text_MatchConductedDenseFog::
# 709 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted::
# 713 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched::
# 717 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_RouletteRoom_Text_BoardspeedIncreased::
# 721 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_RouletteRoom_Text_BoardspeedDecreased::
# 725 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_RouletteRoom_Text_BoardmotionRandom::
# 729 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_RouletteRoom_Text_ReceivedBp::
# 733 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AndReceivedBp::
# 737 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AreYouReady::
# 741 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip::
# 745 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_RouletteRoom_Text_TooBadThereIsNo::
# 749 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_RouletteRoom_Text_OkLetTheBattleCommence::
# 753 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_RouletteRoom_Text_MatchPoisonedLuckyBreak::
# 757 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchBothPoisonedLuckyBreak::
# 761 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak::
# 765 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBothParalyzedLuckyBreak::
# 769 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak::
# 773 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_RouletteRoom_Text_MatchBothBurnedLuckyBreak::
# 777 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak::
# 781 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchBothAsleepLuckyBreak::
# 785 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak::
# 789 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_RouletteRoom_Text_MatchBothFrozenLuckyBreak::
# 793 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh::
# 797 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems::
# 801 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_RouletteRoom_Text_Continue::
# 805 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_RouletteRoom_Text_Record::
# 809 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_RouletteRoom_Text_Rest::
# 813 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_RouletteRoom_Text_Retire::
# 817 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition::
# 821 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_RouletteRoom_Text_NoNeedToWorry::
# 826 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\l"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that.$"

BattleArcade_RouletteRoom_Text_IKnowOneThing::
# 831 "data/scripts/battle_arcade_battle.pory"
	.string "I know one thing for certain. You have\n"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_RouletteRoom_Text_YouAreProving::
# 835 "data/scripts/battle_arcade_battle.pory"
	.string "You are proving yourself incredible. Are\n"
	.string "you incredible because you are so lucky\l"
	.string "you shrug off bad luck entirely? Or, are\l"
	.string "you so incredibly talented to not be\l"
	.string "swayed by luck, good or bad? I wish to\l"
	.string "see for myself what brought you to me\l"
	.string "today!$"

BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour::
# 839 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_RouletteRoom_Text_TrulyItWasSoVery::
# 843 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
