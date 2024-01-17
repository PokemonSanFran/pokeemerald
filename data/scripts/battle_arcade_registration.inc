BattleFrontier_BattleArcadeLobby_EventScript_PlayerFaceNorth::
# 19 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_1, 1
# 20 "data/scripts/battle_arcade_registration.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleFrontier_BattleArcadeLobby_EventScript_GetChallengeStatus::
# 26 "data/scripts/battle_arcade_registration.pory"
	frontier_getstatus
	end


BattleFrontier_BattleArcadeLobby_EventScript_QuitWithoutSaving::
# 32 "data/scripts/battle_arcade_registration.pory"
	lock
# 33 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 34 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDidnt, MSGBOX_DEFAULT
# 35 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 36 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK, 0
# 37 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
# 38 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 39 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 40 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge::
# 46 "data/scripts/battle_arcade_registration.pory"
	lock
# 47 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 49 "data/scripts/battle_arcade_registration.pory"
	frontier_isbrain
# 50 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge_1:
# 54 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_ResetChallengeStatus
# 55 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LookForwardToChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge_2:
# 52 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols
	goto BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge_1


BattleFrontier_BattleArcadeLobby_ResetChallengeStatus::
# 60 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
	return


BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols::
# 66 "data/scripts/battle_arcade_registration.pory"
	arcade_checksymbol
# 67 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 69 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_SILVER, BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_2
# 71 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_GOLD, BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_3
# 73 "data/scripts/battle_arcade_registration.pory"
	case ARCADE_SYMBOL_NONE, BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_4
BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_4:
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_2:
# 70 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GiveSilverPrint
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_3:
# 72 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GiveGoldPrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_GiveGoldPrint::
# 81 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 82 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheGoldPrintWasAdded, MSGBOX_DEFAULT
# 83 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GivePrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_GiveSilverPrint::
# 88 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 89 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheSilverPrintWasAdded, MSGBOX_DEFAULT
# 90 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GivePrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_CheckandGivePrint::
# 95 "data/scripts/battle_arcade_registration.pory"
	goto_if_set FLAG_ARCADE_SILVER_PRINT, BattleFrontier_BattleArcadeLobby_EventScript_CheckandGivePrint_1
# 101 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_SILVER_PRINT
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckandGivePrint_1:
# 97 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_ARCADE_GOLD_PRINT
	return


BattleFrontier_BattleArcadeLobby_EventScript_PlayFanfareMessage::
# 107 "data/scripts/battle_arcade_registration.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 108 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 109 "data/scripts/battle_arcade_registration.pory"
	waitfanfare
	return


BattleFrontier_BattleArcadeLobby_EventScript_GivePrint::
# 114 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_CheckandGivePrint
# 115 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_PlayFanfareMessage
	return


BattleFrontier_BattleArcadeLobby_EventScript_LookForwardToChallenge::
# 120 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 121 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 122 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge::
# 128 "data/scripts/battle_arcade_registration.pory"
	arcade_get ARCADE_DATA_WIN_STREAK
# 129 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_1:
# 133 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_ResetChallengeStatus
# 134 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LostThanksForPlaying
	return

BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_2:
# 131 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
	goto BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_LostThanksForPlaying::
# 139 "data/scripts/battle_arcade_registration.pory"
	lock
# 140 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 141 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 142 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 143 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 144 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle::
# 150 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_RecordWillBeSaved
# 151 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 152 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 153 "data/scripts/battle_arcade_registration.pory"
	arcade_save 0
# 154 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 155 "data/scripts/battle_arcade_registration.pory"
	waitse
# 157 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 158 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_2
# 163 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_RecordLastMatch, MSGBOX_YESNO
# 164 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_5
BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_4:
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_2:
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_5:
# 166 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_4


BattleFrontier_BattleArcadeLobby_EventScript_ResumeChallenge::
# 174 "data/scripts/battle_arcade_registration.pory"
	lock
# 175 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 177 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WeveMissedYou
# 178 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 180 "data/scripts/battle_arcade_registration.pory"
	arcade_save CHALLENGE_STATUS_SAVING
# 181 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 182 "data/scripts/battle_arcade_registration.pory"
	waitse
# 183 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 185 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator
	end


GiveMonDebugScript::
# 191 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_SALAMENCE, 50, ITEM_LEFTOVERS
# 192 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_METAGROSS, 50, ITEM_CHOICE_BAND
# 193 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_LATIOS, 50, ITEM_LUM_BERRY
	return


BattleFrontier_BattleArcadeLobby_EventScript_Attendant::
# 199 "data/scripts/battle_arcade_registration.pory"
	lock
# 200 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 201 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
# 203 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 204 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_Attendant_2
# 211 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti, MSGBOX_DEFAULT
BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1:
# 213 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_Attendant_2:
# 207 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1


BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge::
# 218 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichChallengeWouldYouLike
# 219 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 220 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_CHALLENGE_TYPES_INFO, FALSE
# 221 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 223 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 224 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 227 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3
# 229 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
# 230 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2:
# 225 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_FRONTIER_BATTLE_MODE, VAR_RESULT
# 226 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3:
# 228 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4:
# 231 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge::
# 237 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode
# 238 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 239 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 240 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 242 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3
# 243 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1:
# 245 "data/scripts/battle_arcade_registration.pory"
	frontier_checkineligible
# 246 "data/scripts/battle_arcade_registration.pory"
	compare VAR_0x8004, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5:
# 251 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 252 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_PleaseSelectThePokemonYou, MSGBOX_DEFAULT
# 254 "data/scripts/battle_arcade_registration.pory"
	fadescreen FADE_TO_BLACK
# 255 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 256 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 257 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 259 "data/scripts/battle_arcade_registration.pory"
	special ChoosePartyForBattleFrontier
# 260 "data/scripts/battle_arcade_registration.pory"
	waitstate
# 261 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8:
# 265 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3:
# 242 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4:
# 243 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6:
# 248 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 249 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9:
# 263 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8


BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge::
# 270 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 271 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 272 "data/scripts/battle_arcade_registration.pory"
	arcade_init
# 273 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, TRUE
# 274 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 275 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 276 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 277 "data/scripts/battle_arcade_registration.pory"
	delay 2
# 279 "data/scripts/battle_arcade_registration.pory"
	call Common_EventScript_SaveGame
# 280 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 282 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1:
# 288 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator
	return

BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2:
# 284 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 285 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge::
# 293 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_2
# 299 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_YouMayTeamUpWith, MSGBOX_DEFAULT
BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1:
# 301 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	end

BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_2:
# 295 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_SinglesAttendant::
# 307 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_SINGLES
# 308 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_MultisAttendant::
# 313 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_MULTIS
# 314 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard::
# 319 "data/scripts/battle_arcade_registration.pory"
	lockall
# 320 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_ReadWhichRecord
# 321 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 322 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RECORDS, FALSE
# 323 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 325 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2
# 326 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2
# 331 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2:
# 327 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 328 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleFrontier_BattleArcadeLobby_EventScript_ShowResults::
# 337 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 338 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8006, VAR_RESULT
# 339 "data/scripts/battle_arcade_registration.pory"
	arcade_results VAR_0x8006
# 340 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard
	return


BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons::
# 345 "data/scripts/battle_arcade_registration.pory"
	buffernumberstring STR_VAR_2, VAR_0x8005
# 346 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
# 348 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 349 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2
BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1:
# 353 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
# 354 "data/scripts/battle_arcade_registration.pory"
	closemessage
	end

BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2:
# 351 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1


BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge::
# 360 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 361 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge::
# 366 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 367 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator::
# 373 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 374 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 375 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 376 "data/scripts/battle_arcade_registration.pory"
	special CallFrontierUtilFunc
# 377 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, 0
# 378 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad
	return


BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad::
# 383 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom
# 384 "data/scripts/battle_arcade_registration.pory"
	special HealPlayerParty
# 385 "data/scripts/battle_arcade_registration.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 386 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WarpToHallway
# 387 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 388 "data/scripts/battle_arcade_registration.pory"
	waitstate
	end


BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom::
# 394 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
# 395 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WalkToElevator
	return


BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize::
# 401 "data/scripts/battle_arcade_registration.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 403 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3
# 404 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4
# 405 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5
BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1:
	return

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3:
# 403 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4:
# 404 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5:
# 405 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1


BattleFrontier_BattleArcadeLobby_EventScript_RulesBoard::
# 412 "data/scripts/battle_arcade_registration.pory"
	lockall
# 413 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 414 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard
	end


BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard::
# 420 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_ReadWhichHeading
# 421 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 422 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RULES, FALSE
# 423 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 425 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_3
# 427 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_4
# 429 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_5
# 431 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_6
# 433 "data/scripts/battle_arcade_registration.pory"
	case 4, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7
# 434 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7
BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1:
# 438 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_3:
# 426 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainArcadeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_4:
# 428 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_5:
# 430 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_6:
# 432 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7:
# 435 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleFrontier_BattleArcadeLobby_Text_DidntSaveBeforeQuitting::
# 442 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleArcadeLobby_Text_CongratsBeatenSeven::
# 447 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You've beaten all seven TRAINERS!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ReceivedPrize::
# 452 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_ThankYouForPlaying::
# 457 "data/scripts/battle_arcade_registration.pory"
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_RecordWillBeSaved::
# 462 "data/scripts/battle_arcade_registration.pory"
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_WeveBeenWaitingForYou::
# 467 "data/scripts/battle_arcade_registration.pory"
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ProgressWillBeSaved::
# 472 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_AboutToFace50thTrainer::
# 477 "data/scripts/battle_arcade_registration.pory"
	.string "You're finally about to face the\n"
	.string "50th TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleFrontier_BattleArcadeLobby_Text_HereAreSomeRibbons::
# 482 "data/scripts/battle_arcade_registration.pory"
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleArcadeLobby_Text_PutRibbonOnMons::
# 487 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} put the RIBBONS on\n"
	.string "the challenger POKéMON.$"

BattleFrontier_BattleArcadeLobby_Text_DescribeFeelingsAboutBattleArcade::
# 492 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE ARCADE\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouBegin::
# 497 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveWon::
# 502 "data/scripts/battle_arcade_registration.pory"
	.string "What do you feel when you've won\n"
	.string "a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveLost::
# 507 "data/scripts/battle_arcade_registration.pory"
	.string "Can I hear about your feelings when\n"
	.string "you have lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_DontThinkMuchAboutIt::
# 512 "data/scripts/battle_arcade_registration.pory"
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleFrontier_BattleArcadeLobby_Text_ChangedYourMind::
# 517 "data/scripts/battle_arcade_registration.pory"
	.string "Hunh? You changed your mind?\n"
	.string "I guess you're fickle.$"

BattleFrontier_BattleArcadeLobby_Text_ThatsHowYouFeel::
# 522 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, so that's how you feel?\n"
	.string "That's quite original.\p"
	.string "Thanks!$"

BattleFrontier_BattleArcadeLobby_Text_WinsInRowRecorded::
# 527 "data/scripts/battle_arcade_registration.pory"
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleArcadeLobby_Text_CanLeaveUntilLossOrSevenWins::
# 532 "data/scripts/battle_arcade_registration.pory"
	.string "Once you've entered the BATTLE ARCADE,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

BattleFrontier_BattleArcadeLobby_Text_LookForwardToAnotherChallenge::
# 537 "data/scripts/battle_arcade_registration.pory"
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode::
# 542 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ROOM offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleArcadeLobby_Text_OkayToSaveBeforeEntering::
# 547 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleArcadeLobby_Text_ShowYouToBattleRoom::
# 552 "data/scripts/battle_arcade_registration.pory"
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleArcadeLobby_Text_RecordLastMatch::
# 557 "data/scripts/battle_arcade_registration.pory"
	.string "Shall I record your last BATTLE ARCADE\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Singles::
# 562 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenSingles::
# 567 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Doubles::
# 572 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenDoubles::
# 577 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Multis::
# 582 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenMultis::
# 587 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomSingleBattle::
# 592 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the SINGLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeSinglesChallenge::
# 597 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainSinglesChallenge::
# 602 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE's SINGLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "SINGLE BATTLES with three POKéMON.\p"
	.string "There are many SINGLE BATTLE ROOMS\n"
	.string "in the BATTLE ARCADE for team battles.\p"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleArcadeLobby_Text_SelectThreeMons::
# 607 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeDoubleBattle::
# 612 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the DOUBLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeDoublesChallenge::
# 617 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainDoublesChallenge::
# 622 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE's DOUBLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "DOUBLE BATTLES with four POKéMON.\p"
	.string "There are many DOUBLE BATTLE ROOMS\n"
	.string "in the BATTLE ARCADE for team battles.\p"
	.string "In each of the DOUBLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleArcadeLobby_Text_PleaseSelectFourMons::
# 627 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeMultiBattle::
# 632 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeMultisChallenge::
# 637 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMultisChallenge::
# 642 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES.\p"
	.string "For MULTI BATTLES, you must partner\n"
	.string "with a TRAINER in the ARCADE and enter\l"
	.string "with two POKéMON each.\p"
	.string "Inside the ARCADE is a room named\n"
	.string "the BATTLE SALON where you may meet\l"
	.string "other TRAINERS.\p"
	.string "There, you must find a TRAINER to act\n"
	.string "as your partner in MULTI BATTLES.\p"
	.string "Once you have partnered up, you will\n"
	.string "be shown to a MULTI BATTLE ROOM.\p"
	.string "In the MULTI BATTLE ROOM, seven\n"
	.string "tag teams await your challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleArcadeLobby_Text_PleaseSelectTwoMons::
# 647 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeLinkMultiBattle::
# 652 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeLinkMultisChallenge::
# 657 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainLinkMultisChallenge::
# 662 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES with a friend.\p"
	.string "You must link with your friend using\n"
	.string "Wireless Adapters or a Game Boy\l"
	.string "Advance Game Link cable.\p"
	.string "You must partner with your friend and\n"
	.string "enter two different kinds of POKéMON.\p"
	.string "There are many MULTI BATTLE ROOMS\n"
	.string "in the BATTLE ARCADE for team battles.\p"
	.string "In a MULTI BATTLE ROOM, seven\n"
	.string "tag teams await you and your friend\l"
	.string "to make a tag-team challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "Please beware that unlike other ROOMS,\n"
	.string "you may not interrupt your challenge.\p"
	.string "Once you start, you must battle seven\n"
	.string "MULTI BATTLES in a row nonstop.$"

BattleFrontier_BattleArcadeLobby_Text_PleaseSelectTwoMons2::
# 667 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_LinkMultiOnlyForTwoPlayers::
# 672 "data/scripts/battle_arcade_registration.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMon::
# 677 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMons::
# 682 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendChoseDifferentLvlMode::
# 687 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

BattleFrontier_BattleArcadeLobby_Text_ChooseDifferentMonsMatchLvlMode::
# 692 "data/scripts/battle_arcade_registration.pory"
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleArcadeLobby_Text_SaveGameBeforeShowingIn::
# 697 "data/scripts/battle_arcade_registration.pory"
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_CongratsDefeatedMaiden::
# 702 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You have defeated the SALON MAIDEN\l"
	.string "and swept seven TRAINERS!$"

BattleFrontier_BattleArcadeLobby_Text_AwardYouTheseBattlePoints::
# 707 "data/scripts/battle_arcade_registration.pory"
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleArcadeLobby_Text_RulesAreListed::
# 712 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE rules are listed.$"

BattleFrontier_BattleArcadeLobby_Text_ReadWhichHeading::
# 717 "data/scripts/battle_arcade_registration.pory"
	.string "Which heading do you want to read?$"

BattleFrontier_BattleArcadeLobby_Text_ReadWhichRecord::
# 722 "data/scripts/battle_arcade_registration.pory"
	.string "Which record would you like to see?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainArcadeRules::
# 727 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
	.string "For each of these types, there are\n"
	.string "separate BATTLE ROOMS.\p"
	.string "Please speak with a guide offering\n"
	.string "the type of battle you wish to enter.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMonRules::
# 732 "data/scripts/battle_arcade_registration.pory"
	.string "Depending on the BATTLE ROOM you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of POKéMON.\p"
	.string "The SINGLE BATTLE mode requires\n"
	.string "three POKéMON.\p"
	.string "The DOUBLE BATTLE mode requires four,\n"
	.string "and the MULTI modes both require two.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainSalonRules::
# 737 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE SALON is where you must\n"
	.string "find a partner to form a tag team for\l"
	.string "the MULTI BATTLE ROOM challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other TRAINERS'\l"
	.string "POKéMON and their moves.\p"
	.string "You may choose a new tag partner\n"
	.string "after winning seven straight matches.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMultiLinkRules::
# 742 "data/scripts/battle_arcade_registration.pory"
	.string "The LINK MULTI BATTLE Mode is for two\n"
	.string "friends to mount a challenge together.\p"
	.string "You and your friend must be linked with\n"
	.string "Wireless Adapters or a GBA Game Link\l"
	.string "cable.\p"
	.string "You must choose two POKéMON at\n"
	.string "the registration counter.\p"
	.string "These POKéMON must be different\n"
	.string "from those of your friend.\p"
	.string "You may not interrupt this challenge\n"
	.string "in the middle, unlike other modes.$"

BattleArcade_Entrance_Text_RulesAreListed::
# 747 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE rules are listed.$"

BattleArcade_Entrance_Text_OverviewBoard::
# 752 "data/scripts/battle_arcade_registration.pory"
	.string "BATTLE ARCADE is challenges you to\n"
	.string "battle using up to three POKéMON of a\l"
	.string "single type. Select a level mode and a\l"
	.string "type, then battle your way through five\l"
	.string "consecutive battles.$"

BattleArcade_Entrance_Text_RestrictionsBoard::
# 757 "data/scripts/battle_arcade_registration.pory"
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\l"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

BattleArcade_Entrance_Text_RewardsBoard::
# 762 "data/scripts/battle_arcade_registration.pory"
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\l"
	.string "continue to increase your streak. You'll\l"
	.string "recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
# 767 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\l"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
# 772 "data/scripts/battle_arcade_registration.pory"
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
# 776 "data/scripts/battle_arcade_registration.pory"
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

BattleArcade_Entrance_Text_WhichLevelMode::
# 780 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
# 784 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\l"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
# 788 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_YouMayTeamUpWith::
# 792 "data/scripts/battle_arcade_registration.pory"
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

BattleArcade_Entrance_Text_WeHopeToSeeYou::
# 796 "data/scripts/battle_arcade_registration.pory"
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
# 800 "data/scripts/battle_arcade_registration.pory"
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
# 804 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\l"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
# 808 "data/scripts/battle_arcade_registration.pory"
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_AlsoEggsAreIneligible::
# 812 "data/scripts/battle_arcade_registration.pory"
	.string "Also, Eggs are ineligible to enter.$"

BattleArcade_Entrance_Text_EggsAndAre::
# 816 "data/scripts/battle_arcade_registration.pory"
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
# 820 "data/scripts/battle_arcade_registration.pory"
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
# 824 "data/scripts/battle_arcade_registration.pory"
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_WeveMissedYou::
# 828 "data/scripts/battle_arcade_registration.pory"
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\l"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
# 832 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\l"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_ThereWasAn::
# 837 "data/scripts/battle_arcade_registration.pory"
	.string "There was an error, and we couldn't\n"
	.string "save!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
# 842 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\l"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
# 846 "data/scripts/battle_arcade_registration.pory"
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
# 850 "data/scripts/battle_arcade_registration.pory"
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_SingleBattle::
# 854 "data/scripts/battle_arcade_registration.pory"
	.string "SINGLE BATTLE$"

BattleArcade_Entrance_Text_DoubleBattle::
# 858 "data/scripts/battle_arcade_registration.pory"
	.string "DOUBLE BATTLE$"

BattleArcade_Entrance_Text_TakeChallenge::
# 862 "data/scripts/battle_arcade_registration.pory"
	.string "TAKE CHALLENGE$"

BattleArcade_Entrance_Text_Info::
# 866 "data/scripts/battle_arcade_registration.pory"
	.string "INFO$"

BattleArcade_Entrance_Text_Cancel::
# 870 "data/scripts/battle_arcade_registration.pory"
	.string "CANCEL$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
# 874 "data/scripts/battle_arcade_registration.pory"
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\l"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
# 878 "data/scripts/battle_arcade_registration.pory"
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
# 882 "data/scripts/battle_arcade_registration.pory"
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"

BattleArcade_Entrance_Text_ThoseWhoRuleTheGame::
# 886 "data/scripts/battle_arcade_registration.pory"
	.string "Those who rule the game board reign at\n"
	.string "the Battle Arcade! It sounds sort of\l"
	.string "profound, but it's actually no-kidding\l"
	.string "obvious!$"

BattleArcade_Entrance_Text_ItAllComesDownTo::
# 890 "data/scripts/battle_arcade_registration.pory"
	.string "It all comes down to luck here… My cute\n"
	.string "Pokémon… They were helplessly frozen.$"

BattleArcade_Entrance_Text_TheresNothingYouCan::
# 894 "data/scripts/battle_arcade_registration.pory"
	.string "There's nothing you can do about luck.\n"
	.string "It's just there or not.$"

BattleArcade_Entrance_Text_DontBeAwestruckWatching::
# 898 "data/scripts/battle_arcade_registration.pory"
	.string "Don't be awestruck watching the motion\n"
	.string "of the game board. If you don't stop it\l"
	.string "in 30 seconds, it will stop by itself.$"

BattleArcade_Entrance_Text_TheBrainHasAPeculiar::
# 902 "data/scripts/battle_arcade_registration.pory"
	.string "The Brain has a peculiar fashion sense.\n"
	.string "She flits around oddly, too. Kind of like\l"
	.string "this. A little bump, a wiggle… …Please\l"
	.string "don't look at me that way. It's not nice.$"

BattleArcade_Entrance_Text_YikesTheyCanEven::
# 906 "data/scripts/battle_arcade_registration.pory"
	.string "Yikes, they can even start battles with\n"
	.string "the move Trick Room in effect? A\l"
	.string "strategy built around Speed could\l"
	.string "backfire right in your face!$"

BattleArcade_Entrance_Text_BeThrilledByTheUnknown::
# 910 "data/scripts/battle_arcade_registration.pory"
	.string "Be thrilled by the unknown hand of luck!\n"
	.string "Leap into battles ruled by fickle fate!\l"
	.string "That's how you enjoy the Battle Arcade!$"

BattleArcade_Entrance_Text_BlamingTheGameBoardFor::
# 914 "data/scripts/battle_arcade_registration.pory"
	.string "Blaming the game board for losing is\n"
	.string "pitiful. It's poor form. The game board\l"
	.string "will show better choices the greater\l"
	.string "the wins you achieve.$"

BattleArcade_Entrance_Text_DidYouFigureThisOne::
# 918 "data/scripts/battle_arcade_registration.pory"
	.string "Did you figure this one out? Poisoning\n"
	.string "or freezing events can be made\l"
	.string "ineffective. …If the Pokémon's type or\l"
	.string "ability protects it from such status\l"
	.string "problems.$"

BattleArcade_Entrance_Text_IfTheGameBoardTriggers::
# 922 "data/scripts/battle_arcade_registration.pory"
	.string "If the game board triggers a paralyzing\n"
	.string "event here, Ground types aren't\l"
	.string "affected.$"

BattleArcade_Entrance_Text_RecordLastMatch::
# 926 "data/scripts/battle_arcade_registration.pory"
	.string "Want me to record your last BATTLE\n"
	.string "ARCADE match on your FRONTIER PASS?$"
