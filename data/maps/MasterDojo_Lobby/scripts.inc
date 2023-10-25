MasterDojo_Lobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, MasterDojo_Lobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, MasterDojo_Lobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, MasterDojo_Lobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, MasterDojo_Lobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, MasterDojo_Lobby_EventScript_LostChallenge
	.2byte 0

MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, MasterDojo_Lobby_EventScript_PlayerFaceNorth
	.2byte 0


MasterDojo_Lobby_EventScript_PlayerFaceNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


MasterDojo_Lobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end


MasterDojo_Lobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox MasterDojo_Lobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	sparring_set SPARRING_DATA_WIN_STREAK, 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	goto MasterDojo_Lobby_EventScript_SetChallengeStatusEnd
	return


MasterDojo_Lobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_SPARRING
	special SavePlayerParty
	goto MasterDojo_Lobby_EventScript_AskEnterChallenge
	return


MasterDojo_Lobby_EventScript_AskEnterChallenge::
	message MasterDojo_Lobby_Text_HiyahDo
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, MasterDojo_Lobby_EventScript_AskEnterChallenge_2
	case 1, MasterDojo_Lobby_EventScript_AskEnterChallenge_3
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_AskEnterChallenge_4
	case 2, MasterDojo_Lobby_EventScript_AskEnterChallenge_4
	return

MasterDojo_Lobby_EventScript_AskEnterChallenge_2:
	goto MasterDojo_Lobby_EventScript_TryEnterChallenge
	return

MasterDojo_Lobby_EventScript_AskEnterChallenge_3:
	goto MasterDojo_Lobby_EventScript_ExplainChallenge
	return

MasterDojo_Lobby_EventScript_AskEnterChallenge_4:
	goto MasterDojo_Lobby_EventScript_DenyChallenge
	return


MasterDojo_Lobby_EventScript_TryEnterChallenge::
	message MasterDojo_Lobby_Text_OffersTwoLevels
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, MasterDojo_Lobby_EventScript_TryEnterChallenge_3
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_TryEnterChallenge_3
MasterDojo_Lobby_EventScript_TryEnterChallenge_1:
	message MasterDojo_Lobby_Text_SelectTheTypeYouWant
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	call MasterDojo_Lobby_EventScript_CreateTypeList
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, MasterDojo_Lobby_EventScript_NotEnoughValidMons
	fadescreen FADE_TO_BLACK
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, MasterDojo_Lobby_EventScript_LoadPartyCancelChallenge
	msgbox MasterDojo_Lobby_Text_BeforeDivingInto, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, MasterDojo_Lobby_EventScript_TryEnterChallenge_5
	case NO, MasterDojo_Lobby_EventScript_TryEnterChallenge_6
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_TryEnterChallenge_6
	return

MasterDojo_Lobby_EventScript_TryEnterChallenge_3:
	goto MasterDojo_Lobby_EventScript_CancelChallenge
	goto MasterDojo_Lobby_EventScript_TryEnterChallenge_1

MasterDojo_Lobby_EventScript_TryEnterChallenge_5:
	goto MasterDojo_Lobby_EventScript_SaveBeforeChallenge
	return

MasterDojo_Lobby_EventScript_TryEnterChallenge_6:
	goto MasterDojo_Lobby_EventScript_LoadPartyCancelChallenge
	return


MasterDojo_Lobby_EventScript_CreateTypeList::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_TYPE
	special Sparring_ShowWinsWindow
	special ShowScrollableMultichoice
	waitstate
	special Sparring_CloseWinsWindow
	switch VAR_RESULT
	case 17, MasterDojo_Lobby_EventScript_CreateTypeList_4
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_CreateTypeList_4
	sparring_convertmenutotype
MasterDojo_Lobby_EventScript_CreateTypeList_1:
	sparring_buffersparringtype
	return

MasterDojo_Lobby_EventScript_CreateTypeList_4:
	goto MasterDojo_Lobby_EventScript_CancelChallenge
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1


MasterDojo_Lobby_EventScript_SaveBeforeChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	sparring_init
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	special HealPlayerParty
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq MasterDojo_Lobby_EventScript_SaveBeforeChallenge_2
MasterDojo_Lobby_EventScript_SaveBeforeChallenge_1:
	goto MasterDojo_Lobby_EventScript_EnterElevator
	return

MasterDojo_Lobby_EventScript_SaveBeforeChallenge_2:
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
	goto MasterDojo_Lobby_EventScript_DenyChallenge
	goto MasterDojo_Lobby_EventScript_SaveBeforeChallenge_1


MasterDojo_Lobby_EventScript_ExplainChallenge::
	msgbox MasterDojo_Lobby_Text_RestrictedSparringIsATraining, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MasterDojo_Lobby_EventScript_ExplainChallenge_2
MasterDojo_Lobby_EventScript_ExplainChallenge_1:
	msgbox MasterDojo_Lobby_Text_IWontForceYou, MSGBOX_DEFAULT
	releaseall
	end

MasterDojo_Lobby_EventScript_ExplainChallenge_2:
	goto MasterDojo_Lobby_EventScript_TryEnterChallenge
	goto MasterDojo_Lobby_EventScript_ExplainChallenge_1


MasterDojo_Lobby_EventScript_NotEnoughValidMons::
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq MasterDojo_Lobby_EventScript_NotEnoughValidMons_2
	msgbox MasterDojo_Lobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
MasterDojo_Lobby_EventScript_NotEnoughValidMons_1:
	release
	end

MasterDojo_Lobby_EventScript_NotEnoughValidMons_2:
	msgbox MasterDojo_Lobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_NotEnoughValidMons_1


MasterDojo_Lobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	goto MasterDojo_Lobby_EventScript_CancelChallenge
	return


MasterDojo_Lobby_EventScript_CancelChallenge::
	msgbox MasterDojo_Lobby_Text_OhYouChangedYour, MSGBOX_DEFAULT
	release
	end


MasterDojo_Lobby_EventScript_DenyChallenge::
	msgbox MasterDojo_Lobby_Text_IWontForceYou, MSGBOX_DEFAULT
	release
	end


MasterDojo_Lobby_EventScript_EnterElevator::
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	frontier_saveparty
	setvar VAR_RESULT, 0
	warp MAP_MASTER_DOJO_BATTLE_ROOM, 0, 6
	sparring_save CHALLENGE_STATUS_SAVING
	return


MasterDojo_Lobby_EventScript_WonChallenge::
	sparring_get SPARRING_DATA_WIN_STREAK
	buffernumberstring STR_VAR_1, VAR_RESULT
	goto MasterDojo_Lobby_EventScript_Results
	return


MasterDojo_Lobby_EventScript_LostChallenge::
	sparring_get SPARRING_DATA_WIN_STREAK
	buffernumberstring STR_VAR_1, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq MasterDojo_Lobby_EventScript_LostChallenge_1
	goto MasterDojo_Lobby_EventScript_Results
	return

MasterDojo_Lobby_EventScript_LostChallenge_1:
	goto MasterDojo_Lobby_EventScript_Results_NoWins
	return


MasterDojo_Lobby_EventScript_Results_NoWins::
	lock
	faceplayer
	call MasterDojo_Lobby_EventScript_SaveResult
	call MasterDojo_Lobby_EventScript_AskSaveBattle
	msgbox MasterDojo_Lobby_Text_YouLostbutTrainYourself, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_SetChallengeStatusEnd
	return


MasterDojo_Lobby_EventScript_Results::
	lock
	faceplayer
	call MasterDojo_Lobby_EventScript_SaveResult
	sparring_buffersparringtype
	msgbox MasterDojo_Lobby_Text_YourResultForThisRestricted
	call MasterDojo_Lobby_EventScript_AwardPoints
	goto_if_set FLAG_SPARRING_FIRST_TYPE_WIN, MasterDojo_Lobby_EventScript_Results_2
MasterDojo_Lobby_EventScript_Results_1:
	call MasterDojo_Lobby_EventScript_AskSaveBattle
	goto MasterDojo_Lobby_EventScript_SetChallengeStatusEnd
	return

MasterDojo_Lobby_EventScript_Results_2:
	msgbox MasterDojo_Lobby_Text_TheWayYouHandleType
	call MasterDojo_Lobby_EventScript_CheckSymbol
	goto MasterDojo_Lobby_EventScript_Results_1


MasterDojo_Lobby_EventScript_SaveResult::
	message MasterDojo_Lobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	sparring_givepoints
	sparring_checksymbol
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_SaveResult_2
	compare VAR_RESULT, SPARRING_SYMBOL_GOLD
	goto_if_eq MasterDojo_Lobby_EventScript_SaveResult_3
MasterDojo_Lobby_EventScript_SaveResult_1:
	special LoadPlayerParty
	sparring_save 0
	playse SE_SAVE
	waitse
	return

MasterDojo_Lobby_EventScript_SaveResult_2:
	setflag FLAG_SYS_ARENA_SILVER
	goto MasterDojo_Lobby_EventScript_SaveResult_1

MasterDojo_Lobby_EventScript_SaveResult_3:
	setflag FLAG_SYS_ARENA_GOLD
	goto MasterDojo_Lobby_EventScript_SaveResult_1


MasterDojo_Lobby_EventScript_AwardPoints::
	msgbox MasterDojo_Lobby_Text_YouEarned
	return


MasterDojo_Lobby_EventScript_CheckSymbol::
	sparring_checksymbol
	compare VAR_RESULT, SPARRING_SYMBOL_NONE
	goto_if_gt MasterDojo_Lobby_EventScript_CheckSymbol_2
MasterDojo_Lobby_EventScript_CheckSymbol_1:
	return

MasterDojo_Lobby_EventScript_CheckSymbol_2:
	call MasterDojo_Lobby_EventScript_GiveSymbol
	goto MasterDojo_Lobby_EventScript_CheckSymbol_1


MasterDojo_Lobby_EventScript_GiveSymbol::
	msgbox MasterDojo_Lobby_Text_WhatYouCompletedRestricted
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_2
	msgbox MasterDojo_Lobby_Text_ICantBelieveIt
	msgbox MasterDojo_Lobby_Text_ThisAccomplishmentIsSureTo
MasterDojo_Lobby_EventScript_GiveSymbol_1:
	msgbox MasterDojo_Lobby_Text_ToCommemorateThisMonumentalAchievement
	playfanfare MUS_OBTAIN_SYMBOL
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_6
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
MasterDojo_Lobby_EventScript_GiveSymbol_5:
	waitmessage
	waitfanfare
	compare VAR_RESULT, SPARRING_SYMBOL_GOLD
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_10
MasterDojo_Lobby_EventScript_GiveSymbol_9:
	return

MasterDojo_Lobby_EventScript_GiveSymbol_2:
	msgbox MasterDojo_Lobby_Text_ThatsExcellentWork
	goto MasterDojo_Lobby_EventScript_GiveSymbol_1

MasterDojo_Lobby_EventScript_GiveSymbol_6:
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
	goto MasterDojo_Lobby_EventScript_GiveSymbol_5

MasterDojo_Lobby_EventScript_GiveSymbol_10:
	msgbox MasterDojo_Lobby_Text_IHopeYoullKeep
	goto MasterDojo_Lobby_EventScript_GiveSymbol_9


MasterDojo_Lobby_EventScript_AskSaveBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	compare VAR_RESULT, TRUE
	goto_if_eq MasterDojo_Lobby_EventScript_AskSaveBattle_2
	message MasterDojo_Lobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	compare VAR_RESULT, 0
	goto_if_eq MasterDojo_Lobby_EventScript_AskSaveBattle_5
MasterDojo_Lobby_EventScript_AskSaveBattle_4:
	return

MasterDojo_Lobby_EventScript_AskSaveBattle_2:
	return

MasterDojo_Lobby_EventScript_AskSaveBattle_5:
	call MasterDojo_Lobby_EventScript_SaveBattle
	goto MasterDojo_Lobby_EventScript_AskSaveBattle_4


MasterDojo_Lobby_EventScript_SaveBattle::
	frontier_savebattle
	compare VAR_RESULT, 0
	goto_if_ne MasterDojo_Lobby_EventScript_SaveBattle_2
	msgbox MasterDojo_Lobby_Text_ThereWasAGlitch, MSGBOX_DEFAULT
MasterDojo_Lobby_EventScript_SaveBattle_1:
	return

MasterDojo_Lobby_EventScript_SaveBattle_2:
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_SaveBattle_1


MasterDojo_Lobby_EventScript_SetChallengeStatusEnd::
	setvar VAR_TEMP_0, 255
	goto MasterDojo_Lobby_EventScript_EndChallenge
	return


MasterDojo_Lobby_EventScript_EndChallenge::
	closemessage
	setvar VAR_SPARRING_TYPE, TYPE_NONE
	release
	end


MasterDojo_Lobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	message MasterDojo_Lobby_Text_WeveBeenWaitingForYou
	waitmessage
	message MasterDojo_Lobby_Text_ProgressWillBeSaved
	waitmessage
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto MasterDojo_Lobby_EventScript_EnterElevator
	end


MasterDojo_Lobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_SPARRING, 0
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end


MasterDojo_EventScript_RulesBoard::
	lockall
	msgbox MasterDojo_Lobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_ReadRulesBoard
	end


MasterDojo_Lobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_RESTRICTED_SPARRING_RULES, FALSE
	switch VAR_RESULT
	case 0, MasterDojo_Lobby_EventScript_ReadRulesBoard_3
	case 1, MasterDojo_Lobby_EventScript_ReadRulesBoard_4
	case 2, MasterDojo_Lobby_EventScript_ReadRulesBoard_5
	case 3, MasterDojo_Lobby_EventScript_ReadRulesBoard_6
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_ReadRulesBoard_6
MasterDojo_Lobby_EventScript_ReadRulesBoard_1:
	goto MasterDojo_EventScript_RulesBoard
	end

MasterDojo_Lobby_EventScript_ReadRulesBoard_3:
	msgbox MasterDojo_Lobby_Text_OverviewBoard, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_ReadRulesBoard_1

MasterDojo_Lobby_EventScript_ReadRulesBoard_4:
	msgbox MasterDojo_Lobby_Text_RestrictionsBoard, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_ReadRulesBoard_1

MasterDojo_Lobby_EventScript_ReadRulesBoard_5:
	msgbox MasterDojo_Lobby_Text_RewardsBoard, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_ReadRulesBoard_1

MasterDojo_Lobby_EventScript_ReadRulesBoard_6:
	releaseall
	end


MasterDojo_Lobby_Text_RulesAreListed::
	.string "The RESTRICTED SPARRING rules are\n"
	.string "listed.$"

MasterDojo_Lobby_Text_OverviewBoard::
	.string "RESTRICTED SPARRING is challenges you\n"
	.string "to battle using up to three POKéMON of\l"
	.string "a single type. Select a level mode and a\l"
	.string "type, then battle your way through\l"
	.string "five consecutive battles.$"

MasterDojo_Lobby_Text_RestrictionsBoard::
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\l"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

MasterDojo_Lobby_Text_RewardsBoard::
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\l"
	.string "continue to increase your streak.\l"
	.string "You'll recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

MasterDojo_Lobby_Text_HiyahDo::
	.string "Hi-yah! {PLAYER}! Do you want to try\n"
	.string "RESTRICTED SPARRING?$"

MasterDojo_Lobby_Text_SelectTheTypeYouWant::
	.string "Select the type you want to use for\n"
	.string "sparring.$"

MasterDojo_Lobby_Text_IWontForceYou::
	.string "I won't force you to do anything you\n"
	.string "don't want to do. Some other time, then.$"

MasterDojo_Lobby_Text_RestrictedSparringIsATraining::
	.string "RESTRICTED SPARRING is a training\n"
	.string "course that restricts the type of\l"
	.string "POKéMON you can use. Select a type\l"
	.string "first, and then battle using up to\l"
	.string "three POKéMON of that type. No\l"
	.string "duplicate POKéMON or items are allowed.\l"
	.string "If you can win five times in a row,\l"
	.string "you'll complete the training. However,\l"
	.string "if you lose even once, the sparring will\l"
	.string "end there! You can restore your\l"
	.string "POKéMON between battles, but only\l"
	.string "twice in total, so use the\l"
	.string "opportunities very wisely. That's all!\l"
	.string "Do you want to try RESTRICTED\l"
	.string "SPARRING?$"

MasterDojo_Lobby_Text_OhYouChangedYour::
	.string "Oh, you changed your mind? Some other\n"
	.string "time, then.$"

MasterDojo_Lobby_Text_YouLostbutTrainYourself::
	.string "You lost...but train yourself and your\n"
	.string "POKéMON, and try again! I'm looking\l"
	.string "forward to your next challenge.$"

MasterDojo_Lobby_Text_YourResultForThisRestricted::
	.string "Your result for this RESTRICTED\n"
	.string "SPARRING set is... You had\l"
	.string "{STR_VAR_1} win(s) with the\l"
	.string "{STR_VAR_3}-type POKéMON\l"
	.string "restriction!$"

MasterDojo_Lobby_Text_TheWayYouHandleType::
	.string "The way you handle\n"
	.string "{STR_VAR_3}-type POKéMON is\l"
	.string "flawless!$"

MasterDojo_Lobby_Text_WhatYouCompletedRestricted::
	.string "What?! You completed RESTRICTED\n"
	.string "SPARRING with {STR_VAR_1}\l"
	.string "type(s)?!$"

MasterDojo_Lobby_Text_ThatsExcellentWork::
	.string "That's excellent work!$"

MasterDojo_Lobby_Text_ICantBelieveIt::
	.string "I can't believe it... Your achievement is\n"
	.string "just phenomenal!$"

MasterDojo_Lobby_Text_ThisAccomplishmentIsSureTo::
	.string "This accomplishment is sure to go down\n"
	.string "in dojo history!$"

MasterDojo_Lobby_Text_ToCommemorateThisMonumentalAchievement::
	.string "To commemorate this monumental\n"
	.string "achievement, I'll grant you this!$"

MasterDojo_Lobby_Text_IHopeYoullKeep::
	.string "I hope you'll keep exceeding your own\n"
	.string "limits!$"

MasterDojo_Lobby_Text_DidntSaveBeforeQuitting::
	.string "Oops! {PLAYER}, it seems you didn't\n"
	.string "save before quitting your challenge\l"
	.string "last time. Because of that, your\l"
	.string "challenge so far has been disqualified.\l"
	.string "Sorry!$"

MasterDojo_Lobby_Text_ThankYouForPlaying::
	.string "Thanks for playing, {PLAYER}!$"

MasterDojo_Lobby_Text_RecordWillBeSaved::
	.string "Your record will be saved soon.$"

MasterDojo_Lobby_Text_WeveBeenWaitingForYou::
	.string "We've been waiting for you, {PLAYER}!$"

MasterDojo_Lobby_Text_ProgressWillBeSaved::
	.string "Before entering the BATTLE COURT, your\n"
	.string "progress will be saved. Hang tight!$"

MasterDojo_Lobby_Text_ThereWasAGlitch::
	.string "Oops! There was a glitch, and your\n"
	.string "record couldn't be saved. Better luck\l"
	.string "next time!$"

MasterDojo_Lobby_Text_OffersTwoLevels::
	.string "RESTRICTED SPARRING offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "So, which one is your pick?$"

MasterDojo_Lobby_Text_BeforeDivingInto::
	.string "Before diving into RESTRICTED\n"
	.string "SPARRING, your progress must be saved.\l"
	.string "Is that cool?$"

MasterDojo_Lobby_Text_NotEnoughValidMonsLv50Singles::
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON of Level 50 or less\l"
	.string "to enter. They must all share the\l"
	.string "{STR_VAR_3}-type and hold\l"
	.string "different items. EGGS{STR_VAR_1}\l"
	.string "not allowed. Come back when you're\l"
	.string "ready!$"

MasterDojo_Lobby_Text_NotEnoughValidMonsLvOpenSingles::
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON to enter. They must\l"
	.string "all share the {STR_VAR_3}-type and\l"
	.string "hold different items.\l"
	.string "EGGS{STR_VAR_1} not allowed. Come\l"
	.string "back when you're ready!$"

MasterDojo_Lobby_Text_RecordLastMatch::
	.string "Want me to record your last RESTRICTED\n"
	.string "SPARRING match on your FRONTIER\l"
	.string "PASS?$"

MasterDojo_Lobby_Text_YouEarned::
	.string "You earned {STR_VAR_1} BP!$"
