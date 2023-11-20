BattleArcade_Entrance_EventScript_GetChallengeStatus::
	frontier_getstatus
	end


BattleArcade_Entrance_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	delay 30
	msgbox BattleArcade_Entrance_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	arcade_set ARCADE_DATA_WIN_STREAK, 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	goto BattleArcade_Entrance_EventScript_SetChallengeStatusEnd
	return


BattleArcade_Entrance_EventScript_AskEnterChallenge::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
	special SavePlayerParty
	message BattleArcade_Entrance_Text_HiyahDo
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleArcade_Entrance_EventScript_AskEnterChallenge_2
	case 1, BattleArcade_Entrance_EventScript_AskEnterChallenge_3
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_AskEnterChallenge_4
	case 2, BattleArcade_Entrance_EventScript_AskEnterChallenge_4
	return

BattleArcade_Entrance_EventScript_AskEnterChallenge_2:
	goto BattleArcade_Entrance_EventScript_TryEnterChallenge
	return

BattleArcade_Entrance_EventScript_AskEnterChallenge_3:
	goto BattleArcade_Entrance_EventScript_ExplainChallenge
	return

BattleArcade_Entrance_EventScript_AskEnterChallenge_4:
	goto BattleArcade_Entrance_EventScript_DenyChallenge
	return


BattleArcade_Entrance_EventScript_TryEnterChallenge::
	message BattleArcade_Entrance_Text_OffersTwoLevels
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleArcade_Entrance_EventScript_TryEnterChallenge_3
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_TryEnterChallenge_3
BattleArcade_Entrance_EventScript_TryEnterChallenge_1:
	message BattleArcade_Entrance_Text_SelectTheTypeYouWant
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	call BattleArcade_Entrance_EventScript_CreateTypeList
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleArcade_Entrance_EventScript_NotEnoughValidMons
	fadescreen FADE_TO_BLACK
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleArcade_Entrance_EventScript_LoadPartyCancelChallenge
	msgbox BattleArcade_Entrance_Text_BeforeDivingInto, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleArcade_Entrance_EventScript_TryEnterChallenge_5
	case NO, BattleArcade_Entrance_EventScript_TryEnterChallenge_6
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_TryEnterChallenge_6
	return

BattleArcade_Entrance_EventScript_TryEnterChallenge_3:
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	goto BattleArcade_Entrance_EventScript_TryEnterChallenge_1

BattleArcade_Entrance_EventScript_TryEnterChallenge_5:
	goto BattleArcade_Entrance_EventScript_SaveBeforeChallenge
	return

BattleArcade_Entrance_EventScript_TryEnterChallenge_6:
	goto BattleArcade_Entrance_EventScript_LoadPartyCancelChallenge
	return


BattleArcade_Entrance_EventScript_CreateTypeList::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 17, BattleArcade_Entrance_EventScript_CreateTypeList_4
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_CreateTypeList_4
	arcade_convertmenutotype
BattleArcade_Entrance_EventScript_CreateTypeList_1:
	arcade_bufferarcadetype
	return

BattleArcade_Entrance_EventScript_CreateTypeList_4:
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	goto BattleArcade_Entrance_EventScript_CreateTypeList_1


BattleArcade_Entrance_EventScript_SaveBeforeChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	arcade_init
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	special HealPlayerParty
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Entrance_EventScript_SaveBeforeChallenge_2
BattleArcade_Entrance_EventScript_SaveBeforeChallenge_1:
	goto BattleArcade_Entrance_EventScript_WarpToBattleRoom
	return

BattleArcade_Entrance_EventScript_SaveBeforeChallenge_2:
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
	goto BattleArcade_Entrance_EventScript_DenyChallenge
	goto BattleArcade_Entrance_EventScript_SaveBeforeChallenge_1


BattleArcade_Entrance_EventScript_ExplainChallenge::
	msgbox BattleArcade_Entrance_Text_BattleArcadeIsATraining, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_Entrance_EventScript_ExplainChallenge_2
BattleArcade_Entrance_EventScript_ExplainChallenge_1:
	msgbox BattleArcade_Entrance_Text_IWontForceYou, MSGBOX_DEFAULT
	releaseall
	end

BattleArcade_Entrance_EventScript_ExplainChallenge_2:
	goto BattleArcade_Entrance_EventScript_TryEnterChallenge
	goto BattleArcade_Entrance_EventScript_ExplainChallenge_1


BattleArcade_Entrance_EventScript_NotEnoughValidMons::
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleArcade_Entrance_EventScript_NotEnoughValidMons_2
	msgbox BattleArcade_Entrance_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
BattleArcade_Entrance_EventScript_NotEnoughValidMons_1:
	release
	end

BattleArcade_Entrance_EventScript_NotEnoughValidMons_2:
	msgbox BattleArcade_Entrance_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_NotEnoughValidMons_1


BattleArcade_Entrance_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	return


BattleArcade_Entrance_EventScript_CancelChallenge::
	msgbox BattleArcade_Entrance_Text_OhYouChangedYour, MSGBOX_DEFAULT
	release
	end


BattleArcade_Entrance_EventScript_DenyChallenge::
	msgbox BattleArcade_Entrance_Text_IWontForceYou, MSGBOX_DEFAULT
	release
	end


BattleArcade_Entrance_EventScript_WarpToBattleRoom::
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	frontier_saveparty
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_ARCADE_BATTLE_ROOM, 0, 6
	arcade_save CHALLENGE_STATUS_SAVING
	return


BattleArcade_Entrance_EventScript_JudgeChallenge::
	arcade_get ARCADE_DATA_WIN_STREAK
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Entrance_EventScript_JudgeChallenge_1
	buffernumberstring STR_VAR_1, VAR_RESULT
	goto BattleArcade_Entrance_EventScript_Results
	return

BattleArcade_Entrance_EventScript_JudgeChallenge_1:
	goto BattleArcade_Entrance_EventScript_Results_NoWins
	return


BattleArcade_Entrance_EventScript_Results_NoWins::
	lock
	faceplayer
	call BattleArcade_Entrance_EventScript_SaveResult
	call BattleArcade_Entrance_EventScript_AskSaveBattle
	msgbox BattleArcade_Entrance_Text_YouLostbutTrainYourself, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_SetChallengeStatusEnd
	return


BattleArcade_Entrance_EventScript_Results::
	lock
	faceplayer
	call BattleArcade_Entrance_EventScript_SaveResult
	arcade_bufferarcadetype
	arcade_get ARCADE_DATA_WIN_STREAK
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox BattleArcade_Entrance_Text_YourResultForThisRestricted
	call BattleArcade_Entrance_EventScript_AwardPoints
	goto_if_set FLAG_ARCADE_FIRST_TYPE_WIN, BattleArcade_Entrance_EventScript_Results_2
BattleArcade_Entrance_EventScript_Results_1:
	call BattleArcade_Entrance_EventScript_AskSaveBattle
	goto BattleArcade_Entrance_EventScript_SetChallengeStatusEnd
	return

BattleArcade_Entrance_EventScript_Results_2:
	msgbox BattleArcade_Entrance_Text_TheWayYouHandleType
	call BattleArcade_Entrance_EventScript_CheckSymbol
	goto BattleArcade_Entrance_EventScript_Results_1


BattleArcade_Entrance_EventScript_SaveResult::
	message BattleArcade_Entrance_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	arcade_givepoints
	arcade_checksymbol
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Entrance_EventScript_SaveResult_2
	compare VAR_RESULT, ARCADE_SYMBOL_GOLD
	goto_if_eq BattleArcade_Entrance_EventScript_SaveResult_3
BattleArcade_Entrance_EventScript_SaveResult_1:
	special LoadPlayerParty
	arcade_save 0
	playse SE_SAVE
	waitse
	return

BattleArcade_Entrance_EventScript_SaveResult_2:
	setflag FLAG_SYS_ARENA_SILVER
	goto BattleArcade_Entrance_EventScript_SaveResult_1

BattleArcade_Entrance_EventScript_SaveResult_3:
	setflag FLAG_SYS_ARENA_GOLD
	goto BattleArcade_Entrance_EventScript_SaveResult_1


BattleArcade_Entrance_EventScript_AwardPoints::
	msgbox BattleArcade_Entrance_Text_YouEarned
	return


BattleArcade_Entrance_EventScript_CheckSymbol::
	arcade_checksymbol
	compare VAR_RESULT, ARCADE_SYMBOL_NONE
	goto_if_gt BattleArcade_Entrance_EventScript_CheckSymbol_2
BattleArcade_Entrance_EventScript_CheckSymbol_1:
	return

BattleArcade_Entrance_EventScript_CheckSymbol_2:
	call BattleArcade_Entrance_EventScript_GiveSymbol
	goto BattleArcade_Entrance_EventScript_CheckSymbol_1


BattleArcade_Entrance_EventScript_GiveSymbol::
	msgbox BattleArcade_Entrance_Text_WhatYouCompletedRestricted
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Entrance_EventScript_GiveSymbol_2
	msgbox BattleArcade_Entrance_Text_ICantBelieveIt
	msgbox BattleArcade_Entrance_Text_ThisAccomplishmentIsSureTo
BattleArcade_Entrance_EventScript_GiveSymbol_1:
	msgbox BattleArcade_Entrance_Text_ToCommemorateThisMonumentalAchievement
	playfanfare MUS_OBTAIN_SYMBOL
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Entrance_EventScript_GiveSymbol_6
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
BattleArcade_Entrance_EventScript_GiveSymbol_5:
	waitmessage
	waitfanfare
	compare VAR_RESULT, ARCADE_SYMBOL_GOLD
	goto_if_eq BattleArcade_Entrance_EventScript_GiveSymbol_10
BattleArcade_Entrance_EventScript_GiveSymbol_9:
	return

BattleArcade_Entrance_EventScript_GiveSymbol_2:
	msgbox BattleArcade_Entrance_Text_ThatsExcellentWork
	goto BattleArcade_Entrance_EventScript_GiveSymbol_1

BattleArcade_Entrance_EventScript_GiveSymbol_6:
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
	goto BattleArcade_Entrance_EventScript_GiveSymbol_5

BattleArcade_Entrance_EventScript_GiveSymbol_10:
	msgbox BattleArcade_Entrance_Text_IHopeYoullKeep
	goto BattleArcade_Entrance_EventScript_GiveSymbol_9


BattleArcade_Entrance_EventScript_AskSaveBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Entrance_EventScript_AskSaveBattle_2
	message BattleArcade_Entrance_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Entrance_EventScript_AskSaveBattle_5
BattleArcade_Entrance_EventScript_AskSaveBattle_4:
	return

BattleArcade_Entrance_EventScript_AskSaveBattle_2:
	return

BattleArcade_Entrance_EventScript_AskSaveBattle_5:
	call BattleArcade_Entrance_EventScript_SaveBattle
	goto BattleArcade_Entrance_EventScript_AskSaveBattle_4


BattleArcade_Entrance_EventScript_SaveBattle::
	frontier_savebattle
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Entrance_EventScript_SaveBattle_2
	msgbox BattleArcade_Entrance_Text_ThereWasAGlitch, MSGBOX_DEFAULT
BattleArcade_Entrance_EventScript_SaveBattle_1:
	return

BattleArcade_Entrance_EventScript_SaveBattle_2:
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_SaveBattle_1


BattleArcade_Entrance_EventScript_SetChallengeStatusEnd::
	setvar VAR_TEMP_0, 255
	closemessage
	setvar VAR_ARCADE_TYPE, TYPE_NONE
	release
	end


BattleArcade_Entrance_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleArcade_Entrance_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleArcade_Entrance_Text_ProgressWillBeSaved
	waitmessage
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleArcade_Entrance_EventScript_WarpToBattleRoom
	end


BattleArcade_Entrance_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARCADE, 0
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end


BattleArcade_EventScript_RulesBoard::
	lockall
	msgbox BattleArcade_Entrance_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_ReadRulesBoard
	end


BattleArcade_Entrance_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleArcade_Entrance_EventScript_ReadRulesBoard_3
	case 1, BattleArcade_Entrance_EventScript_ReadRulesBoard_4
	case 2, BattleArcade_Entrance_EventScript_ReadRulesBoard_5
	case 3, BattleArcade_Entrance_EventScript_ReadRulesBoard_6
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_ReadRulesBoard_6
BattleArcade_Entrance_EventScript_ReadRulesBoard_1:
	goto BattleArcade_EventScript_RulesBoard
	end

BattleArcade_Entrance_EventScript_ReadRulesBoard_3:
	msgbox BattleArcade_Entrance_Text_OverviewBoard, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_ReadRulesBoard_1

BattleArcade_Entrance_EventScript_ReadRulesBoard_4:
	msgbox BattleArcade_Entrance_Text_RestrictionsBoard, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_ReadRulesBoard_1

BattleArcade_Entrance_EventScript_ReadRulesBoard_5:
	msgbox BattleArcade_Entrance_Text_RewardsBoard, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_ReadRulesBoard_1

BattleArcade_Entrance_EventScript_ReadRulesBoard_6:
	releaseall
	end


BattleArcade_RouletteRoom_EventScript_RefreshOpponent::
	tower_setopponent
	call BattleArcade_BattleRoom_EventScript_RefreshOpponentObject
	return


BattleArcade_RouletteRoom_EventScript_SetUpOpponent::
	setvar VAR_TEMP_0, 1
	call BattleArcade_RouletteRoom_EventScript_RefreshOpponent
	call BattleArcade_BattleRoom_EventScript_EnterRoomMovement
	goto BattleArcade_RouletteRoom_EventScript_OpponentEnter
	return


BattleArcade_RouletteRoom_EventScript_OpponentEnter::
	call BattleArcade_BattleRoom_EventScript_OpponentEnterMovement
	frontier_get FRONTIER_DATA_BATTLE_NUM
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_OpponentEnter_2
	copyvar VAR_TEMP_E, VAR_RESULT
	addvar VAR_TEMP_E, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_E
	msgbox BattleArcade_RouletteRoom_Text_Next, MSGBOX_DEFAULT
BattleArcade_RouletteRoom_EventScript_OpponentEnter_1:
	delay 15
	msgbox BattleArcade_RouletteRoom_Text_Go, MSGBOX_DEFAULT
	closemessage
	arcade_getopponentintro
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleArcade_RouletteRoom_EventScript_DoTowerBattle
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_RouletteRoom_EventScript_OpponentEnter_6
BattleArcade_RouletteRoom_EventScript_OpponentEnter_5:
	goto BattleArcade_RouletteRoom_EventScript_WarpToEntranceLost
	return

BattleArcade_RouletteRoom_EventScript_OpponentEnter_2:
	msgbox BattleArcade_RouletteRoom_Text_LetTheBattle, MSGBOX_DEFAULT
	goto BattleArcade_RouletteRoom_EventScript_OpponentEnter_1

BattleArcade_RouletteRoom_EventScript_OpponentEnter_6:
	goto BattleArcade_RouletteRoom_EventScript_DefeatedOpponent
	goto BattleArcade_RouletteRoom_EventScript_OpponentEnter_5


BattleArcade_RouletteRoom_EventScript_WarpToEntranceLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	arcade_set ARCADE_DATA_LVL_MODE
	goto BattleArcade_RouletteRoom_EventScript_WarpToEntrance
	return


BattleArcade_RouletteRoom_EventScript_WarpToEntrance::
	warp MAP_BATTLE_ARCADE_LOBBY, 7, 8
	waitstate
	end


BattleArcade_RouletteRoom_EventScript_DefeatedOpponent::
	arcade_setbattlewon
	call BattleArcade_BattleRoom_EventScript_DeafeatedOpponentMovement
	call BattleArcade_RouletteRoom_EventScript_StopChallenge
	msgbox BattleArcade_RouletteRoom_Text_WellDone, MSGBOX_DEFAULT
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_StopChallenge::
	arcade_checkmaxstreak
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_RouletteRoom_EventScript_StopChallenge_2
	msgbox BattleArcade_Entrance_MaxedOutStreak, MSGBOX_DEFAULT
	goto BattleArcade_RouletteRoom_EventScript_WarpToEntranceWon
	return

BattleArcade_RouletteRoom_EventScript_StopChallenge_2:
	return


BattleArcade_RouletteRoom_EventScript_AskReadyGetMenu::
	message BattleArcade_RouletteRoom_Text_DoYouWantToContinue
	waitmessage
	arcade_getcontinuemenutype
	return


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent::
	call BattleArcade_RouletteRoom_EventScript_AskReadyGetMenu
	switch VAR_RESULT
	case ARCADE_RECORDYES_HEALYES, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2
	case ARCADE_RECORDYES_HEALNO, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_3
	case ARCADE_RECORDNO_HEALYES, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4
	case ARCADE_RECORDNO_HEALNO, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_2:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_3:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_4:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_5:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo
	return


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo::
	multichoice 22, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_3
	case 1, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_4
	case 2, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_5
	case 3, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_6
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_7
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1:
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_3:
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_4:
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattle
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_5:
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_6:
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_7:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo_1


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo::
	multichoice 22, 5, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_3
	case 1, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_4
	case 2, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_5
	case 3, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_6
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_1:
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_3:
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_4:
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_5:
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_6:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo_1


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes::
	multichoice 22, 2, MULTI_GO_ON_HEAL_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_3
	case 1, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_4
	case 2, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_5
	case 3, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_6
	case 4, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_7
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_8
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1:
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_3:
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_4:
	goto BattleArcade_RouletteRoom_EventScript_AskHeal
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_5:
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattle
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_6:
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_7:
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_8:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealYes_1


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes::
	multichoice 22, 4, MULTI_GO_ON_HEAL_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_3
	case 1, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_4
	case 2, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_5
	case 3, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_6
	case 4, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_7
BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1:
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_3:
	goto BattleArcade_RouletteRoom_EventScript_ContinueChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_4:
	goto BattleArcade_RouletteRoom_EventScript_AskHeal
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_5:
	goto BattleArcade_RouletteRoom_EventScript_AskPauseChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_6:
	goto BattleArcade_RouletteRoom_EventScript_AskRetireChallenge
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_7:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealYes_1


BattleArcade_RouletteRoom_EventScript_AskHeal::
	buffernumberstring STR_VAR_1, VAR_ARCADE_HEAL_COUNT
	msgbox BattleArcade_RouletteRoom_Text_DoYouWantToRestore, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskHeal_2
BattleArcade_RouletteRoom_EventScript_AskHeal_1:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskHeal_2:
	frontier_restorehelditems
	arcade_restore
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal
	goto BattleArcade_RouletteRoom_EventScript_AskHeal_1


BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal::
	call BattleArcade_RouletteRoom_EventScript_AskReadyGetMenu
	switch VAR_RESULT
	case ARCADE_RECORDYES_HEALYES, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_2
	case ARCADE_RECORDYES_HEALNO, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_2
	case ARCADE_RECORDNO_HEALYES, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_3
	case ARCADE_RECORDNO_HEALNO, BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_3
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_2:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordYesHealNo
	return

BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent_PostHeal_3:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponentRecordNoHealNo
	return


BattleArcade_RouletteRoom_EventScript_AskRecordBattle::
	msgbox BattleArcade_Entrance_Text_RecordLastMatch, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_RouletteRoom_EventScript_AskRecordBattle_2
BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return

BattleArcade_RouletteRoom_EventScript_AskRecordBattle_2:
	call BattleFrontier_EventScript_SaveBattle
	goto BattleArcade_RouletteRoom_EventScript_AskRecordBattle_1


BattleArcade_RouletteRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	waitmessage
	switch VAR_RESULT
	case YES, BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2
	case NO, BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_3
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_3
	return

BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_2:
	goto BattleArcade_RouletteRoom_EventScript_PauseChallenge
	return

BattleArcade_RouletteRoom_EventScript_AskPauseChallenge_3:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_AskRetireChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge, MSGBOX_YESNO
	waitmessage
	switch VAR_RESULT
	case YES, BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2
	case NO, BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_3
	case MULTI_B_PRESSED, BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_3
	return

BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_2:
	goto BattleArcade_RouletteRoom_EventScript_WarpToEntranceWon
	return

BattleArcade_RouletteRoom_EventScript_AskRetireChallenge_3:
	goto BattleArcade_RouletteRoom_EventScript_AskReadyForOpponent
	return


BattleArcade_RouletteRoom_EventScript_ContinueChallenge::
	closemessage
	call BattleArcade_RouletteRoom_EventScript_RefreshOpponent
	call BattleArcade_BattleRoom_EventScript_ContinueChallengeMovement
	goto BattleArcade_RouletteRoom_EventScript_OpponentEnter
	return


BattleArcade_RouletteRoom_EventScript_WarpToEntranceWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	arcade_set TOWER_DATA_LVL_MODE
	goto BattleArcade_RouletteRoom_EventScript_WarpToEntrance
	return


BattleArcade_RouletteRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	arcade_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end


BattleArcade_RouletteRoom_EventScript_DoTowerBattle::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	setvar VAR_0x8004, SPECIAL_BATTLE_ARCADE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	arcade_restorehelditems
	arcade_resetsketch
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return


BattleArcade_Entrance_Text_RulesAreListed::
	.string "The BATTLE ARCADE rules are listed.$"

BattleArcade_Entrance_Text_OverviewBoard::
	.string "BATTLE ARCADE is challenges you to\n"
	.string "battle using up to three POKéMON of a\n"
	.string "single type. Select a level mode and a\l"
	.string "type, then battle your way through\l"
	.string "five consecutive battles.$"

BattleArcade_Entrance_Text_RestrictionsBoard::
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\n"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

BattleArcade_Entrance_Text_RewardsBoard::
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\n"
	.string "continue to increase your streak.\l"
	.string "You'll recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

BattleArcade_Entrance_Text_HiyahDo::
	.string "Hi-yah! {PLAYER}! Do you want to try\n"
	.string "BATTLE ARCADE?$"

BattleArcade_Entrance_Text_SelectTheTypeYouWant::
	.string "Select the type you want to use for\n"
	.string "arcade.$"

BattleArcade_Entrance_Text_IWontForceYou::
	.string "I won't force you to do anything you\n"
	.string "don't want to do. Some other time, then.$"

BattleArcade_Entrance_Text_BattleArcadeIsATraining::
	.string "BATTLE ARCADE is a training course that\n"
	.string "restricts the type of POKéMON you can\n"
	.string "use. Select a type first, and then\l"
	.string "battle using up to three POKéMON of\l"
	.string "that type. No duplicate POKéMON or\l"
	.string "items are allowed. If you can win five\l"
	.string "times in a row, you'll complete the\l"
	.string "training. However, if you lose even\l"
	.string "once, the arcade will end there! You\l"
	.string "can restore your POKéMON between\l"
	.string "battles, but only twice in total, so use\l"
	.string "the opportunities very wisely. That's\l"
	.string "all! Do you want to try BATTLE ARCADE?$"

BattleArcade_Entrance_Text_OhYouChangedYour::
	.string "Oh, you changed your mind? Some other\n"
	.string "time, then.$"

BattleArcade_Entrance_Text_YouLostbutTrainYourself::
	.string "You lost...but train yourself and your\n"
	.string "POKéMON, and try again! I'm looking\n"
	.string "forward to your next challenge.$"

BattleArcade_Entrance_Text_YourResultForThisRestricted::
	.string "Your result for this BATTLE ARCADE set\n"
	.string "is... You had {STR_VAR_1} win(s) with\n"
	.string "the {STR_VAR_3}-type POKéMON\l"
	.string "restriction!$"

BattleArcade_Entrance_Text_TheWayYouHandleType::
	.string "The way you handle\n"
	.string "{STR_VAR_3}-type POKéMON is\n"
	.string "flawless!$"

BattleArcade_Entrance_Text_WhatYouCompletedRestricted::
	.string "What?! You completed BATTLE ARCADE\n"
	.string "with {STR_VAR_1} type(s)?!$"

BattleArcade_Entrance_Text_ThatsExcellentWork::
	.string "That's excellent work!$"

BattleArcade_Entrance_Text_ICantBelieveIt::
	.string "I can't believe it... Your achievement is\n"
	.string "just phenomenal!$"

BattleArcade_Entrance_Text_ThisAccomplishmentIsSureTo::
	.string "This accomplishment is sure to go down\n"
	.string "in dojo history!$"

BattleArcade_Entrance_Text_ToCommemorateThisMonumentalAchievement::
	.string "To commemorate this monumental\n"
	.string "achievement, I'll grant you this!$"

BattleArcade_Entrance_Text_IHopeYoullKeep::
	.string "I hope you'll keep exceeding your own\n"
	.string "limits!$"

BattleArcade_Entrance_Text_DidntSaveBeforeQuitting::
	.string "Oops! {PLAYER}, it seems you didn't\n"
	.string "save before quitting your challenge\n"
	.string "last time. Because of that, your\l"
	.string "challenge so far has been disqualified.\l"
	.string "Sorry!$"

BattleArcade_Entrance_Text_ThankYouForPlaying::
	.string "Thanks for playing, {PLAYER}!$"

BattleArcade_Entrance_Text_RecordWillBeSaved::
	.string "Your record will be saved soon.$"

BattleArcade_Entrance_Text_WeveBeenWaitingForYou::
	.string "We've been waiting for you, {PLAYER}!$"

BattleArcade_Entrance_Text_ProgressWillBeSaved::
	.string "Before entering the BATTLE COURT, your\n"
	.string "progress will be saved. Hang tight!$"

BattleArcade_Entrance_Text_ThereWasAGlitch::
	.string "Oops! There was a glitch, and your\n"
	.string "record couldn't be saved. Better luck\n"
	.string "next time!$"

BattleArcade_Entrance_Text_OffersTwoLevels::
	.string "BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level. So,\n"
	.string "which one is your pick?$"

BattleArcade_Entrance_Text_BeforeDivingInto::
	.string "Before diving into BATTLE ARCADE, your\n"
	.string "progress must be saved. Is that cool?$"

BattleArcade_Entrance_Text_NotEnoughValidMonsLv50Singles::
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON of Level 50 or less\n"
	.string "to enter. They must all share the\l"
	.string "{STR_VAR_3}-type and hold\l"
	.string "different items. EGGS{STR_VAR_1}\l"
	.string "not allowed. Come back when you're\l"
	.string "ready!$"

BattleArcade_Entrance_Text_NotEnoughValidMonsLvOpenSingles::
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON to enter. They must\n"
	.string "all share the {STR_VAR_3}-type and\l"
	.string "hold different items.\l"
	.string "EGGS{STR_VAR_1} not allowed. Come\l"
	.string "back when you're ready!$"

BattleArcade_Entrance_Text_RecordLastMatch::
	.string "Want me to record your last BATTLE\n"
	.string "ARCADE match on your FRONTIER PASS?$"

BattleArcade_Entrance_Text_YouEarned::
	.string "You earned {STR_VAR_2} BP!$"

BattleArcade_RouletteRoom_Text_WellDone::
	.string "Well done!$"

BattleArcade_RouletteRoom_Text_LetTheBattle::
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Next::
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Go::
	.string "Go!$"

BattleArcade_RouletteRoom_Text_DoYouWantToContinue::
	.string "Do you want to continue arcade?$"

BattleArcade_RouletteRoom_Text_DoYouWantToRestore::
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\n"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"
