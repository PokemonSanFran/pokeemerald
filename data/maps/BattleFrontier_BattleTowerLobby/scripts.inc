BattleFrontier_BattleTowerLobby_MapScripts::
# 23 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_RESUME
# 28 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 33 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 41 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_RESUME:
# 24 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryHideBattleTowerReporter
	end

BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 29 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowOrHideReporter
# 30 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventSCript_ShowOrHideApprentice
	return

BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 34 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
# 35 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
# 36 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
# 37 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
# 38 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleTowerLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 42 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth
	.2byte 0


BattleFrontier_BattleTowerLobby_EventSCript_ShowOrHideApprentice::
# 47 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_shouldcheckgone
# 49 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventSCript_ShowOrHideApprentice_1
# 52 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_HIDE_APPRENTICE
# 53 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_setgfx
	return

BattleFrontier_BattleTowerLobby_EventSCript_ShowOrHideApprentice_1:
# 50 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setflag FLAG_HIDE_APPRENTICE
	return


BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth::
# 58 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 59 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus::
# 64 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_getstatus
	end


BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving::
# 69 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 70 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 71 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 72 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 73 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK, 0
# 74 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 75 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 76 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 77 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_WonChallenge::
# 82 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 83 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 85 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_isbrain
# 86 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_WonChallenge_2
# 89 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
# 90 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
BattleFrontier_BattleTowerLobby_EventScript_WonChallenge_1:
# 93 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons
# 94 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
# 95 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 96 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon
# 97 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_WonChallenge_2:
# 87 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_WonChallenge_1


BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons::
# 101 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_giveribbons
# 102 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons_2
# 106 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
# 107 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 108 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 109 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitfanfare
# 110 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons_2:
	return


BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints::
# 115 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 116 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_givepoints
# 117 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	return


BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon::
# 122 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 123 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 49
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon_2
BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon_2:
# 124 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_Explain50StreakRibbon_1


BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge::
# 130 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 131 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 132 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 133 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_LostChallenge::
# 138 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_2
# 139 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_2
BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_1:
# 143 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 144 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_7
BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_6:
# 148 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	return

BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_2:
# 140 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	goto BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_7:
# 145 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
	goto BattleFrontier_BattleTowerLobby_EventScript_LostChallenge_6


BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak::
# 152 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 153 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
	return


BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying::
# 157 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 158 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 159 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
# 160 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 161 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 162 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 163 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 164 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 165 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle::
# 170 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
# 171 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 172 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkairshow
# 173 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 174 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special HealPlayerParty
# 175 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
# 176 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 177 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 179 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 180 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_2
# 184 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
# 185 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 187 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_5
BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_4:
	return

BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_2:
	return

BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_5:
# 188 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle_4


BattleFrontier_EventScript_SaveBattle::
# 195 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_savebattle
# 196 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_EventScript_SaveBattle_2
# 200 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleFrontier_EventScript_SaveBattle_1:
	return

BattleFrontier_EventScript_SaveBattle_2:
# 197 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 198 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleFrontier_EventScript_SaveBattle_1


BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge::
# 207 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 208 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 210 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge_2
BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge_1:
# 214 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
# 215 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 216 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
# 217 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 219 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 220 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 221 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 222 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 224 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge_2:
# 211 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge_1


BattleFrontier_BattleTowerLobby_EventScript_Attendant::
# 229 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 230 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 231 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 233 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_LAST_TALKED, 8
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_Attendant_2
BattleFrontier_BattleTowerLobby_EventScript_Attendant_1:
# 237 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 239 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 240 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_Attendant_6
# 241 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_Attendant_7
# 242 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_Attendant_8
# 243 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_Attendant_9
BattleFrontier_BattleTowerLobby_EventScript_Attendant_4:
# 246 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_Attendant_2:
# 234 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant_1

BattleFrontier_BattleTowerLobby_EventScript_Attendant_6:
# 240 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant_4

BattleFrontier_BattleTowerLobby_EventScript_Attendant_7:
# 241 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant_4

BattleFrontier_BattleTowerLobby_EventScript_Attendant_8:
# 242 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant_4

BattleFrontier_BattleTowerLobby_EventScript_Attendant_9:
# 243 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant_4


BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge::
# 250 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 251 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_3
# 252 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_4
# 253 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_5
# 254 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_6
BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_1:
# 257 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 258 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 259 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 260 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_8
# 261 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_9
# 262 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_10
# 263 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_11
	return

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_3:
# 251 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_4:
# 252 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_5:
# 253 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_6:
# 254 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_8:
# 260 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_9:
# 261 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_10:
# 262 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge_11:
# 263 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge::
# 268 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 269 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_3
# 270 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_4
# 271 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_5
# 272 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_6
BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_1:
# 274 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 275 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 276 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 277 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 278 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_9
# 279 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_10
BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_7:
# 281 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 282 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 283 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 284 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 285 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_13
# 286 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_14
# 287 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_15
# 288 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_16
BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_11:
# 291 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 292 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 293 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 294 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 295 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_19
# 296 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_20
# 297 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_21
# 298 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_22
BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_17:
# 300 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 301 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 302 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 303 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 304 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 305 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_24
# 306 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_25
# 307 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_26
	return

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_3:
# 269 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_4:
# 270 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_5:
# 271 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_6:
# 272 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_9:
# 278 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_7

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_10:
# 279 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_7

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_13:
# 285 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_11

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_14:
# 286 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_11

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_15:
# 287 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_11

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_16:
# 288 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_11

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_19:
# 295 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_17

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_20:
# 296 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_17

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_21:
# 297 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_17

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_22:
# 298 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_17

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_24:
# 305 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_25:
# 306 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge
	return

BattleFrontier_BattleTowerLobby_EventScript_TryEnterChallenge_26:
# 307 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	return


BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge::
# 312 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 313 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 314 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 315 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 316 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 317 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 318 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 319 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 326 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_LAST_TALKED, 9
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_2
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_1:
# 330 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 331 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 333 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_5
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_4:
# 338 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer
# 340 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 341 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_9
# 342 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_10
# 343 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_11
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_7:
# 345 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	return

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_2:
# 327 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_5:
# 334 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
# 335 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_4

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_9:
# 341 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_7

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_10:
# 342 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_7

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_11:
# 343 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeChallenge_7


BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer::
# 349 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_LAST_TALKED, 9
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_2
BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_2:
# 351 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 352 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_5
BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_4:
# 356 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	goto BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_1

BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_5:
# 353 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleFrontier_BattleTowerLobby_EventScript_HandleMultiplayer_4


BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink::
# 362 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_BATTLE_TOWER
# 363 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	end


BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader::
# 368 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message CableClub_Text_ChooseGroupLeaderOfTwo
# 369 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 370 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
# 371 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 372 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_3
# 373 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_4
# 374 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_5
# 375 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_6
BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_1:
	end

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_3:
# 372 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_1

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_4:
# 373 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_1

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_5:
# 374 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_1

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_6:
# 375 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader_1


BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup::
# 381 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 382 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 383 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_3
# 384 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_4
# 385 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_5
# 386 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_6
BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_1:
# 388 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_3:
# 383 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_1

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_4:
# 384 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_1

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_5:
# 385 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_1

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_6:
# 386 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	goto BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup_1


BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader::
# 393 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 394 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 395 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_3
# 396 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_4
# 397 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_5
# 398 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_6
BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_1:
# 400 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_3:
# 395 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_1

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_4:
# 396 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_1

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_5:
# 397 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_1

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_6:
# 398 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	goto BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader_1


BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful::
# 405 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_LinkSuccessful
# 406 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end


BattleFrontier_BattleTowerLobby_EventScript_TryCableLink::
# 411 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, USING_BATTLE_TOWER
# 412 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message gText_PleaseWaitForLink
# 413 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 414 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, 0
# 416 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryBattleLinkup
# 417 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 418 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 419 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_3
# 420 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_SOMEONE_NOT_READY, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_4
# 421 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_DIFF_SELECTIONS, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_5
# 422 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_WRONG_NUM_PLAYERS, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_6
# 423 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_7
# 424 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_CONNECTION_ERROR, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_8
# 425 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_9
BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1:
	end

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_3:
# 419 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_4:
# 420 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto CableClub_EventScript_AbortLinkSomeoneNotReady
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_5:
# 421 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_6:
# 422 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_7:
# 423 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_8:
# 424 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto CableClub_EventScript_AbortLinkConnectionError
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_9:
# 425 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink_1


BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections::
# 431 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 432 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8005, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections_2
BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections_1:
# 435 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
# 436 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections_2:
# 433 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections_1


BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection::
# 441 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
# 442 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 443 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers::
# 448 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers, MSGBOX_DEFAULT
# 449 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 450 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
# 451 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_AbortLink::
# 456 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 458 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_0x8005
# 459 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_AbortLink_3
# 460 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_AbortLink_4
# 461 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_AbortLink_5
BattleFrontier_BattleTowerLobby_EventScript_AbortLink_1:
# 464 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 465 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLink_3:
# 459 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink_1

BattleFrontier_BattleTowerLobby_EventScript_AbortLink_4:
# 460 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink_1

BattleFrontier_BattleTowerLobby_EventScript_AbortLink_5:
# 461 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AbortLink_1


BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful::
# 470 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_LinkSuccessful
# 471 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TrySetBattleTowerLinkType
# 472 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end


BattleFrontier_BattleTowerLobby_EventScript_LinkSuccessful::
# 477 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 478 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 479 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
# 480 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 481 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 482 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SaveForBattleTowerLink
# 483 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 484 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 485 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
	return


BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge::
# 490 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_LAST_TALKED
# 491 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_3
# 493 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 7, BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_4
# 495 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 8, BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_5
# 497 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 9, BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_6
BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_1:
# 501 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_3:
# 492 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_4:
# 494 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_5:
# 496 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_1

BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_6:
# 498 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge_1


BattleFrontier_BattleTowerLobby_EventScript_SinglesAttendant::
# 506 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant
	return


BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant::
# 510 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant
	return


BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant::
# 514 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant
	return


BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant::
# 518 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_Attendant
	return


BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan::
# 522 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 523 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 524 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
# 525 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 526 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 4, MULTI_BATTLE_TOWER_FEELINGS, FALSE
# 527 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 528 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_3
# 532 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_4
# 536 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_5
# 540 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_6
# 541 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_6
BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_1:
# 544 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_3:
# 529 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin, MSGBOX_DEFAULT
# 530 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_START
# 531 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterFeelingsEasyChat
	goto BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_1

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_4:
# 533 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon, MSGBOX_DEFAULT
# 534 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_WON
# 535 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterFeelingsEasyChat
	goto BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_1

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_5:
# 537 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost, MSGBOX_DEFAULT
# 538 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_LOST
# 539 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterFeelingsEasyChat
	goto BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_1

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_6:
# 542 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan_1


BattleFrontier_BattleTowerLobby_EventScript_EnterFeelingsEasyChat::
# 549 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 550 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 551 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 552 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	return


BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings::
# 556 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings_2
# 559 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChangedYourMind, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings_1:
# 561 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings_2:
# 557 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings_1


BattleFrontier_BattleTowerLobby_EventScript_Woman::
# 566 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
	end


BattleFrontier_BattleTowerLobby_EventScript_Boy::
# 571 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end


BattleFrontier_BattleTowerLobby_EventScript_ShowResults::
# 576 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 577 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 578 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_ShowResults_3
# 579 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_ShowResults_4
# 580 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_ShowResults_5
# 581 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_ShowResults_6
BattleFrontier_BattleTowerLobby_EventScript_ShowResults_1:
# 583 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 584 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 585 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowResults_3:
# 578 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults_1

BattleFrontier_BattleTowerLobby_EventScript_ShowResults_4:
# 579 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults_1

BattleFrontier_BattleTowerLobby_EventScript_ShowResults_5:
# 580 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_MULTIS
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults_1

BattleFrontier_BattleTowerLobby_EventScript_ShowResults_6:
# 581 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_LINK_MULTIS
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults_1


BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults::
# 590 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, FRONTIER_MODE_SINGLES
# 591 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults
	return


BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults::
# 595 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, FRONTIER_MODE_DOUBLES
# 596 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults
	return


BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults::
# 600 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, FRONTIER_MODE_MULTIS
# 601 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults
	return


BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults::
# 605 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
# 606 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowResults
	return


BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons::
# 610 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat
# 612 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_0x8007
# 613 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 51, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_3
# 615 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 52, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_4
# 617 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 53, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_5
# 619 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 101, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_6
# 621 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 102, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_7
# 623 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 103, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_8
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1:
# 627 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_3:
# 614 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_4:
# 616 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_5:
# 618 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_6:
# 620 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_7:
# 622 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_8:
# 624 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons_1


BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat::
# 632 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8007, 0
# 634 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 635 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_3
# 636 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_4
# 637 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 200
BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_1:
# 640 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 641 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_8
# 642 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_9
# 643 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 3
BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_6:
	return

BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_3:
# 635 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 50
	goto BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_1

BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_4:
# 636 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 100
	goto BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_1

BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_8:
# 641 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 1
	goto BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_6

BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_9:
# 642 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	addvar VAR_0x8007, 2
	goto BattleFrontier_BattleTowerLobby_EventScript_GetModeandFormat_6


BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
# 649 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 650 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	return


BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge::
# 654 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 655 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 656 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
	end


BattleFrontier_BattleTowerLobby_EventScript_EnterElevator::
# 661 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 662 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 663 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 664 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
# 665 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CallFrontierUtilFunc
# 666 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 667 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
	return


BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad::
# 671 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_loadlinkopponents
# 672 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 1
# 674 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad_2
BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad_1:
# 678 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
# 679 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 680 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
# 681 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 682 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad_2:
# 675 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
	goto BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad_1


BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom::
# 687 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
# 689 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom_2
# 694 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom_1:
# 697 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator
	return

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom_2:
# 690 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
# 691 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 692 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 48
	goto BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom_1


BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator::
# 701 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 702 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo
# 703 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord
# 704 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 705 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 706 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 707 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	opendoor VAR_0x8004, 1
# 708 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
# 709 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
# 710 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
# 711 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 712 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closedoor VAR_0x8004, 1
# 713 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
	return


# 717 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
# 718 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 718 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 718 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 719 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end

# 722 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
# 723 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 724 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 725 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end

# 728 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
# 729 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 729 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 730 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 731 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText::
# 735 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 736 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_3
# 737 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_4
# 738 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_5
# 739 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_6
BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_3:
# 736 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	goto BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_1

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_4:
# 737 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	goto BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_1

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_5:
# 738 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	goto BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_1

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_6:
# 739 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	goto BattleFrontier_BattleTowerLobby_EventScript_BufferModeText_1


BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo::
# 745 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 746 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_3
# 747 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_4
# 748 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_5
# 749 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_6
BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_3:
# 746 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, 1
	goto BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_1

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_4:
# 747 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, 7
	goto BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_1

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_5:
# 748 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, 8
	goto BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_1

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_6:
# 749 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, 9
	goto BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo_1


BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord::
# 755 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 756 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_3
# 757 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_4
# 758 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_5
# 759 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_6
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_3:
# 756 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 6
	goto BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_1

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_4:
# 757 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 10
	goto BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_1

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_5:
# 758 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 14
	goto BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_1

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_6:
# 759 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 18
	goto BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord_1


BattleFrontier_BattleTowerLobby_EventScript_GetPartySize::
# 765 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 766 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_3
# 767 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_4
# 768 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_5
# 769 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_6
BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_1:
	return

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_3:
# 766 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_1

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_4:
# 767 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_1

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_5:
# 768 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_1

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_6:
# 769 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleFrontier_BattleTowerLobby_EventScript_GetPartySize_1


BattleFrontier_BattleTowerLobby_EventScript_RulesBoard::
# 775 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 776 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 777 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end


BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard::
# 782 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
# 783 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 784 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
# 785 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 786 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_3
# 788 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_4
# 790 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_5
# 792 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_6
# 794 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 4, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_7
# 795 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_7
BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_1:
# 799 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_3:
# 787 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_4:
# 789 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_5:
# 791 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_6:
# 793 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_1

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard_7:
# 796 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
	end


BattleFrontier_EventScript_GetCantRecordBattle::
# 1065 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return


BattleFrontier_EventScript_GetLvlMode::
# 1070 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
	return


BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting::
# 803 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou didn't save before you quit your\nchallenge last time.\pBecause of that, your challenge so far\nhas been disqualified. Sorry!$"

BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven::
# 807 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\nYou've beaten all seven TRAINERS!\p$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize::
# 811 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} received the prize\n{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying::
# 815 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Thank you for playing!\p$"

BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved::
# 819 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your record will be saved.\nPlease wait.$"

BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou::
# 823 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We've been waiting for you!\p$"

BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved::
# 827 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\nprogress will be saved. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer::
# 831 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You're finally about to face the\n50th TRAINER.\pFrom here on, every time you beat seven\nTRAINERS in a row, your POKéMON will\lreceive a commemorative RIBBON.\pGood luck!$"

BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons::
# 835 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Here are some RIBBONS for beating\nseven tough TRAINERS in a row.\p{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons::
# 839 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} put the RIBBONS on\nthe challenger POKéMON.$"

BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower::
# 843 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me, do you have a moment?\pCan you describe your feelings when\nyou're about to begin a BATTLE TOWER\lmatch, or when you've either won or\llost a match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin::
# 847 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, what are your feelings when\nyou're about to begin a match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon::
# 851 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "What do you feel when you've won\na match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost::
# 855 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Can I hear about your feelings when\nyou have lost a match?$"

BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt::
# 859 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Oh, so you don't think much about it?\nYou're one cool customer.$"

BattleFrontier_BattleTowerLobby_Text_ChangedYourMind::
# 863 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Hunh? You changed your mind?\nI guess you're fickle.$"

BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel::
# 867 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, so that's how you feel?\nThat's quite original.\pThanks!$"

BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded::
# 871 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The number of matches you win in a row\nis recorded.\pI'd better not get beaten in\nan embarrassing way!$"

BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins::
# 875 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you've entered the BATTLE TOWER,\nyou can't leave until you either lose\lor you beat seven TRAINERS in a row.\pYou'd best be certain that you're up\nto the challenge.$"

BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge::
# 879 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We look forward to seeing you on\nanother challenge!$"

BattleFrontier_BattleTowerLobby_Text_WhichLevelMode::
# 883 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE ROOM offers two levels\nof challenge, Level 50 and Open Level.\lWhich is your choice?$"

BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering::
# 887 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\nprogress must be saved. Is that okay?$"

BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom::
# 891 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will now show you to the\n{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleTowerLobby_Text_RecordLastMatch::
# 895 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Shall I record your last BATTLE TOWER\nmatch on your FRONTIER PASS?$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles::
# 899 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have three eligible POKéMON.\pYou must have three different POKéMON\nof Level 50 or less to enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles::
# 903 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have three eligible POKéMON.\pYou must have three different POKéMON\nto enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles::
# 907 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have four eligible POKéMON.\pYou must have four different POKéMON\nof Level 50 or less to enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles::
# 911 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have four eligible POKéMON.\pYou must have four different POKéMON\nto enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis::
# 915 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have two eligible POKéMON.\pYou must have two different POKéMON\nof Level 50 or less to enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis::
# 919 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\pYou don't have two eligible POKéMON.\pYou must have two different POKéMON\nto enter.\pThey also must be holding different\nkinds of items.\pEGGS{STR_VAR_1} ineligible.\pPlease come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle::
# 923 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\nare put to the test!\pWelcome to the BATTLE TOWER!\pI am your guide to the SINGLE\nBATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge::
# 927 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the SINGLE\nBATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge::
# 931 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's SINGLE BATTLE\nROOMS are facilities for conducting\lSINGLE BATTLES with three POKéMON.\pThere are many SINGLE BATTLE ROOMS\nin the BATTLE TOWER for team battles.\pIn each of the SINGLE BATTLE ROOMS,\nseven TRAINERS await your challenge.\pIf you manage to defeat all seven,\nyou will earn Battle Points.\pIf you want to interrupt your\nchallenge, please save the game.\pIf you don't save before interrupting,\nyou will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_SelectThreeMons::
# 935 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the three POKéMON\nthat are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle::
# 939 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\nare put to the test!\pWelcome to the BATTLE TOWER!\pI am your guide to the DOUBLE\nBATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge::
# 943 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the DOUBLE\nBATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge::
# 947 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's DOUBLE BATTLE\nROOMS are facilities for conducting\lDOUBLE BATTLES with four POKéMON.\pThere are many DOUBLE BATTLE ROOMS\nin the BATTLE TOWER for team battles.\pIn each of the DOUBLE BATTLE ROOMS,\nseven TRAINERS await your challenge.\pIf you manage to defeat all seven,\nyou will earn Battle Points.\pIf you want to interrupt your\nchallenge, please save the game.\pIf you don't save before interrupting,\nyou will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons::
# 951 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the four POKéMON\nthat are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle::
# 955 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\nare put to the test!\pWelcome to the BATTLE TOWER!\pI am your guide to the MULTI\nBATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge::
# 959 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the MULTI\nBATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge::
# 963 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's MULTI BATTLE\nROOMS are facilities for conducting\lMULTI BATTLES.\pFor MULTI BATTLES, you must partner\nwith a TRAINER in the TOWER and enter\lwith two POKéMON each.\pInside the TOWER is a room named\nthe BATTLE SALON where you may meet\lother TRAINERS.\pThere, you must find a TRAINER to act\nas your partner in MULTI BATTLES.\pOnce you have partnered up, you will\nbe shown to a MULTI BATTLE ROOM.\pIn the MULTI BATTLE ROOM, seven\ntag teams await your challenge.\pIf you manage to defeat all seven\nteams, you will earn Battle Points.\pIf you want to interrupt your\nchallenge, please save the game.\pIf you don't save before interrupting,\nyou will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons::
# 967 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two POKéMON\nthat are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle::
# 971 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\nare put to the test!\pWelcome to the BATTLE TOWER!\pI am your guide to the LINK MULTI\nBATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge::
# 975 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the LINK MULTI\nBATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge::
# 979 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's MULTI BATTLE\nROOMS are facilities for conducting\lMULTI BATTLES with a friend.\pYou must link with your friend using\nWireless Adapters or a Game Boy\lAdvance Game Link cable.\pYou must partner with your friend and\nenter two different kinds of POKéMON.\pThere are many MULTI BATTLE ROOMS\nin the BATTLE TOWER for team battles.\pIn a MULTI BATTLE ROOM, seven\ntag teams await you and your friend\lto make a tag-team challenge.\pIf you manage to defeat all seven\nteams, you will earn Battle Points.\pPlease beware that unlike other ROOMS,\nyou may not interrupt your challenge.\pOnce you start, you must battle seven\nMULTI BATTLES in a row nonstop.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2::
# 983 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two POKéMON\nthat are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers::
# 987 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\nis only for two linked players.$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon::
# 991 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected\nthe POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons::
# 995 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected the\nPOKéMON {STR_VAR_1} and {STR_VAR_2}.$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode::
# 999 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\nbattle level.$"

BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode::
# 1003 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please choose two POKéMON different\nfrom your friend's, match the level\lyou wish to enter, and register again.$"

BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn::
# 1007 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will save the game before\nshowing you in. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden::
# 1011 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\nYou have defeated the SALON MAIDEN\land swept seven TRAINERS!$"

BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints::
# 1015 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In recognition of your infinite talent,\nwe award you these Battle Point(s).$"

BattleFrontier_Text_ObtainedXBattlePoints::
# 1019 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleFrontier_BattleTowerLobby_Text_RulesAreListed::
# 1023 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER rules are listed.$"

BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading::
# 1027 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Which heading do you want to read?$"

BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules::
# 1031 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER is a facility where\nfour types of battles are waged--\lSINGLE BATTLE, DOUBLE BATTLE, MULTI\lBATTLE, and LINK MULTI BATTLE.\pFor each of these types, there are\nseparate BATTLE ROOMS.\pPlease speak with a guide offering\nthe type of battle you wish to enter.$"

BattleFrontier_BattleTowerLobby_Text_ExplainMonRules::
# 1035 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Depending on the BATTLE ROOM you are\nentering, you will be required to take\la certain number of POKéMON.\pThe SINGLE BATTLE mode requires\nthree POKéMON.\pThe DOUBLE BATTLE mode requires four,\nand the MULTI modes both require two.$"

BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules::
# 1039 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE SALON is where you must\nfind a partner to form a tag team for\lthe MULTI BATTLE ROOM challenge.\pChoose the best partner for you by\nexamining other TRAINERS'\lPOKéMON and their moves.\pYou may choose a new tag partner\nafter winning seven straight matches.$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules::
# 1043 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE Mode is for two\nfriends to mount a challenge together.\pYou and your friend must be linked with\nWireless Adapters or a GBA Game Link\lcable.\pYou must choose two POKéMON at\nthe registration counter.\pThese POKéMON must be different\nfrom those of your friend.\pYou may not interrupt this challenge\nin the middle, unlike other modes.$"
