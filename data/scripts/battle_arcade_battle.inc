BattleArcade_Challenge_EventScript_BeginChallenge::
# 13 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 14 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 15 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WelcomeToTheBattleArcade, MSGBOX_DEFAULT
# 16 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_FirstIllNeedToHoldOn, MSGBOX_DEFAULT
# 17 "data/scripts/battle_arcade_battle.pory"
	arcade_takeplayerhelditems
# 18 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BattleOpponent::
# 23 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 24 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard::
# 29 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AnnounceGameNumber
# 30 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 31 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainIntro
# 32 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartGameBoard
# 33 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 34 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_LoadOpponentText
# 35 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartBattle
# 36 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HandleBattleResult
	return


BattleArcade_Challenge_EventScript_AnnounceGameNumber::
# 41 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 42 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_GameNoComeOn, MSGBOX_DEFAULT
# 43 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_EventScript_BufferNextBattleNumber::
# 48 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 49 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 50 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_Challenge_EventScript_StartGameBoard::
# 55 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 56 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_PlayGameBoard
# 57 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_HandleGameResults
	return


BattleArcade_Challenge_EventScript_PlayGameBoard::
# 63 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WithoutFurtherAdo, MSGBOX_DEFAULT
# 64 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 65 "data/scripts/battle_arcade_battle.pory"
	arcade_generateopponentparty
# 66 "data/scripts/battle_arcade_battle.pory"
	arcade_takeenemyhelditems
# 67 "data/scripts/battle_arcade_battle.pory"
	arcade_playgameboard
	return


BattleArcade_Challenge_EventScript_HandleGameResults::
# 72 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_ThisIsOurCurrentEvent, MSGBOX_DEFAULT
# 73 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 74 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem
# 75 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
# 76 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_SkipBattle_Script
# 77 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_OkLetTheBattleCommence, MSGBOX_DEFAULT
# 78 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_AnnounceImpactGiveItem::
# 83 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8009, 0
	goto_if_ne BattleArcade_Challenge_AnnounceImpactGiveItem_2
# 89 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Failure
BattleArcade_Challenge_AnnounceImpactGiveItem_1:
# 91 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 92 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_GiveItem_Script
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_2:
# 85 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Success
	goto BattleArcade_Challenge_AnnounceImpactGiveItem_1


BattleArcade_Challenge_AnnounceImpactGiveItem_Success::
# 97 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 99 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LOWER_HP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2
# 101 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3
# 103 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4
# 105 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5
# 107 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6
# 109 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7
# 111 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BERRY, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 112 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_ITEM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 114 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LEVEL_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9
# 116 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SUN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10
# 118 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RAIN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11
# 120 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SAND, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12
# 122 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_HAIL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13
# 124 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FOG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14
# 126 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_TRICK_ROOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15
# 128 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SWAP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16
# 130 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17
# 132 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_DOWN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18
# 134 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RANDOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19
# 136 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_SMALL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 137 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_BIG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 139 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_BATTLE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21
# 142 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_EVENT, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22
BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22:
# 143 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_TooBadThereIsNo, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2:
# 100 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceWithoutFullHp, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3:
# 102 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommencePoisoned, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4:
# 104 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceParalyzed, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5:
# 106 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceBurned, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6:
# 108 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceAsleep, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7:
# 110 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceFrozen, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8:
# 113 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_PokemonWillBeLoanedThe, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9:
# 115 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchCommenceLeveledUp, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10:
# 117 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedHarshSunlight, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11:
# 119 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedSteadyRainfall, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12:
# 121 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedRagingSandstorm, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13:
# 123 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedPeltingHail, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14:
# 125 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedDenseFog, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15:
# 127 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchConductedTimeAndSpaceAreDistorted, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16:
# 129 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YourPokemonWillBeSwitched, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17:
# 131 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardspeedIncreased, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18:
# 133 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardspeedDecreased, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19:
# 135 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_BoardmotionRandom, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20:
# 138 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_ReceivedBp, MSGBOX_GETPOINTS
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21:
# 140 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_OhLuckyYouCanSkip, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_AnnounceImpactGiveItem_Failure::
# 149 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 151 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2
# 153 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3
# 155 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4
# 157 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5
# 160 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6
BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6:
# 161 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchFrozenLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2:
# 152 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchPoisonedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3:
# 154 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchParalyzedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4:
# 156 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchBurnedLuckyBreak, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5:
# 158 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_MatchAsleepLuckyBreak, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_GiveItem_Script::
# 166 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_3
BattleArcade_Challenge_GiveItem_Script_1:
# 170 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCToTrainer
# 171 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_HereYouGo
# 172 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 173 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer
	return

BattleArcade_Challenge_GiveItem_Script_2:
	return

BattleArcade_Challenge_GiveItem_Script_3:
# 166 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_2
	goto BattleArcade_Challenge_GiveItem_Script_1


BattleArcade_Challenge_SkipBattle_Script::
# 178 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_NO_BATTLE
	goto_if_ne BattleArcade_Challenge_SkipBattle_Script_2
# 183 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 184 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	return

BattleArcade_Challenge_SkipBattle_Script_2:
	return


BattleArcade_Challenge_EventScript_BattleBrain::
# 189 "data/scripts/battle_arcade_battle.pory"
	arcade_setbrainobj
# 190 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_LoadOpponentText::
# 196 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 197 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_LoadOpponentText_2
# 204 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 205 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_LoadOpponentText_1:
# 207 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 208 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_LoadOpponentText_2:
# 199 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferBrainPreBattleText
# 200 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar3, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_LoadOpponentText_1


BattleArcade_Challenge_EventScript_StartBattle::
# 213 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 214 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_DoArcadeBattle
	return


BattleArcade_Challenge_EventScript_DoArcadeBattle::
# 219 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 221 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, FALSE
# 222 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 223 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_0x8005, 0
# 225 "data/scripts/battle_arcade_battle.pory"
	special DoArcadeTrainerBattle
# 226 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 227 "data/scripts/battle_arcade_battle.pory"
	arcade_eventcleanup
# 229 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 230 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return


BattleArcade_Challenge_EventScript_HandleBattleResult::
# 235 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_Challenge_EventScript_HandleBattleResult_2
BattleArcade_Challenge_EventScript_HandleBattleResult_1:
# 239 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyLost
	return

BattleArcade_Challenge_EventScript_HandleBattleResult_2:
# 237 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	goto BattleArcade_Challenge_EventScript_HandleBattleResult_1


BattleArcade_Challenge_EventScript_WarpToLobbyLost::
# 244 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveLost
# 245 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobby
	return


BattleArcade_Challenge_EventScript_SaveLost::
# 250 "data/scripts/battle_arcade_battle.pory"
	special LoadPlayerParty
# 251 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_LOST
# 252 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_Save
	return


BattleArcade_Challenge_EventScript_Save::
# 257 "data/scripts/battle_arcade_battle.pory"
	message gText_SavingDontTurnOff2
# 258 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 259 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 260 "data/scripts/battle_arcade_battle.pory"
	waitse
	return


BattleArcade_Challenge_EventScript_WarpToLobby::
# 265 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 266 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_Challenge_EventScript_WarpToLobby_2
# 272 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 5, 6
BattleArcade_Challenge_EventScript_WarpToLobby_1:
# 274 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_Challenge_EventScript_WarpToLobby_2:
# 268 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_BATTLE_ARCADE_LOBBY, 6, 6
	goto BattleArcade_Challenge_EventScript_WarpToLobby_1


BattleArcade_Challenge_EventScript_DefeatedOpponent::
# 280 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 281 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Challenge_EventScript_DefeatedOpponent_2
BattleArcade_Challenge_EventScript_DefeatedOpponent_1:
# 286 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 288 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 289 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_eq BattleArcade_Challenge_EventScript_DefeatedOpponent_5
BattleArcade_Challenge_EventScript_DefeatedOpponent_4:
# 294 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 295 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HealPlayer
	return

BattleArcade_Challenge_EventScript_DefeatedOpponent_2:
# 283 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainCongratsText
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_1

BattleArcade_Challenge_EventScript_DefeatedOpponent_5:
# 292 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_4


BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge::
# 301 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 302 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1:
# 306 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_GiveBP
# 307 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WeWillReturnAnyItems
# 308 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveWon
# 309 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyWon
	return

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2:
# 304 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1


BattleArcade_Challenge_EventScript_GiveBP::
# 314 "data/scripts/battle_arcade_battle.pory"
	arcade_givepoints
# 315 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YouHaveClearedYourSeventh
# 316 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	return


BattleArcade_Challenge_EventScript_SaveWon::
# 321 "data/scripts/battle_arcade_battle.pory"
	special LoadPlayerParty
# 322 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_WON
# 323 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_Save
	return


BattleArcade_Challenge_EventScript_WarpToLobbyWon::
# 328 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SaveWon
# 329 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobby
	return


BattleArcade_Challenge_EventScript_HealPlayer::
# 335 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_GoodGoingWellHeal
# 336 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 337 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 338 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 339 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 340 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 341 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskReadyForOpponent::
# 346 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainstatus
# 347 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_Challenge_EventScript_AskReadyForOpponent_2
BattleArcade_Challenge_EventScript_AskReadyForOpponent_1:
# 352 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 353 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_ReadyForOpponent
# 354 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 355 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForOpponent_5
BattleArcade_Challenge_EventScript_AskReadyForOpponent_4:
# 359 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenu
	return

BattleArcade_Challenge_EventScript_AskReadyForOpponent_2:
# 349 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainUpNext
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_1

BattleArcade_Challenge_EventScript_AskReadyForOpponent_5:
# 357 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenuNoRecord
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_4


BattleArcade_Challenge_EventScript_ReadyForOpponent::
# 365 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 366 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_NextUpGameNoAreYouReady
# 367 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_Challenge_EventScript_ReadyMenu::
# 372 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 373 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 375 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenu_2
# 376 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenu_3
# 377 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenu_4
# 378 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_ReadyMenu_5
# 379 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenu_6
	return

BattleArcade_Challenge_EventScript_ReadyMenu_2:
# 375 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_3:
# 376 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_ReadyMenu_4:
# 377 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_5:
# 378 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_6:
# 379 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_ReadyMenuNoRecord::
# 385 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 386 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 387 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2
# 388 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3
# 389 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4
# 390 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2:
# 387 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3:
# 388 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4:
# 389 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5:
# 390 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle::
# 396 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
# 397 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattle::
# 402 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 403 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 404 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 405 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRecordBattle_1
	return

BattleArcade_Challenge_EventScript_AskRecordBattle_1:
# 407 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	return


BattleArcade_Challenge_EventScript_AskPauseChallenge::
# 413 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_WouldYouLikeToSaveAndTakeABreak, MSGBOX_YESNO
# 414 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_Challenge_EventScript_AskPauseChallenge_2
BattleArcade_Challenge_EventScript_AskPauseChallenge_1:
# 418 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskPauseChallenge_2:
# 416 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_PauseChallenge
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge_1


BattleArcade_Challenge_EventScript_PauseChallenge::
# 423 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_SavingDontTurnOffThePower
# 424 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 426 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_PAUSED
# 427 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 428 "data/scripts/battle_arcade_battle.pory"
	waitse
# 430 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 431 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_Challenge_EventScript_AskRetireChallenge::
# 437 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_Text_WouldYouLikeToRetire
# 438 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 439 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 440 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRetireChallenge_2
BattleArcade_Challenge_EventScript_AskRetireChallenge_1:
# 444 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskRetireChallenge_2:
# 442 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_RetireChallenge
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge_1


BattleArcade_Challenge_EventScript_RetireChallenge::
# 449 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_WarpToLobbyLost
	return


BattleArcade_Challenge_EventScript_ContinueChallenge::
# 454 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 455 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BrainUpNext::
# 460 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainUpNext_2
BattleArcade_Challenge_EventScript_BrainUpNext_1:
# 465 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_CongratulationsTrainerInRecognition, MSGBOX_DEFAULT
# 466 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, TRUE
# 468 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return

BattleArcade_Challenge_EventScript_BrainUpNext_2:
# 462 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	goto BattleArcade_Challenge_EventScript_BrainUpNext_1


BattleArcade_Challenge_EventScript_AskReadyForBrain::
# 473 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 474 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForBrain_1
# 480 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord
	return

BattleArcade_Challenge_EventScript_AskReadyForBrain_1:
# 476 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenu
	return


BattleArcade_Challenge_EventScript_BrainReadyMenu::
# 486 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 487 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 489 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenu_2
# 490 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenu_3
# 491 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenu_4
# 492 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_BrainReadyMenu_5
# 493 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenu_6
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_2:
# 489 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_3:
# 490 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_4:
# 491 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_5:
# 492 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_6:
# 493 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord::
# 499 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 500 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 502 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2
# 503 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3
# 504 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4
# 505 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2:
# 502 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3:
# 503 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4:
# 504 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5:
# 505 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainIntro::
# 511 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 512 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_2
# 517 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_NoNeedToWorry, MSGBOX_DEFAULT
# 518 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 519 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_4
# 525 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_YouAreProving, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_EventScript_BrainIntro_2:
	return

BattleArcade_Challenge_EventScript_BrainIntro_4:
# 521 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_IKnowOneThing, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_EventScript_BufferBrainPreBattleText::
# 531 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 532 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1
# 538 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_Text_WheneverIBattle
	return

BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1:
# 534 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_Text_AlwaysBeSmiling
	return


BattleArcade_Challenge_EventScript_BrainCongratsText::
# 544 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 545 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainCongratsText_2
# 551 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_TrulyItWasSoVery, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_BrainCongratsText_1:
# 553 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_BrainCongratsText_2:
# 547 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_Text_HowFabulousOfYouYour, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_BrainCongratsText_1


BattleArcade_Challenge_Text_WellDone::
# 556 "data/scripts/battle_arcade_battle.pory"
	.string "Well done!$"

BattleArcade_Challenge_Text_LetTheBattle::
# 561 "data/scripts/battle_arcade_battle.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

BattleArcade_Challenge_Text_Next::
# 566 "data/scripts/battle_arcade_battle.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

BattleArcade_Challenge_Text_Go::
# 571 "data/scripts/battle_arcade_battle.pory"
	.string "Go!$"

BattleArcade_Challenge_Text_DoYouWantToContinue::
# 576 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to continue arcade?$"

BattleArcade_Challenge_Text_DoYouWantToRestore::
# 581 "data/scripts/battle_arcade_battle.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

BattleArcade_Entrance_MaxedOutStreak::
# 586 "data/scripts/battle_arcade_battle.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

BattleArcade_Challenge_Text_FirstIllNeedToHoldOn::
# 591 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_Challenge_Text_PleaseWaitAMoment::
# 595 "data/scripts/battle_arcade_battle.pory"
	.string "Please wait a moment.$"

BattleArcade_Challenge_Text_GoodGoingWellHeal::
# 599 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_Challenge_Text_NextUpGameNoAreYouReady::
# 603 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_Challenge_Text_WouldYouLikeToSaveTheLastBattle::
# 607 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save the last battle\n"
	.string "as your Battle Video?$"

BattleArcade_Challenge_Text_BattleHasBeenSaved::
# 611 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s battle has been saved\n"
	.string "as a Battle Video.$"

BattleArcade_Challenge_Text_ThereWasAnError::
# 615 "data/scripts/battle_arcade_battle.pory"
	.string "There was an error. The Battle Video\n"
	.string "couldn’t be saved.$"

BattleArcade_Challenge_Text_DeleteYourExistingBattleVideo::
# 619 "data/scripts/battle_arcade_battle.pory"
	.string "Delete your existing Battle Video and\n"
	.string "save the last battle?$"

BattleArcade_Challenge_Text_SavingDontTurnOffThePower::
# 623 "data/scripts/battle_arcade_battle.pory"
	.string "Saving... Don’t turn off the power.$"

BattleArcade_Challenge_Text_WouldYouLikeToSaveAndTakeABreak::
# 627 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_Challenge_Text_WouldYouLikeToRetire::
# 631 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_Challenge_Text_IsChoosingPleaseWait::
# 635 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} is choosing. Please\n"
	.string "wait.$"

BattleArcade_Challenge_Text_ChoseToRetire::
# 639 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} chose to retire.$"

BattleArcade_Challenge_Text_WelcomeToTheBattleArcade::
# 643 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Battle Arcade!$"

BattleArcade_Challenge_Text_GameNoComeOn::
# 647 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_Challenge_Text_WithoutFurtherAdo::
# 651 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_Challenge_Text_ThisIsOurCurrentEvent::
# 655 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_Challenge_Text_MatchCommenceWithoutFullHp::
# 659 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_Challenge_Text_MatchCommenceBothWithoutFullHp::
# 663 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon without full HP!$"

BattleArcade_Challenge_Text_MatchCommenceLeveledUp::
# 667 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_Challenge_Text_MatchCommenceBothLeveledUp::
# 671 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\l"
	.string "Pokémon leveled up!$"

BattleArcade_Challenge_Text_MatchCommencePoisoned::
# 675 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_Challenge_Text_MatchCommenceBothPoisoned::
# 679 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon poisoned!$"

BattleArcade_Challenge_Text_MatchCommenceParalyzed::
# 683 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_Challenge_Text_MatchCommenceBothParalyzed::
# 687 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon paralyzed!$"

BattleArcade_Challenge_Text_MatchCommenceBurned::
# 691 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_Challenge_Text_MatchCommenceBothBurned::
# 695 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon burned!$"

BattleArcade_Challenge_Text_MatchCommenceAsleep::
# 699 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_Challenge_Text_MatchCommenceBothAsleep::
# 703 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon asleep!$"

BattleArcade_Challenge_Text_MatchCommenceFrozen::
# 707 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_Challenge_Text_MatchCommenceBothFrozen::
# 711 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\l"
	.string "Pokémon frozen!$"

BattleArcade_Challenge_Text_PokemonWillBeLoanedThe::
# 715 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_Challenge_Text_BothPokemonWillBeLoanedThe::
# 719 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1} and {STR_VAR_2}’s\n"
	.string "Pokémon will be loaned the\l"
	.string "{STR_VAR_3}.$"

BattleArcade_Challenge_Text_HereYouGo::
# 723 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_Challenge_Text_MatchConductedHarshSunlight::
# 727 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_Challenge_Text_MatchConductedSteadyRainfall::
# 731 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_Challenge_Text_MatchConductedRagingSandstorm::
# 735 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_Challenge_Text_MatchConductedPeltingHail::
# 739 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_Challenge_Text_MatchConductedDenseFog::
# 743 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_Challenge_Text_MatchConductedTimeAndSpaceAreDistorted::
# 747 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_Challenge_Text_YourPokemonWillBeSwitched::
# 751 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_Challenge_Text_BoardspeedIncreased::
# 755 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_Challenge_Text_BoardspeedDecreased::
# 759 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_Challenge_Text_BoardmotionRandom::
# 763 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_Challenge_Text_ReceivedBp::
# 767 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} received {STR_VAR_1} BP!$"

BattleArcade_Challenge_Text_AndReceivedBp::
# 771 "data/scripts/battle_arcade_battle.pory"
	.string "{PLAYER} and {STR_VAR_2} received\n"
	.string "{STR_VAR_3} BP!$"

BattleArcade_Challenge_Text_AreYouReady::
# 775 "data/scripts/battle_arcade_battle.pory"
	.string "Are you ready?$"

BattleArcade_Challenge_Text_OhLuckyYouCanSkip::
# 779 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_Challenge_Text_TooBadThereIsNo::
# 783 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_Challenge_Text_OkLetTheBattleCommence::
# 787 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_Challenge_Text_MatchPoisonedLuckyBreak::
# 791 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_Challenge_Text_MatchBothPoisonedLuckyBreak::
# 795 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin poisoned... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be poisoned!$"

BattleArcade_Challenge_Text_MatchParalyzedLuckyBreak::
# 799 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_Challenge_Text_MatchBothParalyzedLuckyBreak::
# 803 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin paralyzed... Oh! A\l"
	.string "lucky break! Neither of them has a\l"
	.string "Pokémon that can be paralyzed!$"

BattleArcade_Challenge_Text_MatchBurnedLuckyBreak::
# 807 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_Challenge_Text_MatchBothBurnedLuckyBreak::
# 811 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin burned... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be burned!$"

BattleArcade_Challenge_Text_MatchAsleepLuckyBreak::
# 815 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_Challenge_Text_MatchBothAsleepLuckyBreak::
# 819 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin asleep... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be made to sleep!$"

BattleArcade_Challenge_Text_MatchFrozenLuckyBreak::
# 823 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_Challenge_Text_MatchBothFrozenLuckyBreak::
# 827 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s and {STR_VAR_2}’s\n"
	.string "Pokémon will begin frozen... Oh! A lucky\l"
	.string "break! Neither of them has a Pokémon\l"
	.string "that can be frozen!$"

BattleArcade_Challenge_Text_YouHaveClearedYourSeventh::
# 831 "data/scripts/battle_arcade_battle.pory"
	.string "You have cleared your seventh battle!\n"
	.string "Congratulations! You have earned BP as\l"
	.string "your prize!$"

BattleArcade_Challenge_Text_WeWillReturnAnyItems::
# 835 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_Challenge_Text_Continue::
# 839 "data/scripts/battle_arcade_battle.pory"
	.string "CONTINUE$"

BattleArcade_Challenge_Text_Record::
# 843 "data/scripts/battle_arcade_battle.pory"
	.string "RECORD$"

BattleArcade_Challenge_Text_Rest::
# 847 "data/scripts/battle_arcade_battle.pory"
	.string "REST$"

BattleArcade_Challenge_Text_Retire::
# 851 "data/scripts/battle_arcade_battle.pory"
	.string "RETIRE$"

BattleArcade_Challenge_Text_CongratulationsTrainerInRecognition::
# 856 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding skill,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "the Arcade Star; no ifs or buts! Are you\l"
	.string "ready?$"

BattleArcade_Challenge_Text_NoNeedToWorry::
# 861 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: No need to worry. {EMOJI_NOTE}\n"
	.string "Let chance do what it does. Like\l"
	.string "surprises from the game board, life\l"
	.string "goes through twists and turns. No need\l"
	.string "to worry. {EMOJI_NOTE}\l"
	.string "Things will go as they will. But, enough\l"
	.string "of that.$"

BattleArcade_Challenge_Text_IKnowOneThing::
# 866 "data/scripts/battle_arcade_battle.pory"
	.string "I know one thing for certain. You have\n"
	.string "arrived here not merely because you\l"
	.string "were lucky. Let us not waste any time. I\l"
	.string "wish to test your skills myself!$"

BattleArcade_Challenge_Text_YouAreProving::
# 870 "data/scripts/battle_arcade_battle.pory"
	.string "You are proving yourself incredible. Are\n"
	.string "you incredible because you are so lucky\l"
	.string "you shrug off bad luck entirely? Or, are\l"
	.string "you so incredibly talented to not be\l"
	.string "swayed by luck, good or bad? I wish to\l"
	.string "see for myself what brought you to me\l"
	.string "today!$"

BattleArcade_Challenge_Text_AlwaysBeSmiling::
# 874 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Always be smiling! Luck comes to\n"
	.string "those who are happy! That's why I\l"
	.string "always keep a big smile and believe in my\l"
	.string "Pokémon when I battle.$"

BattleArcade_Challenge_Text_WheneverIBattle::
# 878 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Whenever I battle someone\n"
	.string "tough, I smile. I cannot help it! How\l"
	.string "about you? What do you do? Do you\l"
	.string "laugh? Cry? Get angry?$"

BattleArcade_Challenge_Text_HowFabulousOfYouYour::
# 882 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: How fabulous of you! Your love\n"
	.string "of Pokémon shone through, and, in turn,\l"
	.string "your Pokémon believed in you. That is\l"
	.string "why you handled everything thrown your\l"
	.string "way splendidly. A most wonderful\l"
	.string "victory it was!$"

BattleArcade_Challenge_Text_TrulyItWasSoVery::
# 886 "data/scripts/battle_arcade_battle.pory"
	.string "Dahlia: Truly, it was so very fabulous\n"
	.string "of all of you! Bad luck, you cast aside,\l"
	.string "and good luck, you netted. That you did\l"
	.string "so is evidence of your abilities. By\l"
	.string "defeating me, Dahlia, you have proven\l"
	.string "your mastery brilliantly! I am sincerely\l"
	.string "happy for having this battle against\l"
	.string "you!$"
