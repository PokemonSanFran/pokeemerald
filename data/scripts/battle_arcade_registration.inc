BattleArcade_Registration_EventScript_SinglesAttendant::
# 9 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_SINGLES
# 10 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_Attendant
	return


BattleArcade_Registration_EventScript_MultisAttendant::
# 15 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_MULTIS
# 16 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_Attendant
	return


BattleArcade_Registration_EventScript_Attendant::
# 24 "data/scripts/battle_arcade_registration.pory"
	lock
# 25 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 26 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
# 28 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 29 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleArcade_Registration_EventScript_Attendant_1
# 36 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti, MSGBOX_DEFAULT
# 37 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterMultiChallenge
	return

BattleArcade_Registration_EventScript_Attendant_1:
# 31 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
# 32 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterChallenge
	return


BattleArcade_Registration_EventScript_AskEnterChallenge::
# 43 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichChallengeWouldYouLike
# 44 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 45 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_CHALLENGE_TYPES_INFO, FALSE
# 46 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 48 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleArcade_Registration_EventScript_AskEnterChallenge_2
# 49 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleArcade_Registration_EventScript_AskEnterChallenge_2
# 52 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskEnterChallenge_3
# 54 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleArcade_Registration_EventScript_AskEnterChallenge_4
# 55 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskEnterChallenge_4
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_2:
# 50 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_FRONTIER_BATTLE_MODE, VAR_RESULT
# 51 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_TryEnterChallenge
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_3:
# 53 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ExplainChallenge
	return

BattleArcade_Registration_EventScript_AskEnterChallenge_4:
# 56 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_AskEnterMultiChallenge::
# 62 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WouldYouLikeToTake
# 63 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 64 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 5, MULTI_CHALLENGEINFO, FALSE
# 65 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 67 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_2
# 70 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_3
# 72 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4
# 73 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_2:
# 68 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 69 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_TryEnterChallenge
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_3:
# 71 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ExplainChallenge
	return

BattleArcade_Registration_EventScript_AskEnterMultiChallenge_4:
# 74 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_ExplainChallenge::
# 80 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleArcade_Registration_EventScript_ExplainChallenge_1
# 87 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_YouMayTeamUpWith, MSGBOX_DEFAULT
# 88 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterMultiChallenge
	return

BattleArcade_Registration_EventScript_ExplainChallenge_1:
# 82 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade, MSGBOX_DEFAULT
# 83 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskEnterChallenge
	return


BattleArcade_Registration_EventScript_TryEnterChallenge::
# 94 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichLevelMode
# 95 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 96 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 97 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 99 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_LVL_TENT, BattleArcade_Registration_EventScript_TryEnterChallenge_3
# 100 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_TryEnterChallenge_4
BattleArcade_Registration_EventScript_TryEnterChallenge_1:
# 102 "data/scripts/battle_arcade_registration.pory"
	frontier_checkineligible
# 103 "data/scripts/battle_arcade_registration.pory"
	compare VAR_0x8004, 0
	goto_if_ne BattleArcade_Registration_EventScript_TryEnterChallenge_6
BattleArcade_Registration_EventScript_TryEnterChallenge_5:
# 108 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 109 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_PleaseSelectThePokemonYou, MSGBOX_DEFAULT
# 111 "data/scripts/battle_arcade_registration.pory"
	fadescreen FADE_TO_BLACK
# 112 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 113 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 114 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 116 "data/scripts/battle_arcade_registration.pory"
	special ChoosePartyForBattleFrontier
# 117 "data/scripts/battle_arcade_registration.pory"
	waitstate
# 118 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Registration_EventScript_TryEnterChallenge_9
BattleArcade_Registration_EventScript_TryEnterChallenge_8:
# 122 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge
	return

BattleArcade_Registration_EventScript_TryEnterChallenge_3:
# 99 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_1

BattleArcade_Registration_EventScript_TryEnterChallenge_4:
# 100 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_1

BattleArcade_Registration_EventScript_TryEnterChallenge_6:
# 105 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 106 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_NotEnoughValidMons
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_5

BattleArcade_Registration_EventScript_TryEnterChallenge_9:
# 120 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LoadPartyCancelChallenge
	goto BattleArcade_Registration_EventScript_TryEnterChallenge_8


BattleArcade_Registration_EventScript_GetPartySize::
# 127 "data/scripts/battle_arcade_registration.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 129 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleArcade_Registration_EventScript_GetPartySize_3
# 130 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleArcade_Registration_EventScript_GetPartySize_4
# 131 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleArcade_Registration_EventScript_GetPartySize_5
BattleArcade_Registration_EventScript_GetPartySize_1:
	return

BattleArcade_Registration_EventScript_GetPartySize_3:
# 129 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1

BattleArcade_Registration_EventScript_GetPartySize_4:
# 130 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1

BattleArcade_Registration_EventScript_GetPartySize_5:
# 131 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleArcade_Registration_EventScript_GetPartySize_1


BattleArcade_Registration_EventScript_NotEnoughValidMons::
# 138 "data/scripts/battle_arcade_registration.pory"
	buffernumberstring STR_VAR_2, VAR_0x8005
# 139 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
# 141 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 142 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleArcade_Registration_EventScript_NotEnoughValidMons_2
BattleArcade_Registration_EventScript_NotEnoughValidMons_1:
# 146 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
# 147 "data/scripts/battle_arcade_registration.pory"
	closemessage
	end

BattleArcade_Registration_EventScript_NotEnoughValidMons_2:
# 144 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleArcade_Registration_EventScript_NotEnoughValidMons_1


BattleArcade_Registration_EventScript_LoadPartyCancelChallenge::
# 153 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 154 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_CancelChallenge::
# 159 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 160 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_SaveBeforeChallenge::
# 166 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 167 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 168 "data/scripts/battle_arcade_registration.pory"
	arcade_init
# 169 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, TRUE
# 170 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 171 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 172 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 173 "data/scripts/battle_arcade_registration.pory"
	delay 2
# 175 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleArcade_Registration_EventScript_SaveBeforeChallenge_2
BattleArcade_Registration_EventScript_SaveBeforeChallenge_1:
# 181 "data/scripts/battle_arcade_registration.pory"
	call Common_EventScript_SaveGame
# 182 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 184 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Registration_EventScript_SaveBeforeChallenge_5
BattleArcade_Registration_EventScript_SaveBeforeChallenge_4:
# 190 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_HandleMultiplayer
# 191 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_EnterElevator
	return

BattleArcade_Registration_EventScript_SaveBeforeChallenge_2:
# 177 "data/scripts/battle_arcade_registration.pory"
	arcade_save 0
# 178 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Entrance_LinkMulti_EventScript_Cancel
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge_1

BattleArcade_Registration_EventScript_SaveBeforeChallenge_5:
# 186 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 187 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	goto BattleArcade_Registration_EventScript_SaveBeforeChallenge_4


BattleArcade_Registration_EventScript_HandleMultiplayer::
# 196 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_ne BattleArcade_Registration_EventScript_HandleMultiplayer_2
# 201 "data/scripts/battle_arcade_registration.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 202 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_HandleMultiplayer_5
BattleArcade_Registration_EventScript_HandleMultiplayer_4:
# 206 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	return

BattleArcade_Registration_EventScript_HandleMultiplayer_2:
	return

BattleArcade_Registration_EventScript_HandleMultiplayer_5:
# 204 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleArcade_Registration_EventScript_HandleMultiplayer_4


BattleArcade_Registration_EventScript_EnterElevator::
# 211 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 212 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 213 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GetPartySize
# 214 "data/scripts/battle_arcade_registration.pory"
	special CallFrontierUtilFunc
# 215 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, 0
# 216 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_GoToHallway
	return


BattleArcade_Registration_EventScript_GoToHallway::
# 221 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ShowYouToBattleRoom
# 222 "data/scripts/battle_arcade_registration.pory"
	special HealPlayerParty
# 223 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Lobby_EventScript_WarpToHallway
# 224 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 225 "data/scripts/battle_arcade_registration.pory"
	waitstate
	end


BattleArcade_Registration_EventScript_ShowYouToBattleRoom::
# 231 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
# 232 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Lobby_EventScript_WalkToElevator
	return


BattleArcade_Registration_EventScript_GetChallengeStatus::
# 238 "data/scripts/battle_arcade_registration.pory"
	frontier_getstatus
	end


BattleArcade_Registration_EventScript_ResetChallengeStatus::
# 244 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	return


BattleArcade_Registration_EventScript_WonChallenge::
# 250 "data/scripts/battle_arcade_registration.pory"
	lock
# 251 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 253 "data/scripts/battle_arcade_registration.pory"
	frontier_isbrain
# 254 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_WonChallenge_2
BattleArcade_Registration_EventScript_WonChallenge_1:
# 258 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ResetChallengeStatus
# 259 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LookForwardToChallenge
	return

BattleArcade_Registration_EventScript_WonChallenge_2:
# 256 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_CheckStreakAndSymbols
	goto BattleArcade_Registration_EventScript_WonChallenge_1


BattleArcade_Registration_EventScript_CheckStreakAndSymbols::
# 264 "data/scripts/battle_arcade_registration.pory"
	arcade_checksymbol
# 265 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 267 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_SILVER, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_2
# 269 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_GOLD, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_3
# 271 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_NONE, BattleArcade_Registration_EventScript_CheckStreakAndSymbols_4
BattleArcade_Registration_EventScript_CheckStreakAndSymbols_4:
	return

BattleArcade_Registration_EventScript_CheckStreakAndSymbols_2:
# 268 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GiveSilverPrint
	return

BattleArcade_Registration_EventScript_CheckStreakAndSymbols_3:
# 270 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GiveGoldPrint
	return


BattleArcade_Registration_EventScript_GiveGoldPrint::
# 279 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 280 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheGoldPrintWasAdded, MSGBOX_DEFAULT
# 281 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GivePrint
	return


BattleArcade_Registration_EventScript_GiveSilverPrint::
# 286 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 287 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheSilverPrintWasAdded, MSGBOX_DEFAULT
# 288 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_GivePrint
	return


BattleArcade_Registration_EventScript_QuitWithoutSaving::
# 293 "data/scripts/battle_arcade_registration.pory"
	lock
# 294 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 295 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDidnt, MSGBOX_DEFAULT
# 296 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 297 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK, 0
# 298 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
# 299 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 300 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 301 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_GivePrint::
# 307 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_CheckandGivePrint
# 308 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_PlayFanfareMessage
	return


BattleArcade_Registration_EventScript_CheckandGivePrint::
# 314 "data/scripts/battle_arcade_registration.pory"
	goto_if_set FLAG_ARCADE_SILVER_PRINT, BattleArcade_Registration_EventScript_CheckandGivePrint_1
# 320 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_SILVER_PRINT
	return

BattleArcade_Registration_EventScript_CheckandGivePrint_1:
# 316 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_GOLD_PRINT
	return


BattleArcade_Registration_EventScript_PlayFanfareMessage::
# 326 "data/scripts/battle_arcade_registration.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 327 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 328 "data/scripts/battle_arcade_registration.pory"
	waitfanfare
	return


BattleArcade_Registration_EventScript_LookForwardToChallenge::
# 334 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 335 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 336 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_LostChallenge::
# 342 "data/scripts/battle_arcade_registration.pory"
	arcade_get ARCADE_DATA_WIN_STREAK
# 343 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Registration_EventScript_LostChallenge_2
BattleArcade_Registration_EventScript_LostChallenge_1:
# 347 "data/scripts/battle_arcade_registration.pory"
	call BattleArcade_Registration_EventScript_ResetChallengeStatus
# 348 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_LostThanksForPlaying
	return

BattleArcade_Registration_EventScript_LostChallenge_2:
# 345 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
	goto BattleArcade_Registration_EventScript_LostChallenge_1


BattleArcade_Registration_EventScript_LostThanksForPlaying::
# 353 "data/scripts/battle_arcade_registration.pory"
	lock
# 354 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 355 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 356 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 357 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 358 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleArcade_Registration_EventScript_ResumeChallenge::
# 364 "data/scripts/battle_arcade_registration.pory"
	lock
# 365 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 367 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WeveMissedYou
# 368 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 370 "data/scripts/battle_arcade_registration.pory"
	arcade_save CHALLENGE_STATUS_SAVING
# 371 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 372 "data/scripts/battle_arcade_registration.pory"
	waitse
# 373 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 375 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_EnterElevator
	end


BattleArcade_Entrance_LinkMulti_EventScript_Cancel::
# 381 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_LinkMultisAreNot
# 382 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 383 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 384 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_CancelChallenge
	return


BattleArcade_Registration_EventScript_AskModeResultsBoard::
# 389 "data/scripts/battle_arcade_registration.pory"
	lockall
# 390 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_ReadWhichRecord
# 391 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 392 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RECORDS, FALSE
# 393 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 395 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleArcade_Registration_EventScript_AskModeResultsBoard_2
# 398 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleArcade_Registration_EventScript_AskModeResultsBoard_3
# 399 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleArcade_Registration_EventScript_AskModeResultsBoard_3
# 404 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ShowResults
	return

BattleArcade_Registration_EventScript_AskModeResultsBoard_2:
# 396 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
# 397 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_ShowResults
	return

BattleArcade_Registration_EventScript_AskModeResultsBoard_3:
# 400 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 401 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleArcade_Registration_EventScript_ShowResults::
# 410 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 411 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8006, VAR_RESULT
# 412 "data/scripts/battle_arcade_registration.pory"
	arcade_results VAR_0x8006
# 413 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Registration_EventScript_AskModeResultsBoard
	return


GiveMonDebugScript::
# 538 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_SALAMENCE, 50, ITEM_LEFTOVERS
# 539 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_METAGROSS, 50, ITEM_CHOICE_BAND
# 540 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_LATIOS, 50, ITEM_LUM_BERRY
# 541 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_NUZLEAF, 50, ITEM_STARF_BERRY
# 542 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_SYS_POKEMON_GET
	return


BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
# 416 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\l"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
# 421 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\l"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
# 426 "data/scripts/battle_arcade_registration.pory"
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
# 431 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_WhichLevelMode::
# 436 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
# 441 "data/scripts/battle_arcade_registration.pory"
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
# 446 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\l"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
# 451 "data/scripts/battle_arcade_registration.pory"
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_EggsAndAre::
# 456 "data/scripts/battle_arcade_registration.pory"
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
# 461 "data/scripts/battle_arcade_registration.pory"
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
# 466 "data/scripts/battle_arcade_registration.pory"
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
# 471 "data/scripts/battle_arcade_registration.pory"
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
# 476 "data/scripts/battle_arcade_registration.pory"
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
# 481 "data/scripts/battle_arcade_registration.pory"
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\l"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
# 486 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\l"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
# 491 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\l"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
# 496 "data/scripts/battle_arcade_registration.pory"
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
# 501 "data/scripts/battle_arcade_registration.pory"
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_WeHopeToSeeYou::
# 506 "data/scripts/battle_arcade_registration.pory"
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_ReadWhichRecord::
# 511 "data/scripts/battle_arcade_registration.pory"
	.string "Which record would you like to see?$"

BattleArcade_Entrance_Text_LinkMultisAreNot::
# 516 "data/scripts/battle_arcade_registration.pory"
	.string "I'm sorry! Link Multi Battles have not\n"
	.string "been implemented at this time. Please\l"
	.string "come back later.$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
# 523 "data/scripts/battle_arcade_registration.pory"
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\l"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
# 527 "data/scripts/battle_arcade_registration.pory"
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
# 531 "data/scripts/battle_arcade_registration.pory"
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"
