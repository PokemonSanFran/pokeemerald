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

BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn::
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_RouletteRoom_Text_PleaseWaitAMoment::
	.string "Please wait a moment.$"

BattleArcade_RouletteRoom_Text_GoodGoingWellHeal::
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady::
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveTheLastBattle::
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_RouletteRoom_Text_BattleHasBeenSaved::
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_RouletteRoom_Text_ThereWasAnError::
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_RouletteRoom_Text_DeleteYourExistingBattleVideo::
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower::
	.string "Saving... Don’t turn off the power.$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak::
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire::
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_RouletteRoom_Text_IsChoosingPleaseWait::
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_RouletteRoom_Text_ChoseToRetire::
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade::
	.string "Welcome to the Battle Arcade!$"

BattleArcade_RouletteRoom_Text_GameNoComeOn::
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_RouletteRoom_Text_WithoutFurtherAdo::
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent::
	.string "This is our current event!$"

BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\n"
	.string "HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothWithoutFullHp::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon without full HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothLeveledUp::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommencePoisoned::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothPoisoned::
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothParalyzed::
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBurned::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothBurned::
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceAsleep::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothAsleep::
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceFrozen::
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothFrozen::
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe::
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_BothPokemonWillBeLoanedThe::
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\n"
	.string "{STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_HereYouGo::
	.string "Here you go!$"

BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight::
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall::
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm::
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail::
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_RouletteRoom_Text_MatchConductedDenseFog::
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted::
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched::
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_RouletteRoom_Text_BoardspeedIncreased::
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_RouletteRoom_Text_BoardspeedDecreased::
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_RouletteRoom_Text_BoardmotionRandom::
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_RouletteRoom_Text_ReceivedBp::
	.string "{STR_VAR_1} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AndReceivedBp::
	.string "{STR_VAR_1} and {STR_VAR_2}\n"
	.string "received {STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AreYouReady::
	.string "Are you ready?$"

BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip::
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_RouletteRoom_Text_TooBadThereIsNo::
	.string "Too bad! There is no event this time!$"

BattleArcade_RouletteRoom_Text_OkLetTheBattleCommence::
	.string "OK! Let the battle commence!$"

BattleArcade_RouletteRoom_Text_MatchPoisonedLuckyBreak::
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\n"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchBothPoisonedLuckyBreak::
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\n"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak::
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\n"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBothParalyzedLuckyBreak::
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\n"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak::
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\n"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_RouletteRoom_Text_MatchBothBurnedLuckyBreak::
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\n"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak::
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\n"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchBothAsleepLuckyBreak::
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\n"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak::
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\n"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_RouletteRoom_Text_MatchBothFrozenLuckyBreak::
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\n"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh::
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\n"
	.string "your prize!$"

BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems::
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_RouletteRoom_Text_Continue::
	.string "CONTINUE$"

BattleArcade_RouletteRoom_Text_Record::
	.string "RECORD$"

BattleArcade_RouletteRoom_Text_Rest::
	.string "REST$"

BattleArcade_RouletteRoom_Text_Retire::
	.string "RETIRE$"

BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition::
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\n"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is\l"
	.string "against the Arcade Star; no ifs or\l"
	.string "buts! Are you ready?$"

BattleArcade_RouletteRoom_Text_IKnowOneThingFor::
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\n"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that. I\l"
	.string "know one thing for certain. You have\l"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_RouletteRoom_Text_YouAreProvingYourselfIncredible::
	.string "Dahlia: No need to worry. {EMOJI_NOTE} Let chance do\n"
	.string "what it does. Like surprises from the\n"
	.string "game board, life goes through twists\l"
	.string "and turns. No need to worry. {EMOJI_NOTE} Things will\l"
	.string "go as they will. But, enough of that.\l"
	.string "You are proving yourself incredible.\l"
	.string "Are you incredible because you are so\l"
	.string "lucky you shrug off bad luck entirely?\l"
	.string "Or, are you so incredibly talented to\l"
	.string "not be swayed by luck, good or bad? I\l"
	.string "wish to see for myself what brought\l"
	.string "you to me today!$"

BattleArcade_RouletteRoom_Text_HowFabulousOfYouYour::
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\n"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown\l"
	.string "your way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_RouletteRoom_Text_TrulyItWasSoVery::
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\n"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
