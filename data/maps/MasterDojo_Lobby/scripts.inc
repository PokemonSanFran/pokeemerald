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
	call MasterDojo_Lobby_EventScript_CreateTypeList
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, MasterDojo_Lobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
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
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MasterDojo_Lobby_EventScript_CreateTypeList_3
	case 1, MasterDojo_Lobby_EventScript_CreateTypeList_4
	case 2, MasterDojo_Lobby_EventScript_CreateTypeList_5
	case 3, MasterDojo_Lobby_EventScript_CreateTypeList_6
	case 4, MasterDojo_Lobby_EventScript_CreateTypeList_7
	case 5, MasterDojo_Lobby_EventScript_CreateTypeList_8
	case 6, MasterDojo_Lobby_EventScript_CreateTypeList_9
	case 7, MasterDojo_Lobby_EventScript_CreateTypeList_10
	case 8, MasterDojo_Lobby_EventScript_CreateTypeList_11
	case 9, MasterDojo_Lobby_EventScript_CreateTypeList_12
	case 10, MasterDojo_Lobby_EventScript_CreateTypeList_13
	case 11, MasterDojo_Lobby_EventScript_CreateTypeList_14
	case 12, MasterDojo_Lobby_EventScript_CreateTypeList_15
	case 13, MasterDojo_Lobby_EventScript_CreateTypeList_16
	case 14, MasterDojo_Lobby_EventScript_CreateTypeList_17
	case 15, MasterDojo_Lobby_EventScript_CreateTypeList_18
	case 16, MasterDojo_Lobby_EventScript_CreateTypeList_19
	case MULTI_B_PRESSED, MasterDojo_Lobby_EventScript_CreateTypeList_20
MasterDojo_Lobby_EventScript_CreateTypeList_20:
	goto MasterDojo_Lobby_EventScript_CancelChallenge
MasterDojo_Lobby_EventScript_CreateTypeList_1:
	sparring_buffersparringtype
	return

MasterDojo_Lobby_EventScript_CreateTypeList_3:
	setvar VAR_SPARRING_TYPE, TYPE_NORMAL
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_4:
	setvar VAR_SPARRING_TYPE, TYPE_FIGHTING
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_5:
	setvar VAR_SPARRING_TYPE, TYPE_FLYING
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_6:
	setvar VAR_SPARRING_TYPE, TYPE_POISON
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_7:
	setvar VAR_SPARRING_TYPE, TYPE_GROUND
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_8:
	setvar VAR_SPARRING_TYPE, TYPE_ROCK
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_9:
	setvar VAR_SPARRING_TYPE, TYPE_BUG
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_10:
	setvar VAR_SPARRING_TYPE, TYPE_GHOST
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_11:
	setvar VAR_SPARRING_TYPE, TYPE_STEEL
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_12:
	setvar VAR_SPARRING_TYPE, TYPE_FIRE
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_13:
	setvar VAR_SPARRING_TYPE, TYPE_WATER
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_14:
	setvar VAR_SPARRING_TYPE, TYPE_GRASS
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_15:
	setvar VAR_SPARRING_TYPE, TYPE_ELECTRIC
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_16:
	setvar VAR_SPARRING_TYPE, TYPE_PSYCHIC
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_17:
	setvar VAR_SPARRING_TYPE, TYPE_ICE
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_18:
	setvar VAR_SPARRING_TYPE, TYPE_DRAGON
	goto MasterDojo_Lobby_EventScript_CreateTypeList_1

MasterDojo_Lobby_EventScript_CreateTypeList_19:
	setvar VAR_SPARRING_TYPE, TYPE_DARK
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
	goto MasterDojo_Lobby_EventScript_SaveBeforeChallenge
	goto MasterDojo_Lobby_EventScript_ExplainChallenge_1


MasterDojo_Lobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_SPARRING, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end


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
	sparring_save CHALLENGE_STATUS_SAVING
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	frontier_saveparty
	setvar VAR_RESULT, 0
	setvar VAR_RESTRICTEDSPARRING_HEAL_COUNT, SPARRING_MAX_NUM_RESTORE
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
	call MasterDojo_Lobby_EventScript_AskSaveBattle
	msgbox MasterDojo_Lobby_Text_YouLostbutTrainYourself, MSGBOX_DEFAULT
	goto MasterDojo_Lobby_EventScript_SetChallengeStatusEnd
	return


MasterDojo_Lobby_EventScript_Results::
	lock
	faceplayer
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


MasterDojo_Lobby_EventScript_PositiveExitMessage::
	return


MasterDojo_Lobby_EventScript_AwardPoints::
	sparring_givepoints
	msgbox MasterDojo_Lobby_Text_YouEarned
	return


MasterDojo_Lobby_EventScript_CheckSymbol::
	sparring_checksymbol
	compare VAR_RESULT, SPARRING_GET_NONE
	goto_if_gt MasterDojo_Lobby_EventScript_CheckSymbol_2
MasterDojo_Lobby_EventScript_CheckSymbol_1:
	return

MasterDojo_Lobby_EventScript_CheckSymbol_2:
	call MasterDojo_Lobby_EventScript_GiveSymbol
	goto MasterDojo_Lobby_EventScript_CheckSymbol_1


MasterDojo_Lobby_EventScript_GiveSymbol::
	msgbox MasterDojo_Lobby_Text_WhatYouCompletedRestricted
	compare VAR_RESULT, SPARRING_GET_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_2
	msgbox MasterDojo_Lobby_Text_ICantBelieveIt
	msgbox MasterDojo_Lobby_Text_ThisAccomplishmentIsSureTo
MasterDojo_Lobby_EventScript_GiveSymbol_1:
	msgbox MasterDojo_Lobby_Text_ToCommemorateThisMonumentalAchievement
	playfanfare MUS_OBTAIN_SYMBOL
	compare VAR_RESULT, SPARRING_GET_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_6
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
MasterDojo_Lobby_EventScript_GiveSymbol_5:
	waitmessage
	waitfanfare
	compare VAR_RESULT, SPARRING_GET_SILVER
	goto_if_eq MasterDojo_Lobby_EventScript_GiveSymbol_10
	setflag FLAG_SYS_ARENA_GOLD
	msgbox MasterDojo_Lobby_Text_IHopeYoullKeep
MasterDojo_Lobby_EventScript_GiveSymbol_9:
	return

MasterDojo_Lobby_EventScript_GiveSymbol_2:
	msgbox MasterDojo_Lobby_Text_ThatsExcellentWork
	goto MasterDojo_Lobby_EventScript_GiveSymbol_1

MasterDojo_Lobby_EventScript_GiveSymbol_6:
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
	goto MasterDojo_Lobby_EventScript_GiveSymbol_5

MasterDojo_Lobby_EventScript_GiveSymbol_10:
	setflag FLAG_SYS_ARENA_SILVER
	goto MasterDojo_Lobby_EventScript_GiveSymbol_9


MasterDojo_Lobby_EventScript_AskSaveBattle::
	message MasterDojo_Lobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	sparring_save 0
	playse SE_SAVE
	waitse
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


MasterDojo_Lobby_Text_HiyahDo::
	.string "Hi-yah! {PLAYER}! Do you want to try\n"
	.string "Restricted Sparring?$"

MasterDojo_Lobby_Text_SelectTheTypeYouWant::
	.string "Select the type you want to use for\n"
	.string "sparring.$"

MasterDojo_Lobby_Text_IWontForceYou::
	.string "I won't force you to do anything you\n"
	.string "don't want to do. Some other time, then.$"

MasterDojo_Lobby_Text_RestrictedSparringIsATraining::
	.string "Restricted Sparring is a training\n"
	.string "course that restricts the type of\l"
	.string "Pokémon you can use. Select a type\l"
	.string "first, and then battle using up to\l"
	.string "three Pokémon of that type. No\l"
	.string "duplicate Pokémon or items are allowed.\l"
	.string "If you can win five times in a row,\l"
	.string "you'll complete the training. However,\l"
	.string "if you lose even once, the sparring will\l"
	.string "end there! You can restore your\l"
	.string "Pokémon between battles, but only\l"
	.string "twice in total, so use the\l"
	.string "opportunities very wisely. That's all!\l"
	.string "Do you want to try Restricted\l"
	.string "Sparring?$"

MasterDojo_Lobby_Text_OhYouChangedYour::
	.string "Oh, you changed your mind? Some other\n"
	.string "time, then.$"

MasterDojo_Lobby_Text_LetTheBattlesBegin::
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

MasterDojo_Lobby_Text_NextBattleNo::
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

MasterDojo_Lobby_Text_Go::
	.string "Go!$"

MasterDojo_Lobby_Text_DoYouWantToRestore::
	.string "Do you want to restore your Pokémon?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more {STR_VAR_2}.)$"

MasterDojo_Lobby_Text_YouLostbutTrainYourself::
	.string "You lost...but train yourself and your\n"
	.string "Pokémon, and try again! I'm looking\l"
	.string "forward to your next challenge.$"

MasterDojo_Lobby_Text_YourResultForThisRestricted::
	.string "Your result for this Restricted\n"
	.string "Sparring set is... You had\l"
	.string "{STR_VAR_1} wins with the\l"
	.string "{STR_VAR_3}-type Pokémon\l"
	.string "restriction!$"

MasterDojo_Lobby_Text_TheWayYouHandleType::
	.string "The way you handle\n"
	.string "{STR_VAR_3}-type Pokémon is\l"
	.string "flawless!$"

MasterDojo_Lobby_Text_WhatYouCompletedRestricted::
	.string "What?! You completed Restricted\n"
	.string "Sparring with {STR_VAR_1} types?!$"

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

MasterDojo_Lobby_Text_DoYouWantToContinueNoHeal::
	.string "Do you want to continue sparring?$"

MasterDojo_Lobby_Text_DoYouWantToContinue::
	.string "Do you want to continue sparring? (You\n"
	.string "can restore them {STR_VAR_1} more\l"
	.string "{STR_VAR_2}.)$"

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
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Hang tight!$"

MasterDojo_Lobby_Text_ThereWasAGlitch::
	.string "Oops! There was a glitch, and your\n"
	.string "record couldn't be saved. Better luck\l"
	.string "next time!$"

MasterDojo_Lobby_Text_OffersTwoLevels::
	.string "Restricted Sparring offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "So, which one is your pick?$"

MasterDojo_Lobby_Text_BeforeDivingInto::
	.string "Before diving into Restricted Sparring,\n"
	.string "your progress must be saved. Is that\l"
	.string "cool?$"

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
	.string "Want me to record your last Restricted\n"
	.string "Sparring match on your FRONTIER PASS?$"

MasterDojo_Lobby_Text_YouEarned::
	.string "You earned {STR_VAR_1} BP!$"
