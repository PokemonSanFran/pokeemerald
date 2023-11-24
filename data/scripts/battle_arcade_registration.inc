BattleArcade_Entrance_EventScript_GetChallengeStatus::
	frontier_getstatus
	end


BattleArcade_Entrance_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	delay 30
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDidnt, MSGBOX_DEFAULT
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
	message BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGE_TYPE_INFO, FALSE
	switch VAR_RESULT
	case FRONTIER_MODE_SINGLES, BattleArcade_Entrance_EventScript_AskEnterChallenge_2
	case FRONTIER_MODE_DOUBLES, BattleArcade_Entrance_EventScript_AskEnterChallenge_2
	case 2, BattleArcade_Entrance_EventScript_AskEnterChallenge_3
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_AskEnterChallenge_4
	case 3, BattleArcade_Entrance_EventScript_AskEnterChallenge_4
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
	setvar VAR_ARCADE_TYPE, VAR_RESULT
	message BattleArcade_Entrance_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleArcade_Entrance_EventScript_TryEnterChallenge_3
	case MULTI_B_PRESSED, BattleArcade_Entrance_EventScript_TryEnterChallenge_3
BattleArcade_Entrance_EventScript_TryEnterChallenge_1:
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleArcade_Entrance_EventScript_NotEnoughValidMons
	fadescreen FADE_TO_BLACK
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleArcade_Entrance_EventScript_LoadPartyCancelChallenge
	goto BattleArcade_Entrance_EventScript_SaveBeforeChallenge
	return

BattleArcade_Entrance_EventScript_TryEnterChallenge_3:
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	goto BattleArcade_Entrance_EventScript_TryEnterChallenge_1


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
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade
	goto BattleArcade_Entrance_EventScript_TryEnterChallenge
	return


BattleArcade_Entrance_EventScript_NotEnoughValidMons::
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleArcade_Entrance_EventScript_NotEnoughValidMons_2
BattleArcade_Entrance_EventScript_NotEnoughValidMons_1:
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
	release
	end

BattleArcade_Entrance_EventScript_NotEnoughValidMons_2:
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_NotEnoughValidMons_1


BattleArcade_Entrance_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	return


BattleArcade_Entrance_EventScript_CancelChallenge::
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
	release
	end


BattleArcade_Entrance_EventScript_DenyChallenge::
	msgbox BattleArcade_Entrance_Text_PleaseComeSeeMeWhen, MSGBOX_DEFAULT
	release
	end


BattleArcade_Entrance_EventScript_WarpToBattleRoom::
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special CallFrontierUtilFunc
	frontier_saveparty
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_ARCADE_BATTLE_ROOM, 0, 6
	arcade_save CHALLENGE_STATUS_SAVING
	return


BattleArcade_Entrance_EventScript_JudgeChallenge::
	lock
	call BattleArcade_Entrance_EventScript_SetChallengeStatusEnd
	call BattleArcade_Entrance_EventScript_CheckSymbol
	goto BattleArcade_Entrance_EventScript_CancelChallenge
	return


BattleArcade_Entrance_EventScript_SaveResult::
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
	msgbox BattleArcade_RouletteRoom_Text_ReceivedBp
	return


BattleArcade_Entrance_EventScript_CheckSymbol::
	frontier_isbrain
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Entrance_EventScript_CheckSymbol_2
	frontier_getsymbols
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_lt BattleArcade_Entrance_EventScript_CheckSymbol_5
	call BattleArcade_Entrance_EventScript_GiveSymbolSpeech
	return

BattleArcade_Entrance_EventScript_CheckSymbol_2:
	return

BattleArcade_Entrance_EventScript_CheckSymbol_5:
	return


BattleArcade_Entrance_EventScript_GiveSymbolSpeech::
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
	waitmessage
	frontier_givesymbol
	playfanfare MUS_OBTAIN_SYMBOL
	compare VAR_RESULT, ARCADE_SYMBOL_GOLD
	goto_if_eq BattleArcade_Entrance_EventScript_GiveSymbolSpeech_2
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Entrance_EventScript_GiveSymbolSpeech_3
BattleArcade_Entrance_EventScript_GiveSymbolSpeech_1:
	waitmessage
	waitfanfare
	closemessage
	return

BattleArcade_Entrance_EventScript_GiveSymbolSpeech_2:
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	goto BattleArcade_Entrance_EventScript_GiveSymbolSpeech_1

BattleArcade_Entrance_EventScript_GiveSymbolSpeech_3:
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	goto BattleArcade_Entrance_EventScript_GiveSymbolSpeech_1


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
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleArcade_Entrance_EventScript_SaveBattle_1:
	return

BattleArcade_Entrance_EventScript_SaveBattle_2:
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleArcade_Entrance_EventScript_SaveBattle_1


BattleArcade_Entrance_EventScript_SetChallengeStatusEnd::
	setvar VAR_TEMP_0, 255
	closemessage
	return


BattleArcade_Entrance_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleArcade_Entrance_Text_WeveMissedYou
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

BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\n"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
	.string "At the Battle Arcade, you may take a\n"
	.string "Single or Double Battle challenge. Here,\n"
	.string "a game board is activated before every\l"
	.string "match. Depending on what comes up on\l"
	.string "the game board, an event takes place.\l"
	.string "Some events will be good for the\l"
	.string "challenger, while others won't be. The\l"
	.string "objective is to keep a winning streak\l"
	.string "alive as long as possible. During your\l"
	.string "challenge, any items held by your\l"
	.string "Pokémon will be kept in storage. If you\l"
	.string "manage to win seven matches in a row,\l"
	.string "you will earn Battle Points (BP). If you\l"
	.string "want to interrupt your challenge,\l"
	.string "please save the game. If you don't\l"
	.string "save, you will be disqualified from your\l"
	.string "challenge. Please be aware of that!$"

BattleArcade_Entrance_Text_WhichLevelMode::
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\n"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\n"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_YouMayTeamUpWith::
	.string "You may team up with a friend for a\n"
	.string "Multi Battle challenge. Here, a game\n"
	.string "board is activated before every match.\l"
	.string "Depending on what comes up on the game\l"
	.string "board, an event takes place. The\l"
	.string "events may have great impact on the\l"
	.string "match's outcome, good or bad. The\l"
	.string "objective is to keep a winning streak\l"
	.string "alive as long as possible. During your\l"
	.string "challenge, any items held by your\l"
	.string "Pokémon will be kept in storage. If you\l"
	.string "manage to win seven matches in a row,\l"
	.string "you will earn Battle Points (BP). Please\l"
	.string "note: a Battle Arcade Multi Battle\l"
	.string "challenge can't be interrupted.$"

BattleArcade_Entrance_Text_WeHopeToSeeYou::
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\n"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_AlsoEggsAreIneligible::
	.string "Also, Eggs are ineligible to enter.$"

BattleArcade_Entrance_Text_EggsAndAre::
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_WeveMissedYou::
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\n"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\n"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_ThereWasAn::
	.string "There was an error, and we couldn't\n"
	.string "save!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\n"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_SingleBattle::
	.string "SINGLE BATTLE$"

BattleArcade_Entrance_Text_DoubleBattle::
	.string "DOUBLE BATTLE$"

BattleArcade_Entrance_Text_TakeChallenge::
	.string "TAKE CHALLENGE$"

BattleArcade_Entrance_Text_Info::
	.string "INFO$"

BattleArcade_Entrance_Text_Cancel::
	.string "CANCEL$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\n"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"

BattleArcade_Entrance_Text_ThoseWhoRuleTheGame::
	.string "Those who rule the game board reign at\n"
	.string "the Battle Arcade! It sounds sort of\n"
	.string "profound, but it's actually no-kidding\l"
	.string "obvious!$"

BattleArcade_Entrance_Text_ItAllComesDownTo::
	.string "It all comes down to luck here… My cute\n"
	.string "Pokémon… They were helplessly frozen.$"

BattleArcade_Entrance_Text_TheresNothingYouCan::
	.string "There's nothing you can do about luck.\n"
	.string "It's just there or not.$"

BattleArcade_Entrance_Text_DontBeAwestruckWatching::
	.string "Don't be awestruck watching the motion\n"
	.string "of the game board. If you don't stop it\n"
	.string "in 30 seconds, it will stop by itself.$"

BattleArcade_Entrance_Text_TheBrainHasAPeculiar::
	.string "The Brain has a peculiar fashion sense.\n"
	.string "She flits around oddly, too. Kind of\n"
	.string "like this. A little bump, a wiggle…\l"
	.string "…Please don't look at me that way. It's\l"
	.string "not nice.$"

BattleArcade_Entrance_Text_YikesTheyCanEven::
	.string "Yikes, they can even start battles with\n"
	.string "the move Trick Room in effect? A\n"
	.string "strategy built around Speed could\l"
	.string "backfire right in your face!$"

BattleArcade_Entrance_Text_BeThrilledByTheUnknown::
	.string "Be thrilled by the unknown hand of luck!\n"
	.string "Leap into battles ruled by fickle fate!\n"
	.string "That's how you enjoy the Battle\l"
	.string "Arcade!$"

BattleArcade_Entrance_Text_BlamingTheGameBoardFor::
	.string "Blaming the game board for losing is\n"
	.string "pitiful. It's poor form. The game board\n"
	.string "will show better choices the greater\l"
	.string "the wins you achieve.$"

BattleArcade_Entrance_Text_DidYouFigureThisOne::
	.string "Did you figure this one out? Poisoning\n"
	.string "or freezing events can be made\n"
	.string "ineffective. …If the Pokémon's type or\l"
	.string "ability protects it from such status\l"
	.string "problems.$"

BattleArcade_Entrance_Text_IfTheGameBoardTriggers::
	.string "If the game board triggers a paralyzing\n"
	.string "event here, Ground types aren't\n"
	.string "affected.$"

BattleArcade_Entrance_Text_RecordLastMatch::
	.string "Want me to record your last BATTLE\n"
	.string "ARCADE match on your FRONTIER PASS?$"
