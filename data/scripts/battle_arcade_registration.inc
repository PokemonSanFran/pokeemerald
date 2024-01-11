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
	frontier_getsymbols
# 67 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 69 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_2
# 70 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_3
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_2:
# 69 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GiveSilverPrint
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckStreakAndSymbols_3:
# 70 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_CheckGoldPrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_CheckGoldPrint::
# 77 "data/scripts/battle_arcade_registration.pory"
	arcade_get ARCADE_DATA_WIN_STREAK
# 78 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 49
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_CheckGoldPrint_1
	return

BattleFrontier_BattleArcadeLobby_EventScript_CheckGoldPrint_1:
# 80 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GiveGoldPrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_GiveGoldPrint::
# 86 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 87 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheGoldPrintWasAdded, MSGBOX_DEFAULT
# 88 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GivePrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_GiveSilverPrint::
# 94 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_CongratulationsInHonorOf, MSGBOX_DEFAULT
# 95 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_TheSilverPrintWasAdded, MSGBOX_DEFAULT
# 96 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GivePrint
	return


BattleFrontier_BattleArcadeLobby_EventScript_GivePrint::
# 102 "data/scripts/battle_arcade_registration.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 103 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 104 "data/scripts/battle_arcade_registration.pory"
	waitfanfare
	return


BattleFrontier_BattleArcadeLobby_EventScript_GiveBattlePoints::
# 110 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 111 "data/scripts/battle_arcade_registration.pory"
	arcade_givepoints
# 112 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	return


BattleFrontier_BattleArcadeLobby_EventScript_LookForwardToChallenge::
# 118 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 119 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 120 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge::
# 126 "data/scripts/battle_arcade_registration.pory"
	arcade_get ARCADE_DATA_WIN_STREAK
# 127 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_1:
# 131 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_ResetChallengeStatus
# 132 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LostThanksForPlaying
	return

BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_2:
# 129 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, FALSE
	goto BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_LostThanksForPlaying::
# 137 "data/scripts/battle_arcade_registration.pory"
	lock
# 138 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 139 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 140 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 141 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 142 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle::
# 148 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_RecordWillBeSaved
# 149 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 150 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 151 "data/scripts/battle_arcade_registration.pory"
	arcade_save 0
# 152 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 153 "data/scripts/battle_arcade_registration.pory"
	waitse
# 155 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 156 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_2
# 161 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_RecordLastMatch, MSGBOX_YESNO
# 162 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_5
BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_4:
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_2:
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_5:
# 164 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskSaveBattle_4


BattleFrontier_BattleArcadeLobby_EventScript_ResumeChallenge::
# 172 "data/scripts/battle_arcade_registration.pory"
	lock
# 173 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 175 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WeveMissedYou
# 176 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 178 "data/scripts/battle_arcade_registration.pory"
	arcade_save CHALLENGE_STATUS_SAVING
# 179 "data/scripts/battle_arcade_registration.pory"
	playse SE_SAVE
# 180 "data/scripts/battle_arcade_registration.pory"
	waitse
# 181 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 183 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator
	end


GiveMonDebugScript::
# 189 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_SALAMENCE, 50, ITEM_LEFTOVERS
# 190 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_METAGROSS, 50, ITEM_CHOICE_BAND
# 191 "data/scripts/battle_arcade_registration.pory"
	givemon SPECIES_LATIOS, 50, ITEM_LUM_BERRY
	return


BattleFrontier_BattleArcadeLobby_EventScript_Attendant::
# 197 "data/scripts/battle_arcade_registration.pory"
	lock
# 198 "data/scripts/battle_arcade_registration.pory"
	faceplayer
# 199 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARCADE
# 201 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 202 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_Attendant_2
# 210 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti, MSGBOX_DEFAULT
BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1:
# 212 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_Attendant_2:
# 206 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WelcomeToTheBattleArcade
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant_1


BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge::
# 217 "data/scripts/battle_arcade_registration.pory"
	message BattleArcade_Entrance_Text_WhichChallengeWouldYouLike
# 218 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 219 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_CHALLENGE_TYPES_INFO, FALSE
# 220 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 222 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 223 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2
# 226 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3
# 228 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
# 229 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_2:
# 224 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_FRONTIER_BATTLE_MODE, VAR_RESULT
# 225 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_3:
# 227 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge_4:
# 230 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge::
# 236 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode
# 237 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 238 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 239 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 241 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3
# 242 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1:
# 244 "data/scripts/battle_arcade_registration.pory"
	frontier_checkineligible
# 245 "data/scripts/battle_arcade_registration.pory"
	compare VAR_0x8004, 0
	goto_if_ne BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5:
# 250 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 251 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_PleaseSelectThePokemonYou, MSGBOX_DEFAULT
# 253 "data/scripts/battle_arcade_registration.pory"
	fadescreen FADE_TO_BLACK
# 254 "data/scripts/battle_arcade_registration.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 255 "data/scripts/battle_arcade_registration.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 256 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 258 "data/scripts/battle_arcade_registration.pory"
	special ChoosePartyForBattleFrontier
# 259 "data/scripts/battle_arcade_registration.pory"
	waitstate
# 260 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9
BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8:
# 264 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge
	return

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_3:
# 241 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_4:
# 242 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_6:
# 247 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 248 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_5

BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_9:
# 262 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_TryEnterChallenge_8


BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge::
# 269 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 270 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 271 "data/scripts/battle_arcade_registration.pory"
	arcade_init
# 272 "data/scripts/battle_arcade_registration.pory"
	arcade_set ARCADE_DATA_WIN_STREAK_ACTIVE, TRUE
# 273 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 274 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 275 "data/scripts/battle_arcade_registration.pory"
	closemessage
# 276 "data/scripts/battle_arcade_registration.pory"
	delay 2
# 278 "data/scripts/battle_arcade_registration.pory"
	call Common_EventScript_SaveGame
# 279 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 255
# 281 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2
BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1:
# 287 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator
	return

BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_2:
# 283 "data/scripts/battle_arcade_registration.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 284 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleArcadeLobby_EventScript_SaveBeforeChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge::
# 292 "data/scripts/battle_arcade_registration.pory"
	compare VAR_TEMP_2, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_2
# 298 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_YouMayTeamUpWith, MSGBOX_DEFAULT
BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1:
# 300 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_AskEnterChallenge
	end

BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_2:
# 294 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_AtTheBattleArcade, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ExplainChallenge_1


BattleFrontier_BattleArcadeLobby_EventScript_SinglesAttendant::
# 306 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_SINGLES
# 307 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_MultisAttendant::
# 312 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_2, FRONTIER_MODE_MULTIS
# 313 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_Attendant
	return


BattleFrontier_BattleArcadeLobby_EventScript_ShowResults::
# 318 "data/scripts/battle_arcade_registration.pory"
	lockall
# 319 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 321 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_3
# 322 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_4
# 323 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_5
# 324 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_6
BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_1:
# 326 "data/scripts/battle_arcade_registration.pory"
	waitbuttonpress
# 327 "data/scripts/battle_arcade_registration.pory"
	special RemoveRecordsWindow
# 328 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end

BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_3:
# 321 "data/scripts/battle_arcade_registration.pory"
	frontier_results FRONTIER_FACILITY_ARCADE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_1

BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_4:
# 322 "data/scripts/battle_arcade_registration.pory"
	frontier_results FRONTIER_FACILITY_ARCADE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_1

BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_5:
# 323 "data/scripts/battle_arcade_registration.pory"
	frontier_results FRONTIER_FACILITY_ARCADE, FRONTIER_MODE_MULTIS
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_1

BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_6:
# 324 "data/scripts/battle_arcade_registration.pory"
	frontier_results FRONTIER_FACILITY_ARCADE, FRONTIER_MODE_LINK_MULTIS
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults_1


BattleFrontier_BattleArcadeLobby_EventScript_ShowSinglesResults::
# 334 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_SINGLES
# 335 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return


BattleFrontier_BattleArcadeLobby_EventScript_ShowDoublesResults::
# 340 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_DOUBLES
# 341 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return


BattleFrontier_BattleArcadeLobby_EventScript_ShowMultisResults::
# 346 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_MULTIS
# 347 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return


BattleFrontier_BattleArcadeLobby_EventScript_ShowLinkMultisResults::
# 352 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
# 353 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ShowResults
	return


BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons::
# 358 "data/scripts/battle_arcade_registration.pory"
	buffernumberstring STR_VAR_2, VAR_0x8005
# 359 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_ExcuseMeYouDont, MSGBOX_DEFAULT
# 361 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 362 "data/scripts/battle_arcade_registration.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2
BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1:
# 366 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_EggsAndAre, MSGBOX_DEFAULT
# 367 "data/scripts/battle_arcade_registration.pory"
	closemessage
	end

BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_2:
# 364 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_UnderLevel50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_NotEnoughValidMons_1


BattleFrontier_BattleArcadeLobby_EventScript_LoadPartyCancelChallenge::
# 373 "data/scripts/battle_arcade_registration.pory"
	special LoadPlayerParty
# 374 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleArcadeLobby_EventScript_CancelChallenge::
# 379 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_WeHopeToSeeYou, MSGBOX_DEFAULT
# 380 "data/scripts/battle_arcade_registration.pory"
	release
	end


BattleFrontier_BattleArcadeLobby_EventScript_EnterElevator::
# 386 "data/scripts/battle_arcade_registration.pory"
	special SavePlayerParty
# 387 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 388 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize
# 389 "data/scripts/battle_arcade_registration.pory"
	special CallFrontierUtilFunc
# 390 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_RESULT, 0
# 391 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad
	return


BattleFrontier_BattleArcadeLobby_EventScript_WaitForLinkOpponentLoad::
# 396 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom
# 397 "data/scripts/battle_arcade_registration.pory"
	special HealPlayerParty
# 398 "data/scripts/battle_arcade_registration.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 399 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WarpToHallway
# 400 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_TEMP_0, 0
# 401 "data/scripts/battle_arcade_registration.pory"
	waitstate
	end


BattleFrontier_BattleArcadeLobby_EventScript_ShowYouToBattleRoom::
# 407 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleArcade_Entrance_Text_RightThisWayPlease, MSGBOX_DEFAULT
# 408 "data/scripts/battle_arcade_registration.pory"
	call BattleFrontier_BattleArcadeLobby_EventScript_WalkToElevator
	return


BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize::
# 414 "data/scripts/battle_arcade_registration.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 416 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3
# 417 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4
# 418 "data/scripts/battle_arcade_registration.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5
BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1:
	return

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_3:
# 416 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_4:
# 417 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1

BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_5:
# 418 "data/scripts/battle_arcade_registration.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleArcadeLobby_EventScript_GetPartySize_1


BattleFrontier_BattleArcadeLobby_EventScript_RulesBoard::
# 425 "data/scripts/battle_arcade_registration.pory"
	lockall
# 426 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 427 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard
	end


BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard::
# 433 "data/scripts/battle_arcade_registration.pory"
	message BattleFrontier_BattleArcadeLobby_Text_ReadWhichHeading
# 434 "data/scripts/battle_arcade_registration.pory"
	waitmessage
# 435 "data/scripts/battle_arcade_registration.pory"
	multichoice 17, 2, MULTI_BATTLE_ARCADE_RULES, FALSE
# 436 "data/scripts/battle_arcade_registration.pory"
	switch VAR_RESULT
# 438 "data/scripts/battle_arcade_registration.pory"
	case 0, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_3
# 440 "data/scripts/battle_arcade_registration.pory"
	case 1, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_4
# 442 "data/scripts/battle_arcade_registration.pory"
	case 2, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_5
# 444 "data/scripts/battle_arcade_registration.pory"
	case 3, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_6
# 446 "data/scripts/battle_arcade_registration.pory"
	case 4, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7
# 447 "data/scripts/battle_arcade_registration.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7
BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1:
# 451 "data/scripts/battle_arcade_registration.pory"
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_3:
# 439 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainArcadeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_4:
# 441 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_5:
# 443 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_6:
# 445 "data/scripts/battle_arcade_registration.pory"
	msgbox BattleFrontier_BattleArcadeLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleArcadeLobby_EventScript_ReadRulesBoard_7:
# 448 "data/scripts/battle_arcade_registration.pory"
	releaseall
	end


BattleFrontier_BattleArcadeLobby_Text_DidntSaveBeforeQuitting::
# 455 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleArcadeLobby_Text_CongratsBeatenSeven::
# 460 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You've beaten all seven TRAINERS!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ReceivedPrize::
# 465 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_ThankYouForPlaying::
# 470 "data/scripts/battle_arcade_registration.pory"
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_RecordWillBeSaved::
# 475 "data/scripts/battle_arcade_registration.pory"
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_WeveBeenWaitingForYou::
# 480 "data/scripts/battle_arcade_registration.pory"
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleArcadeLobby_Text_ProgressWillBeSaved::
# 485 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_AboutToFace50thTrainer::
# 490 "data/scripts/battle_arcade_registration.pory"
	.string "You're finally about to face the\n"
	.string "50th TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleFrontier_BattleArcadeLobby_Text_HereAreSomeRibbons::
# 495 "data/scripts/battle_arcade_registration.pory"
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleArcadeLobby_Text_PutRibbonOnMons::
# 500 "data/scripts/battle_arcade_registration.pory"
	.string "{PLAYER} put the RIBBONS on\n"
	.string "the challenger POKéMON.$"

BattleFrontier_BattleArcadeLobby_Text_DescribeFeelingsAboutBattleArcade::
# 505 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE ARCADE\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouBegin::
# 510 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveWon::
# 515 "data/scripts/battle_arcade_registration.pory"
	.string "What do you feel when you've won\n"
	.string "a match?$"

BattleFrontier_BattleArcadeLobby_Text_FeelWhatWhenYouveLost::
# 520 "data/scripts/battle_arcade_registration.pory"
	.string "Can I hear about your feelings when\n"
	.string "you have lost a match?$"

BattleFrontier_BattleArcadeLobby_Text_DontThinkMuchAboutIt::
# 525 "data/scripts/battle_arcade_registration.pory"
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleFrontier_BattleArcadeLobby_Text_ChangedYourMind::
# 530 "data/scripts/battle_arcade_registration.pory"
	.string "Hunh? You changed your mind?\n"
	.string "I guess you're fickle.$"

BattleFrontier_BattleArcadeLobby_Text_ThatsHowYouFeel::
# 535 "data/scripts/battle_arcade_registration.pory"
	.string "Okay, so that's how you feel?\n"
	.string "That's quite original.\p"
	.string "Thanks!$"

BattleFrontier_BattleArcadeLobby_Text_WinsInRowRecorded::
# 540 "data/scripts/battle_arcade_registration.pory"
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleArcadeLobby_Text_CanLeaveUntilLossOrSevenWins::
# 545 "data/scripts/battle_arcade_registration.pory"
	.string "Once you've entered the BATTLE ARCADE,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

BattleFrontier_BattleArcadeLobby_Text_LookForwardToAnotherChallenge::
# 550 "data/scripts/battle_arcade_registration.pory"
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleArcadeLobby_Text_WhichLevelMode::
# 555 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ROOM offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleArcadeLobby_Text_OkayToSaveBeforeEntering::
# 560 "data/scripts/battle_arcade_registration.pory"
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleArcadeLobby_Text_ShowYouToBattleRoom::
# 565 "data/scripts/battle_arcade_registration.pory"
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleArcadeLobby_Text_RecordLastMatch::
# 570 "data/scripts/battle_arcade_registration.pory"
	.string "Shall I record your last BATTLE ARCADE\n"
	.string "match on your FRONTIER PASS?$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Singles::
# 575 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenSingles::
# 580 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Doubles::
# 585 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenDoubles::
# 590 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLv50Multis::
# 595 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_NotEnoughValidMonsLvOpenMultis::
# 600 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomSingleBattle::
# 605 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the SINGLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeSinglesChallenge::
# 610 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainSinglesChallenge::
# 615 "data/scripts/battle_arcade_registration.pory"
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
# 620 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeDoubleBattle::
# 625 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the DOUBLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeDoublesChallenge::
# 630 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainDoublesChallenge::
# 635 "data/scripts/battle_arcade_registration.pory"
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
# 640 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeMultiBattle::
# 645 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeMultisChallenge::
# 650 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMultisChallenge::
# 655 "data/scripts/battle_arcade_registration.pory"
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
# 660 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_WelcomeLinkMultiBattle::
# 665 "data/scripts/battle_arcade_registration.pory"
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE ARCADE!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleArcadeLobby_Text_TakeLinkMultisChallenge::
# 670 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainLinkMultisChallenge::
# 675 "data/scripts/battle_arcade_registration.pory"
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
# 680 "data/scripts/battle_arcade_registration.pory"
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleArcadeLobby_Text_LinkMultiOnlyForTwoPlayers::
# 685 "data/scripts/battle_arcade_registration.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMon::
# 690 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendAlsoSelectedMons::
# 695 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleArcadeLobby_Text_FriendChoseDifferentLvlMode::
# 700 "data/scripts/battle_arcade_registration.pory"
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

BattleFrontier_BattleArcadeLobby_Text_ChooseDifferentMonsMatchLvlMode::
# 705 "data/scripts/battle_arcade_registration.pory"
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleArcadeLobby_Text_SaveGameBeforeShowingIn::
# 710 "data/scripts/battle_arcade_registration.pory"
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleArcadeLobby_Text_CongratsDefeatedMaiden::
# 715 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations!\n"
	.string "You have defeated the SALON MAIDEN\l"
	.string "and swept seven TRAINERS!$"

BattleFrontier_BattleArcadeLobby_Text_AwardYouTheseBattlePoints::
# 720 "data/scripts/battle_arcade_registration.pory"
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleArcadeLobby_Text_RulesAreListed::
# 725 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE rules are listed.$"

BattleFrontier_BattleArcadeLobby_Text_ReadWhichHeading::
# 730 "data/scripts/battle_arcade_registration.pory"
	.string "Which heading do you want to read?$"

BattleFrontier_BattleArcadeLobby_Text_ExplainArcadeRules::
# 735 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
	.string "For each of these types, there are\n"
	.string "separate BATTLE ROOMS.\p"
	.string "Please speak with a guide offering\n"
	.string "the type of battle you wish to enter.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMonRules::
# 740 "data/scripts/battle_arcade_registration.pory"
	.string "Depending on the BATTLE ROOM you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of POKéMON.\p"
	.string "The SINGLE BATTLE mode requires\n"
	.string "three POKéMON.\p"
	.string "The DOUBLE BATTLE mode requires four,\n"
	.string "and the MULTI modes both require two.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainSalonRules::
# 745 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE SALON is where you must\n"
	.string "find a partner to form a tag team for\l"
	.string "the MULTI BATTLE ROOM challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other TRAINERS'\l"
	.string "POKéMON and their moves.\p"
	.string "You may choose a new tag partner\n"
	.string "after winning seven straight matches.$"

BattleFrontier_BattleArcadeLobby_Text_ExplainMultiLinkRules::
# 750 "data/scripts/battle_arcade_registration.pory"
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
# 755 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE rules are listed.$"

BattleArcade_Entrance_Text_OverviewBoard::
# 760 "data/scripts/battle_arcade_registration.pory"
	.string "BATTLE ARCADE is challenges you to\n"
	.string "battle using up to three POKéMON of a\l"
	.string "single type. Select a level mode and a\l"
	.string "type, then battle your way through five\l"
	.string "consecutive battles.$"

BattleArcade_Entrance_Text_RestrictionsBoard::
# 765 "data/scripts/battle_arcade_registration.pory"
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\l"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

BattleArcade_Entrance_Text_RewardsBoard::
# 770 "data/scripts/battle_arcade_registration.pory"
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\l"
	.string "continue to increase your streak. You'll\l"
	.string "recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcade::
# 775 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Single and Double Battle\l"
	.string "challenges. Please be aware that these\l"
	.string "challenges are designed for a single\l"
	.string "Trainer.$"

BattleArcade_Entrance_Text_WhichChallengeWouldYouLike::
# 780 "data/scripts/battle_arcade_registration.pory"
	.string "Which challenge would you like to take?$"

BattleArcade_Entrance_Text_AtTheBattleArcade::
# 784 "data/scripts/battle_arcade_registration.pory"
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
# 788 "data/scripts/battle_arcade_registration.pory"
	.string "The BATTLE ARCADE offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleArcade_Entrance_Text_WelcomeToTheBattleArcadeMulti::
# 792 "data/scripts/battle_arcade_registration.pory"
	.string "Welcome to the Battle Arcade! I am your\n"
	.string "guide to the Multi Battle challenge.\l"
	.string "Please be aware that this challenge\l"
	.string "requires two Trainers.$"

BattleArcade_Entrance_Text_WouldYouLikeToTake::
# 796 "data/scripts/battle_arcade_registration.pory"
	.string "Would you like to take the Battle\n"
	.string "Arcade Multi Battle challenge?$"

BattleArcade_Entrance_Text_YouMayTeamUpWith::
# 800 "data/scripts/battle_arcade_registration.pory"
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
# 804 "data/scripts/battle_arcade_registration.pory"
	.string "We hope to see you again!$"

BattleArcade_Entrance_Text_PleaseSelectThePokemonYou::
# 808 "data/scripts/battle_arcade_registration.pory"
	.string "Please select the Pokémon you wish to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_ExcuseMeYouDont::
# 812 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You don't have\n"
	.string "{STR_VAR_2} eligible Pokémon. You\l"
	.string "must have {STR_VAR_2} different\l"
	.string "Pokémon to enter.$"

BattleArcade_Entrance_Text_UnderLevel50::
# 816 "data/scripts/battle_arcade_registration.pory"
	.string "The {STR_VAR_2} different Pokémon\n"
	.string "must all be Level 50 or lower.$"

BattleArcade_Entrance_Text_AlsoEggsAreIneligible::
# 820 "data/scripts/battle_arcade_registration.pory"
	.string "Also, Eggs are ineligible to enter.$"

BattleArcade_Entrance_Text_EggsAndAre::
# 824 "data/scripts/battle_arcade_registration.pory"
	.string "Eggs{STR_VAR_1} are not allowed to\n"
	.string "enter.$"

BattleArcade_Entrance_Text_PleaseComeSeeMeWhen::
# 828 "data/scripts/battle_arcade_registration.pory"
	.string "Please come see me when you are ready.$"

BattleArcade_Entrance_Text_RightThisWayPlease::
# 832 "data/scripts/battle_arcade_registration.pory"
	.string "Right this way, please!$"

BattleArcade_Entrance_Text_WeveMissedYou::
# 836 "data/scripts/battle_arcade_registration.pory"
	.string "We've missed you! You must save the\n"
	.string "game before you resume your challenge.\l"
	.string "Please wait.$"

BattleArcade_Entrance_Text_ExcuseMeYouDidnt::
# 840 "data/scripts/battle_arcade_registration.pory"
	.string "Excuse me! You didn't save before you\n"
	.string "quit your challenge last time. Because\l"
	.string "of that, you have been disqualified\l"
	.string "from your challenge!$"

BattleArcade_Entrance_Text_ThereWasAn::
# 845 "data/scripts/battle_arcade_registration.pory"
	.string "There was an error, and we couldn't\n"
	.string "save!$"

BattleArcade_Entrance_Text_CongratulationsInHonorOf::
# 850 "data/scripts/battle_arcade_registration.pory"
	.string "Congratulations! In honor of your\n"
	.string "victory, we present you with this\l"
	.string "commemorative print!$"

BattleArcade_Entrance_Text_TheGoldPrintWasAdded::
# 854 "data/scripts/battle_arcade_registration.pory"
	.string "The Gold Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_TheSilverPrintWasAdded::
# 858 "data/scripts/battle_arcade_registration.pory"
	.string "The Silver Print was added to\n"
	.string "{PLAYER}'s Vs. Recorder!$"

BattleArcade_Entrance_Text_SingleBattle::
# 862 "data/scripts/battle_arcade_registration.pory"
	.string "SINGLE BATTLE$"

BattleArcade_Entrance_Text_DoubleBattle::
# 866 "data/scripts/battle_arcade_registration.pory"
	.string "DOUBLE BATTLE$"

BattleArcade_Entrance_Text_TakeChallenge::
# 870 "data/scripts/battle_arcade_registration.pory"
	.string "TAKE CHALLENGE$"

BattleArcade_Entrance_Text_Info::
# 874 "data/scripts/battle_arcade_registration.pory"
	.string "INFO$"

BattleArcade_Entrance_Text_Cancel::
# 878 "data/scripts/battle_arcade_registration.pory"
	.string "CANCEL$"

BattleArcade_Entrance_Text_OneTrainerShouldSelectBecome::
# 882 "data/scripts/battle_arcade_registration.pory"
	.string "One Trainer should select “BECOME\n"
	.string "LEADER.” The other Trainer must select\l"
	.string "“JOIN GROUP.”$"

BattleArcade_Entrance_Text_WeNeedToLaunchDs::
# 886 "data/scripts/battle_arcade_registration.pory"
	.string "We need to launch DS Wireless\n"
	.string "Communications.$"

BattleArcade_Entrance_Text_YouMustSaveTheGame::
# 890 "data/scripts/battle_arcade_registration.pory"
	.string "You must save the game before I show\n"
	.string "you in. Please wait.$"

BattleArcade_Entrance_Text_ThoseWhoRuleTheGame::
# 894 "data/scripts/battle_arcade_registration.pory"
	.string "Those who rule the game board reign at\n"
	.string "the Battle Arcade! It sounds sort of\l"
	.string "profound, but it's actually no-kidding\l"
	.string "obvious!$"

BattleArcade_Entrance_Text_ItAllComesDownTo::
# 898 "data/scripts/battle_arcade_registration.pory"
	.string "It all comes down to luck here… My cute\n"
	.string "Pokémon… They were helplessly frozen.$"

BattleArcade_Entrance_Text_TheresNothingYouCan::
# 902 "data/scripts/battle_arcade_registration.pory"
	.string "There's nothing you can do about luck.\n"
	.string "It's just there or not.$"

BattleArcade_Entrance_Text_DontBeAwestruckWatching::
# 906 "data/scripts/battle_arcade_registration.pory"
	.string "Don't be awestruck watching the motion\n"
	.string "of the game board. If you don't stop it\l"
	.string "in 30 seconds, it will stop by itself.$"

BattleArcade_Entrance_Text_TheBrainHasAPeculiar::
# 910 "data/scripts/battle_arcade_registration.pory"
	.string "The Brain has a peculiar fashion sense.\n"
	.string "She flits around oddly, too. Kind of like\l"
	.string "this. A little bump, a wiggle… …Please\l"
	.string "don't look at me that way. It's not nice.$"

BattleArcade_Entrance_Text_YikesTheyCanEven::
# 914 "data/scripts/battle_arcade_registration.pory"
	.string "Yikes, they can even start battles with\n"
	.string "the move Trick Room in effect? A\l"
	.string "strategy built around Speed could\l"
	.string "backfire right in your face!$"

BattleArcade_Entrance_Text_BeThrilledByTheUnknown::
# 918 "data/scripts/battle_arcade_registration.pory"
	.string "Be thrilled by the unknown hand of luck!\n"
	.string "Leap into battles ruled by fickle fate!\l"
	.string "That's how you enjoy the Battle Arcade!$"

BattleArcade_Entrance_Text_BlamingTheGameBoardFor::
# 922 "data/scripts/battle_arcade_registration.pory"
	.string "Blaming the game board for losing is\n"
	.string "pitiful. It's poor form. The game board\l"
	.string "will show better choices the greater\l"
	.string "the wins you achieve.$"

BattleArcade_Entrance_Text_DidYouFigureThisOne::
# 926 "data/scripts/battle_arcade_registration.pory"
	.string "Did you figure this one out? Poisoning\n"
	.string "or freezing events can be made\l"
	.string "ineffective. …If the Pokémon's type or\l"
	.string "ability protects it from such status\l"
	.string "problems.$"

BattleArcade_Entrance_Text_IfTheGameBoardTriggers::
# 930 "data/scripts/battle_arcade_registration.pory"
	.string "If the game board triggers a paralyzing\n"
	.string "event here, Ground types aren't\l"
	.string "affected.$"

BattleArcade_Entrance_Text_RecordLastMatch::
# 934 "data/scripts/battle_arcade_registration.pory"
	.string "Want me to record your last BATTLE\n"
	.string "ARCADE match on your FRONTIER PASS?$"
