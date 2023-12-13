BattleFrontier_RouletteRoom_EventScript_BeginChallenge::
# 5 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 6 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 8 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 9 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber::
# 14 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 15 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 16 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_GameNoComeOn, MSGBOX_DEFAULT
# 17 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_RouletteRoom_EventScript_PlayGameBoard::
# 22 "data/scripts/battle_arcade_battle.pory"
	additem ITEM_COIN_CASE, 1
# 23 "data/scripts/battle_arcade_battle.pory"
	addcoins 50
# 24 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 25 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 26 "data/scripts/battle_arcade_battle.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 27 "data/scripts/battle_arcade_battle.pory"
	playslotmachine VAR_RESULT
	return


BattleArcade_RouletteRoom_EventScript_HandleGameResults::
# 33 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent, MSGBOX_DEFAULT
# 34 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 37 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceResults
# 38 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
	return


BattleArcade_RouletteRoom_BufferImpactedName::
# 43 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, ARCADE_IMPACT_OPPONENT
	goto_if_eq BattleArcade_RouletteRoom_BufferImpactedName_1
# 50 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_1, gText_Player
	return

BattleArcade_RouletteRoom_BufferImpactedName_1:
# 46 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, 1
	return


BattleArcade_RouletteRoom_AnnounceImpactString::
# 57 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 59 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_LOWER_HP, BattleArcade_RouletteRoom_AnnounceImpactString_2
# 61 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_POISON, BattleArcade_RouletteRoom_AnnounceImpactString_3
# 63 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_PARALYZE, BattleArcade_RouletteRoom_AnnounceImpactString_4
# 65 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_BURN, BattleArcade_RouletteRoom_AnnounceImpactString_5
# 67 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SLEEP, BattleArcade_RouletteRoom_AnnounceImpactString_6
# 69 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_FREEZE, BattleArcade_RouletteRoom_AnnounceImpactString_7
# 71 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BERRY, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 72 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_ITEM, BattleArcade_RouletteRoom_AnnounceImpactString_8
# 74 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_LEVEL_UP, BattleArcade_RouletteRoom_AnnounceImpactString_9
# 76 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SUN, BattleArcade_RouletteRoom_AnnounceImpactString_10
# 78 "data/scripts/battle_arcade_battle.pory"
	case ARACDE_RAIN, BattleArcade_RouletteRoom_AnnounceImpactString_11
# 80 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SAND, BattleArcade_RouletteRoom_AnnounceImpactString_12
# 82 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_HAIL, BattleArcade_RouletteRoom_AnnounceImpactString_13
# 84 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_FOG, BattleArcade_RouletteRoom_AnnounceImpactString_14
# 86 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_TRICK_ROOM, BattleArcade_RouletteRoom_AnnounceImpactString_15
# 88 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SWAP, BattleArcade_RouletteRoom_AnnounceImpactString_16
# 90 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SPEED_UP, BattleArcade_RouletteRoom_AnnounceImpactString_17
# 92 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_SPEED_DOWN, BattleArcade_RouletteRoom_AnnounceImpactString_18
# 94 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_RANDOM, BattleArcade_RouletteRoom_AnnounceImpactString_19
# 96 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BP_SMALL, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 97 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_GIVE_BP_BIG, BattleArcade_RouletteRoom_AnnounceImpactString_20
# 99 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_NO_BATTLE, BattleArcade_RouletteRoom_AnnounceImpactString_21
# 101 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_NO_EVENT, BattleArcade_RouletteRoom_AnnounceImpactString_22
	return

BattleArcade_RouletteRoom_AnnounceImpactString_2:
# 60 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_3:
# 62 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_4:
# 64 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_5:
# 66 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_6:
# 68 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_7:
# 70 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_8:
# 73 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_9:
# 75 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_10:
# 77 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_11:
# 79 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_12:
# 81 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_13:
# 83 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_14:
# 85 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_15:
# 87 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_16:
# 89 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_17:
# 91 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_18:
# 93 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_19:
# 95 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_20:
# 98 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_ReceivedBp, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_21:
# 100 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return

BattleArcade_RouletteRoom_AnnounceImpactString_22:
# 102 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RouletteRoom_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return


BattleArcade_RouletteRoom_AnnounceResults::
# 108 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_BufferImpactedName
# 109 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_AnnounceImpactString
	return


BattleArcade_RouletteRoom_EventScript_SpawnOpponentStartGameBoard::
# 114 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_AnnounceGameNumber
# 115 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 116 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 117 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 118 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_PlayGameBoard
# 119 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_RouletteRoom_EventScript_HandleGameResults
# 120 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RouletteRoom_EventScript_StartBattle
	return


BattleArcade_RouletteRoom_EventScript_StartBattle::
# 125 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 126 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 127 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 128 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 129 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 130 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 131 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	return


BattleArcade_RouletteRoom_Text_WellDone::
# 134 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_RouletteRoom_Text_LetTheBattle::
# 139 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Next::
# 144 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_RouletteRoom_Text_Go::
# 149 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_RouletteRoom_Text_DoYouWantToContinue::
# 154 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_RouletteRoom_Text_DoYouWantToRestore::
# 159 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 164 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_RouletteRoom_Text_FirstIllNeedToHoldOn::
# 169 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_RouletteRoom_Text_PleaseWaitAMoment::
# 173 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_RouletteRoom_Text_GoodGoingWellHeal::
# 177 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_RouletteRoom_Text_NextUpGameNoAreYouReady::
# 181 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveTheLastBattle::
# 185 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_RouletteRoom_Text_BattleHasBeenSaved::
# 189 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_RouletteRoom_Text_ThereWasAnError::
# 193 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_RouletteRoom_Text_DeleteYourExistingBattleVideo::
# 197 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_RouletteRoom_Text_SavingDontTurnOffThePower::
# 201 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToSaveAndTakeABreak::
# 205 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_RouletteRoom_Text_WouldYouLikeToRetire::
# 209 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_RouletteRoom_Text_IsChoosingPleaseWait::
# 213 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_RouletteRoom_Text_ChoseToRetire::
# 217 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_RouletteRoom_Text_WelcomeToTheBattleArcade::
# 221 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_RouletteRoom_Text_GameNoComeOn::
# 225 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_RouletteRoom_Text_WithoutFurtherAdo::
# 229 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_RouletteRoom_Text_ThisIsOurCurrentEvent::
# 233 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_RouletteRoom_Text_MatchCommenceWithoutFullHp::
# 237 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothWithoutFullHp::
# 241 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_RouletteRoom_Text_MatchCommenceLeveledUp::
# 245 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothLeveledUp::
# 249 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_RouletteRoom_Text_MatchCommencePoisoned::
# 253 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothPoisoned::
# 257 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceParalyzed::
# 261 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothParalyzed::
# 265 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBurned::
# 269 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothBurned::
# 273 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_RouletteRoom_Text_MatchCommenceAsleep::
# 277 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothAsleep::
# 281 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_RouletteRoom_Text_MatchCommenceFrozen::
# 285 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_MatchCommenceBothFrozen::
# 289 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_RouletteRoom_Text_PokemonWillBeLoanedThe::
# 293 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_BothPokemonWillBeLoanedThe::
# 297 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_RouletteRoom_Text_HereYouGo::
# 301 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_RouletteRoom_Text_MatchConductedHarshSunlight::
# 305 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_RouletteRoom_Text_MatchConductedSteadyRainfall::
# 309 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_RouletteRoom_Text_MatchConductedRagingSandstorm::
# 313 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_RouletteRoom_Text_MatchConductedPeltingHail::
# 317 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_RouletteRoom_Text_MatchConductedDenseFog::
# 321 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_RouletteRoom_Text_MatchConductedTimeAndSpaceAreDistorted::
# 325 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_RouletteRoom_Text_YourPokemonWillBeSwitched::
# 329 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_RouletteRoom_Text_BoardspeedIncreased::
# 333 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_RouletteRoom_Text_BoardspeedDecreased::
# 337 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_RouletteRoom_Text_BoardmotionRandom::
# 341 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_RouletteRoom_Text_ReceivedBp::
# 345 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AndReceivedBp::
# 349 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_RouletteRoom_Text_AreYouReady::
# 353 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_RouletteRoom_Text_OhLuckyYouCanSkip::
# 357 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_RouletteRoom_Text_TooBadThereIsNo::
# 361 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_RouletteRoom_Text_OkLetTheBattleCommence::
# 365 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_RouletteRoom_Text_MatchPoisonedLuckyBreak::
# 369 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchBothPoisonedLuckyBreak::
# 373 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_RouletteRoom_Text_MatchParalyzedLuckyBreak::
# 377 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBothParalyzedLuckyBreak::
# 381 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_RouletteRoom_Text_MatchBurnedLuckyBreak::
# 385 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_RouletteRoom_Text_MatchBothBurnedLuckyBreak::
# 389 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_RouletteRoom_Text_MatchAsleepLuckyBreak::
# 393 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchBothAsleepLuckyBreak::
# 397 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_RouletteRoom_Text_MatchFrozenLuckyBreak::
# 401 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_RouletteRoom_Text_MatchBothFrozenLuckyBreak::
# 405 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_RouletteRoom_Text_YouHaveClearedYourSeventh::
# 409 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_RouletteRoom_Text_WeWillReturnAnyItems::
# 413 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_RouletteRoom_Text_Continue::
# 417 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_RouletteRoom_Text_Record::
# 421 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_RouletteRoom_Text_Rest::
# 425 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_RouletteRoom_Text_Retire::
# 429 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_RouletteRoom_Text_CongratulationsTrainerInRecognition::
# 433 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_RouletteRoom_Text_IKnowOneThingFor::
# 437 "data/scripts/battle_arcade_battle.pory"
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
# 441 "data/scripts/battle_arcade_battle.pory"
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
# 445 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_RouletteRoom_Text_TrulyItWasSoVery::
# 449 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
