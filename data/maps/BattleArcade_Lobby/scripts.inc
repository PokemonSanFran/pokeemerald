BattleArcade_Lobby_MapScripts::
# 10 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 19 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_Registration_EventScript_GetChallengeStatus
# 13 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleArcade_Registration_EventScript_QuitWithoutSaving
# 14 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleArcade_Registration_EventScript_ResumeChallenge
# 15 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleArcade_Registration_EventScript_WonChallenge
# 16 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleArcade_Registration_EventScript_LostChallenge
	.2byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 21 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_Lobby_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_Lobby_EventScript_PlayerFaceNorth::
# 27 "data/maps/BattleArcade_Lobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 28 "data/maps/BattleArcade_Lobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_Lobby_EventScript_WalkToElevator::
# 34 "data/maps/BattleArcade_Lobby/scripts.pory"
	closemessage
# 36 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleArcadeLobby_Movement_AttendantEnterElevator
# 37 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArcadeLobby_Movement_PlayerEnterElevator
# 38 "data/maps/BattleArcade_Lobby/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_Lobby_EventScript_WarpToHallway::
# 43 "data/maps/BattleArcade_Lobby/scripts.pory"
	warpsilent MAP_BATTLE_ARCADE_HALLWAY, 1, 2
	return


# 45 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleFrontier_BattleArcadeLobby_Movement_AttendantEnterElevator:
# 47 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 47 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 48 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end

# 51 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleFrontier_BattleArcadeLobby_Movement_PlayerEnterElevator:
# 53 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 53 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 53 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 54 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end
