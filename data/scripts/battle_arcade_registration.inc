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
# 194 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_NUZLEAF, 50, ITEM_STARF_BERRY
# 195 "data/scripts/battle_arcade_registration.pory"
	setflag FLAG_SYS_POKEMON_GET
	return


BattleFrontier_BattleArcadeLobby_EventScript_Attendant::
# 203 "data/scripts/battle_arcade_registration.pory"
	lock
# 204 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 205 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
# 207 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 208 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1
# 216 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti, MSGBOX_DEFAULT
# 217 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1:
# 211 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
# 212 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge::
# 223 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WouldYouLikeToTake
# 224 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 225 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 5, MULTI_CHALLENGEINFO, FALSE
# 226 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 228 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_2
# 231 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_3
# 233 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_4
# 234 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_4
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_2:
# 229 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 230 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_3:
# 232 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge_4:
# 235 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge::
# 241 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichChallengeWouldYouLike
# 242 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 243 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_CHALLENGE_TYPES_INFO, FALSE
# 244 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 246 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 247 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 250 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3
# 252 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
# 253 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2:
# 248 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_FRONTIER_BATTLE_MODE, VAR_RESULT
# 249 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3:
# 251 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4:
# 254 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge::
# 260 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode
# 261 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 262 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 263 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 265 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3
# 266 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1:
# 268 "data/scripts/battle_arcade_registration.pory"
	frontier_checkineligible
# 269 "data/scripts/battle_arcade_registration.pory"
	compare VAR_0x8004, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5:
# 274 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 275 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_PleaseSelectThePokemonYou, MSGBOX_DEFAULT
# 277 "data/scripts/battle_arcade_registration.pory"
	fadescreen FADE_TO_BLACK
# 278 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 279 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 280 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 282 "data/scripts/battle_arcade_registration.pory"
	special ChoosePartyForBattleFrontier
# 283 "data/scripts/battle_arcade_registration.pory"
	waitstate
# 284 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8:
# 288 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3:
# 265 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4:
# 266 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6:
# 271 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 272 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9:
# 286 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8


BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge::
# 293 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 294 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 295 "data/scripts/battle_arcade_registration.pory"
	arcade_init
# 296 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, TRUE
# 297 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 298 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 299 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 300 "data/scripts/battle_arcade_registration.pory"
	delay 2
# 302 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1:
# 308 "data/scripts/battle_arcade_registration.pory"
	call Common_EventScript_SaveGame
# 309 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 311 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_5
BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_4:
# 317 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer
# 318 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator
	return

BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2:
# 304 "data/scripts/battle_arcade_registration.pory"
	arcade_save 0
# 305 "data/scripts/battle_arcade_registration.pory"
	goto BattleArcade_Entrance_LinkMulti_EventScript_Cancel
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_5:
# 313 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 314 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_4


BattleArcade_Entrance_LinkMulti_EventScript_Cancel::
# 323 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_LinkMultisAreNot
# 324 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 325 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 326 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer::
# 331 "data/scripts/battle_arcade_registration.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_2
# 336 "data/scripts/battle_arcade_registration.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 337 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_5
BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_4:
# 341 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	return

BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_2:
	return

BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_5:
# 339 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleFrontier_BattleArcadeLobby_EventScript_HandleMultiplayer_4


BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge::
# 346 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1
# 353 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_YouMayTeamUpWith, MSGBOX_DEFAULT
# 354 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterMultiChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1:
# 348 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade, MSGBOX_DEFAULT
# 349 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_SinglesAttendant::
# 360 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_SINGLES
# 361 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_MultisAttendant::
# 366 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_MULTIS
# 367 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard::
# 372 "data/scripts/battle_arcade_registration.pory"
	lockall
# 373 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_ReadWhichRecord
# 374 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 375 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RECORDS, FALSE
# 376 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 378 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2
# 379 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2
# 384 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard_2:
# 380 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 381 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleFrontier_BattleArcadeLobby_EventScript_ShowResults::
# 390 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 391 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8006, VAR_RESULT
# 392 "data/scripts/battle_arcade_registration.pory"
	arcade_results VAR_0x8006
# 393 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskModeResultsBoard
	return


BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons::
# 398 "data/scripts/battle_arcade_registration.pory"
	buffernumberstring STR_VAR_2, VAR_0x8005
# 399 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
# 401 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 402 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2
BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1:
# 406 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
# 407 "data/scripts/battle_arcade_registration.pory"
	closemessage
	end

BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2:
# 404 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1


BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge::
# 413 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 414 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge::
# 419 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 420 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator::
# 426 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 427 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 428 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 429 "data/scripts/battle_arcade_registration.pory"
	special CallFrontierUtilFunc
# 430 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, 0
# 431 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad
	return


BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad::
# 436 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom
# 437 "data/scripts/battle_arcade_registration.pory"
	special HealPlayerParty
# 438 "data/scripts/battle_arcade_registration.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 439 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WarpToHallway
# 440 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 441 "data/scripts/battle_arcade_registration.pory"
	waitstate
	end


BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom::
# 447 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
# 448 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WalkToElevator
	return


BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize::
# 454 "data/scripts/battle_arcade_registration.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 456 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3
# 457 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4
# 458 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5
BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1:
	return

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3:
# 456 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4:
# 457 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5:
# 458 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1


BattleFrontier_BattleArcadeLobby_Text_DidntSaveBeforeQuitting::
# 463 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleArcadeLobby_Text_CongratsBeatenSeven::
# 468 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You've beaten all seven TRAINERS!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ReceivedPrize::
# 473 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_ThankYouForPlaying::
# 478 "data/scripts/battle_arcade_registration.pory"
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_RecordWillBeSaved::
# 483 "data/scripts/battle_arcade_registration.pory"
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_WeveBeenWaitingForYou::
# 488 "data/scripts/battle_arcade_registration.pory"
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ProgressWillBeSaved::
# 493 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_AboutToFace50thTrainer::
# 498 "data/scripts/battle_arcade_registration.pory"
	.string "You're finally about to face the\n"
	.string "50th TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleFrontier_BattleArcadeLobby_Text_HereAreSomeRibbons::
# 503 "data/scripts/battle_arcade_registration.pory"
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleArcadeLobby_Text_PutRibbonOnMons::
# 508 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} put the RIBBONS on\n"
	.string "the challenger POKéMON.$"

BattleFrontier_BattleArcadeLobby_Text_DescribeFeelingsAboutBattleArcade::
# 513 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE ARCADE\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouBegin::
# 518 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveWon::
# 523 "data/scripts/battle_arcade_registration.pory"
	.string "What do you feel when you've won\n"
	.string "a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveLost::
# 528 "data/scripts/battle_arcade_registration.pory"
	.string "Can I hear about your feelings when\n"
	.string "you have lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_DontThinkMuchAboutIt::
# 533 "data/scripts/battle_arcade_registration.pory"
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleFrontier_BattleArcadeLobby_Text_ChangedYourMind::
# 538 "data/scripts/battle_arcade_registration.pory"
	.string "Hunh? You changed your mind?\n"
	.string "I guess you're fickle.$"

BattleFrontier_BattleArcadeLobby_Text_ThatsHowYouFeel::
# 543 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, so that's how you feel?\n"
	.string "That's quite original.\p"
	.string "Thanks!$"

BattleFrontier_BattleArcadeLobby_Text_WinsInRowRecorded::
# 548 "data/scripts/battle_arcade_registration.pory"
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleArcadeLobby_Text_CanLeaveUntilLossOrSevenWins::
# 553 "data/scripts/battle_arcade_registration.pory"
	.string "Once you've entered the BATTLE ARCADE,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

BattleFrontier_BattleArcadeLobby_Text_LookForwardToAnotherChallenge::
# 558 "data/scripts/battle_arcade_registration.pory"
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode::
# 563 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ROOM offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleArcadeLobby_Text_OkayToSaveBeforeEntering::
# 568 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleArcadeLobby_Text_ShowYouToBattleRoom::
# 573 "data/scripts/battle_arcade_registration.pory"
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleArcadeLobby_Text_RecordLastMatch::
# 578 "data/scripts/battle_arcade_registration.pory"
	.string "Shall I record your last BATTLE ARCADE\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Singles::
# 583 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenSingles::
# 588 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Doubles::
# 593 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenDoubles::
# 598 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Multis::
# 603 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenMultis::
# 608 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomSingleBattle::
# 613 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the SINGLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeSinglesChallenge::
# 618 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainSinglesChallenge::
# 623 "data/scripts/battle_arcade_registration.pory"
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
# 628 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeDoubleBattle::
# 633 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the DOUBLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeDoublesChallenge::
# 638 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainDoublesChallenge::
# 643 "data/scripts/battle_arcade_registration.pory"
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
# 648 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeMultiBattle::
# 653 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeMultisChallenge::
# 658 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMultisChallenge::
# 663 "data/scripts/battle_arcade_registration.pory"
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
# 668 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeLinkMultiBattle::
# 673 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeLinkMultisChallenge::
# 678 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainLinkMultisChallenge::
# 683 "data/scripts/battle_arcade_registration.pory"
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
# 688 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_LinkMultiOnlyForTwoPlayers::
# 693 "data/scripts/battle_arcade_registration.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMon::
# 698 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMons::
# 703 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendChoseDifferentLvlMode::
# 708 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

BattleFrontier_BattleArcadeLobby_Text_ChooseDifferentMonsMatchLvlMode::
# 713 "data/scripts/battle_arcade_registration.pory"
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleArcadeLobby_Text_SaveGameBeforeShowingIn::
# 718 "data/scripts/battle_arcade_registration.pory"
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_CongratsDefeatedMaiden::
# 723 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You have defeated the SALON MAIDEN\l"
	.string "and swept seven TRAINERS!$"

BattleFrontier_BattleArcadeLobby_Text_AwardYouTheseBattlePoints::
# 728 "data/scripts/battle_arcade_registration.pory"
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleArcadeLobby_Text_ReadWhichRecord::
# 733 "data/scripts/battle_arcade_registration.pory"
	.string "Which record would you like to see?$"

BattleArcade_Entrance_Text_RulesAreListed::
# 738 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE rules are listed.$"

BattleArcade_Entrance_Text_OverviewBoard::
# 743 "data/scripts/battle_arcade_registration.pory"
	.string "BATTLE ARCADE is challenges you to\n"
	.string "battle using up to three POKéMON of a\l"
	.string "single type. Select a level mode and a\l"
	.string "type, then battle your way through five\l"
	.string "consecutive battles.$"

BattleArcade_Entrance_Text_RestrictionsBoard::
# 748 "data/scripts/battle_arcade_registration.pory"
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\l"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

BattleArcade_Entrance_Text_RewardsBoard::
# 753 "data/scripts/battle_arcade_registration.pory"
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\l"
	.string "continue to increase your streak. You'll\l"
	.string "recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
# 758 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\l"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
# 763 "data/scripts/battle_arcade_registration.pory"
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
# 767 "data/scripts/battle_arcade_registration.pory"
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
# 771 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
# 775 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\l"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
# 779 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_YouMayTeamUpWith::
# 783 "data/scripts/battle_arcade_registration.pory"
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
# 787 "data/scripts/battle_arcade_registration.pory"
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
# 791 "data/scripts/battle_arcade_registration.pory"
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
# 795 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\l"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
# 799 "data/scripts/battle_arcade_registration.pory"
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_AlsoEggsAreIneligible::
# 803 "data/scripts/battle_arcade_registration.pory"
	.string "Also, Eggs are ineligible to enter.$"

BattleArcade_Entrance_Text_EggsAndAre::
# 807 "data/scripts/battle_arcade_registration.pory"
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
# 811 "data/scripts/battle_arcade_registration.pory"
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
# 815 "data/scripts/battle_arcade_registration.pory"
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_WeveMissedYou::
# 819 "data/scripts/battle_arcade_registration.pory"
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\l"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
# 823 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\l"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_ThereWasAn::
# 828 "data/scripts/battle_arcade_registration.pory"
	.string "There was an error, and we couldn't\n"
	.string "save!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
# 833 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\l"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
# 837 "data/scripts/battle_arcade_registration.pory"
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
# 841 "data/scripts/battle_arcade_registration.pory"
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_SingleBattle::
# 845 "data/scripts/battle_arcade_registration.pory"
	.string "SINGLE BATTLE$"

BattleArcade_Entrance_Text_DoubleBattle::
# 849 "data/scripts/battle_arcade_registration.pory"
	.string "DOUBLE BATTLE$"

BattleArcade_Entrance_Text_TakeChallenge::
# 853 "data/scripts/battle_arcade_registration.pory"
	.string "TAKE CHALLENGE$"

BattleArcade_Entrance_Text_Info::
# 857 "data/scripts/battle_arcade_registration.pory"
	.string "INFO$"

BattleArcade_Entrance_Text_Cancel::
# 861 "data/scripts/battle_arcade_registration.pory"
	.string "CANCEL$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
# 865 "data/scripts/battle_arcade_registration.pory"
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\l"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
# 869 "data/scripts/battle_arcade_registration.pory"
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
# 873 "data/scripts/battle_arcade_registration.pory"
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"

BattleArcade_Entrance_Text_ThoseWhoRuleTheGame::
# 877 "data/scripts/battle_arcade_registration.pory"
	.string "Those who rule the game board reign at\n"
	.string "the Battle Arcade! It sounds sort of\l"
	.string "profound, but it's actually no-kidding\l"
	.string "obvious!$"

BattleArcade_Entrance_Text_ItAllComesDownTo::
# 881 "data/scripts/battle_arcade_registration.pory"
	.string "It all comes down to luck here… My cute\n"
	.string "Pokémon… They were helplessly frozen.$"

BattleArcade_Entrance_Text_TheresNothingYouCan::
# 885 "data/scripts/battle_arcade_registration.pory"
	.string "There's nothing you can do about luck.\n"
	.string "It's just there or not.$"

BattleArcade_Entrance_Text_DontBeAwestruckWatching::
# 889 "data/scripts/battle_arcade_registration.pory"
	.string "Don't be awestruck watching the motion\n"
	.string "of the game board. If you don't stop it\l"
	.string "in 30 seconds, it will stop by itself.$"

BattleArcade_Entrance_Text_TheBrainHasAPeculiar::
# 893 "data/scripts/battle_arcade_registration.pory"
	.string "The Brain has a peculiar fashion sense.\n"
	.string "She flits around oddly, too. Kind of like\l"
	.string "this. A little bump, a wiggle… …Please\l"
	.string "don't look at me that way. It's not nice.$"

BattleArcade_Entrance_Text_YikesTheyCanEven::
# 897 "data/scripts/battle_arcade_registration.pory"
	.string "Yikes, they can even start battles with\n"
	.string "the move Trick Room in effect? A\l"
	.string "strategy built around Speed could\l"
	.string "backfire right in your face!$"

BattleArcade_Entrance_Text_BeThrilledByTheUnknown::
# 901 "data/scripts/battle_arcade_registration.pory"
	.string "Be thrilled by the unknown hand of luck!\n"
	.string "Leap into battles ruled by fickle fate!\l"
	.string "That's how you enjoy the Battle Arcade!$"

BattleArcade_Entrance_Text_BlamingTheGameBoardFor::
# 905 "data/scripts/battle_arcade_registration.pory"
	.string "Blaming the game board for losing is\n"
	.string "pitiful. It's poor form. The game board\l"
	.string "will show better choices the greater\l"
	.string "the wins you achieve.$"

BattleArcade_Entrance_Text_DidYouFigureThisOne::
# 909 "data/scripts/battle_arcade_registration.pory"
	.string "Did you figure this one out? Poisoning\n"
	.string "or freezing events can be made\l"
	.string "ineffective. …If the Pokémon's type or\l"
	.string "ability protects it from such status\l"
	.string "problems.$"

BattleArcade_Entrance_Text_IfTheGameBoardTriggers::
# 913 "data/scripts/battle_arcade_registration.pory"
	.string "If the game board triggers a paralyzing\n"
	.string "event here, Ground types aren't\l"
	.string "affected.$"

BattleArcade_Entrance_Text_RecordLastMatch::
# 917 "data/scripts/battle_arcade_registration.pory"
	.string "Want me to record your last BATTLE\n"
	.string "ARCADE match on your FRONTIER PASS?$"

BattleArcade_Entrance_Text_LinkMultisAreNot::
# 921 "data/scripts/battle_arcade_registration.pory"
	.string "I'm sorry! Link Multi Battles have not\n"
	.string "been implemented at this time. Please\l"
	.string "come back later.$"
