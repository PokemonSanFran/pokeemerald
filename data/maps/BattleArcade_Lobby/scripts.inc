BattleArcade_Lobby_MapScripts::
# 8 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 17 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleArcade_Registration_EventScript_GetChallengeStatus
# 11 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleArcade_Registration_EventScript_QuitWithoutSaving
# 12 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleArcade_Registration_EventScript_ResumeChallenge
# 13 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleArcade_Registration_EventScript_WonChallenge
# 14 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleArcade_Registration_EventScript_LostChallenge
	.2byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 19 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_Lobby_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_Lobby_EventScript_PlayerFaceNorth::
# 25 "data/maps/BattleArcade_Lobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 26 "data/maps/BattleArcade_Lobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_Lobby_EventScript_WarpToHallway::
# 32 "data/maps/BattleArcade_Lobby/scripts.pory"
	warpsilent MAP_BATTLE_ARCADE_HALLWAY, 1, 3
	return


BattleArcade_Lobby_EventScript_WalkToElevator::
# 37 "data/maps/BattleArcade_Lobby/scripts.pory"
	closemessage
# 39 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleArcade_Lobby_Movement_AttendantEnterElevator
# 40 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_Lobby_Movement_PlayerEnterElevator
# 41 "data/maps/BattleArcade_Lobby/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


# 44 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleArcade_Lobby_Movement_AttendantEnterElevator:
# 46 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 46 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 47 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end

# 50 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleArcade_Lobby_Movement_PlayerEnterElevator:
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 53 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end
