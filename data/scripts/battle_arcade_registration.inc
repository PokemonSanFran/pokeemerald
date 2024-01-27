BattleArcade_Registration_EventScript_SinglesAttendant::
# 10 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_SINGLES
# 11 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_Attendant
	return


BattleArcade_Registration_EventScript_MultisAttendant::
# 16 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_MULTIS
# 17 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_Attendant
	return


BattleArcade_Registration_EventScript_Attendant::
# 23 "data/scripts/battle_arcade_registration.pory"
	arcade_playgameboard
# 24 "data/scripts/battle_arcade_registration.pory"
	end
# 25 "data/scripts/battle_arcade_registration.pory"
	lock
# 26 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 27 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
# 29 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 30 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleArcade_Registration_EventScript_Attendant_1
# 37 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti, MSGBOX_DEFAULT
# 38 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterMultiChallenge
	return

BattleArcade_Registration_EventScript_Attendant_1:
# 32 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
# 33 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterChallenge
	return


BattleArcade_Registration_EventScript_AskEnterChallenge::
# 44 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichChallengeWouldYouLike
# 45 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 46 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_CHALLENGE_TYPES_INFO, FALSE
# 47 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 49 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleArcade_Registration_EventScript_AskEnterChallenge_2
# 50 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleArcade_Registration_EventScript_AskEnterChallenge_2
# 53 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskEnterChallenge_3
# 55 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleArcade_Registration_EventScript_AskEnterChallenge_4
# 56 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskEnterChallenge_4
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_2:
# 51 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_FRONTIER_BATTLE_MODE, VAR_RESULT
# 52 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_TryEnterChallenge
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_3:
# 54 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ExplainChallenge
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_4:
# 57 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_AskEnterMultiChallenge::
# 63 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WouldYouLikeToTake
# 64 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 65 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 5, MULTI_CHALLENGEINFO, FALSE
# 66 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 68 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_2
# 71 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_3
# 73 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4
# 74 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_2:
# 69 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 70 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_TryEnterChallenge
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_3:
# 72 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ExplainChallenge
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4:
# 75 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_ExplainChallenge::
# 81 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleArcade_Registration_EventScript_ExplainChallenge_1
# 88 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_YouMayTeamUpWith, MSGBOX_DEFAULT
# 89 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterMultiChallenge
	return

BattleArcade_Registration_EventScript_ExplainChallenge_1:
# 83 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade, MSGBOX_DEFAULT
# 84 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterChallenge
	return


BattleArcade_Registration_EventScript_TryEnterChallenge::
# 95 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichLevelMode
# 96 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 97 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 98 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 100 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_LVL_TENT, BattleArcade_Registration_EventScript_TryEnterChallenge_3
# 101 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_TryEnterChallenge_4
BattleArcade_Registration_EventScript_TryEnterChallenge_1:
# 103 "data/scripts/battle_arcade_registration.pory"
	frontier_checkineligible
# 104 "data/scripts/battle_arcade_registration.pory"
	compare VAR_0x8004, 0
	goto_if_ne BattleArcade_Registration_EventScript_TryEnterChallenge_6
BattleArcade_Registration_EventScript_TryEnterChallenge_5:
# 109 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 110 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_PleaseSelectThePokemonYou, MSGBOX_DEFAULT
# 112 "data/scripts/battle_arcade_registration.pory"
	fadescreen FADE_TO_BLACK
# 113 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 114 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 115 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 117 "data/scripts/battle_arcade_registration.pory"
	special ChoosePartyForBattleFrontier
# 118 "data/scripts/battle_arcade_registration.pory"
	waitstate
# 119 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Registration_EventScript_TryEnterChallenge_9
BattleArcade_Registration_EventScript_TryEnterChallenge_8:
# 123 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge
	return

BattleArcade_Registration_EventScript_TryEnterChallenge_3:
# 100 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_1

BattleArcade_Registration_EventScript_TryEnterChallenge_4:
# 101 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_1

BattleArcade_Registration_EventScript_TryEnterChallenge_6:
# 106 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 107 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_NotEnoughValidMons
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_5

BattleArcade_Registration_EventScript_TryEnterChallenge_9:
# 121 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LoadPartyCancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_8


BattleArcade_Registration_EventScript_GetPartySize::
# 128 "data/scripts/battle_arcade_registration.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 130 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleArcade_Registration_EventScript_GetPartySize_3
# 131 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleArcade_Registration_EventScript_GetPartySize_4
# 132 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleArcade_Registration_EventScript_GetPartySize_5
BattleArcade_Registration_EventScript_GetPartySize_1:
	return

BattleArcade_Registration_EventScript_GetPartySize_3:
# 130 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1

BattleArcade_Registration_EventScript_GetPartySize_4:
# 131 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1

BattleArcade_Registration_EventScript_GetPartySize_5:
# 132 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1


BattleArcade_Registration_EventScript_NotEnoughValidMons::
# 139 "data/scripts/battle_arcade_registration.pory"
	buffernumberstring STR_VAR_2, VAR_0x8005
# 140 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
# 142 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 143 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleArcade_Registration_EventScript_NotEnoughValidMons_2
BattleArcade_Registration_EventScript_NotEnoughValidMons_1:
# 147 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
# 148 "data/scripts/battle_arcade_registration.pory"
	closemessage
	end

BattleArcade_Registration_EventScript_NotEnoughValidMons_2:
# 145 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleArcade_Registration_EventScript_NotEnoughValidMons_1


BattleArcade_Registration_EventScript_LoadPartyCancelChallenge::
# 154 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 155 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_CancelChallenge::
# 160 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 161 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_SaveBeforeChallenge::
# 167 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 168 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 169 "data/scripts/battle_arcade_registration.pory"
	arcade_init
# 170 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, TRUE
# 171 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 172 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 173 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 174 "data/scripts/battle_arcade_registration.pory"
	delay 2
# 176 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleArcade_Registration_EventScript_SaveBeforeChallenge_2
BattleArcade_Registration_EventScript_SaveBeforeChallenge_1:
# 182 "data/scripts/battle_arcade_registration.pory"
	call Common_EventScript_SaveGame
# 183 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 185 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Registration_EventScript_SaveBeforeChallenge_5
BattleArcade_Registration_EventScript_SaveBeforeChallenge_4:
# 191 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_HandleMultiplayer
# 192 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_EnterElevator
	return

BattleArcade_Registration_EventScript_SaveBeforeChallenge_2:
# 178 "data/scripts/battle_arcade_registration.pory"
	arcade_save 0
# 179 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Entrance_LinkMulti_EventScript_Cancel
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge_1

BattleArcade_Registration_EventScript_SaveBeforeChallenge_5:
# 187 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 188 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge_4


BattleArcade_Registration_EventScript_HandleMultiplayer::
# 197 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_ne BattleArcade_Registration_EventScript_HandleMultiplayer_2
# 202 "data/scripts/battle_arcade_registration.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 203 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_HandleMultiplayer_5
BattleArcade_Registration_EventScript_HandleMultiplayer_4:
# 207 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	return

BattleArcade_Registration_EventScript_HandleMultiplayer_2:
	return

BattleArcade_Registration_EventScript_HandleMultiplayer_5:
# 205 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleArcade_Registration_EventScript_HandleMultiplayer_4


BattleArcade_Registration_EventScript_EnterElevator::
# 212 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 213 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 214 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 215 "data/scripts/battle_arcade_registration.pory"
	special CallFrontierUtilFunc
# 216 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, 0
# 217 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_GoToHallway
	return


BattleArcade_Registration_EventScript_GoToHallway::
# 222 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ShowYouToBattleRoom
# 223 "data/scripts/battle_arcade_registration.pory"
	special HealPlayerParty
# 224 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Lobby_EventScript_WarpToHallway
# 225 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 226 "data/scripts/battle_arcade_registration.pory"
	waitstate
	end


BattleArcade_Registration_EventScript_ShowYouToBattleRoom::
# 232 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
# 233 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Lobby_EventScript_WalkToElevator
	return


BattleArcade_Registration_EventScript_GetChallengeStatus::
# 239 "data/scripts/battle_arcade_registration.pory"
	frontier_getstatus
	end


BattleArcade_Registration_EventScript_ResetChallengeStatus::
# 245 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
	return


BattleArcade_Registration_EventScript_WonChallenge::
# 251 "data/scripts/battle_arcade_registration.pory"
	lock
# 252 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 254 "data/scripts/battle_arcade_registration.pory"
	frontier_isbrain
# 255 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_WonChallenge_2
BattleArcade_Registration_EventScript_WonChallenge_1:
# 259 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ResetChallengeStatus
# 260 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LookForwardToChallenge
	return

BattleArcade_Registration_EventScript_WonChallenge_2:
# 257 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_CheckStreakAndSymbols
	goto BattleArcade_Registration_EventScript_WonChallenge_1


BattleArcade_Registration_EventScript_CheckStreakAndSymbols::
# 265 "data/scripts/battle_arcade_registration.pory"
	arcade_checksymbol
# 266 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 268 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_SILVER, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_2
# 270 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_GOLD, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_3
# 272 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_NONE, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_4
BattleArcade_Registration_EventScript_CheckStreakAndSymbols_4:
	return

BattleArcade_Registration_EventScript_CheckStreakAndSymbols_2:
# 269 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GiveSilverPrint
	return

BattleArcade_Registration_EventScript_CheckStreakAndSymbols_3:
# 271 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GiveGoldPrint
	return


BattleArcade_Registration_EventScript_GiveGoldPrint::
# 280 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 281 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheGoldPrintWasAdded, MSGBOX_DEFAULT
# 282 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GivePrint
	return


BattleArcade_Registration_EventScript_GiveSilverPrint::
# 287 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 288 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheSilverPrintWasAdded, MSGBOX_DEFAULT
# 289 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GivePrint
	return


BattleArcade_Registration_EventScript_QuitWithoutSaving::
# 294 "data/scripts/battle_arcade_registration.pory"
	lock
# 295 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 296 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDidnt, MSGBOX_DEFAULT
# 297 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 298 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK, 0
# 299 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
# 300 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 301 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 302 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_GivePrint::
# 308 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_CheckandGivePrint
# 309 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_PlayFanfareMessage
	return


BattleArcade_Registration_EventScript_CheckandGivePrint::
# 315 "data/scripts/battle_arcade_registration.pory"
	goto_if_set FLAG_ARCADE_SILVER_PRINT, BattleArcade_Registration_EventScript_CheckandGivePrint_1
# 321 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_SILVER_PRINT
	return

BattleArcade_Registration_EventScript_CheckandGivePrint_1:
# 317 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_GOLD_PRINT
	return


BattleArcade_Registration_EventScript_PlayFanfareMessage::
# 327 "data/scripts/battle_arcade_registration.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 328 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 329 "data/scripts/battle_arcade_registration.pory"
	waitfanfare
	return


BattleArcade_Registration_EventScript_LookForwardToChallenge::
# 335 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 336 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 337 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_LostChallenge::
# 343 "data/scripts/battle_arcade_registration.pory"
	arcade_get ARCADE_DATA_WIN_STREAK
# 344 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_LostChallenge_2
BattleArcade_Registration_EventScript_LostChallenge_1:
# 348 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ResetChallengeStatus
# 349 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LostThanksForPlaying
	return

BattleArcade_Registration_EventScript_LostChallenge_2:
# 346 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
	goto BattleArcade_Registration_EventScript_LostChallenge_1


BattleArcade_Registration_EventScript_LostThanksForPlaying::
# 354 "data/scripts/battle_arcade_registration.pory"
	lock
# 355 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 356 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 357 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 358 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 359 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_ResumeChallenge::
# 365 "data/scripts/battle_arcade_registration.pory"
	lock
# 366 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 368 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WeveMissedYou
# 369 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 371 "data/scripts/battle_arcade_registration.pory"
	arcade_save CHALLENGE_STATUS_SAVING
# 372 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 373 "data/scripts/battle_arcade_registration.pory"
	waitse
# 374 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 376 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_EnterElevator
	end


BattleArcade_Entrance_LinkMulti_EventScript_Cancel::
# 382 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_LinkMultisAreNot
# 383 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 384 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 385 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_AskModeResultsBoard::
# 390 "data/scripts/battle_arcade_registration.pory"
	lockall
# 391 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_ReadWhichRecord
# 392 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 393 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RECORDS, FALSE
# 394 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 396 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskModeResultsBoard_2
# 399 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleArcade_Registration_EventScript_AskModeResultsBoard_3
# 400 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskModeResultsBoard_3
# 405 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ShowResults
	return

BattleArcade_Registration_EventScript_AskModeResultsBoard_2:
# 397 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
# 398 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ShowResults
	return

BattleArcade_Registration_EventScript_AskModeResultsBoard_3:
# 401 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 402 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleArcade_Registration_EventScript_ShowResults::
# 411 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 412 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8006, VAR_RESULT
# 413 "data/scripts/battle_arcade_registration.pory"
	arcade_results VAR_0x8006
# 414 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskModeResultsBoard
	return


GiveMonDebugScript::
# 539 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_SALAMENCE, 50, ITEM_LEFTOVERS
# 540 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_METAGROSS, 50, ITEM_CHOICE_BAND
# 541 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_LATIOS, 50, ITEM_LUM_BERRY
# 542 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_NUZLEAF, 50, ITEM_STARF_BERRY
# 543 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_SYS_POKEMON_GET
	return


BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
# 417 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\l"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
# 422 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\l"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
# 427 "data/scripts/battle_arcade_registration.pory"
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
# 432 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_WhichLevelMode::
# 437 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
# 442 "data/scripts/battle_arcade_registration.pory"
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
# 447 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\l"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
# 452 "data/scripts/battle_arcade_registration.pory"
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_EggsAndAre::
# 457 "data/scripts/battle_arcade_registration.pory"
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
# 462 "data/scripts/battle_arcade_registration.pory"
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
# 467 "data/scripts/battle_arcade_registration.pory"
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
# 472 "data/scripts/battle_arcade_registration.pory"
	.string "At the Battle Arcade, you may take a\n"
	.string "Single or Double Battle challenge. Here,\l"
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
	.string "please save the game. If you don't save,\l"
	.string "you will be disqualified from your\l"
	.string "challenge. Please be aware of that!$"

BattleArcade_Entrance_Text_YouMayTeamUpWith::
# 477 "data/scripts/battle_arcade_registration.pory"
	.string "You may team up with a friend for a\n"
	.string "Multi Battle challenge. Here, a game\l"
	.string "board is activated before every match.\l"
	.string "Depending on what comes up on the game\l"
	.string "board, an event takes place. The events\l"
	.string "may have great impact on the match's\l"
	.string "outcome, good or bad. The objective is\l"
	.string "to keep a winning streak alive as long\l"
	.string "as possible. During your challenge, any\l"
	.string "items held by your Pokémon will be kept\l"
	.string "in storage. If you manage to win seven\l"
	.string "matches in a row, you will earn Battle\l"
	.string "Points (BP). Please note: a Battle\l"
	.string "Arcade Multi Battle challenge can't be\l"
	.string "interrupted.$"

BattleArcade_Entrance_Text_WeveMissedYou::
# 482 "data/scripts/battle_arcade_registration.pory"
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\l"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
# 487 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\l"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
# 492 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\l"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
# 497 "data/scripts/battle_arcade_registration.pory"
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
# 502 "data/scripts/battle_arcade_registration.pory"
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_WeHopeToSeeYou::
# 507 "data/scripts/battle_arcade_registration.pory"
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_ReadWhichRecord::
# 512 "data/scripts/battle_arcade_registration.pory"
	.string "Which record would you like to see?$"

BattleArcade_Entrance_Text_LinkMultisAreNot::
# 517 "data/scripts/battle_arcade_registration.pory"
	.string "I'm sorry! Link Multi Battles have not\n"
	.string "been implemented at this time. Please\l"
	.string "come back later.$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
# 524 "data/scripts/battle_arcade_registration.pory"
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\l"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
# 528 "data/scripts/battle_arcade_registration.pory"
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
# 532 "data/scripts/battle_arcade_registration.pory"
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"
