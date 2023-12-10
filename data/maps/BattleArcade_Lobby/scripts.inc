BattleArcade_Lobby_MapScripts::
# 19 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 28 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArcadeLobby_EventScript_GetChallengeStatus
# 22 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArcadeLobby_EventScript_QuitWithoutSaving
# 23 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArcadeLobby_EventScript_ResumeChallenge
# 24 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleArcadeLobby_EventScript_WonChallenge
# 25 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArcadeLobby_EventScript_LostChallenge
	.2byte 0

BattleArcade_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 30 "data/maps/BattleArcade_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArcadeLobby_EventScript_PlayerFaceNorth
	.2byte 0


BattleFrontier_BattleArcadeLobby_EventScript_WalkToElevator::
# 37 "data/maps/BattleArcade_Lobby/scripts.pory"
	closemessage
# 39 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleArcadeLobby_Movement_AttendantEnterElevator
# 40 "data/maps/BattleArcade_Lobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArcadeLobby_Movement_PlayerEnterElevator
# 41 "data/maps/BattleArcade_Lobby/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


# 44 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleFrontier_BattleArcadeLobby_Movement_AttendantEnterElevator:
# 46 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 46 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 47 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end

# 50 "data/maps/BattleArcade_Lobby/scripts.pory"
BattleFrontier_BattleArcadeLobby_Movement_PlayerEnterElevator:
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 52 "data/maps/BattleArcade_Lobby/scripts.pory"
	walk_up
# 53 "data/maps/BattleArcade_Lobby/scripts.pory"
	set_invisible
	step_end
