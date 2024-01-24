BattleArcade_Challenge_EventScript_BeginChallenge::
# 8 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 9 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 10 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 11 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 12 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BattleOpponent::
# 17 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 18 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard::
# 23 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AnnounceGameNumber
# 24 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 25 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainIntro
# 26 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartGameBoard
# 27 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 28 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_LoadOpponentText
# 29 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartBattle
# 30 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HandleBattleResult
	return


BattleArcade_Challenge_EventScript_AnnounceGameNumber::
# 35 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 36 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_GameNoComeOn, MSGBOX_DEFAULT
# 37 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_EventScript_BufferNextBattleNumber::
# 42 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 43 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 44 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_Challenge_EventScript_StartGameBoard::
# 49 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 50 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_PlayGameBoard
# 51 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_HandleGameResults
	return


BattleArcade_Challenge_EventScript_PlayGameBoard::
# 57 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 58 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 59 "data/scripts/battle_arcade_battle.pory"
	arcade_generateopponentparty
# 60 "data/scripts/battle_arcade_battle.pory"
	arcade_takeenemyhelditems
# 61 "data/scripts/battle_arcade_battle.pory"
	arcade_playgameboard
	return


BattleArcade_Challenge_EventScript_HandleGameResults::
# 66 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_ThisIsOurCurrentEvent, MSGBOX_DEFAULT
# 67 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 68 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem
# 69 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
# 70 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_SkipBattle_Script
# 71 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_OkLetTheBattleCommence, MSGBOX_DEFAULT
# 72 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_AnnounceImpactGiveItem::
# 77 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8009, 0
	goto_if_ne BattleArcade_Challenge_AnnounceImpactGiveItem_2
# 83 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Failure
BattleArcade_Challenge_AnnounceImpactGiveItem_1:
# 85 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 86 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_GiveItem_Script
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_2:
# 79 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Success
	goto BattleArcade_Challenge_AnnounceImpactGiveItem_1


BattleArcade_Challenge_AnnounceImpactGiveItem_Success::
# 91 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 93 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LOWER_HP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2
# 95 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3
# 97 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4
# 99 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5
# 101 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6
# 103 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7
# 105 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BERRY, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 106 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_ITEM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 108 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LEVEL_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9
# 110 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SUN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10
# 112 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RAIN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11
# 114 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SAND, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12
# 116 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_HAIL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13
# 118 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FOG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14
# 120 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_TRICK_ROOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15
# 122 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SWAP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16
# 124 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17
# 126 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_DOWN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18
# 128 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RANDOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19
# 130 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_SMALL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 131 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_BIG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 133 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_BATTLE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21
# 136 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_EVENT, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22
BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22:
# 137 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2:
# 94 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3:
# 96 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4:
# 98 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5:
# 100 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6:
# 102 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7:
# 104 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8:
# 107 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9:
# 109 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10:
# 111 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11:
# 113 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12:
# 115 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13:
# 117 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14:
# 119 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15:
# 121 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16:
# 123 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17:
# 125 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18:
# 127 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19:
# 129 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20:
# 132 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_ReceivedBp, MSGBOX_GETPOINTS
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21:
# 134 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_AnnounceImpactGiveItem_Failure::
# 143 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 145 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2
# 147 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3
# 149 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4
# 151 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5
# 154 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6
BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6:
# 155 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchFrozenLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2:
# 146 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchPoisonedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3:
# 148 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchParalyzedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4:
# 150 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchBurnedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5:
# 152 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchAsleepLuckyBreak, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_GiveItem_Script::
# 160 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_3
BattleArcade_Challenge_GiveItem_Script_1:
# 164 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCToTrainer
# 165 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_HereYouGo
# 166 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 167 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer
	return

BattleArcade_Challenge_GiveItem_Script_2:
	return

BattleArcade_Challenge_GiveItem_Script_3:
# 160 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_2
	goto BattleArcade_Challenge_GiveItem_Script_1


BattleArcade_Challenge_SkipBattle_Script::
# 172 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_NO_BATTLE
	goto_if_ne BattleArcade_Challenge_SkipBattle_Script_2
# 177 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 178 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	return

BattleArcade_Challenge_SkipBattle_Script_2:
	return


BattleArcade_Challenge_EventScript_BattleBrain::
# 183 "data/scripts/battle_arcade_battle.pory"
	arcade_setbrainobj
# 184 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_LoadOpponentText::
# 190 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 191 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_LoadOpponentText_2
# 198 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 199 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_LoadOpponentText_1:
# 201 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 202 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_LoadOpponentText_2:
# 193 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferBrainPreBattleText
# 194 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar3, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_LoadOpponentText_1


BattleArcade_Challenge_EventScript_StartBattle::
# 207 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 208 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_DoArcadeBattle
	return


BattleArcade_Challenge_EventScript_DoArcadeBattle::
# 213 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 215 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, FALSE
# 216 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 217 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_0x8005, 0
# 219 "data/scripts/battle_arcade_battle.pory"
	special DoArcadeTrainerBattle
# 220 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 221 "data/scripts/battle_arcade_battle.pory"
	arcade_eventcleanup
# 223 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 224 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return


BattleArcade_Challenge_EventScript_HandleBattleResult::
# 229 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_Challenge_EventScript_HandleBattleResult_2
BattleArcade_Challenge_EventScript_HandleBattleResult_1:
# 233 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyLost
	return

BattleArcade_Challenge_EventScript_HandleBattleResult_2:
# 231 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	goto BattleArcade_Challenge_EventScript_HandleBattleResult_1


BattleArcade_Challenge_EventScript_WarpToLobbyLost::
# 238 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveLost
# 239 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobby
	return


BattleArcade_Challenge_EventScript_SaveLost::
# 244 "data/scripts/battle_arcade_battle.pory"
	special LoadPlayerParty
# 245 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_LOST
# 246 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_Save
	return


BattleArcade_Challenge_EventScript_Save::
# 251 "data/scripts/battle_arcade_battle.pory"
	message gText_SavingDontTurnOff2
# 252 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 253 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 254 "data/scripts/battle_arcade_battle.pory"
	waitse
	return


BattleArcade_Challenge_EventScript_WarpToLobby::
# 259 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 260 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_Challenge_EventScript_WarpToLobby_2
# 266 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 5, 6
BattleArcade_Challenge_EventScript_WarpToLobby_1:
# 268 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_Challenge_EventScript_WarpToLobby_2:
# 262 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 6, 6
	goto BattleArcade_Challenge_EventScript_WarpToLobby_1


BattleArcade_Challenge_EventScript_DefeatedOpponent::
# 274 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 275 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Challenge_EventScript_DefeatedOpponent_2
BattleArcade_Challenge_EventScript_DefeatedOpponent_1:
# 280 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 282 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 283 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_eq BattleArcade_Challenge_EventScript_DefeatedOpponent_5
BattleArcade_Challenge_EventScript_DefeatedOpponent_4:
# 288 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 289 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HealPlayer
	return

BattleArcade_Challenge_EventScript_DefeatedOpponent_2:
# 277 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainCongratsText
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_1

BattleArcade_Challenge_EventScript_DefeatedOpponent_5:
# 286 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_4


BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge::
# 295 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 296 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1:
# 300 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_GiveBP
# 301 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WeWillReturnAnyItems
# 302 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveWon
# 303 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyWon
	return

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2:
# 298 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1


BattleArcade_Challenge_EventScript_GiveBP::
# 308 "data/scripts/battle_arcade_battle.pory"
	arcade_givepoints
# 309 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YouHaveClearedYourSeventh
# 310 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	return


BattleArcade_Challenge_EventScript_SaveWon::
# 315 "data/scripts/battle_arcade_battle.pory"
	special LoadPlayerParty
# 316 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_WON
# 317 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_Save
	return


BattleArcade_Challenge_EventScript_WarpToLobbyWon::
# 322 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveWon
# 323 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobby
	return


BattleArcade_Challenge_EventScript_HealPlayer::
# 329 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_GoodGoingWellHeal
# 330 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 331 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 332 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 333 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 334 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 335 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskReadyForOpponent::
# 340 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainstatus
# 341 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_Challenge_EventScript_AskReadyForOpponent_2
BattleArcade_Challenge_EventScript_AskReadyForOpponent_1:
# 346 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 347 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_ReadyForOpponent
# 348 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 349 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForOpponent_5
BattleArcade_Challenge_EventScript_AskReadyForOpponent_4:
# 353 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenu
	return

BattleArcade_Challenge_EventScript_AskReadyForOpponent_2:
# 343 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainUpNext
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_1

BattleArcade_Challenge_EventScript_AskReadyForOpponent_5:
# 351 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenuNoRecord
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_4


BattleArcade_Challenge_EventScript_ReadyForOpponent::
# 359 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 360 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_NextUpGameNoAreYouReady
# 361 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_Challenge_EventScript_ReadyMenu::
# 366 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 367 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 369 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenu_2
# 370 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenu_3
# 371 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenu_4
# 372 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_ReadyMenu_5
# 373 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenu_6
	return

BattleArcade_Challenge_EventScript_ReadyMenu_2:
# 369 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_3:
# 370 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_ReadyMenu_4:
# 371 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_5:
# 372 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_6:
# 373 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_ReadyMenuNoRecord::
# 379 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 380 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 381 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2
# 382 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3
# 383 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4
# 384 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2:
# 381 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3:
# 382 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4:
# 383 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5:
# 384 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle::
# 390 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
# 391 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattle::
# 396 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 397 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 398 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 399 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRecordBattle_1
	return

BattleArcade_Challenge_EventScript_AskRecordBattle_1:
# 401 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	return


BattleArcade_Challenge_EventScript_AskPauseChallenge::
# 407 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WouldYouLikeToSaveAndTakeABreak, MSGBOX_YESNO
# 408 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_Challenge_EventScript_AskPauseChallenge_2
BattleArcade_Challenge_EventScript_AskPauseChallenge_1:
# 412 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskPauseChallenge_2:
# 410 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_PauseChallenge
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge_1


BattleArcade_Challenge_EventScript_PauseChallenge::
# 417 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_SavingDontTurnOffThePower
# 418 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 420 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_PAUSED
# 421 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 422 "data/scripts/battle_arcade_battle.pory"
	waitse
# 424 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 425 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_Challenge_EventScript_AskRetireChallenge::
# 431 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_WouldYouLikeToRetire
# 432 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 433 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 434 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRetireChallenge_2
BattleArcade_Challenge_EventScript_AskRetireChallenge_1:
# 438 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskRetireChallenge_2:
# 436 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_RetireChallenge
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge_1


BattleArcade_Challenge_EventScript_RetireChallenge::
# 443 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyLost
	return


BattleArcade_Challenge_EventScript_ContinueChallenge::
# 448 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 449 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BrainUpNext::
# 454 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainUpNext_2
BattleArcade_Challenge_EventScript_BrainUpNext_1:
# 459 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_CongratulationsTrainerInRecognition, MSGBOX_DEFAULT
# 460 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, TRUE
# 462 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return

BattleArcade_Challenge_EventScript_BrainUpNext_2:
# 456 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	goto BattleArcade_Challenge_EventScript_BrainUpNext_1


BattleArcade_Challenge_EventScript_AskReadyForBrain::
# 467 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 468 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForBrain_1
# 474 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord
	return

BattleArcade_Challenge_EventScript_AskReadyForBrain_1:
# 470 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenu
	return


BattleArcade_Challenge_EventScript_BrainReadyMenu::
# 480 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 481 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 483 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenu_2
# 484 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenu_3
# 485 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenu_4
# 486 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_BrainReadyMenu_5
# 487 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenu_6
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_2:
# 483 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_3:
# 484 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_4:
# 485 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_5:
# 486 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_6:
# 487 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord::
# 493 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 494 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 496 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2
# 497 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3
# 498 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4
# 499 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2:
# 496 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3:
# 497 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4:
# 498 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5:
# 499 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainIntro::
# 505 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 506 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_2
# 511 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_NoNeedToWorry, MSGBOX_DEFAULT
# 512 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 513 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_4
# 519 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YouAreProving, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_EventScript_BrainIntro_2:
	return

BattleArcade_Challenge_EventScript_BrainIntro_4:
# 515 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_IKnowOneThing, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_EventScript_BufferBrainPreBattleText::
# 525 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 526 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1
# 532 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_Text_WheneverIBattle
	return

BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1:
# 528 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_Text_AlwaysBeSmiling
	return


BattleArcade_Challenge_EventScript_BrainCongratsText::
# 538 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 539 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainCongratsText_2
# 545 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_TrulyItWasSoVery, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_BrainCongratsText_1:
# 547 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_BrainCongratsText_2:
# 541 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_HowFabulousOfYouYour, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_BrainCongratsText_1


BattleArcade_Challenge_Text_WellDone::
# 550 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_Challenge_Text_LetTheBattle::
# 555 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_Challenge_Text_Next::
# 560 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_Challenge_Text_Go::
# 565 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_Challenge_Text_DoYouWantToContinue::
# 570 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_Challenge_Text_DoYouWantToRestore::
# 575 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 580 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_Challenge_Text_FirstIllNeedToHoldOn::
# 585 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_Challenge_Text_PleaseWaitAMoment::
# 589 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_Challenge_Text_GoodGoingWellHeal::
# 593 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_Challenge_Text_NextUpGameNoAreYouReady::
# 597 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_Challenge_Text_WouldYouLikeToSaveTheLastBattle::
# 601 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_Challenge_Text_BattleHasBeenSaved::
# 605 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_Challenge_Text_ThereWasAnError::
# 609 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_Challenge_Text_DeleteYourExistingBattleVideo::
# 613 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_Challenge_Text_SavingDontTurnOffThePower::
# 617 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_Challenge_Text_WouldYouLikeToSaveAndTakeABreak::
# 621 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_Challenge_Text_WouldYouLikeToRetire::
# 625 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_Challenge_Text_IsChoosingPleaseWait::
# 629 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_Challenge_Text_ChoseToRetire::
# 633 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_Challenge_Text_WelcomeToTheBattleArcade::
# 637 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_Challenge_Text_GameNoComeOn::
# 641 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_Challenge_Text_WithoutFurtherAdo::
# 645 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_Challenge_Text_ThisIsOurCurrentEvent::
# 649 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_Challenge_Text_MatchCommenceWithoutFullHp::
# 653 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_Challenge_Text_MatchCommenceBothWithoutFullHp::
# 657 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_Challenge_Text_MatchCommenceLeveledUp::
# 661 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_Challenge_Text_MatchCommenceBothLeveledUp::
# 665 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_Challenge_Text_MatchCommencePoisoned::
# 669 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_Challenge_Text_MatchCommenceBothPoisoned::
# 673 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_Challenge_Text_MatchCommenceParalyzed::
# 677 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_Challenge_Text_MatchCommenceBothParalyzed::
# 681 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_Challenge_Text_MatchCommenceBurned::
# 685 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_Challenge_Text_MatchCommenceBothBurned::
# 689 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_Challenge_Text_MatchCommenceAsleep::
# 693 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_Challenge_Text_MatchCommenceBothAsleep::
# 697 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_Challenge_Text_MatchCommenceFrozen::
# 701 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_Challenge_Text_MatchCommenceBothFrozen::
# 705 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_Challenge_Text_PokemonWillBeLoanedThe::
# 709 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_Challenge_Text_BothPokemonWillBeLoanedThe::
# 713 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_Challenge_Text_HereYouGo::
# 717 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_Challenge_Text_MatchConductedHarshSunlight::
# 721 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_Challenge_Text_MatchConductedSteadyRainfall::
# 725 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_Challenge_Text_MatchConductedRagingSandstorm::
# 729 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_Challenge_Text_MatchConductedPeltingHail::
# 733 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_Challenge_Text_MatchConductedDenseFog::
# 737 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_Challenge_Text_MatchConductedTimeAndSpaceAreDistorted::
# 741 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_Challenge_Text_YourPokemonWillBeSwitched::
# 745 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_Challenge_Text_BoardspeedIncreased::
# 749 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_Challenge_Text_BoardspeedDecreased::
# 753 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_Challenge_Text_BoardmotionRandom::
# 757 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_Challenge_Text_ReceivedBp::
# 761 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_3} BP!$"

BattleArcade_Challenge_Text_AndReceivedBp::
# 765 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_Challenge_Text_AreYouReady::
# 769 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_Challenge_Text_OhLuckyYouCanSkip::
# 773 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_Challenge_Text_TooBadThereIsNo::
# 777 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_Challenge_Text_OkLetTheBattleCommence::
# 781 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_Challenge_Text_MatchPoisonedLuckyBreak::
# 785 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_Challenge_Text_MatchBothPoisonedLuckyBreak::
# 789 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_Challenge_Text_MatchParalyzedLuckyBreak::
# 793 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_Challenge_Text_MatchBothParalyzedLuckyBreak::
# 797 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_Challenge_Text_MatchBurnedLuckyBreak::
# 801 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_Challenge_Text_MatchBothBurnedLuckyBreak::
# 805 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_Challenge_Text_MatchAsleepLuckyBreak::
# 809 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_Challenge_Text_MatchBothAsleepLuckyBreak::
# 813 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_Challenge_Text_MatchFrozenLuckyBreak::
# 817 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_Challenge_Text_MatchBothFrozenLuckyBreak::
# 821 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_Challenge_Text_YouHaveClearedYourSeventh::
# 825 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_Challenge_Text_WeWillReturnAnyItems::
# 829 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_Challenge_Text_Continue::
# 833 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_Challenge_Text_Record::
# 837 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_Challenge_Text_Rest::
# 841 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_Challenge_Text_Retire::
# 845 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_Challenge_Text_CongratulationsTrainerInRecognition::
# 850 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_Challenge_Text_NoNeedToWorry::
# 855 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE}\n"
	.string "Let chance do what it does. Like\l"
	.string "surprises from the game board, life\l"
	.string "goes through twists and turns. No need\l"
	.string "to worry. {EMOJI_NOTE}\l"
	.string "Things will go as they will. But, enough\l"
	.string "of that.$"

BattleArcade_Challenge_Text_IKnowOneThing::
# 860 "data/scripts/battle_arcade_battle.pory"
	.string "I know one thing for certain. You have\n"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_Challenge_Text_YouAreProving::
# 864 "data/scripts/battle_arcade_battle.pory"
	.string "You are proving yourself incredible. Are\n"
	.string "you incredible because you are so lucky\l"
	.string "you shrug off bad luck entirely? Or, are\l"
	.string "you so incredibly talented to not be\l"
	.string "swayed by luck, good or bad? I wish to\l"
	.string "see for myself what brought you to me\l"
	.string "today!$"

BattleArcade_Challenge_Text_AlwaysBeSmiling::
# 868 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Always be smiling! Luck comes to\n"
	.string "those who are happy! That's why I\l"
	.string "always keep a big smile and believe in my\l"
	.string "Pokémon when I battle.$"

BattleArcade_Challenge_Text_WheneverIBattle::
# 872 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Whenever I battle someone\n"
	.string "tough, I smile. I cannot help it! How\l"
	.string "about you? What do you do? Do you\l"
	.string "laugh? Cry? Get angry?$"

BattleArcade_Challenge_Text_HowFabulousOfYouYour::
# 876 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_Challenge_Text_TrulyItWasSoVery::
# 880 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
