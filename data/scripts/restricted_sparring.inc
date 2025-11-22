RestrictedSparring_Entrance_EventScript_GetChallengeStatus::
# 12 "data/scripts/restricted_sparring.pory"
	frontier_getstatus
	end


RestrictedSparring_Entrance_EventScript_QuitWithoutSaving::
# 18 "data/scripts/restricted_sparring.pory"
	lock
# 19 "data/scripts/restricted_sparring.pory"
	faceplayer
# 20 "data/scripts/restricted_sparring.pory"
	delay 30
# 21 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 22 "data/scripts/restricted_sparring.pory"
	sparring_set SPARRING_DATA_WIN_STREAK, 0
# 23 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 24 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_0, 255
# 25 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_SetChallengeStatusEnd
	return


RestrictedSparring_Entrance_EventScript_AskEnterChallenge::
# 30 "data/scripts/restricted_sparring.pory"
	lock
# 31 "data/scripts/restricted_sparring.pory"
	faceplayer
# 32 "data/scripts/restricted_sparring.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_SPARRING
# 33 "data/scripts/restricted_sparring.pory"
	special SavePlayerParty
# 34 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_HiyahDo
# 35 "data/scripts/restricted_sparring.pory"
	waitmessage
# 37 "data/scripts/restricted_sparring.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 38 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 40 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_Entrance_EventScript_AskEnterChallenge_2
# 41 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_Entrance_EventScript_AskEnterChallenge_3
# 42 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_Entrance_EventScript_AskEnterChallenge_4
# 43 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_Entrance_EventScript_AskEnterChallenge_4
	return

RestrictedSparring_Entrance_EventScript_AskEnterChallenge_2:
# 40 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_TryEnterChallenge
	return

RestrictedSparring_Entrance_EventScript_AskEnterChallenge_3:
# 41 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_ExplainChallenge
	return

RestrictedSparring_Entrance_EventScript_AskEnterChallenge_4:
# 43 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_DenyChallenge
	return


RestrictedSparring_Entrance_EventScript_TryEnterChallenge::
# 49 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_OffersTwoLevels
# 50 "data/scripts/restricted_sparring.pory"
	waitmessage
# 52 "data/scripts/restricted_sparring.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 53 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 55 "data/scripts/restricted_sparring.pory"
	case FRONTIER_LVL_TENT, RestrictedSparring_Entrance_EventScript_TryEnterChallenge_3
# 56 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_Entrance_EventScript_TryEnterChallenge_3
RestrictedSparring_Entrance_EventScript_TryEnterChallenge_1:
# 59 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_SelectTheTypeYouWant
# 60 "data/scripts/restricted_sparring.pory"
	waitmessage
# 61 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 62 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_CreateTypeList
# 63 "data/scripts/restricted_sparring.pory"
	frontier_checkineligible
# 64 "data/scripts/restricted_sparring.pory"
	goto_if_eq VAR_0x8004, TRUE, RestrictedSparring_Entrance_EventScript_NotEnoughValidMons
# 65 "data/scripts/restricted_sparring.pory"
	fadescreen FADE_TO_BLACK
# 66 "data/scripts/restricted_sparring.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 67 "data/scripts/restricted_sparring.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 68 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 69 "data/scripts/restricted_sparring.pory"
	special ChoosePartyForBattleFrontier
# 70 "data/scripts/restricted_sparring.pory"
	waitstate
# 71 "data/scripts/restricted_sparring.pory"
	goto_if_eq VAR_RESULT, 0, RestrictedSparring_Entrance_EventScript_LoadPartyCancelChallenge
# 73 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_BeforeDivingInto, MSGBOX_YESNO
# 74 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 76 "data/scripts/restricted_sparring.pory"
	case YES, RestrictedSparring_Entrance_EventScript_TryEnterChallenge_5
# 77 "data/scripts/restricted_sparring.pory"
	case NO, RestrictedSparring_Entrance_EventScript_TryEnterChallenge_6
# 78 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_Entrance_EventScript_TryEnterChallenge_6
	return

RestrictedSparring_Entrance_EventScript_TryEnterChallenge_3:
# 56 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_CancelChallenge
	goto RestrictedSparring_Entrance_EventScript_TryEnterChallenge_1

RestrictedSparring_Entrance_EventScript_TryEnterChallenge_5:
# 76 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge
	return

RestrictedSparring_Entrance_EventScript_TryEnterChallenge_6:
# 78 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_LoadPartyCancelChallenge
	return


RestrictedSparring_Entrance_EventScript_CreateTypeList::
# 84 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8009, 0
# 85 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_TYPE
# 86 "data/scripts/restricted_sparring.pory"
	special Sparring_ShowWinsWindow
# 87 "data/scripts/restricted_sparring.pory"
	special ShowScrollableMultichoice
# 88 "data/scripts/restricted_sparring.pory"
	waitstate
# 89 "data/scripts/restricted_sparring.pory"
	special Sparring_CloseWinsWindow
# 90 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 93 "data/scripts/restricted_sparring.pory"
	case 17, RestrictedSparring_Entrance_EventScript_CreateTypeList_4
# 94 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_Entrance_EventScript_CreateTypeList_4
# 92 "data/scripts/restricted_sparring.pory"
	sparring_convertmenutotype
RestrictedSparring_Entrance_EventScript_CreateTypeList_1:
# 97 "data/scripts/restricted_sparring.pory"
	sparring_buffersparringtype
	return

RestrictedSparring_Entrance_EventScript_CreateTypeList_4:
# 94 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_CancelChallenge
	goto RestrictedSparring_Entrance_EventScript_CreateTypeList_1


RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge::
# 103 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 104 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_0, 0
# 105 "data/scripts/restricted_sparring.pory"
	sparring_init
# 106 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 107 "data/scripts/restricted_sparring.pory"
	special LoadPlayerParty
# 108 "data/scripts/restricted_sparring.pory"
	closemessage
# 109 "data/scripts/restricted_sparring.pory"
	delay 2
# 111 "data/scripts/restricted_sparring.pory"
	call Common_EventScript_SaveGame
# 112 "data/scripts/restricted_sparring.pory"
	special HealPlayerParty
# 113 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_0, 255
# 115 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_eq RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge_2
RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge_1:
# 121 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_WarpToBattleRoom
	return

RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge_2:
# 117 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 118 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_DenyChallenge
	goto RestrictedSparring_Entrance_EventScript_SaveBeforeChallenge_1


RestrictedSparring_Entrance_EventScript_ExplainChallenge::
# 126 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_RestrictedSparringIsATraining, MSGBOX_YESNO
# 128 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, YES
	goto_if_eq RestrictedSparring_Entrance_EventScript_ExplainChallenge_2
RestrictedSparring_Entrance_EventScript_ExplainChallenge_1:
# 133 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_IWontForceYou, MSGBOX_DEFAULT
# 134 "data/scripts/restricted_sparring.pory"
	releaseall
	end

RestrictedSparring_Entrance_EventScript_ExplainChallenge_2:
# 130 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_TryEnterChallenge
	goto RestrictedSparring_Entrance_EventScript_ExplainChallenge_1


RestrictedSparring_Entrance_EventScript_NotEnoughValidMons::
# 140 "data/scripts/restricted_sparring.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 141 "data/scripts/restricted_sparring.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 143 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
	goto_if_eq RestrictedSparring_Entrance_EventScript_NotEnoughValidMons_2
# 149 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
RestrictedSparring_Entrance_EventScript_NotEnoughValidMons_1:
# 152 "data/scripts/restricted_sparring.pory"
	release
	end

RestrictedSparring_Entrance_EventScript_NotEnoughValidMons_2:
# 145 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto RestrictedSparring_Entrance_EventScript_NotEnoughValidMons_1


RestrictedSparring_Entrance_EventScript_LoadPartyCancelChallenge::
# 158 "data/scripts/restricted_sparring.pory"
	special LoadPlayerParty
# 159 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_CancelChallenge
	return


RestrictedSparring_Entrance_EventScript_CancelChallenge::
# 164 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_OhYouChangedYour, MSGBOX_DEFAULT
# 165 "data/scripts/restricted_sparring.pory"
	release
	end


RestrictedSparring_Entrance_EventScript_DenyChallenge::
# 171 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_IWontForceYou, MSGBOX_DEFAULT
# 172 "data/scripts/restricted_sparring.pory"
	release
	end


RestrictedSparring_Entrance_EventScript_WarpToBattleRoom::
# 178 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 179 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 180 "data/scripts/restricted_sparring.pory"
	special CallFrontierUtilFunc
# 181 "data/scripts/restricted_sparring.pory"
	frontier_saveparty
# 182 "data/scripts/restricted_sparring.pory"
	setvar VAR_RESULT, 0
# 183 "data/scripts/restricted_sparring.pory"
	warp MAP_MASTER_DOJO_BATTLE_ROOM, 0, 6
# 184 "data/scripts/restricted_sparring.pory"
	sparring_save CHALLENGE_STATUS_SAVING
	return


RestrictedSparring_Entrance_EventScript_JudgeChallenge::
# 189 "data/scripts/restricted_sparring.pory"
	sparring_get SPARRING_DATA_WIN_STREAK
# 191 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_eq RestrictedSparring_Entrance_EventScript_JudgeChallenge_1
# 197 "data/scripts/restricted_sparring.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 198 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_Results
	return

RestrictedSparring_Entrance_EventScript_JudgeChallenge_1:
# 193 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_Results_NoWins
	return


RestrictedSparring_Entrance_EventScript_Results_NoWins::
# 204 "data/scripts/restricted_sparring.pory"
	lock
# 205 "data/scripts/restricted_sparring.pory"
	faceplayer
# 206 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_SaveResult
# 207 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_AskSaveBattle
# 208 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_YouLostbutTrainYourself, MSGBOX_DEFAULT
# 209 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_SetChallengeStatusEnd
	return


RestrictedSparring_Entrance_EventScript_Results::
# 214 "data/scripts/restricted_sparring.pory"
	lock
# 215 "data/scripts/restricted_sparring.pory"
	faceplayer
# 216 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_SaveResult
# 218 "data/scripts/restricted_sparring.pory"
	sparring_buffersparringtype
# 219 "data/scripts/restricted_sparring.pory"
	sparring_get SPARRING_DATA_WIN_STREAK
# 220 "data/scripts/restricted_sparring.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 222 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_YourResultForThisRestricted
# 223 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_AwardPoints
# 225 "data/scripts/restricted_sparring.pory"
	goto_if_set FLAG_SPARRING_FIRST_TYPE_WIN, RestrictedSparring_Entrance_EventScript_Results_2
RestrictedSparring_Entrance_EventScript_Results_1:
# 231 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_AskSaveBattle
# 232 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_SetChallengeStatusEnd
	return

RestrictedSparring_Entrance_EventScript_Results_2:
# 227 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_TheWayYouHandleType
# 228 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_CheckSymbol
	goto RestrictedSparring_Entrance_EventScript_Results_1


RestrictedSparring_Entrance_EventScript_SaveResult::
# 237 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_RecordWillBeSaved
# 238 "data/scripts/restricted_sparring.pory"
	waitmessage
# 239 "data/scripts/restricted_sparring.pory"
	frontier_checkairshow
# 240 "data/scripts/restricted_sparring.pory"
	sparring_givepoints
# 241 "data/scripts/restricted_sparring.pory"
	sparring_checksymbol
# 243 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq RestrictedSparring_Entrance_EventScript_SaveResult_2
# 247 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_GOLD
	goto_if_eq RestrictedSparring_Entrance_EventScript_SaveResult_3
RestrictedSparring_Entrance_EventScript_SaveResult_1:
# 252 "data/scripts/restricted_sparring.pory"
	special LoadPlayerParty
# 253 "data/scripts/restricted_sparring.pory"
	sparring_save 0
# 254 "data/scripts/restricted_sparring.pory"
	playse SE_SAVE
# 255 "data/scripts/restricted_sparring.pory"
	waitse
	return

RestrictedSparring_Entrance_EventScript_SaveResult_2:
# 245 "data/scripts/restricted_sparring.pory"
	setflag FLAG_SYS_ARENA_SILVER
	goto RestrictedSparring_Entrance_EventScript_SaveResult_1

RestrictedSparring_Entrance_EventScript_SaveResult_3:
# 249 "data/scripts/restricted_sparring.pory"
	setflag FLAG_SYS_ARENA_GOLD
	goto RestrictedSparring_Entrance_EventScript_SaveResult_1


RestrictedSparring_Entrance_EventScript_AwardPoints::
# 260 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_YouEarned
	return


RestrictedSparring_Entrance_EventScript_CheckSymbol::
# 266 "data/scripts/restricted_sparring.pory"
	sparring_checksymbol
# 267 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_NONE
	goto_if_gt RestrictedSparring_Entrance_EventScript_CheckSymbol_2
RestrictedSparring_Entrance_EventScript_CheckSymbol_1:
	return

RestrictedSparring_Entrance_EventScript_CheckSymbol_2:
# 269 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_GiveSymbol
	goto RestrictedSparring_Entrance_EventScript_CheckSymbol_1


RestrictedSparring_Entrance_EventScript_GiveSymbol::
# 276 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_WhatYouCompletedRestricted
# 278 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq RestrictedSparring_Entrance_EventScript_GiveSymbol_2
# 284 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_ICantBelieveIt
# 285 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_ThisAccomplishmentIsSureTo
RestrictedSparring_Entrance_EventScript_GiveSymbol_1:
# 288 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_ToCommemorateThisMonumentalAchievement
# 289 "data/scripts/restricted_sparring.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 291 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_SILVER
	goto_if_eq RestrictedSparring_Entrance_EventScript_GiveSymbol_6
# 297 "data/scripts/restricted_sparring.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
RestrictedSparring_Entrance_EventScript_GiveSymbol_5:
# 300 "data/scripts/restricted_sparring.pory"
	waitmessage
# 301 "data/scripts/restricted_sparring.pory"
	waitfanfare
# 303 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, SPARRING_SYMBOL_GOLD
	goto_if_eq RestrictedSparring_Entrance_EventScript_GiveSymbol_10
RestrictedSparring_Entrance_EventScript_GiveSymbol_9:
	return

RestrictedSparring_Entrance_EventScript_GiveSymbol_2:
# 280 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_ThatsExcellentWork
	goto RestrictedSparring_Entrance_EventScript_GiveSymbol_1

RestrictedSparring_Entrance_EventScript_GiveSymbol_6:
# 293 "data/scripts/restricted_sparring.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
	goto RestrictedSparring_Entrance_EventScript_GiveSymbol_5

RestrictedSparring_Entrance_EventScript_GiveSymbol_10:
# 305 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_IHopeYoullKeep
	goto RestrictedSparring_Entrance_EventScript_GiveSymbol_9


RestrictedSparring_Entrance_EventScript_AskSaveBattle::
# 312 "data/scripts/restricted_sparring.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 314 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RestrictedSparring_Entrance_EventScript_AskSaveBattle_2
# 319 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_RecordLastMatch
# 320 "data/scripts/restricted_sparring.pory"
	waitmessage
# 321 "data/scripts/restricted_sparring.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 323 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_eq RestrictedSparring_Entrance_EventScript_AskSaveBattle_5
RestrictedSparring_Entrance_EventScript_AskSaveBattle_4:
	return

RestrictedSparring_Entrance_EventScript_AskSaveBattle_2:
	return

RestrictedSparring_Entrance_EventScript_AskSaveBattle_5:
# 325 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_Entrance_EventScript_SaveBattle
	goto RestrictedSparring_Entrance_EventScript_AskSaveBattle_4


RestrictedSparring_Entrance_EventScript_SaveBattle::
# 332 "data/scripts/restricted_sparring.pory"
	frontier_savebattle
# 333 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_ne RestrictedSparring_Entrance_EventScript_SaveBattle_2
# 340 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_ThereWasAGlitch, MSGBOX_DEFAULT
RestrictedSparring_Entrance_EventScript_SaveBattle_1:
	return

RestrictedSparring_Entrance_EventScript_SaveBattle_2:
# 335 "data/scripts/restricted_sparring.pory"
	playse SE_SAVE
# 336 "data/scripts/restricted_sparring.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto RestrictedSparring_Entrance_EventScript_SaveBattle_1


RestrictedSparring_Entrance_EventScript_SetChallengeStatusEnd::
# 347 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_0, 255
# 348 "data/scripts/restricted_sparring.pory"
	closemessage
# 349 "data/scripts/restricted_sparring.pory"
	setvar VAR_SPARRING_TYPE, TYPE_NONE
# 350 "data/scripts/restricted_sparring.pory"
	release
	end


RestrictedSparring_Entrance_EventScript_ResumeChallenge::
# 356 "data/scripts/restricted_sparring.pory"
	lock
# 357 "data/scripts/restricted_sparring.pory"
	faceplayer
# 359 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_WeveBeenWaitingForYou
# 360 "data/scripts/restricted_sparring.pory"
	waitmessage
# 361 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_Entrance_Text_ProgressWillBeSaved
# 362 "data/scripts/restricted_sparring.pory"
	waitmessage
# 364 "data/scripts/restricted_sparring.pory"
	playse SE_SAVE
# 365 "data/scripts/restricted_sparring.pory"
	waitse
# 366 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 368 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_WarpToBattleRoom
	end


RestrictedSparring_Entrance_EventScript_ShowResults::
# 374 "data/scripts/restricted_sparring.pory"
	lockall
# 375 "data/scripts/restricted_sparring.pory"
	frontier_results FRONTIER_FACILITY_SPARRING, 0
# 376 "data/scripts/restricted_sparring.pory"
	waitbuttonpress
# 377 "data/scripts/restricted_sparring.pory"
	special RemoveRecordsWindow
# 378 "data/scripts/restricted_sparring.pory"
	releaseall
	end


RestrictedSparring_EventScript_RulesBoard::
# 384 "data/scripts/restricted_sparring.pory"
	lockall
# 385 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_RulesAreListed, MSGBOX_DEFAULT
# 386 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_Entrance_EventScript_ReadRulesBoard
	end


RestrictedSparring_Entrance_EventScript_ReadRulesBoard::
# 392 "data/scripts/restricted_sparring.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
# 393 "data/scripts/restricted_sparring.pory"
	waitmessage
# 394 "data/scripts/restricted_sparring.pory"
	multichoice 17, 2, MULTI_RESTRICTED_SPARRING_RULES, FALSE
# 396 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 398 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_Entrance_EventScript_ReadRulesBoard_3
# 400 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_Entrance_EventScript_ReadRulesBoard_4
# 402 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_Entrance_EventScript_ReadRulesBoard_5
# 404 "data/scripts/restricted_sparring.pory"
	case 3, RestrictedSparring_Entrance_EventScript_ReadRulesBoard_6
# 405 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_Entrance_EventScript_ReadRulesBoard_6
RestrictedSparring_Entrance_EventScript_ReadRulesBoard_1:
# 409 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_EventScript_RulesBoard
	end

RestrictedSparring_Entrance_EventScript_ReadRulesBoard_3:
# 399 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_OverviewBoard, MSGBOX_DEFAULT
	goto RestrictedSparring_Entrance_EventScript_ReadRulesBoard_1

RestrictedSparring_Entrance_EventScript_ReadRulesBoard_4:
# 401 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_RestrictionsBoard, MSGBOX_DEFAULT
	goto RestrictedSparring_Entrance_EventScript_ReadRulesBoard_1

RestrictedSparring_Entrance_EventScript_ReadRulesBoard_5:
# 403 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_RewardsBoard, MSGBOX_DEFAULT
	goto RestrictedSparring_Entrance_EventScript_ReadRulesBoard_1

RestrictedSparring_Entrance_EventScript_ReadRulesBoard_6:
# 406 "data/scripts/restricted_sparring.pory"
	releaseall
	end


RestrictedSparring_BattleCourt_EventScript_RefreshOpponent::
# 566 "data/scripts/restricted_sparring.pory"
	tower_setopponent
# 567 "data/scripts/restricted_sparring.pory"
	call MasterDojo_BattleRoom_EventScript_RefreshOpponentObject
	return


RestrictedSparring_BattleCourt_EventScript_SetUpOpponent::
# 573 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_0, 1
# 574 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_RefreshOpponent
# 575 "data/scripts/restricted_sparring.pory"
	call MasterDojo_BattleRoom_EventScript_EnterRoomMovement
# 576 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_OpponentEnter
	return


RestrictedSparring_BattleCourt_EventScript_OpponentEnter::
# 581 "data/scripts/restricted_sparring.pory"
	call MasterDojo_BattleRoom_EventScript_OpponentEnterMovement
# 583 "data/scripts/restricted_sparring.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 584 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_eq RestrictedSparring_BattleCourt_EventScript_OpponentEnter_2
# 589 "data/scripts/restricted_sparring.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 590 "data/scripts/restricted_sparring.pory"
	addvar VAR_TEMP_E, 1
# 591 "data/scripts/restricted_sparring.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_E
# 592 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_1, MSGBOX_DEFAULT
RestrictedSparring_BattleCourt_EventScript_OpponentEnter_1:
# 595 "data/scripts/restricted_sparring.pory"
	delay 15
# 597 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_2, MSGBOX_DEFAULT
# 598 "data/scripts/restricted_sparring.pory"
	closemessage
# 599 "data/scripts/restricted_sparring.pory"
	sparring_getopponentintro
# 600 "data/scripts/restricted_sparring.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 601 "data/scripts/restricted_sparring.pory"
	waitmessage
# 603 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_DoTowerBattle
# 604 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RestrictedSparring_BattleCourt_EventScript_OpponentEnter_6
RestrictedSparring_BattleCourt_EventScript_OpponentEnter_5:
# 609 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_WarpToLobbyLost
	return

RestrictedSparring_BattleCourt_EventScript_OpponentEnter_2:
# 585 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_0, MSGBOX_DEFAULT
	goto RestrictedSparring_BattleCourt_EventScript_OpponentEnter_1

RestrictedSparring_BattleCourt_EventScript_OpponentEnter_6:
# 606 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_DefeatedOpponent
	goto RestrictedSparring_BattleCourt_EventScript_OpponentEnter_5


RestrictedSparring_BattleCourt_EventScript_WarpToLobbyLost::
# 614 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 615 "data/scripts/restricted_sparring.pory"
	sparring_set SPARRING_DATA_LVL_MODE
# 616 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_WarpToLobby
	return


RestrictedSparring_BattleCourt_EventScript_WarpToLobby::
# 621 "data/scripts/restricted_sparring.pory"
	warp MAP_MASTER_DOJO_LOBBY, 7, 8
# 622 "data/scripts/restricted_sparring.pory"
	waitstate
	end


RestrictedSparring_BattleCourt_EventScript_DefeatedOpponent::
# 628 "data/scripts/restricted_sparring.pory"
	sparring_setbattlewon
# 629 "data/scripts/restricted_sparring.pory"
	call MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement
# 630 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_StopChallenge
# 631 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_DefeatedOpponent_Text_0, MSGBOX_DEFAULT
# 632 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	return


RestrictedSparring_BattleCourt_EventScript_StopChallenge::
# 637 "data/scripts/restricted_sparring.pory"
	sparring_checkmaxstreak
# 638 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, 0
	goto_if_eq RestrictedSparring_BattleCourt_EventScript_StopChallenge_2
# 642 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_StopChallenge_Text_0, MSGBOX_DEFAULT
# 643 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_WarpToLobbyWon
	return

RestrictedSparring_BattleCourt_EventScript_StopChallenge_2:
	return


RestrictedSparring_BattleCourt_EventScript_AskReadyGetMenu::
# 648 "data/scripts/restricted_sparring.pory"
	message RestrictedSparring_BattleCourt_EventScript_AskReadyGetMenu_Text_0
# 649 "data/scripts/restricted_sparring.pory"
	waitmessage
# 650 "data/scripts/restricted_sparring.pory"
	sparring_getcontinuemenutype
	return


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent::
# 656 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_AskReadyGetMenu
# 657 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 659 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDYES_HEALYES, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_2
# 660 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDYES_HEALNO, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_3
# 661 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDNO_HEALYES, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_4
# 662 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDNO_HEALNO, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_5
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_2:
# 659 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_3:
# 660 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_4:
# 661 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_5:
# 662 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo
	return


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo::
# 668 "data/scripts/restricted_sparring.pory"
	multichoice 22, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 669 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 671 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_3
# 672 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_4
# 673 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_5
# 674 "data/scripts/restricted_sparring.pory"
	case 3, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_6
# 675 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_7
RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1:
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_3:
# 671 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_ContinueChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_4:
# 672 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRecordBattle
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_5:
# 673 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_6:
# 674 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_7:
# 675 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo_1


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo::
# 682 "data/scripts/restricted_sparring.pory"
	multichoice 22, 5, MULTI_GO_ON_REST_RETIRE, TRUE
# 683 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 685 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_3
# 686 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_4
# 687 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_5
# 688 "data/scripts/restricted_sparring.pory"
	case 3, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_6
RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_1:
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_3:
# 685 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_ContinueChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_4:
# 686 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_5:
# 687 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_6:
# 688 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo_1


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes::
# 695 "data/scripts/restricted_sparring.pory"
	multichoice 22, 2, MULTI_GO_ON_HEAL_RECORD_REST_RETIRE, TRUE
# 696 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 698 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_3
# 699 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_4
# 700 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_5
# 701 "data/scripts/restricted_sparring.pory"
	case 3, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_6
# 702 "data/scripts/restricted_sparring.pory"
	case 4, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_7
# 703 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_8
RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1:
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_3:
# 698 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_ContinueChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_4:
# 699 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskHeal
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_5:
# 700 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRecordBattle
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_6:
# 701 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_7:
# 702 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_8:
# 703 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealYes_1


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes::
# 710 "data/scripts/restricted_sparring.pory"
	multichoice 22, 4, MULTI_GO_ON_HEAL_REST_RETIRE, TRUE
# 711 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 713 "data/scripts/restricted_sparring.pory"
	case 0, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_3
# 714 "data/scripts/restricted_sparring.pory"
	case 1, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_4
# 715 "data/scripts/restricted_sparring.pory"
	case 2, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_5
# 716 "data/scripts/restricted_sparring.pory"
	case 3, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_6
# 717 "data/scripts/restricted_sparring.pory"
	case 4, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_7
RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1:
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_3:
# 713 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_ContinueChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_4:
# 714 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskHeal
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_5:
# 715 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_6:
# 716 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_7:
# 717 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealYes_1


RestrictedSparring_BattleCourt_EventScript_AskHeal::
# 724 "data/scripts/restricted_sparring.pory"
	buffernumberstring STR_VAR_1, VAR_RESTRICTEDSPARRING_HEAL_COUNT
# 725 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_BattleCourt_EventScript_AskHeal_Text_0, MSGBOX_YESNO
# 726 "data/scripts/restricted_sparring.pory"
	waitmessage
# 727 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, YES
	goto_if_eq RestrictedSparring_BattleCourt_EventScript_AskHeal_2
RestrictedSparring_BattleCourt_EventScript_AskHeal_1:
# 733 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	return

RestrictedSparring_BattleCourt_EventScript_AskHeal_2:
# 729 "data/scripts/restricted_sparring.pory"
	frontier_restorehelditems
# 730 "data/scripts/restricted_sparring.pory"
	sparring_restore
# 731 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal
	goto RestrictedSparring_BattleCourt_EventScript_AskHeal_1


RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal::
# 738 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_AskReadyGetMenu
# 739 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 741 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDYES_HEALYES, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_2
# 742 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDYES_HEALNO, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_2
# 743 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDNO_HEALYES, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_3
# 744 "data/scripts/restricted_sparring.pory"
	case SPARRING_RECORDNO_HEALNO, RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_3
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_2:
# 742 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordYesHealNo
	return

RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent_PostHeal_3:
# 744 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponentRecordNoHealNo
	return


RestrictedSparring_BattleCourt_EventScript_AskRecordBattle::
# 750 "data/scripts/restricted_sparring.pory"
	msgbox RestrictedSparring_Entrance_Text_RecordLastMatch, MSGBOX_YESNO
# 751 "data/scripts/restricted_sparring.pory"
	waitmessage
# 752 "data/scripts/restricted_sparring.pory"
	compare VAR_RESULT, YES
	goto_if_eq RestrictedSparring_BattleCourt_EventScript_AskRecordBattle_2
RestrictedSparring_BattleCourt_EventScript_AskRecordBattle_1:
# 756 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	return

RestrictedSparring_BattleCourt_EventScript_AskRecordBattle_2:
# 754 "data/scripts/restricted_sparring.pory"
	call BattleFrontier_EventScript_SaveBattle
	goto RestrictedSparring_BattleCourt_EventScript_AskRecordBattle_1


RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge::
# 761 "data/scripts/restricted_sparring.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 762 "data/scripts/restricted_sparring.pory"
	waitmessage
# 763 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 765 "data/scripts/restricted_sparring.pory"
	case YES, RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge_2
# 766 "data/scripts/restricted_sparring.pory"
	case NO, RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge_3
# 767 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge_3
	return

RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge_2:
# 765 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_PauseChallenge
	return

RestrictedSparring_BattleCourt_EventScript_AskPauseChallenge_3:
# 767 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	return


RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge::
# 773 "data/scripts/restricted_sparring.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge, MSGBOX_YESNO
# 774 "data/scripts/restricted_sparring.pory"
	waitmessage
# 775 "data/scripts/restricted_sparring.pory"
	switch VAR_RESULT
# 777 "data/scripts/restricted_sparring.pory"
	case YES, RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge_2
# 778 "data/scripts/restricted_sparring.pory"
	case NO, RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge_3
# 779 "data/scripts/restricted_sparring.pory"
	case MULTI_B_PRESSED, RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge_3
	return

RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge_2:
# 777 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_WarpToLobbyWon
	return

RestrictedSparring_BattleCourt_EventScript_AskRetireChallenge_3:
# 779 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_AskReadyForOpponent
	return


RestrictedSparring_BattleCourt_EventScript_ContinueChallenge::
# 785 "data/scripts/restricted_sparring.pory"
	closemessage
# 786 "data/scripts/restricted_sparring.pory"
	call RestrictedSparring_BattleCourt_EventScript_RefreshOpponent
# 787 "data/scripts/restricted_sparring.pory"
	call MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement
# 788 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_OpponentEnter
	return


RestrictedSparring_BattleCourt_EventScript_WarpToLobbyWon::
# 793 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 794 "data/scripts/restricted_sparring.pory"
	sparring_set TOWER_DATA_LVL_MODE
# 795 "data/scripts/restricted_sparring.pory"
	goto RestrictedSparring_BattleCourt_EventScript_WarpToLobby
	return


RestrictedSparring_BattleCourt_EventScript_PauseChallenge::
# 800 "data/scripts/restricted_sparring.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 801 "data/scripts/restricted_sparring.pory"
	waitmessage
# 802 "data/scripts/restricted_sparring.pory"
	sparring_save CHALLENGE_STATUS_PAUSED
# 803 "data/scripts/restricted_sparring.pory"
	playse SE_SAVE
# 804 "data/scripts/restricted_sparring.pory"
	waitse
# 805 "data/scripts/restricted_sparring.pory"
	fadescreen FADE_TO_BLACK
# 806 "data/scripts/restricted_sparring.pory"
	frontier_reset
	end


RestrictedSparring_BattleCourt_EventScript_DoTowerBattle::
# 812 "data/scripts/restricted_sparring.pory"
	closemessage
# 813 "data/scripts/restricted_sparring.pory"
	setvar VAR_TEMP_2, 0
# 814 "data/scripts/restricted_sparring.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 815 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_SPARRING
# 816 "data/scripts/restricted_sparring.pory"
	setvar VAR_0x8005, 0
# 817 "data/scripts/restricted_sparring.pory"
	special DoSpecialTrainerBattle
# 818 "data/scripts/restricted_sparring.pory"
	waitstate
# 819 "data/scripts/restricted_sparring.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 820 "data/scripts/restricted_sparring.pory"
	sparring_restorehelditems
# 821 "data/scripts/restricted_sparring.pory"
	sparring_resetsketch
# 822 "data/scripts/restricted_sparring.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return


RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_0:
# 585 "data/scripts/restricted_sparring.pory"
	.string "Let the battles begin! Battle No. 1!\n"
	.string "Ready...$"

RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_1:
# 592 "data/scripts/restricted_sparring.pory"
	.string "Next. Battle No. {STR_VAR_1}!\n"
	.string "Ready...$"

RestrictedSparring_BattleCourt_EventScript_OpponentEnter_Text_2:
# 597 "data/scripts/restricted_sparring.pory"
	.string "Go!$"

RestrictedSparring_BattleCourt_EventScript_DefeatedOpponent_Text_0:
# 631 "data/scripts/restricted_sparring.pory"
	.string "Well done!$"

RestrictedSparring_BattleCourt_EventScript_StopChallenge_Text_0:
# 642 "data/scripts/restricted_sparring.pory"
	.string "Wow, {PLAYER}, {STR_VAR_1} win(s)\n"
	.string "in a row... I think we all need a break!$"

RestrictedSparring_BattleCourt_EventScript_AskReadyGetMenu_Text_0:
# 648 "data/scripts/restricted_sparring.pory"
	.string "Do you want to continue sparring?$"

RestrictedSparring_BattleCourt_EventScript_AskHeal_Text_0:
# 725 "data/scripts/restricted_sparring.pory"
	.string "Do you want to restore your POKéMON?\n"
	.string "(You can restore them {STR_VAR_1}\l"
	.string "more time(s).)$"

RestrictedSparring_Entrance_Text_RulesAreListed::
# 413 "data/scripts/restricted_sparring.pory"
	.string "The RESTRICTED SPARRING rules are\n"
	.string "listed.$"

RestrictedSparring_Entrance_Text_OverviewBoard::
# 418 "data/scripts/restricted_sparring.pory"
	.string "RESTRICTED SPARRING is challenges you\n"
	.string "to battle using up to three POKéMON of\l"
	.string "a single type. Select a level mode and a\l"
	.string "type, then battle your way through five\l"
	.string "consecutive battles.$"

RestrictedSparring_Entrance_Text_RestrictionsBoard::
# 423 "data/scripts/restricted_sparring.pory"
	.string "No duplicate POKéMON or items are\n"
	.string "allowed. You can only restore your\l"
	.string "POKéMON twice in total, so use your\l"
	.string "opportunities wisely.$"

RestrictedSparring_Entrance_Text_RewardsBoard::
# 428 "data/scripts/restricted_sparring.pory"
	.string "If you can win five times in a row, you\n"
	.string "will complete the training, but you can\l"
	.string "continue to increase your streak. You'll\l"
	.string "recieve a reward for completing\l"
	.string "training for all types in a level mode.$"

RestrictedSparring_Entrance_Text_HiyahDo::
# 433 "data/scripts/restricted_sparring.pory"
	.string "Hi-yah! {PLAYER}! Do you want to try\n"
	.string "RESTRICTED SPARRING?$"

RestrictedSparring_Entrance_Text_SelectTheTypeYouWant::
# 438 "data/scripts/restricted_sparring.pory"
	.string "Select the type you want to use for\n"
	.string "sparring.$"

RestrictedSparring_Entrance_Text_IWontForceYou::
# 443 "data/scripts/restricted_sparring.pory"
	.string "I won't force you to do anything you\n"
	.string "don't want to do. Some other time, then.$"

RestrictedSparring_Entrance_Text_RestrictedSparringIsATraining::
# 448 "data/scripts/restricted_sparring.pory"
	.string "RESTRICTED SPARRING is a training\n"
	.string "course that restricts the type of\l"
	.string "POKéMON you can use. Select a type\l"
	.string "first, and then battle using up to three\l"
	.string "POKéMON of that type. No duplicate\l"
	.string "POKéMON or items are allowed. If you can\l"
	.string "win five times in a row, you'll complete\l"
	.string "the training. However, if you lose even\l"
	.string "once, the sparring will end there! You\l"
	.string "can restore your POKéMON between\l"
	.string "battles, but only twice in total, so use\l"
	.string "the opportunities very wisely. That's\l"
	.string "all! Do you want to try RESTRICTED\l"
	.string "SPARRING?$"

RestrictedSparring_Entrance_Text_OhYouChangedYour::
# 453 "data/scripts/restricted_sparring.pory"
	.string "Oh, you changed your mind? Some other\n"
	.string "time, then.$"

RestrictedSparring_Entrance_Text_YouLostbutTrainYourself::
# 458 "data/scripts/restricted_sparring.pory"
	.string "You lost...but train yourself and your\n"
	.string "POKéMON, and try again! I'm looking\l"
	.string "forward to your next challenge.$"

RestrictedSparring_Entrance_Text_YourResultForThisRestricted::
# 463 "data/scripts/restricted_sparring.pory"
	.string "Your result for this RESTRICTED\n"
	.string "SPARRING set is... You had\l"
	.string "{STR_VAR_1} win(s) with the\l"
	.string "{STR_VAR_3}-type POKéMON\l"
	.string "restriction!$"

RestrictedSparring_Entrance_Text_TheWayYouHandleType::
# 468 "data/scripts/restricted_sparring.pory"
	.string "The way you handle\n"
	.string "{STR_VAR_3}-type POKéMON is\l"
	.string "flawless!$"

RestrictedSparring_Entrance_Text_WhatYouCompletedRestricted::
# 473 "data/scripts/restricted_sparring.pory"
	.string "What?! You completed RESTRICTED\n"
	.string "SPARRING with {STR_VAR_1} type(s)?!$"

RestrictedSparring_Entrance_Text_ThatsExcellentWork::
# 478 "data/scripts/restricted_sparring.pory"
	.string "That's excellent work!$"

RestrictedSparring_Entrance_Text_ICantBelieveIt::
# 483 "data/scripts/restricted_sparring.pory"
	.string "I can't believe it... Your achievement is\n"
	.string "just phenomenal!$"

RestrictedSparring_Entrance_Text_ThisAccomplishmentIsSureTo::
# 488 "data/scripts/restricted_sparring.pory"
	.string "This accomplishment is sure to go down\n"
	.string "in dojo history!$"

RestrictedSparring_Entrance_Text_ToCommemorateThisMonumentalAchievement::
# 493 "data/scripts/restricted_sparring.pory"
	.string "To commemorate this monumental\n"
	.string "achievement, I'll grant you this!$"

RestrictedSparring_Entrance_Text_IHopeYoullKeep::
# 498 "data/scripts/restricted_sparring.pory"
	.string "I hope you'll keep exceeding your own\n"
	.string "limits!$"

RestrictedSparring_Entrance_Text_DidntSaveBeforeQuitting::
# 503 "data/scripts/restricted_sparring.pory"
	.string "Oops! {PLAYER}, it seems you didn't\n"
	.string "save before quitting your challenge\l"
	.string "last time. Because of that, your\l"
	.string "challenge so far has been disqualified.\l"
	.string "Sorry!$"

RestrictedSparring_Entrance_Text_ThankYouForPlaying::
# 508 "data/scripts/restricted_sparring.pory"
	.string "Thanks for playing, {PLAYER}!$"

RestrictedSparring_Entrance_Text_RecordWillBeSaved::
# 513 "data/scripts/restricted_sparring.pory"
	.string "Your record will be saved soon.$"

RestrictedSparring_Entrance_Text_WeveBeenWaitingForYou::
# 518 "data/scripts/restricted_sparring.pory"
	.string "We've been waiting for you, {PLAYER}!$"

RestrictedSparring_Entrance_Text_ProgressWillBeSaved::
# 523 "data/scripts/restricted_sparring.pory"
	.string "Before entering the BATTLE COURT, your\n"
	.string "progress will be saved. Hang tight!$"

RestrictedSparring_Entrance_Text_ThereWasAGlitch::
# 528 "data/scripts/restricted_sparring.pory"
	.string "Oops! There was a glitch, and your\n"
	.string "record couldn't be saved. Better luck\l"
	.string "next time!$"

RestrictedSparring_Entrance_Text_OffersTwoLevels::
# 533 "data/scripts/restricted_sparring.pory"
	.string "RESTRICTED SPARRING offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "So, which one is your pick?$"

RestrictedSparring_Entrance_Text_BeforeDivingInto::
# 538 "data/scripts/restricted_sparring.pory"
	.string "Before diving into RESTRICTED\n"
	.string "SPARRING, your progress must be saved.\l"
	.string "Is that cool?$"

RestrictedSparring_Entrance_Text_NotEnoughValidMonsLv50Singles::
# 544 "data/scripts/restricted_sparring.pory"
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON of Level 50 or less\l"
	.string "to enter. They must all share the\l"
	.string "{STR_VAR_3}-type and hold\l"
	.string "different items. EGGS{STR_VAR_1}\l"
	.string "not allowed. Come back when you're\l"
	.string "ready!$"

RestrictedSparring_Entrance_Text_NotEnoughValidMonsLvOpenSingles::
# 549 "data/scripts/restricted_sparring.pory"
	.string "Hold up, {PLAYER}! You need three\n"
	.string "different POKéMON to enter. They must\l"
	.string "all share the {STR_VAR_3}-type and\l"
	.string "hold different items.\l"
	.string "EGGS{STR_VAR_1} not allowed. Come\l"
	.string "back when you're ready!$"

RestrictedSparring_Entrance_Text_RecordLastMatch::
# 554 "data/scripts/restricted_sparring.pory"
	.string "Want me to record your last RESTRICTED\n"
	.string "SPARRING match on your FRONTIER PASS?$"

RestrictedSparring_Entrance_Text_YouEarned::
# 559 "data/scripts/restricted_sparring.pory"
	.string "You earned {STR_VAR_2} BP!$"
